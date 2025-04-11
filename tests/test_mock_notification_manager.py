"""Tests for the NotificationContextManager."""

import json
from unittest.mock import MagicMock, patch

import pytest

from falcon_core.communications.managers.notification_manager import (
    NotificationManager,
)
from falcon_core.communications.notifications import Notification, Notifications


@pytest.fixture
def mock_valkey():
    """Mock the valkey client."""
    with patch(
        "falcon_core.communications.managers.dependancies.valkey.Valkey"
    ) as MockValkey:
        # Create mock client and methods
        mock_client = MagicMock()
        MockValkey.return_value = mock_client
        yield mock_client


@pytest.fixture(autouse=True)
def reset_mocks(mock_valkey):
    """Reset all mocks before each test."""
    mock_valkey.reset_mock()
    mock_valkey.hget.return_value = None
    mock_valkey.hset.return_value = True
    mock_valkey.time.return_value = (1685000000, 0)
    mock_valkey.close.return_value = None


@pytest.fixture
def notification():
    """Prepares a Notification."""
    return Notification(
        channel="channel1",
        name="other_app",
        timestamp=1685000000,
    )


@pytest.fixture
def notifications():
    """Prepares a Notifications."""
    return Notifications(
        [
            Notification(
                channel="channel1",
                name="other_app",
                timestamp=1685000000,
            )
        ]
    )


class TestMockNotificationManager:
    """Test the NotificationContextManager."""

    def test_init(self, mock_valkey):
        """Test initialization."""
        ctx = NotificationManager(my_name="test_app")

        assert ctx.namespace == "notifications"
        assert ctx._my_name == "test_app"

    def test_get_notifications_success(self, mock_valkey, notifications: Notifications):
        """Test getting notifications successfully."""
        ctx = NotificationManager(my_name="test_app")
        mock_valkey.hget.return_value = notifications.to_json().encode("utf-8")

        result = ctx.get_notifications(name="test_app")

        assert isinstance(result, Notifications)
        assert len(result) == 1
        assert result.pop(0).name == "other_app"
        mock_valkey.hget.assert_called_with("notifications", "test_app")

    def test_get_notifications_empty(self, mock_valkey):
        """Test getting notifications when there are none."""
        ctx = NotificationManager(my_name="test_app")
        mock_valkey.hget.return_value = None

        result = ctx.get_notifications(name="test_app")

        assert result == Notifications()
        mock_valkey.hget.assert_called_with("notifications", "test_app")

    def test_get_notifications_exception(self, mock_valkey):
        """Test getting notifications when an exception occurs."""
        ctx = NotificationManager(my_name="test_app")
        mock_valkey.hget.side_effect = Exception("Test exception")

        result = ctx.get_notifications(name="test_app")

        assert result == Notifications()

    def test_send_notification_success(self, mock_valkey):
        """Test sending a notification successfully."""
        ctx = NotificationManager(my_name="test_app")
        mock_valkey.hget.return_value = Notifications().to_json().encode("utf-8")

        with patch.object(ctx, "_set_notifications") as mock_set:
            result = ctx.send_notification(name="other_app", channel="channel1")

        assert result is True
        mock_set.assert_called()

    def test_get_next_notification_success(
        self,
        mock_valkey,
        notification: Notification,
    ):
        """Test getting the next notification successfully."""
        ctx = NotificationManager(my_name="test_app")
        mock_valkey.hget.return_value = (
            Notifications([notification]).to_json().encode("utf-8")
        )

        with patch.object(ctx, "_set_notifications") as mock_set:
            result = ctx.get_next_notification()

            assert result == notification
            mock_set.assert_called_with("test_app", Notifications())

    def test_send_notification_exhaust_retries(self, mock_valkey):
        """Test sending a notification when retries are exhausted."""
        ctx = NotificationManager(my_name="test_app", max_retries=2, retry_delay=0)

        with patch.object(ctx, "_send_notification", return_value=False):
            result = ctx.send_notification(
                name="other_app",
                channel="channel1",
            )

        assert result is False

    def test_get_next_notification_empty(self, mock_valkey):
        """Test getting the next notification when there are none."""
        ctx = NotificationManager(my_name="test_app")
        mock_valkey.hget.return_value = Notifications().to_json().encode("utf-8")
        print(Notifications())
        print(Notifications.from_json(Notifications().to_json()))
        result = ctx.get_next_notification()

        assert result is None

    def test_get_next_notification_exhaust_retries(self, mock_valkey):
        """Test getting the next notification when retries are exhausted."""
        ctx = NotificationManager(my_name="test_app", max_retries=2, retry_delay=0)

        with patch.object(ctx, "_get_next_notification", return_value=None):
            result = ctx.get_next_notification()

        assert result is None

    def test_has_notifications_false(self, mock_valkey):
        """Test has_notifications when there are no notifications."""
        ctx = NotificationManager(my_name="test_app")
        mock_valkey.hget.return_value = json.dumps([])

        result = ctx.has_notifications()

        assert result is False
