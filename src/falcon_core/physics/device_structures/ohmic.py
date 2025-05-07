"""An ohmic that represents a named ohmic connection to a quantum dot device."""

from typing import TYPE_CHECKING
from .base_connection import BaseConnection
from .base_connections import BaseConnections
from .dependancies import Jsonable

if TYPE_CHECKING:
    from .typing import TypeAlias


class Ohmic(BaseConnection):
    """Contains the name corresponding to a particular ohmic on the sample."""


class Ohmics(BaseConnections[Ohmic], Jsonable):
    def __init__(self, ohmics: list[Ohmic]) -> None:
        """Initialize the Ohmics object.

        Args:
            ohmics: A list of Ohmic objects.
        """
        super().__init__(ohmics)
