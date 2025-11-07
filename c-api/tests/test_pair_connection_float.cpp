#include <gtest/gtest.h>

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
  EXPECT_THROW(PairConnectionFloat_create(nullptr, t2), std::invalid_argument);
  EXPECT_THROW(PairConnectionFloat_destroy(nullptr), std::invalid_argument);
}

TEST_F(PairConnectionFloatTest, Accessors) {
  auto f = PairConnectionFloat_first(pair1);
  auto s = PairConnectionFloat_second(pair1);
  EXPECT_TRUE(Connection_equal(f, t1));
  EXPECT_TRUE(s == t2);
  EXPECT_THROW(PairConnectionFloat_first(nullptr), std::invalid_argument);
  EXPECT_THROW(PairConnectionFloat_second(nullptr), std::invalid_argument);
}

TEST_F(PairConnectionFloatTest, Equality) {
  EXPECT_TRUE(PairConnectionFloat_equal(pair1, pair2));
  EXPECT_FALSE(PairConnectionFloat_not_equal(pair1, pair2));
  EXPECT_THROW(PairConnectionFloat_equal(nullptr, pair2),
               std::invalid_argument);
  EXPECT_THROW(PairConnectionFloat_equal(pair1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(PairConnectionFloat_not_equal(nullptr, pair2),
               std::invalid_argument);
  EXPECT_THROW(PairConnectionFloat_not_equal(pair1, nullptr),
               std::invalid_argument);
}

TEST_F(PairConnectionFloatTest, ToJsonFromJson) {
  auto json = PairConnectionFloat_to_json_string(pair1);
  auto p2   = PairConnectionFloat_from_json_string(json);
  EXPECT_TRUE(PairConnectionFloat_equal(pair1, p2));
  PairConnectionFloat_destroy(p2);
  EXPECT_THROW(PairConnectionFloat_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(PairConnectionFloat_from_json_string(nullptr),
               std::invalid_argument);
}
