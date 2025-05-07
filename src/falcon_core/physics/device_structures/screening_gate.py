"""This is a specific type of gate on the device."""

from .base_connections import BaseConnections
from .dependancies import Jsonable
from .gate import Gate


class ScreeningGate(Gate):
    """A specific type of gate on the device."""


class ScreeningGates(BaseConnections[ScreeningGate], Jsonable):
    """Contains a group of gates on the sample."""

    def __init__(self, gates: list[ScreeningGate]) -> None:
        """Initialize the Gates object.

        Args:
            gates: A list of Gate objects.
        """
        super().__init__(gates)
