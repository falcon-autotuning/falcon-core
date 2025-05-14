"""This module contains a specific type of gate, the DotGate."""

from .base_connection import BaseConnections
from .dependancies import Jsonable
from .gate import Gate


class DotGate(Gate):
    """The group of plunger and barrier gates."""


class DotGates(BaseConnections[DotGate], Jsonable):
    """Contains a group of gates on the sample."""

    def __init__(self, gates: list[DotGate]) -> None:
        """Initialize the Gates object.

        Args:
            gates: A list of Gate objects.
        """
        super().__init__(gates)
