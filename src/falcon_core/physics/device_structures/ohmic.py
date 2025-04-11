"""An ohmic that represents a named ohmic connection to a quantum dot device."""

from typing import TYPE_CHECKING

from .base_connection import BaseConnection

if TYPE_CHECKING:
    from .typing import TypeAlias

Ohmics: "TypeAlias" = list["Ohmic"]


class Ohmic(BaseConnection):
    """Contains the name corresponding to a particular ohmic on the sample."""
