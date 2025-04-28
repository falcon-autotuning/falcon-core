"""A type of instument port that is used to control a knob on an instrument."""

from typing import TYPE_CHECKING

from .constants import INSTRUMENT_TYPES
from .dependancies import Units
from .instrument_port import InstrumentPort

if TYPE_CHECKING:
    from .instrument import Instrument
    from .typing import Connection, SymbolUnit


class Knob(InstrumentPort):
    """A type of instument port that is used to control a knob on an instrument."""

    def __init__(
        self,
        default_name: str,
        pseudo_name: "Connection | None" = None,
        instrument_type: "Instrument" = INSTRUMENT_TYPES.DC_VOLTAGE_SOURCE.value,
        description: str = "",
        units: "SymbolUnit" = Units.VOLT,
    ) -> None:
        """Initialize the Knob object.

        Args:
            default_name: The default name of the port.
            pseudo_name: The pseudo name of the port.
            instrument_type: The type of instrument that the port is connected
                to.
            units: The units of the port.
            description: The description of the port.
        """
        super().__init__(
            default_name=default_name,
            pseudo_name=pseudo_name,
            instrument_type=instrument_type,
            description=description,
            units=units,
        )
