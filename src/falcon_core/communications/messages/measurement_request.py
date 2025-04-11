"""A request for a measrurement that Falcon can perform."""

from typing import TYPE_CHECKING

from .base_request import BaseRequest
from .dependancies import Domain, Jsonable

if TYPE_CHECKING:
    from .typing import MeterTransforms, Waveform


class MeasurementRequest(BaseRequest, Jsonable):
    """A request for a measurement that Falcon can perform."""

    _waveforms: list["Waveform"]
    _meter_tranforms: list["MeterTransforms"]
    _time_domain: "Domain "
    _measurement_name: str

    def __init__(
        self,
        message: str,
        measurement_name: str,
        waveforms: list["Waveform"],
        meter_tranforms: list["MeterTransforms"],
        time_domain: "Domain" = Domain(bounds=(0, 1)),
    ):
        """Initialize the Request object."""
        super().__init__(message)
        self._waveforms = waveforms
        self._meter_tranforms = meter_tranforms
        self._time_domain = time_domain
        self._measurement_name = measurement_name

    @property
    def measurement_name(self) -> str:
        """Return the measurement name."""
        return self._measurement_name

    @property
    def waveforms(self) -> list["Waveform"]:
        """Return the waveforms."""
        return self._waveforms

    @property
    def meter_tranforms(self) -> list["MeterTransforms"]:
        """Return the meter transforms."""
        return self._meter_tranforms

    @property
    def time_domain(self) -> "Domain":
        """Return the time domain."""
        return self._time_domain
