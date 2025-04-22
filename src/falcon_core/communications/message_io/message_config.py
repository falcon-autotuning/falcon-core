"""A configuration for a messaging system."""

from typing import TYPE_CHECKING

from .dependancies import dataclass

if TYPE_CHECKING:
    from .typing import ApplicationName, Channel


@dataclass
class MessageConfig:
    """A configuration for a messaging system."""

    _application_name: "ApplicationName"
    _channels: list["Channel"]
    _lock_timeout: int = 5
    _max_retries: int = 3
    _retry_delay: float = 0.2
    _message_timeout: float = 3600.0

    @property
    def application_name(self) -> "ApplicationName":
        """The name of the application using the messaging system."""
        return self._application_name

    @property
    def lock_timeout(self) -> int:
        """The timeout for acquiring a lock on a message."""
        return self._lock_timeout

    @property
    def max_retries(self) -> int:
        """The maximum number of retries for sending a message."""
        return self._max_retries

    @property
    def retry_delay(self) -> float:
        """The delay between retries for sending a message."""
        return self._retry_delay

    @property
    def message_timeout(self) -> float:
        """The timeout for processing a message."""
        return self._message_timeout

    @property
    def channels(self) -> list["Channel"]:
        """The list of communication channels for the messaging system."""
        return self._channels
