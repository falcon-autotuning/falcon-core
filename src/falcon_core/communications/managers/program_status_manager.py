"""Program status context manager for Falcon communications."""

from typing import TYPE_CHECKING

from .locking_communication import LockingCommunication
from .status_type import ProgramStatusType

if TYPE_CHECKING:
    from .typing import ApplicationName


class ProgramStatusManager(LockingCommunication):
    """Program status context manager for Falcon communications.

    Strictly manipulates the program status.
    """

    _name: "ApplicationName"

    def __init__(
        self,
        application_name: "ApplicationName",
        startup: bool = False,
        lock_timeout: int = 5,
        max_retries: int = 3,
        retry_delay: float = 0.2,
    ):
        """Initialize the context manager.

        If starting up, it will start the application as the name provided.

        Args:
            application_name: The name of the application to program.
            my_name: The name of the application.
            startup: If True, initialize the status to started.
            lock_timeout: Lock timeout in seconds.
            max_retries: Maximum number of retries.
            retry_delay: Delay between retries in seconds.
        """
        super().__init__(
            namespace="program_status",
            lock_timeout=lock_timeout,
            max_retries=max_retries,
            retry_delay=retry_delay,
        )
        self._name = application_name
        if startup:
            assert application_name is not None, (
                "Application name must be provided on startup."
            )
            self.set(
                key=application_name,
                value=ProgramStatusType.RUNNING.value,
            )
        # otherwise someone else will have set it

    def _set_status(
        self,
        status: ProgramStatusType,
    ) -> bool:
        """Set the program status using distributed locks.

        Args:
            status: The new status.

        Returns:
            bool: True if status was set successfully, False if non-blocking and lock wasn't acquired.
        """
        return self.set(
            key=self._name,
            value=status.value,
            blocking=False,
        )

    def validated_set_status(
        self,
        status: ProgramStatusType,
    ) -> bool:
        """Set the program status with retries and business rules.

        Args:
            status: The new status.

        Returns:
            bool: True if status was set successfully, False if business rules
                prevented the change or retries were exhausted.
        """
        try:
            current_status = self.get_status()

            # Business rule: Cannot change status if already stopped
            if current_status == ProgramStatusType.STOPPED:
                return False

        except Exception:
            # If we can't get the current status, we'll try to set it anyway
            pass

        return self._set_status(status=status)

    def set_status(
        self,
        status: ProgramStatusType,
    ) -> bool:
        """Set the program status with retries and business rules.

        Args:
            status: The new status.
            name: The application to set the status for.

        Returns:
            bool: True if status was set successfully, False if business rules
                prevented the change or retries were exhausted.
        """
        return self._with_bool_retry(
            operation=self.validated_set_status,
            status=status,
        )

    def get_status(self) -> ProgramStatusType:
        """Get the program status.

        Returns:
            The current status.
        """
        return ProgramStatusType(self.get(self._name))
