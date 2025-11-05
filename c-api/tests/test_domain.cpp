#include <gtest/gtest.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/domains/Domain_c_api.h"

class DomainTest : public ::testing::Test {
 protected:
  void SetUp() override {
    dom1 = Domain_create(0.0, 1.0, true, false);
    dom2 = Domain_create(0.5, 2.0, false, true);
  }
  void TearDown() override {
    Domain_destroy(dom1);
    Domain_destroy(dom2);
  }
  DomainHandle dom1;
  DomainHandle dom2;
};

TEST_F(DomainTest, CreateDestroy) {
  auto d = Domain_create(-1.0, 1.0, true, true);
  Domain_destroy(d);
  EXPECT_THROW(Domain_destroy(nullptr), std::invalid_argument);
}

TEST_F(DomainTest, BoundsAndContained) {
  EXPECT_DOUBLE_EQ(Domain_lesser_bound(dom1), 0.0);
  EXPECT_DOUBLE_EQ(Domain_greater_bound(dom1), 1.0);
  EXPECT_TRUE(Domain_lesser_bound_contained(dom1));
  EXPECT_FALSE(Domain_greater_bound_contained(dom1));
  EXPECT_THROW(Domain_lesser_bound(nullptr), std::invalid_argument);
  EXPECT_THROW(Domain_greater_bound(nullptr), std::invalid_argument);
  EXPECT_THROW(Domain_lesser_bound_contained(nullptr), std::invalid_argument);
  EXPECT_THROW(Domain_greater_bound_contained(nullptr), std::invalid_argument);
}

TEST_F(DomainTest, InRangeRangeCenter) {
  EXPECT_TRUE(Domain_in(dom1, 0.5));
  EXPECT_FALSE(Domain_in(dom1, 2.0));
  EXPECT_DOUBLE_EQ(Domain_range(dom1), 1.0);
  EXPECT_DOUBLE_EQ(Domain_center(dom1), 0.5);
  EXPECT_THROW(Domain_in(nullptr, 0.5), std::invalid_argument);
  EXPECT_THROW(Domain_range(nullptr), std::invalid_argument);
  EXPECT_THROW(Domain_center(nullptr), std::invalid_argument);
}

TEST_F(DomainTest, IntersectionUnion) {
  auto inter = Domain_intersection(dom1, dom2);
  auto uni   = Domain_union(dom1, dom2);
  Domain_destroy(inter);
  Domain_destroy(uni);
  EXPECT_THROW(Domain_intersection(nullptr, dom2), std::invalid_argument);
  EXPECT_THROW(Domain_intersection(dom1, nullptr), std::invalid_argument);
  EXPECT_THROW(Domain_union(nullptr, dom2), std::invalid_argument);
  EXPECT_THROW(Domain_union(dom1, nullptr), std::invalid_argument);
}

TEST_F(DomainTest, IsEmptyContainsDomain) {
  EXPECT_FALSE(Domain_is_empty(dom1));
  EXPECT_FALSE(Domain_contains_domain(dom2, dom1));
  EXPECT_THROW(Domain_is_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(Domain_contains_domain(nullptr, dom2), std::invalid_argument);
  EXPECT_THROW(Domain_contains_domain(dom1, nullptr), std::invalid_argument);
}

TEST_F(DomainTest, ShiftScaleTransform) {
  auto shifted = Domain_shift(dom1, 1.0);
  auto scaled  = Domain_scale(dom1, 2.0);
  EXPECT_DOUBLE_EQ(Domain_transform(dom1, dom2, 0.5),
                   Domain_transform(dom1, dom2, 0.5));
  Domain_destroy(shifted);
  Domain_destroy(scaled);
  EXPECT_THROW(Domain_shift(nullptr, 1.0), std::invalid_argument);
  EXPECT_THROW(Domain_scale(nullptr, 2.0), std::invalid_argument);
  EXPECT_THROW(Domain_transform(nullptr, dom2, 0.5), std::invalid_argument);
  EXPECT_THROW(Domain_transform(dom1, nullptr, 0.5), std::invalid_argument);
}

TEST_F(DomainTest, EqualNotEqual) {
  EXPECT_FALSE(Domain_equal(dom1, dom2));
  EXPECT_TRUE(Domain_not_equal(dom1, dom2));
  EXPECT_THROW(Domain_equal(nullptr, dom2), std::invalid_argument);
  EXPECT_THROW(Domain_equal(dom1, nullptr), std::invalid_argument);
  EXPECT_THROW(Domain_not_equal(nullptr, dom2), std::invalid_argument);
  EXPECT_THROW(Domain_not_equal(dom1, nullptr), std::invalid_argument);
}

TEST_F(DomainTest, ToJsonFromJson) {
  auto json = Domain_to_json_string(dom1);
  auto d2   = Domain_from_json_string(json);
  EXPECT_TRUE(Domain_equal(dom1, d2));
  Domain_destroy(d2);
  String_destroy(json);
  EXPECT_THROW(Domain_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(Domain_from_json_string(nullptr), std::invalid_argument);
}
