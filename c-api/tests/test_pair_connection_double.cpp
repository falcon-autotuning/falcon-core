#include <gtest/gtest.h>

#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/generic/PairConnectionDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"

class PairConnectionDoubleTest : public ::testing::Test {
 protected:
  void SetUp() override {
    ConnectionHandle arr1[2] = {
        Connection_create_plunger_gate(String_wrap("gate1")),
        Connection_create_plunger_gate(String_wrap("gate2"))};
    ListConnectionHandle lch1 = ListConnection_create(arr1, 2);
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
  EXPECT_THROW(PairConnectionDouble_create(nullptr, t2), std::invalid_argument);
  EXPECT_THROW(PairConnectionDouble_destroy(nullptr), std::invalid_argument);
}

TEST_F(PairConnectionDoubleTest, Accessors) {
  auto f = PairConnectionDouble_first(pair1);
  auto s = PairConnectionDouble_second(pair1);
  EXPECT_TRUE(Connection_equal(f, t1));
  EXPECT_TRUE(s == t2);
  EXPECT_THROW(PairConnectionDouble_first(nullptr), std::invalid_argument);
  EXPECT_THROW(PairConnectionDouble_second(nullptr), std::invalid_argument);
}

TEST_F(PairConnectionDoubleTest, Equality) {
  EXPECT_TRUE(PairConnectionDouble_equal(pair1, pair2));
  EXPECT_FALSE(PairConnectionDouble_not_equal(pair1, pair2));
  EXPECT_THROW(PairConnectionDouble_equal(nullptr, pair2),
               std::invalid_argument);
  EXPECT_THROW(PairConnectionDouble_equal(pair1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(PairConnectionDouble_not_equal(nullptr, pair2),
               std::invalid_argument);
  EXPECT_THROW(PairConnectionDouble_not_equal(pair1, nullptr),
               std::invalid_argument);
}

TEST_F(PairConnectionDoubleTest, ToJsonFromJson) {
  auto json = PairConnectionDouble_to_json_string(pair1);
  auto p2   = PairConnectionDouble_from_json_string(json);
  EXPECT_TRUE(PairConnectionDouble_equal(pair1, p2));
  PairConnectionDouble_destroy(p2);
  EXPECT_THROW(PairConnectionDouble_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(PairConnectionDouble_from_json_string(nullptr),
               std::invalid_argument);
}
