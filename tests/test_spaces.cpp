#include <gtest/gtest.h>
#include <memory>
#include <string>

#include "falcon_core/math/spaces/UnitSpace.hpp"
#include "falcon_core/math/spaces/CartesianSpace.hpp"
#include "falcon_core/math/spaces/Cartesian1DSpace.hpp"
#include "falcon_core/math/spaces/Cartesian2DSpace.hpp"
#include "falcon_core/math/spaces/RaySpace.hpp"
#include "falcon_core/math/domains/Domain.hpp"

using namespace falcon_core::math::spaces;
using namespace falcon_core::math::domains;

// UnitSpace basic functionality
TEST(SpacesTest, UnitSpaceBasicFunctionality) {
  auto domain = std::make_shared<Domain>(0.0, 1.0);
  std::vector<std::shared_ptr<falcon_core::math::discretizers::BaseDiscretizer>> axes;
  auto unit_space = std::make_shared<UnitSpace>(
      Axes<falcon_core::math::discretizers::BaseDiscretizer>(axes), domain);

  EXPECT_EQ(unit_space->axes().size(), 0);
  EXPECT_DOUBLE_EQ(unit_space->domain()->min(), 0.0);
  EXPECT_DOUBLE_EQ(unit_space->domain()->max(), 1.0);
}

// UnitSpace serialization
TEST(SpacesTest, UnitSpaceSerializationRoundTrip) {
  auto domain = std::make_shared<Domain>(0.0, 1.0);
  std::vector<std::shared_ptr<falcon_core::math::discretizers::BaseDiscretizer>> axes;
  auto unit_space = std::make_shared<UnitSpace>(
      Axes<falcon_core::math::discretizers::BaseDiscretizer>(axes), domain);

  std::string json = unit_space->to_json_string();
  auto unit_space2 = UnitSpace::from_json_string<UnitSpace>(json);

  ASSERT_NE(unit_space2, nullptr);
  EXPECT_EQ(unit_space2->axes().size(), 0);
  EXPECT_DOUBLE_EQ(unit_space2->domain()->min(), 0.0);
  EXPECT_DOUBLE_EQ(unit_space2->domain()->max(), 1.0);
}

// CartesianSpace basic functionality
TEST(SpacesTest, CartesianSpaceBasicFunctionality) {
  auto domain = std::make_shared<Domain>(-1.0, 1.0);
  std::vector<double> deltas{0.1, 0.2, 0.3};
  auto cart_space = std::make_shared<CartesianSpace>(deltas, domain);

  EXPECT_EQ(cart_space->axes().size(), 3);
  EXPECT_DOUBLE_EQ(cart_space->domain()->min(), -1.0);
  EXPECT_DOUBLE_EQ(cart_space->domain()->max(), 1.0);
}

// CartesianSpace serialization
TEST(SpacesTest, CartesianSpaceSerializationRoundTrip) {
  auto domain = std::make_shared<Domain>(-1.0, 1.0);
  std::vector<double> deltas{0.1, 0.2, 0.3};
  auto cart_space = std::make_shared<CartesianSpace>(deltas, domain);

  std::string json = cart_space->to_json_string();
  auto cart_space2 = CartesianSpace::from_json_string<CartesianSpace>(json);

  ASSERT_NE(cart_space2, nullptr);
  EXPECT_EQ(cart_space2->axes().size(), 3);
  EXPECT_DOUBLE_EQ(cart_space2->domain()->min(), -1.0);
  EXPECT_DOUBLE_EQ(cart_space2->domain()->max(), 1.0);
}

// Cartesian1DSpace basic functionality
TEST(SpacesTest, Cartesian1DSpaceBasicFunctionality) {
  auto domain = std::make_shared<Domain>(0.0, 2.0);
  auto space = std::make_shared<Cartesian1DSpace>(0.5, domain);

  EXPECT_EQ(space->axes().size(), 1);
  EXPECT_DOUBLE_EQ(space->domain()->min(), 0.0);
  EXPECT_DOUBLE_EQ(space->domain()->max(), 2.0);
}

// Cartesian1DSpace serialization
TEST(SpacesTest, Cartesian1DSpaceSerializationRoundTrip) {
  auto domain = std::make_shared<Domain>(0.0, 2.0);
  auto space = std::make_shared<Cartesian1DSpace>(0.5, domain);

  std::string json = space->to_json_string();
  auto space2 = Cartesian1DSpace::from_json_string<Cartesian1DSpace>(json);

  ASSERT_NE(space2, nullptr);
  EXPECT_EQ(space2->axes().size(), 1);
  EXPECT_DOUBLE_EQ(space2->domain()->min(), 0.0);
  EXPECT_DOUBLE_EQ(space2->domain()->max(), 2.0);
}

// Cartesian2DSpace basic functionality
TEST(SpacesTest, Cartesian2DSpaceBasicFunctionality) {
  auto domain = std::make_shared<Domain>(-2.0, 2.0);
  std::vector<double> deltas{0.1, 0.2};
  auto space = std::make_shared<Cartesian2DSpace>(deltas, domain);

  EXPECT_EQ(space->axes().size(), 2);
  EXPECT_DOUBLE_EQ(space->domain()->min(), -2.0);
  EXPECT_DOUBLE_EQ(space->domain()->max(), 2.0);
}

// Cartesian2DSpace serialization
TEST(SpacesTest, Cartesian2DSpaceSerializationRoundTrip) {
  auto domain = std::make_shared<Domain>(-2.0, 2.0);
  std::vector<double> deltas{0.1, 0.2};
  auto space = std::make_shared<Cartesian2DSpace>(deltas, domain);

  std::string json = space->to_json_string();
  auto space2 = Cartesian2DSpace::from_json_string<Cartesian2DSpace>(json);

  ASSERT_NE(space2, nullptr);
  EXPECT_EQ(space2->axes().size(), 2);
  EXPECT_DOUBLE_EQ(space2->domain()->min(), -2.0);
  EXPECT_DOUBLE_EQ(space2->domain()->max(), 2.0);
}

// RaySpace basic functionality
TEST(SpacesTest, RaySpaceBasicFunctionality) {
  auto domain = std::make_shared<Domain>(0.0, 1.0);
  auto space = std::make_shared<RaySpace>(0.1, 0.2, domain);

  EXPECT_EQ(space->axes().size(), 2);
  EXPECT_DOUBLE_EQ(space->domain()->min(), 0.0);
  EXPECT_DOUBLE_EQ(space->domain()->max(), 1.0);
}

// RaySpace serialization
TEST(SpacesTest, RaySpaceSerializationRoundTrip) {
  auto domain = std::make_shared<Domain>(0.0, 1.0);
  auto space = std::make_shared<RaySpace>(0.1, 0.2, domain);

  std::string json = space->to_json_string();
  auto space2 = RaySpace::from_json_string<RaySpace>(json);

  ASSERT_NE(space2, nullptr);
  EXPECT_EQ(space2->axes().size(), 2);
  EXPECT_DOUBLE_EQ(space2->domain()->min(), 0.0);
  EXPECT_DOUBLE_EQ(space2->domain()->max(), 1.0);
}
