#include <gtest/gtest.h>

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
  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_create(nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_destroy(nullptr),
               std::invalid_argument);
}

TEST_F(LabelledArraysLabelledMeasuredArrayTest, Accessors) {
  auto arrs = LabelledArraysLabelledMeasuredArray_arrays(arrays);
  EXPECT_EQ(ListLabelledMeasuredArray_size(arrs), 2);
  ListLabelledMeasuredArray_destroy(arrs);

  auto labs = LabelledArraysLabelledMeasuredArray_labels(arrays);
  EXPECT_TRUE(labs != nullptr);
  ListAcquisitionContext_destroy(labs);

  EXPECT_TRUE(LabelledArraysLabelledMeasuredArray_isMeasuredArrays(arrays));
  EXPECT_FALSE(LabelledArraysLabelledMeasuredArray_isControlArrays(arrays));

  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_arrays(nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_labels(nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_isMeasuredArrays(nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_isControlArrays(nullptr),
               std::invalid_argument);
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

  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_at(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_size(nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_empty(nullptr),
               std::invalid_argument);
}

TEST_F(LabelledArraysLabelledMeasuredArrayTest, EraseClearPushBack) {
  LabelledArraysLabelledMeasuredArray_push_back(arrays, arr1);
  EXPECT_EQ(LabelledArraysLabelledMeasuredArray_size(arrays), 3);
  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_push_back(nullptr, arr1),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_push_back(arrays, nullptr),
               std::invalid_argument);

  LabelledArraysLabelledMeasuredArray_erase_at(arrays, 2);
  EXPECT_EQ(LabelledArraysLabelledMeasuredArray_size(arrays), 2);
  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_erase_at(nullptr, 0),
               std::invalid_argument);

  LabelledArraysLabelledMeasuredArray_clear(arrays);
  EXPECT_EQ(LabelledArraysLabelledMeasuredArray_size(arrays), 0);
  EXPECT_TRUE(LabelledArraysLabelledMeasuredArray_empty(arrays));
  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_clear(nullptr),
               std::invalid_argument);
}

TEST_F(LabelledArraysLabelledMeasuredArrayTest, ContainsIndex) {
  EXPECT_TRUE(LabelledArraysLabelledMeasuredArray_contains(arrays, arr1));
  EXPECT_TRUE(LabelledArraysLabelledMeasuredArray_contains(arrays, arr2));
  EXPECT_EQ(LabelledArraysLabelledMeasuredArray_index(arrays, arr1), 0);
  EXPECT_EQ(LabelledArraysLabelledMeasuredArray_index(arrays, arr2), 1);

  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_contains(nullptr, arr1),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_contains(arrays, nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_index(nullptr, arr1),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_index(arrays, nullptr),
               std::invalid_argument);
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

  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_equal(nullptr, a2),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_equal(arrays, nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_not_equal(nullptr, a2),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_not_equal(arrays, nullptr),
               std::invalid_argument);

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

  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_intersection(nullptr, a2),
               std::invalid_argument);
  EXPECT_THROW(
      LabelledArraysLabelledMeasuredArray_intersection(arrays, nullptr),
      std::invalid_argument);

  LabelledArraysLabelledMeasuredArray_destroy(a2);
  ListLabelledMeasuredArray_destroy(l2);
}

TEST_F(LabelledArraysLabelledMeasuredArrayTest, ToJsonFromJson) {
  auto json = LabelledArraysLabelledMeasuredArray_to_json_string(arrays);
  auto arr2 = LabelledArraysLabelledMeasuredArray_from_json_string(json);
  EXPECT_TRUE(LabelledArraysLabelledMeasuredArray_equal(arrays, arr2));
  LabelledArraysLabelledMeasuredArray_destroy(arr2);
  String_destroy(json);

  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledMeasuredArray_from_json_string(nullptr),
               std::invalid_argument);
}
