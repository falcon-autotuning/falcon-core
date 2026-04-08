#include <falcon-core/generic/ListPairFloatFloat_c_api.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListPairFloatFloatTest : public ::testing::Test {
 protected:
  void destroy_string(PairFloatFloatHandle sh) { PairFloatFloat_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<PairFloatFloatHandle> created_strings;
  PairFloatFloatHandle track_quantity(const PairFloatFloatHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(PairFloatFloat_create(1.0, 2.3));
    sh2 = track_quantity(PairFloatFloat_create(4.4, 5.1));
  }
  PairFloatFloatHandle sh1;
  PairFloatFloatHandle sh2;
};

TEST_F(ListPairFloatFloatTest, CreateEmpty) {
  auto handle = ListPairFloatFloat_create_empty();
  EXPECT_TRUE(ListPairFloatFloat_empty(handle));
  EXPECT_EQ(ListPairFloatFloat_size(handle), 0);
  ListPairFloatFloat_destroy(handle);
  set_last_error(0, nullptr);
  ListPairFloatFloat_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairFloatFloatTest, FillValue) {
  auto handle = ListPairFloatFloat_fill_value(3, sh1);
  EXPECT_EQ(ListPairFloatFloat_size(handle), 3);
  ListPairFloatFloat_destroy(handle);
}

TEST_F(ListPairFloatFloatTest, CreateFromArray) {
  PairFloatFloatHandle     arr[2] = {sh1, sh2};
  ListPairFloatFloatHandle handle = ListPairFloatFloat_create(arr, 2);
  EXPECT_EQ(ListPairFloatFloat_size(handle), 2);
  set_last_error(0, nullptr);
  ListPairFloatFloat_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairFloatFloat_destroy(handle);
}

TEST_F(ListPairFloatFloatTest, SizeEmptyInvalid) {
  auto handle = ListPairFloatFloat_create_empty();
  EXPECT_EQ(ListPairFloatFloat_size(handle), 0);
  ListPairFloatFloat_destroy(handle);
  set_last_error(0, nullptr);
  ListPairFloatFloat_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairFloatFloatTest, EmptyInvalid) {
  auto handle = ListPairFloatFloat_create_empty();
  EXPECT_TRUE(ListPairFloatFloat_empty(handle));
  ListPairFloatFloat_destroy(handle);
  set_last_error(0, nullptr);
  ListPairFloatFloat_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairFloatFloatTest, EraseAtClear) {
  auto handle = ListPairFloatFloat_fill_value(2, sh1);
  ListPairFloatFloat_erase_at(handle, 0);
  EXPECT_EQ(ListPairFloatFloat_size(handle), 1);
  ListPairFloatFloat_clear(handle);
  EXPECT_TRUE(ListPairFloatFloat_empty(handle));
  ListPairFloatFloat_destroy(handle);
  set_last_error(0, nullptr);
  ListPairFloatFloat_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairFloatFloat_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairFloatFloatTest, PushBackContainsIndex) {
  auto handle = ListPairFloatFloat_create_empty();
  ListPairFloatFloat_push_back(handle, sh1);
  EXPECT_TRUE(ListPairFloatFloat_contains(handle, sh1));
  EXPECT_EQ(ListPairFloatFloat_index(handle, sh1), 0);
  ListPairFloatFloat_destroy(handle);
  set_last_error(0, nullptr);
  ListPairFloatFloat_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairFloatFloat_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairFloatFloat_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairFloatFloatTest, ItemsAt) {
  PairFloatFloatHandle arr[2] = {sh1, sh2};
  auto                 handle = ListPairFloatFloat_create(arr, 2);
  PairFloatFloatHandle out[2];
  EXPECT_EQ(ListPairFloatFloat_items(handle, out, 2), 2);
  ListPairFloatFloat_destroy(handle);
  set_last_error(0, nullptr);
  ListPairFloatFloat_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairFloatFloat_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairFloatFloat_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairFloatFloatTest, EqualNotEqualIntersection) {
  PairFloatFloatHandle arr[2] = {sh1, sh2};
  auto                 h1     = ListPairFloatFloat_create(arr, 2);
  auto                 h2     = ListPairFloatFloat_create(arr, 2);
  EXPECT_TRUE(ListPairFloatFloat_equal(h1, h2));
  EXPECT_FALSE(ListPairFloatFloat_not_equal(h1, h2));
  auto h3 = ListPairFloatFloat_intersection(h1, h2);
  EXPECT_EQ(ListPairFloatFloat_size(h3), 2);
  ListPairFloatFloat_destroy(h1);
  ListPairFloatFloat_destroy(h2);
  ListPairFloatFloat_destroy(h3);
  set_last_error(0, nullptr);
  ListPairFloatFloat_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairFloatFloat_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairFloatFloat_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairFloatFloat_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairFloatFloat_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairFloatFloat_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairFloatFloatTest, ToJsonFromJson) {
  PairFloatFloatHandle arr[1]  = {sh1};
  auto                 handle  = ListPairFloatFloat_create(arr, 1);
  auto                 json    = ListPairFloatFloat_to_json_string(handle);
  auto                 handle2 = ListPairFloatFloat_from_json_string(json);
  EXPECT_TRUE(ListPairFloatFloat_equal(handle, handle2));
  ListPairFloatFloat_destroy(handle);
  ListPairFloatFloat_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListPairFloatFloat_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairFloatFloat_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairFloatFloatTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListPairFloatFloat_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairFloatFloatTest, PushBackNull) {
  auto handle = ListPairFloatFloat_create_empty();
  set_last_error(0, nullptr);
  ListPairFloatFloat_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairFloatFloat_destroy(handle);
}

TEST_F(ListPairFloatFloatTest, ContainsNull) {
  auto handle = ListPairFloatFloat_create_empty();
  set_last_error(0, nullptr);
  ListPairFloatFloat_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairFloatFloat_destroy(handle);
}

TEST_F(ListPairFloatFloatTest, IndexNull) {
  auto handle = ListPairFloatFloat_create_empty();
  set_last_error(0, nullptr);
  ListPairFloatFloat_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairFloatFloat_destroy(handle);
}

TEST_F(ListPairFloatFloatTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListPairFloatFloat_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairFloatFloatTest, At) {
  PairFloatFloatHandle arr[2] = {sh1, sh2};
  auto                 handle = ListPairFloatFloat_create(arr, 2);
  auto                 at0    = ListPairFloatFloat_at(handle, 0);
  auto                 at1    = ListPairFloatFloat_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPairFloatFloat_destroy(handle);
  set_last_error(0, nullptr);
  ListPairFloatFloat_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
