"""A request for a measrurement that Falcon can perform."""

from typing import TYPE_CHECKING

from .base_message import BaseMessage
from .constants import INSTRUMENT_TYPES
from .dependancies import Jsonable, KnobDomain, Units

if TYPE_CHECKING:
    from .typing import PortTransform, Sequence, Waveform


class MeasurementRequest(BaseMessage, Jsonable):
    """A request for a measurement that Falcon can perform."""

    _waveforms: "Sequence[Waveform]"
    _meter_tranforms: list["PortTransform"]
    _time_domain: "KnobDomain "
    _measurement_name: str

    def __init__(
        self,
        message: str,
        measurement_name: str,
        waveforms: "Sequence[Waveform]",
        meter_tranforms: list["PortTransform"],
        time_domain: "KnobDomain" = KnobDomain(
            default_name="time",
            bounds=(0, 1),
            instrument_type=INSTRUMENT_TYPES.CLOCK.value,
            greater_bound_contained=False,
            units=Units.SECOND,
        ),
    ):
        """Initialize the Request object.

        Args:
            message: The message to be sent.
            measurement_name: The name of the measurement.
            waveforms: The waveforms to be used in the measurement.
            meter_tranforms: The meter transforms to be used in the measurement.
            time_domain: The time domain for the measurement.
        """
        super().__init__(message)
        self._waveforms = waveforms
        self._meter_tranforms = meter_tranforms

        # we need to ensure that the unit of the units of the time domain are in seconds
        time_units = time_domain.units.unit.dimensions
        seconds = Units.SECOND.unit.dimensions
        assert time_units == seconds, "The units of the time domain must be in seconds."
        # we also need to ensure that the instrument type is a clock
        assert time_domain.instrument_type == INSTRUMENT_TYPES.CLOCK.value, (
            "The instrument type of the time domain must be a clock."
        )
        self._time_domain = time_domain
        self._measurement_name = measurement_name

    @property
    def measurement_name(self) -> str:
        """Return the measurement name."""
        return self._measurement_name

    @property
    def waveforms(self) -> list["Waveform"]:
        """Return the waveforms."""
        return [waveform for waveform in self._waveforms]

    @property
    def meter_tranforms(self) -> list["PortTransform"]:
        """Return the meter transforms."""
        return self._meter_tranforms

    @property
    def time_domain(self) -> "KnobDomain":
        """Return the time domain."""
        return self._time_domain
