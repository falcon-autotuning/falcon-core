#include <falcon_core/generic/ListMapStringBool_c_api.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon_core/generic/PairStringBool_c_api.h"

class ListMapStringBoolTest : public ::testing::Test {
 protected:
  void destroy_string(MapStringBoolHandle sh) { MapStringBool_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<MapStringBoolHandle> created_strings;
  MapStringBoolHandle track_quantity(const MapStringBoolHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    PairStringBoolHandle pair[1] = {
        PairStringBool_create(String_wrap("key"), true)};
    PairStringBoolHandle pair2[1] = {
        PairStringBool_create(String_wrap("key2"), false)};
    sh1 = track_quantity(MapStringBool_create(pair, 1));
    sh2 = track_quantity(MapStringBool_create(pair2, 1));
  }
  MapStringBoolHandle sh1;
  MapStringBoolHandle sh2;
};

TEST_F(ListMapStringBoolTest, CreateEmpty) {
  auto handle = ListMapStringBool_create_empty();
  EXPECT_TRUE(ListMapStringBool_empty(handle));
  EXPECT_EQ(ListMapStringBool_size(handle), 0);
  ListMapStringBool_destroy(handle);
  EXPECT_THROW(ListMapStringBool_destroy(nullptr), std::invalid_argument);
}

TEST_F(ListMapStringBoolTest, FillValue) {
  auto handle = ListMapStringBool_fill_value(3, sh1);
  EXPECT_EQ(ListMapStringBool_size(handle), 3);
  ListMapStringBool_destroy(handle);
}

TEST_F(ListMapStringBoolTest, CreateFromArray) {
  MapStringBoolHandle     arr[2] = {sh1, sh2};
  ListMapStringBoolHandle handle = ListMapStringBool_create(arr, 2);
  EXPECT_EQ(ListMapStringBool_size(handle), 2);
  EXPECT_THROW(ListMapStringBool_create(nullptr, 2), std::invalid_argument);
  ListMapStringBool_destroy(handle);
}

TEST_F(ListMapStringBoolTest, SizeEmptyInvalid) {
  auto handle = ListMapStringBool_create_empty();
  EXPECT_EQ(ListMapStringBool_size(handle), 0);
  ListMapStringBool_destroy(handle);
  EXPECT_THROW(ListMapStringBool_size(nullptr), std::invalid_argument);
}

TEST_F(ListMapStringBoolTest, EmptyInvalid) {
  auto handle = ListMapStringBool_create_empty();
  EXPECT_TRUE(ListMapStringBool_empty(handle));
  ListMapStringBool_destroy(handle);
  EXPECT_THROW(ListMapStringBool_empty(nullptr), std::invalid_argument);
}

TEST_F(ListMapStringBoolTest, EraseAtClear) {
  auto handle = ListMapStringBool_fill_value(2, sh1);
  ListMapStringBool_erase_at(handle, 0);
  EXPECT_EQ(ListMapStringBool_size(handle), 1);
  ListMapStringBool_clear(handle);
  EXPECT_TRUE(ListMapStringBool_empty(handle));
  ListMapStringBool_destroy(handle);
  EXPECT_THROW(ListMapStringBool_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ListMapStringBool_clear(nullptr), std::invalid_argument);
}

TEST_F(ListMapStringBoolTest, PushBackContainsIndex) {
  auto handle = ListMapStringBool_create_empty();
  ListMapStringBool_push_back(handle, sh1);
  EXPECT_TRUE(ListMapStringBool_contains(handle, sh1));
  EXPECT_EQ(ListMapStringBool_index(handle, sh1), 0);
  ListMapStringBool_destroy(handle);
  EXPECT_THROW(ListMapStringBool_push_back(nullptr, sh1),
               std::invalid_argument);
  EXPECT_THROW(ListMapStringBool_contains(nullptr, sh1), std::invalid_argument);
  EXPECT_THROW(ListMapStringBool_index(nullptr, sh1), std::invalid_argument);
}

TEST_F(ListMapStringBoolTest, ItemsAt) {
  MapStringBoolHandle arr[2] = {sh1, sh2};
  auto                handle = ListMapStringBool_create(arr, 2);
  MapStringBoolHandle out[2];
  EXPECT_EQ(ListMapStringBool_items(handle, out, 2), 2);
  ListMapStringBool_destroy(handle);
  EXPECT_THROW(ListMapStringBool_items(nullptr, out, 2), std::invalid_argument);
  EXPECT_THROW(ListMapStringBool_items(handle, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ListMapStringBool_at(nullptr, 0), std::invalid_argument);
}

TEST_F(ListMapStringBoolTest, EqualNotEqualIntersection) {
  MapStringBoolHandle arr[2] = {sh1, sh2};
  auto                h1     = ListMapStringBool_create(arr, 2);
  auto                h2     = ListMapStringBool_create(arr, 2);
  EXPECT_TRUE(ListMapStringBool_equal(h1, h2));
  EXPECT_FALSE(ListMapStringBool_not_equal(h1, h2));
  auto h3 = ListMapStringBool_intersection(h1, h2);
  EXPECT_EQ(ListMapStringBool_size(h3), 2);
  ListMapStringBool_destroy(h1);
  ListMapStringBool_destroy(h2);
  ListMapStringBool_destroy(h3);
  EXPECT_THROW(ListMapStringBool_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListMapStringBool_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListMapStringBool_not_equal(h1, nullptr), std::invalid_argument);
  EXPECT_THROW(ListMapStringBool_not_equal(nullptr, h2), std::invalid_argument);
  EXPECT_THROW(ListMapStringBool_intersection(nullptr, h2),
               std::invalid_argument);
  EXPECT_THROW(ListMapStringBool_intersection(h1, nullptr),
               std::invalid_argument);
}

TEST_F(ListMapStringBoolTest, ToJsonFromJson) {
  MapStringBoolHandle arr[1]  = {sh1};
  auto                handle  = ListMapStringBool_create(arr, 1);
  auto                json    = ListMapStringBool_to_json_string(handle);
  auto                handle2 = ListMapStringBool_from_json_string(json);
  EXPECT_TRUE(ListMapStringBool_equal(handle, handle2));
  ListMapStringBool_destroy(handle);
  ListMapStringBool_destroy(handle2);
  String_destroy(json);
  EXPECT_THROW(ListMapStringBool_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(ListMapStringBool_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(ListMapStringBoolTest, FillValueNull) {
  EXPECT_THROW(ListMapStringBool_fill_value(3, nullptr), std::invalid_argument);
}

TEST_F(ListMapStringBoolTest, PushBackNull) {
  auto handle = ListMapStringBool_create_empty();
  EXPECT_THROW(ListMapStringBool_push_back(handle, nullptr),
               std::invalid_argument);
  ListMapStringBool_destroy(handle);
}

TEST_F(ListMapStringBoolTest, ContainsNull) {
  auto handle = ListMapStringBool_create_empty();
  EXPECT_THROW(ListMapStringBool_contains(handle, nullptr),
               std::invalid_argument);
  ListMapStringBool_destroy(handle);
}

TEST_F(ListMapStringBoolTest, IndexNull) {
  auto handle = ListMapStringBool_create_empty();
  EXPECT_THROW(ListMapStringBool_index(handle, nullptr), std::invalid_argument);
  ListMapStringBool_destroy(handle);
}

TEST_F(ListMapStringBoolTest, CreateNullArray) {
  EXPECT_THROW(ListMapStringBool_create(nullptr, 2), std::invalid_argument);
}

TEST_F(ListMapStringBoolTest, At) {
  MapStringBoolHandle arr[2] = {sh1, sh2};
  auto                handle = ListMapStringBool_create(arr, 2);
  auto                at0    = ListMapStringBool_at(handle, 0);
  auto                at1    = ListMapStringBool_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListMapStringBool_destroy(handle);
  EXPECT_THROW(ListMapStringBool_at(nullptr, 0), std::invalid_argument);
}
