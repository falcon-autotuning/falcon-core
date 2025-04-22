"""Integration tests for BaseMessageIO with real Valkey client.

These tests require a running Valkey instance and will modify real data.
They are intended for integration testing only, not for regular CI runs.
"""

import contextlib
import os
import subprocess
import threading
import time
import uuid

import pytest
import valkey

from falcon_core.communications.managers.status_type import (
    ChannelStatusType,
    ProgramStatusType,
)
from falcon_core.communications.message_io.base_message_io import BaseMessageIO
from falcon_core.communications.message_io.message_config import MessageConfig
from falcon_core.generic import Jsonable


class TestMessage(Jsonable):
    """Test message class for JSON serialization."""

    def __init__(self, data: str):
        self._data = data


@pytest.fixture(scope="module")
def valkey_server():
    """Start a Valkey server for testing and clean up after."""
    # Check if we should use an existing Valkey instance
    use_existing = os.environ.get("USE_EXISTING_VALKEY", "False").lower() == "true"

    valkey_process = None
    try:
        if not use_existing:
            # Determine if valkey-server is available
            try:
                subprocess.run(
                    ["which", "valkey-server"], check=True, capture_output=True
                )
            except subprocess.CalledProcessError:
                pytest.skip(
                    "valkey-server not found. Install it or set USE_EXISTING_VALKEY=true"
                )

            # Start a local Valkey server for testing
            valkey_process = subprocess.Popen(
                ["valkey-server", "--port", "6379", "--save", "", "--appendonly", "no"],
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
            )

            # Wait for server to start
            time.sleep(2)

            # Check if server is running
            try:
                status = subprocess.run(
                    ["valkey-cli", "-h", "localhost", "-p", "6379", "ping"],
                    check=True,
                    capture_output=True,
                )
                if b"PONG" not in status.stdout:
                    pytest.skip("Failed to start Valkey server")
            except subprocess.CalledProcessError:
                pytest.skip("Failed to connect to Valkey server")

        # Return connection details
        yield {"host": "localhost", "port": 6379}

    finally:
        # Clean up the Valkey server
        if valkey_process is not None:
            valkey_process.terminate()
            valkey_process.wait(timeout=5.0)


@pytest.fixture
def clean_valkey(valkey_server):
    """Connect to Valkey and ensure a clean database for each test."""
    # Flush the database before each test
    result = subprocess.run(
        [
            "valkey-cli",
            "-h",
            valkey_server["host"],
            "-p",
            str(valkey_server["port"]),
            "flushall",
        ],
        check=True,
        capture_output=True,
    )
    assert b"OK" in result.stdout, "Failed to flush Valkey database"

    # Return connection details
    return valkey_server


@pytest.fixture
def unique_name():
    """Generate a unique application name for tests."""
    return f"test_app_{uuid.uuid4().hex[:8]}"


@pytest.fixture
def message_config(unique_name):
    """Create a message configuration for testing.

    Returns:
        A MessageConfig instance with a unique application name and test settings.
    """
    return MessageConfig(
        _application_name=unique_name,
        _message_timeout=2.0,
        _lock_timeout=1,
        _max_retries=2,
        _retry_delay=0.01,
        _channels=[f"channel_{i}" for i in range(3)],
    )


@pytest.fixture
def message_io(clean_valkey, message_config: MessageConfig):
    """Create a BaseMessageIO instance connected to the real Valkey server."""
    # Create instance with test-appropriate settings
    io = BaseMessageIO(
        message_config=message_config,
        startup=True,
        startup_program=True,
    )

    yield io

    # Cleanup after test
    with contextlib.suppress(Exception):
        # Set program status to STOPPED to clean up
        io._program_status_manager().set_status(ProgramStatusType.STOPPED)


# Tests
def test_real_collect_message(message_io):
    """Test collecting messages with real Valkey."""
    # Create a test message
    message = TestMessage("collect_test")
    channel = "collect_channel"

    # Publish message
    message_io.publish(channel, message)

    # Detailed inspection after command
    inspect_valkey(
        "AFTER_COMMAND", app_name=message_io._my_name, channel="collect_channel"
    )

    # Collect message
    collected = message_io.collect_message(channel)
    assert collected is not None
    assert isinstance(collected, TestMessage)
    assert collected._data == "collect_test"


def inspect_valkey(label, channel=None, app_name=None):
    """Simple, reliable inspection of Valkey data.

    Args:
        label: A label for this inspection point
        channel: Optional channel name to inspect
        app_name: Optional application name to inspect
    """
    print(f"\n===== VALKEY INSPECTION: {label} =====")
    client = valkey.Valkey()
    # 1. Get all keys - simple and reliable
    try:
        raw_keys = client.keys("*")
        assert isinstance(raw_keys, list)
        keys = [key.decode("utf-8") for key in raw_keys]

        print(f"Keys in database: {keys}")
    except Exception as e:
        print(f"Error listing keys: {e}")
        keys = []

    # 2. Check channel data
    if channel:
        try:
            # Get all hash fields and values
            print(f"\nChannel {channel} message data:")
            print(client.hget("messages", channel))

        except Exception:
            print(f"Error getting message data for {channel}")

    # 3. Check application notifications
    if app_name:
        try:
            # Get all hash fields and values
            print(f"\nNotifications for {app_name}:")
            print(client.hget("notifications", app_name))
        except Exception:
            print(f"Error getting notification data for {app_name}")

    # 4. Check program status
    if "program_status" in keys:
        try:
            print("\nProgram statuses:")
            print(client.hgetall("program_status"))

        except Exception:
            print("Error getting program status data")

    # 5. Check channel status
    if "channel_status" in keys:
        try:
            print("\nChannel statuses:")
            print(client.hgetall("channel_status"))
        except Exception:
            print("Error getting channel status data")

    print("=" * 40)


def test_real_listen_command_workflow(message_io, unique_name):
    """Test complete listen/command workflow with real Valkey."""
    # Create a receiver that will listen for commands
    receiver_name = f"{unique_name}_listener"
    config = MessageConfig(
        _application_name=receiver_name,
        _message_timeout=2.0,
        _lock_timeout=1,
        _max_retries=2,
        _retry_delay=0.01,
        _channels=[f"channel_{i}" for i in range(3)],
    )
    receiver = BaseMessageIO(
        message_config=config,
        startup=True,
        startup_program=True,
    )

    # Run a thread that will listen for commands
    listen_result = None
    listen_complete = threading.Event()
    listen_error = None

    inspect_lock = threading.Lock()  # Add lock for inspections

    def listener_thread():
        nonlocal listen_result, listen_error
        try:
            # This will block until a command is received
            print(f"Listener thread starting: {threading.get_ident()}")
            listen_result = receiver.listen()
            print(f"Listener received: {listen_result}")
            listen_complete.set()
        except Exception as e:
            listen_error = e
            print(f"Listener thread error: {e}")
            listen_complete.set()  # Signal completion even on error

    # Start listener thread
    listener = threading.Thread(target=listener_thread)
    listener.daemon = True
    listener.start()

    # Give the listener time to start
    time.sleep(0.5)

    # Basic debug before command
    with inspect_lock:
        inspect_valkey("BEFORE_COMMAND", app_name=receiver_name)

        # Send a command from main thread
        print(f"\nSending command to {receiver_name}")
        command_message = TestMessage("listen_test")
        message_io.command(receiver_name, command_message)

        # Detailed inspection after command
        for i in range(3):
            print(f"\nInspecting channel_{i} after command")
            inspect_valkey(
                "AFTER_COMMAND", app_name=receiver_name, channel=f"channel_{i}"
            )

    # Wait for listener to receive the command
    not listen_complete.wait(timeout=5.0)

    if listen_error:
        pytest.fail(f"Listener thread failed: {listen_error}")

    # Check the received message
    assert listen_result is not None
    assert isinstance(listen_result, TestMessage)
    assert listen_result._data == "listen_test"

    # Cleanup
    with receiver._program_status_manager() as manager:
        manager.set_status(ProgramStatusType.STOPPED)


def test_real_program_status(message_io):
    """Test program status using managers directly."""
    # Use the program status manager directly
    with message_io._program_status_manager() as manager:
        # Check current status
        status = manager.get_status()

        # Set to PAUSED
        manager.set_status(ProgramStatusType.PAUSED)
        assert manager.get_status() == ProgramStatusType.PAUSED

        # Set to STOPPED
        manager.set_status(ProgramStatusType.STOPPED)
        assert manager.get_status() == ProgramStatusType.STOPPED

        # Set back to original status
        manager.set_status(status)


def test_real_channel_status(message_io):
    """Test channel status using manager directly."""
    # Get a channel directly from manager
    with message_io._channel_status_manager() as manager:
        channels = manager.get_channels()
        assert len(channels) > 0
        channel = channels[0]

        # Set to IDLE
        manager.set_status(channel, ChannelStatusType.IDLE)
        assert manager.get_status(channel) == ChannelStatusType.IDLE

        # Set to BUSY
        manager.set_status(channel, ChannelStatusType.BUSY)
        assert manager.get_status(channel) == ChannelStatusType.BUSY

        # Set to FINISHED
        manager.set_status(channel, ChannelStatusType.FINISHED)
        assert manager.get_status(channel) == ChannelStatusType.FINISHED


def test_real_channel_toggle(message_io):
    """Test toggle_channel_status method."""
    # First need to get a channel directly from manager
    with message_io._channel_status_manager() as manager:
        channels = manager.get_channels()
        assert len(channels) > 0
        channel = channels[0]

        # Set to BUSY
        manager.set_status(channel, ChannelStatusType.BUSY)

    # Now toggle using the method in BaseMessageIO
    message_io.toggle_channel_status(channel)

    # Verify using manager
    with message_io._channel_status_manager() as manager:
        status = manager.get_status(channel)
        assert status == ChannelStatusType.FINISHED


def test_real_communication_status_checks(message_io, unique_name):
    """Test communication status check methods."""
    # Create another app to check
    other_name = f"{unique_name}_status_check"
    config = MessageConfig(
        _application_name=other_name,
        _message_timeout=2.0,
        _lock_timeout=1,
        _max_retries=2,
        _retry_delay=0.01,
        _channels=[f"channel_{i}" for i in range(3)],
    )
    other_io = BaseMessageIO(
        message_config=config,
        startup=True,
        startup_program=True,
    )

    # Check running
    assert message_io.check_program_running(other_name)
    assert not message_io.check_program_stopped(other_name)

    # Set to stopped using manager
    with other_io._program_status_manager() as manager:
        manager.set_status(ProgramStatusType.STOPPED)

    # Check stopped
    assert not message_io.check_program_running(other_name)
    assert message_io.check_program_stopped(other_name)


def test_real_wait_for_channel_opening(message_io):
    """Test wait_for_channel_opening method."""
    # First make all channels busy using manager
    with message_io._channel_status_manager() as manager:
        channels = manager.get_channels()
        for channel in channels:
            manager.set_status(channel, ChannelStatusType.BUSY)

    # Start a thread that will release a channel after a delay
    def release_channel():
        time.sleep(0.5)  # Wait before releasing
        with message_io._channel_status_manager() as manager:
            manager.set_status(channels[0], ChannelStatusType.IDLE)

    release_thread = threading.Thread(target=release_channel)
    release_thread.daemon = True
    release_thread.start()

    # This should block until the channel is released
    result_channel = message_io.wait_for_channel_opening()

    # Check we got the released channel
    assert result_channel == channels[0]

    # Check it's now marked busy (because wait_for_channel_opening claims it)
    with message_io._channel_status_manager() as manager:
        status = manager.get_status(result_channel)
        assert status == ChannelStatusType.BUSY


def test_real_find_available_channel(message_io):
    """Test find_available_channel method."""
    # Make all channels available using manager
    with message_io._channel_status_manager() as manager:
        channels = manager.get_channels()
        for channel in channels:
            manager.set_status(channel, ChannelStatusType.IDLE)

    # Find an available channel
    channel = message_io.find_available_channel()
    assert channel is not None

    # Verify it's marked busy now
    with message_io._channel_status_manager() as manager:
        status = manager.get_status(channel)
        assert status == ChannelStatusType.BUSY


if __name__ == "__main__":
    # This allows running the tests manually with python -m pytest tests/test_integration_base_message_io.py -v
    pytest.main(["-v", __file__])
