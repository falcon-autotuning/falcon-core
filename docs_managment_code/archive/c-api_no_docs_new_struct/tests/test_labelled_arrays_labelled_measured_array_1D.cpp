#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/arrays/LabelledArraysLabelledMeasuredArray1D_c_api.h"
#include "falcon_core/math/arrays/LabelledMeasuredArray1D_c_api.h"

class LabelledArraysLabelledMeasuredArray1DTest : public ::testing::Test {
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
    // Create two LabelledMeasuredArray1D objects
    arr1 = LabelledMeasuredArray1D_from_farray(fa, label);
    arr2 = LabelledMeasuredArray1D_from_farray(fa2, label2);
    // Create a List<LabelledMeasuredArray1D> and add arr1, arr2
    list = ListLabelledMeasuredArray1D_create_empty();
    ListLabelledMeasuredArray1D_push_back(list, arr1);
    ListLabelledMeasuredArray1D_push_back(list, arr2);
    // Create the LabelledArraysLabelledMeasuredArray1D object
    arrays = LabelledArraysLabelledMeasuredArray1D_create(list);
  }
  void TearDown() override {
    LabelledArraysLabelledMeasuredArray1D_destroy(arrays);
    ListLabelledMeasuredArray1D_destroy(list);
    LabelledMeasuredArray1D_destroy(arr1);
    LabelledMeasuredArray1D_destroy(arr2);
  }
  double                                      data[6];
  double                                      data2[6];
  size_t                                      shape[1];
  AcquisitionContextHandle                    label;
  AcquisitionContextHandle                    label2;
  FArrayDoubleHandle                          fa;
  FArrayDoubleHandle                          fa2;
  LabelledMeasuredArray1DHandle               arr1;
  LabelledMeasuredArray1DHandle               arr2;
  ListLabelledMeasuredArray1DHandle           list;
  LabelledArraysLabelledMeasuredArray1DHandle arrays;
};

TEST_F(LabelledArraysLabelledMeasuredArray1DTest, CreateDestroy) {
  auto l = ListLabelledMeasuredArray1D_create_empty();
  auto a = LabelledArraysLabelledMeasuredArray1D_create(l);
  LabelledArraysLabelledMeasuredArray1D_destroy(a);
  ListLabelledMeasuredArray1D_destroy(l);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledArraysLabelledMeasuredArray1DTest, Accessors) {
  auto arrs = LabelledArraysLabelledMeasuredArray1D_arrays(arrays);
  EXPECT_EQ(ListLabelledMeasuredArray1D_size(arrs), 2);
  ListLabelledMeasuredArray1D_destroy(arrs);

  auto labs = LabelledArraysLabelledMeasuredArray1D_labels(arrays);
  EXPECT_TRUE(labs != nullptr);
  ListAcquisitionContext_destroy(labs);

  EXPECT_TRUE(LabelledArraysLabelledMeasuredArray1D_is_measured_arrays(arrays));
  EXPECT_FALSE(LabelledArraysLabelledMeasuredArray1D_is_control_arrays(arrays));

  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_arrays(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_labels(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_is_control_arrays(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_is_measured_arrays(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledArraysLabelledMeasuredArray1DTest, AtAndSizeEmpty) {
  EXPECT_EQ(LabelledArraysLabelledMeasuredArray1D_size(arrays), 2);
  EXPECT_FALSE(LabelledArraysLabelledMeasuredArray1D_empty(arrays));
  auto a0 = LabelledArraysLabelledMeasuredArray1D_at(arrays, 0);
  auto a1 = LabelledArraysLabelledMeasuredArray1D_at(arrays, 1);
  EXPECT_TRUE(a0 != nullptr);
  EXPECT_TRUE(a1 != nullptr);
  LabelledMeasuredArray1D_destroy(a0);
  LabelledMeasuredArray1D_destroy(a1);

  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledArraysLabelledMeasuredArray1DTest, EraseClearPushBack) {
  LabelledArraysLabelledMeasuredArray1D_push_back(arrays, arr1);
  EXPECT_EQ(LabelledArraysLabelledMeasuredArray1D_size(arrays), 3);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_push_back(nullptr, arr1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_push_back(arrays, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  LabelledArraysLabelledMeasuredArray1D_erase_at(arrays, 2);
  EXPECT_EQ(LabelledArraysLabelledMeasuredArray1D_size(arrays), 2);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);

  LabelledArraysLabelledMeasuredArray1D_clear(arrays);
  EXPECT_EQ(LabelledArraysLabelledMeasuredArray1D_size(arrays), 0);
  EXPECT_TRUE(LabelledArraysLabelledMeasuredArray1D_empty(arrays));
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledArraysLabelledMeasuredArray1DTest, ContainsIndex) {
  EXPECT_TRUE(LabelledArraysLabelledMeasuredArray1D_contains(arrays, arr1));
  EXPECT_TRUE(LabelledArraysLabelledMeasuredArray1D_contains(arrays, arr2));
  EXPECT_EQ(LabelledArraysLabelledMeasuredArray1D_index(arrays, arr1), 0);
  EXPECT_EQ(LabelledArraysLabelledMeasuredArray1D_index(arrays, arr2), 1);

  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_contains(nullptr, arr1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_contains(arrays, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_index(nullptr, arr1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_index(arrays, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledArraysLabelledMeasuredArray1DTest, Equality) {
  auto l2 = ListLabelledMeasuredArray1D_create_empty();
  ListLabelledMeasuredArray1D_push_back(l2, arr1);
  ListLabelledMeasuredArray1D_push_back(l2, arr2);
  auto a2 = LabelledArraysLabelledMeasuredArray1D_create(l2);

  EXPECT_TRUE(LabelledArraysLabelledMeasuredArray1D_equal(arrays, a2));
  EXPECT_FALSE(LabelledArraysLabelledMeasuredArray1D_not_equal(arrays, a2));

  LabelledArraysLabelledMeasuredArray1D_erase_at(a2, 1);
  EXPECT_FALSE(LabelledArraysLabelledMeasuredArray1D_equal(arrays, a2));
  EXPECT_TRUE(LabelledArraysLabelledMeasuredArray1D_not_equal(arrays, a2));

  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_equal(nullptr, a2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_equal(arrays, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_not_equal(nullptr, a2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_not_equal(arrays, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  LabelledArraysLabelledMeasuredArray1D_destroy(a2);
  ListLabelledMeasuredArray1D_destroy(l2);
}

TEST_F(LabelledArraysLabelledMeasuredArray1DTest, Intersection) {
  auto l2 = ListLabelledMeasuredArray1D_create_empty();
  ListLabelledMeasuredArray1D_push_back(l2, arr1);
  auto a2 = LabelledArraysLabelledMeasuredArray1D_create(l2);

  auto inter = LabelledArraysLabelledMeasuredArray1D_intersection(arrays, a2);
  EXPECT_EQ(LabelledArraysLabelledMeasuredArray1D_size(inter), 1);
  auto at0 = LabelledArraysLabelledMeasuredArray1D_at(inter, 0);
  EXPECT_TRUE(LabelledArraysLabelledMeasuredArray1D_contains(inter, arr1));
  LabelledMeasuredArray1D_destroy(at0);
  LabelledArraysLabelledMeasuredArray1D_destroy(inter);

  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_intersection(nullptr, a2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_intersection(arrays, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  LabelledArraysLabelledMeasuredArray1D_destroy(a2);
  ListLabelledMeasuredArray1D_destroy(l2);
}

TEST_F(LabelledArraysLabelledMeasuredArray1DTest, ToJsonFromJson) {
  auto json = LabelledArraysLabelledMeasuredArray1D_to_json_string(arrays);
  auto arr2 = LabelledArraysLabelledMeasuredArray1D_from_json_string(json);
  EXPECT_TRUE(LabelledArraysLabelledMeasuredArray1D_equal(arrays, arr2));
  LabelledArraysLabelledMeasuredArray1D_destroy(arr2);
  String_destroy(json);

  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledArraysLabelledMeasuredArray1D_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
