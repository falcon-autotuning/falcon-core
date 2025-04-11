"""This module defines the BarrierGate class, which represents a specific type of gate on the device."""

from typing import TYPE_CHECKING

from .dot_gate import DotGate

if TYPE_CHECKING:
    from .typing import TypeAlias

BarrierGates: "TypeAlias" = list["BarrierGate"]


class BarrierGate(DotGate):
    """A specific type of gate on the device."""
