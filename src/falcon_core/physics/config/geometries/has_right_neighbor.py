"""A gate with a left neighbor."""

from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from .typing import Gate


class HasRightNeighbor:
    """A gate with a left neighbor."""

    _right_neighbor: "Gate"

    def __init__(self, right_neighbor: "Gate") -> None:
        """Creates a gate with a left neighbor.

        Args:
            name: The name of the gate.
            left_neighbor: The gate to the left of this gate.
        """
        self._right_neighbor = right_neighbor
