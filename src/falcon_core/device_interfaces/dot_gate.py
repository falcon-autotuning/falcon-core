"""This module contains a specific type of gate, the DotGate."""

from typing import TYPE_CHECKING

from .gate import Gate

if TYPE_CHECKING:
    from .typing import TypeAlias

DotGates: "TypeAlias" = list["DotGate"]


class DotGate(Gate):
    """The group of plunger and barrier gates."""
