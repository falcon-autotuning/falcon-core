"""This module defines the BarrierGate class, which represents a specific type of gate on the device."""

from typing import TYPE_CHECKING

from .dot_gate import DotGate
from .dependancies import Jsonable
from .base_connections import BaseConnections

if TYPE_CHECKING:
    from .typing import TypeAlias


class BarrierGate(DotGate, Jsonable):
    """A specific type of gate on the device."""


class BarrierGates(BaseConnections[BarrierGate], Jsonable):
    """Contains a group of gates on the sample."""

    def __init__(self, gates: list[BarrierGate]) -> None:
        """Initialize the Gates object.

        Args:
            gates: A list of Gate objects.
        """
        super().__init__(gates)
