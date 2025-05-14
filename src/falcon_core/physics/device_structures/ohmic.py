"""An ohmic that represents a named ohmic connection to a quantum dot device."""

from .base_connection import BaseConnection, BaseConnections
from .dependancies import Jsonable


class Ohmic(BaseConnection, Jsonable):
    """Contains the name corresponding to a particular ohmic on the sample."""


class Ohmics(BaseConnections[Ohmic], Jsonable):
    def __init__(self, ohmics: list[Ohmic]) -> None:
        """Initialize the Ohmics object.

        Args:
            ohmics: A list of Ohmic objects.
        """
        super().__init__(ohmics)
