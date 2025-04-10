"""Tests for the ProgramStatusContextManager."""

import threading
from unittest.mock import MagicMock, patch

import pytest

from falcon_core.communications.managers.program_status_manager import (
    ProgramStatusManager,
)
from falcon_core.communications.managers.status_type import ProgramStatusType


@pytest.fixture
def mock_valkey():
    """Mock the valkey client."""
    with patch(
        "falcon.communications.managers.dependancies.valkey.Valkey"
    ) as MockValkey:
        # Create mock client and methods
        mock_client = MagicMock()
        MockValkey.return_value = mock_client
        # Setup get/set methods that will be used by BaseGlobalContextManager
        mock_client.hget.return_value = None  # Default return value
        mock_client.hset.return_value = True  # Default return value for successful set
        mock_client.close.return_value = None
        yield mock_client


class TestMockProgramStatusManager:
    """Test the ProgramStatusContextManager."""

    def test_init_with_startup(self, mock_valkey):
        """Test initialization with startup=True."""
        ctx = ProgramStatusManager(application_name="test_app", startup=True)

        assert ctx.namespace == "program_status"
        # Validate that the status is set correctly
        mock_valkey.hset.assert_called_with(
            "program_status", "test_app", ProgramStatusType.STARTED.value
        )

    def test_init_without_startup(self, mock_valkey):
        """Test initialization with startup=False."""
        ctx = ProgramStatusManager(application_name="test_app", startup=False)

        assert ctx.namespace == "program_status"
        # Ensure no status is set during initialization
        mock_valkey.hset.assert_not_called()

    def test_set_status_success(self, mock_valkey):
        """Test setting the status successfully."""
        ctx = ProgramStatusManager(application_name="test_app")
        mock_valkey.hget.return_value = ProgramStatusType.RUNNING.value
        result = ctx.set_status(status=ProgramStatusType.STOPPED)

        assert result is True
        mock_valkey.hset.assert_called_with(
            "program_status", "test_app", ProgramStatusType.STOPPED.value
        )

    def test_set_status_exhaust_retries(self, mock_valkey):
        """Test setting the status when retries are exhausted."""
        ctx = ProgramStatusManager(application_name="test_app")
        mock_valkey.hget.return_value = ProgramStatusType.RUNNING.value
        mock_valkey.set.return_value = False

        # Simulate a scenario where the status cannot be set
        with patch.object(ctx, "_set_status", return_value=False):
            result = ctx.set_status(
                status=ProgramStatusType.STOPPED,
            )

        assert result is False

    def test_set_status_business_rule_violation(self, mock_valkey):
        """Test setting the status when business rules prevent it."""
        ctx = ProgramStatusManager(application_name="test_app")
        mock_valkey.hget.return_value = ProgramStatusType.STOPPED.value

        # Simulate a scenario where the current status prevents the update
        result = ctx.set_status(status=ProgramStatusType.RUNNING)

        assert result is False
        mock_valkey.hset.assert_not_called()

    def test_get_status(self, mock_valkey):
        """Test getting the current status."""
        ctx = ProgramStatusManager(application_name="test_app")
        mock_valkey.hget.return_value = ProgramStatusType.RUNNING.value

        result = ctx.get_status()

        assert result == ProgramStatusType.RUNNING

    def test_concurrent_status_updates(self, mock_valkey):
        """Test concurrent status updates using threads."""
        num_threads = 2
        app_name = "concurrent_app"
        initial_status = ProgramStatusType.RUNNING
        final_status = ProgramStatusType.STOPPED

        # Initialize the context manager
        ctx1 = ProgramStatusManager(application_name="test_app1")
        ctx2 = ProgramStatusManager(application_name="test_app2")

        # Ensure initial status is set
        mock_valkey.hget.return_value = initial_status.value
        ctx1.set_status(status=initial_status)

        def update_status(context, status):
            context.set_status(status=status)

        # Create threads to concurrently update the status
        thread1 = threading.Thread(target=update_status, args=(ctx1, final_status))
        thread2 = threading.Thread(target=update_status, args=(ctx2, final_status))

        # Start the threads
        thread1.start()
        thread2.start()

        # Wait for the threads to complete
        thread1.join()
        thread2.join()

        # Verify that the final status is correct
        mock_valkey.hget.return_value = final_status.value
        assert ctx1.get_status() == final_status
        assert ctx2.get_status() == final_status
