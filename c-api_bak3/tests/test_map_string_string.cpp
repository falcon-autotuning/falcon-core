#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"

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
  set_last_error(0, nullptr);
  MapStringString_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringString_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapStringStringTest, InsertAssignAccessErase) {
  EXPECT_TRUE(String_equal(MapStringString_at(map, PairStringString_first(p1)),
                           PairStringString_second(p1)));
  MapStringString_erase(map, PairStringString_first(p1));
  EXPECT_FALSE(MapStringString_contains(map, PairStringString_first(p1)));
  set_last_error(0, nullptr);
  MapStringString_insert_or_assign(          nullptr, PairStringString_first(p1), PairStringString_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringString_insert_or_assign(                   map, nullptr, PairStringString_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringString_insert_or_assign(                   map, PairStringString_first(p1), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringString_insert(          nullptr, PairStringString_first(p1), PairStringString_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringString_insert(map, nullptr, PairStringString_second(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringString_insert(map, PairStringString_first(p1), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringString_at(nullptr, PairStringString_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringString_at(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringString_erase(nullptr, PairStringString_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringString_erase(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapStringStringTest, SizeEmptyClearContains) {
  EXPECT_EQ(MapStringString_size(map), 2);
  EXPECT_FALSE(MapStringString_empty(map));
  MapStringString_clear(map);
  EXPECT_TRUE(MapStringString_empty(map));
  set_last_error(0, nullptr);
  MapStringString_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringString_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringString_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringString_contains(nullptr, PairStringString_first(p1));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringString_contains(map2, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapStringStringTest, KeysValuesItems) {
  EXPECT_NE(MapStringString_keys(map), nullptr);
  EXPECT_NE(MapStringString_values(map), nullptr);
  EXPECT_NE(MapStringString_items(map), nullptr);
  set_last_error(0, nullptr);
  MapStringString_keys(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringString_values(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringString_items(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapStringStringTest, Equality) {
  EXPECT_TRUE(MapStringString_equal(map, map2));
  EXPECT_FALSE(MapStringString_not_equal(map, map2));
  set_last_error(0, nullptr);
  MapStringString_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringString_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringString_not_equal(nullptr, map2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringString_not_equal(map, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MapStringStringTest, ToJsonFromJson) {
  auto json = MapStringString_to_json_string(map);
  auto m2   = MapStringString_from_json_string(json);
  EXPECT_TRUE(MapStringString_equal(map, m2));
  MapStringString_destroy(m2);
  String_destroy(json);
  set_last_error(0, nullptr);
  MapStringString_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MapStringString_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
