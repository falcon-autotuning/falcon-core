#include <gtest/gtest.h>

#include "falcon_core/Constants.hpp"
#include "falcon_core/macros.hpp"
#include "falcon_core/physics/units/CommonUnits.hpp"
#include "falcon_core/physics/units/TotalDimensions.hpp"
#include "falcon_core/physics/units/Unit.hpp"
using namespace falcon_core;
using namespace falcon_core::physics::units;
#define SPU(...) SP(Unit, __VA_ARGS__)
/**
 * @brief test that the base SI units are correctly defined.
 */
TEST(TestCommonUnits, BaseUnits) {
  Unit            meter = common_units::Meter;
  TotalDimensions mdims = {{SI::DIMENSION_LENGTH, 1}};
  ASSERT_EQ(meter.dimensions(), mdims);
  ASSERT_DOUBLE_EQ(meter.scale_factor(), 1.0);

  Unit            kilogram = common_units::Kilogram;
  TotalDimensions k_dims   = {{SI::DIMENSION_MASS, 1}};
  ASSERT_EQ(kilogram.dimensions(), k_dims);

  Unit            ampere = common_units::Ampere;
  TotalDimensions a_dims = {{SI::DIMENSION_CURRENT, 1}};
  ASSERT_EQ(ampere.dimensions(), a_dims);

  Unit            second = common_units::Second;
  TotalDimensions s_dims = {{SI::DIMENSION_TIME, 1}};
  ASSERT_EQ(second.dimensions(), s_dims);
}

TEST(TestCommonUnits, DerivedUnits) {
  Unit            volt               = common_units::Volt;
  TotalDimensions expected_volt_dims = {
      {SI::DIMENSION_MASS, 1},
      {SI::DIMENSION_LENGTH, 2},
      {SI::DIMENSION_TIME, -3},
      {SI::DIMENSION_CURRENT, -1},
  };
  ASSERT_EQ(volt.dimensions(), expected_volt_dims);

  Unit            newton               = common_units::Newton;
  TotalDimensions expected_newton_dims = {
      {SI::DIMENSION_MASS, 1},
      {SI::DIMENSION_LENGTH, 1},
      {SI::DIMENSION_TIME, -2},
  };
  ASSERT_EQ(newton.dimensions(), expected_newton_dims);

  Unit            hertz               = common_units::Hertz;
  TotalDimensions expected_hertz_dims = {
      {SI::DIMENSION_TIME, -1},
  };
  ASSERT_EQ(hertz.dimensions(), expected_hertz_dims);

  Unit            tesla               = common_units::Tesla;
  TotalDimensions expected_tesla_dims = {
      {SI::DIMENSION_MASS, 1},
      {SI::DIMENSION_TIME, -2},
      {SI::DIMENSION_CURRENT, -1},
  };
  ASSERT_EQ(tesla.dimensions(), expected_tesla_dims);
}

TEST(TestCommonUnits, ConsistencyWithDefinitionJoule) {
  // Joule = Newton * Meter
  Unit   joule        = common_units::Joule;
  UnitSP newton_meter = common_units::Newton * SPU(common_units::Meter);
  ASSERT_EQ(joule.dimensions(), newton_meter->dimensions());
}

TEST(TestCommonUnits, ConsistencyWithDefinitionWatt) {
  // Watt = Joule / Second
  Unit   watt             = common_units::Watt;
  UnitSP joule_per_second = common_units::Joule / SPU(common_units::Second);
  ASSERT_EQ(watt.dimensions(), joule_per_second->dimensions());
}

TEST(TestCommonUnits, ConsistencyWithDefinitionVolt) {
  // Volt = Watt / Ampere
  Unit   volt            = common_units::Volt;
  UnitSP watt_per_ampere = common_units::Watt / SPU(common_units::Ampere);
  ASSERT_EQ(volt.dimensions(), watt_per_ampere->dimensions());
}

TEST(TestCommonUnits, ConsistencyWithDefinitionOhm) {
  // Ohm = Volt / Ampere
  Unit   ohm             = common_units::Ohm;
  UnitSP volt_per_ampere = common_units::Volt / SPU(common_units::Ampere);
  ASSERT_EQ(ohm.dimensions(), volt_per_ampere->dimensions());
}

// Non-SI units
TEST(TestCommonUnits, NonSIUnits) {
  // Minute
  Unit            minute   = common_units::Minute;
  TotalDimensions time_dim = {{SI::DIMENSION_TIME, 1}};
  ASSERT_EQ(minute.dimensions(), time_dim);
  ASSERT_DOUBLE_EQ(minute.scale_factor(), 60.0);

  // Hour
  Unit hour = common_units::Hour;
  ASSERT_EQ(hour.dimensions(), time_dim);
  ASSERT_DOUBLE_EQ(hour.scale_factor(), 3600.0);

  // Electron volt
  Unit            ev      = common_units::ElectronVolt;
  TotalDimensions ev_dims = {
      {SI::DIMENSION_MASS, 1},
      {SI::DIMENSION_LENGTH, 2},
      {SI::DIMENSION_TIME, -2},
  };
  ASSERT_EQ(ev.dimensions(), ev_dims);
  ASSERT_NEAR(ev.scale_factor(), 1.602176634e-19, 1e-25);
}

// Temperature units
TEST(TestCommonUnits, TemperatureUnits) {
  // Kelvin (base unit)
  UnitSP          kelvin   = SPU(common_units::Kelvin);
  TotalDimensions temp_dim = {{SI::DIMENSION_TEMPERATURE, 1}};
  ASSERT_EQ(kelvin->dimensions(), temp_dim);
  ASSERT_DOUBLE_EQ(kelvin->scale_factor(), 1.0);
  ASSERT_DOUBLE_EQ(kelvin->offset(), 0.0);

  // Celsius
  UnitSP celsius = SPU(common_units::Celsius);
  ASSERT_EQ(celsius->dimensions(), temp_dim);
  ASSERT_DOUBLE_EQ(celsius->scale_factor(), 1.0);
  ASSERT_DOUBLE_EQ(celsius->offset(), 273.15);

  // Fahrenheit
  UnitSP fahrenheit = SPU(common_units::Fahrenheit);
  ASSERT_EQ(fahrenheit->dimensions(), temp_dim);
  ASSERT_NEAR(fahrenheit->scale_factor(), 5.0 / 9.0, 1e-10);
  ASSERT_NEAR(fahrenheit->offset(), 459.67, 1e-10);

  // Temperature conversion validation
  // 0°C = 273.15K
  ASSERT_NEAR(celsius->convert_value_to(0.0, kelvin), 273.15, 1e-10);
  // 0K = -273.15°C
  ASSERT_NEAR(kelvin->convert_value_to(0.0, celsius), -273.15, 1e-10);
  // 32°F = 0°C
  ASSERT_NEAR(fahrenheit->convert_value_to(32.0, celsius), 0.0, 1e-10);
}

// Dimensionless units
TEST(TestCommonUnits, DimensionlessUnits) {
  UnitSP          dimensionless = SPU(common_units::Dimensionless);
  TotalDimensions empty_dims;
  ASSERT_EQ(dimensionless->dimensions(), empty_dims);
  ASSERT_DOUBLE_EQ(dimensionless->scale_factor(), 1.0);

  UnitSP percent = SPU(common_units::Percent);
  ASSERT_EQ(percent->dimensions(), empty_dims);
  ASSERT_DOUBLE_EQ(percent->scale_factor(), 0.01);

  // 100% = 1.0 dimensionless
  ASSERT_DOUBLE_EQ(percent->convert_value_to(100.0, dimensionless), 1.0);
}

// Get unit with prefix
TEST(TestCommonUnits, GetUnitWithPrefix) {
  // General prefix method
  UnitSP millimeter =
      common_units::get_unit_with_prefix(common_units::Meter, SI::MILLI_SYMBOL);
  TotalDimensions len_dim = {{SI::DIMENSION_LENGTH, 1}};
  ASSERT_EQ(millimeter->dimensions(), len_dim);
  ASSERT_DOUBLE_EQ(millimeter->scale_factor(), 0.001);

  // Specific prefix methods
  UnitSP km = common_units::get_kilo(common_units::Meter);
  ASSERT_DOUBLE_EQ(km->scale_factor(), 1000.0);

  UnitSP uA = common_units::get_micro(common_units::Ampere);
  ASSERT_DOUBLE_EQ(uA->scale_factor(), 1e-6);

  UnitSP mV = common_units::get_milli(common_units::Volt);
  ASSERT_DOUBLE_EQ(mV->scale_factor(), 0.001);

  UnitSP MW = common_units::get_mega(common_units::Watt);
  ASSERT_DOUBLE_EQ(MW->scale_factor(), 1e6);
}

// Conversion between prefixed units
TEST(TestCommonUnits, ConversionBetweenPrefixedUnits) {
  // 1 km to m
  UnitSP km           = common_units::get_kilo(common_units::Meter);
  double meters_in_km = km->convert_value_to(1.0, SPU(common_units::Meter));
  ASSERT_DOUBLE_EQ(meters_in_km, 1000.0);

  // 1000 mV to V
  UnitSP mV          = common_units::get_milli(common_units::Volt);
  double volts_in_mV = mV->convert_value_to(1000.0, SPU(common_units::Volt));
  ASSERT_DOUBLE_EQ(volts_in_mV, 1.0);

  // 1 MW to kW
  UnitSP MW       = common_units::get_mega(common_units::Watt);
  UnitSP kW       = common_units::get_kilo(common_units::Watt);
  double kW_in_MW = MW->convert_value_to(1.0, kW);
  ASSERT_DOUBLE_EQ(kW_in_MW, 1000.0);
}
