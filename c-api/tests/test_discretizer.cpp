#include <gtest/gtest.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/discrete_spaces/Discretizer_c_api.h"
#include "falcon_core/math/domains/Domain_c_api.h"

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
  EXPECT_THROW(Discretizer_destroy(nullptr), std::invalid_argument);
}

TEST_F(DiscretizerTest, DeltaSetDelta) {
  EXPECT_DOUBLE_EQ(Discretizer_delta(cart), 0.1);
  Discretizer_set_delta(cart, 0.5);
  EXPECT_DOUBLE_EQ(Discretizer_delta(cart), 0.5);
  EXPECT_THROW(Discretizer_delta(nullptr), std::invalid_argument);
  EXPECT_THROW(Discretizer_set_delta(nullptr, 0.5), std::invalid_argument);
}

TEST_F(DiscretizerTest, Domain) {
  auto dom = Discretizer_domain(cart);
  Domain_destroy(dom);
  EXPECT_THROW(Discretizer_domain(nullptr), std::invalid_argument);
}

TEST_F(DiscretizerTest, IsCartesianIsPolar) {
  EXPECT_TRUE(Discretizer_is_cartesian(cart));
  EXPECT_FALSE(Discretizer_is_cartesian(polar));
  EXPECT_TRUE(Discretizer_is_polar(polar));
  EXPECT_FALSE(Discretizer_is_polar(cart));
  EXPECT_THROW(Discretizer_is_cartesian(nullptr), std::invalid_argument);
  EXPECT_THROW(Discretizer_is_polar(nullptr), std::invalid_argument);
}

TEST_F(DiscretizerTest, Equality) {
  auto d2 = Discretizer_create_cartesian_discretizer(0.1);
  EXPECT_TRUE(Discretizer_equal(cart, d2));
  EXPECT_FALSE(Discretizer_not_equal(cart, d2));
  Discretizer_destroy(d2);
  EXPECT_THROW(Discretizer_equal(nullptr, cart), std::invalid_argument);
  EXPECT_THROW(Discretizer_equal(cart, nullptr), std::invalid_argument);
  EXPECT_THROW(Discretizer_not_equal(nullptr, cart), std::invalid_argument);
  EXPECT_THROW(Discretizer_not_equal(cart, nullptr), std::invalid_argument);
}

TEST_F(DiscretizerTest, ToJsonFromJson) {
  auto json = Discretizer_to_json_string(cart);
  auto d2   = Discretizer_from_json_string(json);
  EXPECT_TRUE(Discretizer_equal(cart, d2));
  Discretizer_destroy(d2);
  String_destroy(json);
  EXPECT_THROW(Discretizer_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(Discretizer_from_json_string(nullptr), std::invalid_argument);
}
