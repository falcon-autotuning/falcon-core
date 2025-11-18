#include <gtest/gtest.h>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"

class FArrayDoubleTest : public ::testing::Test {
 protected:
  void SetUp() override {
    shape[0]       = 2;
    shape[1]       = 2;
    arr1           = FArrayDouble_create_zeros(shape, 2);
    arr2           = FArrayDouble_from_shape(shape, 2);
    double data[4] = {1.0, 2.0, 3.0, 4.0};
    arr3           = FArrayDouble_from_data(data, shape, 2);
  }
  void TearDown() override {
    FArrayDouble_destroy(arr1);
    FArrayDouble_destroy(arr2);
    FArrayDouble_destroy(arr3);
  }
  size_t             shape[2];
  FArrayDoubleHandle arr1 = nullptr, arr2 = nullptr, arr3 = nullptr;
};

TEST_F(FArrayDoubleTest, CreateDestroy) {
  FArrayDoubleHandle empty = FArrayDouble_create_empty(shape, 2);
  FArrayDouble_destroy(empty);

  FArrayDoubleHandle zeros = FArrayDouble_create_zeros(shape, 2);
  FArrayDouble_destroy(zeros);

  FArrayDoubleHandle from_shape = FArrayDouble_from_shape(shape, 2);
  FArrayDouble_destroy(from_shape);

  double             data[4]   = {1.0, 2.0, 3.0, 4.0};
  FArrayDoubleHandle from_data = FArrayDouble_from_data(data, shape, 2);
  FArrayDouble_destroy(from_data);

  set_last_error(0, nullptr);
  FArrayDouble_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(FArrayDoubleTest, NullptrCoverage) {
  double data[4] = {1.0, 2.0, 3.0, 4.0};
  set_last_error(0, nullptr);
  FArrayDouble_create_zeros(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_from_shape(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_from_data(nullptr, shape, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_from_data(data, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_dimension(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_shape(nullptr, shape, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_shape(arr1, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_data(nullptr, data, 4);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_plusequals_farray(nullptr, arr1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_plusequals_farray(arr1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_plusequals_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_plusequals_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_plus_farray(nullptr, arr1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_plus_farray(arr1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_plus_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_plus_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_minusequals_farray(nullptr, arr1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_minusequals_farray(arr1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_minusequals_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_minusequals_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_minus_farray(nullptr, arr1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_minus_farray(arr1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_minus_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_minus_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_negation(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_timesequals_farray(nullptr, arr1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_timesequals_farray(arr1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_timesequals_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_timesequals_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_times_farray(nullptr, arr1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_times_farray(arr1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_times_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_times_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_dividesequals_farray(nullptr, arr1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_dividesequals_farray(arr1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_dividesequals_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_dividesequals_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_divides_farray(nullptr, arr1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_divides_farray(arr1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_divides_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_divides_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_pow(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_abs(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_min(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_min_arraywise(nullptr, arr1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_min_arraywise(arr1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_max(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_max_arraywise(nullptr, arr1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_max_arraywise(arr1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_equality(nullptr, arr1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_equality(arr1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_notequality(nullptr, arr1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_notequality(arr1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_greaterthan(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_lessthan(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_remove_offset(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_sum(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_reshape(nullptr, shape, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_where(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_flip(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_full_gradient(nullptr, nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_full_gradient(arr1, nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_gradient(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_get_sum_of_squares(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_get_summed_diff_int_of_squares(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_get_summed_diff_double_of_squares(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_get_summed_diff_array_of_squares(nullptr, arr1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_get_summed_diff_array_of_squares(arr1, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  FArrayDouble_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(FArrayDoubleTest, BasicProperties) {
  EXPECT_EQ(FArrayDouble_size(arr1), 4);
  EXPECT_EQ(FArrayDouble_dimension(arr1), 2);
  size_t out_shape[2] = {0, 0};
  EXPECT_EQ(FArrayDouble_shape(arr1, out_shape, 2), 2);
  EXPECT_EQ(out_shape[0], 2);
  EXPECT_EQ(out_shape[1], 2);

  double out_data[4] = {0};
  EXPECT_EQ(FArrayDouble_data(arr1, out_data, 4), 4);
}

TEST_F(FArrayDoubleTest, ArithmeticAndComparison) {
  FArrayDoubleHandle arr4 = FArrayDouble_create_zeros(shape, 2);
  EXPECT_TRUE(FArrayDouble_equality(arr1, arr1));
  EXPECT_FALSE(FArrayDouble_notequality(arr1, arr4));
  EXPECT_TRUE(FArrayDouble_greaterthan(arr1, -1000.0));
  EXPECT_FALSE(FArrayDouble_lessthan(arr1, -1000.0));
  FArrayDouble_plusequals_farray(arr1, arr4);
  FArrayDouble_plusequals_double(arr1, 1.0);
  FArrayDouble_plusequals_int(arr1, 1);
  FArrayDouble_minusequals_farray(arr1, arr4);
  FArrayDouble_minusequals_double(arr1, 1.0);
  FArrayDouble_minusequals_int(arr1, 1);
  FArrayDouble_timesequals_farray(arr1, arr4);
  FArrayDouble_timesequals_double(arr1, 2.0);
  FArrayDouble_timesequals_int(arr1, 2);
  FArrayDouble_dividesequals_farray(arr1, arr4);
  FArrayDouble_dividesequals_double(arr1, 2.0);
  FArrayDouble_dividesequals_int(arr1, 2);

  FArrayDoubleHandle arr5  = FArrayDouble_plus_farray(arr1, arr4);
  FArrayDoubleHandle arr6  = FArrayDouble_plus_double(arr1, 1.0);
  FArrayDoubleHandle arr7  = FArrayDouble_plus_int(arr1, 1);
  FArrayDoubleHandle arr8  = FArrayDouble_minus_farray(arr1, arr4);
  FArrayDoubleHandle arr9  = FArrayDouble_minus_double(arr1, 1.0);
  FArrayDoubleHandle arr10 = FArrayDouble_minus_int(arr1, 1);
  FArrayDoubleHandle arr11 = FArrayDouble_times_farray(arr1, arr4);
  FArrayDoubleHandle arr12 = FArrayDouble_times_double(arr1, 2.0);
  FArrayDoubleHandle arr13 = FArrayDouble_times_int(arr1, 2);
  FArrayDoubleHandle arr14 = FArrayDouble_divides_farray(arr1, arr4);
  FArrayDoubleHandle arr15 = FArrayDouble_divides_double(arr1, 2.0);
  FArrayDoubleHandle arr16 = FArrayDouble_divides_int(arr1, 2);
  FArrayDoubleHandle arr17 = FArrayDouble_pow(arr1, 2.0);
  FArrayDoubleHandle arr18 = FArrayDouble_abs(arr1);
  double             num1  = FArrayDouble_min(arr1);
  FArrayDoubleHandle arr19 = FArrayDouble_min_arraywise(arr1, arr4);
  double             num2  = FArrayDouble_max(arr1);
  FArrayDoubleHandle arr20 = FArrayDouble_max_arraywise(arr1, arr4);
  FArrayDoubleHandle arr21 = FArrayDouble_negation(arr1);
  FArrayDoubleHandle arr22 = FArrayDouble_reshape(arr1, shape, 2);
  FArrayDoubleHandle arr23 = FArrayDouble_gradient(arr1, 0);
  FArrayDoubleHandle arr24 = FArrayDouble_flip(arr1, 0);

  FArrayDouble_destroy(arr4);
  FArrayDouble_destroy(arr5);
  FArrayDouble_destroy(arr6);
  FArrayDouble_destroy(arr7);
  FArrayDouble_destroy(arr8);
  FArrayDouble_destroy(arr9);
  FArrayDouble_destroy(arr10);
  FArrayDouble_destroy(arr11);
  FArrayDouble_destroy(arr12);
  FArrayDouble_destroy(arr13);
  FArrayDouble_destroy(arr14);
  FArrayDouble_destroy(arr15);
  FArrayDouble_destroy(arr16);
  FArrayDouble_destroy(arr17);
  FArrayDouble_destroy(arr18);
  FArrayDouble_destroy(arr20);
  FArrayDouble_destroy(arr21);
  FArrayDouble_destroy(arr22);
  FArrayDouble_destroy(arr23);
  FArrayDouble_destroy(arr24);
}

TEST_F(FArrayDoubleTest, Miscellaneous) {
  FArrayDouble_remove_offset(arr3, 1.0);
  EXPECT_GE(FArrayDouble_sum(arr3), 0.0);
  double sumsq = FArrayDouble_get_sum_of_squares(arr3);
  EXPECT_GE(sumsq, 0.0);
  EXPECT_NO_THROW(FArrayDouble_get_summed_diff_int_of_squares(arr3, 1));
  EXPECT_NO_THROW(FArrayDouble_get_summed_diff_double_of_squares(arr3, 1.0));
  EXPECT_NO_THROW(FArrayDouble_get_summed_diff_array_of_squares(arr3, arr2));
  ListListSizeTHandle where = FArrayDouble_where(arr3, 0.0);
  EXPECT_NO_THROW({
    FArrayDoubleHandle grads[2];
    size_t             n = FArrayDouble_full_gradient(arr3, grads, 2);
    for (size_t i = 0; i < n; ++i) FArrayDouble_destroy(grads[i]);
  });
  StringHandle       json          = FArrayDouble_to_json_string(arr3);
  FArrayDoubleHandle arr_from_json = FArrayDouble_from_json_string(json);
  FArrayDouble_destroy(arr_from_json);
  String_destroy(json);
}

TEST_F(FArrayDoubleTest, ShapeBufferTooSmall) {
  size_t out_shape[1] = {0};  // buffer smaller than needed (should be 2)
  // Should only fill one element, return 1
  EXPECT_EQ(FArrayDouble_shape(arr1, out_shape, 1), 1);
  EXPECT_EQ(out_shape[0], 2);
}

TEST_F(FArrayDoubleTest, FullGradientBufferTooSmall) {
  FArrayDoubleHandle grads[1];  // buffer smaller than needed
  // Should throw or error if more gradients than buffer
  set_last_error(0, nullptr);
  FArrayDouble_full_gradient(arr1, grads, 1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(FArrayDoubleTest, DataBufferTooSmall) {
  double out_data[2] = {0, 0};  // buffer smaller than needed (should be 4)
  set_last_error(0, nullptr);
  FArrayDouble_data(arr1, out_data, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(FArrayDoubleTest, DataNullBuffer) {
  set_last_error(0, nullptr);
  FArrayDouble_data(arr1, nullptr, 4);
  EXPECT_EQ(get_last_error_code(), 1);
}
