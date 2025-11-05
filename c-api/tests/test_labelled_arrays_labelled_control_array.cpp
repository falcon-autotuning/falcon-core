#include <gtest/gtest.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/arrays/LabelledArraysLabelledControlArray_c_api.h"
#include "falcon_core/math/arrays/LabelledControlArray_c_api.h"

class LabelledArraysLabelledControlArrayTest : public ::testing::Test {
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
    // Create two LabelledControlArray objects
    arr1 = LabelledControlArray_from_farray(fa, label);
    arr2 = LabelledControlArray_from_farray(fa2, label2);
    // Create a List<LabelledControlArray> and add arr1, arr2
    list = ListLabelledControlArray_create_empty();
    ListLabelledControlArray_push_back(list, arr1);
    ListLabelledControlArray_push_back(list, arr2);
    // Create the LabelledArraysLabelledControlArray object
    arrays = LabelledArraysLabelledControlArray_create(list);
  }
  void TearDown() override {
    LabelledArraysLabelledControlArray_destroy(arrays);
    ListLabelledControlArray_destroy(list);
    LabelledControlArray_destroy(arr1);
    LabelledControlArray_destroy(arr2);
  }
  double                                   data[6];
  double                                   data2[6];
  size_t                                   shape[1];
  AcquisitionContextHandle                 label;
  AcquisitionContextHandle                 label2;
  FArrayDoubleHandle                       fa;
  FArrayDoubleHandle                       fa2;
  LabelledControlArrayHandle               arr1;
  LabelledControlArrayHandle               arr2;
  ListLabelledControlArrayHandle           list;
  LabelledArraysLabelledControlArrayHandle arrays;
};

TEST_F(LabelledArraysLabelledControlArrayTest, CreateDestroy) {
  auto l = ListLabelledControlArray_create_empty();
  auto a = LabelledArraysLabelledControlArray_create(l);
  LabelledArraysLabelledControlArray_destroy(a);
  ListLabelledControlArray_destroy(l);
  EXPECT_THROW(LabelledArraysLabelledControlArray_create(nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledControlArray_destroy(nullptr),
               std::invalid_argument);
}

TEST_F(LabelledArraysLabelledControlArrayTest, Accessors) {
  auto arrs = LabelledArraysLabelledControlArray_arrays(arrays);
  EXPECT_EQ(ListLabelledControlArray_size(arrs), 2);
  ListLabelledControlArray_destroy(arrs);

  auto labs = LabelledArraysLabelledControlArray_labels(arrays);
  EXPECT_TRUE(labs != nullptr);
  ListAcquisitionContext_destroy(labs);

  EXPECT_TRUE(LabelledArraysLabelledControlArray_isControlArrays(arrays));
  EXPECT_FALSE(LabelledArraysLabelledControlArray_isMeasuredArrays(arrays));

  EXPECT_THROW(LabelledArraysLabelledControlArray_arrays(nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledControlArray_labels(nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledControlArray_isControlArrays(nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledControlArray_isMeasuredArrays(nullptr),
               std::invalid_argument);
}

TEST_F(LabelledArraysLabelledControlArrayTest, AtAndSizeEmpty) {
  EXPECT_EQ(LabelledArraysLabelledControlArray_size(arrays), 2);
  EXPECT_FALSE(LabelledArraysLabelledControlArray_empty(arrays));
  auto a0 = LabelledArraysLabelledControlArray_at(arrays, 0);
  auto a1 = LabelledArraysLabelledControlArray_at(arrays, 1);
  EXPECT_TRUE(a0 != nullptr);
  EXPECT_TRUE(a1 != nullptr);
  LabelledControlArray_destroy(a0);
  LabelledControlArray_destroy(a1);

  EXPECT_THROW(LabelledArraysLabelledControlArray_at(nullptr, 0),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledControlArray_size(nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledControlArray_empty(nullptr),
               std::invalid_argument);
}

TEST_F(LabelledArraysLabelledControlArrayTest, EraseClearPushBack) {
  LabelledArraysLabelledControlArray_push_back(arrays, arr1);
  EXPECT_EQ(LabelledArraysLabelledControlArray_size(arrays), 3);
  EXPECT_THROW(LabelledArraysLabelledControlArray_push_back(nullptr, arr1),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledControlArray_push_back(arrays, nullptr),
               std::invalid_argument);

  LabelledArraysLabelledControlArray_erase_at(arrays, 2);
  EXPECT_EQ(LabelledArraysLabelledControlArray_size(arrays), 2);
  EXPECT_THROW(LabelledArraysLabelledControlArray_erase_at(nullptr, 0),
               std::invalid_argument);

  LabelledArraysLabelledControlArray_clear(arrays);
  EXPECT_EQ(LabelledArraysLabelledControlArray_size(arrays), 0);
  EXPECT_TRUE(LabelledArraysLabelledControlArray_empty(arrays));
  EXPECT_THROW(LabelledArraysLabelledControlArray_clear(nullptr),
               std::invalid_argument);
}

TEST_F(LabelledArraysLabelledControlArrayTest, ContainsIndex) {
  EXPECT_TRUE(LabelledArraysLabelledControlArray_contains(arrays, arr1));
  EXPECT_TRUE(LabelledArraysLabelledControlArray_contains(arrays, arr2));
  EXPECT_EQ(LabelledArraysLabelledControlArray_index(arrays, arr1), 0);
  EXPECT_EQ(LabelledArraysLabelledControlArray_index(arrays, arr2), 1);

  EXPECT_THROW(LabelledArraysLabelledControlArray_contains(nullptr, arr1),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledControlArray_contains(arrays, nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledControlArray_index(nullptr, arr1),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledControlArray_index(arrays, nullptr),
               std::invalid_argument);
}

TEST_F(LabelledArraysLabelledControlArrayTest, Equality) {
  auto l2 = ListLabelledControlArray_create_empty();
  ListLabelledControlArray_push_back(l2, arr1);
  ListLabelledControlArray_push_back(l2, arr2);
  auto a2 = LabelledArraysLabelledControlArray_create(l2);

  EXPECT_TRUE(LabelledArraysLabelledControlArray_equal(arrays, a2));
  EXPECT_FALSE(LabelledArraysLabelledControlArray_not_equal(arrays, a2));

  LabelledArraysLabelledControlArray_erase_at(a2, 1);
  EXPECT_FALSE(LabelledArraysLabelledControlArray_equal(arrays, a2));
  EXPECT_TRUE(LabelledArraysLabelledControlArray_not_equal(arrays, a2));

  EXPECT_THROW(LabelledArraysLabelledControlArray_equal(nullptr, a2),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledControlArray_equal(arrays, nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledControlArray_not_equal(nullptr, a2),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledControlArray_not_equal(arrays, nullptr),
               std::invalid_argument);

  LabelledArraysLabelledControlArray_destroy(a2);
  ListLabelledControlArray_destroy(l2);
}

TEST_F(LabelledArraysLabelledControlArrayTest, Intersection) {
  auto l2 = ListLabelledControlArray_create_empty();
  ListLabelledControlArray_push_back(l2, arr1);
  auto a2 = LabelledArraysLabelledControlArray_create(l2);

  auto inter = LabelledArraysLabelledControlArray_intersection(arrays, a2);
  EXPECT_EQ(LabelledArraysLabelledControlArray_size(inter), 1);
  auto at0 = LabelledArraysLabelledControlArray_at(inter, 0);
  EXPECT_TRUE(LabelledArraysLabelledControlArray_contains(inter, arr1));
  LabelledControlArray_destroy(at0);
  LabelledArraysLabelledControlArray_destroy(inter);

  EXPECT_THROW(LabelledArraysLabelledControlArray_intersection(nullptr, a2),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledControlArray_intersection(arrays, nullptr),
               std::invalid_argument);

  LabelledArraysLabelledControlArray_destroy(a2);
  ListLabelledControlArray_destroy(l2);
}

TEST_F(LabelledArraysLabelledControlArrayTest, ToJsonFromJson) {
  auto json = LabelledArraysLabelledControlArray_to_json_string(arrays);
  auto arr2 = LabelledArraysLabelledControlArray_from_json_string(json);
  EXPECT_TRUE(LabelledArraysLabelledControlArray_equal(arrays, arr2));
  LabelledArraysLabelledControlArray_destroy(arr2);
  String_destroy(json);

  EXPECT_THROW(LabelledArraysLabelledControlArray_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledArraysLabelledControlArray_from_json_string(nullptr),
               std::invalid_argument);
}
