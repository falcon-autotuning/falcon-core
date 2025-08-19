"""A physical unit with dimension and scaling."""

from .constants import UNIT_SYMBOL
from .dependancies import Jsonable
from .prefix import Prefix


class Unit(Jsonable):
    """A physical unit with dimensions.

    This class represents units like meters, volts, etc., and handles
    unit conversions, combinations, and dimensional analysis.

    TODO : Add support for unit algebra (e.g., V/A = Ohm, etc.)
    """

    _dimensions: dict[str, int]
    _scale_factor: float
    _offset: float  # For units like Celsius that have an offset from base unit
    _prefix: str  # Store the prefix

    def __init__(
        self,
        dimensions: dict[str, int],
        scale_factor: float = 1.0,
        offset: float = 0.0,
        prefix: str = UNIT_SYMBOL,
    ):
        """Initialize a unit.

        Args:
            dimensions: Dictionary mapping dimensions to their powers
            scale_factor: Scale factor relative to SI base units
            offset: Offset from base unit (e.g., for Celsius)
            prefix: The SI prefix applied to this unit (default: None)
        """
        self._dimensions = dimensions
        self._scale_factor = scale_factor
        self._offset = offset
        self._prefix = prefix
        self._simplify_dimensions()

    @property
    def prefix(self) -> str:
        """The prefix applied to this unit."""
        return self._prefix

    @property
    def dimensions(self) -> dict[str, int]:
        """Dimensions of this unit."""
        return self._dimensions.copy()

    @property
    def scale_factor(self) -> float:
        """Scale factor relative to SI base units."""
        return self._scale_factor

    @property
    def offset(self) -> float:
        """Offset from base unit."""
        return self._offset

    @property
    def is_dimensionless(self) -> bool:
        """Check if the unit is dimensionless."""
        return not any(self._dimensions.values())

    def _simplify_dimensions(self):
        """Simplify the dimensions by removing zero powers and factoring.

        This method:
        1. Removes dimensions with zero power
        2. Attempts to combine dimensions through exponentiation
        3. Reduces to simplest form with single numerator/denominator where possible
        """
        # Remove dimensions with zero power
        simplified = {
            dim: power for dim, power in self.dimensions.items() if power != 0
        }

        # If empty, return empty dict (dimensionless unit)
        if not simplified:
            return

        # Look for known dimension combinations that can be simplified
        # For example, if we have m¹·s⁻² we can identify it as acceleration
        # This would require a database of known dimension combinations
        # Placeholder for future implementation

        # Separate positive and negative powers (numerator and denominator)
        numerator = {dim: power for dim, power in simplified.items() if power > 0}
        denominator = {dim: -power for dim, power in simplified.items() if power < 0}

        # Find common factors between numerator and denominator
        # For example, m²/m should simplify to m
        common_dims = set(numerator.keys()) & set(denominator.keys())
        for dim in common_dims:
            min_power = min(numerator[dim], denominator[dim])
            numerator[dim] -= min_power
            denominator[dim] -= min_power
            # Remove if zero
            if numerator[dim] == 0:
                del numerator[dim]
            if denominator[dim] == 0:
                del denominator[dim]

        # Recombine into a single dictionary
        result = numerator.copy()
        for dim, power in denominator.items():
            result[dim] = -power

        self._dimensions = result

    def __mul__(self, other: "Unit") -> "Unit":
        """Multiply two units.

        Args:
            other: The other unit to multiply by

        Returns:
            The product of the two units
        """
        if not isinstance(other, Unit):
            return NotImplemented

        # Combine dimensions
        new_dims = self.dimensions.copy()
        for dim, power in other.dimensions.items():
            if dim in new_dims:
                new_dims[dim] += power
                # Remove dimension if power becomes zero
                if new_dims[dim] == 0:
                    del new_dims[dim]
            else:
                new_dims[dim] = power

        # Combine scale factors
        new_scale = (
            (self.scale_factor * other.scale_factor)
            + (self.scale_factor * other.offset)
            + (other.scale_factor * self.offset)
        )

        new_mult, prefix = Prefix.prefix_multiplication(
            first_prefix=self.prefix,
            second_prefix=other.prefix,
            scale_factor=new_scale,
        )

        return Unit(
            dimensions=new_dims,
            scale_factor=new_mult,
            prefix=prefix,
            offset=self.offset * other.offset,
        )

    def __truediv__(self, other: "Unit") -> "Unit":
        """Divide two units."""
        if not isinstance(other, Unit):
            return NotImplemented

        # Inverse the dimensions of the denominator
        inverse_dims = {dim: -power for dim, power in other.dimensions.items()}

        new_mult, prefix = Prefix.prefix_multiplication(
            first_prefix=Prefix.get_symbol(-1 * Prefix.get_value(other.prefix)),
            second_prefix=UNIT_SYMBOL,
            scale_factor=1.0 / other.scale_factor,
        )

        # Create a temporary unit with inverted dimensions
        inverse_unit = Unit(
            dimensions=inverse_dims,
            scale_factor=new_mult,
            prefix=prefix,
            offset=-other.offset
            / (other.scale_factor * (other.scale_factor + other.offset)),
        )

        # Multiply with the inverted unit
        return self * inverse_unit

    def __pow__(self, power: int) -> "Unit":
        """Raise unit to a power.

        Args:
            power: The power to raise the unit to

        Returns:
            The unit raised to the power
        """
        new_dims = {
            dim: dim_power * power for dim, dim_power in self.dimensions.items()
        }
        new_scale = self.scale_factor**power

        return Unit(
            dimensions=new_dims,
            scale_factor=new_scale,
            prefix=self.prefix,
            offset=self.offset,
        )

    def with_prefix(self, prefix: str) -> "Unit":
        """Apply a prefix to this unit.

        Args:
            prefix: The SI prefix to apply

        Returns:
            A new unit with the prefix applied
        """
        # Get current prefix value (defaults to 1.0 if None)
        current_prefix_value = Prefix.get_value(prefix_symbol=self._prefix)

        # validate the new prefix
        assert Prefix.is_valid(prefix=prefix), "Invalid prefix"
        new_prefix_value = Prefix.get_value(prefix_symbol=prefix)

        # Calculate the new scale factor
        new_scale_factor = self._scale_factor * 10 ** (
            new_prefix_value - current_prefix_value
        )

        return Unit(
            dimensions=self.dimensions.copy(),
            scale_factor=new_scale_factor,
            offset=self.offset,
            prefix=prefix,  # Store the new prefix
        )

    def convert_value_to(self, value: float, target_unit: "Unit") -> float:
        """Convert a value from this unit to another unit.

        Args:
            value: The value in this unit
            target_unit: The unit to convert to

        Returns:
            The converted value

        Raises:
            ValueError: If units are not compatible
        """
        # Check unit compatibility
        if self.dimensions != target_unit.dimensions:
            msg = "Cannot convert: incompatible dimensions"
            raise ValueError(msg)

        # Convert to base units (apply offset then scale)
        base_value = (value + self._offset) * self.scale_factor

        # Convert from base units to target (apply scale then offset)
        return (base_value / target_unit.scale_factor) - target_unit._offset

    def is_compatible_with(self, other: "Unit") -> bool:
        """Check if this unit is compatible with another unit.

        Args:
            other: The unit to compare with

        Returns:
            True if units have the same dimensions
        """
        return self.dimensions == other.dimensions

    def __repr__(self) -> str:
        """Detailed representation of the unit."""
        return f"Unit(prefix={self.prefix}, dimensions={self.dimensions}, scale_factor={self.scale_factor})"
