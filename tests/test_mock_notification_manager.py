"""Tests for the NotificationContextManager."""

import json
from unittest.mock import MagicMock, patch

import pytest

from falcon_core.communications.managers.notification_manager import (
    NotificationManager,
)


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
        mock_client.time.return_value = (1685000000, 0)  # Mock timestamp
        mock_client.close.return_value = None
        yield mock_client


class TestMockNotificationManager:
    """Test the NotificationContextManager."""

    def test_init(self, mock_valkey):
        """Test initialization."""
        ctx = NotificationManager(my_name="test_app")

        assert ctx.namespace == "notifications"
        assert ctx._my_name == "test_app"

    def test_get_notifications_success(self, mock_valkey):
        """Test getting notifications successfully."""
        ctx = NotificationManager(my_name="test_app")
        mock_valkey.hget.return_value = json.dumps(
            [
                {
                    "from": "other_app",
                    "channel_ready": "channel1",
                    "timestamp": 1685000000,
                }
            ]
        )

        result = ctx.get_notifications(name="test_app")

        assert isinstance(result, list)
        assert len(result) == 1
        assert result[0]["from"] == "other_app"
        mock_valkey.hget.assert_called_with("notifications", "test_app")

    def test_get_notifications_empty(self, mock_valkey):
        """Test getting notifications when there are none."""
        ctx = NotificationManager(my_name="test_app")
        mock_valkey.hget.return_value = None

        result = ctx.get_notifications(name="test_app")

        assert result == []
        mock_valkey.hget.assert_called_with("notifications", "test_app")

    def test_get_notifications_exception(self, mock_valkey):
        """Test getting notifications when an exception occurs."""
        ctx = NotificationManager(my_name="test_app")
        mock_valkey.hget.side_effect = Exception("Test exception")

        result = ctx.get_notifications(name="test_app")

        assert result == []

    def test_send_notification_success(self, mock_valkey):
        """Test sending a notification successfully."""
        ctx = NotificationManager(my_name="test_app")
        mock_valkey.hget.return_value = json.dumps([])

        with patch.object(ctx, "_set_notifications") as mock_set:
            result = ctx.send_notification(name="other_app", channel="channel1")

        assert result is True
        mock_set.assert_called()

    def test_send_notification_exhaust_retries(self, mock_valkey):
        """Test sending a notification when retries are exhausted."""
        ctx = NotificationManager(my_name="test_app", max_retries=2, retry_delay=0)

        with patch.object(ctx, "_send_notification", return_value=False):
            result = ctx.send_notification(
                name="other_app",
                channel="channel1",
            )

        assert result is False

    def test_get_next_notification_success(self, mock_valkey):
        """Test getting the next notification successfully."""
        ctx = NotificationManager(my_name="test_app")
        mock_valkey.hget.return_value = json.dumps(
            [
                {
                    "from": "other_app",
                    "channel_ready": "channel1",
                    "timestamp": 1685000000,
                }
            ]
        )

        with patch.object(ctx, "_set_notifications") as mock_set:
            result = ctx.get_next_notification()

        assert result == {
            "from": "other_app",
            "channel_ready": "channel1",
            "timestamp": 1685000000,
        }
        mock_set.assert_called_with("test_app", [])

    def test_get_next_notification_empty(self, mock_valkey):
        """Test getting the next notification when there are none."""
        ctx = NotificationManager(my_name="test_app")
        mock_valkey.hget.return_value = json.dumps([])

        result = ctx.get_next_notification()

        assert result is None

    def test_get_next_notification_exhaust_retries(self, mock_valkey):
        """Test getting the next notification when retries are exhausted."""
        ctx = NotificationManager(my_name="test_app", max_retries=2, retry_delay=0)

        with patch.object(ctx, "_get_next_notification", return_value=None):
            result = ctx.get_next_notification()

        assert result is None

    def test_has_notifications_true(self, mock_valkey):
        """Test has_notifications when there are notifications."""
        ctx = NotificationManager(my_name="test_app")
        mock_valkey.hget.return_value = json.dumps(
            [
                {
                    "from": "other_app",
                    "channel_ready": "channel1",
                    "timestamp": 1685000000,
                }
            ]
        )

        result = ctx.has_notifications()

        assert result is True

    def test_has_notifications_false(self, mock_valkey):
        """Test has_notifications when there are no notifications."""
        ctx = NotificationManager(my_name="test_app")
        mock_valkey.hget.return_value = json.dumps([])

        result = ctx.has_notifications()

        assert result is False
