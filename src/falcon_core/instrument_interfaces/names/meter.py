"""A type of instrument port that is used to measure the output of an instrument."""

from typing import TYPE_CHECKING

from .constants import INSTRUMENT_TYPES
from .dependancies import Jsonable, Units
from .instrument_port import InstrumentPort
from .typing import Ohmic

if TYPE_CHECKING:
    from .dependancies import Instrument
    from .typing import SymbolUnit


class Meter(InstrumentPort[Ohmic], Jsonable):
    """A type of instrument port that is used to measure the output of an instrument."""

    def __init__(
        self,
        default_name: str,
        pseudo_name: "Ohmic | None" = None,
        instrument_type: "Instrument" = INSTRUMENT_TYPES.AMNMETER,
        units: "SymbolUnit" = Units.AMPERE,
        description: str = "",
    ) -> None:
        """Initialize the Meter object.

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
            units=units,
            description=description,
        )
