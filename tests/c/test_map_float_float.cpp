#include <gtest/gtest.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"

#include "falcon-core/generic/MapFloatFloat_c_api.h"
#include "falcon-core/generic/PairFloatFloat_c_api.h"
#include "falcon-core/generic/String_c_api.h"

class MapFloatFloatTest : public ::testing::Test {
 protected:
  void SetUp() override {
    p1                          = PairFloatFloat_create(1.0, 10.3);
    p2                          = PairFloatFloat_create(2.9, 20.0);
    PairFloatFloatHandle arr[2] = {p1, p2};
    map                         = MapFloatFloat_create(arr, 2);
    map2                        = MapFloatFloat_create_empty();
    MapFloatFloat_insert_or_assign(
        map2, PairFloatFloat_first(p1), PairFloatFloat_second(p1));
    MapFloatFloat_insert(
        map2, PairFloatFloat_first(p2), PairFloatFloat_second(p2));
  }
  void TearDown() override {
    MapFloatFloat_destroy(map);
    PairFloatFloat_destroy(p1);
    PairFloatFloat_destroy(p2);
  }
  PairFloatFloatHandle p1;
  PairFloatFloatHandle p2;
  MapFloatFloatHandle  map;
  MapFloatFloatHandle  map2;
};

TEST_F(MapFloatFloatTest, CreateDestroy) {
  set_last_error(0, nullptr);
  MapFloatFloat_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapFloatFloat_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapFloatFloatTest, InsertAssignAccessErase) {
  EXPECT_EQ(MapFloatFloat_at(map, PairFloatFloat_first(p1)),
            PairFloatFloat_second(p1));
  MapFloatFloat_erase(map, PairFloatFloat_first(p1));
  EXPECT_FALSE(MapFloatFloat_contains(map, PairFloatFloat_first(p1)));
  set_last_error(0, nullptr);
  MapFloatFloat_insert_or_assign(          nullptr, PairFloatFloat_first(p1), PairFloatFloat_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapFloatFloat_insert(          nullptr, PairFloatFloat_first(p1), PairFloatFloat_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapFloatFloat_at(nullptr, PairFloatFloat_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapFloatFloat_erase(nullptr, PairFloatFloat_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapFloatFloatTest, SizeEmptyClearContains) {
  EXPECT_EQ(MapFloatFloat_size(map), 2);
  EXPECT_FALSE(MapFloatFloat_empty(map));
  MapFloatFloat_clear(map);
  EXPECT_TRUE(MapFloatFloat_empty(map));
  set_last_error(0, nullptr);
  MapFloatFloat_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapFloatFloat_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapFloatFloat_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapFloatFloat_contains(nullptr, PairFloatFloat_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapFloatFloatTest, KeysValuesItems) {
  EXPECT_NE(MapFloatFloat_keys(map), nullptr);
  EXPECT_NE(MapFloatFloat_values(map), nullptr);
  EXPECT_NE(MapFloatFloat_items(map), nullptr);
  set_last_error(0, nullptr);
  MapFloatFloat_keys(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapFloatFloat_values(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapFloatFloat_items(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapFloatFloatTest, Equality) {
  EXPECT_TRUE(MapFloatFloat_equal(map, map2));
  EXPECT_FALSE(MapFloatFloat_not_equal(map, map2));
  set_last_error(0, nullptr);
  MapFloatFloat_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapFloatFloat_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapFloatFloat_not_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapFloatFloat_not_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapFloatFloatTest, ToJsonFromJson) {
  auto json = MapFloatFloat_to_json_string(map);
  auto m2   = MapFloatFloat_from_json_string(json);
  EXPECT_TRUE(MapFloatFloat_equal(map, m2));
  MapFloatFloat_destroy(m2);
  String_destroy(json);
  set_last_error(0, nullptr);
  MapFloatFloat_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapFloatFloat_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
