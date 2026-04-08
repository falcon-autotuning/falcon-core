#include <gtest/gtest.h>

#include <cmath>

#include "falcon-core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/FArrayDouble_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/math/arrays/LabelledMeasuredArray1D_c_api.h"
#include "falcon-core/math/arrays/MeasuredArray_c_api.h"
#include "falcon-core/physics/device_structures/Connection_c_api.h"
#include "falcon-core/physics/units/SymbolUnit_c_api.h"

class LabelledMeasuredArray1DTest : public ::testing::Test {
 protected:
  void SetUp() override {
    shape[0] = 6;
    data[0]  = 1.0;
    data[1]  = 2.0;
    data[2]  = 3.0;
    data[3]  = 4.0;
    data[4]  = 5.0;
    data[5]  = 6.0;
    fa       = FArrayDouble_from_data(data, shape, 1);
    ma       = MeasuredArray_from_data(data, shape, 1);
    conn     = Connection_create_barrier_gate(String_wrap("GATE1"));
    label    = AcquisitionContext_create(
        conn, InstrumentTypes_voltmeter(), SymbolUnit_create_volt());
    lma  = LabelledMeasuredArray1D_from_farray(fa, label);
    lma2 = LabelledMeasuredArray1D_from_measured_array(ma, label);
  }
  void TearDown() override {
    Connection_destroy(conn);
    LabelledMeasuredArray1D_destroy(lma);
    LabelledMeasuredArray1D_destroy(lma2);
    FArrayDouble_destroy(fa);
    MeasuredArray_destroy(ma);
    AcquisitionContext_destroy(label);
  }
  double                        data[6];
  size_t                        shape[1];
  ConnectionHandle              conn;
  FArrayDoubleHandle            fa;
  MeasuredArrayHandle           ma;
  AcquisitionContextHandle      label;
  LabelledMeasuredArray1DHandle lma;
  LabelledMeasuredArray1DHandle lma2;
};

TEST_F(LabelledMeasuredArray1DTest, CreateDestroy) {
  auto lma3 = LabelledMeasuredArray1D_from_farray(fa, label);
  LabelledMeasuredArray1D_destroy(lma3);
  lma3 = LabelledMeasuredArray1D_from_measured_array(ma, label);
  LabelledMeasuredArray1D_destroy(lma3);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_from_farray(nullptr, label);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_from_measured_array(nullptr, label);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArray1DTest, Accessors) {
  EXPECT_TRUE(LabelledMeasuredArray1D_is_1D(lma));
  auto fa1 = LabelledMeasuredArray1D_as_1D(lma);
  FArrayDouble_destroy(fa1);
  EXPECT_DOUBLE_EQ(LabelledMeasuredArray1D_get_start(lma), 1.0);
  EXPECT_DOUBLE_EQ(LabelledMeasuredArray1D_get_end(lma), 6.0);
  EXPECT_FALSE(LabelledMeasuredArray1D_is_decreasing(lma));
  EXPECT_TRUE(LabelledMeasuredArray1D_is_increasing(lma));
  EXPECT_DOUBLE_EQ(LabelledMeasuredArray1D_get_distance(lma), 5.0);
  EXPECT_DOUBLE_EQ(LabelledMeasuredArray1D_get_mean(lma), 3.5);
  EXPECT_NE(LabelledMeasuredArray1D_get_std(lma), 0.0);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_is_1D(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_as_1D(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_get_start(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_get_end(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_is_decreasing(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_is_increasing(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_get_distance(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_get_mean(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_get_std(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArray1DTest, ReverseAndClosestIndex) {
  LabelledMeasuredArray1D_reverse(lma);
  EXPECT_EQ(LabelledMeasuredArray1D_get_closest_index(lma, 2.0), 4);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_reverse(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_get_closest_index(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArray1DTest, EvenDivisions) {
  LabelledMeasuredArray1D_even_divisions(lma, 2);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_even_divisions(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArray1DTest, SizeAndShapeAndData) {
  EXPECT_EQ(LabelledMeasuredArray1D_size(lma), 6);
  EXPECT_EQ(LabelledMeasuredArray1D_dimension(lma), 1);
  size_t out_shape[1];
  EXPECT_EQ(LabelledMeasuredArray1D_shape(lma, out_shape, 1), 1);
  EXPECT_EQ(out_shape[0], 6);
  double out_data[6];
  EXPECT_EQ(LabelledMeasuredArray1D_data(lma, out_data, 6), 6);
  for (int i = 0; i < 6; ++i) EXPECT_EQ(out_data[i], data[i]);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_dimension(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_shape(nullptr, out_shape, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_data(nullptr, out_data, 6);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArray1DTest, ArithmeticOperators) {
  LabelledMeasuredArray1D_plus_equals_farray(lma, fa);
  LabelledMeasuredArray1D_plus_equals_double(lma, 1.0);
  LabelledMeasuredArray1D_plus_equals_int(lma, 1);
  auto lma_plus_lma = LabelledMeasuredArray1D_plus_measured_array(lma, lma2);
  auto lma_plus_fa  = LabelledMeasuredArray1D_plus_farray(lma, fa);
  auto lma_plus_d   = LabelledMeasuredArray1D_plus_double(lma, 1.0);
  auto lma_plus_i   = LabelledMeasuredArray1D_plus_int(lma, 1);
  LabelledMeasuredArray1D_destroy(lma_plus_lma);
  LabelledMeasuredArray1D_destroy(lma_plus_fa);
  LabelledMeasuredArray1D_destroy(lma_plus_d);
  LabelledMeasuredArray1D_destroy(lma_plus_i);

  LabelledMeasuredArray1D_minus_equals_measured_array(lma, lma2);
  LabelledMeasuredArray1D_minus_equals_farray(lma, fa);
  LabelledMeasuredArray1D_minus_equals_double(lma, 1.0);
  LabelledMeasuredArray1D_minus_equals_int(lma, 1);
  auto lma_minus_ma = LabelledMeasuredArray1D_minus_measured_array(lma, ma);
  auto lma_minus_fa = LabelledMeasuredArray1D_minus_farray(lma, fa);
  auto lma_minus_d  = LabelledMeasuredArray1D_minus_double(lma, 1.0);
  auto lma_minus_i  = LabelledMeasuredArray1D_minus_int(lma, 1);
  LabelledMeasuredArray1D_destroy(lma_minus_ma);
  LabelledMeasuredArray1D_destroy(lma_minus_fa);
  LabelledMeasuredArray1D_destroy(lma_minus_d);
  LabelledMeasuredArray1D_destroy(lma_minus_i);

  auto lma_neg = LabelledMeasuredArray1D_negation(lma);
  LabelledMeasuredArray1D_destroy(lma_neg);

  LabelledMeasuredArray1D_times_equals_measured_array(lma, lma2);
  LabelledMeasuredArray1D_times_equals_farray(lma, fa);
  MeasuredArray_times_equals_double(lma, 2.0);
  LabelledMeasuredArray1D_times_equals_int(lma, 2);
  auto lma_times_lma = LabelledMeasuredArray1D_times_measured_array(lma, lma2);
  auto lma_times_fa  = LabelledMeasuredArray1D_times_farray(lma, fa);
  auto lma_times_d   = LabelledMeasuredArray1D_times_double(lma, 2.0);
  auto lma_times_i   = LabelledMeasuredArray1D_times_int(lma, 2);
  LabelledMeasuredArray1D_destroy(lma_times_lma);
  LabelledMeasuredArray1D_destroy(lma_times_fa);
  LabelledMeasuredArray1D_destroy(lma_times_d);
  LabelledMeasuredArray1D_destroy(lma_times_i);

  LabelledMeasuredArray1D_divides_equals_measured_array(lma, lma2);
  LabelledMeasuredArray1D_divides_equals_farray(lma, fa);
  LabelledMeasuredArray1D_divides_equals_double(lma, 2.0);
  LabelledMeasuredArray1D_divides_equals_int(lma, 2);
  auto lma_div_lma = LabelledMeasuredArray1D_divides_measured_array(lma, lma2);
  auto lma_div_fa  = LabelledMeasuredArray1D_divides_farray(lma, fa);
  auto lma_div_d   = LabelledMeasuredArray1D_divides_double(lma, 2.0);
  auto lma_div_i   = LabelledMeasuredArray1D_divides_int(lma, 2);
  LabelledMeasuredArray1D_destroy(lma_div_lma);
  LabelledMeasuredArray1D_destroy(lma_div_fa);
  LabelledMeasuredArray1D_destroy(lma_div_d);
  LabelledMeasuredArray1D_destroy(lma_div_i);

  auto lma_pow = LabelledMeasuredArray1D_pow(lma, 2.0);
  LabelledMeasuredArray1D_destroy(lma_pow);

  auto lma_abs = LabelledMeasuredArray1D_abs(lma);
  LabelledMeasuredArray1D_destroy(lma_abs);

  auto lma_min_fa  = LabelledMeasuredArray1D_min_farray(lma, fa);
  auto lma_min_lma = LabelledMeasuredArray1D_min_measured_array(lma, lma2);
  LabelledMeasuredArray1D_destroy(lma_min_fa);
  LabelledMeasuredArray1D_destroy(lma_min_lma);

  auto lma_max_fa  = LabelledMeasuredArray1D_max_farray(lma, fa);
  auto lma_max_lma = LabelledMeasuredArray1D_max_measured_array(lma, lma2);
  LabelledMeasuredArray1D_destroy(lma_max_fa);
  LabelledMeasuredArray1D_destroy(lma_max_lma);

  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_plus_equals_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_plus_equals_farray(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_plus_equals_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_plus_equals_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_plus_measured_array(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_plus_measured_array(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_plus_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_plus_farray(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_plus_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_plus_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_minus_equals_measured_array(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_minus_equals_measured_array(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_minus_equals_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_minus_equals_farray(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_minus_equals_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_minus_equals_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_minus_measured_array(nullptr, ma);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_minus_measured_array(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_minus_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_minus_farray(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_minus_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_minus_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_negation(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_times_equals_measured_array(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_times_equals_measured_array(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_times_equals_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_times_equals_farray(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_times_equals_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_times_equals_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_times_measured_array(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_times_measured_array(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_times_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_times_farray(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_times_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_times_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_divides_equals_measured_array(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_divides_equals_measured_array(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_divides_equals_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_divides_equals_farray(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_divides_equals_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_divides_equals_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_divides_measured_array(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_divides_measured_array(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_divides_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_divides_farray(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_divides_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_divides_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_pow(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_abs(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_min_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_min_farray(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_min_measured_array(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_min_measured_array(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_max_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_max_farray(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_max_measured_array(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_max_measured_array(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArray1DTest, EqualityOperators) {
  EXPECT_TRUE(LabelledMeasuredArray1D_equal(lma, lma2));
  EXPECT_FALSE(LabelledMeasuredArray1D_not_equal(lma, lma2));
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_equal(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_equal(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_not_equal(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_not_equal(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArray1DTest, ComparisonOperators) {
  EXPECT_TRUE(LabelledMeasuredArray1D_greater_than(lma, 0.5));
  EXPECT_FALSE(LabelledMeasuredArray1D_less_than(lma, 0.5));
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_greater_than(nullptr, 0.5);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_less_than(nullptr, 0.5);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArray1DTest, OffsetSumReshapeWhereFlipGradient) {
  LabelledMeasuredArray1D_remove_offset(lma, 1.0);
  EXPECT_DOUBLE_EQ(LabelledMeasuredArray1D_sum(lma), 15.0);
  size_t new_shape[1] = {6};
  auto   reshaped     = LabelledMeasuredArray1D_reshape(lma, new_shape, 1);
  LabelledMeasuredArray1D_destroy(reshaped);
  auto where = LabelledMeasuredArray1D_where(lma, 2.0);
  ListListSizeT_destroy(where);
  auto flipped = LabelledMeasuredArray1D_flip(lma, 0);
  LabelledMeasuredArray1D_destroy(flipped);
  LabelledMeasuredArray1DHandle grad_buffer[1];
  EXPECT_EQ(LabelledMeasuredArray1D_full_gradient(lma, grad_buffer, 1), 1);
  for (size_t i = 0; i < 1; ++i) {
    LabelledMeasuredArray1D_destroy(grad_buffer[i]);
  }
  auto grad = LabelledMeasuredArray1D_gradient(lma, 0);
  LabelledMeasuredArray1D_destroy(grad);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_remove_offset(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_sum(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_reshape(nullptr, new_shape, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_where(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_flip(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_full_gradient(nullptr, grad_buffer, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_gradient(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArray1DTest, SumOfSquares) {
  EXPECT_DOUBLE_EQ(LabelledMeasuredArray1D_get_sum_of_squares(lma), 91.0);
  EXPECT_DOUBLE_EQ(
      LabelledMeasuredArray1D_get_summed_diff_int_of_squares(lma, 1), 55.0);
  EXPECT_DOUBLE_EQ(
      LabelledMeasuredArray1D_get_summed_diff_double_of_squares(lma, 1.0),
      55.0);
  EXPECT_DOUBLE_EQ(
      LabelledMeasuredArray1D_get_summed_diff_array_of_squares(lma, lma2), 0.0);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_get_sum_of_squares(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_get_summed_diff_int_of_squares(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_get_summed_diff_double_of_squares(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_get_summed_diff_array_of_squares(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_get_summed_diff_array_of_squares(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArray1DTest, ToJsonFromJson) {
  auto json = LabelledMeasuredArray1D_to_json_string(lma);
  auto lma3 = LabelledMeasuredArray1D_from_json_string(json);
  EXPECT_TRUE(LabelledMeasuredArray1D_equal(lma, lma3));
  LabelledMeasuredArray1D_destroy(lma3);
  String_destroy(json);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArray1DTest, TimesEqualsDouble) {
  LabelledMeasuredArray1D_times_equals_double(lma, 2.0);
  double out_data[6];
  EXPECT_EQ(LabelledMeasuredArray1D_data(lma, out_data, 6), 6);
  for (int i = 0; i < 6; ++i) EXPECT_DOUBLE_EQ(out_data[i], data[i] * 2.0);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_times_equals_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArray1DTest, LabelAccess) {
  auto ac = LabelledMeasuredArray1D_label(lma);
  EXPECT_TRUE(AcquisitionContext_equal(ac, label));
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_label(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArray1DTest, ConnectionAccess) {
  auto conn_out = LabelledMeasuredArray1D_connection(lma);
  EXPECT_TRUE(Connection_equal(conn_out, conn));
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_connection(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArray1DTest, InstrumentTypeAccess) {
  LabelledMeasuredArray1D_instrument_type(lma);
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_instrument_type(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArray1DTest, UnitAccess) {
  auto unit = LabelledMeasuredArray1D_units(lma);
  EXPECT_TRUE(SymbolUnit_equal(unit, SymbolUnit_create_volt()));
  set_last_error(0, nullptr);
  LabelledMeasuredArray1D_units(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
