#include <gtest/gtest.h>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/arrays/MeasuredArray_c_api.h"

class MeasuredArrayTest : public ::testing::Test {
 protected:
  void SetUp() override {
    shape[0] = 6;
    data[0]  = 1.0;
    data[1]  = 2.0;
    data[2]  = 3.0;
    data[3]  = 4.0;
    data[4]  = 5.0;
    data[5]  = 6.0;
    ma       = MeasuredArray_from_data(data, shape, 1);
    fa       = FArrayDouble_from_data(data, shape, 1);
    ma2      = MeasuredArray_from_farray(fa);
  }
  void TearDown() override {
    MeasuredArray_destroy(ma);
    MeasuredArray_destroy(ma2);
    FArrayDouble_destroy(fa);
  }
  double              data[6];
  size_t              shape[1];
  MeasuredArrayHandle ma;
  MeasuredArrayHandle ma2;
  FArrayDoubleHandle  fa;
};

TEST_F(MeasuredArrayTest, CreateDestroy) {
  auto ma3 = MeasuredArray_from_data(data, shape, 1);
  MeasuredArray_destroy(ma3);
  set_last_error(0, nullptr);
  MeasuredArray_from_data(nullptr, shape, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_from_data(data, nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_from_farray(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MeasuredArrayTest, SizeDimensionShapeData) {
  EXPECT_EQ(MeasuredArray_size(ma), 6);
  EXPECT_EQ(MeasuredArray_dimension(ma), 1);
  size_t out_shape[1];
  EXPECT_EQ(MeasuredArray_shape(ma, out_shape, 1), 1);
  EXPECT_EQ(out_shape[0], 6);
  double out_data[6];
  EXPECT_EQ(MeasuredArray_data(ma, out_data, 6), 6);
  for (int i = 0; i < 6; ++i) EXPECT_EQ(out_data[i], data[i]);
  set_last_error(0, nullptr);
  MeasuredArray_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_dimension(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_shape(nullptr, out_shape, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_data(nullptr, out_data, 6);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MeasuredArrayTest, Addition) {
  MeasuredArray_plusequals_farray(ma, fa);
  MeasuredArray_plusequals_double(ma, 1.0);
  MeasuredArray_plusequals_int(ma, 1);
  auto ma_plus_ma = MeasuredArray_plus_control_array(ma, ma2);
  auto ma_plus_fa = MeasuredArray_plus_farray(ma, fa);
  auto ma_plus_d  = MeasuredArray_plus_double(ma, 1.0);
  auto ma_plus_i  = MeasuredArray_plus_int(ma, 1);
  MeasuredArray_destroy(ma_plus_ma);
  MeasuredArray_destroy(ma_plus_fa);
  MeasuredArray_destroy(ma_plus_d);
  MeasuredArray_destroy(ma_plus_i);
}

TEST_F(MeasuredArrayTest, Subtraction) {
  MeasuredArray_minusequals_farray(ma, fa);
  MeasuredArray_minusequals_double(ma, 1.0);
  MeasuredArray_minusequals_int(ma, 1);
  auto ma_minus_ma = MeasuredArray_minus_control_array(ma, ma2);
  auto ma_minus_fa = MeasuredArray_minus_farray(ma, fa);
  auto ma_minus_d  = MeasuredArray_minus_double(ma, 1.0);
  auto ma_minus_i  = MeasuredArray_minus_int(ma, 1);
  MeasuredArray_destroy(ma_minus_ma);
  MeasuredArray_destroy(ma_minus_fa);
  MeasuredArray_destroy(ma_minus_d);
  MeasuredArray_destroy(ma_minus_i);
}

TEST_F(MeasuredArrayTest, Negation) {
  auto ma_neg = MeasuredArray_negation(ma);
  MeasuredArray_destroy(ma_neg);
}

TEST_F(MeasuredArrayTest, Multiplication) {
  MeasuredArray_timesequals_measured_array(ma, ma2);
  MeasuredArray_timesequals_farray(ma, fa);
  MeasuredArray_timesequals_double(ma, 2.0);
  MeasuredArray_timesequals_int(ma, 2);
  auto ma_times_ma = MeasuredArray_times_measured_array(ma, ma2);
  auto ma_times_fa = MeasuredArray_times_farray(ma, fa);
  auto ma_times_d  = MeasuredArray_times_double(ma, 2.0);
  auto ma_times_i  = MeasuredArray_times_int(ma, 2);
  MeasuredArray_destroy(ma_times_ma);
  MeasuredArray_destroy(ma_times_fa);
  MeasuredArray_destroy(ma_times_d);
  MeasuredArray_destroy(ma_times_i);
}

TEST_F(MeasuredArrayTest, Division) {
  MeasuredArray_dividesequals_measured_array(ma, ma2);
  MeasuredArray_dividesequals_farray(ma, fa);
  MeasuredArray_dividesequals_double(ma, 2.0);
  MeasuredArray_dividesequals_int(ma, 2);
  auto ma_div_ma = MeasuredArray_divides_measured_array(ma, ma2);
  auto ma_div_fa = MeasuredArray_divides_farray(ma, fa);
  auto ma_div_d  = MeasuredArray_divides_double(ma, 2.0);
  auto ma_div_i  = MeasuredArray_divides_int(ma, 2);
  MeasuredArray_destroy(ma_div_ma);
  MeasuredArray_destroy(ma_div_fa);
  MeasuredArray_destroy(ma_div_d);
  MeasuredArray_destroy(ma_div_i);
}

TEST_F(MeasuredArrayTest, Operations) {
  auto ma_pow = MeasuredArray_pow(ma, 2.0);
  MeasuredArray_destroy(ma_pow);

  auto ma_abs = MeasuredArray_abs(ma);
  MeasuredArray_destroy(ma_abs);

  auto ma_min_fa = MeasuredArray_min_farray(ma, fa);
  auto ma_min_ma = MeasuredArray_min_control_array(ma, ma2);
  MeasuredArray_destroy(ma_min_fa);
  MeasuredArray_destroy(ma_min_ma);

  auto ma_max_fa = MeasuredArray_max_farray(ma, fa);
  auto ma_max_ma = MeasuredArray_max_control_array(ma, ma2);
  MeasuredArray_destroy(ma_max_fa);
  MeasuredArray_destroy(ma_max_ma);
}

TEST_F(MeasuredArrayTest, ArithmeticOperatorsInvalidArgs) {
  set_last_error(0, nullptr);
  MeasuredArray_plusequals_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_plusequals_farray(ma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_plusequals_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_plusequals_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_plus_control_array(nullptr, ma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_plus_control_array(ma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_plus_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_plus_farray(ma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_plus_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_plus_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MeasuredArray_minusequals_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_minusequals_farray(ma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_minusequals_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_minusequals_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_minus_control_array(nullptr, ma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_minus_control_array(ma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_minus_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_minus_farray(ma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_minus_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_minus_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MeasuredArray_negation(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MeasuredArray_timesequals_measured_array(nullptr, ma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_timesequals_measured_array(ma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_timesequals_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_timesequals_farray(ma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_timesequals_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_timesequals_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_times_measured_array(nullptr, ma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_times_measured_array(ma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_times_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_times_farray(ma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_times_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_times_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MeasuredArray_dividesequals_measured_array(nullptr, ma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_dividesequals_measured_array(ma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_dividesequals_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_dividesequals_farray(ma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_dividesequals_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_dividesequals_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_divides_measured_array(nullptr, ma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_divides_measured_array(ma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_divides_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_divides_farray(ma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_divides_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_divides_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MeasuredArray_pow(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_abs(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MeasuredArray_min_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_min_farray(ma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_min_control_array(nullptr, ma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_min_control_array(ma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  MeasuredArray_max_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_max_farray(ma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_max_control_array(nullptr, ma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_max_control_array(ma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MeasuredArrayTest, EqualityOperators) {
  EXPECT_TRUE(MeasuredArray_equality(ma, ma2));
  EXPECT_FALSE(MeasuredArray_notequality(ma, ma2));
  set_last_error(0, nullptr);
  MeasuredArray_equality(nullptr, ma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_equality(ma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_notequality(nullptr, ma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_notequality(ma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MeasuredArrayTest, ComparisonOperators) {
  EXPECT_TRUE(MeasuredArray_greaterthan(ma, 0.5));
  EXPECT_FALSE(MeasuredArray_lessthan(ma, 0.5));
  set_last_error(0, nullptr);
  MeasuredArray_greaterthan(nullptr, 0.5);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_lessthan(nullptr, 0.5);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MeasuredArrayTest, OffsetSumReshapeWhereFlipGradient) {
  MeasuredArray_remove_offset(ma, 1.0);
  EXPECT_DOUBLE_EQ(MeasuredArray_sum(ma), 15.0);
  size_t new_shape[1] = {6};
  auto   reshaped     = MeasuredArray_reshape(ma, new_shape, 1);
  MeasuredArray_destroy(reshaped);
  auto where   = MeasuredArray_where(ma, 2.0);
  auto flipped = MeasuredArray_flip(ma, 0);
  MeasuredArray_destroy(flipped);
  MeasuredArrayHandle grad_buffer[1];
  EXPECT_EQ(MeasuredArray_full_gradient(ma, grad_buffer, 1), 1);
  for (size_t i = 0; i < 1; ++i) {
    MeasuredArray_destroy(grad_buffer[i]);
  }
  auto grad = MeasuredArray_gradient(ma, 0);
  MeasuredArray_destroy(grad);
  set_last_error(0, nullptr);
  MeasuredArray_remove_offset(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_sum(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_reshape(nullptr, new_shape, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_where(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_flip(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_full_gradient(nullptr, grad_buffer, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_full_gradient(ma, nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_gradient(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MeasuredArrayTest, SumOfSquares) {
  EXPECT_DOUBLE_EQ(MeasuredArray_get_sum_of_squares(ma), 91.0);
  EXPECT_DOUBLE_EQ(MeasuredArray_get_summed_diff_int_of_squares(ma, 1), 55.0);
  EXPECT_DOUBLE_EQ(MeasuredArray_get_summed_diff_double_of_squares(ma, 1.0),
                   55.0);
  EXPECT_DOUBLE_EQ(MeasuredArray_get_summed_diff_array_of_squares(ma, ma2),
                   0.0);
  set_last_error(0, nullptr);
  MeasuredArray_get_sum_of_squares(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_get_summed_diff_int_of_squares(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_get_summed_diff_double_of_squares(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_get_summed_diff_array_of_squares(nullptr, ma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_get_summed_diff_array_of_squares(ma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MeasuredArrayTest, ToJsonFromJson) {
  auto json = MeasuredArray_to_json_string(ma);
  auto ma3  = MeasuredArray_from_json_string(json);
  EXPECT_TRUE(MeasuredArray_equality(ma, ma3));
  MeasuredArray_destroy(ma3);
  String_destroy(json);
  set_last_error(0, nullptr);
  MeasuredArray_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MeasuredArrayTest, DataBufferTooSmall) {
  double out_data[2] = {0, 0};  // buffer smaller than needed (should be 4)
  set_last_error(0, nullptr);
  FArrayDouble_data(ma, out_data, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MeasuredArrayTest, DataNullBuffer) {
  set_last_error(0, nullptr);
  FArrayDouble_data(ma, nullptr, 4);
  EXPECT_EQ(get_last_error_code(), 1);
}
