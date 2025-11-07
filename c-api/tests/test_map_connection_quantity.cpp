#include <gtest/gtest.h>

#include "falcon_core/generic/MapConnectionQuantity_c_api.h"
#include "falcon_core/generic/PairConnectionQuantity_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class MapConnectionQuantityTest : public ::testing::Test {
 protected:
  void SetUp() override {
    p1 = PairConnectionQuantity_create(
        Connection_create_plunger_gate(String_wrap("A")), Quantity_create(1.0));
    p2 = PairConnectionQuantity_create(
        Connection_create_barrier_gate(String_wrap("B")), Quantity_create(2.0));
    PairConnectionQuantityHandle arr[2] = {p1, p2};
    map                                 = MapConnectionQuantity_create(arr, 2);
    map2                                = MapConnectionQuantity_create_empty();
    MapConnectionQuantity_insert_or_assign(map2,
                                           PairConnectionQuantity_first(p1),
                                           PairConnectionQuantity_second(p1));
    MapConnectionQuantity_insert(map2,
                                 PairConnectionQuantity_first(p2),
                                 PairConnectionQuantity_second(p2));
  }
  void TearDown() override {
    MapConnectionQuantity_destroy(map);
    PairConnectionQuantity_destroy(p1);
    PairConnectionQuantity_destroy(p2);
  }
  PairConnectionQuantityHandle p1;
  PairConnectionQuantityHandle p2;
  MapConnectionQuantityHandle  map;
  MapConnectionQuantityHandle  map2;
};

TEST_F(MapConnectionQuantityTest, CreateDestroy) {
  EXPECT_THROW(MapConnectionQuantity_create(nullptr, 2), std::invalid_argument);
  EXPECT_THROW(MapConnectionQuantity_destroy(nullptr), std::invalid_argument);
}

TEST_F(MapConnectionQuantityTest, InsertAssignAccessErase) {
  EXPECT_TRUE(Quantity_equal(
      MapConnectionQuantity_at(map, PairConnectionQuantity_first(p1)),
      PairConnectionQuantity_second(p1)));
  MapConnectionQuantity_erase(map, PairConnectionQuantity_first(p1));
  EXPECT_FALSE(
      MapConnectionQuantity_contains(map, PairConnectionQuantity_first(p1)));
  EXPECT_THROW(
      MapConnectionQuantity_insert_or_assign(nullptr,
                                             PairConnectionQuantity_first(p1),
                                             PairConnectionQuantity_second(p1)),
      std::invalid_argument);
  EXPECT_THROW(MapConnectionQuantity_insert_or_assign(
                   map, nullptr, PairConnectionQuantity_second(p1)),
               std::invalid_argument);
  EXPECT_THROW(MapConnectionQuantity_insert_or_assign(
                   map, PairConnectionQuantity_first(p1), nullptr),
               std::invalid_argument);
  EXPECT_THROW(MapConnectionQuantity_insert(nullptr,
                                            PairConnectionQuantity_first(p1),
                                            PairConnectionQuantity_second(p1)),
               std::invalid_argument);
  EXPECT_THROW(MapConnectionQuantity_insert(
                   map, nullptr, PairConnectionQuantity_second(p1)),
               std::invalid_argument);
  EXPECT_THROW(MapConnectionQuantity_insert(
                   map, PairConnectionQuantity_first(p1), nullptr),
               std::invalid_argument);
  EXPECT_THROW(
      MapConnectionQuantity_at(nullptr, PairConnectionQuantity_first(p1)),
      std::invalid_argument);
  EXPECT_THROW(MapConnectionQuantity_at(map, nullptr), std::invalid_argument);
  EXPECT_THROW(
      MapConnectionQuantity_erase(nullptr, PairConnectionQuantity_first(p1)),
      std::invalid_argument);
  EXPECT_THROW(MapConnectionQuantity_erase(map, nullptr),
               std::invalid_argument);
}

TEST_F(MapConnectionQuantityTest, SizeEmptyClearContains) {
  EXPECT_EQ(MapConnectionQuantity_size(map), 2);
  EXPECT_FALSE(MapConnectionQuantity_empty(map));
  MapConnectionQuantity_clear(map);
  EXPECT_TRUE(MapConnectionQuantity_empty(map));
  EXPECT_THROW(MapConnectionQuantity_size(nullptr), std::invalid_argument);
  EXPECT_THROW(MapConnectionQuantity_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(MapConnectionQuantity_clear(nullptr), std::invalid_argument);
  EXPECT_THROW(
      MapConnectionQuantity_contains(nullptr, PairConnectionQuantity_first(p1)),
      std::invalid_argument);
  EXPECT_THROW(MapConnectionQuantity_contains(map2, nullptr),
               std::invalid_argument);
}

TEST_F(MapConnectionQuantityTest, KeysValuesItems) {
  EXPECT_NE(MapConnectionQuantity_keys(map), nullptr);
  EXPECT_NE(MapConnectionQuantity_values(map), nullptr);
  EXPECT_NE(MapConnectionQuantity_items(map), nullptr);
  EXPECT_THROW(MapConnectionQuantity_keys(nullptr), std::invalid_argument);
  EXPECT_THROW(MapConnectionQuantity_values(nullptr), std::invalid_argument);
  EXPECT_THROW(MapConnectionQuantity_items(nullptr), std::invalid_argument);
}

TEST_F(MapConnectionQuantityTest, Equality) {
  EXPECT_TRUE(MapConnectionQuantity_equal(map, map2));
  EXPECT_FALSE(MapConnectionQuantity_not_equal(map, map2));
  EXPECT_THROW(MapConnectionQuantity_equal(nullptr, map2),
               std::invalid_argument);
  EXPECT_THROW(MapConnectionQuantity_equal(map, nullptr),
               std::invalid_argument);
  EXPECT_THROW(MapConnectionQuantity_not_equal(nullptr, map2),
               std::invalid_argument);
  EXPECT_THROW(MapConnectionQuantity_not_equal(map, nullptr),
               std::invalid_argument);
}

TEST_F(MapConnectionQuantityTest, ToJsonFromJson) {
  auto json = MapConnectionQuantity_to_json_string(map);
  auto m2   = MapConnectionQuantity_from_json_string(json);
  EXPECT_TRUE(MapConnectionQuantity_equal(map, m2));
  MapConnectionQuantity_destroy(m2);
  String_destroy(json);
  EXPECT_THROW(MapConnectionQuantity_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(MapConnectionQuantity_from_json_string(nullptr),
               std::invalid_argument);
}
