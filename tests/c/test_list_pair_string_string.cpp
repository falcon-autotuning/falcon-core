#include <falcon-core/generic/ListPairStringString_c_api.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListPairStringStringTest : public ::testing::Test {
 protected:
  void destroy_string(PairStringStringHandle sh) {
    PairStringString_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<PairStringStringHandle> created_strings;
  PairStringStringHandle track_quantity(const PairStringStringHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(
        PairStringString_create(String_wrap("first"), String_wrap("second")));
    sh2 = track_quantity(
        PairStringString_create(String_wrap("third"), String_wrap("fourth")));
  }
  PairStringStringHandle sh1;
  PairStringStringHandle sh2;
};

TEST_F(ListPairStringStringTest, CreateEmpty) {
  auto handle = ListPairStringString_create_empty();
  EXPECT_TRUE(ListPairStringString_empty(handle));
  EXPECT_EQ(ListPairStringString_size(handle), 0);
  ListPairStringString_destroy(handle);
  set_last_error(0, nullptr);
  ListPairStringString_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringStringTest, FillValue) {
  auto handle = ListPairStringString_fill_value(3, sh1);
  EXPECT_EQ(ListPairStringString_size(handle), 3);
  ListPairStringString_destroy(handle);
}

TEST_F(ListPairStringStringTest, CreateFromArray) {
  PairStringStringHandle     arr[2] = {sh1, sh2};
  ListPairStringStringHandle handle = ListPairStringString_create(arr, 2);
  EXPECT_EQ(ListPairStringString_size(handle), 2);
  set_last_error(0, nullptr);
  ListPairStringString_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairStringString_destroy(handle);
}

TEST_F(ListPairStringStringTest, SizeEmptyInvalid) {
  auto handle = ListPairStringString_create_empty();
  EXPECT_EQ(ListPairStringString_size(handle), 0);
  ListPairStringString_destroy(handle);
  set_last_error(0, nullptr);
  ListPairStringString_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringStringTest, EmptyInvalid) {
  auto handle = ListPairStringString_create_empty();
  EXPECT_TRUE(ListPairStringString_empty(handle));
  ListPairStringString_destroy(handle);
  set_last_error(0, nullptr);
  ListPairStringString_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringStringTest, EraseAtClear) {
  auto handle = ListPairStringString_fill_value(2, sh1);
  ListPairStringString_erase_at(handle, 0);
  EXPECT_EQ(ListPairStringString_size(handle), 1);
  ListPairStringString_clear(handle);
  EXPECT_TRUE(ListPairStringString_empty(handle));
  ListPairStringString_destroy(handle);
  set_last_error(0, nullptr);
  ListPairStringString_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringString_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringStringTest, PushBackContainsIndex) {
  auto handle = ListPairStringString_create_empty();
  ListPairStringString_push_back(handle, sh1);
  EXPECT_TRUE(ListPairStringString_contains(handle, sh1));
  EXPECT_EQ(ListPairStringString_index(handle, sh1), 0);
  ListPairStringString_destroy(handle);
  set_last_error(0, nullptr);
  ListPairStringString_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringString_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringString_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringStringTest, ItemsAt) {
  PairStringStringHandle arr[2] = {sh1, sh2};
  auto                   handle = ListPairStringString_create(arr, 2);
  PairStringStringHandle out[2];
  EXPECT_EQ(ListPairStringString_items(handle, out, 2), 2);
  ListPairStringString_destroy(handle);
  set_last_error(0, nullptr);
  ListPairStringString_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringString_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringString_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringStringTest, EqualNotEqualIntersection) {
  PairStringStringHandle arr[2] = {sh1, sh2};
  auto                   h1     = ListPairStringString_create(arr, 2);
  auto                   h2     = ListPairStringString_create(arr, 2);
  EXPECT_TRUE(ListPairStringString_equal(h1, h2));
  EXPECT_FALSE(ListPairStringString_not_equal(h1, h2));
  auto h3 = ListPairStringString_intersection(h1, h2);
  EXPECT_EQ(ListPairStringString_size(h3), 2);
  ListPairStringString_destroy(h1);
  ListPairStringString_destroy(h2);
  ListPairStringString_destroy(h3);
  set_last_error(0, nullptr);
  ListPairStringString_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringString_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringString_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringString_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringString_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringString_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringStringTest, ToJsonFromJson) {
  PairStringStringHandle arr[1]  = {sh1};
  auto                   handle  = ListPairStringString_create(arr, 1);
  auto                   json    = ListPairStringString_to_json_string(handle);
  auto                   handle2 = ListPairStringString_from_json_string(json);
  EXPECT_TRUE(ListPairStringString_equal(handle, handle2));
  ListPairStringString_destroy(handle);
  ListPairStringString_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListPairStringString_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringString_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringStringTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListPairStringString_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringStringTest, PushBackNull) {
  auto handle = ListPairStringString_create_empty();
  set_last_error(0, nullptr);
  ListPairStringString_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairStringString_destroy(handle);
}

TEST_F(ListPairStringStringTest, ContainsNull) {
  auto handle = ListPairStringString_create_empty();
  set_last_error(0, nullptr);
  ListPairStringString_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairStringString_destroy(handle);
}

TEST_F(ListPairStringStringTest, IndexNull) {
  auto handle = ListPairStringString_create_empty();
  set_last_error(0, nullptr);
  ListPairStringString_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairStringString_destroy(handle);
}

TEST_F(ListPairStringStringTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListPairStringString_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringStringTest, At) {
  PairStringStringHandle arr[2] = {sh1, sh2};
  auto                   handle = ListPairStringString_create(arr, 2);
  auto                   at0    = ListPairStringString_at(handle, 0);
  auto                   at1    = ListPairStringString_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPairStringString_destroy(handle);
  set_last_error(0, nullptr);
  ListPairStringString_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
