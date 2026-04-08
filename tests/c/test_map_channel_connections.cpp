#include <gtest/gtest.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"

#include "falcon-core/generic/MapChannelConnections_c_api.h"
#include "falcon-core/generic/PairChannelConnections_c_api.h"
#include "falcon-core/generic/String_c_api.h"

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
  set_last_error(0, nullptr);
  MapChannelConnections_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapChannelConnections_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapChannelConnectionsTest, InsertAssignAccessErase) {
  EXPECT_TRUE(Connections_equal(
      MapChannelConnections_at(map, PairChannelConnections_first(p1)),
      PairChannelConnections_second(p1)));
  MapChannelConnections_erase(map, PairChannelConnections_first(p1));
  EXPECT_FALSE(
      MapChannelConnections_contains(map, PairChannelConnections_first(p1)));
  set_last_error(0, nullptr);
  MapChannelConnections_insert_or_assign(nullptr,                                             PairChannelConnections_first(p1),                                             PairChannelConnections_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapChannelConnections_insert_or_assign(                   map, nullptr, PairChannelConnections_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapChannelConnections_insert_or_assign(                   map, PairChannelConnections_first(p1), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapChannelConnections_insert(nullptr,                                            PairChannelConnections_first(p1),                                            PairChannelConnections_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapChannelConnections_insert(                   map, nullptr, PairChannelConnections_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapChannelConnections_insert(                   map, PairChannelConnections_first(p1), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapChannelConnections_at(nullptr, PairChannelConnections_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapChannelConnections_at(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapChannelConnections_erase(nullptr, PairChannelConnections_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapChannelConnections_erase(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapChannelConnectionsTest, SizeEmptyClearContains) {
  EXPECT_EQ(MapChannelConnections_size(map), 2);
  EXPECT_FALSE(MapChannelConnections_empty(map));
  MapChannelConnections_clear(map);
  EXPECT_TRUE(MapChannelConnections_empty(map));
  set_last_error(0, nullptr);
  MapChannelConnections_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapChannelConnections_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapChannelConnections_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapChannelConnections_contains(nullptr, PairChannelConnections_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapChannelConnections_contains(map2, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapChannelConnectionsTest, KeysValuesItems) {
  EXPECT_NE(MapChannelConnections_keys(map), nullptr);
  EXPECT_NE(MapChannelConnections_values(map), nullptr);
  EXPECT_NE(MapChannelConnections_items(map), nullptr);
  set_last_error(0, nullptr);
  MapChannelConnections_keys(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapChannelConnections_values(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapChannelConnections_items(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapChannelConnectionsTest, Equality) {
  EXPECT_TRUE(MapChannelConnections_equal(map, map2));
  EXPECT_FALSE(MapChannelConnections_not_equal(map, map2));
  set_last_error(0, nullptr);
  MapChannelConnections_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapChannelConnections_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapChannelConnections_not_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapChannelConnections_not_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapChannelConnectionsTest, ToJsonFromJson) {
  auto json = MapChannelConnections_to_json_string(map);
  auto m2   = MapChannelConnections_from_json_string(json);
  EXPECT_TRUE(MapChannelConnections_equal(map, m2));
  MapChannelConnections_destroy(m2);
  String_destroy(json);
  set_last_error(0, nullptr);
  MapChannelConnections_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapChannelConnections_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
