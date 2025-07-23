"""Contains a ready to use voltage constraints matrix and matching limits for each constraint."""

from typing import TYPE_CHECKING

from ....dependancies import np

if TYPE_CHECKING:
    from .adjacency import Adjacency


class VoltageConstraints:
    """Contains a ready to use voltage constraints matrix and matching limits for each constraint."""

    _matrix: "np.ndarray"
    _adjacency: "Adjacency"
    _limits: "np.ndarray"

    def __init__(
        self,
        adjacency: "Adjacency",
        max_safe_diff: float,
        bounds: tuple[float, float],
    ):
        """Constructs a voltage constraints.

        Args:
            adjacency: the adjacency matrix used to understand the device layout
            max_safe_diff: the maximum safe voltage difference between adjacent gates
            bounds: the (min,max) safe voltage bounds to apply voltages
        """
        self._adjacency = adjacency
        self._matrix = np.vstack(
            [
                np.identity(len(adjacency)),
                -1 * np.identity(len(adjacency)),
            ]
        )
        limits = [bounds[1]] * 2 * len(adjacency)
        for pair in self.adjacency.get_true_pairs():
            constraint = np.zeros(len(adjacency))
            constraint[pair[0]] = 1
            constraint[pair[1]] = -1
            inv_constraint = -1 * constraint
            self._matrix = np.vstack([self._matrix, constraint, inv_constraint])
            limits += [max_safe_diff, max_safe_diff]
        self._limits = np.array(limits).T

    @property
    def matrix(self) -> np.ndarray:
        """Returns the constraint matrix."""
        return self._matrix

    @property
    def adjacency(self) -> "Adjacency":
        """Returns the adjacency matrix used to construct the constraints."""
        return self._adjacency

    @property
    def limits(self) -> np.ndarray:
        """Returns the limits of the constraints."""
        return self._limits
