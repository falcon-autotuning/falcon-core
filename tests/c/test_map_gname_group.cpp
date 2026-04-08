#include <gtest/gtest.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"

#include "falcon-core/generic/MapGnameGroup_c_api.h"
#include "falcon-core/generic/PairGnameGroup_c_api.h"
#include "falcon-core/generic/String_c_api.h"

class MapGnameGroupTest : public ::testing::Test {
 protected:
  void SetUp() override {
    ConnectionHandle s1raw[2] = {
        Connection_create_screening_gate(String_wrap("S1")),
        Connection_create_screening_gate(String_wrap("S2"))};
    ListConnectionHandle s1       = ListConnection_create(s1raw, 2);
    ConnectionHandle     s2raw[2] = {
        Connection_create_screening_gate(String_wrap("S3")),
        Connection_create_screening_gate(String_wrap("S4"))};
    ListConnectionHandle s2       = ListConnection_create(s2raw, 2);
    ConnectionHandle     r1raw[2] = {
        Connection_create_reservoir_gate(String_wrap("R1")),
        Connection_create_reservoir_gate(String_wrap("R2"))};
    ListConnectionHandle r1       = ListConnection_create(r1raw, 2);
    ConnectionHandle     r2raw[2] = {
        Connection_create_reservoir_gate(String_wrap("R3")),
        Connection_create_reservoir_gate(String_wrap("R4"))};
    ListConnectionHandle r2       = ListConnection_create(r2raw, 2);
    ConnectionHandle     b1raw[2] = {
        Connection_create_barrier_gate(String_wrap("B1")),
        Connection_create_barrier_gate(String_wrap("B2"))};
    ListConnectionHandle b1       = ListConnection_create(b1raw, 2);
    ConnectionHandle     b2raw[2] = {
        Connection_create_barrier_gate(String_wrap("B3")),
        Connection_create_barrier_gate(String_wrap("B4"))};
    ListConnectionHandle b2       = ListConnection_create(b2raw, 2);
    ConnectionHandle     p1raw[1] = {
        Connection_create_plunger_gate(String_wrap("P1"))};
    ListConnectionHandle P1       = ListConnection_create(p1raw, 1);
    ConnectionHandle     p2raw[1] = {
        Connection_create_plunger_gate(String_wrap("P2"))};
    ListConnectionHandle P2       = ListConnection_create(p2raw, 1);
    ConnectionHandle     o1raw[7] = {
        Connection_create_ohmic(String_wrap("O1")),
        Connection_create_reservoir_gate(String_wrap("R1")),
        Connection_create_barrier_gate(String_wrap("B1")),
        Connection_create_plunger_gate(String_wrap("P1")),
        Connection_create_barrier_gate(String_wrap("B2")),
        Connection_create_reservoir_gate(String_wrap("R2")),
        Connection_create_ohmic(String_wrap("O2"))};
    ListConnectionHandle o1       = ListConnection_create(o1raw, 7);
    ConnectionHandle     o2raw[7] = {
        Connection_create_ohmic(String_wrap("O3")),
        Connection_create_reservoir_gate(String_wrap("R3")),
        Connection_create_barrier_gate(String_wrap("B3")),
        Connection_create_plunger_gate(String_wrap("P2")),
        Connection_create_barrier_gate(String_wrap("B4")),
        Connection_create_reservoir_gate(String_wrap("R4")),
        Connection_create_ohmic(String_wrap("O4"))};
    ListConnectionHandle o2 = ListConnection_create(o2raw, 7);
    p1 =
        PairGnameGroup_create(Gname_create(String_wrap("A")),
                              Group_create(Channel_create(String_wrap("Chan1")),
                                           1,
                                           Connections_create(s1),
                                           Connections_create(r1),
                                           Connections_create(P1),
                                           Connections_create(b1),
                                           Connections_create(o1)));
    p2 =
        PairGnameGroup_create(Gname_create(String_wrap("B")),
                              Group_create(Channel_create(String_wrap("Chan2")),
                                           2,
                                           Connections_create(s2),
                                           Connections_create(r2),
                                           Connections_create(P2),
                                           Connections_create(b2),
                                           Connections_create(o2)));
    PairGnameGroupHandle arr[2] = {p1, p2};
    map                         = MapGnameGroup_create(arr, 2);
    map2                        = MapGnameGroup_create_empty();
    MapGnameGroup_insert_or_assign(
        map2, PairGnameGroup_first(p1), PairGnameGroup_second(p1));
    MapGnameGroup_insert(
        map2, PairGnameGroup_first(p2), PairGnameGroup_second(p2));
  }
  void TearDown() override {
    MapGnameGroup_destroy(map);
    PairGnameGroup_destroy(p1);
    PairGnameGroup_destroy(p2);
  }
  PairGnameGroupHandle p1;
  PairGnameGroupHandle p2;
  MapGnameGroupHandle  map;
  MapGnameGroupHandle  map2;
};

TEST_F(MapGnameGroupTest, CreateDestroy) {
  set_last_error(0, nullptr);
  MapGnameGroup_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapGnameGroup_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapGnameGroupTest, InsertAssignAccessErase) {
  EXPECT_TRUE(Group_equal(MapGnameGroup_at(map, PairGnameGroup_first(p1)),
                          PairGnameGroup_second(p1)));
  MapGnameGroup_erase(map, PairGnameGroup_first(p1));
  EXPECT_FALSE(MapGnameGroup_contains(map, PairGnameGroup_first(p1)));
  set_last_error(0, nullptr);
  MapGnameGroup_insert_or_assign(          nullptr, PairGnameGroup_first(p1), PairGnameGroup_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapGnameGroup_insert_or_assign(map, nullptr, PairGnameGroup_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapGnameGroup_insert_or_assign(map, PairGnameGroup_first(p1), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapGnameGroup_insert(          nullptr, PairGnameGroup_first(p1), PairGnameGroup_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapGnameGroup_insert(map, nullptr, PairGnameGroup_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapGnameGroup_insert(map, PairGnameGroup_first(p1), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapGnameGroup_at(nullptr, PairGnameGroup_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapGnameGroup_at(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapGnameGroup_erase(nullptr, PairGnameGroup_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapGnameGroup_erase(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapGnameGroupTest, SizeEmptyClearContains) {
  EXPECT_EQ(MapGnameGroup_size(map), 2);
  EXPECT_FALSE(MapGnameGroup_empty(map));
  MapGnameGroup_clear(map);
  EXPECT_TRUE(MapGnameGroup_empty(map));
  set_last_error(0, nullptr);
  MapGnameGroup_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapGnameGroup_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapGnameGroup_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapGnameGroup_contains(nullptr, PairGnameGroup_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapGnameGroup_contains(map2, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapGnameGroupTest, KeysValuesItems) {
  EXPECT_NE(MapGnameGroup_keys(map), nullptr);
  EXPECT_NE(MapGnameGroup_values(map), nullptr);
  EXPECT_NE(MapGnameGroup_items(map), nullptr);
  set_last_error(0, nullptr);
  MapGnameGroup_keys(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapGnameGroup_values(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapGnameGroup_items(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapGnameGroupTest, Equality) {
  EXPECT_TRUE(MapGnameGroup_equal(map, map2));
  EXPECT_FALSE(MapGnameGroup_not_equal(map, map2));
  set_last_error(0, nullptr);
  MapGnameGroup_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapGnameGroup_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapGnameGroup_not_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapGnameGroup_not_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapGnameGroupTest, ToJsonFromJson) {
  auto json = MapGnameGroup_to_json_string(map);
  auto m2   = MapGnameGroup_from_json_string(json);
  EXPECT_TRUE(MapGnameGroup_equal(map, m2));
  MapGnameGroup_destroy(m2);
  String_destroy(json);
  set_last_error(0, nullptr);
  MapGnameGroup_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapGnameGroup_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
