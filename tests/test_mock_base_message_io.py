"""Unit tests for BaseMessageIO."""

import threading
from unittest.mock import MagicMock, patch

import pytest

from falcon_core.communications.managers.status_type import (
    ChannelStatusType,
    ProgramStatusType,
)
from falcon_core.communications.message_io.base_message_io import BaseMessageIO
from falcon_core.communications.notifications import Notification, Notifications
from falcon_core.dependancies import time
from falcon_core.generic import Jsonable


# Mock classes for testing
class MockJsonable(Jsonable):
    """Mock class for Jsonable objects."""

    def __init__(self, data):
        self.data = data

    def to_json(self):
        return self.data

    @classmethod
    def from_json(cls, data, *args, **kwargs):
        return MockJsonable(data)


# Mock Valkey client instead of entire managers
@pytest.fixture
def mock_valkey():
    """Create a mock for the valkey client that's used by all managers."""
    with patch(
        "falcon_core.communications.managers.locking_communication.valkey.Valkey"
    ) as mock_valkey_cls:
        # Create a mock valkey client
        mock_client = MagicMock()

        # Configure mock client behavior for normal operations
        mock_client.set.return_value = True
        mock_client.hset.return_value = True
        mock_client.eval.return_value = 1

        # Return the mock client when Valkey() is called
        mock_valkey_cls.return_value = mock_client

        yield mock_client


@pytest.fixture(autouse=True)
def reset_mocks(mock_valkey):
    """Reset all mocks before each test."""
    # Clear all saved calls first
    mock_valkey.reset_mock()

    # Create a completely fresh MagicMock for methods that need it
    mock_valkey.hget = MagicMock(return_value=None)
    mock_valkey.hset = MagicMock(return_value=True)
    mock_valkey.set = MagicMock(return_value=True)
    mock_valkey.eval = MagicMock(return_value=1)
    mock_valkey.time = MagicMock(return_value=(1685000000, 0))
    mock_valkey.close = MagicMock(return_value=None)
    mock_valkey.hkeys = MagicMock(return_value=[])
    mock_valkey.hexists = MagicMock(return_value=False)

    # No need to clear side effects as we've replaced the methods with fresh mocks


@pytest.fixture
def message_io(mock_valkey):
    """Create a BaseMessageIO instance with mocked valkey client."""
    return BaseMessageIO(
        application_name="test_app",
        timeout=1.0,  # Short timeout for tests
        lock_timeout=1,
        max_retries=2,
        retry_delay=0.01,  # Short delay for faster tests
    )


# Tests
def test_initialization(mock_valkey):
    """Test BaseMessageIO initialization."""
    io = BaseMessageIO("test_app")
    assert io._my_name == "test_app"
    assert io._timeout == 3600
    assert io._lock_timeout == 5
    assert io._max_retries == 3
    assert io._retry_delay == 0.2

    # Test with startup flags
    io = BaseMessageIO("test_application", startup=True, startup_program=True)

    # Verify that the right keys were set in valkey for program status
    startup_calls = [
        call
        for call in mock_valkey.hset.call_args_list
        if "program_status" in str(call)
    ]
    assert len(startup_calls) > 0


def test_check_program_status(message_io, mock_valkey):
    """Test checking program status."""

    # Configure mock to return RUNNING status
    def get_side_effect(*args, **kwargs):
        if "program_status" in str(args):
            return ProgramStatusType.RUNNING.value
        return None

    mock_valkey.hget.side_effect = get_side_effect

    # Test check_program_running
    assert message_io.check_program_running("test_app")

    # Configure mock to return STOPPED status
    def get_side_effect_stopped(*args, **kwargs):
        if "program_status" in str(args):
            return ProgramStatusType.STOPPED.value
        return None

    mock_valkey.hget.side_effect = get_side_effect_stopped

    # Test check_program_stopped
    assert message_io.check_program_stopped("test_app")


def test_publish_message(message_io, mock_valkey):
    """Test publishing a message."""
    message = MockJsonable("test message")
    message_io.publish("test_channel", message)

    # Verify message was stored in valkey
    assert mock_valkey.hset.called


def test_find_available_channel(message_io, mock_valkey):
    """Test finding an available channel."""

    # Configure mock to return an available channel
    def hkeys_side_effect(*args, **kwargs):
        if "channel_status" in str(args):
            return [b"channel1"]
        return []

    def hget_side_effect(*args, **kwargs):
        if "channel1" in str(args):
            return ChannelStatusType.IDLE.value
        return ChannelStatusType.BUSY.value

    mock_valkey.hkeys.side_effect = hkeys_side_effect
    mock_valkey.hget.side_effect = hget_side_effect

    # Test finding channel
    channel = message_io.find_available_channel()
    assert channel == "channel1"

    # Verify channel status was updated
    assert any("channel1" in str(call) for call in mock_valkey.hset.call_args_list)


def test_collision_when_toggling_channel_status(message_io, mock_valkey):
    """Test handling collisions when toggling channel status."""

    # Setup to return BUSY status for a channel
    def hget_side_effect(*args, **kwargs):
        if "channel_status" in str(args) and "test_channel" in str(args):
            return ChannelStatusType.BUSY.value
        return None

    mock_valkey.hget.side_effect = hget_side_effect

    # First call succeeds
    assert message_io.toggle_channel_status("test_channel")

    # Second call fails due to collision - simulate by setting return False for set operations
    mock_valkey.set.return_value = False
    assert not message_io.toggle_channel_status("test_channel")

    # Verify attempt to set appropriate status
    assert any(
        "test_channel" in str(call) and ChannelStatusType.FINISHED.value in str(call)
        for call in mock_valkey.hset.call_args_list
    )


def test_collision_during_channel_acquisition(message_io, mock_valkey):
    """Test handling collisions during channel acquisition."""
    # First call returns available channels
    mock_valkey.hkeys.return_value = [b"channel1"]

    # Then simulate collision by having hset fail
    mock_valkey.hset.return_value = False

    # Should time out waiting for channel
    with pytest.raises(TimeoutError):
        message_io.wait_for_channel_opening()


def test_communication_status_check_timeout(message_io, mock_valkey):
    """Test timeout when checking communication status."""
    # Program neither running nor stopped
    mock_valkey.hget.return_value = ProgramStatusType.PAUSED.value

    # Should time out
    with pytest.raises(TimeoutError):
        message_io.check_communication_status("app_name")


def test_communication_status_check_stopped(message_io, mock_valkey):
    """Test raising exception when program is stopped."""
    # Program is stopped
    mock_valkey.hget.return_value = ProgramStatusType.STOPPED.value

    # Should raise RuntimeError
    with pytest.raises(RuntimeError, match="Program is stopped"):
        message_io.check_communication_status("app_name")


def test_concurrent_notification_handling(mock_valkey):
    """Test handling concurrent notification access with proper locking."""
    # Use real synchronization for thread-safe mocking
    locks = {}  # Dictionary to track Redis locks by key
    locks_mutex = threading.Lock()  # Mutex to protect the locks dictionary

    # Set up thread tracking
    results = []
    results_lock = threading.Lock()

    # Track actual calls to verify locking behavior
    call_order = []
    call_lock = threading.Lock()

    # Store notifications with thread-safe access
    notifications_container = Notifications(
        [
            Notification(
                channel=f"channel_{i}",
                timestamp=1000000 + i,
                name="sender",
            )
            for i in range(3)
        ]
    )
    notifications_lock = threading.Lock()

    # Define mock behaviors for valkey methods
    def hkeys_side_effect(*args, **kwargs):
        with call_lock:
            call_order.append(f"hkeys:{args}")
        return [f"channel_{i}".encode() for i in range(3)]

    def hexists_side_effect(namespace, key):
        with call_lock:
            call_order.append(f"hexists:{namespace}:{key}")

        # Check if notifications exist
        if "notifications" in namespace:
            with notifications_lock:
                return len(notifications_container) > 0
        return False

    def hget_side_effect(*args, **kwargs):
        with call_lock:
            call_order.append(f"hget:{args}")

        # Handle notifications retrieval
        if "notifications" in str(args) and "test_app" in str(args):
            with notifications_lock:
                if len(notifications_container) > 0:
                    return notifications_container.to_json().encode("utf-8")
        return None

    def hset_side_effect(*args, **kwargs):
        with call_lock:
            call_order.append(f"hset:{args}")

        # Handle notifications updates
        if "notifications" in str(args) and "test_app" in str(args) and len(args) > 2:
            with notifications_lock:
                try:
                    # Update notifications - using proper method to update container
                    new_notifications = Notifications.from_json(args[2])
                    # Use clear method followed by add to avoid attribute access
                    notifications_container.notifications.clear()
                    for notif in new_notifications.notifications:
                        notifications_container.notifications.append(notif)
                except Exception as e:
                    print(f"EXCEPTION in hset: {e}")

        return True

    def hdel_side_effect(*args, **kwargs):
        with call_lock:
            call_order.append(f"hdel:{args}")

        if "notifications" in str(args) and "test_app" in str(args):
            with notifications_lock:
                # Clear notifications if needed
                if len(notifications_container) == 0:
                    return 1
        return 0

    # Mock the Redis distributed lock mechanism
    def set_side_effect(key, value=None, nx=None, ex=None):
        if nx:  # This is a lock acquisition
            with locks_mutex:
                # If the lock already exists, fail to acquire
                if key in locks:
                    return False
                # Otherwise acquire the lock
                locks[key] = value
                with call_lock:
                    call_order.append(f"lock_acquire:{key}:{value}")
                return True
        return True  # Regular SET operations succeed

    def eval_side_effect(script, num_keys, key, value):
        # This is for lock release
        with locks_mutex:
            if key in locks and locks[key] == value:
                with call_lock:
                    call_order.append(f"lock_release:{key}:{value}")
                del locks[key]
                return 1
            return 0

    # Set up the mock client
    mock_valkey.hkeys.side_effect = hkeys_side_effect
    mock_valkey.hexists.side_effect = hexists_side_effect
    mock_valkey.hget.side_effect = hget_side_effect
    mock_valkey.hset.side_effect = hset_side_effect
    mock_valkey.hdel.side_effect = hdel_side_effect
    mock_valkey.set.side_effect = set_side_effect
    mock_valkey.eval.side_effect = eval_side_effect
    mock_valkey.time.return_value = (1234567890, 0)

    # Create BaseMessageIO instance with shorter timeout for faster tests
    message_io = BaseMessageIO(
        "test_app",
        max_retries=5,
        retry_delay=1,
        startup=True,
        channels=[f"channel_{i}" for i in range(3)],
    )

    # Define a cleaner thread function with better error handling
    def check_notification():
        thread_id = threading.get_ident()
        try:
            with call_lock:
                call_order.append(f"thread_start:{thread_id}")

            result = message_io.check_notifications()

            if result is not None:
                with results_lock:
                    results.append(result)
                with call_lock:
                    call_order.append(f"thread_success:{thread_id}:{result.channel}")
            else:
                with call_lock:
                    call_order.append(f"thread_no_notification:{thread_id}")
        except Exception as e:
            with call_lock:
                call_order.append(f"thread_error:{thread_id}:{e!s}")
            print(f"Error in check_notification: {e}")

    # Start multiple threads to simulate concurrent access
    threads = []
    for _ in range(5):  # More threads than notifications
        t = threading.Thread(target=check_notification)
        t.daemon = True  # Mark as daemon so they don't block test exit
        threads.append(t)
        t.start()
        # Small delay between thread starts to reduce extreme contention
        time.sleep(0.01)

    # Wait for all threads to complete with a reasonable timeout
    for thread in threads:
        thread.join(timeout=20.0)

    # Print diagnostics for debugging
    print(f"Results length: {len(results)}")
    print(f"Call order: {call_order}")

    # Add more detailed diagnostic info
    print(f"Notifications remaining: {len(notifications_container)}")
    print(f"Locks at end: {locks}")

    # Check that all notifications were removed from container
    with notifications_lock:
        assert len(notifications_container) == 0, (
            f"Expected 0 notifications remaining but got {len(notifications_container)}"
        )

    # Verify lock behavior - check that locks were properly acquired and released
    assert any("lock_acquire:" in call for call in call_order), "No locks were acquired"
    assert any("lock_release:" in call for call in call_order), "No locks were released"

    # Verify results - we should have exactly 3 notifications processed
    assert len(results) == 3, f"Expected 3 results but got {len(results)}"

    # Check that all notifications were unique (no duplicate processing)
    channels = [n.channel for n in results]
    unique_channels = set(channels)
    assert len(unique_channels) == 3, (
        f"Expected 3 unique channels but got {len(unique_channels)}: {unique_channels}"
    )


def test_message_collision_with_concurrent_threads(mock_valkey):
    """Test handling message collisions with concurrent threads."""
    # Use real synchronization for thread-safe mocking
    locks = {}  # Dictionary to track Redis locks by key
    locks_mutex = threading.Lock()  # Mutex to protect the locks dictionary

    # Set up more robust thread tracking
    thread_results = []
    results_lock = threading.Lock()

    # Track actual calls to verify locking behavior
    call_order = []
    call_lock = threading.Lock()

    # Storage for channel states
    channel_states = {"channel1": ChannelStatusType.IDLE.value}
    channel_states_lock = threading.Lock()

    # Define mock behaviors for valkey methods
    def hkeys_side_effect(*args, **kwargs):
        with call_lock:
            call_order.append(f"hkeys:{args}")
        return [key.encode("utf-8") for key in channel_states]

    def hget_side_effect(*args, **kwargs):
        with call_lock:
            call_order.append(f"hget:{args}")

        if "program_status" in str(args):
            return ProgramStatusType.RUNNING.value.encode("utf-8")

        if "channel_status" in str(args):
            channel_key = args[1]
            return channel_states.get(channel_key, ChannelStatusType.IDLE.value).encode(
                "utf-8"
            )

        return None

    def hset_side_effect(*args, **kwargs):
        with call_lock:
            call_order.append(f"hset:{args}")

        # For channel status updates
        if "channel_status" in str(args) and len(args) > 2:
            with channel_states_lock:
                channel_key = args[1]
                new_status = args[2]
                # Update the channel status
                channel_states[channel_key] = new_status

        return True

    # Mock the Redis distributed lock mechanism
    def set_side_effect(key, value=None, nx=None, ex=None):
        if nx:  # This is a lock acquisition
            with locks_mutex:
                # If the lock already exists, fail to acquire
                if key in locks:
                    return False
                # Otherwise acquire the lock
                locks[key] = value
                with call_lock:
                    call_order.append(f"lock_acquire:{key}:{value}")
                return True
        return True  # Regular SET operations succeed

    def eval_side_effect(script, num_keys, key, value):
        # This is for lock release
        with locks_mutex:
            if key in locks and locks[key] == value:
                with call_lock:
                    call_order.append(f"lock_release:{key}:{value}")
                del locks[key]
                return 1
            return 0

    # Set up the mock client
    mock_valkey.hkeys.side_effect = hkeys_side_effect
    mock_valkey.hget.side_effect = hget_side_effect
    mock_valkey.hset.side_effect = hset_side_effect
    mock_valkey.set.side_effect = set_side_effect
    mock_valkey.eval.side_effect = eval_side_effect
    mock_valkey.time.return_value = (1234567890, 0)

    # Create BaseMessageIO instance with shorter timeout for faster tests
    io = BaseMessageIO(
        "test_app",
        timeout=10,  # Short timeout for faster tests
        lock_timeout=1,
        max_retries=2,
        retry_delay=0.01,
        startup=True,
        channels=["channel1"],
    )

    # Thread function to send command
    def thread_func():
        thread_id = threading.get_ident()
        try:
            with call_lock:
                call_order.append(f"thread_start:{thread_id}")
            io.command("target_app", MockJsonable("test"))
            # If we get here, command succeeded
            with results_lock:
                thread_results.append(True)
            with call_lock:
                call_order.append(f"thread_success:{thread_id}")
        except TimeoutError:
            # Expected behavior for threads that can't get channel
            with results_lock:
                thread_results.append(False)
            with call_lock:
                call_order.append(f"thread_timeout:{thread_id}")
        except Exception as e:
            # Unexpected error
            with results_lock:
                thread_results.append(f"Error: {e!s}")
            with call_lock:
                call_order.append(f"thread_error:{thread_id}:{e!s}")

    # Create and start threads
    threads = []
    for _ in range(3):
        t = threading.Thread(target=thread_func)
        threads.append(t)
        t.start()

    # Wait for threads to complete
    for t in threads:
        t.join(timeout=20.0)  # Longer timeout to ensure threads finish

    # All threads should have finished
    assert all(not t.is_alive() for t in threads), "Some threads did not complete"

    # Count successful and failed threads
    successes = thread_results.count(True)
    failures = thread_results.count(False)
    errors = [r for r in thread_results if isinstance(r, str)]

    # Check there were no unexpected errors
    assert len(errors) == 0, f"Unexpected errors: {errors}"
    # Check that exactly one thread succeeded
    assert successes == 1, f"Expected 1 successful thread, got {successes}"
    # Check that the other threads failed with TimeoutError
    assert failures == 2, f"Expected 2 failed threads, got {failures}"

    # Print diagnostics for debugging
    print(f"Thread results: {thread_results}")
    print(f"Call order: {call_order}")

    # Verify lock behavior - check that locks were properly acquired and released
    assert any("lock_acquire:" in call for call in call_order), "No locks were acquired"
    assert any("lock_release:" in call for call in call_order), "No locks were released"


def test_command_workflow(message_io, mock_valkey):
    """Test the entire command workflow."""
    # Configure mock for a successful command workflow

    # 1. Program status check returns RUNNING
    def hget_side_effect(*args, **kwargs):
        if "program_status" in str(args):
            return ProgramStatusType.RUNNING.value.encode("utf-8")
        if "channel_status" in str(args):
            return ChannelStatusType.IDLE.value.encode("utf-8")
        return None

    mock_valkey.hget.side_effect = hget_side_effect

    # 2. Available channel check
    mock_valkey.hkeys.return_value = [b"test_channel"]

    # 3. Set time for notification
    mock_valkey.time.return_value = (1234567890, 0)

    # Execute command
    message = MockJsonable("test command")
    message_io.command("target_app", message)

    # Verify operations were performed in correct order
    # We can check the sequence of calls to valkey methods
    call_sequence = mock_valkey.method_calls

    # Check that we set message to the channel
    hset_calls = [call for call in call_sequence if call[0] == "hset"]
    assert any("test_channel" in str(call) for call in hset_calls)

    # Check that we set notification
    assert any("notification" in str(call) for call in hset_calls)
