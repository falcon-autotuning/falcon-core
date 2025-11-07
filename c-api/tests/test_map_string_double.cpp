#include <gtest/gtest.h>

#include "falcon_core/generic/MapStringDouble_c_api.h"
#include "falcon_core/generic/PairStringDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"

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
  EXPECT_THROW(MapStringDouble_create(nullptr, 2), std::invalid_argument);
  EXPECT_THROW(MapStringDouble_destroy(nullptr), std::invalid_argument);
}

TEST_F(MapStringDoubleTest, InsertAssignAccessErase) {
  EXPECT_EQ(MapStringDouble_at(map, PairStringDouble_first(p1)),
            PairStringDouble_second(p1));
  MapStringDouble_erase(map, PairStringDouble_first(p1));
  EXPECT_FALSE(MapStringDouble_contains(map, PairStringDouble_first(p1)));
  EXPECT_THROW(
      MapStringDouble_insert_or_assign(
          nullptr, PairStringDouble_first(p1), PairStringDouble_second(p1)),
      std::invalid_argument);
  EXPECT_THROW(MapStringDouble_insert_or_assign(
                   map, nullptr, PairStringDouble_second(p1)),
               std::invalid_argument);
  EXPECT_THROW(
      MapStringDouble_insert(
          nullptr, PairStringDouble_first(p1), PairStringDouble_second(p1)),
      std::invalid_argument);
  EXPECT_THROW(
      MapStringDouble_insert(map, nullptr, PairStringDouble_second(p1)),
      std::invalid_argument);
  EXPECT_THROW(MapStringDouble_at(nullptr, PairStringDouble_first(p1)),
               std::invalid_argument);
  EXPECT_THROW(MapStringDouble_at(map, nullptr), std::invalid_argument);
  EXPECT_THROW(MapStringDouble_erase(nullptr, PairStringDouble_first(p1)),
               std::invalid_argument);
  EXPECT_THROW(MapStringDouble_erase(map, nullptr), std::invalid_argument);
}

TEST_F(MapStringDoubleTest, SizeEmptyClearContains) {
  EXPECT_EQ(MapStringDouble_size(map), 2);
  EXPECT_FALSE(MapStringDouble_empty(map));
  MapStringDouble_clear(map);
  EXPECT_TRUE(MapStringDouble_empty(map));
  EXPECT_THROW(MapStringDouble_size(nullptr), std::invalid_argument);
  EXPECT_THROW(MapStringDouble_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(MapStringDouble_clear(nullptr), std::invalid_argument);
  EXPECT_THROW(MapStringDouble_contains(nullptr, PairStringDouble_first(p1)),
               std::invalid_argument);
  EXPECT_THROW(MapStringDouble_contains(map2, nullptr), std::invalid_argument);
}

TEST_F(MapStringDoubleTest, KeysValuesItems) {
  EXPECT_NE(MapStringDouble_keys(map), nullptr);
  EXPECT_NE(MapStringDouble_values(map), nullptr);
  EXPECT_NE(MapStringDouble_items(map), nullptr);
  EXPECT_THROW(MapStringDouble_keys(nullptr), std::invalid_argument);
  EXPECT_THROW(MapStringDouble_values(nullptr), std::invalid_argument);
  EXPECT_THROW(MapStringDouble_items(nullptr), std::invalid_argument);
}

TEST_F(MapStringDoubleTest, Equality) {
  EXPECT_TRUE(MapStringDouble_equal(map, map2));
  EXPECT_FALSE(MapStringDouble_not_equal(map, map2));
  EXPECT_THROW(MapStringDouble_equal(nullptr, map2), std::invalid_argument);
  EXPECT_THROW(MapStringDouble_equal(map, nullptr), std::invalid_argument);
  EXPECT_THROW(MapStringDouble_not_equal(nullptr, map2), std::invalid_argument);
  EXPECT_THROW(MapStringDouble_not_equal(map, nullptr), std::invalid_argument);
}

TEST_F(MapStringDoubleTest, ToJsonFromJson) {
  auto json = MapStringDouble_to_json_string(map);
  auto m2   = MapStringDouble_from_json_string(json);
  EXPECT_TRUE(MapStringDouble_equal(map, m2));
  MapStringDouble_destroy(m2);
  String_destroy(json);
  EXPECT_THROW(MapStringDouble_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(MapStringDouble_from_json_string(nullptr),
               std::invalid_argument);
}
