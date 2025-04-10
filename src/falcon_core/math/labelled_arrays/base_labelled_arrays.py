"""A collection of labelled arrays that are kept together."""

from typing import TYPE_CHECKING

from .base_labelled_array import BaseLabelledArray
from .dependancies import Generic, Jsonable, TypeVar

if TYPE_CHECKING:
    from .dependancies import AcquisitionContext
    from .typing import Iterator

T = TypeVar("T", bound=BaseLabelledArray)


class BaseLabelledArrays(Jsonable, Generic[T]):
    """A collection of labelled arrays that are kept together."""

    _arrays: list[T]

    def __init__(self, arrays: list[T]) -> None:
        """Initialize the LabelledArray object."""
        self._arrays = arrays
        self.check_array_labels()

    @property
    def arrays(self) -> list[T]:
        """Return the arrays."""
        return self._arrays

    @property
    def labels(self) -> list["AcquisitionContext"]:
        """Return the labels of the arrays."""
        return [array.label for array in self.arrays]

    def check_array_labels(self) -> None:
        """Make sure that all the arrays have unique labels.

        Raises:
            ValueError: If any of the arrays have the same label.
        """
        labels = [array.label for array in self.arrays]
        if len(labels) != len(set(labels)):
            msg = "All arrays must have unique labels."
            raise ValueError(msg)

    def __getitem__(self, key: "AcquisitionContext") -> T:
        """Return the array with the given port.

        Args:
            key: The port to search for.

        Returns:
            The array with the given port.

        Raises:
            KeyError: If the port is not found in the LabelledArrays object.
        """
        for array in self.arrays:
            if array.label == key:
                return array
        msg = f"Context {key} not found in the LabelledArrays object."
        raise KeyError(msg)

    def __iter__(self) -> "Iterator[T]":
        """Iterate through the arrays.

        Yields:
            The array at each index.
        """
        yield from self._arrays

    def __len__(self) -> int:
        """Return the number of arrays in the collection."""
        return len(self._arrays)
