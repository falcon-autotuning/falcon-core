#include <falcon-core/generic/ListMapStringBool_c_api.h>
#include <falcon-core/math/AxesMapStringBool_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/MapStringBool_c_api.h"
#include "falcon-core/generic/PairStringBool_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/math/AxesMapStringBool_c_api.h"

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
  set_last_error(0, nullptr);
  AxesMapStringBool_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AxesMapStringBoolTest, CreateDestroy) {
  auto h = AxesMapStringBool_create_empty();
  AxesMapStringBool_destroy(h);
  set_last_error(0, nullptr);
  AxesMapStringBool_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesMapStringBool_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

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
  set_last_error(0, nullptr);
  AxesMapStringBool_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesMapStringBool_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW({
    auto json   = AxesMapStringBool_to_json_string(sh1);
    auto loaded = AxesMapStringBool_from_json_string(json);
    AxesMapStringBool_destroy(loaded);
    String_destroy(json);
  });
}

TEST_F(AxesMapStringBoolTest, EqualityWorks) {
  set_last_error(0, nullptr);
  AxesMapStringBool_equal(sh1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesMapStringBool_not_equal(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW(AxesMapStringBool_equal(sh1, sh1));
  EXPECT_NO_THROW(AxesMapStringBool_not_equal(sh1, sh2));
}

TEST_F(AxesMapStringBoolTest, Intersection) {
  set_last_error(0, nullptr);
  AxesMapStringBool_intersection(nullptr, sh2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesMapStringBool_intersection(sh1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  EXPECT_NO_THROW(AxesMapStringBool_intersection(sh1, sh2));
}

TEST_F(AxesMapStringBoolTest, MiscNullChecks) {
  set_last_error(0, nullptr);
  AxesMapStringBool_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesMapStringBool_push_back(nullptr, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesMapStringBool_push_back(sh1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesMapStringBool_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesMapStringBool_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesMapStringBool_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesMapStringBool_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesMapStringBool_push_back(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesMapStringBool_contains(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesMapStringBool_contains(sh1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesMapStringBool_index(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesMapStringBool_index(sh1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  MapStringBoolHandle rawbuffer[2];
  set_last_error(0, nullptr);
  AxesMapStringBool_items(nullptr, rawbuffer, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesMapStringBool_items(sh1, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AxesMapStringBool_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
}
