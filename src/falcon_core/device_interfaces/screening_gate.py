"""This is a specific type of gate on the device."""

from typing import TYPE_CHECKING

from .gate import Gate

if TYPE_CHECKING:
    from .typing import TypeAlias

ScreeningGates: "TypeAlias" = list["ScreeningGate"]


class ScreeningGate(Gate):
    """A specific type of gate on the device."""
