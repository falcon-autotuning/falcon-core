"""Base structure for message I/O classes."""

from typing import TYPE_CHECKING

from .dependancies import (
    ChannelStatusManager,
    ChannelStatusType,
    MessageManager,
    NotificationManager,
    ProgramStatusManager,
    ProgramStatusType,
    time,
)

if TYPE_CHECKING:
    from .message_config import MessageConfig
if TYPE_CHECKING:
    from .typing import (
        ApplicationName,
        Channel,
        Jsonable,
        LockingCommunication,
        Notification,
        ProcessName,
    )


class BaseMessageIO:
    """Base class for message I/O operations.

    This class is responsible for sending and receiving messages.
    It serves as a base class for specific message I/O implementations.
    """

    _timeout: float
    _application_name: "ApplicationName"
    _my_name: "ProcessName"
    _lock_timeout: int
    _max_retries: int
    _retry_delay: float

    def __init__(
        self,
        message_config: "MessageConfig",
        process_name: "ProcessName | None" = None,
        startup_program: bool = False,
        startup: bool = False,
    ):
        """Initialize the message I/O object.

        Args:
            message_config: The message configuration object.
            process_name: The name of the process. If None, use the application name.
            startup: If True, initialize the program status and setup channels
            startup_program: If True, initialize the program status to started.
        """
        application_name = message_config.application_name
        if startup | startup_program:
            ProgramStatusManager(
                startup=startup_program | startup,
                application_name=application_name,
            )
        if startup:
            ChannelStatusManager(
                startup=startup,
                startup_channels=message_config.channels,
            )
        self._timeout = message_config.message_timeout
        self._my_name = process_name if process_name else application_name
        self._lock_timeout = message_config.lock_timeout
        self._max_retries = message_config.max_retries
        self._retry_delay = message_config.retry_delay
        self._application_name = application_name

    def _create_manager(
        self,
        manager_class: type["LockingCommunication"],
        **kwargs,
    ) -> "LockingCommunication":
        """Create a manager with default lock parameters.

        Args:
            manager_class: The class of the manager to create.
            kwargs: Additional arguments for the manager.

        Returns:
            LockingCommunication: The created manager instance.
        """
        manager_kwargs = {
            "lock_timeout": self._lock_timeout,
            "max_retries": self._max_retries,
            "retry_delay": self._retry_delay,
            **kwargs,
        }
        return manager_class(**manager_kwargs)

    # Create specialized manager factory methods

    def _program_status_manager(
        self,
        application_name: "ApplicationName | None" = None,
        **kwargs,
    ) -> ProgramStatusManager:
        """Create a program status manager for a specific application.

        Args:
            application_name: The name of the application.
            kwargs: Additional arguments for the manager.

        Returns:
            ProgramStatusManager: The created program status manager instance.
        """
        man = self._create_manager(
            ProgramStatusManager,
            application_name=application_name
            if application_name
            else self._application_name,
            **kwargs,
        )
        assert isinstance(man, ProgramStatusManager)
        return man

    def _channel_status_manager(
        self,
        **kwargs,
    ) -> ChannelStatusManager:
        """Create a channel status manager.

        Args:
            kwargs: Additional arguments for the manager.

        Returns:
            ChannelStatusManager: The created channel status manager instance.
        """
        man = self._create_manager(
            ChannelStatusManager,
            **kwargs,
        )
        assert isinstance(man, ChannelStatusManager)
        return man

    def _message_manager(
        self,
        channel: "Channel",
        **kwargs,
    ):
        """Create a message manager for a specific channel.

        Args:
            channel: The channel to manage.
            kwargs: Additional arguments for the manager.

        Returns:
            MessageManager: The created message manager instance.
        """
        man = self._create_manager(
            MessageManager,
            channel=channel,
            **kwargs,
        )
        assert isinstance(man, MessageManager)
        return man

    def _notification_manager(
        self,
        **kwargs,
    ):
        """Create a notification manager.

        Args:
            kwargs: Additional arguments for the manager.

        Returns:
            NotificationManager: The created notification manager instance.
        """
        man = self._create_manager(
            NotificationManager,
            my_name=self._my_name,
            **kwargs,
        )
        assert isinstance(man, NotificationManager)
        return man

    def check_communication_status(
        self,
        name: "ApplicationName",
    ):
        """Manage the communication status.

        Needs to be called immediately before IO communication.
        This function will block until the program is running or stopped.

        Args:
            name: The name of the application.

        Raises:
            TimeoutError: If the timeout is exceeded.
            RuntimeError: If the program is stopped.
        """
        starting_time = time.time()
        while self._timeout > time.time() - starting_time:
            if self.check_program_running(name=name):
                return
            if self.check_program_stopped(name=name):
                msg = "Program is stopped."
                raise RuntimeError(msg)
            time.sleep(self._retry_delay)
        msg = "Timeout exceeded."
        raise TimeoutError(msg)

    def wait_for_channel_opening(self) -> "Channel":
        """Wait for the channel to be available.

        This function will block until the channel is available.

        Returns:
            The available channel.

        Raises:
            TimeoutError: If the timeout is exceeded.
        """
        starting_time = time.time()
        while self._timeout > time.time() - starting_time:
            channel = self.find_available_channel()
            if channel is not None:
                return channel
            time.sleep(self._retry_delay)
        msg = "Timeout exceeded."
        raise TimeoutError(msg)

    def wait_for_notification(self) -> "Notification":
        """Wait for a notification.

        This function will block until a notification is available.

        Returns:
            The notification.

        Raises:
            TimeoutError: If the timeout is exceeded.
        """
        starting_time = time.time()
        while self._timeout > time.time() - starting_time:
            notification = self.check_notifications()
            if notification is not None:
                return notification
            time.sleep(self._retry_delay)
        msg = "Timeout exceeded."
        raise TimeoutError(msg)

    def check_program_running(
        self,
        name: "ApplicationName",
    ) -> bool:
        """Check the program status.

        Args:
            name: The name of the application.

        Returns:
            True if the program is running, False otherwise.
        """
        with self._program_status_manager(application_name=name) as ctx:
            return ctx.get_status() == ProgramStatusType.RUNNING

    def check_program_stopped(
        self,
        name: "ApplicationName",
    ) -> bool:
        """Check the program status.

        Args:
            name: The name of the application.

        Returns:
            True if the program is stopped, False otherwise.
        """
        with self._program_status_manager(application_name=name) as ctx:
            return ctx.get_status() == ProgramStatusType.STOPPED

    def publish(
        self,
        channel: "Channel",
        message: "Jsonable",
    ):
        """Publish a message to the channel.

        Args:
            channel: The channel to publish to.
            message: The message to publish.
        """
        with self._message_manager(channel=channel) as ctx:
            ctx.publish_message(message)

    def find_available_channel(self) -> "Channel | None":
        """Find the nearest channel.

        Args:
            lock_timeout: Timeout for the lock.

        Returns:
            The nearest channel, or None if none are available.
        """
        with self._channel_status_manager() as ctx:
            return ctx.get_and_claim_available_channel()

    def toggle_channel_status(
        self,
        channel: "Channel",
    ) -> bool:
        """Toggle the channel status.

        Args:
            channel: The channel to toggle.

        Returns:
            bool: True if the status was toggled successfully, False otherwise.
        """
        with ChannelStatusManager() as ctx:
            status = ctx.get_status(channel=channel)
        if status == ChannelStatusType.BUSY:
            toggled_status = ChannelStatusType.FINISHED
        else:
            toggled_status = ChannelStatusType.IDLE

        with self._channel_status_manager() as ctx:
            return ctx.set_status(
                channel=channel,
                status=toggled_status,
            )

    def alert_target(
        self,
        name: "ApplicationName",
        channel: "Channel",
    ):
        """Notify the target application.

        Args:
            name: The name of the application to notify.
            channel : The channel the message is on.
        """
        with self._notification_manager() as ctx:
            ctx.send_notification(
                name=name,
                channel=channel,
            )

    def collect_message(
        self,
        channel: "Channel",
    ) -> "Jsonable":
        """Collect a message from the channel.

        Args:
            channel: The channel to collect from.

        Returns:
            The collected message.
        """
        with self._message_manager(channel=channel) as ctx:
            return ctx.get_message()

    def retrieve_message_from_notification(
        self,
        notification: "Notification",
    ) -> "Jsonable":
        """Read a notification and retrieve the message.

        Args:
            notification: The notification to read.

        Returns:
            The received message.
        """
        channel = notification.channel
        message = self.collect_message(channel=channel)
        self.toggle_channel_status(channel=channel)
        return message

    def check_notifications(self) -> "Notification | None":
        """Check for notifications.

        Returns:
            The notification if available, None otherwise.
        """
        with self._notification_manager() as ctx:
            if ctx.has_notifications():
                return ctx.get_next_notification()
            return None

    def command(
        self,
        name: "ApplicationName",
        command: "Jsonable",
    ) -> None:
        """Send a command to the channel.

        Args:
            command: The command to send.
            name: The name of the application we are sending the command to.
        """
        self.check_communication_status(name=name)
        self.check_communication_status(name=self._application_name)
        channel = self.wait_for_channel_opening()
        self.publish(
            channel=channel,
            message=command,
        )
        self.toggle_channel_status(channel=channel)
        self.alert_target(name=name, channel=channel)

    def listen(self) -> "Jsonable":
        """Listen for incoming messages.

        Returns:
            The received message.
        """
        self.check_communication_status(name=self._application_name)
        notification = self.wait_for_notification()
        return self.retrieve_message_from_notification(notification=notification)
