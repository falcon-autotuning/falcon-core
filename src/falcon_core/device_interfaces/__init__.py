"""Directory holding the various connections to a quantum dot device sample."""

from typing import TYPE_CHECKING

from .barrier_gate import BarrierGate, BarrierGates
from .base_connection import BaseConnection, BaseConnections
from .dot_gate import DotGate, DotGates
from .gate import Gate, Gates
from .ohmic import Ohmic, Ohmics
from .plunger_gate import PlungerGate, PlungerGates
from .reservoir_gate import ReservoirGate, ReservoirGates
from .screening_gate import ScreeningGate, ScreeningGates

if TYPE_CHECKING:
    from ..typing import TypeAlias

NamedPrimitiveGates: "TypeAlias" = (
    ScreeningGates | ReservoirGates | PlungerGates | BarrierGates
)

UsefulGate: "TypeAlias" = (
    ScreeningGate | ReservoirGate | PlungerGate | BarrierGate | DotGate | Gate
)
UsefulGateType: "TypeAlias" = (
    type[ScreeningGate]
    | type[ReservoirGate]
    | type[PlungerGate]
    | type[BarrierGate]
    | type[DotGate]
    | type[Gate]
)
UsefulGates: "TypeAlias" = NamedPrimitiveGates | DotGates | Gates
UsefulGatesTypes: "TypeAlias" = (
    type[ScreeningGates]
    | type[ReservoirGates]
    | type[PlungerGates]
    | type[BarrierGates]
)
Connection: "TypeAlias" = UsefulGate | Ohmic
Connections: "TypeAlias" = UsefulGates | Ohmics
UsefulConnectionType: "TypeAlias" = UsefulGateType | type[Ohmic]
UsefulConnectionsTypes: "TypeAlias" = UsefulGatesTypes | type[Ohmics]

__all__ = [
    "Gate",
    "Gates",
    "Ohmic",
    "Ohmics",
    "BaseConnection",
    "BaseConnections",
    "DotGate",
    "DotGates",
    "PlungerGate",
    "ScreeningGate",
    "ReservoirGate",
    "BarrierGate",
    "Connection",
    "Connections",
    "UsefulGate",
    "UsefulGates",
    "UsefulGateType",
    "UsefulGatesTypes",
    "UsefulConnectionType",
    "UsefulConnectionsTypes",
]
