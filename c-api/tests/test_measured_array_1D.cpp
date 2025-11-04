#include <gtest/gtest.h>

#include <cmath>

#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/arrays/MeasuredArray1D_c_api.h"

class MeasuredArray1DTest : public ::testing::Test {
 protected:
  void SetUp() override {
    shape[0] = 6;
    data[0]  = 1.0;
    data[1]  = 2.0;
    data[2]  = 3.0;
    data[3]  = 4.0;
    data[4]  = 5.0;
    data[5]  = 6.0;
    ma       = MeasuredArray1D_from_data(data, shape, 1);
    fa       = FArrayDouble_from_data(data, shape, 6);
    ma2      = MeasuredArray1D_from_farray(fa);
  }
  void TearDown() override {
    MeasuredArray1D_destroy(ma);
    MeasuredArray1D_destroy(ma2);
    FArrayDouble_destroy(fa);
  }
  double                data[6];
  size_t                shape[1];
  MeasuredArray1DHandle ma  = nullptr;
  MeasuredArray1DHandle ma2 = nullptr;
  FArrayDoubleHandle    fa  = nullptr;
};

TEST_F(MeasuredArray1DTest, CreateDestroy) {
  auto ma3 = MeasuredArray1D_from_data(data, shape, 1);
  MeasuredArray1D_destroy(ma3);
  EXPECT_THROW(MeasuredArray1D_from_data(nullptr, shape, 1),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_from_data(data, nullptr, 1),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_from_data(data, shape, 0),
               std::invalid_argument);
  size_t bad_shape[1] = {0};
  EXPECT_THROW(MeasuredArray1D_from_data(data, bad_shape, 1),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_from_data(data, shape, 2),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_from_farray(nullptr), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_destroy(nullptr), std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, Accessors) {
  EXPECT_TRUE(MeasuredArray1D_is_1D(ma));
  auto fa1 = MeasuredArray1D_as_1D(ma);
  FArrayDouble_destroy(fa1);
  EXPECT_DOUBLE_EQ(MeasuredArray1D_get_start(ma), 1.0);
  EXPECT_DOUBLE_EQ(MeasuredArray1D_get_end(ma), 6.0);
  EXPECT_FALSE(MeasuredArray1D_is_decreasing(ma));
  EXPECT_TRUE(MeasuredArray1D_is_increasing(ma));
  EXPECT_DOUBLE_EQ(MeasuredArray1D_get_distance(ma), 5.0);
  EXPECT_DOUBLE_EQ(MeasuredArray1D_get_mean(ma), 3.5);
  EXPECT_DOUBLE_EQ(MeasuredArray1D_get_std(ma),
                   std::sqrt(35.0 / 6.0 - 3.5 * 3.5));
  EXPECT_THROW(MeasuredArray1D_is_1D(nullptr), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_as_1D(nullptr), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_get_start(nullptr), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_get_end(nullptr), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_is_decreasing(nullptr), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_is_increasing(nullptr), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_get_distance(nullptr), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_get_mean(nullptr), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_get_std(nullptr), std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, ReverseAndClosestIndex) {
  MeasuredArray1D_reverse(ma);
  EXPECT_EQ(MeasuredArray1D_get_closest_index(ma, 2.0), 3);
  EXPECT_THROW(MeasuredArray1D_reverse(nullptr), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_get_closest_index(nullptr, 2.0),
               std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, EvenDivisions) {
  auto list = MeasuredArray1D_even_divisions(ma, 2);
  // ListFArrayDouble_destroy(list); // implement destroy if needed
  EXPECT_THROW(MeasuredArray1D_even_divisions(nullptr, 2),
               std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, SizeAndShapeAndData) {
  EXPECT_EQ(MeasuredArray1D_size(ma), 6);
  EXPECT_EQ(MeasuredArray1D_dimension(ma), 1);
  size_t out_shape[1];
  EXPECT_EQ(MeasuredArray1D_shape(ma, out_shape, 1), 1);
  EXPECT_EQ(out_shape[0], 6);
  double out_data[6];
  EXPECT_EQ(MeasuredArray1D_data(ma, out_data, 6), 6);
  for (int i = 0; i < 6; ++i) EXPECT_EQ(out_data[i], data[i]);
  EXPECT_THROW(MeasuredArray1D_size(nullptr), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_dimension(nullptr), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_shape(nullptr, out_shape, 1),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_data(nullptr, out_data, 6),
               std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, ArithmeticOperators) {
  MeasuredArray1D_plusequals_farray(ma, fa);
  MeasuredArray1D_plusequals_double(ma, 1.0);
  MeasuredArray1D_plusequals_int(ma, 1);
  auto ma_plus_ma = MeasuredArray1D_plus_control_array(ma, ma2);
  auto ma_plus_fa = MeasuredArray1D_plus_farray(ma, fa);
  auto ma_plus_d  = MeasuredArray1D_plus_double(ma, 1.0);
  auto ma_plus_i  = MeasuredArray1D_plus_int(ma, 1);
  MeasuredArray1D_destroy(ma_plus_ma);
  MeasuredArray1D_destroy(ma_plus_fa);
  MeasuredArray1D_destroy(ma_plus_d);
  MeasuredArray1D_destroy(ma_plus_i);

  MeasuredArray1D_minusequals_farray(ma, fa);
  MeasuredArray1D_minusequals_double(ma, 1.0);
  MeasuredArray1D_minusequals_int(ma, 1);
  auto ma_minus_ma = MeasuredArray1D_minus_control_array(ma, ma2);
  auto ma_minus_fa = MeasuredArray1D_minus_farray(ma, fa);
  auto ma_minus_d  = MeasuredArray1D_minus_double(ma, 1.0);
  auto ma_minus_i  = MeasuredArray1D_minus_int(ma, 1);
  MeasuredArray1D_destroy(ma_minus_ma);
  MeasuredArray1D_destroy(ma_minus_fa);
  MeasuredArray1D_destroy(ma_minus_d);
  MeasuredArray1D_destroy(ma_minus_i);

  auto ma_neg = MeasuredArray1D_negation(ma);
  MeasuredArray1D_destroy(ma_neg);

  MeasuredArray1D_timesequals_farray(ma, fa);
  MeasuredArray1D_timesequals_double(ma, 2.0);
  MeasuredArray1D_timesequals_int(ma, 2);
  auto ma_times_ma = MeasuredArray1D_times_measured_array(ma, ma2);
  auto ma_times_fa = MeasuredArray1D_times_farray(ma, fa);
  auto ma_times_d  = MeasuredArray1D_times_double(ma, 2.0);
  auto ma_times_i  = MeasuredArray1D_times_int(ma, 2);
  MeasuredArray1D_destroy(ma_times_ma);
  MeasuredArray1D_destroy(ma_times_fa);
  MeasuredArray1D_destroy(ma_times_d);
  MeasuredArray1D_destroy(ma_times_i);

  MeasuredArray1D_dividesequals_farray(ma, fa);
  MeasuredArray1D_dividesequals_double(ma, 2.0);
  MeasuredArray1D_dividesequals_int(ma, 2);
  auto ma_div_ma = MeasuredArray1D_divides_measured_array(ma, ma2);
  auto ma_div_fa = MeasuredArray1D_divides_farray(ma, fa);
  auto ma_div_d  = MeasuredArray1D_divides_double(ma, 2.0);
  auto ma_div_i  = MeasuredArray1D_divides_int(ma, 2);
  MeasuredArray1D_destroy(ma_div_ma);
  MeasuredArray1D_destroy(ma_div_fa);
  MeasuredArray1D_destroy(ma_div_d);
  MeasuredArray1D_destroy(ma_div_i);

  auto ma_pow = MeasuredArray1D_pow(ma, 2.0);
  MeasuredArray1D_destroy(ma_pow);

  auto ma_abs = MeasuredArray1D_abs(ma);
  MeasuredArray1D_destroy(ma_abs);

  auto ma_min_fa = MeasuredArray1D_min_farray(ma, fa);
  auto ma_min_ma = MeasuredArray1D_min_control_array(ma, ma2);
  MeasuredArray1D_destroy(ma_min_fa);
  MeasuredArray1D_destroy(ma_min_ma);

  auto ma_max_fa = MeasuredArray1D_max_farray(ma, fa);
  auto ma_max_ma = MeasuredArray1D_max_control_array(ma, ma2);
  MeasuredArray1D_destroy(ma_max_fa);
  MeasuredArray1D_destroy(ma_max_ma);

  EXPECT_THROW(MeasuredArray1D_plusequals_farray(nullptr, fa),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_plusequals_farray(ma, nullptr),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_plusequals_double(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_plusequals_int(nullptr, 1),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_plus_control_array(nullptr, ma2),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_plus_control_array(ma, nullptr),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_plus_farray(nullptr, fa), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_plus_farray(ma, nullptr), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_plus_double(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_plus_int(nullptr, 1), std::invalid_argument);

  EXPECT_THROW(MeasuredArray1D_minusequals_farray(nullptr, fa),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_minusequals_farray(ma, nullptr),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_minusequals_double(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_minusequals_int(nullptr, 1),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_minus_control_array(nullptr, ma2),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_minus_control_array(ma, nullptr),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_minus_farray(nullptr, fa),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_minus_farray(ma, nullptr),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_minus_double(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_minus_int(nullptr, 1), std::invalid_argument);

  EXPECT_THROW(MeasuredArray1D_negation(nullptr), std::invalid_argument);

  EXPECT_THROW(MeasuredArray1D_timesequals_farray(nullptr, fa),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_timesequals_farray(ma, nullptr),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_timesequals_double(nullptr, 2.0),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_timesequals_int(nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_times_measured_array(nullptr, ma2),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_times_measured_array(ma, nullptr),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_times_farray(nullptr, fa),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_times_farray(ma, nullptr),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_times_double(nullptr, 2.0),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_times_int(nullptr, 2), std::invalid_argument);

  EXPECT_THROW(MeasuredArray1D_dividesequals_farray(nullptr, fa),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_dividesequals_farray(ma, nullptr),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_dividesequals_double(nullptr, 2.0),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_dividesequals_int(nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_divides_measured_array(nullptr, ma2),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_divides_measured_array(ma, nullptr),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_divides_farray(nullptr, fa),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_divides_farray(ma, nullptr),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_divides_double(nullptr, 2.0),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_divides_int(nullptr, 2), std::invalid_argument);

  EXPECT_THROW(MeasuredArray1D_pow(nullptr, 2.0), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_abs(nullptr), std::invalid_argument);

  EXPECT_THROW(MeasuredArray1D_min_farray(nullptr, fa), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_min_farray(ma, nullptr), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_min_control_array(nullptr, ma2),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_min_control_array(ma, nullptr),
               std::invalid_argument);

  EXPECT_THROW(MeasuredArray1D_max_farray(nullptr, fa), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_max_farray(ma, nullptr), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_max_control_array(nullptr, ma2),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_max_control_array(ma, nullptr),
               std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, EqualityOperators) {
  EXPECT_FALSE(MeasuredArray1D_equality(ma, ma2));
  EXPECT_TRUE(MeasuredArray1D_notequality(ma, ma2));
  EXPECT_THROW(MeasuredArray1D_equality(nullptr, ma2), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_equality(ma, nullptr), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_notequality(nullptr, ma2),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_notequality(ma, nullptr), std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, ComparisonOperators) {
  EXPECT_TRUE(MeasuredArray1D_greaterthan(ma, 0.5));
  EXPECT_FALSE(MeasuredArray1D_lessthan(ma, 0.5));
  EXPECT_THROW(MeasuredArray1D_greaterthan(nullptr, 0.5),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_lessthan(nullptr, 0.5), std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, OffsetSumReshapeWhereFlipGradient) {
  MeasuredArray1D_remove_offset(ma, 1.0);
  EXPECT_DOUBLE_EQ(MeasuredArray1D_sum(ma), 21.0);
  size_t new_shape[1] = {6};
  auto   reshaped     = MeasuredArray1D_reshape(ma, new_shape, 1);
  MeasuredArray1D_destroy(reshaped);
  auto where = MeasuredArray1D_where(ma, 2.0);
  // ListListSizeT_destroy(where); // implement destroy if needed
  auto flipped = MeasuredArray1D_flip(ma, 0);
  MeasuredArray1D_destroy(flipped);
  MeasuredArray1DHandle grad_buffer[1];
  EXPECT_EQ(MeasuredArray1D_full_gradient(ma, grad_buffer, 1), 1);
  for (size_t i = 0; i < 1; ++i) {
    MeasuredArray1D_destroy(grad_buffer[i]);
  }
  auto grad = MeasuredArray1D_gradient(ma, 0);
  MeasuredArray1D_destroy(grad);
  EXPECT_THROW(MeasuredArray1D_remove_offset(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_sum(nullptr), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_reshape(nullptr, new_shape, 1),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_where(nullptr, 2.0), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_flip(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_full_gradient(nullptr, grad_buffer, 1),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_gradient(nullptr, 0), std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, SumOfSquares) {
  EXPECT_DOUBLE_EQ(MeasuredArray1D_get_sum_of_squares(ma), 91.0);
  EXPECT_DOUBLE_EQ(MeasuredArray1D_get_summed_diff_int_of_squares(ma, 1), 70.0);
  EXPECT_DOUBLE_EQ(MeasuredArray1D_get_summed_diff_double_of_squares(ma, 1.0),
                   70.0);
  EXPECT_DOUBLE_EQ(MeasuredArray1D_get_summed_diff_array_of_squares(ma, ma2),
                   0.0);
  EXPECT_THROW(MeasuredArray1D_get_sum_of_squares(nullptr),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_get_summed_diff_int_of_squares(nullptr, 1),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_get_summed_diff_double_of_squares(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_get_summed_diff_array_of_squares(nullptr, ma2),
               std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_get_summed_diff_array_of_squares(ma, nullptr),
               std::invalid_argument);
}

TEST_F(MeasuredArray1DTest, ToJsonFromJson) {
  auto json = MeasuredArray1D_to_json_string(ma);
  auto ma3  = MeasuredArray1D_from_json_string(json);
  EXPECT_TRUE(MeasuredArray1D_equality(ma, ma3));
  MeasuredArray1D_destroy(ma3);
  String_destroy(json);
  EXPECT_THROW(MeasuredArray1D_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(MeasuredArray1D_from_json_string(nullptr),
               std::invalid_argument);
}
