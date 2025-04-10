"""Tests for the CommonUnits class."""

import pytest

from falcon_core.constants import MILLI_SYMBOL
from falcon_core.datatypes.units.common_units import CommonUnits
from falcon_core.datatypes.units.dimension import Dimension


class TestCommonUnits:
    """Test suite for the CommonUnits class."""

    def test_base_units(self):
        """Test that base SI units are correctly defined."""
        # Check meter
        meter = CommonUnits.METER
        assert meter.dimensions == {Dimension.LENGTH: 1}
        assert meter.scale_factor == 1.0

        # Check kilogram
        kg = CommonUnits.KILOGRAM
        assert kg.dimensions == {Dimension.MASS: 1}

        # Check ampere
        ampere = CommonUnits.AMPERE
        assert ampere.dimensions == {Dimension.CURRENT: 1}

        # Check second
        second = CommonUnits.SECOND
        assert second.dimensions == {Dimension.TIME: 1}

    def test_derived_units(self):
        """Test that derived SI units have correct dimensions."""
        # Volt dimensions check
        volt = CommonUnits.VOLT
        expected_volt_dims = {
            Dimension.MASS: 1,
            Dimension.LENGTH: 2,
            Dimension.TIME: -3,
            Dimension.CURRENT: -1,
        }
        assert volt.dimensions == expected_volt_dims

        # Newton dimensions check
        newton = CommonUnits.NEWTON
        expected_newton_dims = {
            Dimension.MASS: 1,
            Dimension.LENGTH: 1,
            Dimension.TIME: -2,
        }
        assert newton.dimensions == expected_newton_dims

        # Hertz check
        hertz = CommonUnits.HERTZ
        assert hertz.dimensions == {Dimension.TIME: -1}

        # Tesla check
        tesla = CommonUnits.TESLA
        expected_tesla_dims = {
            Dimension.MASS: 1,
            Dimension.TIME: -2,
            Dimension.CURRENT: -1,
        }
        assert tesla.dimensions == expected_tesla_dims

    def test_consistency_with_definitions(self):
        """Test derived units are consistent with their base unit definitions."""
        # Joule = Newton * meter
        joule = CommonUnits.JOULE
        newton_meter = CommonUnits.NEWTON * CommonUnits.METER
        assert joule.dimensions == newton_meter.dimensions

        # Watt = Joule / second
        watt = CommonUnits.WATT
        joule_per_second = CommonUnits.JOULE / CommonUnits.SECOND
        assert watt.dimensions == joule_per_second.dimensions

        # Volt = Watt / Ampere
        volt = CommonUnits.VOLT
        watt_per_ampere = CommonUnits.WATT / CommonUnits.AMPERE
        assert volt.dimensions == watt_per_ampere.dimensions

        # Ohm = Volt / Ampere
        ohm = CommonUnits.OHM
        volt_per_ampere = CommonUnits.VOLT / CommonUnits.AMPERE
        assert ohm.dimensions == volt_per_ampere.dimensions

    def test_non_si_units(self):
        """Test non-SI units are correctly defined."""
        # Minute
        minute = CommonUnits.MINUTE
        assert minute.dimensions == {Dimension.TIME: 1}
        assert minute.scale_factor == 60.0  # 60 seconds

        # Hour
        hour = CommonUnits.HOUR
        assert hour.dimensions == {Dimension.TIME: 1}
        assert hour.scale_factor == 3600.0  # 3600 seconds

        # Electron volt
        ev = CommonUnits.ELECTRON_VOLT
        assert ev.dimensions == {
            Dimension.MASS: 1,
            Dimension.LENGTH: 2,
            Dimension.TIME: -2,
        }
        assert ev.scale_factor == pytest.approx(1.602176634e-19)

    def test_temperature_units(self):
        """Test temperature units with offsets."""
        # Kelvin (base unit)
        kelvin = CommonUnits.KELVIN
        assert kelvin.dimensions == {Dimension.TEMPERATURE: 1}
        assert kelvin.scale_factor == 1.0
        assert kelvin.offset == 0.0

        # Celsius
        celsius = CommonUnits.CELSIUS
        assert celsius.dimensions == {Dimension.TEMPERATURE: 1}
        assert celsius.scale_factor == 1.0
        assert celsius.offset == 273.15

        # Fahrenheit
        fahrenheit = CommonUnits.FAHRENHEIT
        assert fahrenheit.dimensions == {Dimension.TEMPERATURE: 1}
        assert fahrenheit.scale_factor == pytest.approx(5 / 9)
        assert fahrenheit.offset == pytest.approx(459.67)

        # Temperature conversion validation
        # 0°C = 273.15K
        assert celsius.convert_value_to(0.0, kelvin) == pytest.approx(273.15)
        # 0K = -273.15°C
        assert kelvin.convert_value_to(0.0, celsius) == pytest.approx(-273.15)
        # 32°F = 0°C
        assert fahrenheit.convert_value_to(32.0, celsius) == pytest.approx(0.0)

    def test_dimensionless_units(self):
        """Test dimensionless units."""
        dimensionless = CommonUnits.DIMENSIONLESS
        assert dimensionless.dimensions == {}
        assert dimensionless.scale_factor == 1.0

        percent = CommonUnits.PERCENT
        assert percent.dimensions == {}
        assert percent.scale_factor == 0.01

        # 100% = 1.0 dimensionless
        assert percent.convert_value_to(100.0, dimensionless) == 1.0

    def test_get_unit_with_prefix(self):
        """Test getting units with different prefixes."""
        # General prefix method
        millimeter = CommonUnits.get_unit_with_prefix(CommonUnits.METER, MILLI_SYMBOL)
        assert millimeter.dimensions == {Dimension.LENGTH: 1}
        assert millimeter.scale_factor == 0.001

        # Specific prefix methods
        km = CommonUnits.get_kilo(CommonUnits.METER)
        assert km.scale_factor == 1000.0

        uA = CommonUnits.get_micro(CommonUnits.AMPERE)
        assert uA.scale_factor == 1e-6

        mV = CommonUnits.get_milli(CommonUnits.VOLT)
        assert mV.scale_factor == 0.001

        MW = CommonUnits.get_mega(CommonUnits.WATT)
        assert MW.scale_factor == 1e6

    def test_conversion_between_prefixed_units(self):
        """Test converting values between units with different prefixes."""
        # 1 km to m
        km = CommonUnits.get_kilo(CommonUnits.METER)
        meters_in_km = km.convert_value_to(1.0, CommonUnits.METER)
        assert meters_in_km == 1000.0

        # 1000 mV to V
        mV = CommonUnits.get_milli(CommonUnits.VOLT)
        volts_in_mV = mV.convert_value_to(1000.0, CommonUnits.VOLT)
        assert volts_in_mV == 1.0

        # 1 MW to kW
        MW = CommonUnits.get_mega(CommonUnits.WATT)
        kW = CommonUnits.get_kilo(CommonUnits.WATT)
        kW_in_MW = MW.convert_value_to(1.0, kW)
        assert kW_in_MW == 1000.0


if __name__ == "__main__":
    pytest.main(["-xvs", __file__])
