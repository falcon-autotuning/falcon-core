"""This is a specific type of gate on the device."""

from typing import TYPE_CHECKING

from .dot_gate import DotGate

if TYPE_CHECKING:
    from .typing import TypeAlias

PlungerGates: "TypeAlias" = list["PlungerGate"]


class PlungerGate(DotGate):
    """A specific type of gate on the device."""
