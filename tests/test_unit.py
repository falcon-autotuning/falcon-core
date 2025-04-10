# """Tests for the Unit class."""

from math import isclose

import pytest

from falcon_core.constants import (
    DIMENSIONS_METER,
    DIMENSIONS_SECOND,
    KILO_SYMBOL,
    MILLI_SYMBOL,
    UNIT_NAME_METER,
    UNIT_NAME_SECOND,
    UNIT_NAME_VOLT,
    UNIT_SYMBOL_JOULE,
    UNIT_SYMBOL_METER,
    UNIT_SYMBOL_SECOND,
    UNIT_SYMBOL_VOLT,
)
from falcon_core.instrument_interfaces.physics_units import SymbolUnit, Units
from falcon_core.instrument_interfaces.physics_units.unit import Unit


class TestSymbolUnit:
    """Test suite for the SymbolUnit class."""

    def test_initialization(self):
        """Test initialization with various units."""
        # Test with common units
        m = Units.METER
        s = Units.SECOND
        v = Units.VOLT

        assert m.symbol == UNIT_SYMBOL_METER
        assert m.name == UNIT_NAME_METER
        assert s.symbol == UNIT_SYMBOL_SECOND
        assert s.name == UNIT_NAME_SECOND
        assert v.symbol == UNIT_SYMBOL_VOLT
        assert v.name == UNIT_NAME_VOLT

    def test_prefixed_units(self):
        """Test units with prefixes."""
        # Test with prefixed units
        mm = Units.MILLIMETER
        kv = Units.KILOVOLT

        assert mm.symbol == f"{MILLI_SYMBOL}{UNIT_SYMBOL_METER}"
        assert kv.symbol == f"{KILO_SYMBOL}{UNIT_SYMBOL_VOLT}"

    def test_operations(self):
        """Test mathematical operations on units."""
        # Test multiplication
        m = Units.METER
        s = Units.SECOND
        v = Units.VOLT

        # m·s
        m_times_s = m * s
        assert m_times_s.unit.dimensions == {**DIMENSIONS_METER, **DIMENSIONS_SECOND}
        assert m_times_s.symbol == f"{UNIT_SYMBOL_METER}·{UNIT_SYMBOL_SECOND}"

        # Test division
        m_per_s = m / s
        assert m_per_s.symbol == f"{UNIT_SYMBOL_METER}/{UNIT_SYMBOL_SECOND}"

        # Test more complex operations
        ohm = Units.OHM
        v_div_ohm = v / ohm
        assert v_div_ohm.unit.dimensions == {
            # Ampere has dimensions of current
            "CURRENT": 1
        }

    def test_equality_and_compatibility(self):
        """Test equality and compatibility between units."""
        # Test equality
        m1 = Units.METER
        m2 = Units.METER
        s = Units.SECOND

        # Units should be equal if they have the same dimensions and scale factors
        assert m1.unit == m2.unit
        assert m1.unit != s.unit

        # Test compatibility
        mm = Units.MILLIMETER
        assert m1.is_compatible_with(mm)
        assert not m1.is_compatible_with(s)

    def test_conversion(self):
        """Test conversion between compatible units."""
        m = Units.METER
        mm = Units.MILLIMETER
        km = Units.KILOMETER

        # 1 m = 1000 mm
        assert isclose(m.convert_value_to(1.0, mm), 1000.0)
        # 1 m = 0.001 km
        assert isclose(m.convert_value_to(1.0, km), 0.001)
        # 1 km = 1000 m
        assert isclose(km.convert_value_to(1.0, m), 1000.0)
        # 1 km = 1,000,000 mm
        assert isclose(km.convert_value_to(1.0, mm), 1_000_000.0)

    def test_derived_units(self):
        """Test recognition and generation of derived unit symbols."""
        # Test derived units like m/s, N·m, etc.
        m = Units.METER
        s = Units.SECOND
        n = Units.NEWTON

        m_per_s = m / s
        n_times_m = n * m  # Should be joule

        assert m_per_s.symbol == f"{UNIT_SYMBOL_METER}/{UNIT_SYMBOL_SECOND}"

        # N·m should be recognized as joule
        assert n_times_m.unit == Units.JOULE.unit
        # Since we're generating symbols based on components, we'll get N·m even though it's a joule
        assert n_times_m.symbol == f"{UNIT_SYMBOL_JOULE}"

    def test_dimensionless_units(self):
        """Test dimensionless units."""
        dimensionless = Units.DIMENSIONLESS
        percent = Units.PERCENT

        assert dimensionless.unit.dimensions == {}
        assert percent.unit.dimensions == {}
        assert percent.unit.scale_factor == 0.01

        # 100% = 1.0 dimensionless
        assert isclose(percent.convert_value_to(100.0, dimensionless), 1.0)

    def test_complex_units(self):
        """Test more complex unit combinations."""
        m = Units.METER
        s = Units.SECOND

        # Create m/s²
        acceleration = m / (s**2)

        assert acceleration.unit.dimensions == {"LENGTH": 1, "TIME": -2}

        # Symbol should show negative exponent
        assert acceleration.symbol == f"{UNIT_SYMBOL_METER}·{UNIT_SYMBOL_SECOND}^-2"

    def test_custom_unit(self):
        """Test with a custom unit not in CommonUnits."""
        # Create a custom unit with dimensions {length: 3}
        volume_dimensions = {"LENGTH": 3}
        custom_unit = Unit(dimensions=volume_dimensions)
        symbol_unit = SymbolUnit(custom_unit)

        # Should generate a symbol based on dimensions
        assert symbol_unit.symbol == f"{UNIT_SYMBOL_METER}^3"

    def test_symbol_generation(self):
        """Test symbol generation for units not in CommonUnits."""
        # Create various custom units
        length_time = Unit(dimensions={"LENGTH": 1, "TIME": 1})
        complex_unit = Unit(dimensions={"LENGTH": 2, "TIME": -1, "MASS": 1})

        # Test symbol generation
        length_time_symbol = SymbolUnit(length_time)
        complex_symbol = SymbolUnit(complex_unit)

        assert length_time_symbol.symbol == f"{UNIT_SYMBOL_METER}·{UNIT_SYMBOL_SECOND}"
        # Complex unit will have kg·m²/s
        assert "k" in complex_symbol.symbol
        assert "m^2" in complex_symbol.symbol
        assert "s" in complex_symbol.symbol

    def test_with_prefix(self):
        """Test applying prefix to a SymbolUnit."""
        m = Units.METER
        km = m.with_prefix(KILO_SYMBOL)

        assert km.symbol == f"{KILO_SYMBOL}{UNIT_SYMBOL_METER}"
        assert km.unit.scale_factor == 1000.0
        assert km.unit.dimensions == m.unit.dimensions

    def test_invalid_conversion(self):
        """Test invalid unit conversion raises ValueError."""
        m = Units.METER
        s = Units.SECOND

        with pytest.raises(ValueError):
            m.convert_value_to(10.0, s)

    def test_comparison(self):
        """Test comparison of SymbolUnit objects through their underlying units."""
        # Units with same physical meaning but different representations
        m_per_s = Units.METER / Units.SECOND
        v = SymbolUnit(Unit(dimensions={"LENGTH": 1, "TIME": -1}))

        # The underlying units should be equal
        assert m_per_s.unit == v.unit

        # But the symbols might differ based on how they were constructed
        # m_per_s might be "m/s" while v might use the dimension names

    def test_string_representations(self):
        """Test string and repr representations."""
        m = Units.METER

        # str() should return the symbol
        assert str(m) == UNIT_SYMBOL_METER

        # repr() should include symbol, name, and unit details
        repr_str = repr(m)
        assert f"symbol='{UNIT_SYMBOL_METER}'" in repr_str
        assert f"name='{UNIT_NAME_METER}'" in repr_str
        assert "unit=" in repr_str

    def test_power_operations(self):
        """Test power operations on SymbolUnits."""
        m = Units.METER

        # m² (area)
        area = m**2
        assert area.unit.dimensions == {"LENGTH": 2}
        assert "m^2" in area.symbol

        # m³ (volume)
        volume = m**3
        assert volume.unit.dimensions == {"LENGTH": 3}
        assert "m^3" in volume.symbol


if __name__ == "__main__":
    pytest.main(["-xvs", __file__])
