"""The StateDF object is a data structure that represents a snapshot of the state of a device."""

from typing import TYPE_CHECKING

from .dependancies import Jsonable

if TYPE_CHECKING:
    from .typing import BaseConnection, SymbolUnit


class DeviceVoltageState(Jsonable):
    """The state of a single connection on a device."""

    _connection: "BaseConnection"
    _voltage: float
    _unit: "SymbolUnit"

    def __init__(
        self,
        connection: "BaseConnection",
        voltage: float,
        unit: "SymbolUnit",
    ):
        """Initialize the DeviceVoltageState object.

        Args:
            connection (BaseConnection): The connection of the device.
            voltage (float): The voltage of the device.
            unit (SymbolUnit): The unit of the voltage.
        """
        self._connection = connection
        self._voltage = voltage
        self._unit = unit

    @property
    def connection(self) -> "BaseConnection":
        """Returns the connection of the device."""
        return self._connection

    @property
    def voltage(self) -> float:
        """Returns the voltage of the device."""
        return self._voltage

    @property
    def unit(self) -> "SymbolUnit":
        """Returns the unit of the voltage."""
        return self._unit
