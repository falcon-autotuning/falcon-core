#include <falcon_core/generic/ListPairStringBool_c_api.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"

class ListPairStringBoolTest : public ::testing::Test {
 protected:
  void destroy_string(PairStringBoolHandle sh) { PairStringBool_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<PairStringBoolHandle> created_strings;
  PairStringBoolHandle track_quantity(const PairStringBoolHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    sh1 = track_quantity(PairStringBool_create(String_wrap("name1"), true));
    sh2 = track_quantity(PairStringBool_create(String_wrap("name2"), false));
  }
  PairStringBoolHandle sh1;
  PairStringBoolHandle sh2;
};

TEST_F(ListPairStringBoolTest, CreateEmpty) {
  auto handle = ListPairStringBool_create_empty();
  EXPECT_TRUE(ListPairStringBool_empty(handle));
  EXPECT_EQ(ListPairStringBool_size(handle), 0);
  ListPairStringBool_destroy(handle);
  set_last_error(0, nullptr);
  ListPairStringBool_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringBoolTest, FillValue) {
  auto handle = ListPairStringBool_fill_value(3, sh1);
  EXPECT_EQ(ListPairStringBool_size(handle), 3);
  ListPairStringBool_destroy(handle);
}

TEST_F(ListPairStringBoolTest, CreateFromArray) {
  PairStringBoolHandle     arr[2] = {sh1, sh2};
  ListPairStringBoolHandle handle = ListPairStringBool_create(arr, 2);
  EXPECT_EQ(ListPairStringBool_size(handle), 2);
  set_last_error(0, nullptr);
  ListPairStringBool_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairStringBool_destroy(handle);
}

TEST_F(ListPairStringBoolTest, SizeEmptyInvalid) {
  auto handle = ListPairStringBool_create_empty();
  EXPECT_EQ(ListPairStringBool_size(handle), 0);
  ListPairStringBool_destroy(handle);
  set_last_error(0, nullptr);
  ListPairStringBool_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringBoolTest, EmptyInvalid) {
  auto handle = ListPairStringBool_create_empty();
  EXPECT_TRUE(ListPairStringBool_empty(handle));
  ListPairStringBool_destroy(handle);
  set_last_error(0, nullptr);
  ListPairStringBool_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringBoolTest, EraseAtClear) {
  auto handle = ListPairStringBool_fill_value(2, sh1);
  ListPairStringBool_erase_at(handle, 0);
  EXPECT_EQ(ListPairStringBool_size(handle), 1);
  ListPairStringBool_clear(handle);
  EXPECT_TRUE(ListPairStringBool_empty(handle));
  ListPairStringBool_destroy(handle);
  set_last_error(0, nullptr);
  ListPairStringBool_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringBool_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringBoolTest, PushBackContainsIndex) {
  auto handle = ListPairStringBool_create_empty();
  ListPairStringBool_push_back(handle, sh1);
  EXPECT_TRUE(ListPairStringBool_contains(handle, sh1));
  EXPECT_EQ(ListPairStringBool_index(handle, sh1), 0);
  ListPairStringBool_destroy(handle);
  set_last_error(0, nullptr);
  ListPairStringBool_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringBool_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringBool_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringBoolTest, ItemsAt) {
  PairStringBoolHandle arr[2] = {sh1, sh2};
  auto                 handle = ListPairStringBool_create(arr, 2);
  PairStringBoolHandle out[2];
  EXPECT_EQ(ListPairStringBool_items(handle, out, 2), 2);
  ListPairStringBool_destroy(handle);
  set_last_error(0, nullptr);
  ListPairStringBool_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringBool_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringBool_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringBoolTest, EqualNotEqualIntersection) {
  PairStringBoolHandle arr[2] = {sh1, sh2};
  auto                 h1     = ListPairStringBool_create(arr, 2);
  auto                 h2     = ListPairStringBool_create(arr, 2);
  EXPECT_TRUE(ListPairStringBool_equal(h1, h2));
  EXPECT_FALSE(ListPairStringBool_not_equal(h1, h2));
  auto h3 = ListPairStringBool_intersection(h1, h2);
  EXPECT_EQ(ListPairStringBool_size(h3), 2);
  ListPairStringBool_destroy(h1);
  ListPairStringBool_destroy(h2);
  ListPairStringBool_destroy(h3);
  set_last_error(0, nullptr);
  ListPairStringBool_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringBool_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringBool_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringBool_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringBool_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringBool_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringBoolTest, ToJsonFromJson) {
  PairStringBoolHandle arr[1]  = {sh1};
  auto                 handle  = ListPairStringBool_create(arr, 1);
  auto                 json    = ListPairStringBool_to_json_string(handle);
  auto                 handle2 = ListPairStringBool_from_json_string(json);
  EXPECT_TRUE(ListPairStringBool_equal(handle, handle2));
  ListPairStringBool_destroy(handle);
  ListPairStringBool_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListPairStringBool_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListPairStringBool_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringBoolTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListPairStringBool_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringBoolTest, PushBackNull) {
  auto handle = ListPairStringBool_create_empty();
  set_last_error(0, nullptr);
  ListPairStringBool_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairStringBool_destroy(handle);
}

TEST_F(ListPairStringBoolTest, ContainsNull) {
  auto handle = ListPairStringBool_create_empty();
  set_last_error(0, nullptr);
  ListPairStringBool_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairStringBool_destroy(handle);
}

TEST_F(ListPairStringBoolTest, IndexNull) {
  auto handle = ListPairStringBool_create_empty();
  set_last_error(0, nullptr);
  ListPairStringBool_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListPairStringBool_destroy(handle);
}

TEST_F(ListPairStringBoolTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListPairStringBool_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListPairStringBoolTest, At) {
  PairStringBoolHandle arr[2] = {sh1, sh2};
  auto                 handle = ListPairStringBool_create(arr, 2);
  auto                 at0    = ListPairStringBool_at(handle, 0);
  auto                 at1    = ListPairStringBool_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListPairStringBool_destroy(handle);
  set_last_error(0, nullptr);
  ListPairStringBool_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
