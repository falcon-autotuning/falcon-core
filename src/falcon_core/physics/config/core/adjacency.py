"""An adjacency matrix for understanding device layout."""

from typing import TYPE_CHECKING

from ....generic.jsonable import Jsonable

if TYPE_CHECKING:
    from ....dependancies import np
    from ...device_structures.gate import Gate


class Adjacency(Jsonable):
    """An adjacency matrix for understanding device layout."""

    _matrix: "np.ndarray"
    _indexes: list["Gate"]

    def __init__(self, matrix: "np.ndarray", indexes: list["Gate"]) -> None:
        self._matrix = matrix
        self._indexes = indexes

    @property
    def matrix(self) -> "np.ndarray":
        """Returns the matrix contained within the adjacency."""
        return self._matrix

    @property
    def indexes(self) -> list["Gate"]:
        """Returns the indexes along both edges of the adjacency."""
        return self._indexes

    def __len__(self) -> int:
        """Returns the size of the adjacency."""
        return len(self.indexes)

    def get_true_pairs(self) -> list[tuple[int, int]]:
        """Returns a list of (i, j) coordinates where the adjacency matrix is True."""
        true_pairs = []
        for i in range(len(self._matrix)):
            for j in range(len(self._matrix[i])):
                if self._matrix[i][j]:
                    true_pairs.append((i, j))
        return true_pairs
