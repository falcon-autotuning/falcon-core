#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class SymbolUnitTest : public ::testing::Test {
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

TEST_F(SymbolUnitTest, StaticConstructors) {
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

TEST_F(SymbolUnitTest, Properties) {
  EXPECT_STREQ(SymbolUnit_symbol(meter)->raw, "m");
  EXPECT_STRNE(SymbolUnit_name(meter)->raw, "");
}

TEST_F(SymbolUnitTest, OperatorMultiplyWorks) {
  SymbolUnitHandle result = SymbolUnit_multiplication(meter, second);
  EXPECT_TRUE(result != nullptr);
  EXPECT_NE(std::string(SymbolUnit_symbol(result)->raw).find("m·s"),
            std::string::npos);
  SymbolUnit_destroy(result);
}

TEST_F(SymbolUnitTest, OperatorDivideWorks) {
  SymbolUnitHandle result = SymbolUnit_division(meter, second);
  EXPECT_TRUE(result != nullptr);
  EXPECT_NE(std::string(SymbolUnit_symbol(result)->raw).find("m/s"),
            std::string::npos);
  SymbolUnit_destroy(result);
}

TEST_F(SymbolUnitTest, OperatorPowerWorks) {
  SymbolUnitHandle area = SymbolUnit_power(meter, 2);
  EXPECT_TRUE(area != nullptr);
  EXPECT_NE(std::string(SymbolUnit_symbol(area)->raw).find("m^2"),
            std::string::npos);
  SymbolUnit_destroy(area);
}

TEST_F(SymbolUnitTest, WithPrefixWorks) {
  SymbolUnitHandle km = SymbolUnit_with_prefix(meter, String_wrap("k"));
  EXPECT_TRUE(km != nullptr);
  EXPECT_NE(std::string(SymbolUnit_symbol(km)->raw).find("km"),
            std::string::npos);
  SymbolUnit_destroy(km);
}

TEST_F(SymbolUnitTest, WithPrefixInvalidThrows) {
  set_last_error(0, nullptr);
  SymbolUnit_with_prefix(meter, String_wrap("invalid"));
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(SymbolUnitTest, ConvertValueToWorks) {
  double val = SymbolUnit_convert_value_to(meter, 1.0, millimeter);
  EXPECT_NEAR(val, 1000.0, 1e-9);
}

TEST_F(SymbolUnitTest, ConvertValueToNullptrThrows) {
  set_last_error(0, nullptr);
  SymbolUnit_convert_value_to(meter, 1.0, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(SymbolUnitTest, ConvertValueToIncompatibleThrows) {
  set_last_error(0, nullptr);
  SymbolUnit_convert_value_to(meter, 1.0, second);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(SymbolUnitTest, IsCompatibleWithWorks) {
  EXPECT_TRUE(SymbolUnit_is_compatible_with(meter, millimeter));
  EXPECT_FALSE(SymbolUnit_is_compatible_with(meter, second));
}

TEST_F(SymbolUnitTest, IsCompatibleWithNullptrThrows) {
  set_last_error(0, nullptr);
  SymbolUnit_is_compatible_with(meter, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(SymbolUnitTest, SerializationRoundTrip) {
  StringHandle     json = SymbolUnit_to_json_string(meter);
  SymbolUnitHandle m2   = SymbolUnit_from_json_string(json);
  EXPECT_TRUE(SymbolUnit_equal(meter, m2));
  SymbolUnit_destroy(m2);
}

TEST_F(SymbolUnitTest, DestructorThrowsOnNullptr) {
  set_last_error(0, nullptr);
  SymbolUnit_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(SymbolUnitTest, EqualityAndInequality) {
  SymbolUnitHandle m1 = SymbolUnit_create_meter();
  SymbolUnitHandle m2 = SymbolUnit_create_meter();
  SymbolUnitHandle s  = SymbolUnit_create_second();
  EXPECT_TRUE(SymbolUnit_equal(m1, m2));
  EXPECT_TRUE(SymbolUnit_not_equal(m1, s));
  SymbolUnit_destroy(m1);
  SymbolUnit_destroy(m2);
  SymbolUnit_destroy(s);
}

TEST_F(SymbolUnitTest, StaticConstructorsNotNull) {
  SymbolUnitHandle units[] = {SymbolUnit_create_meter(),
                              SymbolUnit_create_kilogram(),
                              SymbolUnit_create_second(),
                              SymbolUnit_create_ampere(),
                              SymbolUnit_create_kelvin(),
                              SymbolUnit_create_mole(),
                              SymbolUnit_create_candela(),
                              SymbolUnit_create_hertz(),
                              SymbolUnit_create_newton(),
                              SymbolUnit_create_pascal(),
                              SymbolUnit_create_joule(),
                              SymbolUnit_create_watt(),
                              SymbolUnit_create_coulomb(),
                              SymbolUnit_create_volt(),
                              SymbolUnit_create_farad(),
                              SymbolUnit_create_ohm(),
                              SymbolUnit_create_siemens(),
                              SymbolUnit_create_weber(),
                              SymbolUnit_create_tesla(),
                              SymbolUnit_create_henry(),
                              SymbolUnit_create_minute(),
                              SymbolUnit_create_hour(),
                              SymbolUnit_create_electronvolt(),
                              SymbolUnit_create_celsius(),
                              SymbolUnit_create_fahrenheit(),
                              SymbolUnit_create_dimensionless(),
                              SymbolUnit_create_percent(),
                              SymbolUnit_create_radian(),
                              SymbolUnit_create_kilometer(),
                              SymbolUnit_create_millimeter(),
                              SymbolUnit_create_millivolt(),
                              SymbolUnit_create_kilovolt(),
                              SymbolUnit_create_milliampere(),
                              SymbolUnit_create_microampere(),
                              SymbolUnit_create_nanoampere(),
                              SymbolUnit_create_picoampere(),
                              SymbolUnit_create_millisecond(),
                              SymbolUnit_create_microsecond(),
                              SymbolUnit_create_nanosecond(),
                              SymbolUnit_create_picosecond(),
                              SymbolUnit_create_milliohm(),
                              SymbolUnit_create_kiloohm(),
                              SymbolUnit_create_megaohm(),
                              SymbolUnit_create_millihertz(),
                              SymbolUnit_create_kilohertz(),
                              SymbolUnit_create_megahertz(),
                              SymbolUnit_create_gigahertz(),
                              SymbolUnit_create_meters_per_second(),
                              SymbolUnit_create_meters_per_second_squared(),
                              SymbolUnit_create_newton_meter(),
                              SymbolUnit_create_newtons_per_meter(),
                              SymbolUnit_create_volts_per_meter(),
                              SymbolUnit_create_volts_per_second(),
                              SymbolUnit_create_amperes_per_meter(),
                              SymbolUnit_create_volts_per_ampere(),
                              SymbolUnit_create_watts_per_meter_kelvin()};

  for (auto unit : units) {
    EXPECT_TRUE(unit != nullptr);
    SymbolUnit_destroy(unit);
  }
}

TEST_F(SymbolUnitTest, NullHandlesThrow) {
  set_last_error(0, nullptr);
  SymbolUnit_equal(nullptr, meter);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  SymbolUnit_equal(meter, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  SymbolUnit_not_equal(nullptr, meter);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  SymbolUnit_not_equal(meter, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  SymbolUnit_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  SymbolUnit_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  SymbolUnit_symbol(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  SymbolUnit_name(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  SymbolUnit_multiplication(nullptr, meter);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  SymbolUnit_multiplication(meter, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  SymbolUnit_division(nullptr, meter);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  SymbolUnit_division(meter, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  SymbolUnit_power(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  SymbolUnit_with_prefix(nullptr, String_wrap("k"));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  SymbolUnit_with_prefix(meter, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  SymbolUnit_convert_value_to(nullptr, 1.0, meter);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  SymbolUnit_convert_value_to(meter, 1.0, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  SymbolUnit_is_compatible_with(nullptr, meter);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  SymbolUnit_is_compatible_with(meter, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
