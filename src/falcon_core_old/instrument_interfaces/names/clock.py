"""Standard clock objects that can be utilized by various composers."""

from ...constants import INSTRUMENT_TYPES
from ...generic import Jsonable
from ...physics.units import Units
from .knob import Knob
from .meter import Meter


class Timer(Knob, Jsonable):
    def __init__(self):
        super().__init__(
            default_name=INSTRUMENT_TYPES.CLOCK,
            pseudo_name=None,
            instrument_type=INSTRUMENT_TYPES.CLOCK,
            description="Clock",
            units=Units.SECOND,
        )


class ExecutionClock(Meter, Jsonable):
    """A clock that is used to execute analysis over the raw data."""

    def __init__(self):
        super().__init__(
            default_name=INSTRUMENT_TYPES.CLOCK,
            instrument_type=INSTRUMENT_TYPES.CLOCK,
            pseudo_name=None,
            description="Execution clock",
            units=Units.SECOND,
        )
