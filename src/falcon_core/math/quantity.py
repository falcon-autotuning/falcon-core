"""A quantity class that represents a physical quantity with units and dimensions."""

from typing import TYPE_CHECKING

from .dependancies import Generic, Jsonable, TypeVar, Units

if TYPE_CHECKING:
    from .typing import SymbolUnit

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

    def convert_to(self, target_unit: "SymbolUnit"):
        """Convert the quantity to a different unit.

        Args:
            target_unit: The target unit to convert to.
        """
        self.unit.unit.convert_value_to(self._value, target_unit.unit)
