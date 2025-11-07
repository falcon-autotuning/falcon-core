#include <gtest/gtest.h>

#include "falcon_core/generic/MapChannelConnections_c_api.h"
#include "falcon_core/generic/PairChannelConnections_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class MapChannelConnectionsTest : public ::testing::Test {
 protected:
  void SetUp() override {
    ListConnectionHandle connections = ListConnection_create_empty();
    ListConnection_push_back(connections,
                             Connection_create_plunger_gate(String_wrap("A")));
    p1 = PairChannelConnections_create(Channel_create(String_wrap("A")),
                                       Connections_create(connections));
    p2 = PairChannelConnections_create(Channel_create(String_wrap("B")),
                                       Connections_create(connections));
    PairChannelConnectionsHandle arr[2] = {p1, p2};
    map                                 = MapChannelConnections_create(arr, 2);
    map2                                = MapChannelConnections_create_empty();
    MapChannelConnections_insert_or_assign(map2,
                                           PairChannelConnections_first(p1),
                                           PairChannelConnections_second(p1));
    MapChannelConnections_insert(map2,
                                 PairChannelConnections_first(p2),
                                 PairChannelConnections_second(p2));
  }
  void TearDown() override {
    MapChannelConnections_destroy(map);
    PairChannelConnections_destroy(p1);
    PairChannelConnections_destroy(p2);
  }
  PairChannelConnectionsHandle p1;
  PairChannelConnectionsHandle p2;
  MapChannelConnectionsHandle  map;
  MapChannelConnectionsHandle  map2;
};

TEST_F(MapChannelConnectionsTest, CreateDestroy) {
  EXPECT_THROW(MapChannelConnections_create(nullptr, 2), std::invalid_argument);
  EXPECT_THROW(MapChannelConnections_destroy(nullptr), std::invalid_argument);
}

TEST_F(MapChannelConnectionsTest, InsertAssignAccessErase) {
  EXPECT_TRUE(Connections_equal(
      MapChannelConnections_at(map, PairChannelConnections_first(p1)),
      PairChannelConnections_second(p1)));
  MapChannelConnections_erase(map, PairChannelConnections_first(p1));
  EXPECT_FALSE(
      MapChannelConnections_contains(map, PairChannelConnections_first(p1)));
  EXPECT_THROW(
      MapChannelConnections_insert_or_assign(nullptr,
                                             PairChannelConnections_first(p1),
                                             PairChannelConnections_second(p1)),
      std::invalid_argument);
  EXPECT_THROW(MapChannelConnections_insert_or_assign(
                   map, nullptr, PairChannelConnections_second(p1)),
               std::invalid_argument);
  EXPECT_THROW(MapChannelConnections_insert_or_assign(
                   map, PairChannelConnections_first(p1), nullptr),
               std::invalid_argument);
  EXPECT_THROW(MapChannelConnections_insert(nullptr,
                                            PairChannelConnections_first(p1),
                                            PairChannelConnections_second(p1)),
               std::invalid_argument);
  EXPECT_THROW(MapChannelConnections_insert(
                   map, nullptr, PairChannelConnections_second(p1)),
               std::invalid_argument);
  EXPECT_THROW(MapChannelConnections_insert(
                   map, PairChannelConnections_first(p1), nullptr),
               std::invalid_argument);
  EXPECT_THROW(
      MapChannelConnections_at(nullptr, PairChannelConnections_first(p1)),
      std::invalid_argument);
  EXPECT_THROW(MapChannelConnections_at(map, nullptr), std::invalid_argument);
  EXPECT_THROW(
      MapChannelConnections_erase(nullptr, PairChannelConnections_first(p1)),
      std::invalid_argument);
  EXPECT_THROW(MapChannelConnections_erase(map, nullptr),
               std::invalid_argument);
}

TEST_F(MapChannelConnectionsTest, SizeEmptyClearContains) {
  EXPECT_EQ(MapChannelConnections_size(map), 2);
  EXPECT_FALSE(MapChannelConnections_empty(map));
  MapChannelConnections_clear(map);
  EXPECT_TRUE(MapChannelConnections_empty(map));
  EXPECT_THROW(MapChannelConnections_size(nullptr), std::invalid_argument);
  EXPECT_THROW(MapChannelConnections_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(MapChannelConnections_clear(nullptr), std::invalid_argument);
  EXPECT_THROW(
      MapChannelConnections_contains(nullptr, PairChannelConnections_first(p1)),
      std::invalid_argument);
  EXPECT_THROW(MapChannelConnections_contains(map2, nullptr),
               std::invalid_argument);
}

TEST_F(MapChannelConnectionsTest, KeysValuesItems) {
  EXPECT_NE(MapChannelConnections_keys(map), nullptr);
  EXPECT_NE(MapChannelConnections_values(map), nullptr);
  EXPECT_NE(MapChannelConnections_items(map), nullptr);
  EXPECT_THROW(MapChannelConnections_keys(nullptr), std::invalid_argument);
  EXPECT_THROW(MapChannelConnections_values(nullptr), std::invalid_argument);
  EXPECT_THROW(MapChannelConnections_items(nullptr), std::invalid_argument);
}

TEST_F(MapChannelConnectionsTest, Equality) {
  EXPECT_TRUE(MapChannelConnections_equal(map, map2));
  EXPECT_FALSE(MapChannelConnections_not_equal(map, map2));
  EXPECT_THROW(MapChannelConnections_equal(nullptr, map2),
               std::invalid_argument);
  EXPECT_THROW(MapChannelConnections_equal(map, nullptr),
               std::invalid_argument);
  EXPECT_THROW(MapChannelConnections_not_equal(nullptr, map2),
               std::invalid_argument);
  EXPECT_THROW(MapChannelConnections_not_equal(map, nullptr),
               std::invalid_argument);
}

TEST_F(MapChannelConnectionsTest, ToJsonFromJson) {
  auto json = MapChannelConnections_to_json_string(map);
  auto m2   = MapChannelConnections_from_json_string(json);
  EXPECT_TRUE(MapChannelConnections_equal(map, m2));
  MapChannelConnections_destroy(m2);
  String_destroy(json);
  EXPECT_THROW(MapChannelConnections_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(MapChannelConnections_from_json_string(nullptr),
               std::invalid_argument);
}
