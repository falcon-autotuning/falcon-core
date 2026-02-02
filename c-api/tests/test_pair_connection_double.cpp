#include <gtest/gtest.h>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/PairConnectionDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"

class PairConnectionDoubleTest : public ::testing::Test {
 protected:
  void SetUp() override {
    ConnectionHandle arr1[2] = {
        Connection_create_plunger_gate(String_wrap("gate1")),
        Connection_create_plunger_gate(String_wrap("gate2"))};
    t1    = Connection_create_plunger_gate(String_wrap("A"));
    t2    = 1.0;
    pair1 = PairConnectionDouble_create(t1, t2);
    pair2 = PairConnectionDouble_create(t1, t2);
  }
  void TearDown() override {
    PairConnectionDouble_destroy(pair1);
    PairConnectionDouble_destroy(pair2);
    Connection_destroy(t1);
  }
  PairConnectionDoubleHandle pair1;
  PairConnectionDoubleHandle pair2;
  ConnectionHandle           t1;
  double                     t2;
};

TEST_F(PairConnectionDoubleTest, CreateDestroy) {
  set_last_error(0, nullptr);
  PairConnectionDouble_create(nullptr, t2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionDouble_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairConnectionDoubleTest, Accessors) {
  auto f = PairConnectionDouble_first(pair1);
  auto s = PairConnectionDouble_second(pair1);
  EXPECT_TRUE(Connection_equal(f, t1));
  EXPECT_TRUE(s == t2);
  set_last_error(0, nullptr);
  PairConnectionDouble_first(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionDouble_second(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairConnectionDoubleTest, Equality) {
  EXPECT_TRUE(PairConnectionDouble_equal(pair1, pair2));
  EXPECT_FALSE(PairConnectionDouble_not_equal(pair1, pair2));
  set_last_error(0, nullptr);
  PairConnectionDouble_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionDouble_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionDouble_not_equal(nullptr, pair2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionDouble_not_equal(pair1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PairConnectionDoubleTest, ToJsonFromJson) {
  auto json = PairConnectionDouble_to_json_string(pair1);
  auto p2   = PairConnectionDouble_from_json_string(json);
  EXPECT_TRUE(PairConnectionDouble_equal(pair1, p2));
  PairConnectionDouble_destroy(p2);
  set_last_error(0, nullptr);
  PairConnectionDouble_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  PairConnectionDouble_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
