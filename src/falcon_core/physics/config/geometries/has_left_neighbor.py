"""A gate with a left neighbor."""

from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from .typing import Gate


class HasLeftNeighbor:
    """A gate with a left neighbor."""

    _left_neighbor: "Gate"

    def __init__(self, left_neighbor: "Gate") -> None:
        """Creates a gate with a left neighbor.

        Args:
            name: The name of the gate.
            left_neighbor: The gate to the left of this gate.
        """
        self._left_neighbor = left_neighbor
