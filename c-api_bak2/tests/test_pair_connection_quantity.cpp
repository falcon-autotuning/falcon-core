#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include "falcon_core/generic/PairConnectionQuantity_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class PairConnectionQuantityTest : public ::testing::Test {
 protected:
  void SetUp() override {
    t1    = Connection_create_plunger_gate(String_wrap("A"));
    t2    = Quantity_create(1.0, SymbolUnit_create_volt());
    pair1 = PairConnectionQuantity_create(t1, t2);
    pair2 = PairConnectionQuantity_create(t1, t2);
  }
  void TearDown() override {
    PairConnectionQuantity_destroy(pair1);
    PairConnectionQuantity_destroy(pair2);
    Connection_destroy(t1);
    Quantity_destroy(t2);
  }
  PairConnectionQuantityHandle pair1;
  PairConnectionQuantityHandle pair2;
  ConnectionHandle             t1;
  QuantityHandle               t2;
};

TEST_F(PairConnectionQuantityTest, CreateDestroy) {
  set_last_error(0, nullptr);
  PairConnectionQuantity_create(nullptr, t2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionQuantity_create(t1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionQuantity_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairConnectionQuantityTest, Accessors) {
  auto f = PairConnectionQuantity_first(pair1);
  auto s = PairConnectionQuantity_second(pair1);
  EXPECT_TRUE(Connection_equal(f, t1));
  EXPECT_TRUE(Quantity_equal(s, t2));
  set_last_error(0, nullptr);
  PairConnectionQuantity_first(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionQuantity_second(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairConnectionQuantityTest, Equality) {
  EXPECT_TRUE(PairConnectionQuantity_equal(pair1, pair2));
  EXPECT_FALSE(PairConnectionQuantity_not_equal(pair1, pair2));
  set_last_error(0, nullptr);
  PairConnectionQuantity_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionQuantity_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionQuantity_not_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionQuantity_not_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairConnectionQuantityTest, ToJsonFromJson) {
  auto json = PairConnectionQuantity_to_json_string(pair1);
  auto p2   = PairConnectionQuantity_from_json_string(json);
  EXPECT_TRUE(PairConnectionQuantity_equal(pair1, p2));
  PairConnectionQuantity_destroy(p2);
  set_last_error(0, nullptr);
  PairConnectionQuantity_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionQuantity_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
