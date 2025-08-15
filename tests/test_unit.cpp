#include <gtest/gtest.h>

#include "falcon_core/Constants.hpp"
#include "falcon_core/physics/units/Unit.hpp"

using namespace falcon_core;
using namespace falcon_core::physics::units;

// Test fixture for Unit tests
class UnitTest : public ::testing::Test {
 protected:
  TotalDimensions dim_len_  = {{SI::DIMENSION_LENGTH, 1}};
  TotalDimensions dim_time_ = {{SI::DIMENSION_TIME, 1}};
};

TEST_F(UnitTest, ConstructionAndAccessors) {
  Unit meter(dim_len_, 1.0, 0.0, "");
  ASSERT_EQ(meter.dimensions(), dim_len_);
  ASSERT_DOUBLE_EQ(meter.scale_factor(), 1.0);
  ASSERT_DOUBLE_EQ(meter.offset(), 0.0);
  ASSERT_EQ(meter.prefix(), "");
}

TEST_F(UnitTest, Compatibility) {
  Unit meter(dim_len_);
  Unit second(dim_time_);
  Unit foot(dim_len_, 0.3048);

  ASSERT_TRUE(meter.is_compatible_with(foot));
  ASSERT_FALSE(meter.is_compatible_with(second));
}

TEST_F(UnitTest, Conversion) {
  Unit meter(dim_len_);
  Unit kilometer(dim_len_, 1000.0);
  Unit second(dim_time_);

  ASSERT_DOUBLE_EQ(meter.convert_value_to(1000, kilometer), 1.0);
  ASSERT_DOUBLE_EQ(kilometer.convert_value_to(1, meter), 1000.0);
  ASSERT_THROW(meter.convert_value_to(1, second), std::invalid_argument);
}

TEST_F(UnitTest, OffsetConversion) {
  Unit kelvin({{SI::DIMENSION_TEMPERATURE, 1}}, 1.0, 0.0);
  Unit celsius({{SI::DIMENSION_TEMPERATURE, 1}}, 1.0, CELSIUS_OFFSET);

  // 0 C is 273.15 K
  ASSERT_NEAR(celsius.convert_value_to(0, kelvin), 273.15, 1e-9);
  // 273.15 K is 0 C
  ASSERT_NEAR(kelvin.convert_value_to(273.15, celsius), 0.0, 1e-9);
}

TEST_F(UnitTest, WithPrefix) {
  Unit meter(dim_len_);
  auto kilometer = meter.with_prefix("k");

  ASSERT_DOUBLE_EQ(kilometer->scale_factor(), 1000.0);
  ASSERT_EQ(kilometer->prefix(), "k");
  ASSERT_TRUE(kilometer->is_compatible_with(meter));

  auto millimeter = meter.with_prefix("m");
  ASSERT_DOUBLE_EQ(millimeter->scale_factor(), 0.001);
  ASSERT_EQ(millimeter->prefix(), "m");

  ASSERT_THROW(meter.with_prefix("invalid_prefix"), std::invalid_argument);
}

TEST_F(UnitTest, Multiplication) {
  Unit meter(dim_len_);
  Unit second(dim_time_);

  auto meter_second = meter * second;
  auto expected_dims =
      TotalDimensions{{SI::DIMENSION_LENGTH, 1}, {SI::DIMENSION_TIME, 1}};
  ASSERT_EQ(meter_second->dimensions(), expected_dims);
  ASSERT_DOUBLE_EQ(meter_second->scale_factor(), 1.0);
}

TEST_F(UnitTest, Division) {
  Unit meter(dim_len_);
  Unit second(dim_time_);
  auto m_per_s = meter / second;

  auto expected_dims =
      TotalDimensions{{SI::DIMENSION_LENGTH, 1}, {SI::DIMENSION_TIME, -1}};
  ASSERT_EQ(m_per_s->dimensions(), expected_dims);
}

TEST_F(UnitTest, Power) {
  Unit meter(dim_len_);
  auto m2      = meter ^ 2;
  auto dims_m2 = m2->dimensions();
  ASSERT_EQ(dims_m2.size(), 1);
  ASSERT_EQ(dims_m2.at(SI::DIMENSION_LENGTH), 2);

  auto inv_m      = meter ^ -1;
  auto dims_inv_m = inv_m->dimensions();
  ASSERT_EQ(dims_inv_m.size(), 1);
  ASSERT_EQ(dims_inv_m.at(SI::DIMENSION_LENGTH), -1);

  auto m0 = meter ^ 0;
  ASSERT_TRUE(m0->dimensions().empty());
}
