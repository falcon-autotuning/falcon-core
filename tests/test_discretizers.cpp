#include <gtest/gtest.h>

#include "falcon_core/Constants.hpp"
#include "falcon_core/math/discrete_spaces/Discretizer.hpp"
namespace tests {
using namespace falcon_core::math::discrete_spaces;
using namespace falcon_core::math::domains;

// Test Discretizer basic functionality
TEST(DiscretizerTest, DiscretizerBasicFunctionality) {
  auto        domain = std::make_shared<Domain>(-1.0, 1.0);
  Discretizer d(0.5, domain, Dividers::Cartesian);

  EXPECT_DOUBLE_EQ(d.delta(), 0.5);
  EXPECT_DOUBLE_EQ(d.domain()->lesser_bound(), -1.0);
  EXPECT_DOUBLE_EQ(d.domain()->greater_bound(), 1.0);

  d.set_delta(0.25);
  EXPECT_DOUBLE_EQ(d.delta(), 0.25);
}

// Test Discretizer serialization
TEST(DiscretizerTest, DiscretizerSerializationRoundTrip) {
  auto d = Discretizer::CartesianDiscretizer(0.5);

  std::string json = d->to_json_string();
  auto        d2   = Discretizer::from_json_string<Discretizer>(json);

  ASSERT_NE(d2, nullptr);
  EXPECT_DOUBLE_EQ(d2->delta(), 0.5);
  EXPECT_DOUBLE_EQ(d2->domain()->lesser_bound(), -1.0);
  EXPECT_DOUBLE_EQ(d2->domain()->greater_bound(), 1.0);
}

// Test CartesianDiscretizer basic functionality
TEST(DiscretizerTest, CartesianDiscretizerBasicFunctionality) {
  DiscretizerSP d = Discretizer::CartesianDiscretizer(0.1);
  EXPECT_DOUBLE_EQ(d->delta(), 0.1);
  EXPECT_DOUBLE_EQ(d->domain()->lesser_bound(), -1.0);
  EXPECT_DOUBLE_EQ(d->domain()->greater_bound(), 1.0);
}

// Test CartesianDiscretizer serialization
TEST(DiscretizerTest, CartesianDiscretizerSerializationRoundTrip) {
  auto d = Discretizer::CartesianDiscretizer(0.1);

  std::string json = d->to_json_string();
  auto        d2   = Discretizer::from_json_string<Discretizer>(json);

  ASSERT_NE(d2, nullptr);
  EXPECT_DOUBLE_EQ(d2->delta(), 0.1);
  EXPECT_DOUBLE_EQ(d2->domain()->lesser_bound(), -1.0);
  EXPECT_DOUBLE_EQ(d2->domain()->greater_bound(), 1.0);
}

// Test PolarDiscretizer basic functionality
TEST(DiscretizerTest, PolarDiscretizerBasicFunctionality) {
  DiscretizerSP d = Discretizer::PolarDiscretizer(0.2);
  EXPECT_DOUBLE_EQ(d->delta(), 0.2);
  EXPECT_DOUBLE_EQ(d->domain()->lesser_bound(), -2.0 * falcon_core::PI);
  EXPECT_DOUBLE_EQ(d->domain()->greater_bound(), 2.0 * falcon_core::PI);
}

}  // namespace tests
