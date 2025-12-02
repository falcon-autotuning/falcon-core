#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/generic/PairConnectionFloat_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"

class PairConnectionFloatTest : public ::testing::Test {
 protected:
  void SetUp() override {
    ConnectionHandle arr1[2] = {
        Connection_create_plunger_gate(String_wrap("gate1")),
        Connection_create_plunger_gate(String_wrap("gate2"))};
    ListConnectionHandle lch1 = ListConnection_create(arr1, 2);
    t1    = Connection_create_plunger_gate(String_wrap("A"));
    t2    = 1.0;
    pair1 = PairConnectionFloat_create(t1, t2);
    pair2 = PairConnectionFloat_create(t1, t2);
  }
  void TearDown() override {
    PairConnectionFloat_destroy(pair1);
    PairConnectionFloat_destroy(pair2);
    Connection_destroy(t1);
  }
  PairConnectionFloatHandle pair1;
  PairConnectionFloatHandle pair2;
  ConnectionHandle          t1;
  float                     t2;
};

TEST_F(PairConnectionFloatTest, CreateDestroy) {
  set_last_error(0, nullptr);
  PairConnectionFloat_create(nullptr, t2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionFloat_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairConnectionFloatTest, Accessors) {
  auto f = PairConnectionFloat_first(pair1);
  auto s = PairConnectionFloat_second(pair1);
  EXPECT_TRUE(Connection_equal(f, t1));
  EXPECT_TRUE(s == t2);
  set_last_error(0, nullptr);
  PairConnectionFloat_first(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionFloat_second(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairConnectionFloatTest, Equality) {
  EXPECT_TRUE(PairConnectionFloat_equal(pair1, pair2));
  EXPECT_FALSE(PairConnectionFloat_not_equal(pair1, pair2));
  set_last_error(0, nullptr);
  PairConnectionFloat_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionFloat_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionFloat_not_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionFloat_not_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairConnectionFloatTest, ToJsonFromJson) {
  auto json = PairConnectionFloat_to_json_string(pair1);
  auto p2   = PairConnectionFloat_from_json_string(json);
  EXPECT_TRUE(PairConnectionFloat_equal(pair1, p2));
  PairConnectionFloat_destroy(p2);
  set_last_error(0, nullptr);
  PairConnectionFloat_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionFloat_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
