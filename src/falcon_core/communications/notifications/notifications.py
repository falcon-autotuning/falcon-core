"""A collection of Notification classes for Falcon communications."""

from typing import TYPE_CHECKING

from .dependancies import Jsonable

if TYPE_CHECKING:
    from .notification import Notification


class Notifications(Jsonable):
    """A collection of notifications."""

    _notifications: list["Notification"]

    def __init__(self, notifications: list["Notification"] = []):
        """Initialize the notifications collection.

        Args:
            notifications: A list of Notification objects.
        """
        self._notifications = notifications

    @property
    def notifications(self) -> list["Notification"]:
        """Return the list of notifications."""
        return self._notifications

    def append(self, notification: "Notification") -> None:
        """Append a notification to the collection.

        Args:
            notification: A Notification object to append.
        """
        self._notifications.append(notification)

    def pop(
        self,
        index: int = -1,
    ) -> "Notification":
        """Pop a notification from the collection.

        Args:
            index: The index of the notification to pop. Defaults to -1 (last notification).

        Returns:
            The last Notification object in the collection.
        """
        return self._notifications.pop(index)

    def __len__(self) -> int:
        """Return the number of notifications in the collection."""
        return len(self._notifications)
