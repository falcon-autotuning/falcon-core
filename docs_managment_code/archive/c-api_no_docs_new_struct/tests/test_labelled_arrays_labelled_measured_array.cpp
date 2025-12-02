#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/arrays/LabelledArraysLabelledMeasuredArray_c_api.h"
#include "falcon_core/math/arrays/LabelledMeasuredArray_c_api.h"

class LabelledArraysLabelledMeasuredArrayTest : public ::testing::Test {
 protected:
  void SetUp() override {
    shape[0] = 6;
    data[0]  = 1.0;
    data[1]  = 2.0;
    data[2]  = 3.0;
    data[3]  = 4.0;
    data[4]  = 5.0;
    data[5]  = 6.0;
    data2[0] = 2.0;
    data2[1] = 4.0;
    data2[2] = 6.0;
    data2[3] = 8.0;
    data2[4] = 10.0;
    data2[5] = 12.0;
    fa       = FArrayDouble_from_data(data, shape, 1);
    fa2      = FArrayDouble_from_data(data2, shape, 1);
    label    = AcquisitionContext_create(
        Connection_create_plunger_gate(String_wrap("P1")),
        InstrumentTypes_voltmeter(),
        SymbolUnit_create_volt());
    label2 = AcquisitionContext_create(
        Connection_create_barrier_gate(String_wrap("B1")),
        InstrumentTypes_voltmeter(),
        SymbolUnit_create_ampere());
    // Create two LabelledMeasuredArray objects
    arr1 = LabelledMeasuredArray_from_farray(fa, label);
    arr2 = LabelledMeasuredArray_from_farray(fa2, label2);
    // Create a List<LabelledMeasuredArray> and add arr1, arr2
    list = ListLabelledMeasuredArray_create_empty();
    ListLabelledMeasuredArray_push_back(list, arr1);
    ListLabelledMeasuredArray_push_back(list, arr2);
    // Create the LabelledArraysLabelledMeasuredArray object
    arrays = LabelledArraysLabelledMeasuredArray_create(list);
  }
  void TearDown() override {
    LabelledArraysLabelledMeasuredArray_destroy(arrays);
    ListLabelledMeasuredArray_destroy(list);
    LabelledMeasuredArray_destroy(arr1);
    LabelledMeasuredArray_destroy(arr2);
  }
  double                                    data[6];
  double                                    data2[6];
  size_t                                    shape[1];
  AcquisitionContextHandle                  label;
  AcquisitionContextHandle                  label2;
  FArrayDoubleHandle                        fa;
  FArrayDoubleHandle                        fa2;
  LabelledMeasuredArrayHandle               arr1;
  LabelledMeasuredArrayHandle               arr2;
  ListLabelledMeasuredArrayHandle           list;
  LabelledArraysLabelledMeasuredArrayHandle arrays;
};

TEST_F(LabelledArraysLabelledMeasuredArrayTest, CreateDestroy) {
  auto l = ListLabelledMeasuredArray_create_empty();
  auto a = LabelledArraysLabelledMeasuredArray_create(l);
  LabelledArraysLabelledMeasuredArray_destroy(a);
  ListLabelledMeasuredArray_destroy(l);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledArraysLabelledMeasuredArrayTest, Accessors) {
  auto arrs = LabelledArraysLabelledMeasuredArray_arrays(arrays);
  EXPECT_EQ(ListLabelledMeasuredArray_size(arrs), 2);
  ListLabelledMeasuredArray_destroy(arrs);

  auto labs = LabelledArraysLabelledMeasuredArray_labels(arrays);
  EXPECT_TRUE(labs != nullptr);
  ListAcquisitionContext_destroy(labs);

  EXPECT_TRUE(LabelledArraysLabelledMeasuredArray_is_measured_arrays(arrays));
  EXPECT_FALSE(LabelledArraysLabelledMeasuredArray_is_control_arrays(arrays));

  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_arrays(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_labels(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_is_measured_arrays(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_is_control_arrays(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledArraysLabelledMeasuredArrayTest, AtAndSizeEmpty) {
  EXPECT_EQ(LabelledArraysLabelledMeasuredArray_size(arrays), 2);
  EXPECT_FALSE(LabelledArraysLabelledMeasuredArray_empty(arrays));
  auto a0 = LabelledArraysLabelledMeasuredArray_at(arrays, 0);
  auto a1 = LabelledArraysLabelledMeasuredArray_at(arrays, 1);
  EXPECT_TRUE(a0 != nullptr);
  EXPECT_TRUE(a1 != nullptr);
  LabelledMeasuredArray_destroy(a0);
  LabelledMeasuredArray_destroy(a1);

  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledArraysLabelledMeasuredArrayTest, EraseClearPushBack) {
  LabelledArraysLabelledMeasuredArray_push_back(arrays, arr1);
  EXPECT_EQ(LabelledArraysLabelledMeasuredArray_size(arrays), 3);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_push_back(nullptr, arr1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_push_back(arrays, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  LabelledArraysLabelledMeasuredArray_erase_at(arrays, 2);
  EXPECT_EQ(LabelledArraysLabelledMeasuredArray_size(arrays), 2);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);

  LabelledArraysLabelledMeasuredArray_clear(arrays);
  EXPECT_EQ(LabelledArraysLabelledMeasuredArray_size(arrays), 0);
  EXPECT_TRUE(LabelledArraysLabelledMeasuredArray_empty(arrays));
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledArraysLabelledMeasuredArrayTest, ContainsIndex) {
  EXPECT_TRUE(LabelledArraysLabelledMeasuredArray_contains(arrays, arr1));
  EXPECT_TRUE(LabelledArraysLabelledMeasuredArray_contains(arrays, arr2));
  EXPECT_EQ(LabelledArraysLabelledMeasuredArray_index(arrays, arr1), 0);
  EXPECT_EQ(LabelledArraysLabelledMeasuredArray_index(arrays, arr2), 1);

  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_contains(nullptr, arr1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_contains(arrays, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_index(nullptr, arr1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_index(arrays, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledArraysLabelledMeasuredArrayTest, Equality) {
  auto l2 = ListLabelledMeasuredArray_create_empty();
  ListLabelledMeasuredArray_push_back(l2, arr1);
  ListLabelledMeasuredArray_push_back(l2, arr2);
  auto a2 = LabelledArraysLabelledMeasuredArray_create(l2);

  EXPECT_TRUE(LabelledArraysLabelledMeasuredArray_equal(arrays, a2));
  EXPECT_FALSE(LabelledArraysLabelledMeasuredArray_not_equal(arrays, a2));

  LabelledArraysLabelledMeasuredArray_erase_at(a2, 1);
  EXPECT_FALSE(LabelledArraysLabelledMeasuredArray_equal(arrays, a2));
  EXPECT_TRUE(LabelledArraysLabelledMeasuredArray_not_equal(arrays, a2));

  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_equal(nullptr, a2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_equal(arrays, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_not_equal(nullptr, a2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_not_equal(arrays, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  LabelledArraysLabelledMeasuredArray_destroy(a2);
  ListLabelledMeasuredArray_destroy(l2);
}

TEST_F(LabelledArraysLabelledMeasuredArrayTest, Intersection) {
  auto l2 = ListLabelledMeasuredArray_create_empty();
  ListLabelledMeasuredArray_push_back(l2, arr1);
  auto a2 = LabelledArraysLabelledMeasuredArray_create(l2);

  auto inter = LabelledArraysLabelledMeasuredArray_intersection(arrays, a2);
  EXPECT_EQ(LabelledArraysLabelledMeasuredArray_size(inter), 1);
  auto at0 = LabelledArraysLabelledMeasuredArray_at(inter, 0);
  EXPECT_TRUE(LabelledArraysLabelledMeasuredArray_contains(inter, arr1));
  LabelledMeasuredArray_destroy(at0);
  LabelledArraysLabelledMeasuredArray_destroy(inter);

  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_intersection(nullptr, a2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_intersection(arrays, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  LabelledArraysLabelledMeasuredArray_destroy(a2);
  ListLabelledMeasuredArray_destroy(l2);
}

TEST_F(LabelledArraysLabelledMeasuredArrayTest, ToJsonFromJson) {
  auto json = LabelledArraysLabelledMeasuredArray_to_json_string(arrays);
  auto arr2 = LabelledArraysLabelledMeasuredArray_from_json_string(json);
  EXPECT_TRUE(LabelledArraysLabelledMeasuredArray_equal(arrays, arr2));
  LabelledArraysLabelledMeasuredArray_destroy(arr2);
  String_destroy(json);

  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
