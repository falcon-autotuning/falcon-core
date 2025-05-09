"""The base unit type of port that all instrument ports consist of."""

from typing import TYPE_CHECKING

from .constants import INSTRUMENT_TYPES
from .dependancies import Instrument, Jsonable, Units

if TYPE_CHECKING:
    from .dependancies import Instrument
    from .typing import Connection, SymbolUnit


class InstrumentPort(Jsonable):
    """The base unit type of port that all instrument ports consist of.

    Note that this class stores attributes and is meant for users to lookup
    information about the port. The actual connection is stored in the
    Connection object.

    The instrument_type comes from the INSTRUMENT_TYPES constant in the
    constants module.
    """

    _defualt_name: str
    _pseudo_name: "Connection | None"
    _instrument_type: "Instrument"
    _units: "SymbolUnit"
    _description: str

    def __init__(
        self,
        default_name: str,
        pseudo_name: "Connection | None" = None,
        instrument_type: "Instrument" = INSTRUMENT_TYPES.DC_VOLTAGE_SOURCE,
        units: "SymbolUnit" = Units.VOLT,
        description: str = "",
    ) -> None:
        """Initialize the InstrumentPort object.

        Args:
            default_name: The default name of the port.
            pseudo_name: The pseudo name of the port.
            instrument_type: The type of instrument that the port is connected
                to.
            units: The units of the port.
            description: The description of the port.

        Raises:
            ValueError: If the default name is an empty string.
        """
        if not default_name:
            msg = "The default name of the port cannot be an empty string."
            raise ValueError(msg)
        self._defualt_name = default_name
        self._pseudo_name = pseudo_name
        self._instrument_type = instrument_type
        self._units = units
        self._description = description

    @property
    def default_name(self) -> str:
        """Return the default name of the port."""
        return self._defualt_name

    @property
    def pseudo_name(self) -> "Connection":
        """Return the pseudo name of the port.

        Raises:
            ValueError: If the pseudo name is not set.
        """
        if self._pseudo_name is None:
            msg = "The pseudo name of the port is not set."
            raise ValueError(msg)
        return self._pseudo_name

    @property
    def instrument_type(self) -> "Instrument":
        """Return the type of instrument that the port is connected to."""
        return self._instrument_type

    @property
    def units(self) -> "SymbolUnit":
        """Return the units of the port."""
        return self._units

    @property
    def description(self) -> str:
        """Return the description of the port."""
        return self._description
