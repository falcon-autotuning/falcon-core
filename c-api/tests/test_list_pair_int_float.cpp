#include <falcon_core/generic/ListPairIntFloat_c_api.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListPairIntFloatTest : public ::testing::Test {
 protected:
  void destroy_string(PairIntFloatHandle sh) { PairIntFloat_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<PairIntFloatHandle> created_strings;
  PairIntFloatHandle              track_quantity(const PairIntFloatHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(PairIntFloat_create(1, 2.0));
    sh2 = track_quantity(PairIntFloat_create(4, 5.0));
  }
  PairIntFloatHandle sh1;
  PairIntFloatHandle sh2;
};

TEST_F(ListPairIntFloatTest, CreateEmpty) {
  auto handle = ListPairIntFloat_create_empty();
  EXPECT_TRUE(ListPairIntFloat_empty(handle));
  EXPECT_EQ(ListPairIntFloat_size(handle), 0);
  ListPairIntFloat_destroy(handle);
  set_last_error(0, nullptr);
  ListPairIntFloat_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairIntFloatTest, FillValue) {
  auto handle = ListPairIntFloat_fill_value(3, sh1);
  EXPECT_EQ(ListPairIntFloat_size(handle), 3);
  ListPairIntFloat_destroy(handle);
}

TEST_F(ListPairIntFloatTest, CreateFromArray) {
  PairIntFloatHandle     arr[2] = {sh1, sh2};
  ListPairIntFloatHandle handle = ListPairIntFloat_create(arr, 2);
  EXPECT_EQ(ListPairIntFloat_size(handle), 2);
  set_last_error(0, nullptr);
  ListPairIntFloat_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairIntFloat_destroy(handle);
}

TEST_F(ListPairIntFloatTest, SizeEmptyInvalid) {
  auto handle = ListPairIntFloat_create_empty();
  EXPECT_EQ(ListPairIntFloat_size(handle), 0);
  ListPairIntFloat_destroy(handle);
  set_last_error(0, nullptr);
  ListPairIntFloat_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairIntFloatTest, EmptyInvalid) {
  auto handle = ListPairIntFloat_create_empty();
  EXPECT_TRUE(ListPairIntFloat_empty(handle));
  ListPairIntFloat_destroy(handle);
  set_last_error(0, nullptr);
  ListPairIntFloat_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairIntFloatTest, EraseAtClear) {
  auto handle = ListPairIntFloat_fill_value(2, sh1);
  ListPairIntFloat_erase_at(handle, 0);
  EXPECT_EQ(ListPairIntFloat_size(handle), 1);
  ListPairIntFloat_clear(handle);
  EXPECT_TRUE(ListPairIntFloat_empty(handle));
  ListPairIntFloat_destroy(handle);
  set_last_error(0, nullptr);
  ListPairIntFloat_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairIntFloat_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairIntFloatTest, PushBackContainsIndex) {
  auto handle = ListPairIntFloat_create_empty();
  ListPairIntFloat_push_back(handle, sh1);
  EXPECT_TRUE(ListPairIntFloat_contains(handle, sh1));
  EXPECT_EQ(ListPairIntFloat_index(handle, sh1), 0);
  ListPairIntFloat_destroy(handle);
  set_last_error(0, nullptr);
  ListPairIntFloat_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairIntFloat_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairIntFloat_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairIntFloatTest, ItemsAt) {
  PairIntFloatHandle arr[2] = {sh1, sh2};
  auto               handle = ListPairIntFloat_create(arr, 2);
  PairIntFloatHandle out[2];
  EXPECT_EQ(ListPairIntFloat_items(handle, out, 2), 2);
  ListPairIntFloat_destroy(handle);
  set_last_error(0, nullptr);
  ListPairIntFloat_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairIntFloat_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairIntFloat_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairIntFloatTest, EqualNotEqualIntersection) {
  PairIntFloatHandle arr[2] = {sh1, sh2};
  auto               h1     = ListPairIntFloat_create(arr, 2);
  auto               h2     = ListPairIntFloat_create(arr, 2);
  EXPECT_TRUE(ListPairIntFloat_equal(h1, h2));
  EXPECT_FALSE(ListPairIntFloat_not_equal(h1, h2));
  auto h3 = ListPairIntFloat_intersection(h1, h2);
  EXPECT_EQ(ListPairIntFloat_size(h3), 2);
  ListPairIntFloat_destroy(h1);
  ListPairIntFloat_destroy(h2);
  ListPairIntFloat_destroy(h3);
  set_last_error(0, nullptr);
  ListPairIntFloat_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairIntFloat_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairIntFloat_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairIntFloat_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairIntFloat_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairIntFloat_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairIntFloatTest, ToJsonFromJson) {
  PairIntFloatHandle arr[1]  = {sh1};
  auto               handle  = ListPairIntFloat_create(arr, 1);
  auto               json    = ListPairIntFloat_to_json_string(handle);
  auto               handle2 = ListPairIntFloat_from_json_string(json);
  EXPECT_TRUE(ListPairIntFloat_equal(handle, handle2));
  ListPairIntFloat_destroy(handle);
  ListPairIntFloat_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListPairIntFloat_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairIntFloat_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairIntFloatTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListPairIntFloat_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairIntFloatTest, PushBackNull) {
  auto handle = ListPairIntFloat_create_empty();
  set_last_error(0, nullptr);
  ListPairIntFloat_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairIntFloat_destroy(handle);
}

TEST_F(ListPairIntFloatTest, ContainsNull) {
  auto handle = ListPairIntFloat_create_empty();
  set_last_error(0, nullptr);
  ListPairIntFloat_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairIntFloat_destroy(handle);
}

TEST_F(ListPairIntFloatTest, IndexNull) {
  auto handle = ListPairIntFloat_create_empty();
  set_last_error(0, nullptr);
  ListPairIntFloat_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairIntFloat_destroy(handle);
}

TEST_F(ListPairIntFloatTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListPairIntFloat_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairIntFloatTest, At) {
  PairIntFloatHandle arr[2] = {sh1, sh2};
  auto               handle = ListPairIntFloat_create(arr, 2);
  auto               at0    = ListPairIntFloat_at(handle, 0);
  auto               at1    = ListPairIntFloat_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPairIntFloat_destroy(handle);
  set_last_error(0, nullptr);
  ListPairIntFloat_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
