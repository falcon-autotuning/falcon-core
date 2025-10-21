#include <gtest/gtest.h>

#include "falcon_core/math/UnitSpace.hpp"
#include "falcon_core/math/discrete_spaces/Discretizer.hpp"
#include "falcon_core/math/domains/Domain.hpp"
namespace {
using namespace falcon_core::math;
using namespace falcon_core::math::discrete_spaces;
using namespace falcon_core::math::domains;

class UnitSpaceTest : public ::testing::Test {
 protected:
  DomainSP            domain = std::make_shared<Domain>(0.0, 1.0);
  AxesSP<Discretizer> axes   = std::make_shared<Axes<Discretizer>>();
  void                SetUp() override {
    axes->push_back(Discretizer::CartesianDiscretizer(0.1));
    axes->push_back(Discretizer::CartesianDiscretizer(0.2));
  }
};

TEST_F(UnitSpaceTest, ConstructorValid) {
  UnitSpace us(axes, domain);
  EXPECT_EQ(us.dimension(), 2);
  EXPECT_EQ(us.domain(), domain);
  EXPECT_EQ(us.axes()->size(), 2u);
}

TEST_F(UnitSpaceTest, ConstructorNullAxesThrows) {
  EXPECT_THROW(UnitSpace(nullptr, domain), std::invalid_argument);
}

TEST_F(UnitSpaceTest, ConstructorNullDomainThrows) {
  EXPECT_THROW(UnitSpace(axes, nullptr), std::invalid_argument);
}

TEST_F(UnitSpaceTest, RaySpaceValid) {
  auto us = UnitSpace::RaySpace(0.1, 0.2, domain);
  EXPECT_EQ(us->dimension(), 2);
  EXPECT_EQ(us->domain(), domain);
}

TEST_F(UnitSpaceTest, RaySpaceNullDomainThrows) {
  EXPECT_THROW(UnitSpace::RaySpace(0.1, 0.2, nullptr), std::invalid_argument);
}

TEST_F(UnitSpaceTest, CartesianSpaceValid) {
  auto deltas = std::make_shared<Axes<double>>();
  deltas->push_back(0.1);
  deltas->push_back(0.2);
  auto us = UnitSpace::CartesianSpace(deltas, domain);
  EXPECT_EQ(us->dimension(), 2);
}

TEST_F(UnitSpaceTest, CartesianSpaceNullDeltasThrows) {
  EXPECT_THROW(UnitSpace::CartesianSpace(nullptr, domain),
               std::invalid_argument);
}

TEST_F(UnitSpaceTest, CartesianSpaceNullDomainThrows) {
  auto deltas = std::make_shared<Axes<double>>();
  deltas->push_back(0.1);
  EXPECT_THROW(UnitSpace::CartesianSpace(deltas, nullptr),
               std::invalid_argument);
}

TEST_F(UnitSpaceTest, Cartesian2DSpaceValid) {
  auto deltas = std::make_shared<Axes<double>>();
  deltas->push_back(0.1);
  deltas->push_back(0.2);
  auto us = UnitSpace::Cartesian2DSpace(deltas, domain);
  EXPECT_EQ(us->dimension(), 2);
}

TEST_F(UnitSpaceTest, Cartesian2DSpaceWrongSizeThrows) {
  auto deltas = std::make_shared<Axes<double>>();
  deltas->push_back(0.1);
  EXPECT_THROW(UnitSpace::Cartesian2DSpace(deltas, domain), std::runtime_error);
}

TEST_F(UnitSpaceTest, Cartesian2DSpaceNullDeltasThrows) {
  EXPECT_THROW(UnitSpace::Cartesian2DSpace(nullptr, domain),
               std::invalid_argument);
}

TEST_F(UnitSpaceTest, Cartesian2DSpaceNullDomainThrows) {
  auto deltas = std::make_shared<Axes<double>>();
  deltas->push_back(0.1);
  deltas->push_back(0.2);
  EXPECT_THROW(UnitSpace::Cartesian2DSpace(deltas, nullptr),
               std::invalid_argument);
}

TEST_F(UnitSpaceTest, Cartesian1DSpaceValid) {
  auto us = UnitSpace::Cartesian1DSpace(0.1, domain);
  EXPECT_EQ(us->dimension(), 1);
}

TEST_F(UnitSpaceTest, Cartesian1DSpaceNullDomainThrows) {
  EXPECT_THROW(UnitSpace::Cartesian1DSpace(0.1, nullptr),
               std::invalid_argument);
}

TEST_F(UnitSpaceTest, ShapeAndDimension) {
  UnitSpace us(axes, domain);
  auto      shape = us.shape();
  EXPECT_EQ(shape->size(), 2u);
  EXPECT_EQ(us.dimension(), 2);
}

TEST_F(UnitSpaceTest, CompileAndSpace) {
  UnitSpace us(axes, domain);
  us.compile();
  auto sp = us.space();
  ASSERT_TRUE(sp != nullptr);
}

TEST_F(UnitSpaceTest, CreateArrayNullAxesThrows) {
  UnitSpace us(axes, domain);
  EXPECT_THROW(us.create_array(nullptr), std::invalid_argument);
}

TEST_F(UnitSpaceTest, EqualityOperators) {
  UnitSpace us1(axes, domain);
  UnitSpace us2(axes, domain);
  EXPECT_TRUE(us1 == us2);
  EXPECT_FALSE(us1 != us2);
}

TEST_F(UnitSpaceTest, SerializationRoundTrip) {
  UnitSpace us1(axes, domain);
  auto      string = us1.to_json_string();
  auto      us2    = UnitSpace::from_json_string<UnitSpace>(string);
  EXPECT_EQ(us1, *us2);
}
}  // namespace
