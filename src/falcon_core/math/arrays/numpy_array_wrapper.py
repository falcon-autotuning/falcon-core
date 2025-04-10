"""A base array of ND data."""

from typing import TYPE_CHECKING

from .dependancies import Generic, Jsonable, TypeVar, arrayND, cast, np, overload

if TYPE_CHECKING:
    from .dependancies import Self


T = TypeVar("T", bound=arrayND)


class NumpyArrayWrapper(Jsonable, Generic[T]):
    """A wrapper of basic numpy functionality."""

    _data: "T"

    def __init__(
        self,
        data: "T",
    ):
        """Initialize the Array object."""
        self._data = data

    def __getitem__(
        self,
        index: slice
        | int
        | list[int]
        | tuple[int, ...]
        | tuple[slice, ...]
        | np.ndarray,
    ) -> "T | float | np.ndarray":
        """Return the value at the given index.

        Supports various indexing methods:
        - Single integer index
        - Slice
        - List of integers (for advanced indexing)
        - Tuple of integers (for multi-dimensional indexing)
        - Tuple of slices (for multi-dimensional slicing)
        - NumPy array (for boolean or advanced indexing)

        Args:
            index: The index or indices to access

        Returns:
            The data at the specified index/indices

        Raises:
            TypeError: If the index type is not supported.
        """
        result = None

        # Handle simple integer indexing
        if isinstance(index, (int, slice, np.ndarray)):
            result = self._data[index]

        # Handle list of integers (advanced indexing)
        elif isinstance(index, list):
            result = self._data[np.array(index)]

        # Handle tuple (multi-dimensional indexing or slicing)
        elif isinstance(index, tuple):
            result = self._data[index]

        # Fallback case
        else:
            msg = f"Unsupported index type: {type(index)}"
            raise TypeError(msg)

        # Handle scalar results
        if isinstance(result, (int, float, np.number)):
            return float(result)

        # Handle array results
        return cast(T, result)

    @property
    def shape(
        self,
    ) -> tuple[int, ...]:
        """Return the length of the data."""
        return self._data.shape

    @property
    def data(self) -> "T":
        """Return the data."""
        return self._data

    def greater_than(
        self,
        value: float,
    ) -> bool:
        """Check if any of the data is greater than the value.

        Args:
            value: The value to compare to.

        Returns:
            True if any of the data is greater than the value, False otherwise.
        """
        return any(self._data > value)

    def less_than(
        self,
        value: float,
    ) -> bool:
        """Check if any of the data is less than the value.

        Args:
            value: The value to compare to.

        Returns:
            True if any of the data is less than the value, False otherwise.
        """
        return any(self._data < value)

    def remove_offset(
        self,
        offset: float,
    ):
        """Remove the offset from the data."""
        self._data = cast(T, self.data - offset)

    def get_max(self) -> float:
        """Return the maximum value in the data."""
        return float(max(self.data))

    def get_min(self) -> float:
        """Return the minimum value in the data."""
        return min(self.data)

    def get_sum(self) -> float:
        """Return the sum of the data."""
        return float(np.sum(self.data))

    def reshape(
        self,
        shape: tuple[int, ...],
    ) -> "Self":
        """Return a new Array with the given shape."""
        return self.__class__(cast(T, self.data.reshape(shape)))

    def where(
        self,
        value: float,
    ) -> list[tuple[int, ...]]:
        """Return the indices of the data where the value is."""
        return list(np.where(self.data == value)[0])

    def flip(self, axis: int) -> "Self":
        """Flip the data along the given axis."""
        return self.__class__(cast(T, np.flip(self.data, axis=axis)))

    @overload
    def gradient(
        self,
        axis: None = None,
    ) -> "list[Self]":
        """Return the gradient of the data."""

    @overload
    def gradient(
        self,
        axis: int,
    ) -> "Self":
        """Return the gradient of the data."""

    def gradient(
        self,
        axis: int | None = None,
    ) -> "list[Self] | Self":
        """Return the gradient of the data."""
        if axis is None:
            return [self.__class__(data=grad) for grad in np.gradient(self.data)]
        return [self.__class__(data=np.gradient(self.data, axis=axis))]
