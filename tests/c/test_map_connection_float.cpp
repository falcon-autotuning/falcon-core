#include <gtest/gtest.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"

#include "falcon-core/generic/MapConnectionFloat_c_api.h"
#include "falcon-core/generic/PairConnectionFloat_c_api.h"
#include "falcon-core/generic/String_c_api.h"

class MapConnectionFloatTest : public ::testing::Test {
 protected:
  void SetUp() override {
    p1 = PairConnectionFloat_create(
        Connection_create_plunger_gate(String_wrap("A")), 1.0);
    p2 = PairConnectionFloat_create(
        Connection_create_plunger_gate(String_wrap("B")), 2.0);
    PairConnectionFloatHandle arr[2] = {p1, p2};
    map                              = MapConnectionFloat_create(arr, 2);
    map2                             = MapConnectionFloat_create_empty();
    MapConnectionFloat_insert_or_assign(
        map2, PairConnectionFloat_first(p1), PairConnectionFloat_second(p1));
    MapConnectionFloat_insert(
        map2, PairConnectionFloat_first(p2), PairConnectionFloat_second(p2));
  }
  void TearDown() override {
    MapConnectionFloat_destroy(map);
    PairConnectionFloat_destroy(p1);
    PairConnectionFloat_destroy(p2);
  }
  PairConnectionFloatHandle p1;
  PairConnectionFloatHandle p2;
  MapConnectionFloatHandle  map;
  MapConnectionFloatHandle  map2;
};

TEST_F(MapConnectionFloatTest, CreateDestroy) {
  set_last_error(0, nullptr);
  MapConnectionFloat_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapConnectionFloat_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapConnectionFloatTest, InsertAssignAccessErase) {
  EXPECT_TRUE(MapConnectionFloat_at(map, PairConnectionFloat_first(p1)) ==
              PairConnectionFloat_second(p1));
  MapConnectionFloat_erase(map, PairConnectionFloat_first(p1));
  EXPECT_FALSE(MapConnectionFloat_contains(map, PairConnectionFloat_first(p1)));
  set_last_error(0, nullptr);
  MapConnectionFloat_insert_or_assign(nullptr,                                          PairConnectionFloat_first(p1),                                          PairConnectionFloat_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapConnectionFloat_insert_or_assign(                   map, nullptr, PairConnectionFloat_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapConnectionFloat_insert(nullptr,                                         PairConnectionFloat_first(p1),                                         PairConnectionFloat_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapConnectionFloat_insert(map, nullptr, PairConnectionFloat_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapConnectionFloat_at(nullptr, PairConnectionFloat_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapConnectionFloat_at(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapConnectionFloat_erase(nullptr, PairConnectionFloat_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapConnectionFloat_erase(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapConnectionFloatTest, SizeEmptyClearContains) {
  EXPECT_EQ(MapConnectionFloat_size(map), 2);
  EXPECT_FALSE(MapConnectionFloat_empty(map));
  MapConnectionFloat_clear(map);
  EXPECT_TRUE(MapConnectionFloat_empty(map));
  set_last_error(0, nullptr);
  MapConnectionFloat_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapConnectionFloat_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapConnectionFloat_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapConnectionFloat_contains(nullptr, PairConnectionFloat_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapConnectionFloat_contains(map2, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapConnectionFloatTest, KeysValuesItems) {
  EXPECT_NE(MapConnectionFloat_keys(map), nullptr);
  EXPECT_NE(MapConnectionFloat_values(map), nullptr);
  EXPECT_NE(MapConnectionFloat_items(map), nullptr);
  set_last_error(0, nullptr);
  MapConnectionFloat_keys(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapConnectionFloat_values(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapConnectionFloat_items(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapConnectionFloatTest, Equality) {
  EXPECT_TRUE(MapConnectionFloat_equal(map, map2));
  EXPECT_FALSE(MapConnectionFloat_not_equal(map, map2));
  set_last_error(0, nullptr);
  MapConnectionFloat_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapConnectionFloat_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapConnectionFloat_not_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapConnectionFloat_not_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapConnectionFloatTest, ToJsonFromJson) {
  auto json = MapConnectionFloat_to_json_string(map);
  auto m2   = MapConnectionFloat_from_json_string(json);
  EXPECT_TRUE(MapConnectionFloat_equal(map, m2));
  MapConnectionFloat_destroy(m2);
  String_destroy(json);
  set_last_error(0, nullptr);
  MapConnectionFloat_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapConnectionFloat_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
