"""Notification context manager for Falcon communications."""

from typing import TYPE_CHECKING

from .dependancies import Notification, Notifications
from .locking_communication import LockingCommunication

if TYPE_CHECKING:
    from .typing import ApplicationName, Channel


class NotificationManager(LockingCommunication):
    """Notification context manager for Falcon communications.

    Handles sending and receiving notifications between applications.
    Uses the base global context manager's locking mechanism to ensure thread safety.
    """

    _my_name: "ApplicationName"

    def __init__(
        self,
        my_name: "ApplicationName",
        lock_timeout: int = 5,
        max_retries: int = 3,
        retry_delay: float = 0.3,
    ):
        """Initialize the notification context manager.

        Args:
            my_name: The name of the application.
            startup: If True, startup the notification system.
            lock_timeout: Lock timeout in seconds.
            max_retries: Maximum number of retries.
            retry_delay: Delay between retries in seconds.
        """
        super().__init__(
            namespace="notifications",
            lock_timeout=lock_timeout,
            max_retries=max_retries,
            retry_delay=retry_delay,
        )
        self._my_name = my_name

    def get_notifications(
        self,
        name: "ApplicationName",
    ) -> "Notifications":
        """Get the current notifications for an application.

        Args:
            name: The application to get notifications for.

        Returns:
            List of notification dictionaries.
        """
        try:
            notifications_json = self._get(key=name)
            if not notifications_json:
                return Notifications()
            return Notifications.from_json(notifications_json)
        except Exception:
            return Notifications()

    def _set_notifications(
        self,
        name: "ApplicationName",
        notifications: "Notifications",
    ):
        """Set the notifications for an application.

        Not thread-safe, should be called within a lock.

        Args:
            name: The application to set notifications for.
            notifications: The list of notification dictionaries.
        """
        self._set(name, notifications.to_json())

    def _send_notification(
        self,
        name: "ApplicationName",
        channel: "Channel",
    ) -> bool:
        """Send a notification to another application.

        Uses the _lock method to ensure thread safety when updating the notification queue.

        Args:
            name: The application to send the notification to.
            channel: The channel holding the data.
            lock_timeout: Timeout for the lock in seconds.

        Returns:
            True if notification was sent successfully.
        """

        # Define the update function to run under lock protection
        def update_notifications():
            # Get current notifications
            notifications = self.get_notifications(name=name)

            timestamp = self._client.time()  # Server time for consistency
            assert isinstance(timestamp, tuple)

            # Add new notification
            notifications.append(
                Notification(
                    channel=channel,
                    name=self._my_name,
                    timestamp=timestamp[0],
                )
            )

            # Update notifications
            self._set_notifications(name=name, notifications=notifications)

        # Use the lock mechanism from the base class
        return self._lock(
            callable=update_notifications,
            target_key=name,
            blocking=False,
        )[0]

    def send_notification(
        self,
        name: "ApplicationName",
        channel: "Channel",
    ) -> bool:
        """Send a notification to another application.

        Args:
            name: The application to send the notification to.
            channel: The channel holding the data.

        Returns:
            True if notification was sent successfully.
        """
        return self._with_bool_retry(
            operation=self._send_notification,
            name=name,
            channel=channel,
        )

    def _get_next_notification(self) -> "Notification | None":
        """Get and remove the oldest notification for this application.

        Uses the _lock method to ensure thread safety when updating the notification queue.

        Args:
            lock_timeout: Timeout for the lock in seconds.

        Returns:
            The oldest notification or None if no notifications.
        """

        # Define the update function to run under lock protection
        def process_notification():
            # Get current notifications
            notifications = self.get_notifications(self._my_name)

            if not notifications or len(notifications) == 0:
                return None

            # Get oldest notification
            result = notifications.pop(0)

            # Update notifications
            self._set_notifications(self._my_name, notifications)
            return result

        # Use the lock mechanism from the base class
        success, result = self._lock(
            callable=process_notification,
            target_key=self._my_name,
            blocking=False,
        )

        return result if success else None

    def get_next_notification(self) -> "Notification | None":
        """Get and remove the oldest notification for this application.

        Returns:
            The oldest notification or None if no notifications.
        """
        return self._with_retry(
            operation=self._get_next_notification,
        )

    def has_notifications(self) -> bool:
        """Check if this application has any pending notifications.

        Returns:
            True if there are notifications.
        """
        notifications = self.get_notifications(name=self._my_name)
        return len(notifications) > 0
