#include <gtest/gtest.h>

#include "falcon_core/Constants.hpp"
#include "falcon_core/physics/units/CommonUnits.hpp"
#include "falcon_core/physics/units/TotalDimensions.hpp"
#include "falcon_core/physics/units/Unit.hpp"
using namespace falcon_core;
using namespace falcon_core::physics::units;
/**
 * @brief test that the base SI units are correctly defined.
 */
TEST(TestCommonUnits, BaseUnits) {
  UnitSP          meter = CommonUnits::Meter;
  TotalDimensions mdims = {{SI::DIMENSION_LENGTH, 1}};
  ASSERT_EQ(meter->dimensions(), mdims);
  ASSERT_DOUBLE_EQ(meter->scale_factor(), 1.0);

  UnitSP          kilogram = CommonUnits::Kilogram;
  TotalDimensions k_dims   = {{SI::DIMENSION_MASS, 1}};
  ASSERT_EQ(kilogram->dimensions(), k_dims);

  UnitSP          ampere = CommonUnits::Ampere;
  TotalDimensions a_dims = {{SI::DIMENSION_CURRENT, 1}};
  ASSERT_EQ(ampere->dimensions(), a_dims);

  UnitSP          second = CommonUnits::Second;
  TotalDimensions s_dims = {{SI::DIMENSION_TIME, 1}};
  ASSERT_EQ(second->dimensions(), s_dims);
}

TEST(TestCommonUnits, DerivedUnits) {
  UnitSP          volt               = CommonUnits::Volt;
  TotalDimensions expected_volt_dims = {
      {SI::DIMENSION_MASS, 1},
      {SI::DIMENSION_LENGTH, 2},
      {SI::DIMENSION_TIME, -3},
      {SI::DIMENSION_CURRENT, -1},
  };
  ASSERT_EQ(volt->dimensions(), expected_volt_dims);

  UnitSP          newton               = CommonUnits::Newton;
  TotalDimensions expected_newton_dims = {
      {SI::DIMENSION_MASS, 1},
      {SI::DIMENSION_LENGTH, 1},
      {SI::DIMENSION_TIME, -2},
  };
  ASSERT_EQ(newton->dimensions(), expected_newton_dims);

  UnitSP          hertz               = CommonUnits::Hertz;
  TotalDimensions expected_hertz_dims = {
      {SI::DIMENSION_TIME, -1},
  };
  ASSERT_EQ(hertz->dimensions(), expected_hertz_dims);

  UnitSP          tesla               = CommonUnits::Tesla;
  TotalDimensions expected_tesla_dims = {
      {SI::DIMENSION_MASS, 1},
      {SI::DIMENSION_TIME, -2},
      {SI::DIMENSION_CURRENT, -1},
  };
  ASSERT_EQ(tesla->dimensions(), expected_tesla_dims);
}

TEST(TestCommonUnits, ConsistencyWithDefinitionJoule) {
  // Joule = Newton * Meter
  UnitSP joule        = CommonUnits::Joule;
  UnitSP newton_meter = *CommonUnits::Newton * CommonUnits::Meter;
  ASSERT_EQ(joule->dimensions(), newton_meter->dimensions());
}

TEST(TestCommonUnits, ConsistencyWithDefinitionWatt) {
  // Watt = Joule / Second
  UnitSP watt             = CommonUnits::Watt;
  UnitSP joule_per_second = *CommonUnits::Joule / CommonUnits::Second;
  ASSERT_EQ(watt->dimensions(), joule_per_second->dimensions());
}

TEST(TestCommonUnits, ConsistencyWithDefinitionVolt) {
  // Volt = Watt / Ampere
  UnitSP volt            = CommonUnits::Volt;
  UnitSP watt_per_ampere = *CommonUnits::Watt / (CommonUnits::Ampere);
  ASSERT_EQ(volt->dimensions(), watt_per_ampere->dimensions());
}

TEST(TestCommonUnits, ConsistencyWithDefinitionOhm) {
  // Ohm = Volt / Ampere
  UnitSP ohm             = CommonUnits::Ohm;
  UnitSP volt_per_ampere = *CommonUnits::Volt / (CommonUnits::Ampere);
  ASSERT_EQ(ohm->dimensions(), volt_per_ampere->dimensions());
}

// Non-SI units
TEST(TestCommonUnits, NonSIUnits) {
  // Minute
  UnitSP          minute   = CommonUnits::Minute;
  TotalDimensions time_dim = {{SI::DIMENSION_TIME, 1}};
  ASSERT_EQ(minute->dimensions(), time_dim);
  ASSERT_DOUBLE_EQ(minute->scale_factor(), 60.0);

  // Hour
  UnitSP hour = CommonUnits::Hour;
  ASSERT_EQ(hour->dimensions(), time_dim);
  ASSERT_DOUBLE_EQ(hour->scale_factor(), 3600.0);

  // Electron volt
  UnitSP          ev      = CommonUnits::ElectronVolt;
  TotalDimensions ev_dims = {
      {SI::DIMENSION_MASS, 1},
      {SI::DIMENSION_LENGTH, 2},
      {SI::DIMENSION_TIME, -2},
  };
  ASSERT_EQ(ev->dimensions(), ev_dims);
  ASSERT_NEAR(ev->scale_factor(), 1.602176634e-19, 1e-25);
}

// Temperature units
TEST(TestCommonUnits, TemperatureUnits) {
  // Kelvin (base unit)
  UnitSP          kelvin   = (CommonUnits::Kelvin);
  TotalDimensions temp_dim = {{SI::DIMENSION_TEMPERATURE, 1}};
  ASSERT_EQ(kelvin->dimensions(), temp_dim);
  ASSERT_DOUBLE_EQ(kelvin->scale_factor(), 1.0);
  ASSERT_DOUBLE_EQ(kelvin->offset(), 0.0);

  // Celsius
  UnitSP celsius = (CommonUnits::Celsius);
  ASSERT_EQ(celsius->dimensions(), temp_dim);
  ASSERT_DOUBLE_EQ(celsius->scale_factor(), 1.0);
  ASSERT_DOUBLE_EQ(celsius->offset(), 273.15);

  // Fahrenheit
  UnitSP fahrenheit = (CommonUnits::Fahrenheit);
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
  UnitSP          dimensionless = (CommonUnits::Dimensionless);
  TotalDimensions empty_dims;
  ASSERT_EQ(dimensionless->dimensions(), empty_dims);
  ASSERT_DOUBLE_EQ(dimensionless->scale_factor(), 1.0);

  UnitSP percent = (CommonUnits::Percent);
  ASSERT_EQ(percent->dimensions(), empty_dims);
  ASSERT_DOUBLE_EQ(percent->scale_factor(), 0.01);

  // 100% = 1.0 dimensionless
  ASSERT_DOUBLE_EQ(percent->convert_value_to(100.0, dimensionless), 1.0);
}

// Get unit with prefix
TEST(TestCommonUnits, GetUnitWithPrefix) {
  // General prefix method
  UnitSP millimeter =
      CommonUnits::get_unit_with_prefix(CommonUnits::Meter, SI::MILLI_SYMBOL);
  TotalDimensions len_dim = {{SI::DIMENSION_LENGTH, 1}};
  ASSERT_EQ(millimeter->dimensions(), len_dim);
  ASSERT_DOUBLE_EQ(millimeter->scale_factor(), 0.001);

  // Specific prefix methods
  UnitSP km = CommonUnits::get_kilo(CommonUnits::Meter);
  ASSERT_DOUBLE_EQ(km->scale_factor(), 1000.0);

  UnitSP uA = CommonUnits::get_micro(CommonUnits::Ampere);
  ASSERT_DOUBLE_EQ(uA->scale_factor(), 1e-6);

  UnitSP mV = CommonUnits::get_milli(CommonUnits::Volt);
  ASSERT_DOUBLE_EQ(mV->scale_factor(), 0.001);

  UnitSP MW = CommonUnits::get_mega(CommonUnits::Watt);
  ASSERT_DOUBLE_EQ(MW->scale_factor(), 1e6);
}

// Conversion between prefixed units
TEST(TestCommonUnits, ConversionBetweenPrefixedUnits) {
  // 1 km to m
  UnitSP km           = CommonUnits::get_kilo(CommonUnits::Meter);
  double meters_in_km = km->convert_value_to(1.0, (CommonUnits::Meter));
  ASSERT_DOUBLE_EQ(meters_in_km, 1000.0);

  // 1000 mV to V
  UnitSP mV          = CommonUnits::get_milli(CommonUnits::Volt);
  double volts_in_mV = mV->convert_value_to(1000.0, (CommonUnits::Volt));
  ASSERT_DOUBLE_EQ(volts_in_mV, 1.0);

  // 1 MW to kW
  UnitSP MW       = CommonUnits::get_mega(CommonUnits::Watt);
  UnitSP kW       = CommonUnits::get_kilo(CommonUnits::Watt);
  double kW_in_MW = MW->convert_value_to(1.0, kW);
  ASSERT_DOUBLE_EQ(kW_in_MW, 1000.0);
}
