"""Tests for the ChannelStatusContextManager."""

from unittest.mock import MagicMock, patch

import pytest

from falcon_core.communications.managers.channel_status_manager import (
    ChannelStatusManager,
)
from falcon_core.communications.managers.status_type import ChannelStatusType


@pytest.fixture
def mock_valkey():
    """Mock the valkey client."""
    with patch(
        "falcon_core.communications.managers.dependancies.valkey.Valkey"
    ) as MockValkey:
        # Create mock client and methods
        mock_client = MagicMock()
        MockValkey.return_value = mock_client
        # Setup get/set methods that will be used by BaseGlobalContextManager
        mock_client.hget.return_value = None  # Default return value
        mock_client.hset.return_value = True  # Default return value for successful set
        mock_client.hkeys.return_value = []  # Default return value for hkeys
        mock_client.close.return_value = None
        yield mock_client


class TestMockChannelStatusManager:
    """Test the ChannelStatusContextManager."""

    def test_init_with_startup(self, mock_valkey):
        """Test initialization with startup=True."""
        channels = ["channel1", "channel2"]
        ctx = ChannelStatusManager(startup_channels=channels, startup=True)

        assert ctx.namespace == "channel_status"
        # Validate that the status is set correctly for each channel
        mock_valkey.hset.assert_any_call(
            "channel_status", "channel1", ChannelStatusType.IDLE.value
        )
        mock_valkey.hset.assert_any_call(
            "channel_status", "channel2", ChannelStatusType.IDLE.value
        )
        assert mock_valkey.hset.call_count == len(channels)

    def test_init_without_startup(self, mock_valkey):
        """Test initialization with startup=False."""
        ctx = ChannelStatusManager(startup=False)

        assert ctx.namespace == "channel_status"
        # Ensure no status is set during initialization
        mock_valkey.hset.assert_not_called()

    def test_set_status_success(self, mock_valkey):
        """Test setting the status successfully."""
        ctx = ChannelStatusManager()
        channel = "test_channel"
        result = ctx.set_status(channel=channel, status=ChannelStatusType.BUSY)

        assert result is True
        mock_valkey.hset.assert_called_with(
            "channel_status", "test_channel", ChannelStatusType.BUSY.value
        )

    def test_set_status_exhaust_retries(self, mock_valkey):
        """Test setting the status when retries are exhausted."""
        ctx = ChannelStatusManager(
            max_retries=2,
            retry_delay=0,
        )
        mock_valkey.set.return_value = False
        channel = "test_channel"

        # Simulate a scenario where the status cannot be set
        with patch.object(ctx, "_set_status", return_value=False):
            result = ctx.set_status(
                channel=channel,
                status=ChannelStatusType.BUSY,
            )

        assert result is False

    def test_get_status(self, mock_valkey):
        """Test getting the current status."""
        ctx = ChannelStatusManager()
        mock_valkey.hget.return_value = ChannelStatusType.IDLE.value
        channel = "test_channel"

        result = ctx.get_status(channel=channel)

        assert result == ChannelStatusType.IDLE

    def test_get_channels(self, mock_valkey):
        """Test getting the channels."""
        ctx = ChannelStatusManager()
        mock_valkey.hkeys.return_value = [b"channel1", b"channel2"]

        result = ctx.get_channels()

        assert result == ["channel1", "channel2"]
        mock_valkey.hkeys.assert_called_with("channel_status")

    def test_get_and_claim_available_channel_success(self, mock_valkey):
        """Test getting and claiming an available channel successfully."""
        ctx = ChannelStatusManager()
        mock_valkey.hkeys.return_value = [b"channel1"]
        mock_valkey.hget.return_value = ChannelStatusType.IDLE.value.encode("utf-8")
        channel = "channel1"

        with patch.object(ctx, "_set_status", return_value=True):
            result = ctx.get_and_claim_available_channel()

        assert result == channel
        mock_valkey.hget.assert_called_with("channel_status", channel)

    def test_get_and_claim_available_channel_none_available(self, mock_valkey):
        """Test getting and claiming when no channels are available."""
        ctx = ChannelStatusManager()
        mock_valkey.hkeys.return_value = [b"channel1", b"channel2"]
        mock_valkey.hget.return_value = ChannelStatusType.BUSY.value.encode("utf-8")

        with patch.object(ctx, "_set_status", return_value=False):
            result = ctx.get_and_claim_available_channel()

        assert result is None

    def test_get_and_claim_available_channel_no_channels(self, mock_valkey):
        """Test getting and claiming when no channels exist."""
        ctx = ChannelStatusManager()
        mock_valkey.hkeys.return_value = []

        with pytest.raises(ValueError, match="No channels available"):
            ctx.get_and_claim_available_channel()
