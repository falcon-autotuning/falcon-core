#include <falcon-core/generic/ListControlArray1D_c_api.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListControlArray1DTest : public ::testing::Test {
 protected:
  void destroy_string(ControlArray1DHandle sh) { ControlArray1D_destroy(sh); }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<ControlArray1DHandle> created_strings;
  ControlArray1DHandle track_quantity(const ControlArray1DHandle& s) {
    created_strings.push_back(s);
    return s;
  }
  void SetUp() override {
    double             data1[3] = {1.0, 2.0, 3.0};
    double             data2[3] = {4.0, 5.0, 6.0};
    FArrayDoubleHandle farray1 =
        FArrayDouble_from_data(data1, (size_t[]){3}, 1);
    FArrayDoubleHandle farray2 =
        FArrayDouble_from_data(data2, (size_t[]){3}, 1);
    sh1 = track_quantity(ControlArray1D_from_farray(farray1));
    sh2 = track_quantity(ControlArray1D_from_farray(farray2));
  }
  ControlArray1DHandle sh1;
  ControlArray1DHandle sh2;
};

TEST_F(ListControlArray1DTest, CreateEmpty) {
  auto handle = ListControlArray1D_create_empty();
  EXPECT_TRUE(ListControlArray1D_empty(handle));
  EXPECT_EQ(ListControlArray1D_size(handle), 0);
  ListControlArray1D_destroy(handle);
  set_last_error(0, nullptr);
  ListControlArray1D_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListControlArray1DTest, FillValue) {
  auto handle = ListControlArray1D_fill_value(3, sh1);
  EXPECT_EQ(ListControlArray1D_size(handle), 3);
  ListControlArray1D_destroy(handle);
}

TEST_F(ListControlArray1DTest, CreateFromArray) {
  ControlArray1DHandle     arr[2] = {sh1, sh2};
  ListControlArray1DHandle handle = ListControlArray1D_create(arr, 2);
  EXPECT_EQ(ListControlArray1D_size(handle), 2);
  set_last_error(0, nullptr);
  ListControlArray1D_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListControlArray1D_destroy(handle);
}

TEST_F(ListControlArray1DTest, SizeEmptyInvalid) {
  auto handle = ListControlArray1D_create_empty();
  EXPECT_EQ(ListControlArray1D_size(handle), 0);
  ListControlArray1D_destroy(handle);
  set_last_error(0, nullptr);
  ListControlArray1D_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListControlArray1DTest, EmptyInvalid) {
  auto handle = ListControlArray1D_create_empty();
  EXPECT_TRUE(ListControlArray1D_empty(handle));
  ListControlArray1D_destroy(handle);
  set_last_error(0, nullptr);
  ListControlArray1D_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListControlArray1DTest, EraseAtClear) {
  auto handle = ListControlArray1D_fill_value(2, sh1);
  ListControlArray1D_erase_at(handle, 0);
  EXPECT_EQ(ListControlArray1D_size(handle), 1);
  ListControlArray1D_clear(handle);
  EXPECT_TRUE(ListControlArray1D_empty(handle));
  ListControlArray1D_destroy(handle);
  set_last_error(0, nullptr);
  ListControlArray1D_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListControlArray1D_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListControlArray1DTest, PushBackContainsIndex) {
  auto handle = ListControlArray1D_create_empty();
  ListControlArray1D_push_back(handle, sh1);
  EXPECT_TRUE(ListControlArray1D_contains(handle, sh1));
  EXPECT_EQ(ListControlArray1D_index(handle, sh1), 0);
  ListControlArray1D_destroy(handle);
  set_last_error(0, nullptr);
  ListControlArray1D_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListControlArray1D_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListControlArray1D_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListControlArray1DTest, ItemsAt) {
  ControlArray1DHandle arr[2] = {sh1, sh2};
  auto                 handle = ListControlArray1D_create(arr, 2);
  ControlArray1DHandle out[2];
  EXPECT_EQ(ListControlArray1D_items(handle, out, 2), 2);
  ListControlArray1D_destroy(handle);
  set_last_error(0, nullptr);
  ListControlArray1D_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListControlArray1D_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListControlArray1D_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListControlArray1DTest, EqualNotEqualIntersection) {
  ControlArray1DHandle arr[2] = {sh1, sh2};
  auto                 h1     = ListControlArray1D_create(arr, 2);
  auto                 h2     = ListControlArray1D_create(arr, 2);
  EXPECT_TRUE(ListControlArray1D_equal(h1, h2));
  EXPECT_FALSE(ListControlArray1D_not_equal(h1, h2));
  auto h3 = ListControlArray1D_intersection(h1, h2);
  EXPECT_EQ(ListControlArray1D_size(h3), 2);
  ListControlArray1D_destroy(h1);
  ListControlArray1D_destroy(h2);
  ListControlArray1D_destroy(h3);
  set_last_error(0, nullptr);
  ListControlArray1D_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListControlArray1D_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListControlArray1D_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListControlArray1D_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListControlArray1D_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListControlArray1D_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListControlArray1DTest, ToJsonFromJson) {
  ControlArray1DHandle arr[1]  = {sh1};
  auto                 handle  = ListControlArray1D_create(arr, 1);
  auto                 json    = ListControlArray1D_to_json_string(handle);
  auto                 handle2 = ListControlArray1D_from_json_string(json);
  EXPECT_TRUE(ListControlArray1D_equal(handle, handle2));
  ListControlArray1D_destroy(handle);
  ListControlArray1D_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListControlArray1D_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListControlArray1D_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListControlArray1DTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListControlArray1D_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListControlArray1DTest, PushBackNull) {
  auto handle = ListControlArray1D_create_empty();
  set_last_error(0, nullptr);
  ListControlArray1D_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListControlArray1D_destroy(handle);
}

TEST_F(ListControlArray1DTest, ContainsNull) {
  auto handle = ListControlArray1D_create_empty();
  set_last_error(0, nullptr);
  ListControlArray1D_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListControlArray1D_destroy(handle);
}

TEST_F(ListControlArray1DTest, IndexNull) {
  auto handle = ListControlArray1D_create_empty();
  set_last_error(0, nullptr);
  ListControlArray1D_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListControlArray1D_destroy(handle);
}

TEST_F(ListControlArray1DTest, CreateNullArray) {
  set_last_error(0, nullptr);
  ListControlArray1D_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListControlArray1DTest, At) {
  ControlArray1DHandle arr[2] = {sh1, sh2};
  auto                 handle = ListControlArray1D_create(arr, 2);
  auto                 at0    = ListControlArray1D_at(handle, 0);
  auto                 at1    = ListControlArray1D_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListControlArray1D_destroy(handle);
  set_last_error(0, nullptr);
  ListControlArray1D_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
