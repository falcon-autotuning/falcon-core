#include <falcon-core/generic/ListString_c_api.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <string>
#include <vector>

class ListStringTest : public ::testing::Test {
 protected:
  StringHandle make_json(const std::string& s) {
    return String_create(s.c_str(), s.size());
  }
  void destroy_string(StringHandle sh) { String_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<StringHandle> created_strings;
  StringHandle              track_string(const std::string& s) {
    auto sh = make_json(s);
    created_strings.push_back(sh);
    return sh;
  }
  void SetUp() override {
    sh1 = track_string("one");
    sh2 = track_string("two");
  }
  StringHandle sh1;
  StringHandle sh2;
};

TEST_F(ListStringTest, CreateEmpty) {
  auto handle = ListString_create_empty();
  EXPECT_TRUE(ListString_empty(handle));
  EXPECT_EQ(ListString_size(handle), 0);
  ListString_destroy(handle);
  set_last_error(0, nullptr);
  ListString_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListStringTest, FillValue) {
  auto handle = ListString_fill_value(3, sh1);
  EXPECT_EQ(ListString_size(handle), 3);
  ListString_destroy(handle);
}

TEST_F(ListStringTest, Allocate) {
  auto handle = ListString_allocate(5);
  EXPECT_EQ(ListString_size(handle), 5);
  ListString_destroy(handle);
}

TEST_F(ListStringTest, CreateFromArray) {
  StringHandle     arr[2] = {sh1, sh2};
  ListStringHandle handle = ListString_create(arr, 2);
  EXPECT_EQ(ListString_size(handle), 2);
  set_last_error(0, nullptr);
  ListString_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListString_destroy(handle);
}

TEST_F(ListStringTest, SizeEmptyInvalid) {
  auto handle = ListString_create_empty();
  EXPECT_EQ(ListString_size(handle), 0);
  ListString_destroy(handle);
  set_last_error(0, nullptr);
  ListString_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListStringTest, EmptyInvalid) {
  auto handle = ListString_create_empty();
  EXPECT_TRUE(ListString_empty(handle));
  ListString_destroy(handle);
  set_last_error(0, nullptr);
  ListString_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListStringTest, EraseAtClear) {
  auto handle = ListString_fill_value(2, sh1);
  ListString_erase_at(handle, 0);
  EXPECT_EQ(ListString_size(handle), 1);
  ListString_clear(handle);
  EXPECT_TRUE(ListString_empty(handle));
  ListString_destroy(handle);
  set_last_error(0, nullptr);
  ListString_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListString_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListStringTest, PushBackContainsIndex) {
  auto handle = ListString_create_empty();
  ListString_push_back(handle, sh1);
  EXPECT_TRUE(ListString_contains(handle, sh1));
  EXPECT_EQ(ListString_index(handle, sh1), 0);
  ListString_destroy(handle);
  set_last_error(0, nullptr);
  ListString_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListString_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListString_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListStringTest, ItemsAt) {
  StringHandle arr[2] = {sh1, sh2};
  auto         handle = ListString_create(arr, 2);
  StringHandle out[2];
  EXPECT_EQ(ListString_items(handle, out, 2), 2);
  ListString_destroy(handle);
  set_last_error(0, nullptr);
  ListString_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListString_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListString_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListStringTest, EqualNotEqualIntersection) {
  StringHandle arr[2] = {sh1, sh2};
  auto         h1     = ListString_create(arr, 2);
  auto         h2     = ListString_create(arr, 2);
  EXPECT_TRUE(ListString_equal(h1, h2));
  EXPECT_FALSE(ListString_not_equal(h1, h2));
  auto h3 = ListString_intersection(h1, h2);
  EXPECT_EQ(ListString_size(h3), 2);
  ListString_destroy(h1);
  ListString_destroy(h2);
  ListString_destroy(h3);
  set_last_error(0, nullptr);
  ListString_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListString_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListString_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListString_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListString_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListString_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListStringTest, ToJsonFromJson) {
  StringHandle arr[1]  = {sh1};
  auto         handle  = ListString_create(arr, 1);
  auto         json    = ListString_to_json_string(handle);
  auto         handle2 = ListString_from_json_string(json);
  EXPECT_TRUE(ListString_equal(handle, handle2));
  ListString_destroy(handle);
  ListString_destroy(handle2);
  destroy_string(json);
  set_last_error(0, nullptr);
  ListString_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListString_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListStringTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListString_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListStringTest, PushBackNull) {
  auto handle = ListString_create_empty();
  set_last_error(0, nullptr);
  ListString_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListString_destroy(handle);
}

TEST_F(ListStringTest, ContainsNull) {
  auto handle = ListString_create_empty();
  set_last_error(0, nullptr);
  ListString_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListString_destroy(handle);
}

TEST_F(ListStringTest, IndexNull) {
  auto handle = ListString_create_empty();
  set_last_error(0, nullptr);
  ListString_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListString_destroy(handle);
}

TEST_F(ListStringTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListString_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}
