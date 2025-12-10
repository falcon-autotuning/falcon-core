
#include <gtest/gtest.h>

#include <stdexcept>
#include <string>

#include "falcon_core/Constants.hpp"
#include "falcon_core/physics/units/Prefix.hpp"
namespace {
using namespace falcon_core::physics::units;

TEST(PrefixTest, GetSymbolWorks) {
  EXPECT_EQ(Prefix::get_symbol(falcon_core::SI::KILO_EXPONENT),
            falcon_core::SI::KILO_SYMBOL);
  EXPECT_EQ(Prefix::get_symbol(falcon_core::SI::UNIT_EXPONENT),
            falcon_core::SI::UNIT_SYMBOL);
  EXPECT_EQ(Prefix::get_symbol(falcon_core::SI::MILLI_EXPONENT),
            falcon_core::SI::MILLI_SYMBOL);
}

TEST(PrefixTest, GetSymbolThrowsOutOfRange) {
  int invalid_exp = 12345;
  try {
    Prefix::get_symbol(invalid_exp);
    FAIL() << "Expected std::out_of_range";
  } catch (const std::out_of_range& e) {
    std::string msg = e.what();
    EXPECT_NE(msg.find("Prefix value"), std::string::npos);
    EXPECT_NE(msg.find("not found in power_to_symbol mapping"),
              std::string::npos);
  }
}

TEST(PrefixTest, GetValueWorks) {
  EXPECT_EQ(Prefix::get_value(falcon_core::SI::KILO_SYMBOL),
            falcon_core::SI::KILO_EXPONENT);
  EXPECT_EQ(Prefix::get_value(falcon_core::SI::UNIT_SYMBOL),
            falcon_core::SI::UNIT_EXPONENT);
  EXPECT_EQ(
      Prefix::get_value(" " + std::string(falcon_core::SI::MILLI_SYMBOL) + " "),
      falcon_core::SI::MILLI_EXPONENT);  // test trim
}

TEST(PrefixTest, GetValueThrowsOutOfRange) {
  std::string invalid_symbol = "XX";
  try {
    Prefix::get_value(invalid_symbol);
    FAIL() << "Expected std::out_of_range";
  } catch (const std::out_of_range& e) {
    std::string msg = e.what();
    EXPECT_NE(msg.find("Symbol value"), std::string::npos);
    EXPECT_NE(msg.find("not found in symbol_to_power mapping"),
              std::string::npos);
  }
}

TEST(PrefixTest, IsValidWorks) {
  EXPECT_TRUE(Prefix::is_valid(falcon_core::SI::KILO_SYMBOL));
  EXPECT_TRUE(
      Prefix::is_valid(" " + std::string(falcon_core::SI::MILLI_SYMBOL) + " "));
  EXPECT_FALSE(Prefix::is_valid("XX"));
}

TEST(PrefixTest, PrefixMultiplicationWorks) {
  // kilo * milli = unit, scale 1.0
  auto result = Prefix::prefix_multiplication(
      falcon_core::SI::KILO_SYMBOL, falcon_core::SI::MILLI_SYMBOL, 1.0);
  EXPECT_NEAR(result.first, 1.0, 1e-12);
  EXPECT_EQ(result.second, falcon_core::SI::UNIT_SYMBOL);

  // kilo * kilo = mega, scale 1.0
  result = Prefix::prefix_multiplication(
      falcon_core::SI::KILO_SYMBOL, falcon_core::SI::KILO_SYMBOL, 1.0);
  EXPECT_NEAR(result.first, 1.0, 1e-12);
  EXPECT_EQ(result.second, falcon_core::SI::MEGA_SYMBOL);

  // kilo * milli, scale 1000.0
  result = Prefix::prefix_multiplication(
      falcon_core::SI::KILO_SYMBOL, falcon_core::SI::MILLI_SYMBOL, 1000.0);
  EXPECT_NEAR(result.first, 1.0, 1e-12);
  EXPECT_EQ(result.second, falcon_core::SI::KILO_SYMBOL);

  // scale_factor == 0
  result = Prefix::prefix_multiplication(
      falcon_core::SI::KILO_SYMBOL, falcon_core::SI::MILLI_SYMBOL, 0.0);
  EXPECT_EQ(result.first, 0.0);
  EXPECT_EQ(result.second, falcon_core::SI::UNIT_SYMBOL);
}

TEST(PrefixTest, PrefixMultiplicationThrowsOnInvalidPrefix) {
  // get_value will throw
  EXPECT_THROW(
      Prefix::prefix_multiplication("XX", falcon_core::SI::KILO_SYMBOL, 1.0),
      std::out_of_range);
  EXPECT_THROW(
      Prefix::prefix_multiplication(falcon_core::SI::KILO_SYMBOL, "YY", 1.0),
      std::out_of_range);
}
}  // namespace
