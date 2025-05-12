"""A collection of knobs."""

from .dependancies import Jsonable
from .meter import Meter
from .ports import Ports


class Meters(Ports[Meter], Jsonable):
    """A collection of meters."""

    def __init__(self, meters: Meter | list[Meter]) -> None:
        """Initialize the Meters collection."""
        super().__init__(ports=meters)
