"""A gate on a quantum dot device."""

from .base_connection import BaseConnection, BaseConnections
from .dependancies import Jsonable


class Gate(BaseConnection, Jsonable):
    """Contains the name corresponding to a particular gate on the sample."""


class Gates(BaseConnections[Gate], Jsonable):
    """Contains a group of gates on the sample."""

    def __init__(self, gates: list[Gate]) -> None:
        """Initialize the Gates object.

        Args:
            gates: A list of Gate objects.
        """
        super().__init__(connections=gates)  # type: ignore[call-arg]
