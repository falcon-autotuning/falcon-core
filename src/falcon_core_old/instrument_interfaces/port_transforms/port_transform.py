"""A transform that maps a port to a port on a time domain."""

from typing import TYPE_CHECKING

from .dependancies import (
    Jsonable,
    Knob,
    Knobs,
    Meter,
    Meters,
    OneToOneMapping,
)

if TYPE_CHECKING:
    from .dependancies import (
        InstrumentPort,
    )
    from .typing import ValidatedAnalyticFunction


PORT_COLLECTION_MAP = OneToOneMapping([(Knob, Knobs), (Meter, Meters)])


class PortTransform(Jsonable):
    """A transform that maps a port to a port on a time domain."""

    _port: "InstrumentPort"
    _transform: "ValidatedAnalyticFunction"

    def __init__(self, port: "InstrumentPort", transform: "ValidatedAnalyticFunction"):
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
    def port(self) -> "InstrumentPort":
        """Return the port."""
        return self._port

    @property
    def transform(self) -> "ValidatedAnalyticFunction":
        """Return the transform."""
        return self._transform

    def validate_transform(self):
        """Validate that the transform is valid."""
        assert self.transform.validate_port(port=self.port), (
            "The transform must be valid for the port."
        )
