"""A special dot gate surrounded by dot gates."""

from .dependancies import BarrierGate, PlungerGate
from .has_left_neighbor import HasLeftNeighbor
from .has_right_neighbor import HasRightNeighbor


class PlungerGateWithNeighbors(
    PlungerGate,
    HasRightNeighbor,
    HasLeftNeighbor,
):
    """A plunger gate with neighbors."""

    def __init__(
        self, name: str, right_neighbor: "BarrierGate", left_neighbor: "BarrierGate"
    ) -> None:
        """Creates a plunger gate with neighbors.

        Args:
            name: The name of the gate.
            right_neighbor: The right neighbor of the gate.
            left_neighbor: The left neighbor of the gate
        """
        PlungerGate.__init__(
            self=self,
            name=name,
        )
        HasRightNeighbor.__init__(
            self=self,
            right_neighbor=right_neighbor,
        )
        HasLeftNeighbor.__init__(
            self=self,
            left_neighbor=left_neighbor,
        )

    @property
    def left_neighbor(self) -> "BarrierGate":
        """Gets the left neighbor of the gate.

        Returns:
            ReservoirGate | PlungerGate: The left neighbor.
        """
        assert isinstance(self._left_neighbor, BarrierGate)
        return self._left_neighbor

    @property
    def right_neighbor(self) -> "BarrierGate":
        """Gets the right neighbor of the gate.

        Returns:
            ReservoirGate | PlungerGate: The right neighbor.
        """
        assert isinstance(self._right_neighbor, BarrierGate)
        return self._right_neighbor
