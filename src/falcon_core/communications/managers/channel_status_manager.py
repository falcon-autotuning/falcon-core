"""Channel status context manager for Falcon communications."""

from typing import TYPE_CHECKING

from .dependancies import random
from .locking_communication import LockingCommunication
from .status_type import ChannelStatusType

if TYPE_CHECKING:
    from .typing import Channel


class ChannelStatusManager(LockingCommunication):
    """Program status context manager for Falcon communications.

    Strictly manipulates the program status.
    """

    def __init__(
        self,
        startup_channels: list["Channel"] = [],
        startup: bool = False,
        lock_timeout: int = 5,
        max_retries: int = 3,
        retry_delay: float = 0.2,
    ):
        """Initialize the context manager.

        Channels and startup are optional. Channels are only supplied if starting

        Args:
            startup_channels: The channels to initialize.
            startup: If True, initialize the channels to idle.
            lock_timeout: Lock timeout in seconds.
            max_retries: Maximum number of retries.
            retry_delay: Delay between retries in seconds.
        """
        super().__init__(
            namespace="channel_status",
            lock_timeout=lock_timeout,
            max_retries=max_retries,
            retry_delay=retry_delay,
        )
        if startup:
            for channel in startup_channels:
                self.set(
                    key=channel,
                    value=ChannelStatusType.IDLE.value,
                )

    def _set_status(
        self,
        channel: "Channel",
        status: ChannelStatusType,
    ) -> bool:
        """Set the program status.

        Args:
            channel: The channel to set the status for.
            status: The new status.
            lock_timeout: Lock timeout in seconds.

        Returns:
            bool: True if status was set successfully, False if non-blocking and lock wasn't acquired.
        """
        return self.set(
            channel,
            status.value,
            blocking=False,
        )

    def set_status(
        self,
        channel: "Channel",
        status: ChannelStatusType,
    ) -> bool:
        """Set the program status with retries and business rules.

        Args:
            channel: The channel to set the status for.
            status: The new status.

        Returns:
            bool: True if status was set successfully, False if non-blocking and lock wasn't acquired.
        """
        return self._with_bool_retry(
            operation=self._set_status,
            channel=channel,
            status=status,
        )

    def get_status(self, channel: "Channel") -> ChannelStatusType:
        """Get the program status.

        Args:
            channel: The channel to get the status for.

        Returns:
            The current status.
        """
        return ChannelStatusType(self.get(channel))

    def get_channels(self) -> list["Channel"]:
        """Get the channels.

        Returns:
            The channels.
        """
        raw_keys = self._client.hkeys(self._namespace)
        assert isinstance(raw_keys, list)
        return [key.decode("utf-8") for key in raw_keys]

    def get_and_claim_available_channel(
        self,
    ) -> "Channel | None":
        """Get an available channel and atomically claim it.

        Randomly selects channels to check to distribute load evenly.
        Uses direct status setting to minimize overhead. If claiming
        fails due to concurrent access, automatically tries another channel.

        Args:
            lock_timeout: Lock timeout in seconds.

        Returns:
            A channel that was successfully claimed (set to BUSY), or None if none could be claimed.

        Raises:
            ValueError: If no channels are available.
        """
        # Get all channels and shuffle them for random selection
        channels = self.get_channels()
        if not channels:
            msg = "No channels available"
            raise ValueError(msg)

        # Create a random ordering
        random.shuffle(channels)

        def find_idle_channel(channel: "Channel") -> "Channel | None":
            """Check if a channel is idle."""
            status = self.get_status(channel) == ChannelStatusType.IDLE
            if status:
                self._set(
                    key=channel,
                    value=ChannelStatusType.BUSY.value,
                )
                return channel
            return None

        # Try each channel in our randomized order
        for channel in channels:
            try:
                # Check if the channel is idle
                # Try to atomically claim it - if it fails, the loop will continue to next channel
                success, result = self._lock(
                    callable=find_idle_channel,
                    target_key=channel,
                    channel=channel,
                    blocking=False,
                )
                if success and result:
                    # Successfully claimed the channel
                    return result
            except Exception:
                # If there's an error checking or setting status, just try the next channel
                continue

        # No available channels could be claimed
        return None
