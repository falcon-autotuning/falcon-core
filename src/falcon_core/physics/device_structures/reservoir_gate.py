"""This is a specific type of gate on the device."""

from .base_connection import BaseConnections
from .dependancies import Jsonable
from .gate import Gate


class ReservoirGate(Gate, Jsonable):
    """A specific type of gate on the device."""


class ReservoirGates(BaseConnections[ReservoirGate], Jsonable):
    """Contains a group of gates on the sample."""

    def __init__(self, gates: list[ReservoirGate]) -> None:
        """Initialize the Gates object.

        Args:
            gates: A list of Gate objects.
        """
        super().__init__(gates)
