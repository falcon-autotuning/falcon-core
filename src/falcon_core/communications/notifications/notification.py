"""A notification from the messaging system."""

from typing import TYPE_CHECKING

from .dependancies import Jsonable

if TYPE_CHECKING:
    from .typing import ApplicationName, Channel


class Notification(Jsonable):
    """Notification class for Falcon communications."""

    _name: str
    _channel: str
    _timestamp: int

    def __init__(
        self,
        channel: "Channel" = "",
        name: "ApplicationName" = "",
        timestamp: int = 0,
    ):
        """Initialize the notification.

        Args:
            channel: The channel for the notification.
            name: The name of the application.
            timestamp: The timestamp for the notification.
        """
        self._channel = str(channel)
        self._name = str(name)
        self._timestamp = int(timestamp)

    @property
    def channel(self) -> "Channel":
        """Return the channel for the notification."""
        return self._channel

    @property
    def name(self) -> "ApplicationName":
        """Return the application name for the notification."""
        return self._name

    @property
    def timestamp(self) -> int:
        """Return the timestamp for the notification."""
        return self._timestamp
