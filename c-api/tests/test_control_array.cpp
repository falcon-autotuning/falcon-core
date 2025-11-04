#include <gtest/gtest.h>

#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/arrays/ControlArray_c_api.h"

class ControlArrayTest : public ::testing::Test {
 protected:
  void SetUp() override {
    // 2D array: shape = [2, 3], data = {1,2,3,4,5,6}
    shape2d[0] = 2;
    shape2d[1] = 3;
    data2d[0]  = 1.0;
    data2d[1]  = 2.0;
    data2d[2]  = 3.0;
    data2d[3]  = 4.0;
    data2d[4]  = 5.0;
    data2d[5]  = 6.0;
    ca2d       = ControlArray_from_data(data2d, shape2d, 2);

    // 1D array for some tests
    shape1d[0] = 6;
    for (int i = 0; i < 6; ++i) data1d[i] = data2d[i];
    ca1d = ControlArray_from_data(data1d, shape1d, 1);

    fa2d = FArrayDouble_from_data(
        new double(data2d[0]), new size_t(shape2d[0]), 2);
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
  ControlArrayHandle ca2d   = nullptr;
  ControlArrayHandle ca1d   = nullptr;
  ControlArrayHandle ca2d_2 = nullptr;
  FArrayDoubleHandle fa2d   = nullptr;
};

TEST_F(ControlArrayTest, CreateDestroy) {
  auto ca3 = ControlArray_from_data(data2d, shape2d, 2);
  ControlArray_destroy(ca3);
  EXPECT_THROW(ControlArray_from_data(nullptr, shape2d, 2),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_from_data(data2d, nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_from_farray(nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray_destroy(nullptr), std::invalid_argument);
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
  EXPECT_THROW(ControlArray_size(nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray_dimension(nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray_shape(nullptr, out_shape, 2),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_data(nullptr, out_data, 6), std::invalid_argument);
}

TEST_F(ControlArrayTest, ArithmeticOperators) {
  ControlArray_plusequals_farray(ca2d, fa2d);
  ControlArray_plusequals_double(ca2d, 1.0);
  ControlArray_plusequals_int(ca2d, 1);
  auto ca_plus_ca = ControlArray_plus_control_array(ca2d, ca2d_2);
  auto ca_plus_fa = ControlArray_plus_farray(ca2d, fa2d);
  auto ca_plus_d  = ControlArray_plus_double(ca2d, 1.0);
  auto ca_plus_i  = ControlArray_plus_int(ca2d, 1);
  ControlArray_destroy(ca_plus_ca);
  ControlArray_destroy(ca_plus_fa);
  ControlArray_destroy(ca_plus_d);
  ControlArray_destroy(ca_plus_i);

  ControlArray_minusequals_farray(ca2d, fa2d);
  ControlArray_minusequals_double(ca2d, 1.0);
  ControlArray_minusequals_int(ca2d, 1);
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

  ControlArray_timesequals_double(ca2d, 2.0);
  ControlArray_timesequals_int(ca2d, 2);
  auto ca_times_d = ControlArray_times_double(ca2d, 2.0);
  auto ca_times_i = ControlArray_times_int(ca2d, 2);
  ControlArray_destroy(ca_times_d);
  ControlArray_destroy(ca_times_i);

  ControlArray_dividesequals_double(ca2d, 2.0);
  ControlArray_dividesequals_int(ca2d, 2);
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

  EXPECT_THROW(ControlArray_plusequals_farray(nullptr, fa2d),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_plusequals_farray(ca2d, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_plusequals_double(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_plusequals_int(nullptr, 1), std::invalid_argument);
  EXPECT_THROW(ControlArray_plus_control_array(nullptr, ca2d_2),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_plus_control_array(ca2d, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_plus_farray(nullptr, fa2d), std::invalid_argument);
  EXPECT_THROW(ControlArray_plus_farray(ca2d, nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray_plus_double(nullptr, 1.0), std::invalid_argument);
  EXPECT_THROW(ControlArray_plus_int(nullptr, 1), std::invalid_argument);

  EXPECT_THROW(ControlArray_minusequals_farray(nullptr, fa2d),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_minusequals_farray(ca2d, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_minusequals_double(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_minusequals_int(nullptr, 1), std::invalid_argument);
  EXPECT_THROW(ControlArray_minus_control_array(nullptr, ca2d_2),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_minus_control_array(ca2d, nullptr),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_minus_farray(nullptr, fa2d), std::invalid_argument);
  EXPECT_THROW(ControlArray_minus_farray(ca2d, nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray_minus_double(nullptr, 1.0), std::invalid_argument);
  EXPECT_THROW(ControlArray_minus_int(nullptr, 1), std::invalid_argument);

  EXPECT_THROW(ControlArray_negation(nullptr), std::invalid_argument);

  EXPECT_THROW(ControlArray_timesequals_double(nullptr, 2.0),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_timesequals_int(nullptr, 2), std::invalid_argument);
  EXPECT_THROW(ControlArray_times_double(nullptr, 2.0), std::invalid_argument);
  EXPECT_THROW(ControlArray_times_int(nullptr, 2), std::invalid_argument);

  EXPECT_THROW(ControlArray_dividesequals_double(nullptr, 2.0),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_dividesequals_int(nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_divides_double(nullptr, 2.0),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_divides_int(nullptr, 2), std::invalid_argument);

  EXPECT_THROW(ControlArray_pow(nullptr, 2.0), std::invalid_argument);
  EXPECT_THROW(ControlArray_abs(nullptr), std::invalid_argument);

  EXPECT_THROW(ControlArray_min_farray(nullptr, fa2d), std::invalid_argument);
  EXPECT_THROW(ControlArray_min_farray(ca2d, nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray_min_control_array(nullptr, ca2d_2),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_min_control_array(ca2d, nullptr),
               std::invalid_argument);

  EXPECT_THROW(ControlArray_max_farray(nullptr, fa2d), std::invalid_argument);
  EXPECT_THROW(ControlArray_max_farray(ca2d, nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray_max_control_array(nullptr, ca2d_2),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_max_control_array(ca2d, nullptr),
               std::invalid_argument);
}

TEST_F(ControlArrayTest, EqualityOperators) {
  EXPECT_FALSE(ControlArray_equality(ca2d, ca2d_2));
  EXPECT_TRUE(ControlArray_notequality(ca2d, ca2d_2));
  EXPECT_THROW(ControlArray_equality(nullptr, ca2d_2), std::invalid_argument);
  EXPECT_THROW(ControlArray_equality(ca2d, nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray_notequality(nullptr, ca2d_2),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_notequality(ca2d, nullptr), std::invalid_argument);
}

TEST_F(ControlArrayTest, ComparisonOperators) {
  EXPECT_TRUE(ControlArray_greaterthan(ca2d, 0.5));
  EXPECT_FALSE(ControlArray_lessthan(ca2d, 0.5));
  EXPECT_THROW(ControlArray_greaterthan(nullptr, 0.5), std::invalid_argument);
  EXPECT_THROW(ControlArray_lessthan(nullptr, 0.5), std::invalid_argument);
}

TEST_F(ControlArrayTest, OffsetSumReshapeWhereFlipGradient) {
  ControlArray_remove_offset(ca2d, 1.0);
  EXPECT_DOUBLE_EQ(ControlArray_sum(ca2d), 21.0);
  size_t new_shape[2] = {3, 2};
  auto   reshaped     = ControlArray_reshape(ca2d, new_shape, 2);
  ControlArray_destroy(reshaped);
  auto where = ControlArray_where(ca2d, 2.0);
  // ListListSizeT_destroy(where); // implement destroy if needed
  auto flipped = ControlArray_flip(ca2d, 0);
  ControlArray_destroy(flipped);
  ControlArrayHandle grad_buffer[2];
  EXPECT_EQ(ControlArray_full_gradient(ca2d, grad_buffer, 2), 2);
  for (size_t i = 0; i < 2; ++i) {
    ControlArray_destroy(grad_buffer[i]);
  }
  auto grad = ControlArray_gradient(ca2d, 0);
  ControlArray_destroy(grad);
  EXPECT_THROW(ControlArray_remove_offset(nullptr, 1.0), std::invalid_argument);
  EXPECT_THROW(ControlArray_sum(nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray_reshape(nullptr, new_shape, 2),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_where(nullptr, 2.0), std::invalid_argument);
  EXPECT_THROW(ControlArray_flip(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(ControlArray_full_gradient(nullptr, grad_buffer, 2),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_gradient(nullptr, 0), std::invalid_argument);
}

TEST_F(ControlArrayTest, SumOfSquares) {
  EXPECT_DOUBLE_EQ(ControlArray_get_sum_of_squares(ca2d), 91.0);
  EXPECT_DOUBLE_EQ(ControlArray_get_summed_diff_int_of_squares(ca2d, 1), 70.0);
  EXPECT_DOUBLE_EQ(ControlArray_get_summed_diff_double_of_squares(ca2d, 1.0),
                   70.0);
  EXPECT_DOUBLE_EQ(ControlArray_get_summed_diff_array_of_squares(ca2d, ca2d_2),
                   0.0);
  EXPECT_THROW(ControlArray_get_sum_of_squares(nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray_get_summed_diff_int_of_squares(nullptr, 1),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_get_summed_diff_double_of_squares(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_get_summed_diff_array_of_squares(nullptr, ca2d_2),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_get_summed_diff_array_of_squares(ca2d, nullptr),
               std::invalid_argument);
}

TEST_F(ControlArrayTest, ToJsonFromJson) {
  auto json = ControlArray_to_json_string(ca2d);
  auto ca3  = ControlArray_from_json_string(json);
  EXPECT_TRUE(ControlArray_equality(ca2d, ca3));
  ControlArray_destroy(ca3);
  String_destroy(json);
  EXPECT_THROW(ControlArray_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(ControlArray_from_json_string(nullptr), std::invalid_argument);
}
