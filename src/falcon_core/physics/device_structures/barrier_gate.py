"""This module defines the BarrierGate class, which represents a specific type of gate on the device."""

from .base_connection import BaseConnections
from .dependancies import Jsonable
from .dot_gate import DotGate


class BarrierGate(DotGate, Jsonable):
    """A specific type of gate on the device."""


class BarrierGates(BaseConnections[BarrierGate], Jsonable):
    """Contains a group of gates on the sample."""

    def __init__(self, gates: list[BarrierGate]) -> None:
        """Initialize the Gates object.

        Args:
            gates: A list of Gate objects.
        """
        super().__init__(gates)  # type: ignore[call-arg]
