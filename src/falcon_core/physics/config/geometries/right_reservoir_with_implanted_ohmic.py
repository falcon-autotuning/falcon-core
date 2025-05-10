"""A special reservoir gate with an ohmic below it and the rest of the channel extending to the right."""

from typing import TYPE_CHECKING

from .dependancies import BarrierGate, ReservoirGate
from .has_implanted_ohmic import HasImplantedOhmic
from .has_left_neighbor import HasLeftNeighbor

if TYPE_CHECKING:
    from .dependancies import Ohmic


class RightReservoirWithImplantedOhmic(
    ReservoirGate,
    HasImplantedOhmic,
    HasLeftNeighbor,
):
    """A special reservoir gate with an ohmic below it and the rest of the channel extending to the right."""

    def __init__(self, name: str, ohmic: "Ohmic", left_neighbor: "BarrierGate") -> None:
        """Creates a reservoir gate with an ohmic below it and the rest of the channel extending to the right.

        Args:
            name: The name of the gate.
            ohmic: The ohmic below the reservoir gate.
        """
        ReservoirGate.__init__(
            self=self,
            name=name,
        )
        HasImplantedOhmic.__init__(
            self=self,
            ohmic=ohmic,
        )
        HasLeftNeighbor.__init__(
            self=self,
            left_neighbor=left_neighbor,
        )

    @property
    def left_neighbor(self) -> "BarrierGate":
        """The left barrier gate."""
        assert isinstance(self._left_neighbor, BarrierGate)
        return self._left_neighbor
