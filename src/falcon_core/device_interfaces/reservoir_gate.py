"""This is a specific type of gate on the device."""

from typing import TYPE_CHECKING

from .gate import Gate

if TYPE_CHECKING:
    from .typing import TypeAlias

ReservoirGates: "TypeAlias" = list["ReservoirGate"]


class ReservoirGate(Gate):
    """A specific type of gate on the device."""
