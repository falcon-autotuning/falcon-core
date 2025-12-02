#include <falcon_core/generic/ListLabelledMeasuredArray1D_c_api.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

class ListLabelledMeasuredArray1DTest : public ::testing::Test {
 protected:
  void destroy_string(LabelledMeasuredArray1DHandle sh) {
    LabelledMeasuredArray1D_destroy(sh);
  }
  void TearDown() override {
    for (auto sh : created_strings) destroy_string(sh);
    created_strings.clear();
  }
  std::vector<LabelledMeasuredArray1DHandle> created_strings;
  LabelledMeasuredArray1DHandle              track_quantity(
                   const LabelledMeasuredArray1DHandle& s) {
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
    sh1 = track_quantity(LabelledMeasuredArray1D_from_farray(
        farray1,
        AcquisitionContext_create(
            Connection_create_plunger_gate(String_wrap("A")),
            InstrumentTypes_voltmeter(),
            SymbolUnit_create_volt())));
    sh2 = track_quantity(LabelledMeasuredArray1D_from_farray(
        farray2,
        AcquisitionContext_create(
            Connection_create_plunger_gate(String_wrap("A")),
            InstrumentTypes_voltmeter(),
            SymbolUnit_create_volt())));
  }
  LabelledMeasuredArray1DHandle sh1;
  LabelledMeasuredArray1DHandle sh2;
};

TEST_F(ListLabelledMeasuredArray1DTest, CreateEmpty) {
  auto handle = ListLabelledMeasuredArray1D_create_empty();
  EXPECT_TRUE(ListLabelledMeasuredArray1D_empty(handle));
  EXPECT_EQ(ListLabelledMeasuredArray1D_size(handle), 0);
  ListLabelledMeasuredArray1D_destroy(handle);
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListLabelledMeasuredArray1DTest, FillValue) {
  auto handle = ListLabelledMeasuredArray1D_fill_value(3, sh1);
  EXPECT_EQ(ListLabelledMeasuredArray1D_size(handle), 3);
  ListLabelledMeasuredArray1D_destroy(handle);
}

TEST_F(ListLabelledMeasuredArray1DTest, CreateFromArray1D) {
  LabelledMeasuredArray1DHandle     arr[2] = {sh1, sh2};
  ListLabelledMeasuredArray1DHandle handle =
      ListLabelledMeasuredArray1D_create(arr, 2);
  EXPECT_EQ(ListLabelledMeasuredArray1D_size(handle), 2);
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  ListLabelledMeasuredArray1D_destroy(handle);
}

TEST_F(ListLabelledMeasuredArray1DTest, SizeEmptyInvalid) {
  auto handle = ListLabelledMeasuredArray1D_create_empty();
  EXPECT_EQ(ListLabelledMeasuredArray1D_size(handle), 0);
  ListLabelledMeasuredArray1D_destroy(handle);
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListLabelledMeasuredArray1DTest, EmptyInvalid) {
  auto handle = ListLabelledMeasuredArray1D_create_empty();
  EXPECT_TRUE(ListLabelledMeasuredArray1D_empty(handle));
  ListLabelledMeasuredArray1D_destroy(handle);
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListLabelledMeasuredArray1DTest, EraseAtClear) {
  auto handle = ListLabelledMeasuredArray1D_fill_value(2, sh1);
  ListLabelledMeasuredArray1D_erase_at(handle, 0);
  EXPECT_EQ(ListLabelledMeasuredArray1D_size(handle), 1);
  ListLabelledMeasuredArray1D_clear(handle);
  EXPECT_TRUE(ListLabelledMeasuredArray1D_empty(handle));
  ListLabelledMeasuredArray1D_destroy(handle);
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListLabelledMeasuredArray1DTest, PushBackContainsIndex) {
  auto handle = ListLabelledMeasuredArray1D_create_empty();
  ListLabelledMeasuredArray1D_push_back(handle, sh1);
  EXPECT_TRUE(ListLabelledMeasuredArray1D_contains(handle, sh1));
  EXPECT_EQ(ListLabelledMeasuredArray1D_index(handle, sh1), 0);
  ListLabelledMeasuredArray1D_destroy(handle);
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_push_back(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_contains(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_index(nullptr, sh1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListLabelledMeasuredArray1DTest, ItemsAt) {
  LabelledMeasuredArray1DHandle arr[2] = {sh1, sh2};
  auto handle = ListLabelledMeasuredArray1D_create(arr, 2);
  LabelledMeasuredArray1DHandle out[2];
  EXPECT_EQ(ListLabelledMeasuredArray1D_items(handle, out, 2), 2);
  ListLabelledMeasuredArray1D_destroy(handle);
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_items(nullptr, out, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_items(handle, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListLabelledMeasuredArray1DTest, EqualNotEqualIntersection) {
  LabelledMeasuredArray1DHandle arr[2] = {sh1, sh2};
  auto                          h1 = ListLabelledMeasuredArray1D_create(arr, 2);
  auto                          h2 = ListLabelledMeasuredArray1D_create(arr, 2);
  EXPECT_TRUE(ListLabelledMeasuredArray1D_equal(h1, h2));
  EXPECT_FALSE(ListLabelledMeasuredArray1D_not_equal(h1, h2));
  auto h3 = ListLabelledMeasuredArray1D_intersection(h1, h2);
  EXPECT_EQ(ListLabelledMeasuredArray1D_size(h3), 2);
  ListLabelledMeasuredArray1D_destroy(h1);
  ListLabelledMeasuredArray1D_destroy(h2);
  ListLabelledMeasuredArray1D_destroy(h3);
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_not_equal(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_not_equal(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_intersection(nullptr, h2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_intersection(h1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListLabelledMeasuredArray1DTest, ToJsonFromJson) {
  LabelledMeasuredArray1DHandle arr[1] = {sh1};
  auto handle  = ListLabelledMeasuredArray1D_create(arr, 1);
  auto json    = ListLabelledMeasuredArray1D_to_json_string(handle);
  auto handle2 = ListLabelledMeasuredArray1D_from_json_string(json);
  EXPECT_TRUE(ListLabelledMeasuredArray1D_equal(handle, handle2));
  ListLabelledMeasuredArray1D_destroy(handle);
  ListLabelledMeasuredArray1D_destroy(handle2);
  String_destroy(json);
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListLabelledMeasuredArray1DTest, FillValueNull) {
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_fill_value(3, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListLabelledMeasuredArray1DTest, PushBackNull) {
  auto handle = ListLabelledMeasuredArray1D_create_empty();
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_push_back(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListLabelledMeasuredArray1D_destroy(handle);
}

TEST_F(ListLabelledMeasuredArray1DTest, ContainsNull) {
  auto handle = ListLabelledMeasuredArray1D_create_empty();
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_contains(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListLabelledMeasuredArray1D_destroy(handle);
}

TEST_F(ListLabelledMeasuredArray1DTest, IndexNull) {
  auto handle = ListLabelledMeasuredArray1D_create_empty();
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_index(handle, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  ListLabelledMeasuredArray1D_destroy(handle);
}

TEST_F(ListLabelledMeasuredArray1DTest, CreateNullArray1D) {
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_create(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ListLabelledMeasuredArray1DTest, At) {
  LabelledMeasuredArray1DHandle arr[2] = {sh1, sh2};
  auto handle = ListLabelledMeasuredArray1D_create(arr, 2);
  auto at0    = ListLabelledMeasuredArray1D_at(handle, 0);
  auto at1    = ListLabelledMeasuredArray1D_at(handle, 1);
  destroy_string(at0);
  destroy_string(at1);
  ListLabelledMeasuredArray1D_destroy(handle);
  set_last_error(0, nullptr);
  ListLabelledMeasuredArray1D_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}
