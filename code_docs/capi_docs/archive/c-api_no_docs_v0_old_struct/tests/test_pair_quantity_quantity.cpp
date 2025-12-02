#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include "falcon_core/generic/PairQuantityQuantity_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class PairQuantityQuantityTest : public ::testing::Test {
 protected:
  void SetUp() override {
    t1    = Quantity_create(2.0, SymbolUnit_create_ampere());
    t2    = Quantity_create(1.0, SymbolUnit_create_volt());
    pair1 = PairQuantityQuantity_create(t1, t2);
    pair2 = PairQuantityQuantity_create(t1, t2);
  }
  void TearDown() override {
    PairQuantityQuantity_destroy(pair1);
    PairQuantityQuantity_destroy(pair2);
    Quantity_destroy(t1);
    Quantity_destroy(t2);
  }
  PairQuantityQuantityHandle pair1;
  PairQuantityQuantityHandle pair2;
  QuantityHandle             t1;
  QuantityHandle             t2;
};

TEST_F(PairQuantityQuantityTest, CreateDestroy) {
  set_last_error(0, nullptr);
  PairQuantityQuantity_create(nullptr, t2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairQuantityQuantity_create(t1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairQuantityQuantity_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairQuantityQuantityTest, Accessors) {
  auto f = PairQuantityQuantity_first(pair1);
  auto s = PairQuantityQuantity_second(pair1);
  EXPECT_TRUE(Quantity_equal(f, t1));
  EXPECT_TRUE(Quantity_equal(s, t2));
  set_last_error(0, nullptr);
  PairQuantityQuantity_first(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairQuantityQuantity_second(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairQuantityQuantityTest, Equality) {
  EXPECT_TRUE(PairQuantityQuantity_equal(pair1, pair2));
  EXPECT_FALSE(PairQuantityQuantity_not_equal(pair1, pair2));
  set_last_error(0, nullptr);
  PairQuantityQuantity_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairQuantityQuantity_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairQuantityQuantity_not_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairQuantityQuantity_not_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairQuantityQuantityTest, ToJsonFromJson) {
  auto json = PairQuantityQuantity_to_json_string(pair1);
  auto p2   = PairQuantityQuantity_from_json_string(json);
  EXPECT_TRUE(PairQuantityQuantity_equal(pair1, p2));
  PairQuantityQuantity_destroy(p2);
  set_last_error(0, nullptr);
  PairQuantityQuantity_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairQuantityQuantity_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
