#include <falcon-core/generic/ListMapStringBool_c_api.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon-core/generic/PairStringBool_c_api.h"

class ListMapStringBoolTest : public ::testing::Test {
 protected:
  void TearDown() override {
    for (auto sh : created_strings) MapStringBool_destroy(sh);
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
  set_last_error(0, nullptr);
  ListMapStringBool_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
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
  set_last_error(0, nullptr);
  ListMapStringBool_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListMapStringBool_destroy(handle);
}

TEST_F(ListMapStringBoolTest, SizeEmptyInvalid) {
  auto handle = ListMapStringBool_create_empty();
  EXPECT_EQ(ListMapStringBool_size(handle), 0);
  ListMapStringBool_destroy(handle);
  set_last_error(0, nullptr);
  ListMapStringBool_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListMapStringBoolTest, EmptyInvalid) {
  auto handle = ListMapStringBool_create_empty();
  EXPECT_TRUE(ListMapStringBool_empty(handle));
  ListMapStringBool_destroy(handle);
  set_last_error(0, nullptr);
  ListMapStringBool_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListMapStringBoolTest, EraseAtClear) {
  auto handle = ListMapStringBool_fill_value(2, sh1);
  ListMapStringBool_erase_at(handle, 0);
  EXPECT_EQ(ListMapStringBool_size(handle), 1);
  ListMapStringBool_clear(handle);
  EXPECT_TRUE(ListMapStringBool_empty(handle));
  ListMapStringBool_destroy(handle);
  set_last_error(0, nullptr);
  ListMapStringBool_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMapStringBool_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListMapStringBoolTest, PushBackContainsIndex) {
  auto handle = ListMapStringBool_create_empty();
  ListMapStringBool_push_back(handle, sh1);
  EXPECT_TRUE(ListMapStringBool_contains(handle, sh1));
  EXPECT_EQ(ListMapStringBool_index(handle, sh1), 0);
  ListMapStringBool_destroy(handle);
  set_last_error(0, nullptr);
  ListMapStringBool_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMapStringBool_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMapStringBool_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListMapStringBoolTest, ItemsAt) {
  MapStringBoolHandle arr[2] = {sh1, sh2};
  auto                handle = ListMapStringBool_create(arr, 2);
  MapStringBoolHandle out[2];
  EXPECT_EQ(ListMapStringBool_items(handle, out, 2), 2);
  ListMapStringBool_destroy(handle);
  set_last_error(0, nullptr);
  ListMapStringBool_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMapStringBool_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMapStringBool_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
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
  set_last_error(0, nullptr);
  ListMapStringBool_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMapStringBool_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMapStringBool_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMapStringBool_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMapStringBool_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMapStringBool_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
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
  set_last_error(0, nullptr);
  ListMapStringBool_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListMapStringBool_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListMapStringBoolTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListMapStringBool_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListMapStringBoolTest, PushBackNull) {
  auto handle = ListMapStringBool_create_empty();
  set_last_error(0, nullptr);
  ListMapStringBool_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListMapStringBool_destroy(handle);
}

TEST_F(ListMapStringBoolTest, ContainsNull) {
  auto handle = ListMapStringBool_create_empty();
  set_last_error(0, nullptr);
  ListMapStringBool_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListMapStringBool_destroy(handle);
}

TEST_F(ListMapStringBoolTest, IndexNull) {
  auto handle = ListMapStringBool_create_empty();
  set_last_error(0, nullptr);
  ListMapStringBool_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListMapStringBool_destroy(handle);
}

TEST_F(ListMapStringBoolTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListMapStringBool_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListMapStringBoolTest, At) {
  MapStringBoolHandle arr[2] = {sh1, sh2};
  auto                handle = ListMapStringBool_create(arr, 2);
  auto                at0    = ListMapStringBool_at(handle, 0);
  auto                at1    = ListMapStringBool_at(handle, 1);
  ListMapStringBool_destroy(at0);
  ListMapStringBool_destroy(at1);
  ListMapStringBool_destroy(handle);
  set_last_error(0, nullptr);
  ListMapStringBool_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
