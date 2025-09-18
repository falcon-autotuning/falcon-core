#include <gtest/gtest.h>

#include "falcon_core/Constants.hpp"
#include "falcon_core/math/discretizers/CartesianDiscretizer.hpp"
#include "falcon_core/math/discretizers/PolarDiscretizer.hpp"
namespace tests {
using namespace falcon_core::math::discretizers;
using namespace falcon_core::math::domains;

// Test BaseDiscretizer basic functionality
TEST(DiscretizerTest, BaseDiscretizerBasicFunctionality) {
  auto            domain = std::make_shared<Domain>(-1.0, 1.0);
  BaseDiscretizer d(0.5, domain);

  EXPECT_DOUBLE_EQ(d.delta(), 0.5);
  EXPECT_DOUBLE_EQ(d.domain()->lesser_bound(), -1.0);
  EXPECT_DOUBLE_EQ(d.domain()->greater_bound(), 1.0);

  d.set_delta(0.25);
  EXPECT_DOUBLE_EQ(d.delta(), 0.25);
}

// Test BaseDiscretizer serialization
TEST(DiscretizerTest, BaseDiscretizerSerializationRoundTrip) {
  auto domain = std::make_shared<Domain>(-1.0, 1.0);
  auto d      = std::make_shared<BaseDiscretizer>(0.5, domain);

  std::string json = d->to_json_string();
  auto        d2   = BaseDiscretizer::from_json_string<BaseDiscretizer>(json);

  ASSERT_NE(d2, nullptr);
  EXPECT_DOUBLE_EQ(d2->delta(), 0.5);
  EXPECT_DOUBLE_EQ(d2->domain()->lesser_bound(), -1.0);
  EXPECT_DOUBLE_EQ(d2->domain()->greater_bound(), 1.0);
}

// Test CartesianDiscretizer basic functionality
TEST(DiscretizerTest, CartesianDiscretizerBasicFunctionality) {
  CartesianDiscretizer d(0.1);
  EXPECT_DOUBLE_EQ(d.delta(), 0.1);
  EXPECT_DOUBLE_EQ(d.domain()->lesser_bound(), -1.0);
  EXPECT_DOUBLE_EQ(d.domain()->greater_bound(), 1.0);
}

// Test CartesianDiscretizer serialization
TEST(DiscretizerTest, CartesianDiscretizerSerializationRoundTrip) {
  auto d = std::make_shared<CartesianDiscretizer>(0.1);

  std::string json = d->to_json_string();
  auto d2 = CartesianDiscretizer::from_json_string<CartesianDiscretizer>(json);

  ASSERT_NE(d2, nullptr);
  EXPECT_DOUBLE_EQ(d2->delta(), 0.1);
  EXPECT_DOUBLE_EQ(d2->domain()->lesser_bound(), -1.0);
  EXPECT_DOUBLE_EQ(d2->domain()->greater_bound(), 1.0);
}

// Test PolarDiscretizer basic functionality
TEST(DiscretizerTest, PolarDiscretizerBasicFunctionality) {
  PolarDiscretizer d(0.2);
  EXPECT_DOUBLE_EQ(d.delta(), 0.2);
  EXPECT_DOUBLE_EQ(d.domain()->lesser_bound(), -2.0 * falcon_core::PI);
  EXPECT_DOUBLE_EQ(d.domain()->greater_bound(), 2.0 * falcon_core::PI);
}

// Test PolarDiscretizer serialization
TEST(DiscretizerTest, PolarDiscretizerSerializationRoundTrip) {
  auto d = std::make_shared<PolarDiscretizer>(0.2);

  std::string json = d->to_json_string();
  auto        d2   = PolarDiscretizer::from_json_string<PolarDiscretizer>(json);

  ASSERT_NE(d2, nullptr);
  EXPECT_DOUBLE_EQ(d2->delta(), 0.2);
  EXPECT_DOUBLE_EQ(d2->domain()->lesser_bound(), -2.0 * falcon_core::PI);
  EXPECT_DOUBLE_EQ(d2->domain()->greater_bound(), 2.0 * falcon_core::PI);
}
}  // namespace tests
