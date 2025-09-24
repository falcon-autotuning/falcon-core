"""This is a specific type of gate on the device."""

from .base_connection import BaseConnections
from .dependancies import Jsonable
from .dot_gate import DotGate


class PlungerGate(DotGate, Jsonable):
    """A specific type of gate on the device."""


class PlungerGates(BaseConnections[PlungerGate], Jsonable):
    """Contains a group of gates on the sample."""

    def __init__(self, gates: list[PlungerGate]) -> None:
        """Initialize the Gates object.

        Args:
            gates: A list of Gate objects.
        """
        super().__init__(gates)  # type: ignore[call-arg]
