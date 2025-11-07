#include <gtest/gtest.h>

#include "falcon_core/generic/MapStringString_c_api.h"
#include "falcon_core/generic/PairStringString_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class MapStringStringTest : public ::testing::Test {
 protected:
  void SetUp() override {
    p1 = PairStringString_create(String_wrap("huh"), String_wrap("hello"));
    p2 = PairStringString_create(String_wrap("whee"), String_wrap("world"));
    PairStringStringHandle arr[2] = {p1, p2};
    map                           = MapStringString_create(arr, 2);
    map2                          = MapStringString_create_empty();
    MapStringString_insert_or_assign(
        map2, PairStringString_first(p1), PairStringString_second(p1));
    MapStringString_insert(
        map2, PairStringString_first(p2), PairStringString_second(p2));
  }
  void TearDown() override {
    MapStringString_destroy(map);
    PairStringString_destroy(p1);
    PairStringString_destroy(p2);
  }
  PairStringStringHandle p1;
  PairStringStringHandle p2;
  MapStringStringHandle  map;
  MapStringStringHandle  map2;
  bool                   String_equal(StringHandle a, StringHandle b) {
    if (a == nullptr || b == nullptr) {
      throw std::invalid_argument("Null StringHandle provided");
    }
    std::string str_a = std::string(a->raw, a->length);
    std::string str_b = std::string(b->raw, b->length);
    return std::string(str_a) == std::string(str_b);
  }
};

TEST_F(MapStringStringTest, CreateDestroy) {
  EXPECT_THROW(MapStringString_create(nullptr, 2), std::invalid_argument);
  EXPECT_THROW(MapStringString_destroy(nullptr), std::invalid_argument);
}

TEST_F(MapStringStringTest, InsertAssignAccessErase) {
  EXPECT_TRUE(String_equal(MapStringString_at(map, PairStringString_first(p1)),
                           PairStringString_second(p1)));
  MapStringString_erase(map, PairStringString_first(p1));
  EXPECT_FALSE(MapStringString_contains(map, PairStringString_first(p1)));
  EXPECT_THROW(
      MapStringString_insert_or_assign(
          nullptr, PairStringString_first(p1), PairStringString_second(p1)),
      std::invalid_argument);
  EXPECT_THROW(MapStringString_insert_or_assign(
                   map, nullptr, PairStringString_second(p1)),
               std::invalid_argument);
  EXPECT_THROW(MapStringString_insert_or_assign(
                   map, PairStringString_first(p1), nullptr),
               std::invalid_argument);
  EXPECT_THROW(
      MapStringString_insert(
          nullptr, PairStringString_first(p1), PairStringString_second(p1)),
      std::invalid_argument);
  EXPECT_THROW(
      MapStringString_insert(map, nullptr, PairStringString_second(p1)),
      std::invalid_argument);
  EXPECT_THROW(MapStringString_insert(map, PairStringString_first(p1), nullptr),
               std::invalid_argument);
  EXPECT_THROW(MapStringString_at(nullptr, PairStringString_first(p1)),
               std::invalid_argument);
  EXPECT_THROW(MapStringString_at(map, nullptr), std::invalid_argument);
  EXPECT_THROW(MapStringString_erase(nullptr, PairStringString_first(p1)),
               std::invalid_argument);
  EXPECT_THROW(MapStringString_erase(map, nullptr), std::invalid_argument);
}

TEST_F(MapStringStringTest, SizeEmptyClearContains) {
  EXPECT_EQ(MapStringString_size(map), 2);
  EXPECT_FALSE(MapStringString_empty(map));
  MapStringString_clear(map);
  EXPECT_TRUE(MapStringString_empty(map));
  EXPECT_THROW(MapStringString_size(nullptr), std::invalid_argument);
  EXPECT_THROW(MapStringString_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(MapStringString_clear(nullptr), std::invalid_argument);
  EXPECT_THROW(MapStringString_contains(nullptr, PairStringString_first(p1)),
               std::invalid_argument);
  EXPECT_THROW(MapStringString_contains(map2, nullptr), std::invalid_argument);
}

TEST_F(MapStringStringTest, KeysValuesItems) {
  EXPECT_NE(MapStringString_keys(map), nullptr);
  EXPECT_NE(MapStringString_values(map), nullptr);
  EXPECT_NE(MapStringString_items(map), nullptr);
  EXPECT_THROW(MapStringString_keys(nullptr), std::invalid_argument);
  EXPECT_THROW(MapStringString_values(nullptr), std::invalid_argument);
  EXPECT_THROW(MapStringString_items(nullptr), std::invalid_argument);
}

TEST_F(MapStringStringTest, Equality) {
  EXPECT_TRUE(MapStringString_equal(map, map2));
  EXPECT_FALSE(MapStringString_not_equal(map, map2));
  EXPECT_THROW(MapStringString_equal(nullptr, map2), std::invalid_argument);
  EXPECT_THROW(MapStringString_equal(map, nullptr), std::invalid_argument);
  EXPECT_THROW(MapStringString_not_equal(nullptr, map2), std::invalid_argument);
  EXPECT_THROW(MapStringString_not_equal(map, nullptr), std::invalid_argument);
}

TEST_F(MapStringStringTest, ToJsonFromJson) {
  auto json = MapStringString_to_json_string(map);
  auto m2   = MapStringString_from_json_string(json);
  EXPECT_TRUE(MapStringString_equal(map, m2));
  MapStringString_destroy(m2);
  String_destroy(json);
  EXPECT_THROW(MapStringString_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(MapStringString_from_json_string(nullptr),
               std::invalid_argument);
}
