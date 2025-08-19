"""A base array that provides label functionality."""

from typing import TYPE_CHECKING

from .dependancies import (
    AcquisitionContext,
    BaseArray,
    Jsonable,
    TypeVar,
    overload,
)

if TYPE_CHECKING:
    from .typing import Connection, Instrument, InstrumentPort, Self, SymbolUnit

T = TypeVar("T", bound=BaseArray)


class BaseLabelledArray[T: BaseArray](Jsonable):
    _array: T
    _label: "AcquisitionContext"

    def __init__(
        self,
        array: T,
        label: "AcquisitionContext",
    ):
        """Initialize the LabelledArray object."""
        self._array = array
        self._label = label

    @property
    def array(self) -> T:
        """Return the array."""
        return self._array

    @property
    def label(self) -> "AcquisitionContext":
        """Return the label."""
        return self._label

    @classmethod
    def from_port(
        cls,
        array: T,
        port: "InstrumentPort",
    ) -> "Self":
        """Create a LabelledArray from a port.

        Args:
            port: The instrument port.
            array: The data array.

        Returns:
            The LabelledArray object.
        """
        return cls(
            array=array,
            label=AcquisitionContext.from_instrument_port(port),
        )

    @property
    def connection(self) -> "Connection | None":
        """Return the connection."""
        return self._label.connection

    @property
    def instrument_type(self) -> "Instrument":
        """Return the instrument type."""
        return self._label.instrument_type

    @property
    def units(self) -> "SymbolUnit":
        """Return the units."""
        return self._label.units

    def __eq__(self, other: object) -> bool:
        """Check if the data is equal to the other data."""
        if not isinstance(other, self.__class__ | BaseLabelledArray):
            raise NotImplementedError
        if isinstance(other, self.__class__):
            return self.array == other.array and self.label == other.label
        return False

    def __add__(self, other: object) -> "Self":
        """Add the data to the other data."""
        if not isinstance(
            other,
            self.__class__ | BaseLabelledArray | BaseArray | int | float,
        ):
            raise NotImplementedError
        if isinstance(other, self.__class__ | BaseLabelledArray):
            if self.label != other.label:
                msg = "Cannot add two labelled arrays with different labels."
                raise ValueError(msg)
            return self.__class__(self.array + other.array, self.label)
        return self.__class__(self.array + other, self.label)

    def __neg__(self) -> "Self":
        """Negate the data by multiplying by -1."""
        return self.__class__(-self.array, self.label)

    def __sub__(self, other: "Self | BaseArray | int | float") -> "Self":
        """Subtract the data from the other data."""
        if isinstance(other, BaseLabelledArray | BaseArray | int | float):
            return self.__add__(-other)
        return NotImplemented

    def __pow__(self, power: int) -> "Self":
        """Raise the data to the power."""
        label = self.label
        label._units **= power
        return self.__class__(self.array**power, label)

    def __mul__(self, other: object) -> "Self":
        """Multiply the data by the other data."""
        if isinstance(other, int | float | BaseArray):
            return self.__class__(self.array * other, self.label)
        if isinstance(other, self.__class__ | BaseLabelledArray):
            label = self.label
            label._units *= other.label.units
            return self.__class__(self.array * other.array, label)
        raise NotImplementedError

    def __truediv__(self, other: object) -> "Self":
        """Divide the data by the other data."""
        if isinstance(other, int | float | BaseArray):
            return self.__class__(self.array / other, self.label)
        if isinstance(other, self.__class__ | BaseLabelledArray):
            label = self.label
            label._units /= other.label.units
            return self.__class__(self.array / other.array, label)
        raise NotImplementedError

    def get_sum_of_squares(self) -> float:
        """Get the sum of squares of the data."""
        return self.array.get_sum_of_squares()

    def greater_than(self, value: float) -> bool:
        """Check if any of the data is greater than the value.

        Args:
            value: The value to compare to.

        Returns:
            True if any of the data is greater than the value, False otherwise.
        """
        return self.array.greater_than(value)

    def remove_offset(self, offset: float):
        """Remove the offset from the data."""
        self.array.remove_offset(offset)

    def get_max(self) -> float:
        """Return the maximum value in the data."""
        return self.array.get_max()

    def get_min(self) -> float:
        """Return the minimum value in the data."""
        return self.array.get_min()

    def get_sum(self) -> float:
        """Return the sum of the data."""
        return self.array.get_sum()

    def flip(self, axis: int) -> "Self":
        """Flip the data.

        Args:
            axis: The axis to flip along.

        Returns:
            The flipped data.
        """
        return self.__class__(self.array.flip(axis=axis), self.label)

    @overload
    def gradient(
        self,
        axis: None = None,
    ) -> "list[Self]": ...

    @overload
    def gradient(
        self,
        axis: int,
    ) -> "Self": ...

    def gradient(self, axis: int | None = None) -> "list[Self] | Self":
        """Return the gradient of the data.

        Args:
            axis: The axis to take the gradient along.

        Returns:
            The gradient of the data.
        """
        if axis is None:
            return [
                self.__class__(gradient, self.label)
                for gradient in self.array.gradient()
            ]
        return self.__class__(self.array.gradient(axis=axis), self.label)
