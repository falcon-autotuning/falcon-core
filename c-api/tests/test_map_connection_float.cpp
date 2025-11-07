#include <gtest/gtest.h>

#include "falcon_core/generic/MapConnectionFloat_c_api.h"
#include "falcon_core/generic/PairConnectionFloat_c_api.h"
#include "falcon_core/generic/String_c_api.h"

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
  EXPECT_THROW(MapConnectionFloat_create(nullptr, 2), std::invalid_argument);
  EXPECT_THROW(MapConnectionFloat_destroy(nullptr), std::invalid_argument);
}

TEST_F(MapConnectionFloatTest, InsertAssignAccessErase) {
  EXPECT_TRUE(MapConnectionFloat_at(map, PairConnectionFloat_first(p1)) ==
              PairConnectionFloat_second(p1));
  MapConnectionFloat_erase(map, PairConnectionFloat_first(p1));
  EXPECT_FALSE(MapConnectionFloat_contains(map, PairConnectionFloat_first(p1)));
  EXPECT_THROW(
      MapConnectionFloat_insert_or_assign(nullptr,
                                          PairConnectionFloat_first(p1),
                                          PairConnectionFloat_second(p1)),
      std::invalid_argument);
  EXPECT_THROW(MapConnectionFloat_insert_or_assign(
                   map, nullptr, PairConnectionFloat_second(p1)),
               std::invalid_argument);
  EXPECT_THROW(MapConnectionFloat_insert(nullptr,
                                         PairConnectionFloat_first(p1),
                                         PairConnectionFloat_second(p1)),
               std::invalid_argument);
  EXPECT_THROW(
      MapConnectionFloat_insert(map, nullptr, PairConnectionFloat_second(p1)),
      std::invalid_argument);
  EXPECT_THROW(MapConnectionFloat_at(nullptr, PairConnectionFloat_first(p1)),
               std::invalid_argument);
  EXPECT_THROW(MapConnectionFloat_at(map, nullptr), std::invalid_argument);
  EXPECT_THROW(MapConnectionFloat_erase(nullptr, PairConnectionFloat_first(p1)),
               std::invalid_argument);
  EXPECT_THROW(MapConnectionFloat_erase(map, nullptr), std::invalid_argument);
}

TEST_F(MapConnectionFloatTest, SizeEmptyClearContains) {
  EXPECT_EQ(MapConnectionFloat_size(map), 2);
  EXPECT_FALSE(MapConnectionFloat_empty(map));
  MapConnectionFloat_clear(map);
  EXPECT_TRUE(MapConnectionFloat_empty(map));
  EXPECT_THROW(MapConnectionFloat_size(nullptr), std::invalid_argument);
  EXPECT_THROW(MapConnectionFloat_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(MapConnectionFloat_clear(nullptr), std::invalid_argument);
  EXPECT_THROW(
      MapConnectionFloat_contains(nullptr, PairConnectionFloat_first(p1)),
      std::invalid_argument);
  EXPECT_THROW(MapConnectionFloat_contains(map2, nullptr),
               std::invalid_argument);
}

TEST_F(MapConnectionFloatTest, KeysValuesItems) {
  EXPECT_NE(MapConnectionFloat_keys(map), nullptr);
  EXPECT_NE(MapConnectionFloat_values(map), nullptr);
  EXPECT_NE(MapConnectionFloat_items(map), nullptr);
  EXPECT_THROW(MapConnectionFloat_keys(nullptr), std::invalid_argument);
  EXPECT_THROW(MapConnectionFloat_values(nullptr), std::invalid_argument);
  EXPECT_THROW(MapConnectionFloat_items(nullptr), std::invalid_argument);
}

TEST_F(MapConnectionFloatTest, Equality) {
  EXPECT_TRUE(MapConnectionFloat_equal(map, map2));
  EXPECT_FALSE(MapConnectionFloat_not_equal(map, map2));
  EXPECT_THROW(MapConnectionFloat_equal(nullptr, map2), std::invalid_argument);
  EXPECT_THROW(MapConnectionFloat_equal(map, nullptr), std::invalid_argument);
  EXPECT_THROW(MapConnectionFloat_not_equal(nullptr, map2),
               std::invalid_argument);
  EXPECT_THROW(MapConnectionFloat_not_equal(map, nullptr),
               std::invalid_argument);
}

TEST_F(MapConnectionFloatTest, ToJsonFromJson) {
  auto json = MapConnectionFloat_to_json_string(map);
  auto m2   = MapConnectionFloat_from_json_string(json);
  EXPECT_TRUE(MapConnectionFloat_equal(map, m2));
  MapConnectionFloat_destroy(m2);
  String_destroy(json);
  EXPECT_THROW(MapConnectionFloat_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(MapConnectionFloat_from_json_string(nullptr),
               std::invalid_argument);
}
