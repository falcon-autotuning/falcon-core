"""A collection of voltage states for a device."""

from typing import TYPE_CHECKING

from .dependancies import Jsonable

if TYPE_CHECKING:
    from .device_voltage_state import DeviceVoltageState
    from .typing import BaseConnection


class DeviceVoltageStates(Jsonable):
    """A collection of voltage states for a device."""

    _states: list["DeviceVoltageState"]

    def __init__(self, states: list["DeviceVoltageState"] = []):
        """Initialize the DeviceVoltageStates object."""
        self._states = states

    @property
    def states(self) -> list["DeviceVoltageState"]:
        """Returns the list of voltage states."""
        return self._states

    def add_state(self, state: "DeviceVoltageState"):
        """Add a voltage state to the collection.

        Args:
            state (DeviceVoltageState): The voltage state to add.
        """
        self._states.append(state)

    def find_state(
        self,
        connection: "BaseConnection",
    ) -> "DeviceVoltageState | None":
        """Find a voltage state by its connection.

        Args:
            connection (BaseConnection): The connection to find.

        Returns:
            DeviceVoltageState | None: The voltage state if found, otherwise None.
        """
        for state in self._states:
            if state.connection == connection:
                return state
        return None
