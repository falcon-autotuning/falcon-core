"""Convenient access to common units with symbolic representation."""

from .common_units import CommonUnits
from .symbol_unit import SymbolUnit


class Units:
    """Provides convenient access to common units as SymbolUnit objects.

    This class provides static attributes for all common units, allowing
    easy access like Units.VOLT instead of SymbolUnit(CommonUnits.VOLT).

    All units are pre-defined as class attributes for direct access with
    IDE completion support.
    """

    # SI base units
    METER = SymbolUnit(CommonUnits.METER)
    KILOGRAM = SymbolUnit(CommonUnits.KILOGRAM)
    SECOND = SymbolUnit(CommonUnits.SECOND)
    AMPERE = SymbolUnit(CommonUnits.AMPERE)
    KELVIN = SymbolUnit(CommonUnits.KELVIN)
    MOLE = SymbolUnit(CommonUnits.MOLE)
    CANDELA = SymbolUnit(CommonUnits.CANDELA)

    # Derived SI units
    HERTZ = SymbolUnit(CommonUnits.HERTZ)
    NEWTON = SymbolUnit(CommonUnits.NEWTON)
    PASCAL = SymbolUnit(CommonUnits.PASCAL)
    JOULE = SymbolUnit(CommonUnits.JOULE)
    WATT = SymbolUnit(CommonUnits.WATT)
    COULOMB = SymbolUnit(CommonUnits.COULOMB)
    VOLT = SymbolUnit(CommonUnits.VOLT)
    FARAD = SymbolUnit(CommonUnits.FARAD)
    OHM = SymbolUnit(CommonUnits.OHM)
    SIEMENS = SymbolUnit(CommonUnits.SIEMENS)
    WEBER = SymbolUnit(CommonUnits.WEBER)
    TESLA = SymbolUnit(CommonUnits.TESLA)
    HENRY = SymbolUnit(CommonUnits.HENRY)

    # Common non-SI units
    MINUTE = SymbolUnit(CommonUnits.MINUTE)
    HOUR = SymbolUnit(CommonUnits.HOUR)
    ELECTRON_VOLT = SymbolUnit(CommonUnits.ELECTRON_VOLT)

    # Temperature units with offsets
    CELSIUS = SymbolUnit(CommonUnits.CELSIUS)
    FAHRENHEIT = SymbolUnit(CommonUnits.FAHRENHEIT)

    # Dimensionless units
    DIMENSIONLESS = SymbolUnit(CommonUnits.DIMENSIONLESS)
    PERCENT = SymbolUnit(CommonUnits.PERCENT)
    RADIAN = SymbolUnit(CommonUnits.RADIAN)

    # Common prefixed units
    MILLIMETER = SymbolUnit(CommonUnits.get_milli(CommonUnits.METER))
    CENTIMETER = SymbolUnit(CommonUnits.get_unit_with_prefix(CommonUnits.METER, "c"))
    KILOMETER = SymbolUnit(CommonUnits.get_kilo(CommonUnits.METER))

    MILLIVOLT = SymbolUnit(CommonUnits.get_milli(CommonUnits.VOLT))
    KILOVOLT = SymbolUnit(CommonUnits.get_kilo(CommonUnits.VOLT))

    MILLIAMPERE = SymbolUnit(CommonUnits.get_milli(CommonUnits.AMPERE))
    MICROAMPERE = SymbolUnit(CommonUnits.get_micro(CommonUnits.AMPERE))

    MILLISECOND = SymbolUnit(CommonUnits.get_milli(CommonUnits.SECOND))
    MICROSECOND = SymbolUnit(CommonUnits.get_micro(CommonUnits.SECOND))

    MILLIOHM = SymbolUnit(CommonUnits.get_milli(CommonUnits.OHM))
    KILOOHM = SymbolUnit(CommonUnits.get_kilo(CommonUnits.OHM))
    MEGAOHM = SymbolUnit(CommonUnits.get_mega(CommonUnits.OHM))

    MILLIHERTZ = SymbolUnit(CommonUnits.get_milli(CommonUnits.HERTZ))
    KILOHERTZ = SymbolUnit(CommonUnits.get_kilo(CommonUnits.HERTZ))
    MEGAHERTZ = SymbolUnit(CommonUnits.get_mega(CommonUnits.HERTZ))

    # Derived units from combinations
    METERS_PER_SECOND = SymbolUnit(CommonUnits.METER / CommonUnits.SECOND)
    METERS_PER_SECOND_SQUARED = SymbolUnit(CommonUnits.METER / (CommonUnits.SECOND**2))

    NEWTON_METER = SymbolUnit(CommonUnits.NEWTON * CommonUnits.METER)
    NEWTON_PER_METER = SymbolUnit(CommonUnits.NEWTON / CommonUnits.METER)

    VOLT_PER_METER = SymbolUnit(CommonUnits.VOLT / CommonUnits.METER)

    AMPERE_PER_VOLT = SymbolUnit(CommonUnits.AMPERE / CommonUnits.VOLT)  # Siemens
    VOLT_PER_AMPERE = SymbolUnit(CommonUnits.VOLT / CommonUnits.AMPERE)  # Ohm

    WATTS_PER_METER_KELVIN = SymbolUnit(
        CommonUnits.WATT / (CommonUnits.METER * CommonUnits.KELVIN)
    )

    # Convenience method to get a unit by name
    @classmethod
    def get(cls, unit_name: str) -> SymbolUnit:
        """Get a unit by name.

        Args:
            unit_name: The name of the unit (case-insensitive)

        Returns:
            The corresponding SymbolUnit

        Raises:
            ValueError: If the unit is not found
        """
        try:
            return getattr(cls, unit_name.upper())
        except AttributeError:
            msg = f"Unit '{unit_name}' not found"
            raise ValueError(msg)

    @classmethod
    def list_available(cls) -> list[str]:
        """List all available unit names.

        Returns:
            A list of available unit names
        """
        return [
            attr
            for attr in dir(cls)
            if not attr.startswith("_") and isinstance(getattr(cls, attr), SymbolUnit)
        ]
