"""A collection of knobs."""

from .meter import Meter
from .ports import Ports


class Meters(Ports[Meter]):
    """A collection of meters."""

    def __init__(self, meters: Meter | list[Meter]) -> None:
        """Initialize the Meters collection."""
        super().__init__(ports=meters)
