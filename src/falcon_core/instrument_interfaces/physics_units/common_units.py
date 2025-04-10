"""Factory for creating common physical units."""

from .constants import (
    # Conversion factors
    CELSIUS_OFFSET,
    DIMENSIONS_AMPERE,
    DIMENSIONS_CANDELA,
    DIMENSIONS_COULOMB,
    DIMENSIONS_DIMENSIONLESS,
    DIMENSIONS_FARAD,
    DIMENSIONS_HENRY,
    DIMENSIONS_HERTZ,
    DIMENSIONS_JOULE,
    DIMENSIONS_KELVIN,
    DIMENSIONS_KILOGRAM,
    # Dimension dictionaries
    DIMENSIONS_METER,
    DIMENSIONS_MOLE,
    DIMENSIONS_NEWTON,
    DIMENSIONS_OHM,
    DIMENSIONS_PASCAL,
    DIMENSIONS_SECOND,
    DIMENSIONS_SIEMENS,
    DIMENSIONS_TESLA,
    DIMENSIONS_VOLT,
    DIMENSIONS_WATT,
    DIMENSIONS_WEBER,
    ELECTRON_CHARGE,
    FAHRENHEIT_OFFSET,
    KILO_SYMBOL,
    MEGA_SYMBOL,
    MICRO_SYMBOL,
    MILLI_SYMBOL,
    MINUTES_PER_HOUR,
    SECONDS_PER_MINUTE,
    UNIT_SCALE_FAHRENHEIT,
)
from .unit import Unit


class CommonUnits:
    """Factory for common physical units."""

    # SI base units
    METER = Unit(dimensions=DIMENSIONS_METER)
    KILOGRAM = Unit(dimensions=DIMENSIONS_KILOGRAM)
    SECOND = Unit(dimensions=DIMENSIONS_SECOND)
    AMPERE = Unit(dimensions=DIMENSIONS_AMPERE)
    KELVIN = Unit(dimensions=DIMENSIONS_KELVIN)
    MOLE = Unit(dimensions=DIMENSIONS_MOLE)
    CANDELA = Unit(dimensions=DIMENSIONS_CANDELA)

    # Derived SI units
    HERTZ = Unit(dimensions=DIMENSIONS_HERTZ)
    NEWTON = Unit(dimensions=DIMENSIONS_NEWTON)
    PASCAL = Unit(dimensions=DIMENSIONS_PASCAL)
    JOULE = Unit(dimensions=DIMENSIONS_JOULE)
    WATT = Unit(dimensions=DIMENSIONS_WATT)
    COULOMB = Unit(dimensions=DIMENSIONS_COULOMB)
    VOLT = Unit(dimensions=DIMENSIONS_VOLT)
    FARAD = Unit(dimensions=DIMENSIONS_FARAD)
    OHM = Unit(dimensions=DIMENSIONS_OHM)
    SIEMENS = Unit(dimensions=DIMENSIONS_SIEMENS)
    WEBER = Unit(dimensions=DIMENSIONS_WEBER)
    TESLA = Unit(dimensions=DIMENSIONS_TESLA)
    HENRY = Unit(dimensions=DIMENSIONS_HENRY)

    # Common non-SI units
    MINUTE = Unit(
        dimensions=DIMENSIONS_SECOND,  # Same dimensions as second
        scale_factor=SECONDS_PER_MINUTE,
    )
    HOUR = Unit(
        dimensions=DIMENSIONS_SECOND,  # Same dimensions as second
        scale_factor=SECONDS_PER_MINUTE * MINUTES_PER_HOUR,
    )
    ELECTRON_VOLT = Unit(
        dimensions=DIMENSIONS_JOULE,  # Same dimensions as joule
        scale_factor=ELECTRON_CHARGE,
    )

    # Temperature units with offsets
    CELSIUS = Unit(
        dimensions=DIMENSIONS_KELVIN,  # Same dimensions as kelvin
        offset=CELSIUS_OFFSET,
    )
    FAHRENHEIT = Unit(
        dimensions=DIMENSIONS_KELVIN,  # Same dimensions as kelvin
        scale_factor=UNIT_SCALE_FAHRENHEIT,
        offset=FAHRENHEIT_OFFSET,
    )

    # Dimensionless units
    DIMENSIONLESS = Unit(dimensions=DIMENSIONS_DIMENSIONLESS)
    PERCENT = Unit(
        dimensions=DIMENSIONS_DIMENSIONLESS,
        scale_factor=0.01,
    )
    RADIAN = Unit(dimensions=DIMENSIONS_DIMENSIONLESS)  # Dimensionless angle

    # Keep the existing methods unchanged
    @classmethod
    def get_unit_with_prefix(cls, unit: Unit, prefix: str) -> Unit:
        """Get a unit with an SI prefix applied."""
        return unit.with_prefix(prefix)

    @classmethod
    def get_milli(cls, unit: Unit) -> Unit:
        """Get the milli- version of a unit."""
        return cls.get_unit_with_prefix(unit, MILLI_SYMBOL)

    @classmethod
    def get_micro(cls, unit: Unit) -> Unit:
        """Get the micro- version of a unit."""
        return cls.get_unit_with_prefix(unit, MICRO_SYMBOL)

    @classmethod
    def get_kilo(cls, unit: Unit) -> Unit:
        """Get the kilo- version of a unit."""
        return cls.get_unit_with_prefix(unit, KILO_SYMBOL)

    @classmethod
    def get_mega(cls, unit: Unit) -> Unit:
        """Get the mega- version of a unit."""
        return cls.get_unit_with_prefix(unit, MEGA_SYMBOL)
