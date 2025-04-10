"""A transform that maps a port to a port on a time domain."""

from typing import TYPE_CHECKING

from .dependancies import (
    Generic,
    InstrumentPort,
    Jsonable,
    Knob,
    Knobs,
    Meter,
    Meters,
    OneToOneMapping,
    TypeVar,
)

if TYPE_CHECKING:
    from .typing import AnalyticFunction

T = TypeVar("T", bound=InstrumentPort)

PORT_COLLECTION_MAP = OneToOneMapping([(Knob, Knobs), (Meter, Meters)])


class PortTransform(Jsonable, Generic[T]):
    """A transform that maps a port to a port on a time domain."""

    _port: T
    _transform: "AnalyticFunction"

    def __init__(self, port: T, transform: "AnalyticFunction"):
        """Initialize the PortTransform object."""
        port_type = port.__class__.__name__
        for knob_type, knobs_type in PORT_COLLECTION_MAP.items():
            if port_type == knob_type.__name__:
                assert isinstance(transform.ports, knobs_type), (
                    f"Expected transform for {knobs_type}, got {transform.ports}"
                )
        self._port = port
        self._transform = transform
        self.validate_transform()

    @property
    def port(self) -> T:
        """Return the port."""
        return self._port

    @property
    def transform(self) -> "AnalyticFunction":
        """Return the transform."""
        return self._transform

    def validate_transform(self):
        """Validate that the transform is valid."""
        assert self.transform.validate_port(port=self.port), (
            "The transform must be valid for the port."
        )
