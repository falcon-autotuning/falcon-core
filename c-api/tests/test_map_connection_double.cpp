#include <gtest/gtest.h>

#include "falcon_core/generic/MapConnectionDouble_c_api.h"
#include "falcon_core/generic/PairConnectionDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class MapConnectionDoubleTest : public ::testing::Test {
 protected:
  void SetUp() override {
    p1 = PairConnectionDouble_create(
        Connection_create_plunger_gate(String_wrap("A")), 1.0);
    p2 = PairConnectionDouble_create(
        Connection_create_plunger_gate(String_wrap("B")), 2.0);
    PairConnectionDoubleHandle arr[2] = {p1, p2};
    map                               = MapConnectionDouble_create(arr, 2);
    map2                              = MapConnectionDouble_create_empty();
    MapConnectionDouble_insert_or_assign(
        map2, PairConnectionDouble_first(p1), PairConnectionDouble_second(p1));
    MapConnectionDouble_insert(
        map2, PairConnectionDouble_first(p2), PairConnectionDouble_second(p2));
  }
  void TearDown() override {
    MapConnectionDouble_destroy(map);
    PairConnectionDouble_destroy(p1);
    PairConnectionDouble_destroy(p2);
  }
  PairConnectionDoubleHandle p1;
  PairConnectionDoubleHandle p2;
  MapConnectionDoubleHandle  map;
  MapConnectionDoubleHandle  map2;
};

TEST_F(MapConnectionDoubleTest, CreateDestroy) {
  EXPECT_THROW(MapConnectionDouble_create(nullptr, 2), std::invalid_argument);
  EXPECT_THROW(MapConnectionDouble_destroy(nullptr), std::invalid_argument);
}

TEST_F(MapConnectionDoubleTest, InsertAssignAccessErase) {
  EXPECT_TRUE(MapConnectionDouble_at(map, PairConnectionDouble_first(p1)) ==
              PairConnectionDouble_second(p1));
  MapConnectionDouble_erase(map, PairConnectionDouble_first(p1));
  EXPECT_FALSE(
      MapConnectionDouble_contains(map, PairConnectionDouble_first(p1)));
  EXPECT_THROW(
      MapConnectionDouble_insert_or_assign(nullptr,
                                           PairConnectionDouble_first(p1),
                                           PairConnectionDouble_second(p1)),
      std::invalid_argument);
  EXPECT_THROW(MapConnectionDouble_insert_or_assign(
                   map, nullptr, PairConnectionDouble_second(p1)),
               std::invalid_argument);
  EXPECT_THROW(MapConnectionDouble_insert(nullptr,
                                          PairConnectionDouble_first(p1),
                                          PairConnectionDouble_second(p1)),
               std::invalid_argument);
  EXPECT_THROW(
      MapConnectionDouble_insert(map, nullptr, PairConnectionDouble_second(p1)),
      std::invalid_argument);
  EXPECT_THROW(MapConnectionDouble_at(nullptr, PairConnectionDouble_first(p1)),
               std::invalid_argument);
  EXPECT_THROW(MapConnectionDouble_at(map, nullptr), std::invalid_argument);
  EXPECT_THROW(
      MapConnectionDouble_erase(nullptr, PairConnectionDouble_first(p1)),
      std::invalid_argument);
  EXPECT_THROW(MapConnectionDouble_erase(map, nullptr), std::invalid_argument);
}

TEST_F(MapConnectionDoubleTest, SizeEmptyClearContains) {
  EXPECT_EQ(MapConnectionDouble_size(map), 2);
  EXPECT_FALSE(MapConnectionDouble_empty(map));
  MapConnectionDouble_clear(map);
  EXPECT_TRUE(MapConnectionDouble_empty(map));
  EXPECT_THROW(MapConnectionDouble_size(nullptr), std::invalid_argument);
  EXPECT_THROW(MapConnectionDouble_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(MapConnectionDouble_clear(nullptr), std::invalid_argument);
  EXPECT_THROW(
      MapConnectionDouble_contains(nullptr, PairConnectionDouble_first(p1)),
      std::invalid_argument);
  EXPECT_THROW(MapConnectionDouble_contains(map2, nullptr),
               std::invalid_argument);
}

TEST_F(MapConnectionDoubleTest, KeysValuesItems) {
  EXPECT_NE(MapConnectionDouble_keys(map), nullptr);
  EXPECT_NE(MapConnectionDouble_values(map), nullptr);
  EXPECT_NE(MapConnectionDouble_items(map), nullptr);
  EXPECT_THROW(MapConnectionDouble_keys(nullptr), std::invalid_argument);
  EXPECT_THROW(MapConnectionDouble_values(nullptr), std::invalid_argument);
  EXPECT_THROW(MapConnectionDouble_items(nullptr), std::invalid_argument);
}

TEST_F(MapConnectionDoubleTest, Equality) {
  EXPECT_TRUE(MapConnectionDouble_equal(map, map2));
  EXPECT_FALSE(MapConnectionDouble_not_equal(map, map2));
  EXPECT_THROW(MapConnectionDouble_equal(nullptr, map2), std::invalid_argument);
  EXPECT_THROW(MapConnectionDouble_equal(map, nullptr), std::invalid_argument);
  EXPECT_THROW(MapConnectionDouble_not_equal(nullptr, map2),
               std::invalid_argument);
  EXPECT_THROW(MapConnectionDouble_not_equal(map, nullptr),
               std::invalid_argument);
}

TEST_F(MapConnectionDoubleTest, ToJsonFromJson) {
  auto json = MapConnectionDouble_to_json_string(map);
  auto m2   = MapConnectionDouble_from_json_string(json);
  EXPECT_TRUE(MapConnectionDouble_equal(map, m2));
  MapConnectionDouble_destroy(m2);
  String_destroy(json);
  EXPECT_THROW(MapConnectionDouble_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(MapConnectionDouble_from_json_string(nullptr),
               std::invalid_argument);
}
