#include <gtest/gtest.h>

#include "falcon_core/generic/PairChannelConnections_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class PairChannelConnectionsTest : public ::testing::Test {
 protected:
  void SetUp() override {
    ConnectionHandle arr1[2] = {
        Connection_create_plunger_gate(String_wrap("gate1")),
        Connection_create_plunger_gate(String_wrap("gate2"))};
    ListConnectionHandle lch1 = ListConnection_create(arr1, 2);
    t1                        = Channel_create(String_wrap("channel_1"));
    t2                        = Connections_create(lch1);
    pair1                     = PairChannelConnections_create(t1, t2);
    pair2                     = PairChannelConnections_create(t1, t2);
  }
  void TearDown() override {
    PairChannelConnections_destroy(pair1);
    PairChannelConnections_destroy(pair2);
    Channel_destroy(t1);
    Connections_destroy(t2);
  }
  PairChannelConnectionsHandle pair1;
  PairChannelConnectionsHandle pair2;
  ChannelHandle                t1;
  ConnectionsHandle            t2;
};

TEST_F(PairChannelConnectionsTest, CreateDestroy) {
  EXPECT_THROW(PairChannelConnections_create(nullptr, t2),
               std::invalid_argument);
  EXPECT_THROW(PairChannelConnections_create(t1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(PairChannelConnections_destroy(nullptr), std::invalid_argument);
}

TEST_F(PairChannelConnectionsTest, Accessors) {
  auto f = PairChannelConnections_first(pair1);
  auto s = PairChannelConnections_second(pair1);
  EXPECT_TRUE(Channel_equal(f, t1));
  EXPECT_TRUE(Connections_equal(s, t2));
  EXPECT_THROW(PairChannelConnections_first(nullptr), std::invalid_argument);
  EXPECT_THROW(PairChannelConnections_second(nullptr), std::invalid_argument);
}

TEST_F(PairChannelConnectionsTest, Equality) {
  EXPECT_TRUE(PairChannelConnections_equal(pair1, pair2));
  EXPECT_FALSE(PairChannelConnections_not_equal(pair1, pair2));
  EXPECT_THROW(PairChannelConnections_equal(nullptr, pair2),
               std::invalid_argument);
  EXPECT_THROW(PairChannelConnections_equal(pair1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(PairChannelConnections_not_equal(nullptr, pair2),
               std::invalid_argument);
  EXPECT_THROW(PairChannelConnections_not_equal(pair1, nullptr),
               std::invalid_argument);
}

TEST_F(PairChannelConnectionsTest, ToJsonFromJson) {
  auto json = PairChannelConnections_to_json_string(pair1);
  auto p2   = PairChannelConnections_from_json_string(json);
  EXPECT_TRUE(PairChannelConnections_equal(pair1, p2));
  PairChannelConnections_destroy(p2);
  EXPECT_THROW(PairChannelConnections_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(PairChannelConnections_from_json_string(nullptr),
               std::invalid_argument);
}
