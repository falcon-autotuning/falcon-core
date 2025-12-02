#include <gtest/gtest.h>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/arrays/ControlArray_c_api.h"

class ControlArrayTest : public ::testing::Test {
 protected:
  void SetUp() override {
    shape2d[0] = 2;
    shape2d[1] = 3;
    data2d[0]  = 1.0;
    data2d[1]  = 2.0;
    data2d[2]  = 3.0;
    data2d[3]  = 1.0;
    data2d[4]  = 2.0;
    data2d[5]  = 3.0;
    ca2d       = ControlArray_from_data(data2d, shape2d, 2);

    // 1D array for some tests
    shape1d[0] = 3;
    for (int i = 0; i < 3; ++i) data1d[i] = data2d[i];
    ca1d = ControlArray_from_data(data1d, shape1d, 1);

    fa2d = FArrayDouble_times_double(FArrayDouble_from_data(data2d, shape2d, 2),
                                     2.0);
    ca2d_2 = ControlArray_from_farray(fa2d);
  }
  void TearDown() override {
    ControlArray_destroy(ca2d);
    ControlArray_destroy(ca1d);
    ControlArray_destroy(ca2d_2);
    FArrayDouble_destroy(fa2d);
  }
  double             data2d[6];
  size_t             shape2d[2];
  double             data1d[6];
  size_t             shape1d[1];
  ControlArrayHandle ca2d;
  ControlArrayHandle ca1d;
  ControlArrayHandle ca2d_2;
  FArrayDoubleHandle fa2d;
};

TEST_F(ControlArrayTest, CreateDestroy) {
  auto ca3 = ControlArray_from_data(data2d, shape2d, 2);
  ControlArray_destroy(ca3);
  set_last_error(0, nullptr);
  ControlArray_from_data(nullptr, shape2d, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_from_data(data2d, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_from_farray(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ControlArrayTest, SizeDimensionShapeData) {
  EXPECT_EQ(ControlArray_size(ca2d), 6);
  EXPECT_EQ(ControlArray_dimension(ca2d), 2);
  size_t out_shape[2];
  EXPECT_EQ(ControlArray_shape(ca2d, out_shape, 2), 2);
  EXPECT_EQ(out_shape[0], 2);
  EXPECT_EQ(out_shape[1], 3);
  double out_data[6];
  EXPECT_EQ(ControlArray_data(ca2d, out_data, 6), 6);
  for (int i = 0; i < 6; ++i) EXPECT_EQ(out_data[i], data2d[i]);
  set_last_error(0, nullptr);
  ControlArray_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_dimension(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_shape(nullptr, out_shape, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_data(nullptr, out_data, 6);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ControlArrayTest, ArithmeticOperators) {
  ControlArray_plus_equals_farray(ca2d, fa2d);
  ControlArray_plus_equals_double(ca2d, 1.0);
  ControlArray_plus_equals_int(ca2d, 1);
  auto ca_plus_ca = ControlArray_plus_control_array(ca2d, ca2d_2);
  auto ca_plus_fa = ControlArray_plus_farray(ca2d, fa2d);
  auto ca_plus_d  = ControlArray_plus_double(ca2d, 1.0);
  auto ca_plus_i  = ControlArray_plus_int(ca2d, 1);
  ControlArray_destroy(ca_plus_ca);
  ControlArray_destroy(ca_plus_fa);
  ControlArray_destroy(ca_plus_d);
  ControlArray_destroy(ca_plus_i);

  ControlArray_minus_equals_farray(ca2d, fa2d);
  ControlArray_minus_equals_double(ca2d, 1.0);
  ControlArray_minus_equals_int(ca2d, 1);
  auto ca_minus_ca = ControlArray_minus_control_array(ca2d, ca2d_2);
  auto ca_minus_fa = ControlArray_minus_farray(ca2d, fa2d);
  auto ca_minus_d  = ControlArray_minus_double(ca2d, 1.0);
  auto ca_minus_i  = ControlArray_minus_int(ca2d, 1);
  ControlArray_destroy(ca_minus_ca);
  ControlArray_destroy(ca_minus_fa);
  ControlArray_destroy(ca_minus_d);
  ControlArray_destroy(ca_minus_i);

  auto ca_neg = ControlArray_negation(ca2d);
  ControlArray_destroy(ca_neg);

  ControlArray_times_equals_double(ca2d, 2.0);
  ControlArray_times_equals_int(ca2d, 2);
  auto ca_times_d = ControlArray_times_double(ca2d, 2.0);
  auto ca_times_i = ControlArray_times_int(ca2d, 2);
  ControlArray_destroy(ca_times_d);
  ControlArray_destroy(ca_times_i);

  ControlArray_divides_equals_double(ca2d, 2.0);
  ControlArray_divides_equals_int(ca2d, 2);
  auto ca_div_d = ControlArray_divides_double(ca2d, 2.0);
  auto ca_div_i = ControlArray_divides_int(ca2d, 2);
  ControlArray_destroy(ca_div_d);
  ControlArray_destroy(ca_div_i);

  auto ca_pow = ControlArray_pow(ca2d, 2.0);
  ControlArray_destroy(ca_pow);

  auto ca_abs = ControlArray_abs(ca2d);
  ControlArray_destroy(ca_abs);

  auto ca_min_fa = ControlArray_min_farray(ca2d, fa2d);
  auto ca_min_ca = ControlArray_min_control_array(ca2d, ca2d_2);
  ControlArray_destroy(ca_min_fa);
  ControlArray_destroy(ca_min_ca);

  auto ca_max_fa = ControlArray_max_farray(ca2d, fa2d);
  auto ca_max_ca = ControlArray_max_control_array(ca2d, ca2d_2);
  ControlArray_destroy(ca_max_fa);
  ControlArray_destroy(ca_max_ca);

  set_last_error(0, nullptr);
  ControlArray_plus_equals_farray(nullptr, fa2d);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_plus_equals_farray(ca2d, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_plus_equals_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_plus_equals_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_plus_control_array(nullptr, ca2d_2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_plus_control_array(ca2d, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_plus_farray(nullptr, fa2d);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_plus_farray(ca2d, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_plus_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_plus_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  ControlArray_minus_equals_farray(nullptr, fa2d);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_minus_equals_farray(ca2d, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_minus_equals_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_minus_equals_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_minus_control_array(nullptr, ca2d_2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_minus_control_array(ca2d, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_minus_farray(nullptr, fa2d);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_minus_farray(ca2d, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_minus_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_minus_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  ControlArray_negation(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  ControlArray_times_equals_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_times_equals_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_times_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_times_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  ControlArray_divides_equals_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_divides_equals_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_divides_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_divides_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  ControlArray_pow(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_abs(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  ControlArray_min_farray(nullptr, fa2d);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_min_farray(ca2d, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_min_control_array(nullptr, ca2d_2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_min_control_array(ca2d, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  ControlArray_max_farray(nullptr, fa2d);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_max_farray(ca2d, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_max_control_array(nullptr, ca2d_2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_max_control_array(ca2d, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ControlArrayTest, EqualityOperators) {
  EXPECT_FALSE(ControlArray_equal(ca2d, ca2d_2));
  EXPECT_TRUE(ControlArray_not_equal(ca2d, ca2d_2));
  set_last_error(0, nullptr);
  ControlArray_equal(nullptr, ca2d_2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_equal(ca2d, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_not_equal(nullptr, ca2d_2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_not_equal(ca2d, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ControlArrayTest, ComparisonOperators) {
  EXPECT_TRUE(ControlArray_greater_than(ca2d, 0.5));
  EXPECT_FALSE(ControlArray_less_than(ca2d, 0.5));
  set_last_error(0, nullptr);
  ControlArray_greater_than(nullptr, 0.5);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_less_than(nullptr, 0.5);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ControlArrayTest, OffsetSumWhereFlipGradient) {
  ControlArray_remove_offset(ca2d, 1.0);
  EXPECT_DOUBLE_EQ(ControlArray_sum(ca2d), 6.0);
  auto where   = ControlArray_where(ca2d, 2.0);
  auto flipped = ControlArray_flip(ca2d, 0);
  ControlArray_destroy(flipped);
  FArrayDoubleHandle grad_buffer[2];
  EXPECT_EQ(ControlArray_full_gradient(ca2d, grad_buffer, 2), 2);
  for (size_t i = 0; i < 2; ++i) {
    FArrayDouble_destroy(grad_buffer[i]);
  }
  auto grad = ControlArray_gradient(ca2d, 0);
  FArrayDouble_destroy(grad);
  set_last_error(0, nullptr);
  ControlArray_remove_offset(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_sum(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_where(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_flip(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_full_gradient(nullptr, grad_buffer, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_full_gradient(ca2d, nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_gradient(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ControlArrayTest, SumOfSquares) {
  EXPECT_DOUBLE_EQ(ControlArray_get_sum_of_squares(ca2d), 28.0);
  EXPECT_DOUBLE_EQ(ControlArray_get_summed_diff_int_of_squares(ca2d, 1), 10.0);
  EXPECT_DOUBLE_EQ(ControlArray_get_summed_diff_double_of_squares(ca2d, 1.0),
                   10.0);
  EXPECT_DOUBLE_EQ(ControlArray_get_summed_diff_array_of_squares(ca2d, ca2d_2),
                   28);
  set_last_error(0, nullptr);
  ControlArray_get_sum_of_squares(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_get_summed_diff_int_of_squares(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_get_summed_diff_double_of_squares(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_get_summed_diff_array_of_squares(nullptr, ca2d_2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_get_summed_diff_array_of_squares(ca2d, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ControlArrayTest, ToJsonFromJson) {
  auto json = ControlArray_to_json_string(ca2d);
  auto ca3  = ControlArray_from_json_string(json);
  EXPECT_TRUE(ControlArray_equal(ca2d, ca3));
  ControlArray_destroy(ca3);
  String_destroy(json);
  set_last_error(0, nullptr);
  ControlArray_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  ControlArray_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ControlArrayTest, ShapeBufferTooSmall) {
  size_t out_shape[1] = {0};  // buffer smaller than needed (should be 2)
  // Should only fill one element, return 1
  EXPECT_EQ(FArrayDouble_shape(ca2d, out_shape, 1), 1);
  EXPECT_EQ(out_shape[0], 2);
}

TEST_F(ControlArrayTest, FullGradientBufferTooSmall) {
  FArrayDoubleHandle grads[1];  // buffer smaller than needed
  // Should throw or error if more gradients than buffer
  set_last_error(0, nullptr);
  FArrayDouble_full_gradient(ca2d, grads, 1);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ControlArrayTest, DataBufferTooSmall) {
  double out_data[2] = {0, 0};  // buffer smaller than needed (should be 4)
  set_last_error(0, nullptr);
  FArrayDouble_data(ca2d, out_data, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(ControlArrayTest, DataNullBuffer) {
  set_last_error(0, nullptr);
  FArrayDouble_data(ca2d, nullptr, 4);
  EXPECT_EQ(get_last_error_code(), 1);
}
