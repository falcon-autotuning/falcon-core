#include <gtest/gtest.h>

#include <cmath>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/arrays/ControlArray1D_c_api.h"

class ControlArray1DTest : public ::testing::Test {
 protected:
  void SetUp() override {
    shape[0] = 3;
    data[0]  = 1.0;
    data[1]  = 2.0;
    data[2]  = 3.0;
    shape[0] = 3;
    ca       = ControlArray1D_from_data(data, shape, 1);
    fa = FArrayDouble_times_double(FArrayDouble_from_data(data, shape, 1), 2.0);
    ca2 = ControlArray1D_from_farray(fa);
  }
  void TearDown() override {
    ControlArray1D_destroy(ca);
    ControlArray1D_destroy(ca2);
    FArrayDouble_destroy(fa);
  }
  double               data[3];
  size_t               shape[1];
  ControlArray1DHandle ca;
  ControlArray1DHandle ca2;
  FArrayDoubleHandle   fa;
};

TEST_F(ControlArray1DTest, CreateDestroy) {
  auto ca3 = ControlArray1D_from_data(data, shape, 1);
  ControlArray1D_destroy(ca3);
  EXPECT_THROW(ControlArray1D_from_data(nullptr, shape, 1),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_from_data(data, nullptr, 1),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_from_data(data, shape, 0), std::invalid_argument);
  size_t bad_shape[1] = {0};
  EXPECT_THROW(ControlArray1D_from_data(data, bad_shape, 1),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_from_data(data, shape, 2), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_from_farray(nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_destroy(nullptr), std::invalid_argument);
}

TEST_F(ControlArray1DTest, Accessors) {
  EXPECT_TRUE(ControlArray1D_is_1D(ca));
  auto fa1 = ControlArray1D_as_1D(ca);
  FArrayDouble_destroy(fa1);
  EXPECT_DOUBLE_EQ(ControlArray1D_get_start(ca), 1.0);
  EXPECT_DOUBLE_EQ(ControlArray1D_get_end(ca), 3.0);
  EXPECT_FALSE(ControlArray1D_is_decreasing(ca));
  EXPECT_TRUE(ControlArray1D_is_increasing(ca));
  EXPECT_DOUBLE_EQ(ControlArray1D_get_distance(ca), 2.0);
  EXPECT_DOUBLE_EQ(ControlArray1D_get_mean(ca), 2.0);
  EXPECT_DOUBLE_EQ(ControlArray1D_get_std(ca), std::sqrt(2.0 / 3.0));
  EXPECT_THROW(ControlArray1D_is_1D(nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_as_1D(nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_get_start(nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_get_end(nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_is_decreasing(nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_is_increasing(nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_get_distance(nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_get_mean(nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_get_std(nullptr), std::invalid_argument);
}

TEST_F(ControlArray1DTest, ReverseAndClosestIndex) {
  ControlArray1D_reverse(ca);
  EXPECT_EQ(ControlArray1D_get_closest_index(ca, 2.0), 1);
  EXPECT_THROW(ControlArray1D_reverse(nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_get_closest_index(nullptr, 2.0),
               std::invalid_argument);
}

TEST_F(ControlArray1DTest, EvenDivisions) {
  auto list = ControlArray1D_even_divisions(ca, 3);
  ListFArrayDouble_destroy(list);
  EXPECT_THROW(ControlArray1D_even_divisions(nullptr, 2),
               std::invalid_argument);
}

TEST_F(ControlArray1DTest, SizeAndShapeAndData) {
  EXPECT_EQ(ControlArray1D_size(ca), 3);
  EXPECT_EQ(ControlArray1D_dimension(ca), 1);
  size_t out_shape[1];
  EXPECT_EQ(ControlArray1D_shape(ca, out_shape, 1), 1);
  double out_data[3];
  EXPECT_EQ(ControlArray1D_data(ca, out_data, 3), 3);
  EXPECT_THROW(ControlArray1D_size(nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_dimension(nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_shape(nullptr, out_shape, 1),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_data(nullptr, out_data, 3),
               std::invalid_argument);
}

TEST_F(ControlArray1DTest, ArithmeticOperators) {
  ControlArray1D_plusequals_farray(ca, fa);
  ControlArray1D_plusequals_double(ca, 1.0);
  ControlArray1D_plusequals_int(ca, 1);
  auto ca_plus_ca = ControlArray1D_plus_control_array(ca, ca2);
  auto ca_plus_fa = ControlArray1D_plus_farray(ca, fa);
  auto ca_plus_d  = ControlArray1D_plus_double(ca, 1.0);
  auto ca_plus_i  = ControlArray1D_plus_int(ca, 1);
  ControlArray1D_destroy(ca_plus_ca);
  ControlArray1D_destroy(ca_plus_fa);
  ControlArray1D_destroy(ca_plus_d);
  ControlArray1D_destroy(ca_plus_i);

  ControlArray1D_minusequals_farray(ca, fa);
  ControlArray1D_minusequals_double(ca, 1.0);
  ControlArray1D_minusequals_int(ca, 1);
  auto ca_minus_ca = ControlArray1D_minus_control_array(ca, ca2);
  auto ca_minus_fa = ControlArray1D_minus_farray(ca, fa);
  auto ca_minus_d  = ControlArray1D_minus_double(ca, 1.0);
  auto ca_minus_i  = ControlArray1D_minus_int(ca, 1);
  ControlArray1D_destroy(ca_minus_ca);
  ControlArray1D_destroy(ca_minus_fa);
  ControlArray1D_destroy(ca_minus_d);
  ControlArray1D_destroy(ca_minus_i);

  auto ca_neg = ControlArray1D_negation(ca);
  ControlArray1D_destroy(ca_neg);

  ControlArray1D_timesequals_double(ca, 2.0);
  ControlArray1D_timesequals_int(ca, 2);
  auto ca_times_d = ControlArray1D_times_double(ca, 2.0);
  auto ca_times_i = ControlArray1D_times_int(ca, 2);
  ControlArray1D_destroy(ca_times_d);
  ControlArray1D_destroy(ca_times_i);

  ControlArray1D_dividesequals_double(ca, 2.0);
  ControlArray1D_dividesequals_int(ca, 2);
  auto ca_div_d = ControlArray1D_divides_double(ca, 2.0);
  auto ca_div_i = ControlArray1D_divides_int(ca, 2);
  ControlArray1D_destroy(ca_div_d);
  ControlArray1D_destroy(ca_div_i);

  auto ca_pow = ControlArray1D_pow(ca, 2.0);
  ControlArray1D_destroy(ca_pow);

  auto ca_abs = ControlArray1D_abs(ca);
  ControlArray1D_destroy(ca_abs);

  auto ca_min_fa = ControlArray1D_min_farray(ca, fa);
  auto ca_min_ca = ControlArray1D_min_control_array(ca, ca2);
  ControlArray1D_destroy(ca_min_fa);
  ControlArray1D_destroy(ca_min_ca);

  auto ca_max_fa = ControlArray1D_max_farray(ca, fa);
  auto ca_max_ca = ControlArray1D_max_control_array(ca, ca2);
  ControlArray1D_destroy(ca_max_fa);
  ControlArray1D_destroy(ca_max_ca);

  EXPECT_THROW(ControlArray1D_plusequals_farray(nullptr, fa),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_plusequals_farray(ca, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_plusequals_double(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_plusequals_int(nullptr, 1),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_plus_control_array(nullptr, ca2),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_plus_control_array(ca, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_plus_farray(nullptr, fa), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_plus_farray(ca, nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_plus_double(nullptr, 1.0), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_plus_int(nullptr, 1), std::invalid_argument);

  EXPECT_THROW(ControlArray1D_minusequals_farray(nullptr, fa),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_minusequals_farray(ca, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_minusequals_double(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_minusequals_int(nullptr, 1),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_minus_control_array(nullptr, ca2),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_minus_control_array(ca, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_minus_farray(nullptr, fa), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_minus_farray(ca, nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_minus_double(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_minus_int(nullptr, 1), std::invalid_argument);

  EXPECT_THROW(ControlArray1D_negation(nullptr), std::invalid_argument);

  EXPECT_THROW(ControlArray1D_timesequals_double(nullptr, 2.0),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_timesequals_int(nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_times_double(nullptr, 2.0),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_times_int(nullptr, 2), std::invalid_argument);

  EXPECT_THROW(ControlArray1D_dividesequals_double(nullptr, 2.0),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_dividesequals_int(nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_divides_double(nullptr, 2.0),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_divides_int(nullptr, 2), std::invalid_argument);

  EXPECT_THROW(ControlArray1D_pow(nullptr, 2.0), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_abs(nullptr), std::invalid_argument);

  EXPECT_THROW(ControlArray1D_min_farray(nullptr, fa), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_min_farray(ca, nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_min_control_array(nullptr, ca2),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_min_control_array(ca, nullptr),
               std::invalid_argument);

  EXPECT_THROW(ControlArray1D_max_farray(nullptr, fa), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_max_farray(ca, nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_max_control_array(nullptr, ca2),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_max_control_array(ca, nullptr),
               std::invalid_argument);
}

TEST_F(ControlArray1DTest, EqualityOperators) {
  EXPECT_FALSE(ControlArray1D_equality(ca, ca2));
  EXPECT_TRUE(ControlArray1D_notequality(ca, ca2));
  EXPECT_THROW(ControlArray1D_equality(nullptr, ca2), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_equality(ca, nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_notequality(nullptr, ca2), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_notequality(ca, nullptr), std::invalid_argument);
}

TEST_F(ControlArray1DTest, ComparisonOperators) {
  EXPECT_TRUE(ControlArray1D_greaterthan(ca, 0.5));
  EXPECT_FALSE(ControlArray1D_lessthan(ca, 0.5));
  EXPECT_THROW(ControlArray1D_greaterthan(nullptr, 0.5), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_lessthan(nullptr, 0.5), std::invalid_argument);
}

TEST_F(ControlArray1DTest, OffsetSumWhereFlipGradient) {
  ControlArray1D_remove_offset(ca, 1.0);
  EXPECT_DOUBLE_EQ(ControlArray1D_sum(ca), 3.0);
  size_t               new_shape[1] = {3};
  ListListSizeTHandle  where        = ControlArray1D_where(ca, 2.0);
  ControlArray1DHandle flipped      = ControlArray1D_flip(ca, 0);
  ControlArray1D_destroy(flipped);
  ListListSizeT_destroy(where);
  ControlArray1DHandle grad_buffer[3];
  EXPECT_EQ(ControlArray1D_full_gradient(ca, grad_buffer, 3), 3);
  for (size_t i = 0; i < 3; ++i) {
    ControlArray1D_destroy(grad_buffer[i]);
  }
  auto grad = ControlArray1D_gradient(ca, 0);
  ControlArray1D_destroy(grad);
  EXPECT_THROW(ControlArray1D_remove_offset(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_sum(nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_where(nullptr, 2.0), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_flip(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_full_gradient(nullptr, grad_buffer, 3),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_gradient(nullptr, 0), std::invalid_argument);
}

TEST_F(ControlArray1DTest, SumOfSquares) {
  EXPECT_DOUBLE_EQ(ControlArray1D_get_sum_of_squares(ca), 14.0);
  EXPECT_DOUBLE_EQ(ControlArray1D_get_summed_diff_int_of_squares(ca, 1), 9.0);
  EXPECT_DOUBLE_EQ(ControlArray1D_get_summed_diff_double_of_squares(ca, 1.0),
                   9.0);
  EXPECT_DOUBLE_EQ(ControlArray1D_get_summed_diff_array_of_squares(ca, ca2),
                   0.0);
  EXPECT_THROW(ControlArray1D_get_sum_of_squares(nullptr),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_get_summed_diff_int_of_squares(nullptr, 1),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_get_summed_diff_double_of_squares(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_get_summed_diff_array_of_squares(nullptr, ca2),
               std::invalid_argument);
  EXPECT_THROW(ControlArray1D_get_summed_diff_array_of_squares(ca, nullptr),
               std::invalid_argument);
}

TEST_F(ControlArray1DTest, ToJsonFromJson) {
  auto json = ControlArray1D_to_json_string(ca);
  auto ca3  = ControlArray1D_from_json_string(json);
  EXPECT_TRUE(ControlArray1D_equality(ca, ca3));
  ControlArray1D_destroy(ca3);
  String_destroy(json);
  EXPECT_THROW(ControlArray1D_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray1D_from_json_string(nullptr), std::invalid_argument);
}
