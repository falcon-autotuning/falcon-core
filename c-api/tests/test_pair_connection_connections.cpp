#include <gtest/gtest.h>

#include "falcon_core/generic/PairConnectionConnections_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"

class PairConnectionConnectionsTest : public ::testing::Test {
 protected:
  void SetUp() override {
    ConnectionHandle arr1[2] = {
        Connection_create_plunger_gate(String_wrap("gate1")),
        Connection_create_plunger_gate(String_wrap("gate2"))};
    ListConnectionHandle lch1 = ListConnection_create(arr1, 2);
    t1    = Connection_create_plunger_gate(String_wrap("A"));
    t2    = Connections_create(lch1);
    pair1 = PairConnectionConnections_create(t1, t2);
    pair2 = PairConnectionConnections_create(t1, t2);
  }
  void TearDown() override {
    PairConnectionConnections_destroy(pair1);
    PairConnectionConnections_destroy(pair2);
    Connection_destroy(t1);
    Connections_destroy(t2);
  }
  PairConnectionConnectionsHandle pair1;
  PairConnectionConnectionsHandle pair2;
  ConnectionHandle                t1;
  ConnectionsHandle               t2;
};

TEST_F(PairConnectionConnectionsTest, CreateDestroy) {
  EXPECT_THROW(PairConnectionConnections_create(nullptr, t2),
               std::invalid_argument);
  EXPECT_THROW(PairConnectionConnections_create(t1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(PairConnectionConnections_destroy(nullptr),
               std::invalid_argument);
}

TEST_F(PairConnectionConnectionsTest, Accessors) {
  auto f = PairConnectionConnections_first(pair1);
  auto s = PairConnectionConnections_second(pair1);
  EXPECT_TRUE(Connection_equal(f, t1));
  EXPECT_TRUE(Connections_equal(s, t2));
  EXPECT_THROW(PairConnectionConnections_first(nullptr), std::invalid_argument);
  EXPECT_THROW(PairConnectionConnections_second(nullptr),
               std::invalid_argument);
}

TEST_F(PairConnectionConnectionsTest, Equality) {
  EXPECT_TRUE(PairConnectionConnections_equal(pair1, pair2));
  EXPECT_FALSE(PairConnectionConnections_not_equal(pair1, pair2));
  EXPECT_THROW(PairConnectionConnections_equal(nullptr, pair2),
               std::invalid_argument);
  EXPECT_THROW(PairConnectionConnections_equal(pair1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(PairConnectionConnections_not_equal(nullptr, pair2),
               std::invalid_argument);
  EXPECT_THROW(PairConnectionConnections_not_equal(pair1, nullptr),
               std::invalid_argument);
}

TEST_F(PairConnectionConnectionsTest, ToJsonFromJson) {
  auto json = PairConnectionConnections_to_json_string(pair1);
  auto p2   = PairConnectionConnections_from_json_string(json);
  EXPECT_TRUE(PairConnectionConnections_equal(pair1, p2));
  PairConnectionConnections_destroy(p2);
  EXPECT_THROW(PairConnectionConnections_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(PairConnectionConnections_from_json_string(nullptr),
               std::invalid_argument);
}
