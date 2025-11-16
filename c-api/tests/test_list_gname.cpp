#include <falcon_core/generic/ListGname_c_api.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListGnameTest : public ::testing::Test {
 protected:
  void destroy_string(GnameHandle sh) { Gname_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<GnameHandle> created_strings;
  GnameHandle              track_quantity(const GnameHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(Gname_create(String_wrap("name1")));
    sh2 = track_quantity(Gname_create(String_wrap("name2")));
  }
  GnameHandle sh1;
  GnameHandle sh2;
};

TEST_F(ListGnameTest, CreateEmpty) {
  auto handle = ListGname_create_empty();
  EXPECT_TRUE(ListGname_empty(handle));
  EXPECT_EQ(ListGname_size(handle), 0);
  ListGname_destroy(handle);
  set_last_error(0, nullptr);
  ListGname_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListGnameTest, FillValue) {
  auto handle = ListGname_fill_value(3, sh1);
  EXPECT_EQ(ListGname_size(handle), 3);
  ListGname_destroy(handle);
}

TEST_F(ListGnameTest, CreateFromArray) {
  GnameHandle     arr[2] = {sh1, sh2};
  ListGnameHandle handle = ListGname_create(arr, 2);
  EXPECT_EQ(ListGname_size(handle), 2);
  set_last_error(0, nullptr);
  ListGname_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListGname_destroy(handle);
}

TEST_F(ListGnameTest, SizeEmptyInvalid) {
  auto handle = ListGname_create_empty();
  EXPECT_EQ(ListGname_size(handle), 0);
  ListGname_destroy(handle);
  set_last_error(0, nullptr);
  ListGname_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListGnameTest, EmptyInvalid) {
  auto handle = ListGname_create_empty();
  EXPECT_TRUE(ListGname_empty(handle));
  ListGname_destroy(handle);
  set_last_error(0, nullptr);
  ListGname_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListGnameTest, EraseAtClear) {
  auto handle = ListGname_fill_value(2, sh1);
  ListGname_erase_at(handle, 0);
  EXPECT_EQ(ListGname_size(handle), 1);
  ListGname_clear(handle);
  EXPECT_TRUE(ListGname_empty(handle));
  ListGname_destroy(handle);
  set_last_error(0, nullptr);
  ListGname_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListGname_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListGnameTest, PushBackContainsIndex) {
  auto handle = ListGname_create_empty();
  ListGname_push_back(handle, sh1);
  EXPECT_TRUE(ListGname_contains(handle, sh1));
  EXPECT_EQ(ListGname_index(handle, sh1), 0);
  ListGname_destroy(handle);
  set_last_error(0, nullptr);
  ListGname_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListGname_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListGname_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListGnameTest, ItemsAt) {
  GnameHandle arr[2] = {sh1, sh2};
  auto        handle = ListGname_create(arr, 2);
  GnameHandle out[2];
  EXPECT_EQ(ListGname_items(handle, out, 2), 2);
  ListGname_destroy(handle);
  set_last_error(0, nullptr);
  ListGname_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListGname_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListGname_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListGnameTest, EqualNotEqualIntersection) {
  GnameHandle arr[2] = {sh1, sh2};
  auto        h1     = ListGname_create(arr, 2);
  auto        h2     = ListGname_create(arr, 2);
  EXPECT_TRUE(ListGname_equal(h1, h2));
  EXPECT_FALSE(ListGname_not_equal(h1, h2));
  auto h3 = ListGname_intersection(h1, h2);
  EXPECT_EQ(ListGname_size(h3), 2);
  ListGname_destroy(h1);
  ListGname_destroy(h2);
  ListGname_destroy(h3);
  set_last_error(0, nullptr);
  ListGname_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListGname_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListGname_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListGname_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListGname_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListGname_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListGnameTest, ToJsonFromJson) {
  GnameHandle arr[1]  = {sh1};
  auto        handle  = ListGname_create(arr, 1);
  auto        json    = ListGname_to_json_string(handle);
  auto        handle2 = ListGname_from_json_string(json);
  EXPECT_TRUE(ListGname_equal(handle, handle2));
  ListGname_destroy(handle);
  ListGname_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListGname_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListGname_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListGnameTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListGname_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListGnameTest, PushBackNull) {
  auto handle = ListGname_create_empty();
  set_last_error(0, nullptr);
  ListGname_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListGname_destroy(handle);
}

TEST_F(ListGnameTest, ContainsNull) {
  auto handle = ListGname_create_empty();
  set_last_error(0, nullptr);
  ListGname_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListGname_destroy(handle);
}

TEST_F(ListGnameTest, IndexNull) {
  auto handle = ListGname_create_empty();
  set_last_error(0, nullptr);
  ListGname_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListGname_destroy(handle);
}

TEST_F(ListGnameTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListGname_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListGnameTest, At) {
  GnameHandle arr[2] = {sh1, sh2};
  auto        handle = ListGname_create(arr, 2);
  auto        at0    = ListGname_at(handle, 0);
  auto        at1    = ListGname_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListGname_destroy(handle);
  set_last_error(0, nullptr);
  ListGname_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
