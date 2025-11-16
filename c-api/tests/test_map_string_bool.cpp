#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include "falcon_core/generic/MapStringBool_c_api.h"
#include "falcon_core/generic/PairStringBool_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class MapStringBoolTest : public ::testing::Test {
 protected:
  void SetUp() override {
    p1 = PairStringBool_create(String_wrap("huh"), true);
    p2 = PairStringBool_create(String_wrap("whee"), false);
    PairStringBoolHandle arr[2] = {p1, p2};
    map                         = MapStringBool_create(arr, 2);
    map2                        = MapStringBool_create_empty();
    MapStringBool_insert_or_assign(
        map2, PairStringBool_first(p1), PairStringBool_second(p1));
    MapStringBool_insert(
        map2, PairStringBool_first(p2), PairStringBool_second(p2));
  }
  void TearDown() override {
    MapStringBool_destroy(map);
    PairStringBool_destroy(p1);
    PairStringBool_destroy(p2);
  }
  PairStringBoolHandle p1;
  PairStringBoolHandle p2;
  MapStringBoolHandle  map;
  MapStringBoolHandle  map2;
};

TEST_F(MapStringBoolTest, CreateDestroy) {
  set_last_error(0, nullptr);
  MapStringBool_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringBool_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapStringBoolTest, InsertAssignAccessErase) {
  EXPECT_EQ(MapStringBool_at(map, PairStringBool_first(p1)),
            PairStringBool_second(p1));
  MapStringBool_erase(map, PairStringBool_first(p1));
  EXPECT_FALSE(MapStringBool_contains(map, PairStringBool_first(p1)));
  set_last_error(0, nullptr);
  MapStringBool_insert_or_assign(          nullptr, PairStringBool_first(p1), PairStringBool_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringBool_insert_or_assign(map, nullptr, PairStringBool_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringBool_insert(          nullptr, PairStringBool_first(p1), PairStringBool_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringBool_insert(map, nullptr, PairStringBool_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringBool_at(nullptr, PairStringBool_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringBool_at(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringBool_erase(nullptr, PairStringBool_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringBool_erase(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapStringBoolTest, SizeEmptyClearContains) {
  EXPECT_EQ(MapStringBool_size(map), 2);
  EXPECT_FALSE(MapStringBool_empty(map));
  MapStringBool_clear(map);
  EXPECT_TRUE(MapStringBool_empty(map));
  set_last_error(0, nullptr);
  MapStringBool_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringBool_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringBool_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringBool_contains(nullptr, PairStringBool_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringBool_contains(map2, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapStringBoolTest, KeysValuesItems) {
  EXPECT_NE(MapStringBool_keys(map), nullptr);
  EXPECT_NE(MapStringBool_values(map), nullptr);
  EXPECT_NE(MapStringBool_items(map), nullptr);
  set_last_error(0, nullptr);
  MapStringBool_keys(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringBool_values(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringBool_items(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapStringBoolTest, Equality) {
  EXPECT_TRUE(MapStringBool_equal(map, map2));
  EXPECT_FALSE(MapStringBool_not_equal(map, map2));
  set_last_error(0, nullptr);
  MapStringBool_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringBool_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringBool_not_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringBool_not_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapStringBoolTest, ToJsonFromJson) {
  auto json = MapStringBool_to_json_string(map);
  auto m2   = MapStringBool_from_json_string(json);
  EXPECT_TRUE(MapStringBool_equal(map, m2));
  MapStringBool_destroy(m2);
  String_destroy(json);
  set_last_error(0, nullptr);
  MapStringBool_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringBool_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
