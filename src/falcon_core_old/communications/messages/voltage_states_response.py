"""A standard communication request."""

from typing import TYPE_CHECKING

from .base_message import BaseMessage

if TYPE_CHECKING:
    from .typing import DeviceVoltageStates


class VoltageStatesResponse(BaseMessage):
    """A standard communication request."""

    _states: "DeviceVoltageStates"

    def __init__(self, message: str, states: "DeviceVoltageStates"):
        """Initialize the StandardRequest object."""
        super().__init__(message)
        self._states = states

    @property
    def states(self) -> "DeviceVoltageStates":
        """Get the states."""
        return self._states
