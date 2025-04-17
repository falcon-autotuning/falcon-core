"""A transform for a knob domain."""

from .dependancies import Knob
from .port_transform import PortTransform


class KnobTransform(PortTransform[Knob]):
    """A transform for a knob domain."""
