#include <falcon-core/generic/ListFArrayDouble_c_api.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListFArrayDoubleTest : public ::testing::Test {
 protected:
  void destroy_string(FArrayDoubleHandle sh) { FArrayDouble_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<FArrayDoubleHandle> created_strings;
  FArrayDoubleHandle              track_quantity(const FArrayDoubleHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    double arr1[3]  = {1.0, 5.0, 8.0};
    size_t shape[1] = {3};
    double arr2[3]  = {2.0, 3.0, 4.0};
    sh1             = track_quantity(FArrayDouble_from_data(arr1, shape, 1));
    sh2             = track_quantity(FArrayDouble_from_data(arr2, shape, 1));
  }
  FArrayDoubleHandle sh1;
  FArrayDoubleHandle sh2;
};

TEST_F(ListFArrayDoubleTest, CreateEmpty) {
  auto handle = ListFArrayDouble_create_empty();
  EXPECT_TRUE(ListFArrayDouble_empty(handle));
  EXPECT_EQ(ListFArrayDouble_size(handle), 0);
  ListFArrayDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListFArrayDouble_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListFArrayDoubleTest, FillValue) {
  auto handle = ListFArrayDouble_fill_value(3, sh1);
  EXPECT_EQ(ListFArrayDouble_size(handle), 3);
  ListFArrayDouble_destroy(handle);
}

TEST_F(ListFArrayDoubleTest, CreateFromArray) {
  FArrayDoubleHandle     arr[2] = {sh1, sh2};
  ListFArrayDoubleHandle handle = ListFArrayDouble_create(arr, 2);
  EXPECT_EQ(ListFArrayDouble_size(handle), 2);
  set_last_error(0, nullptr);
  ListFArrayDouble_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListFArrayDouble_destroy(handle);
}

TEST_F(ListFArrayDoubleTest, SizeEmptyInvalid) {
  auto handle = ListFArrayDouble_create_empty();
  EXPECT_EQ(ListFArrayDouble_size(handle), 0);
  ListFArrayDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListFArrayDouble_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListFArrayDoubleTest, EmptyInvalid) {
  auto handle = ListFArrayDouble_create_empty();
  EXPECT_TRUE(ListFArrayDouble_empty(handle));
  ListFArrayDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListFArrayDouble_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListFArrayDoubleTest, EraseAtClear) {
  auto handle = ListFArrayDouble_fill_value(2, sh1);
  ListFArrayDouble_erase_at(handle, 0);
  EXPECT_EQ(ListFArrayDouble_size(handle), 1);
  ListFArrayDouble_clear(handle);
  EXPECT_TRUE(ListFArrayDouble_empty(handle));
  ListFArrayDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListFArrayDouble_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListFArrayDouble_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListFArrayDoubleTest, PushBackContainsIndex) {
  auto handle = ListFArrayDouble_create_empty();
  ListFArrayDouble_push_back(handle, sh1);
  EXPECT_TRUE(ListFArrayDouble_contains(handle, sh1));
  EXPECT_EQ(ListFArrayDouble_index(handle, sh1), 0);
  ListFArrayDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListFArrayDouble_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListFArrayDouble_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListFArrayDouble_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListFArrayDoubleTest, ItemsAt) {
  FArrayDoubleHandle arr[2] = {sh1, sh2};
  auto               handle = ListFArrayDouble_create(arr, 2);
  FArrayDoubleHandle out[2];
  EXPECT_EQ(ListFArrayDouble_items(handle, out, 2), 2);
  ListFArrayDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListFArrayDouble_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListFArrayDouble_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListFArrayDouble_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListFArrayDoubleTest, EqualNotEqualIntersection) {
  FArrayDoubleHandle arr[2] = {sh1, sh2};
  auto               h1     = ListFArrayDouble_create(arr, 2);
  auto               h2     = ListFArrayDouble_create(arr, 2);
  EXPECT_TRUE(ListFArrayDouble_equal(h1, h2));
  EXPECT_FALSE(ListFArrayDouble_not_equal(h1, h2));
  auto h3 = ListFArrayDouble_intersection(h1, h2);
  EXPECT_EQ(ListFArrayDouble_size(h3), 2);
  ListFArrayDouble_destroy(h1);
  ListFArrayDouble_destroy(h2);
  ListFArrayDouble_destroy(h3);
  set_last_error(0, nullptr);
  ListFArrayDouble_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListFArrayDouble_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListFArrayDouble_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListFArrayDouble_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListFArrayDouble_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListFArrayDouble_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListFArrayDoubleTest, ToJsonFromJson) {
  FArrayDoubleHandle arr[1]  = {sh1};
  auto               handle  = ListFArrayDouble_create(arr, 1);
  auto               json    = ListFArrayDouble_to_json_string(handle);
  auto               handle2 = ListFArrayDouble_from_json_string(json);
  EXPECT_TRUE(ListFArrayDouble_equal(handle, handle2));
  ListFArrayDouble_destroy(handle);
  ListFArrayDouble_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListFArrayDouble_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListFArrayDouble_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListFArrayDoubleTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListFArrayDouble_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListFArrayDoubleTest, PushBackNull) {
  auto handle = ListFArrayDouble_create_empty();
  set_last_error(0, nullptr);
  ListFArrayDouble_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListFArrayDouble_destroy(handle);
}

TEST_F(ListFArrayDoubleTest, ContainsNull) {
  auto handle = ListFArrayDouble_create_empty();
  set_last_error(0, nullptr);
  ListFArrayDouble_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListFArrayDouble_destroy(handle);
}

TEST_F(ListFArrayDoubleTest, IndexNull) {
  auto handle = ListFArrayDouble_create_empty();
  set_last_error(0, nullptr);
  ListFArrayDouble_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListFArrayDouble_destroy(handle);
}

TEST_F(ListFArrayDoubleTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListFArrayDouble_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListFArrayDoubleTest, At) {
  FArrayDoubleHandle arr[2] = {sh1, sh2};
  auto               handle = ListFArrayDouble_create(arr, 2);
  auto               at0    = ListFArrayDouble_at(handle, 0);
  auto               at1    = ListFArrayDouble_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListFArrayDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListFArrayDouble_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
