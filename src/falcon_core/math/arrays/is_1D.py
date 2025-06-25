"""A mixin for 1D arrays."""

from typing import TYPE_CHECKING

from .dependancies import Protocol, Self, array1D, cast, np, runtime_checkable

if TYPE_CHECKING:
    from .dependancies import arrayND


@runtime_checkable
class HasShapeAndData(Protocol):
    """Protocol defining required attributes for Is1D mixin."""

    @property
    def shape(self) -> tuple[int, ...]: ...

    @property
    def data(self) -> "arrayND": ...

    def __getitem__(
        self, index: int | slice | list[int] | np.ndarray | tuple[int, ...]
    ) -> float | np.ndarray | Self: ...


class Is1D:
    """A mixin that provides 1D-specific functionality to array classes.

    The class that inherits from this must provide:
    - shape property returning tuple[int, ...]
    - data property returning array-like
    """

    @property
    def is_1D(self) -> bool:
        """Check if the array is 1D.

        Returns:
            bool: True if the array is 1D, False otherwise.

        Raises:
            TypeError: If the class does not implement shape and data properties.
        """
        if not isinstance(self, HasShapeAndData):
            msg = "Class inheriting from Is1D must implement shape and data properties"
            raise TypeError(msg)
        return len(self.shape) == 1

    def as_1D(self) -> "array1D":
        """Return the data as a 1D array.

        Returns:
            array1D: The data as a 1D array.

        Raises:
            TypeError: If the class does not implement shape and data properties.
            ValueError: If the array is not 1D.
        """
        if not isinstance(self, HasShapeAndData):
            msg = "Class inheriting from Is1D must implement shape and data properties"
            raise TypeError(msg)

        if not self.is_1D:
            msg = "Cannot convert non-1D array to 1D"
            raise ValueError(msg)

        return cast(array1D, self.data)

    def get_item_1d(self, index: int) -> float:
        """Get a single item from the 1D array at the specified index.

        Args:
            index: The index to access

        Returns:
            The scalar value at the index

        Raises:
            TypeError: If the class does not implement __getitem__ method.
        """
        if not isinstance(self, HasShapeAndData):
            msg = "Class inheriting from Is1D must implement __getitem__ method"
            raise TypeError(msg)

        # Use the class's __getitem__ implementation and convert to float
        out = self[index]
        assert isinstance(out, float), "Expected a float value"
        return out

    def get_slice_1d(self, index: slice) -> Self:
        """Get a slice of items from the 1D array.

        Args:
            index: The slice to access

        Returns:
            A 1D array containing the sliced values

        Raises:
            TypeError: If the class does not implement __getitem__ method.
        """
        if not isinstance(self, HasShapeAndData):
            msg = "Class inheriting from Is1D must implement __getitem__ method"
            raise TypeError(msg)

        # Use the class's __getitem__ implementation
        return cast(Self, self[index])

    def get_indices_1d(self, indices: list[int]) -> Self:
        """Get values at multiple indices from the 1D array.

        Args:
            indices: The list of indices to access

        Returns:
            A 1D array containing the values at the specified indices

        Raises:
            TypeError: If the class does not implement __getitem__ method.
        """
        if not isinstance(self, HasShapeAndData):
            msg = "Class inheriting from Is1D must implement __getitem__ method"
            raise TypeError(msg)

        # Use the class's __getitem__ implementation
        return cast(Self, self[indices])

    def __iter__(self):
        """Return iterator over the data."""
        return iter(self.as_1D())

    def __len__(self):
        """Return the length of the data."""
        return len(self.as_1D())

    # 1D-specific convenience methods
    def get_start(self) -> float:
        """Get the first element of the 1D array.

        Returns:
            float: The first element of the 1D array.
        """
        return float(self.as_1D()[0])

    def get_end(self) -> float:
        """Get the last element of the 1D array.

        Returns:
            float: The last element of the 1D array.
        """
        return float(self.as_1D()[-1])

    def get_min(self) -> float:
        """Get the minimum value in the 1D array.

        Returns:
            float: The minimum value in the 1D array.
        """
        return float(np.min(self.as_1D()))

    def get_max(self) -> float:
        """Get the maximum value in the 1D array.

        Returns:
            float: The maximum value in the 1D array.
        """
        return float(np.max(self.as_1D()))

    def is_decreasing(self) -> bool:
        """Check if the array is decreasing.

        Returns:
            bool: True if the array is decreasing, False otherwise.
        """
        return self.get_start() > self.get_end()

    def is_increasing(self) -> bool:
        """Check if the array is increasing.

        Returns:
            bool: True if the array is increasing, False otherwise.
        """
        return self.get_start() < self.get_end()

    def get_distance(self) -> float:
        """Get the distance between the first and last element of the 1D array.

        Returns:
            float: The distance between the first and last element of the 1D array.
        """
        return abs(self.get_start() - self.get_end())

    def get_std(self) -> float:
        """Get the standard deviation of the 1D array.

        Returns:
            float: The standard deviation of the 1D array.
        """
        return float(np.std(self.as_1D()))

    def get_mean(self) -> float:
        """Get the mean of the 1D array.

        Returns:
            float: The mean of the 1D array.
        """
        return float(np.mean(self.as_1D()))

    def reverse(self) -> None:
        """Reverse the 1D array."""
        self._data = self.as_1D()[::-1]

    def get_closest_index(self, value: float) -> int:
        """Get the index of the closest element to the given value.

        Args:
            value: The value to find the closest index to.

        Returns:
            int: The index of the closest element to the given value.
        """
        return int(np.abs(self.as_1D() - value).argmin())

    def even_divisions(self, divisions: int) -> tuple[array1D, ...]:
        """Splits the array into even division if possible.

        Args:
            divisions: The number of divisions to split the array into.

        Returns:
            the many divisions of the array as a tuple of arrays.
        """
        partition_length = len(self) // divisions
        assert len(self) % divisions == 0, "Array cannot be evenly divided"
        arr = self.as_1D()
        return tuple(
            cast(array1D, arr[i * partition_length : (i + 1) * partition_length])
            for i in range(divisions)
        )
