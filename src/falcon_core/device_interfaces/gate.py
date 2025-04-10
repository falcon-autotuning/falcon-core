"""A gate on a quantum dot device."""

from typing import TYPE_CHECKING

from .base_connection import BaseConnection

if TYPE_CHECKING:
    from .typing import TypeAlias

Gates: "TypeAlias" = list["Gate"]


class Gate(BaseConnection):
    """Contains the name corresponding to a particular gate on the sample."""
