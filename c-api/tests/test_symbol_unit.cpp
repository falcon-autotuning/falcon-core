#include <gtest/gtest.h>

#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class SymbolUnitCAPI_Fixture : public ::testing::Test {
 protected:
  SymbolUnitHandle meter, second, volt, kilometer, millimeter, dimensionless,
      percent, celsius, fahrenheit, joule, ohm;
  void SetUp() override {
    meter         = SymbolUnit_create_meter();
    second        = SymbolUnit_create_second();
    volt          = SymbolUnit_create_volt();
    kilometer     = SymbolUnit_create_kilometer();
    millimeter    = SymbolUnit_create_millimeter();
    dimensionless = SymbolUnit_create_dimensionless();
    percent       = SymbolUnit_create_percent();
    celsius       = SymbolUnit_create_celsius();
    fahrenheit    = SymbolUnit_create_fahrenheit();
    joule         = SymbolUnit_create_joule();
    ohm           = SymbolUnit_create_ohm();
  }
  void TearDown() override {
    SymbolUnit_destroy(meter);
    SymbolUnit_destroy(second);
    SymbolUnit_destroy(volt);
    SymbolUnit_destroy(kilometer);
    SymbolUnit_destroy(millimeter);
    SymbolUnit_destroy(dimensionless);
    SymbolUnit_destroy(percent);
    SymbolUnit_destroy(celsius);
    SymbolUnit_destroy(fahrenheit);
    SymbolUnit_destroy(joule);
    SymbolUnit_destroy(ohm);
  }
};

TEST_F(SymbolUnitCAPI_Fixture, StaticConstructors) {
  EXPECT_TRUE(meter != nullptr);
  EXPECT_TRUE(second != nullptr);
  EXPECT_TRUE(volt != nullptr);
  EXPECT_TRUE(kilometer != nullptr);
  EXPECT_TRUE(millimeter != nullptr);
  EXPECT_TRUE(dimensionless != nullptr);
  EXPECT_TRUE(percent != nullptr);
  EXPECT_TRUE(celsius != nullptr);
  EXPECT_TRUE(fahrenheit != nullptr);
  EXPECT_TRUE(joule != nullptr);
  EXPECT_TRUE(ohm != nullptr);
}

TEST_F(SymbolUnitCAPI_Fixture, Properties) {
  EXPECT_STREQ(SymbolUnit_symbol(meter)->raw, "m");
  EXPECT_STRNE(SymbolUnit_name(meter)->raw, "");
}

TEST_F(SymbolUnitCAPI_Fixture, OperatorMultiplyWorks) {
  SymbolUnitHandle result = SymbolUnit_multiplication(meter, second);
  EXPECT_TRUE(result != nullptr);
  EXPECT_NE(std::string(SymbolUnit_symbol(result)->raw).find("m·s"),
            std::string::npos);
  SymbolUnit_destroy(result);
}

TEST_F(SymbolUnitCAPI_Fixture, OperatorDivideWorks) {
  SymbolUnitHandle result = SymbolUnit_division(meter, second);
  EXPECT_TRUE(result != nullptr);
  EXPECT_NE(std::string(SymbolUnit_symbol(result)->raw).find("m/s"),
            std::string::npos);
  SymbolUnit_destroy(result);
}

TEST_F(SymbolUnitCAPI_Fixture, OperatorPowerWorks) {
  SymbolUnitHandle area = SymbolUnit_power(meter, 2);
  EXPECT_TRUE(area != nullptr);
  EXPECT_NE(std::string(SymbolUnit_symbol(area)->raw).find("m^2"),
            std::string::npos);
  SymbolUnit_destroy(area);
}

TEST_F(SymbolUnitCAPI_Fixture, WithPrefixWorks) {
  SymbolUnitHandle km = SymbolUnit_with_prefix(meter, String_wrap("k"));
  EXPECT_TRUE(km != nullptr);
  EXPECT_NE(std::string(SymbolUnit_symbol(km)->raw).find("km"),
            std::string::npos);
  SymbolUnit_destroy(km);
}

TEST_F(SymbolUnitCAPI_Fixture, WithPrefixInvalidThrows) {
  EXPECT_ANY_THROW(SymbolUnit_with_prefix(meter, String_wrap("invalid")));
}

TEST_F(SymbolUnitCAPI_Fixture, ConvertValueToWorks) {
  double val = SymbolUnit_convert_value_to(meter, 1.0, millimeter);
  EXPECT_NEAR(val, 1000.0, 1e-9);
}

TEST_F(SymbolUnitCAPI_Fixture, ConvertValueToNullptrThrows) {
  EXPECT_ANY_THROW(SymbolUnit_convert_value_to(meter, 1.0, nullptr));
}

TEST_F(SymbolUnitCAPI_Fixture, ConvertValueToIncompatibleThrows) {
  EXPECT_ANY_THROW(SymbolUnit_convert_value_to(meter, 1.0, second));
}

TEST_F(SymbolUnitCAPI_Fixture, IsCompatibleWithWorks) {
  EXPECT_TRUE(SymbolUnit_is_compatible_with(meter, millimeter));
  EXPECT_FALSE(SymbolUnit_is_compatible_with(meter, second));
}

TEST_F(SymbolUnitCAPI_Fixture, IsCompatibleWithNullptrThrows) {
  EXPECT_ANY_THROW(SymbolUnit_is_compatible_with(meter, nullptr));
}

TEST_F(SymbolUnitCAPI_Fixture, SerializationRoundTrip) {
  StringHandle     json = SymbolUnit_to_json_string(meter);
  SymbolUnitHandle m2   = SymbolUnit_from_json_string(json);
  EXPECT_TRUE(SymbolUnit_equal(meter, m2));
  SymbolUnit_destroy(m2);
}

TEST_F(SymbolUnitCAPI_Fixture, EqualityAndInequality) {
  SymbolUnitHandle m1 = SymbolUnit_create_meter();
  SymbolUnitHandle m2 = SymbolUnit_create_meter();
  SymbolUnitHandle s  = SymbolUnit_create_second();
  EXPECT_TRUE(SymbolUnit_equal(m1, m2));
  EXPECT_TRUE(SymbolUnit_not_equal(m1, s));
  SymbolUnit_destroy(m1);
  SymbolUnit_destroy(m2);
  SymbolUnit_destroy(s);
}

TEST_F(SymbolUnitCAPI_Fixture, AllStaticConstructors) {
  EXPECT_TRUE(SymbolUnit_create_meter() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_kilogram() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_second() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_ampere() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_kelvin() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_mole() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_candela() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_hertz() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_newton() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_pascal() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_joule() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_watt() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_coulomb() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_volt() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_farad() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_ohm() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_siemens() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_weber() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_tesla() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_henry() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_minute() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_hour() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_electronvolt() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_celsius() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_fahrenheit() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_dimensionless() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_percent() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_radian() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_kilometer() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_millimeter() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_millivolt() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_kilovolt() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_milliampere() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_microampere() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_nanoampere() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_picoampere() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_millisecond() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_microsecond() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_nanosecond() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_picosecond() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_milliohm() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_kiloohm() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_megaohm() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_millihertz() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_kilohertz() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_megahertz() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_gigahertz() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_meters_per_second() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_meters_per_second_squared() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_newton_meter() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_newtons_per_meter() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_volts_per_meter() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_volts_per_second() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_amperes_per_meter() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_volts_per_ampere() != nullptr);
  EXPECT_TRUE(SymbolUnit_create_watts_per_meter_kelvin() != nullptr);
}
