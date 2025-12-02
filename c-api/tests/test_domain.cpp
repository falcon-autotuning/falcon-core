#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

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
  set_last_error(0, nullptr);
  Domain_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DomainTest, BoundsAndContained) {
  EXPECT_DOUBLE_EQ(Domain_lesser_bound(dom1), 0.0);
  EXPECT_DOUBLE_EQ(Domain_greater_bound(dom1), 1.0);
  EXPECT_TRUE(Domain_lesser_bound_contained(dom1));
  EXPECT_FALSE(Domain_greater_bound_contained(dom1));
  set_last_error(0, nullptr);
  Domain_lesser_bound(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Domain_greater_bound(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Domain_lesser_bound_contained(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Domain_greater_bound_contained(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DomainTest, InRangeRangeCenter) {
  EXPECT_TRUE(Domain_in(dom1, 0.5));
  EXPECT_FALSE(Domain_in(dom1, 2.0));
  EXPECT_DOUBLE_EQ(Domain_range(dom1), 1.0);
  EXPECT_DOUBLE_EQ(Domain_center(dom1), 0.5);
  set_last_error(0, nullptr);
  Domain_in(nullptr, 0.5);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Domain_range(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Domain_center(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DomainTest, IntersectionUnion) {
  auto inter = Domain_intersection(dom1, dom2);
  auto uni   = Domain_union(dom1, dom2);
  Domain_destroy(inter);
  Domain_destroy(uni);
  set_last_error(0, nullptr);
  Domain_intersection(nullptr, dom2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Domain_intersection(dom1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Domain_union(nullptr, dom2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Domain_union(dom1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DomainTest, IsEmptyContainsDomain) {
  EXPECT_FALSE(Domain_is_empty(dom1));
  EXPECT_FALSE(Domain_contains_domain(dom2, dom1));
  set_last_error(0, nullptr);
  Domain_is_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Domain_contains_domain(nullptr, dom2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Domain_contains_domain(dom1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DomainTest, ShiftScaleTransform) {
  auto shifted = Domain_shift(dom1, 1.0);
  auto scaled  = Domain_scale(dom1, 2.0);
  EXPECT_DOUBLE_EQ(Domain_transform(dom1, dom2, 0.5),
                   Domain_transform(dom1, dom2, 0.5));
  Domain_destroy(shifted);
  Domain_destroy(scaled);
  set_last_error(0, nullptr);
  Domain_shift(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Domain_scale(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Domain_transform(nullptr, dom2, 0.5);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Domain_transform(dom1, nullptr, 0.5);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DomainTest, EqualNotEqual) {
  EXPECT_FALSE(Domain_equal(dom1, dom2));
  EXPECT_TRUE(Domain_not_equal(dom1, dom2));
  set_last_error(0, nullptr);
  Domain_equal(nullptr, dom2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Domain_equal(dom1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Domain_not_equal(nullptr, dom2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Domain_not_equal(dom1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DomainTest, ToJsonFromJson) {
  auto json = Domain_to_json_string(dom1);
  auto d2   = Domain_from_json_string(json);
  EXPECT_TRUE(Domain_equal(dom1, d2));
  Domain_destroy(d2);
  String_destroy(json);
  set_last_error(0, nullptr);
  Domain_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Domain_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
