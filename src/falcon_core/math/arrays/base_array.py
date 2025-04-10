"""A base array of ND data."""

from typing import TYPE_CHECKING

from .dependancies import Generic, Jsonable, TypeVar, arrayND, cast, np, overload
from .numpy_array_wrapper import NumpyArrayWrapper

if TYPE_CHECKING:
    from .dependancies import Self


T = TypeVar("T", bound=arrayND)


class BaseArray(NumpyArrayWrapper[T], Generic[T]):
    """A base array of ND data."""

    def __init__(
        self,
        data: "T",
    ):
        """Initialize the Array object."""
        super().__init__(data)

    def __eq__(
        self,
        other: object,
    ) -> bool:
        """Check if the data is equal to the other data.

        Args:
            other: The other data to compare to.

        Returns:
            True if the data is equal to the other data, False otherwise.
        """
        if isinstance(other, self.__class__):
            return np.array_equal(self.data, other.data) and Jsonable.__eq__(
                self, other
            )
        return False

    def __add__(
        self,
        other: object,
    ) -> "Self":
        """Add the data to the other data.

        Args:
            other: The other data to add to the data.

        Returns:
            The sum of the data and the other data.
        """
        if not isinstance(other, BaseArray | int | float):
            return NotImplemented
        if isinstance(other, int | float):
            return self.__class__(cast(T, self.data + other))
        return self.__class__(self.data + other.data)

    def __neg__(self) -> "Self":
        """Negate the data by multiplying by -1.

        Returns:
            The negated data.
        """
        return self.__class__(cast(T, -self.data))

    def __sub__(
        self,
        other: object,
    ) -> "Self":
        """Add the data to the other data.

        Args:
            other: The other data to add to the data.

        Returns:
            The difference of the data and the other data.
        """
        if isinstance(other, self.__class__ | (int | float)):
            return self.__add__(-other)
        return NotImplemented

    def __pow__(
        self,
        power: float,
    ) -> "Self":
        """Raise the data to the power.

        Args:
            power: The power to raise the data to.

        Returns:
            The data raised to the power.
        """
        return self.__class__(cast(T, self.data**power))

    def __mul__(
        self,
        other: object,
    ) -> "Self":
        """Multiply the data by the other data.

        Args:
            other: The other data to multiply by.

        Returns:
            The product of the data and the other data.
        """
        if not isinstance(other, BaseArray | int | float):
            return NotImplemented
        if isinstance(other, int | float):
            return self.__class__(cast(T, self.data * other))
        return self.__class__(self.data * other.data)

    def __truediv__(
        self,
        other: object,
    ) -> "Self":
        """Divide the data by the other data.

        Args:
            other: The other data to divide by.

        Returns:
            The data divided by the other data.
        """
        if not isinstance(other, BaseArray | int | float):
            return NotImplemented
        if isinstance(other, int | float):
            return self.__class__(cast(T, self.data / other))
        return self.__class__(self.data / other.data)

    def get_sum_of_squares(
        self,
        other: object = 0,
    ) -> float:
        """Return the sum of the squares of the data.

        If other is provided, subtract it from the data before squaring.
        """
        if isinstance(other, self.__class__ | int | float):
            return ((self - other) ** 2).get_sum()
        return NotImplemented

    def abs(self) -> "Self":
        """Return the absolute value of the data."""
        return self.__class__(cast(T, abs(self.data)))

    @overload
    def min(
        self,
        other: None = None,
    ) -> float: ...

    @overload
    def min(
        self,
        other: object,
    ) -> "Self": ...

    def min(
        self,
        other: object = None,
    ) -> "Self | float":
        """Return the element-wise minimum.

        Args:
            other: Another array or scalar to compare with.
                If None, returns the minimum value in the array.

        Returns:
            If other is provided: A new array with element-wise minimums
            If other is None: The minimum value across all elements
        """
        if other is None:
            # Return the minimum value in the array
            return float(np.min(self.data))

        if not isinstance(other, self.__class__ | BaseArray):
            return NotImplemented

        assert self.shape == other.shape, (
            "Shapes must be the same for element-wise operations"
        )
        return self.__class__(np.min(np.array([self.data, other.data]), axis=0))
