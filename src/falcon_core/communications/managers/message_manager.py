"""Base class for managing message context in Falcon communications."""

from typing import TYPE_CHECKING

from .dependancies import Jsonable
from .locking_communication import LockingCommunication

if TYPE_CHECKING:
    from .typing import Channel


class MessageManager(LockingCommunication):
    """Message context manager for Falcon communications.

    This class is responsible for managing the message context in Falcon communications.
    It provides methods to set and get message context information.
    """

    _channel: "Channel"
    _lock_timeout: int
    _max_retries: int
    _retry_delay: float

    def __init__(
        self,
        channel: "Channel",
        lock_timeout: int = 5,
        max_retries: int = 3,
        retry_delay: float = 0.2,
    ):
        """Initialize the message context manager.

        Args:
            channel: The channel to manage.
            lock_timeout: Lock timeout in seconds.
            max_retries: Maximum number of retries.
            retry_delay: Delay between retries in seconds.
        """
        super().__init__(namespace="messages")
        self._channel = channel
        self._lock_timeout = lock_timeout
        self._max_retries = max_retries
        self._retry_delay = retry_delay

    def _publish_message(
        self,
        message: "Jsonable",
    ) -> bool:
        """Publishes the message.

        Args:
            message: The message to send.

        Returns:
            bool: True if the message was sent successfully, False if non-blocking and lock wasn't acquired.
        """
        return self.set(
            key=self._channel,
            value=message.to_json(),
            blocking=False,
        )

    def publish_message(
        self,
        message: "Jsonable",
    ) -> bool:
        """Publishes a message and will retry if blocked.

        Args:
            message: The message to send.

        Returns:
            bool: True if message was sent successfully, False if non-blocking and lock wasn't acquired.
        """
        return self._with_bool_retry(
            operation=self._publish_message,
            message=message,
        )

    def get_message(
        self,
    ) -> "Jsonable":
        """Returns the message from the channel."""
        raw = self.get(self._channel)
        return Jsonable.from_json(raw)
