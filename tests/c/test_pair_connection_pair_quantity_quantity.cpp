#include <gtest/gtest.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"

#include "falcon-core/generic/PairConnectionPairQuantityQuantity_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/physics/device_structures/Connection_c_api.h"
#include "falcon-core/physics/units/SymbolUnit_c_api.h"

class PairConnectionPairQuantityQuantityTest : public ::testing::Test {
 protected:
  void SetUp() override {
    t1 = Connection_create_plunger_gate(String_wrap("A"));
    t2 = PairQuantityQuantity_create(
        Quantity_create(1.0, SymbolUnit_create_volt()),
        Quantity_create(2.0, SymbolUnit_create_ampere()));
    pair1 = PairConnectionPairQuantityQuantity_create(t1, t2);
    pair2 = PairConnectionPairQuantityQuantity_create(t1, t2);
  }
  void TearDown() override {
    PairConnectionPairQuantityQuantity_destroy(pair1);
    PairConnectionPairQuantityQuantity_destroy(pair2);
    Connection_destroy(t1);
    PairQuantityQuantity_destroy(t2);
  }
  PairConnectionPairQuantityQuantityHandle pair1;
  PairConnectionPairQuantityQuantityHandle pair2;
  ConnectionHandle                         t1;
  PairQuantityQuantityHandle               t2;
};

TEST_F(PairConnectionPairQuantityQuantityTest, CreateDestroy) {
  set_last_error(0, nullptr);
  PairConnectionPairQuantityQuantity_create(nullptr, t2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionPairQuantityQuantity_create(t1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionPairQuantityQuantity_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairConnectionPairQuantityQuantityTest, Accessors) {
  auto f = PairConnectionPairQuantityQuantity_first(pair1);
  auto s = PairConnectionPairQuantityQuantity_second(pair1);
  EXPECT_TRUE(Connection_equal(f, t1));
  EXPECT_TRUE(PairQuantityQuantity_equal(s, t2));
  set_last_error(0, nullptr);
  PairConnectionPairQuantityQuantity_first(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionPairQuantityQuantity_second(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairConnectionPairQuantityQuantityTest, Equality) {
  EXPECT_TRUE(PairConnectionPairQuantityQuantity_equal(pair1, pair2));
  EXPECT_FALSE(PairConnectionPairQuantityQuantity_not_equal(pair1, pair2));
  set_last_error(0, nullptr);
  PairConnectionPairQuantityQuantity_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionPairQuantityQuantity_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionPairQuantityQuantity_not_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionPairQuantityQuantity_not_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairConnectionPairQuantityQuantityTest, ToJsonFromJson) {
  auto json = PairConnectionPairQuantityQuantity_to_json_string(pair1);
  auto p2   = PairConnectionPairQuantityQuantity_from_json_string(json);
  EXPECT_TRUE(PairConnectionPairQuantityQuantity_equal(pair1, p2));
  PairConnectionPairQuantityQuantity_destroy(p2);
  set_last_error(0, nullptr);
  PairConnectionPairQuantityQuantity_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionPairQuantityQuantity_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
