#include <falcon_core/generic/ListMapStringBool_c_api.h>
#include <falcon_core/math/AxesMapStringBool_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon_core/generic/MapStringBool_c_api.h"
#include "falcon_core/generic/PairStringBool_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/AxesMapStringBool_c_api.h"

class AxesMapStringBoolTest : public ::testing::Test {
 protected:
  void TearDown() override {
    String_destroy(str1);
    String_destroy(str2);
    AxesMapStringBool_destroy(sh1);
    AxesMapStringBool_destroy(sh2);
  }

  void SetUp() override {
    str1                          = String_wrap("key");
    str2                          = String_wrap("key2");
    PairStringBoolHandle pair[1]  = {PairStringBool_create(str1, true)};
    PairStringBoolHandle pair2[1] = {PairStringBool_create(str2, false)};

    MapStringBoolHandle map_pair[1]  = {MapStringBool_create(pair, 1)};
    MapStringBoolHandle map_pair2[1] = {MapStringBool_create(pair2, 1)};

    ListMapStringBoolHandle list_map_pair =
        ListMapStringBool_create(map_pair, 1);
    ListMapStringBoolHandle list_map_pair2 =
        ListMapStringBool_create(map_pair2, 1);

    sh1 = AxesMapStringBool_create(list_map_pair);
    sh2 = AxesMapStringBool_create(list_map_pair2);
  }
  AxesMapStringBoolHandle sh1;
  AxesMapStringBoolHandle sh2;
  StringHandle            str1;
  StringHandle            str2;
};

TEST_F(AxesMapStringBoolTest, CreateEmpty) {
  auto handle = AxesMapStringBool_create_empty();
  EXPECT_TRUE(AxesMapStringBool_empty(handle));
  EXPECT_EQ(AxesMapStringBool_size(handle), 0);
  AxesMapStringBool_destroy(handle);
  EXPECT_THROW(AxesMapStringBool_destroy(nullptr), std::invalid_argument);
}

TEST_F(AxesMapStringBoolTest, CreateDestroy) {
  auto h = AxesMapStringBool_create_empty();
  AxesMapStringBool_destroy(h);
  EXPECT_THROW(AxesMapStringBool_create(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesMapStringBool_destroy(nullptr), std::invalid_argument);
  StringHandle         str3     = String_wrap("key3");
  PairStringBoolHandle pair3[1] = {PairStringBool_create(str3, true)};

  MapStringBoolHandle map_pair3[1] = {MapStringBool_create(pair3, 1)};
  //
  auto h1 = AxesMapStringBool_create_raw(map_pair3, 1);
}
//
TEST_F(AxesMapStringBoolTest, AccessorsAndMutators) {
  MapStringBoolHandle rawbuffer[1];
  EXPECT_NO_THROW(AxesMapStringBool_items(sh1, rawbuffer, 1));
  StringHandle         str3     = String_wrap("key3");
  PairStringBoolHandle pair3[1] = {PairStringBool_create(str3, true)};

  MapStringBoolHandle map_pair3[1] = {MapStringBool_create(pair3, 1)};

  ListMapStringBoolHandle list_map_pair3 =
      ListMapStringBool_create(map_pair3, 1);

  AxesMapStringBoolHandle sh3 = AxesMapStringBool_create(list_map_pair3);
  AxesMapStringBool_erase_at(sh3, 0);
}

TEST_F(AxesMapStringBoolTest, CanClear) {
  MapStringBoolHandle rawbuffer[1];
  EXPECT_NO_THROW(AxesMapStringBool_items(sh1, rawbuffer, 1));
  StringHandle         str3     = String_wrap("key3");
  PairStringBoolHandle pair3[1] = {PairStringBool_create(str3, true)};

  MapStringBoolHandle map_pair3[1] = {MapStringBool_create(pair3, 1)};

  ListMapStringBoolHandle list_map_pair3 =
      ListMapStringBool_create(map_pair3, 1);

  AxesMapStringBoolHandle sh3 = AxesMapStringBool_create(list_map_pair3);
  AxesMapStringBool_clear(sh3);
}

TEST_F(AxesMapStringBoolTest, ContainsIndexEquality) {
  EXPECT_NO_THROW(
      AxesMapStringBool_contains(sh1, AxesMapStringBool_at(sh1, 0)));

  EXPECT_NO_THROW(AxesMapStringBool_index(sh1, AxesMapStringBool_at(sh1, 0)));
  EXPECT_NO_THROW(AxesMapStringBool_equal(sh1, sh2));
}

TEST_F(AxesMapStringBoolTest, SerializationRoundTrip) {
  EXPECT_THROW(AxesMapStringBool_from_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesMapStringBool_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_NO_THROW({
    auto json   = AxesMapStringBool_to_json_string(sh1);
    auto loaded = AxesMapStringBool_from_json_string(json);
    AxesMapStringBool_destroy(loaded);
    String_destroy(json);
  });
}

TEST_F(AxesMapStringBoolTest, EqualityWorks) {
  EXPECT_THROW(AxesMapStringBool_equal(sh1, nullptr), std::invalid_argument);
  EXPECT_THROW(AxesMapStringBool_not_equal(nullptr, sh1),
               std::invalid_argument);
  EXPECT_NO_THROW(AxesMapStringBool_equal(sh1, sh1));
  EXPECT_NO_THROW(AxesMapStringBool_not_equal(sh1, sh2));
}

TEST_F(AxesMapStringBoolTest, Intersection) {
  EXPECT_THROW(AxesMapStringBool_intersection(nullptr, sh2),
               std::invalid_argument);
  EXPECT_THROW(AxesMapStringBool_intersection(sh1, nullptr),
               std::invalid_argument);
  EXPECT_NO_THROW(AxesMapStringBool_intersection(sh1, sh2));
}

TEST_F(AxesMapStringBoolTest, MiscNullChecks) {
  EXPECT_THROW(AxesMapStringBool_destroy(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesMapStringBool_push_back(nullptr, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesMapStringBool_push_back(sh1, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AxesMapStringBool_size(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesMapStringBool_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesMapStringBool_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesMapStringBool_clear(nullptr), std::invalid_argument);
  EXPECT_THROW(AxesMapStringBool_push_back(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesMapStringBool_contains(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesMapStringBool_contains(sh1, nullptr), std::invalid_argument);
  EXPECT_THROW(AxesMapStringBool_index(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesMapStringBool_index(sh1, nullptr), std::invalid_argument);
  MapStringBoolHandle rawbuffer[2];
  EXPECT_THROW(AxesMapStringBool_items(nullptr, rawbuffer, 2),
               std::invalid_argument);
  EXPECT_THROW(AxesMapStringBool_items(sh1, nullptr, 2), std::invalid_argument);
  EXPECT_THROW(AxesMapStringBool_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(AxesMapStringBool_create_raw(nullptr, 2), std::invalid_argument);
}
