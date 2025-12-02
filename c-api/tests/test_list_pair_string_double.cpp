#include <falcon_core/generic/ListPairStringDouble_c_api.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListPairStringDoubleTest : public ::testing::Test {
 protected:
  void destroy_string(PairStringDoubleHandle sh) {
    PairStringDouble_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<PairStringDoubleHandle> created_strings;
  PairStringDoubleHandle track_quantity(const PairStringDoubleHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(PairStringDouble_create(String_wrap("name1"), 1.0));
    sh2 = track_quantity(PairStringDouble_create(String_wrap("name2"), 2.0));
  }
  PairStringDoubleHandle sh1;
  PairStringDoubleHandle sh2;
};

TEST_F(ListPairStringDoubleTest, CreateEmpty) {
  auto handle = ListPairStringDouble_create_empty();
  EXPECT_TRUE(ListPairStringDouble_empty(handle));
  EXPECT_EQ(ListPairStringDouble_size(handle), 0);
  ListPairStringDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListPairStringDouble_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringDoubleTest, FillValue) {
  auto handle = ListPairStringDouble_fill_value(3, sh1);
  EXPECT_EQ(ListPairStringDouble_size(handle), 3);
  ListPairStringDouble_destroy(handle);
}

TEST_F(ListPairStringDoubleTest, CreateFromArray) {
  PairStringDoubleHandle     arr[2] = {sh1, sh2};
  ListPairStringDoubleHandle handle = ListPairStringDouble_create(arr, 2);
  EXPECT_EQ(ListPairStringDouble_size(handle), 2);
  set_last_error(0, nullptr);
  ListPairStringDouble_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairStringDouble_destroy(handle);
}

TEST_F(ListPairStringDoubleTest, SizeEmptyInvalid) {
  auto handle = ListPairStringDouble_create_empty();
  EXPECT_EQ(ListPairStringDouble_size(handle), 0);
  ListPairStringDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListPairStringDouble_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringDoubleTest, EmptyInvalid) {
  auto handle = ListPairStringDouble_create_empty();
  EXPECT_TRUE(ListPairStringDouble_empty(handle));
  ListPairStringDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListPairStringDouble_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringDoubleTest, EraseAtClear) {
  auto handle = ListPairStringDouble_fill_value(2, sh1);
  ListPairStringDouble_erase_at(handle, 0);
  EXPECT_EQ(ListPairStringDouble_size(handle), 1);
  ListPairStringDouble_clear(handle);
  EXPECT_TRUE(ListPairStringDouble_empty(handle));
  ListPairStringDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListPairStringDouble_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringDouble_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringDoubleTest, PushBackContainsIndex) {
  auto handle = ListPairStringDouble_create_empty();
  ListPairStringDouble_push_back(handle, sh1);
  EXPECT_TRUE(ListPairStringDouble_contains(handle, sh1));
  EXPECT_EQ(ListPairStringDouble_index(handle, sh1), 0);
  ListPairStringDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListPairStringDouble_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringDouble_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringDouble_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringDoubleTest, ItemsAt) {
  PairStringDoubleHandle arr[2] = {sh1, sh2};
  auto                   handle = ListPairStringDouble_create(arr, 2);
  PairStringDoubleHandle out[2];
  EXPECT_EQ(ListPairStringDouble_items(handle, out, 2), 2);
  ListPairStringDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListPairStringDouble_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringDouble_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringDouble_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringDoubleTest, EqualNotEqualIntersection) {
  PairStringDoubleHandle arr[2] = {sh1, sh2};
  auto                   h1     = ListPairStringDouble_create(arr, 2);
  auto                   h2     = ListPairStringDouble_create(arr, 2);
  EXPECT_TRUE(ListPairStringDouble_equal(h1, h2));
  EXPECT_FALSE(ListPairStringDouble_not_equal(h1, h2));
  auto h3 = ListPairStringDouble_intersection(h1, h2);
  EXPECT_EQ(ListPairStringDouble_size(h3), 2);
  ListPairStringDouble_destroy(h1);
  ListPairStringDouble_destroy(h2);
  ListPairStringDouble_destroy(h3);
  set_last_error(0, nullptr);
  ListPairStringDouble_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringDouble_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringDouble_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringDouble_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringDouble_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringDouble_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringDoubleTest, ToJsonFromJson) {
  PairStringDoubleHandle arr[1]  = {sh1};
  auto                   handle  = ListPairStringDouble_create(arr, 1);
  auto                   json    = ListPairStringDouble_to_json_string(handle);
  auto                   handle2 = ListPairStringDouble_from_json_string(json);
  EXPECT_TRUE(ListPairStringDouble_equal(handle, handle2));
  ListPairStringDouble_destroy(handle);
  ListPairStringDouble_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListPairStringDouble_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringDouble_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringDoubleTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListPairStringDouble_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringDoubleTest, PushBackNull) {
  auto handle = ListPairStringDouble_create_empty();
  set_last_error(0, nullptr);
  ListPairStringDouble_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairStringDouble_destroy(handle);
}

TEST_F(ListPairStringDoubleTest, ContainsNull) {
  auto handle = ListPairStringDouble_create_empty();
  set_last_error(0, nullptr);
  ListPairStringDouble_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairStringDouble_destroy(handle);
}

TEST_F(ListPairStringDoubleTest, IndexNull) {
  auto handle = ListPairStringDouble_create_empty();
  set_last_error(0, nullptr);
  ListPairStringDouble_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairStringDouble_destroy(handle);
}

TEST_F(ListPairStringDoubleTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListPairStringDouble_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringDoubleTest, At) {
  PairStringDoubleHandle arr[2] = {sh1, sh2};
  auto                   handle = ListPairStringDouble_create(arr, 2);
  auto                   at0    = ListPairStringDouble_at(handle, 0);
  auto                   at1    = ListPairStringDouble_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPairStringDouble_destroy(handle);
  set_last_error(0, nullptr);
  ListPairStringDouble_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
