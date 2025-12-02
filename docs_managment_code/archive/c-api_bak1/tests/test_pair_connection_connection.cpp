#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include "falcon_core/generic/PairConnectionConnection_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"

class PairConnectionConnectionTest : public ::testing::Test {
 protected:
  void SetUp() override {
    t1    = Connection_create_plunger_gate(String_wrap("A"));
    t2    = Connection_create_barrier_gate(String_wrap("B"));
    pair1 = PairConnectionConnection_create(t1, t2);
    pair2 = PairConnectionConnection_create(t1, t2);
  }
  void TearDown() override {
    PairConnectionConnection_destroy(pair1);
    PairConnectionConnection_destroy(pair2);
    Connection_destroy(t1);
    Connection_destroy(t2);
  }
  PairConnectionConnectionHandle pair1;
  PairConnectionConnectionHandle pair2;
  ConnectionHandle               t1;
  ConnectionHandle               t2;
};

TEST_F(PairConnectionConnectionTest, CreateDestroy) {
  set_last_error(0, nullptr);
  PairConnectionConnection_create(nullptr, t2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionConnection_create(t1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionConnection_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairConnectionConnectionTest, Accessors) {
  auto f = PairConnectionConnection_first(pair1);
  auto s = PairConnectionConnection_second(pair1);
  EXPECT_TRUE(Connection_equal(f, t1));
  EXPECT_TRUE(Connection_equal(s, t2));
  set_last_error(0, nullptr);
  PairConnectionConnection_first(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionConnection_second(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairConnectionConnectionTest, Equality) {
  EXPECT_TRUE(PairConnectionConnection_equal(pair1, pair2));
  EXPECT_FALSE(PairConnectionConnection_not_equal(pair1, pair2));
  set_last_error(0, nullptr);
  PairConnectionConnection_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionConnection_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionConnection_not_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionConnection_not_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairConnectionConnectionTest, ToJsonFromJson) {
  auto json = PairConnectionConnection_to_json_string(pair1);
  auto p2   = PairConnectionConnection_from_json_string(json);
  EXPECT_TRUE(PairConnectionConnection_equal(pair1, p2));
  PairConnectionConnection_destroy(p2);
  set_last_error(0, nullptr);
  PairConnectionConnection_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionConnection_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
