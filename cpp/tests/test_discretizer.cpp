#include <gtest/gtest.h>

#include <cereal/archives/binary.hpp>

#include "falcon_core/Constants.hpp"
#include "falcon_core/math/discrete_spaces/Discretizer.hpp"
#include "falcon_core/math/domains/Domain.hpp"
namespace {
using namespace falcon_core::math::discrete_spaces;
using namespace falcon_core::math::domains;

class DiscretizerTest : public ::testing::Test {
 protected:
  DomainSP domainA = std::make_shared<Domain>(-1.0, 1.0);
  DomainSP domainB = std::make_shared<Domain>(0.0, 2.0);
  double   deltaA  = 0.5;
  double   deltaB  = 1.0;
};

TEST_F(DiscretizerTest, ConstructorValid) {
  Discretizer d(deltaA, domainA, Dividers::Cartesian);
  EXPECT_EQ(d.delta(), deltaA);
  EXPECT_EQ(d.domain(), domainA);
  EXPECT_TRUE(d.is_cartesian());
  EXPECT_FALSE(d.is_polar());
}

TEST_F(DiscretizerTest, ConstructorNullDomainThrows) {
  EXPECT_THROW(
      { Discretizer d(deltaA, nullptr, Dividers::Cartesian); },
      std::invalid_argument);
}

TEST_F(DiscretizerTest, CartesianDiscretizerFactory) {
  auto d = Discretizer::CartesianDiscretizer(deltaA);
  ASSERT_NE(d, nullptr);
  EXPECT_TRUE(d->is_cartesian());
  EXPECT_FALSE(d->is_polar());
  EXPECT_EQ(d->delta(), deltaA);
  EXPECT_EQ(d->domain()->lesser_bound(), -1.0);
  EXPECT_EQ(d->domain()->greater_bound(), 1.0);
}

TEST_F(DiscretizerTest, PolarDiscretizerFactory) {
  auto d = Discretizer::PolarDiscretizer(deltaB);
  ASSERT_NE(d, nullptr);
  EXPECT_TRUE(d->is_polar());
  EXPECT_FALSE(d->is_cartesian());
  EXPECT_EQ(d->delta(), deltaB);
  EXPECT_DOUBLE_EQ(d->domain()->lesser_bound(), -2.0 * falcon_core::PI);
  EXPECT_DOUBLE_EQ(d->domain()->greater_bound(), 2.0 * falcon_core::PI);
}

TEST_F(DiscretizerTest, SetDelta) {
  Discretizer d(deltaA, domainA, Dividers::Cartesian);
  d.set_delta(deltaB);
  EXPECT_EQ(d.delta(), deltaB);
}

TEST_F(DiscretizerTest, DomainGetter) {
  Discretizer d(deltaA, domainB, Dividers::Polar);
  EXPECT_EQ(d.domain(), domainB);
}

TEST_F(DiscretizerTest, IsCartesianAndIsPolar) {
  Discretizer d1(deltaA, domainA, Dividers::Cartesian);
  Discretizer d2(deltaA, domainA, Dividers::Polar);
  EXPECT_TRUE(d1.is_cartesian());
  EXPECT_FALSE(d1.is_polar());
  EXPECT_FALSE(d2.is_cartesian());
  EXPECT_TRUE(d2.is_polar());
}

TEST_F(DiscretizerTest, EqualityOperators) {
  Discretizer d1(deltaA, domainA, Dividers::Cartesian);
  Discretizer d2(deltaA, domainA, Dividers::Cartesian);
  Discretizer d3(deltaB, domainA, Dividers::Cartesian);
  Discretizer d4(deltaA, domainB, Dividers::Cartesian);
  Discretizer d5(deltaA, domainA, Dividers::Polar);
  EXPECT_TRUE(d1 == d2);
  EXPECT_FALSE(d1 != d2);
  EXPECT_FALSE(d1 == d3);
  EXPECT_TRUE(d1 != d3);
  EXPECT_FALSE(d1 == d4);
  EXPECT_TRUE(d1 != d4);
  EXPECT_FALSE(d1 == d5);
  EXPECT_TRUE(d1 != d5);
}

TEST_F(DiscretizerTest, SerializationRoundTrip) {
  Discretizer d1(deltaA, domainA, Dividers::Cartesian);
  auto        string = d1.to_json_string();
  auto        d2     = Discretizer::from_json_string<Discretizer>(string);
  EXPECT_EQ(d1, *d2);
}

}  // namespace
