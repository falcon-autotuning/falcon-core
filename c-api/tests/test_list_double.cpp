#include <falcon_core/generic/ListDouble_c_api.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <string>
#include <vector>

class ListDoubleTest : public ::testing::Test {
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
};

TEST_F(ListDoubleTest, CreateEmpty) {
  auto handle = ListDouble_create_empty();
  EXPECT_TRUE(ListDouble_empty(handle));
  EXPECT_EQ(ListDouble_size(handle), 0);
  ListDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListDouble_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListDoubleTest, FillValue) {
  auto handle = ListDouble_fill_value(3, true);
  EXPECT_EQ(ListDouble_size(handle), 3);
  ListDouble_destroy(handle);
}

TEST_F(ListDoubleTest, Allocate) {
  auto handle = ListDouble_allocate(5);
  EXPECT_EQ(ListDouble_size(handle), 5);
  ListDouble_destroy(handle);
}

TEST_F(ListDoubleTest, CreateFromArray) {
  double           arr[2] = {true, false};
  ListDoubleHandle handle = ListDouble_create(arr, 2);
  EXPECT_EQ(ListDouble_size(handle), 2);
  ListDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListDouble_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListDoubleTest, SizeEmptyInvalid) {
  auto handle = ListDouble_create_empty();
  EXPECT_EQ(ListDouble_size(handle), 0);
  ListDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListDouble_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListDoubleTest, EmptyInvalid) {
  auto handle = ListDouble_create_empty();
  EXPECT_TRUE(ListDouble_empty(handle));
  ListDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListDouble_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListDoubleTest, EraseAtClear) {
  auto handle = ListDouble_fill_value(2, true);
  ListDouble_erase_at(handle, 0);
  EXPECT_EQ(ListDouble_size(handle), 1);
  ListDouble_clear(handle);
  EXPECT_TRUE(ListDouble_empty(handle));
  ListDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListDouble_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDouble_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListDoubleTest, PushBackContainsIndex) {
  auto handle = ListDouble_create_empty();
  ListDouble_push_back(handle, true);
  EXPECT_TRUE(ListDouble_contains(handle, true));
  EXPECT_EQ(ListDouble_index(handle, true), 0);
  ListDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListDouble_push_back(nullptr, true);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDouble_contains(nullptr, true);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDouble_index(nullptr, true);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListDoubleTest, ItemsAt) {
  double arr[2] = {true, false};
  auto   handle = ListDouble_create(arr, 2);
  double out[2];
  EXPECT_EQ(ListDouble_items(handle, out, 2), 2);
  EXPECT_EQ(ListDouble_at(handle, 0), true);
  EXPECT_EQ(ListDouble_at(handle, 1), false);
  ListDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListDouble_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDouble_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDouble_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListDoubleTest, EqualNotEqualDoubleersection) {
  double arr[2] = {true, false};
  auto   h1     = ListDouble_create(arr, 2);
  auto   h2     = ListDouble_create(arr, 2);
  EXPECT_TRUE(ListDouble_equal(h1, h2));
  EXPECT_FALSE(ListDouble_not_equal(h1, h2));
  auto h3 = ListDouble_intersection(h1, h2);
  EXPECT_EQ(ListDouble_size(h3), 2);
  ListDouble_destroy(h1);
  ListDouble_destroy(h2);
  ListDouble_destroy(h3);
  set_last_error(0, nullptr);
  ListDouble_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDouble_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDouble_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDouble_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDouble_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDouble_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListDoubleTest, ToJsonFromJson) {
  double arr[1]  = {1.0};
  auto   handle  = ListDouble_create(arr, 1);
  auto   json    = ListDouble_to_json_string(handle);
  auto   handle2 = ListDouble_from_json_string(json);
  EXPECT_TRUE(ListDouble_equal(handle, handle2));
  ListDouble_destroy(handle);
  ListDouble_destroy(handle2);
  destroy_string(json);
  set_last_error(0, nullptr);
  ListDouble_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListDouble_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
