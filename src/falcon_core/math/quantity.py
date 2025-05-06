"""A quantity class that represents a physical quantity with units and dimensions."""

from typing import TYPE_CHECKING

from .dependancies import Generic, Jsonable, TypeVar, Units, deepcopy

if TYPE_CHECKING:
    from .typing import Self, SymbolUnit

T = TypeVar("T", bound="SymbolUnit")


class Quantity(Jsonable, Generic[T]):
    """A quantity class that represents a physical quantity with units and dimensions."""

    def __init__(self, value: float, unit: "SymbolUnit" = Units.VOLT):
        """Initialize the Quantity object.

        Args:
            value: The value of the quantity.
            unit: The unit of the quantity.
        """
        self._value = value
        self._unit = unit

    @property
    def value(self) -> float:
        """Return the value of the quantity."""
        return self._value

    @property
    def unit(self) -> "SymbolUnit":
        """Return the unit of the quantity."""
        return self._unit

    def deepcopy(self) -> "Self":
        """Return a deep copy of the quantity."""
        return deepcopy(self)

    def convert_to(self, target_unit: "SymbolUnit"):
        """Convert the quantity to a different unit.

        Args:
            target_unit: The target unit to convert to.
        """
        self.unit.unit.convert_value_to(self._value, target_unit.unit)

    def __mul__(self, other: "Quantity | int | float") -> "Self":
        """Multiply two quantities.

        Args:
            ohter: The other quantity or a scalar to multiply with.

        Returns:
            a new Quantity object with the result.
        """
        clone = self.deepcopy()
        if isinstance(other, int | float):
            clone._value *= other
            clone._unit = self.unit
        else:
            clone._value *= other.value
            clone._unit *= other.unit
        return clone

    def __truediv__(self, other: "Quantity | int | float") -> "Self":
        """Performs the division of two quantities.

        Args:
            other: The other quantity or a scalar to divide by.

        Returns:
            the Qauantity object with the result.
        """
        clone = self.deepcopy()
        if isinstance(other, int | float):
            clone._value /= other
            clone._unit = self.unit
        else:
            clone._value /= other.value
            clone._unit /= other.unit
        return clone

    def __pow__(self, power: int) -> "Self":
        """Raise the quantity to a power.

        Args:
            power: The power to raise the quantity to.

        Returns:
            a new Quantity object with the result.
        """
        clone = self.deepcopy()
        clone._value = self._value**power
        clone._unit = self.unit**power
        return clone
