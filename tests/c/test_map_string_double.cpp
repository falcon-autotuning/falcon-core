#include <gtest/gtest.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"

#include "falcon-core/generic/MapStringDouble_c_api.h"
#include "falcon-core/generic/PairStringDouble_c_api.h"
#include "falcon-core/generic/String_c_api.h"

class MapStringDoubleTest : public ::testing::Test {
 protected:
  void SetUp() override {
    p1 = PairStringDouble_create(String_wrap("huh"), 1.0);
    p2 = PairStringDouble_create(String_wrap("whee"), 2.0);
    PairStringDoubleHandle arr[2] = {p1, p2};
    map                           = MapStringDouble_create(arr, 2);
    map2                          = MapStringDouble_create_empty();
    MapStringDouble_insert_or_assign(
        map2, PairStringDouble_first(p1), PairStringDouble_second(p1));
    MapStringDouble_insert(
        map2, PairStringDouble_first(p2), PairStringDouble_second(p2));
  }
  void TearDown() override {
    MapStringDouble_destroy(map);
    PairStringDouble_destroy(p1);
    PairStringDouble_destroy(p2);
  }
  PairStringDoubleHandle p1;
  PairStringDoubleHandle p2;
  MapStringDoubleHandle  map;
  MapStringDoubleHandle  map2;
};

TEST_F(MapStringDoubleTest, CreateDestroy) {
  set_last_error(0, nullptr);
  MapStringDouble_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringDouble_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapStringDoubleTest, InsertAssignAccessErase) {
  EXPECT_EQ(MapStringDouble_at(map, PairStringDouble_first(p1)),
            PairStringDouble_second(p1));
  MapStringDouble_erase(map, PairStringDouble_first(p1));
  EXPECT_FALSE(MapStringDouble_contains(map, PairStringDouble_first(p1)));
  set_last_error(0, nullptr);
  MapStringDouble_insert_or_assign(          nullptr, PairStringDouble_first(p1), PairStringDouble_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringDouble_insert_or_assign(                   map, nullptr, PairStringDouble_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringDouble_insert(          nullptr, PairStringDouble_first(p1), PairStringDouble_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringDouble_insert(map, nullptr, PairStringDouble_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringDouble_at(nullptr, PairStringDouble_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringDouble_at(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringDouble_erase(nullptr, PairStringDouble_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringDouble_erase(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapStringDoubleTest, SizeEmptyClearContains) {
  EXPECT_EQ(MapStringDouble_size(map), 2);
  EXPECT_FALSE(MapStringDouble_empty(map));
  MapStringDouble_clear(map);
  EXPECT_TRUE(MapStringDouble_empty(map));
  set_last_error(0, nullptr);
  MapStringDouble_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringDouble_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringDouble_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringDouble_contains(nullptr, PairStringDouble_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringDouble_contains(map2, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapStringDoubleTest, KeysValuesItems) {
  EXPECT_NE(MapStringDouble_keys(map), nullptr);
  EXPECT_NE(MapStringDouble_values(map), nullptr);
  EXPECT_NE(MapStringDouble_items(map), nullptr);
  set_last_error(0, nullptr);
  MapStringDouble_keys(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringDouble_values(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringDouble_items(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapStringDoubleTest, Equality) {
  EXPECT_TRUE(MapStringDouble_equal(map, map2));
  EXPECT_FALSE(MapStringDouble_not_equal(map, map2));
  set_last_error(0, nullptr);
  MapStringDouble_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringDouble_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringDouble_not_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringDouble_not_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapStringDoubleTest, ToJsonFromJson) {
  auto json = MapStringDouble_to_json_string(map);
  auto m2   = MapStringDouble_from_json_string(json);
  EXPECT_TRUE(MapStringDouble_equal(map, m2));
  MapStringDouble_destroy(m2);
  String_destroy(json);
  set_last_error(0, nullptr);
  MapStringDouble_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringDouble_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
