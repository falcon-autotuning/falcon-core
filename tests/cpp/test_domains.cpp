#include <gtest/gtest.h>

#include "falcon-core/math/domains/Domain.hpp"

namespace {

using namespace falcon_core::math::domains;
TEST(DomainTest, BasicFunctionality) {
  Domain d(1.0, 5.0);
  EXPECT_DOUBLE_EQ(d.lesser_bound(), 1.0);
  EXPECT_DOUBLE_EQ(d.greater_bound(), 5.0);
  EXPECT_DOUBLE_EQ(d.range(), 4.0);
  EXPECT_TRUE(d.lesser_bound_contained());
  EXPECT_TRUE(d.greater_bound_contained());
  EXPECT_EQ(d.bounds(), std::make_pair(1.0, 5.0));
  EXPECT_DOUBLE_EQ(d.get_center(), 3.0);
  EXPECT_TRUE(d.in(1.0));
  EXPECT_TRUE(d.in(5.0));
  EXPECT_TRUE(d.in(3.0));
  EXPECT_FALSE(d.in(0.0));
  EXPECT_FALSE(d.in(6.0));
  EXPECT_FALSE(d.is_empty());
}

TEST(DomainTest, BoundContainmentFlags) {
  Domain d(1.0, 5.0, false, false);
  EXPECT_FALSE(d.lesser_bound_contained());
  EXPECT_FALSE(d.greater_bound_contained());
  EXPECT_FALSE(d.in(1.0));
  EXPECT_FALSE(d.in(5.0));
  EXPECT_TRUE(d.in(3.0));
}

TEST(DomainTest, InvalidConstruction) {
  EXPECT_THROW(Domain(5.0, 1.0), std::invalid_argument);
  EXPECT_NO_THROW(Domain(std::make_pair(5.0, 1.0)));
}

TEST(DomainTest, PairConstructor) {
  Domain d(std::make_pair(2.0, 4.0), false, true);
  EXPECT_DOUBLE_EQ(d.lesser_bound(), 2.0);
  EXPECT_DOUBLE_EQ(d.greater_bound(), 4.0);
  EXPECT_FALSE(d.lesser_bound_contained());
  EXPECT_TRUE(d.greater_bound_contained());
}

TEST(DomainTest, Intersection) {
  auto d1           = std::make_shared<Domain>(1.0, 5.0);
  auto d2           = std::make_shared<Domain>(3.0, 7.0);
  auto intersection = *d1 & d2;
  EXPECT_DOUBLE_EQ(intersection->lesser_bound(), 3.0);
  EXPECT_DOUBLE_EQ(intersection->greater_bound(), 5.0);

  auto d3 = std::make_shared<Domain>(6.0, 8.0);
  EXPECT_THROW(*d1 & d3, std::runtime_error);
}

TEST(DomainTest, IntersectionNullptr) {
  auto                    d1 = std::make_shared<Domain>(1.0, 5.0);
  std::shared_ptr<Domain> null_domain;
  EXPECT_THROW(*d1 & null_domain, std::invalid_argument);
}

TEST(DomainTest, Union) {
  auto d1  = std::make_shared<Domain>(1.0, 5.0);
  auto d2  = std::make_shared<Domain>(3.0, 7.0);
  auto uni = *d1 | d2;
  EXPECT_DOUBLE_EQ(uni->lesser_bound(), 1.0);
  EXPECT_DOUBLE_EQ(uni->greater_bound(), 7.0);

  auto d3 = std::make_shared<Domain>(8.0, 10.0);
  EXPECT_THROW(*d1 | d3, std::runtime_error);
}

TEST(DomainTest, UnionNullptr) {
  auto                    d1 = std::make_shared<Domain>(1.0, 5.0);
  std::shared_ptr<Domain> null_domain;
  EXPECT_THROW(*d1 | null_domain, std::invalid_argument);
}

TEST(DomainTest, ContainsDomain) {
  auto d1 = std::make_shared<Domain>(1.0, 10.0);
  auto d2 = std::make_shared<Domain>(3.0, 7.0);
  EXPECT_TRUE(d1->contains_domain(d2));
  EXPECT_FALSE(d2->contains_domain(d1));
}

TEST(DomainTest, ContainsDomainNullptr) {
  auto                    d1 = std::make_shared<Domain>(1.0, 10.0);
  std::shared_ptr<Domain> null_domain;
  EXPECT_THROW(d1->contains_domain(null_domain), std::invalid_argument);
}

TEST(DomainTest, Shift) {
  auto d       = std::make_shared<Domain>(1.0, 5.0);
  auto shifted = d->shift(2.0);
  EXPECT_DOUBLE_EQ(shifted->lesser_bound(), 3.0);
  EXPECT_DOUBLE_EQ(shifted->greater_bound(), 7.0);
}

TEST(DomainTest, Scale) {
  auto d      = std::make_shared<Domain>(2.0, 4.0);
  auto scaled = d->scale(2.0);
  EXPECT_DOUBLE_EQ(scaled->lesser_bound(), 1.0);
  EXPECT_DOUBLE_EQ(scaled->greater_bound(), 5.0);
}

TEST(DomainTest, CalculateTransform) {
  auto d1     = std::make_shared<Domain>(1.0, 5.0);
  auto d2     = std::make_shared<Domain>(2.0, 6.0);
  auto params = d1->calculate_transform(d2);
  EXPECT_DOUBLE_EQ(params.first, 1.0);   // scale
  EXPECT_DOUBLE_EQ(params.second, 1.0);  // offset
}

TEST(DomainTest, CalculateTransformNullptr) {
  auto                    d1 = std::make_shared<Domain>(1.0, 5.0);
  std::shared_ptr<Domain> null_domain;
  EXPECT_THROW(d1->calculate_transform(null_domain), std::invalid_argument);
}

TEST(DomainTest, Transform) {
  auto   d1  = std::make_shared<Domain>(1.0, 5.0);
  auto   d2  = std::make_shared<Domain>(2.0, 6.0);
  double val = d1->transform(d2, 3.0);
  EXPECT_DOUBLE_EQ(val, 4.0);
}

TEST(DomainTest, TransformNullptr) {
  auto                    d1 = std::make_shared<Domain>(1.0, 5.0);
  std::shared_ptr<Domain> null_domain;
  EXPECT_THROW(d1->transform(null_domain, 3.0), std::invalid_argument);
}

TEST(DomainTest, EmptyDomain) {
  Domain d(1.0, 1.0, false, false);
  EXPECT_TRUE(d.is_empty());
}

TEST(DomainTest, RoundTripSerialization) {
  Domain      d(1.0, 2.0, false, false);
  std::string serial = d.to_json_string();
  auto        loaded = Domain::from_json_string<Domain>(serial);
  EXPECT_EQ(d, *loaded);
}

TEST(DomainTest, Intersection_OnlyThisGreaterBoundNotContained) {
  auto d1 = std::make_shared<Domain>(1.0, 5.0, true, false);
  auto d2 = std::make_shared<Domain>(5.0, 10.0, true, true);
  EXPECT_THROW(*d1 & d2, std::runtime_error);
}

TEST(DomainTest, Intersection_OnlyOtherGreaterBoundNotContained) {
  auto d1 = std::make_shared<Domain>(1.0, 5.0, true, true);
  auto d2 = std::make_shared<Domain>(5.0, 10.0, true, false);
  EXPECT_NO_THROW(*d1 & d2);
}

TEST(DomainTest, Intersection_OnlyThisLesserBoundNotContained) {
  auto d1 = std::make_shared<Domain>(5.0, 10.0, false, true);
  auto d2 = std::make_shared<Domain>(1.0, 5.0, true, true);
  EXPECT_THROW(*d1 & d2, std::runtime_error);
}

TEST(DomainTest, Intersection_OnlyOtherLesserBoundNotContained) {
  auto d1 = std::make_shared<Domain>(5.0, 10.0, true, true);
  auto d2 = std::make_shared<Domain>(1.0, 5.0, false, true);
  EXPECT_NO_THROW(*d1 & d2);
}

TEST(DomainTest, IsEmpty_GreaterBoundNotContained) {
  Domain d(2.0, 2.0, true, false);
  EXPECT_TRUE(d.is_empty());
}

}  // namespace
