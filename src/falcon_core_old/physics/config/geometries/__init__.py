from typing import TYPE_CHECKING

from ...device_structures import DotGate, ReservoirGate
from .gate_geometry_array_1D import GateGeometryArray1D

if TYPE_CHECKING:
    from ....typing import TypeAlias

NeighborGate: "TypeAlias" = DotGate | ReservoirGate

__all__ = ["GateGeometryArray1D", "NeighborGate"]
