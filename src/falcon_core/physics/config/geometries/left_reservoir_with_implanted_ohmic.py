"""A special reservoir gate with an ohmic below it and the rest of the channel extending to the right."""

from typing import TYPE_CHECKING

from .dependancies import BarrierGate, ReservoirGate
from .has_implanted_ohmic import HasImplantedOhmic
from .has_right_neighbor import HasRightNeighbor

if TYPE_CHECKING:
    from .dependancies import Ohmic


class LeftReservoirWithImplantedOhmic(
    ReservoirGate,
    HasImplantedOhmic,
    HasRightNeighbor,
):
    """A special reservoir gate with an ohmic below it and the rest of the channel extending to the right."""

    def __init__(
        self, name: str, ohmic: "Ohmic", right_neighbor: "BarrierGate"
    ) -> None:
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
        HasRightNeighbor.__init__(
            self=self,
            right_neighbor=right_neighbor,
        )

    @property
    def right_neighbor(self) -> "BarrierGate":
        """The right barrier gate."""
        assert isinstance(self._right_neighbor, BarrierGate)
        return self._right_neighbor
