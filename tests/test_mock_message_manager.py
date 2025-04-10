"""Tests for the MessageContextManager."""

import json
from unittest.mock import MagicMock, patch

import pytest

from falcon_core.communications.managers.dependancies import Jsonable
from falcon_core.communications.managers.message_manager import (
    MessageManager,
)


class TestJsonable(Jsonable):
    """Test Jsonable implementation for testing."""

    _value: str

    def __init__(self, value: str = "test_value"):
        self._value = value

    def to_json(self) -> str:
        return json.dumps({"value": self._value})

    @property
    def value(self) -> str:
        return self._value


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


class TestMockMessageManager:
    """Test the MessageContextManager."""

    def test_init(self, mock_valkey):
        """Test initialization."""
        ctx = MessageManager(channel="test_channel")

        assert ctx._channel == "test_channel"
        assert ctx._lock_timeout == 5
        assert ctx._max_retries == 3
        assert ctx._retry_delay == 0.2
        assert ctx.namespace == "messages"

    def test_publish_message_success(self, mock_valkey):
        """Test publishing a message successfully."""
        ctx = MessageManager(channel="test_channel")
        test_msg = TestJsonable("hello")

        with patch.object(ctx, "_publish_message", return_value=True) as mock_publish:
            result = ctx.publish_message(message=test_msg)

        assert result is True
        mock_publish.assert_called_with(message=test_msg)

    def test_publish_message_exhaust_retries(self, mock_valkey):
        """Test publishing a message when retries are exhausted."""
        ctx = MessageManager(channel="test_channel")
        test_msg = TestJsonable("hello")

        with patch.object(ctx, "_publish_message", return_value=False):
            result = ctx.publish_message(message=test_msg)

        assert result is False

    def test_get_message_success(self, mock_valkey):
        """Test getting a message successfully."""
        ctx = MessageManager(channel="test_channel")
        mock_valkey.hget.return_value = json.dumps(
            {"__class__": "TestJsonable", "value": "received"}
        )

        result = ctx.get_message()

        assert isinstance(result, TestJsonable)
        assert result.value == "received"
        mock_valkey.hget.assert_called_with("messages", "test_channel")

    def test__publish_message_success(self, mock_valkey):
        """Test _publish_message successfully."""
        ctx = MessageManager(channel="test_channel")
        test_msg = TestJsonable("hello")
        mock_valkey.hset.return_value = True

        result = ctx._publish_message(message=test_msg)

        assert result is True
        mock_valkey.hset.assert_called_with(
            "messages", "test_channel", '{"value": "hello"}'
        )
