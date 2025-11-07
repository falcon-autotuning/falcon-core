#include <gtest/gtest.h>

#include "falcon_core/generic/MapFloatFloat_c_api.h"
#include "falcon_core/generic/PairFloatFloat_c_api.h"
#include "falcon_core/generic/String_c_api.h"

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
  EXPECT_THROW(MapFloatFloat_create(nullptr, 2), std::invalid_argument);
  EXPECT_THROW(MapFloatFloat_destroy(nullptr), std::invalid_argument);
}

TEST_F(MapFloatFloatTest, InsertAssignAccessErase) {
  EXPECT_EQ(MapFloatFloat_at(map, PairFloatFloat_first(p1)),
            PairFloatFloat_second(p1));
  MapFloatFloat_erase(map, PairFloatFloat_first(p1));
  EXPECT_FALSE(MapFloatFloat_contains(map, PairFloatFloat_first(p1)));
  EXPECT_THROW(
      MapFloatFloat_insert_or_assign(
          nullptr, PairFloatFloat_first(p1), PairFloatFloat_second(p1)),
      std::invalid_argument);
  EXPECT_THROW(
      MapFloatFloat_insert(
          nullptr, PairFloatFloat_first(p1), PairFloatFloat_second(p1)),
      std::invalid_argument);
  EXPECT_THROW(MapFloatFloat_at(nullptr, PairFloatFloat_first(p1)),
               std::invalid_argument);
  EXPECT_THROW(MapFloatFloat_erase(nullptr, PairFloatFloat_first(p1)),
               std::invalid_argument);
}

TEST_F(MapFloatFloatTest, SizeEmptyClearContains) {
  EXPECT_EQ(MapFloatFloat_size(map), 2);
  EXPECT_FALSE(MapFloatFloat_empty(map));
  MapFloatFloat_clear(map);
  EXPECT_TRUE(MapFloatFloat_empty(map));
  EXPECT_THROW(MapFloatFloat_size(nullptr), std::invalid_argument);
  EXPECT_THROW(MapFloatFloat_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(MapFloatFloat_clear(nullptr), std::invalid_argument);
  EXPECT_THROW(MapFloatFloat_contains(nullptr, PairFloatFloat_first(p1)),
               std::invalid_argument);
}

TEST_F(MapFloatFloatTest, KeysValuesItems) {
  EXPECT_NE(MapFloatFloat_keys(map), nullptr);
  EXPECT_NE(MapFloatFloat_values(map), nullptr);
  EXPECT_NE(MapFloatFloat_items(map), nullptr);
  EXPECT_THROW(MapFloatFloat_keys(nullptr), std::invalid_argument);
  EXPECT_THROW(MapFloatFloat_values(nullptr), std::invalid_argument);
  EXPECT_THROW(MapFloatFloat_items(nullptr), std::invalid_argument);
}

TEST_F(MapFloatFloatTest, Equality) {
  EXPECT_TRUE(MapFloatFloat_equal(map, map2));
  EXPECT_FALSE(MapFloatFloat_not_equal(map, map2));
  EXPECT_THROW(MapFloatFloat_equal(nullptr, map2), std::invalid_argument);
  EXPECT_THROW(MapFloatFloat_equal(map, nullptr), std::invalid_argument);
  EXPECT_THROW(MapFloatFloat_not_equal(nullptr, map2), std::invalid_argument);
  EXPECT_THROW(MapFloatFloat_not_equal(map, nullptr), std::invalid_argument);
}

TEST_F(MapFloatFloatTest, ToJsonFromJson) {
  auto json = MapFloatFloat_to_json_string(map);
  auto m2   = MapFloatFloat_from_json_string(json);
  EXPECT_TRUE(MapFloatFloat_equal(map, m2));
  MapFloatFloat_destroy(m2);
  String_destroy(json);
  EXPECT_THROW(MapFloatFloat_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(MapFloatFloat_from_json_string(nullptr), std::invalid_argument);
}
