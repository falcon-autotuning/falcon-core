#include <gtest/gtest.h>

#include "falcon_core/generic/MapIntInt_c_api.h"
#include "falcon_core/generic/PairIntInt_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class MapIntIntTest : public ::testing::Test {
 protected:
  void SetUp() override {
    p1                      = PairIntInt_create(1, 10);
    p2                      = PairIntInt_create(2, 20);
    PairIntIntHandle arr[2] = {p1, p2};
    map                     = MapIntInt_create(arr, 2);
    map2                    = MapIntInt_create_empty();
    MapIntInt_insert_or_assign(
        map2, PairIntInt_first(p1), PairIntInt_second(p1));
    MapIntInt_insert(map2, PairIntInt_first(p2), PairIntInt_second(p2));
  }
  void TearDown() override {
    MapIntInt_destroy(map);
    PairIntInt_destroy(p1);
    PairIntInt_destroy(p2);
  }
  PairIntIntHandle p1;
  PairIntIntHandle p2;
  MapIntIntHandle  map;
  MapIntIntHandle  map2;
};

TEST_F(MapIntIntTest, CreateDestroy) {
  EXPECT_THROW(MapIntInt_create(nullptr, 2), std::invalid_argument);
  EXPECT_THROW(MapIntInt_destroy(nullptr), std::invalid_argument);
}

TEST_F(MapIntIntTest, InsertAssignAccessErase) {
  EXPECT_EQ(MapIntInt_at(map, PairIntInt_first(p1)), PairIntInt_second(p1));
  MapIntInt_erase(map, PairIntInt_first(p1));
  EXPECT_FALSE(MapIntInt_contains(map, PairIntInt_first(p1)));
  EXPECT_THROW(MapIntInt_insert_or_assign(
                   nullptr, PairIntInt_first(p1), PairIntInt_second(p1)),
               std::invalid_argument);
  EXPECT_THROW(
      MapIntInt_insert(nullptr, PairIntInt_first(p1), PairIntInt_second(p1)),
      std::invalid_argument);
  EXPECT_THROW(MapIntInt_at(nullptr, PairIntInt_first(p1)),
               std::invalid_argument);
  EXPECT_THROW(MapIntInt_erase(nullptr, PairIntInt_first(p1)),
               std::invalid_argument);
}

TEST_F(MapIntIntTest, SizeEmptyClearContains) {
  EXPECT_EQ(MapIntInt_size(map), 2);
  EXPECT_FALSE(MapIntInt_empty(map));
  MapIntInt_clear(map);
  EXPECT_TRUE(MapIntInt_empty(map));
  EXPECT_THROW(MapIntInt_size(nullptr), std::invalid_argument);
  EXPECT_THROW(MapIntInt_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(MapIntInt_clear(nullptr), std::invalid_argument);
  EXPECT_THROW(MapIntInt_contains(nullptr, PairIntInt_first(p1)),
               std::invalid_argument);
}

TEST_F(MapIntIntTest, KeysValuesItems) {
  EXPECT_NE(MapIntInt_keys(map), nullptr);
  EXPECT_NE(MapIntInt_values(map), nullptr);
  EXPECT_NE(MapIntInt_items(map), nullptr);
  EXPECT_THROW(MapIntInt_keys(nullptr), std::invalid_argument);
  EXPECT_THROW(MapIntInt_values(nullptr), std::invalid_argument);
  EXPECT_THROW(MapIntInt_items(nullptr), std::invalid_argument);
}

TEST_F(MapIntIntTest, Equality) {
  EXPECT_TRUE(MapIntInt_equal(map, map2));
  EXPECT_FALSE(MapIntInt_not_equal(map, map2));
  EXPECT_THROW(MapIntInt_equal(nullptr, map2), std::invalid_argument);
  EXPECT_THROW(MapIntInt_equal(map, nullptr), std::invalid_argument);
  EXPECT_THROW(MapIntInt_not_equal(nullptr, map2), std::invalid_argument);
  EXPECT_THROW(MapIntInt_not_equal(map, nullptr), std::invalid_argument);
}

TEST_F(MapIntIntTest, ToJsonFromJson) {
  auto json = MapIntInt_to_json_string(map);
  auto m2   = MapIntInt_from_json_string(json);
  EXPECT_TRUE(MapIntInt_equal(map, m2));
  MapIntInt_destroy(m2);
  String_destroy(json);
  EXPECT_THROW(MapIntInt_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(MapIntInt_from_json_string(nullptr), std::invalid_argument);
}
