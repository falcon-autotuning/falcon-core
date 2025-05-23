"""An array of ND data."""

from .base_array import BaseArray
from .dependancies import Jsonable, TypeVar, arrayND, np
from .increasing_alignment import IncreasingAlignment

T = TypeVar("T", bound=arrayND)


class ControlArray[T: arrayND](BaseArray[T], Jsonable):
    """A domain array that an array is built upon."""

    _alignment: IncreasingAlignment
    _principle_dimension: int | None

    def __init__(self, data: T):
        BaseArray.__init__(self, data=data)
        self._alignment = self._determine_alignments()
        self._principle_dimension = None

    @property
    def principle_dimension(self) -> int:
        """Return the principle dimension of the array."""
        assert self._principle_dimension is not None, (
            "The principle dimension must be set."
        )
        return self._principle_dimension

    def _determine_alignments(self) -> IncreasingAlignment:
        """Determine the alignment for each dimension of the array.

        For each dimension, checks if values are:
        - Increasing: returns True
        - Decreasing: returns False
        - Not changing: returns None

        Returns:
            List[IncreasingAlignment]: Alignment for each dimension

        Raises:
            ValueError: If no alignment is found
            ValueError: If more than one alignment is
        """
        alignments = []
        # Calculate alignment for each dimension
        for dim, (gradient, shape) in enumerate(
            zip(np.gradient(self.data), self.shape)
        ):
            if shape <= 1:
                continue  # Skip dimensions that are too small

            if np.all(gradient < 0):
                alignments.append((IncreasingAlignment(False), dim))
            elif np.all(gradient > 0):
                alignments.append((IncreasingAlignment(True), dim))

        # Check if we found exactly one dimension with alignment
        if len(alignments) == 0:
            msg = "The array must have an alignment."
            raise ValueError(msg)
        if len(alignments) > 1:
            msg = "The array must have exactly one alignment dimension."
            raise ValueError(msg)

        # Return the single alignment we found
        self._alignment, self._principle_dimension = alignments[0]
        return self._alignment

    @property
    def alignment(self) -> IncreasingAlignment:
        """Return the increasing alignments for each dimension."""
        self.update_alignments()
        return self._alignment

    def update_alignments(self):
        """Recalculate the alignments based on current data."""
        self._alignment = self._determine_alignments()
