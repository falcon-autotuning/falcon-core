#include <gtest/gtest.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/ErrorHandling_c_api.h"

#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/math/discrete_spaces/Discretizer_c_api.h"
#include "falcon-core/math/domains/Domain_c_api.h"

class DiscretizerTest : public ::testing::Test {
 protected:
  void SetUp() override {
    cart  = Discretizer_create_cartesian_discretizer(0.1);
    polar = Discretizer_create_polar_discretizer(0.2);
  }
  void TearDown() override {
    Discretizer_destroy(cart);
    Discretizer_destroy(polar);
  }
  DiscretizerHandle cart  = nullptr;
  DiscretizerHandle polar = nullptr;
};

TEST_F(DiscretizerTest, CreateDestroy) {
  auto d = Discretizer_create_cartesian_discretizer(0.5);
  Discretizer_destroy(d);
  auto p = Discretizer_create_polar_discretizer(0.5);
  Discretizer_destroy(p);
  set_last_error(0, nullptr);
  Discretizer_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DiscretizerTest, DeltaSetDelta) {
  EXPECT_DOUBLE_EQ(Discretizer_delta(cart), 0.1);
  Discretizer_set_delta(cart, 0.5);
  EXPECT_DOUBLE_EQ(Discretizer_delta(cart), 0.5);
  set_last_error(0, nullptr);
  Discretizer_delta(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Discretizer_set_delta(nullptr, 0.5);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DiscretizerTest, Domain) {
  auto dom = Discretizer_domain(cart);
  Domain_destroy(dom);
  set_last_error(0, nullptr);
  Discretizer_domain(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DiscretizerTest, IsCartesianIsPolar) {
  EXPECT_TRUE(Discretizer_is_cartesian(cart));
  EXPECT_FALSE(Discretizer_is_cartesian(polar));
  EXPECT_TRUE(Discretizer_is_polar(polar));
  EXPECT_FALSE(Discretizer_is_polar(cart));
  set_last_error(0, nullptr);
  Discretizer_is_cartesian(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Discretizer_is_polar(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DiscretizerTest, Equality) {
  auto d2 = Discretizer_create_cartesian_discretizer(0.1);
  EXPECT_TRUE(Discretizer_equal(cart, d2));
  EXPECT_FALSE(Discretizer_not_equal(cart, d2));
  Discretizer_destroy(d2);
  set_last_error(0, nullptr);
  Discretizer_equal(nullptr, cart);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Discretizer_equal(cart, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Discretizer_not_equal(nullptr, cart);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Discretizer_not_equal(cart, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DiscretizerTest, ToJsonFromJson) {
  auto json = Discretizer_to_json_string(cart);
  auto d2   = Discretizer_from_json_string(json);
  EXPECT_TRUE(Discretizer_equal(cart, d2));
  Discretizer_destroy(d2);
  String_destroy(json);
  set_last_error(0, nullptr);
  Discretizer_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Discretizer_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
