"""A unit with a symbolic representation."""

from typing import TYPE_CHECKING

from .common_units import CommonUnits
from .constants import (
    DIMENSION_AMOUNT,
    DIMENSION_CURRENT,
    DIMENSION_LENGTH,
    DIMENSION_LUMINOSITY,
    DIMENSION_MASS,
    DIMENSION_TEMPERATURE,
    DIMENSION_TIME,
    UNIT_NAME_AMPERE,
    UNIT_NAME_CANDELA,
    UNIT_NAME_CELSIUS,
    UNIT_NAME_COULOMB,
    UNIT_NAME_DIMENSIONLESS,
    UNIT_NAME_ELECTRON_VOLT,
    UNIT_NAME_FAHRENHEIT,
    UNIT_NAME_FARAD,
    UNIT_NAME_HENRY,
    UNIT_NAME_HERTZ,
    UNIT_NAME_HOUR,
    UNIT_NAME_JOULE,
    UNIT_NAME_KELVIN,
    UNIT_NAME_KILOGRAM,
    UNIT_NAME_METER,
    UNIT_NAME_MINUTE,
    UNIT_NAME_MOLE,
    UNIT_NAME_NEWTON,
    UNIT_NAME_OHM,
    UNIT_NAME_PASCAL,
    UNIT_NAME_PERCENT,
    UNIT_NAME_RADIAN,
    UNIT_NAME_SECOND,
    UNIT_NAME_SIEMENS,
    UNIT_NAME_TESLA,
    UNIT_NAME_VOLT,
    UNIT_NAME_WATT,
    UNIT_NAME_WEBER,
    UNIT_SYMBOL,
    UNIT_SYMBOL_AMPERE,
    UNIT_SYMBOL_CANDELA,
    UNIT_SYMBOL_CELSIUS,
    UNIT_SYMBOL_COULOMB,
    UNIT_SYMBOL_ELECTRON_VOLT,
    UNIT_SYMBOL_FAHRENHEIT,
    UNIT_SYMBOL_FARAD,
    UNIT_SYMBOL_HENRY,
    UNIT_SYMBOL_HERTZ,
    UNIT_SYMBOL_HOUR,
    UNIT_SYMBOL_JOULE,
    UNIT_SYMBOL_KELVIN,
    UNIT_SYMBOL_KILOGRAM,
    UNIT_SYMBOL_METER,
    UNIT_SYMBOL_MINUTE,
    UNIT_SYMBOL_MOLE,
    UNIT_SYMBOL_NEWTON,
    UNIT_SYMBOL_OHM,
    UNIT_SYMBOL_PASCAL,
    UNIT_SYMBOL_PERCENT,
    UNIT_SYMBOL_RADIAN,
    UNIT_SYMBOL_SECOND,
    UNIT_SYMBOL_SIEMENS,
    UNIT_SYMBOL_TESLA,
    UNIT_SYMBOL_VOLT,
    UNIT_SYMBOL_WATT,
    UNIT_SYMBOL_WEBER,
)
from .dependancies import Jsonable
from .unit import Unit

if TYPE_CHECKING:
    from .typing import ClassVar


class SymbolUnit(Jsonable):
    """A unit with symbolic representation.

    This class wraps a Unit and provides a symbol representation by either:
    1. Finding a matching CommonUnit from available CommonUnits
    2. Generating a simplified symbolic representation if no match is found

    This allows units to have readable symbols even when they're created
    through mathematical operations.
    """

    _initialized: "ClassVar[bool]" = False

    _unit: Unit
    _symbol: str
    _name: str

    # Mapping from unit constants to symbols and names
    _UNIT_SYMBOLS: "ClassVar[dict[Unit, str]]" = {}
    _UNIT_NAMES: "ClassVar[dict[Unit, str]]" = {}

    # Base dimension symbols for generating composite symbols
    _DIMENSION_SYMBOLS: "ClassVar[dict[str, str]]" = {
        DIMENSION_LENGTH: UNIT_SYMBOL_METER,
        DIMENSION_MASS: UNIT_SYMBOL_KILOGRAM,
        DIMENSION_TIME: UNIT_SYMBOL_SECOND,
        DIMENSION_CURRENT: UNIT_SYMBOL_AMPERE,
        DIMENSION_TEMPERATURE: UNIT_SYMBOL_KELVIN,
        DIMENSION_AMOUNT: UNIT_SYMBOL_MOLE,
        DIMENSION_LUMINOSITY: UNIT_SYMBOL_CANDELA,
    }

    def __init__(self, unit: Unit):
        """Initialize a SymbolUnit.

        Args:
            unit: The Unit to wrap
        """
        super().__init__()
        self._unit = unit

        # Initialize the cache of common units if not already done
        if not SymbolUnit._initialized:
            self._initialize_common_units()

        # Find matching common unit or generate symbol
        symbol, name = self._find_matching_common_unit()

        self._symbol = symbol
        self._name = name

    @classmethod
    def _initialize_common_units(cls):
        """Initialize the mappings of units to their symbols and names."""
        # Define mappings for each unit in CommonUnits
        unit_info = [
            (CommonUnits.METER, UNIT_SYMBOL_METER, UNIT_NAME_METER),
            (CommonUnits.KILOGRAM, UNIT_SYMBOL_KILOGRAM, UNIT_NAME_KILOGRAM),
            (CommonUnits.SECOND, UNIT_SYMBOL_SECOND, UNIT_NAME_SECOND),
            (CommonUnits.AMPERE, UNIT_SYMBOL_AMPERE, UNIT_NAME_AMPERE),
            (CommonUnits.KELVIN, UNIT_SYMBOL_KELVIN, UNIT_NAME_KELVIN),
            (CommonUnits.MOLE, UNIT_SYMBOL_MOLE, UNIT_NAME_MOLE),
            (CommonUnits.CANDELA, UNIT_SYMBOL_CANDELA, UNIT_NAME_CANDELA),
            (CommonUnits.HERTZ, UNIT_SYMBOL_HERTZ, UNIT_NAME_HERTZ),
            (CommonUnits.NEWTON, UNIT_SYMBOL_NEWTON, UNIT_NAME_NEWTON),
            (CommonUnits.PASCAL, UNIT_SYMBOL_PASCAL, UNIT_NAME_PASCAL),
            (CommonUnits.JOULE, UNIT_SYMBOL_JOULE, UNIT_NAME_JOULE),
            (CommonUnits.WATT, UNIT_SYMBOL_WATT, UNIT_NAME_WATT),
            (CommonUnits.COULOMB, UNIT_SYMBOL_COULOMB, UNIT_NAME_COULOMB),
            (CommonUnits.VOLT, UNIT_SYMBOL_VOLT, UNIT_NAME_VOLT),
            (CommonUnits.FARAD, UNIT_SYMBOL_FARAD, UNIT_NAME_FARAD),
            (CommonUnits.OHM, UNIT_SYMBOL_OHM, UNIT_NAME_OHM),
            (CommonUnits.SIEMENS, UNIT_SYMBOL_SIEMENS, UNIT_NAME_SIEMENS),
            (CommonUnits.WEBER, UNIT_SYMBOL_WEBER, UNIT_NAME_WEBER),
            (CommonUnits.TESLA, UNIT_SYMBOL_TESLA, UNIT_NAME_TESLA),
            (CommonUnits.HENRY, UNIT_SYMBOL_HENRY, UNIT_NAME_HENRY),
            (CommonUnits.MINUTE, UNIT_SYMBOL_MINUTE, UNIT_NAME_MINUTE),
            (CommonUnits.HOUR, UNIT_SYMBOL_HOUR, UNIT_NAME_HOUR),
            (
                CommonUnits.ELECTRON_VOLT,
                UNIT_SYMBOL_ELECTRON_VOLT,
                UNIT_NAME_ELECTRON_VOLT,
            ),
            (CommonUnits.CELSIUS, UNIT_SYMBOL_CELSIUS, UNIT_NAME_CELSIUS),
            (CommonUnits.FAHRENHEIT, UNIT_SYMBOL_FAHRENHEIT, UNIT_NAME_FAHRENHEIT),
            (
                CommonUnits.DIMENSIONLESS,
                UNIT_SYMBOL,
                UNIT_NAME_DIMENSIONLESS,
            ),
            (CommonUnits.PERCENT, UNIT_SYMBOL_PERCENT, UNIT_NAME_PERCENT),
            (CommonUnits.RADIAN, UNIT_SYMBOL_RADIAN, UNIT_NAME_RADIAN),
        ]

        # Store the units directly in the symbol and name mappings
        for unit, symbol, name in unit_info:
            cls._UNIT_SYMBOLS[unit] = symbol
            cls._UNIT_NAMES[unit] = name

        cls._initialized = True

    def _find_matching_common_unit(self) -> tuple[str, str]:
        """Find a matching CommonUnit for this unit.

        Returns:
            Tuple of (symbol, name)
            If no match is found, generates a symbol and name
        """
        # Check for exact match with a common unit
        for common_unit, symbol in self._UNIT_SYMBOLS.items():
            if self._unit.dimensions == common_unit.dimensions:
                return self._unit.prefix + symbol, self._unit.prefix + self._UNIT_NAMES[
                    common_unit
                ]

        # No exact match found, generate a symbol and name
        return self._generate_symbol(), self._generate_name()

    def _generate_symbol(self) -> str:
        """Generate a symbolic representation for this unit.

        Uses dimensional information to create a string representation.
        For example: m·s⁻², kg·m/s², etc.

        Returns:
            A string representation of the unit
        """
        dimensions = self._unit.dimensions

        # If dimensionless, return appropriate representation
        if not dimensions:  # Empty dimensions dict means dimensionless
            if self._unit.scale_factor == 1.0:
                return ""
            if self._unit.scale_factor == 0.01:
                return "%"  # Special case for percent
            return str(self._unit.scale_factor)

        # Separate positive and negative powers
        numerator = {dim: power for dim, power in dimensions.items() if power > 0}
        denominator = {dim: -power for dim, power in dimensions.items() if power < 0}

        # Build numerator string
        num_symbols = []
        for dim, power in numerator.items():
            # Get the symbol for this dimension
            symbol = self._get_dimension_symbol(dim)
            if power == 1:
                num_symbols.append(symbol)
            else:
                num_symbols.append(f"{symbol}^{power}")

        # Build denominator string
        denom_symbols = []
        for dim, power in denominator.items():
            # Get the symbol for this dimension
            symbol = self._get_dimension_symbol(dim)
            if power == 1:
                denom_symbols.append(symbol)
            else:
                denom_symbols.append(f"{symbol}^{-power}")

        # Add prefix if present
        prefix = self._unit.prefix

        # Combine with proper formatting
        if not num_symbols:
            numerator_str = "1"
        elif len(num_symbols) == 1:
            numerator_str = f"{prefix}{num_symbols[0]}"
        else:
            # Multiple numerator terms
            terms = []
            # Apply prefix only to first term
            terms.append(f"{prefix}{num_symbols[0]}")
            terms.extend(num_symbols[1:])
            numerator_str = "·".join(terms)

        if not denom_symbols:
            return numerator_str

        # If there's a single denominator with power 1, use slash notation
        if len(denom_symbols) == 1 and "^" not in denom_symbols[0]:
            return f"{numerator_str}/{denom_symbols[0]}"

        # Otherwise, use negative exponent notation
        denominator_str = "·".join(denom_symbols)
        return f"{numerator_str}·{denominator_str}"

    def _get_dimension_symbol(self, dimension: str) -> str:
        """Get a symbol for a dimension.

        Args:
            dimension: The dimension name

        Returns:
            A symbol for the dimension
        """
        # Use predefined dimension symbols
        if dimension in self._DIMENSION_SYMBOLS:
            return self._DIMENSION_SYMBOLS[dimension]

        # If no match found, use the dimension name
        return dimension

    def _generate_name(self) -> str:
        """Generate a name for this unit.

        Returns:
            A name for the unit
        """
        # Look for a common unit with the same dimensions
        for common_unit, name in self._UNIT_NAMES.items():
            if self._unit.dimensions == common_unit.dimensions:
                return name

        # Otherwise, use the symbol as the name
        return self._generate_symbol()

    @property
    def unit(self) -> Unit:
        """Get the underlying unit.

        Returns:
            The wrapped Unit
        """
        return self._unit

    @property
    def symbol(self) -> str:
        """Get the symbolic representation.

        Returns:
            The symbol for this unit
        """
        return self._symbol

    @property
    def name(self) -> str:
        """Get the name of this unit.

        Returns:
            The name of this unit
        """
        return self._name

    def __str__(self) -> str:
        """String representation of the unit.

        Returns:
            The symbol
        """
        return self.symbol

    def __repr__(self) -> str:
        """Detailed representation of the unit.

        Returns:
            A detailed string representation
        """
        return (
            f"SymbolUnit(symbol='{self.symbol}', name='{self.name}', unit={self._unit})"
        )

    def __mul__(self, other) -> "SymbolUnit":
        """Multiply this unit with another.

        Args:
            other: Another SymbolUnit or Unit

        Returns:
            A new SymbolUnit representing the product

        Raises:
            NotImplementedError: If other is not a SymbolUnit or Unit
        """
        if isinstance(other, SymbolUnit):
            return SymbolUnit(self._unit * other._unit)
        if isinstance(other, Unit):
            return SymbolUnit(self._unit * other)
        raise NotImplementedError

    def __truediv__(self, other) -> "SymbolUnit":
        """Divide this unit by another.

        Args:
            other: Another SymbolUnit or Unit

        Returns:
            A new SymbolUnit representing the quotient

        Raises:
            NotImplementedError: If other is not a SymbolUnit or Unit
        """
        if isinstance(other, SymbolUnit):
            return SymbolUnit(self._unit / other._unit)
        if isinstance(other, Unit):
            return SymbolUnit(self._unit / other)
        raise NotImplementedError

    def __pow__(self, power: int) -> "SymbolUnit":
        """Raise this unit to a power.

        Args:
            power: The power to raise to

        Returns:
            A new SymbolUnit representing the power
        """
        return SymbolUnit(self._unit**power)

    def with_prefix(self, prefix: str) -> "SymbolUnit":
        """Apply a prefix to this unit.

        Args:
            prefix: The SI prefix to apply

        Returns:
            A new SymbolUnit with the prefix applied
        """
        return SymbolUnit(self._unit.with_prefix(prefix))

    def convert_value_to(self, value: float, target: "SymbolUnit") -> float:
        """Convert a value from this unit to another.

        Args:
            value: The value to convert
            target: The target SymbolUnit

        Returns:
            The converted value
        """
        return self._unit.convert_value_to(value, target._unit)

    def is_compatible_with(self, other: "SymbolUnit") -> bool:
        """Check if this unit is compatible with another.

        Args:
            other: The other SymbolUnit

        Returns:
            True if units have the same dimensions
        """
        return self._unit.is_compatible_with(other._unit)
