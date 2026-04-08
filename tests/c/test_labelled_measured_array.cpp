#include <gtest/gtest.h>

#include "falcon-core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/FArrayDouble_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/math/arrays/LabelledMeasuredArray_c_api.h"
#include "falcon-core/math/arrays/MeasuredArray_c_api.h"
#include "falcon-core/physics/device_structures/Connection_c_api.h"
#include "falcon-core/physics/units/SymbolUnit_c_api.h"

class LabelledMeasuredArrayTest : public ::testing::Test {
 protected:
  void SetUp() override {
    shape[0] = 6;
    data[0]  = 1.0;
    data[1]  = 2.0;
    data[2]  = 3.0;
    data[3]  = 4.0;
    data[4]  = 5.0;
    data[5]  = 6.0;
    conn     = Connection_create_barrier_gate(String_wrap("GATE1"));
    fa       = FArrayDouble_from_data(data, shape, 1);
    ma       = MeasuredArray_from_data(data, shape, 1);
    label    = AcquisitionContext_create(
        conn, InstrumentTypes_voltmeter(), SymbolUnit_create_volt());
    lma  = LabelledMeasuredArray_from_farray(fa, label);
    lma2 = LabelledMeasuredArray_from_measured_array(ma, label);
  }
  void TearDown() override {
    Connection_destroy(conn);
    LabelledMeasuredArray_destroy(lma);
    LabelledMeasuredArray_destroy(lma2);
    FArrayDouble_destroy(fa);
    MeasuredArray_destroy(ma);
    AcquisitionContext_destroy(label);
  }
  double                      data[6];
  size_t                      shape[1];
  ConnectionHandle            conn;
  FArrayDoubleHandle          fa;
  MeasuredArrayHandle         ma;
  AcquisitionContextHandle    label;
  LabelledMeasuredArrayHandle lma;
  LabelledMeasuredArrayHandle lma2;
};

TEST_F(LabelledMeasuredArrayTest, CreateDestroy) {
  auto lma3 = LabelledMeasuredArray_from_farray(fa, label);
  LabelledMeasuredArray_destroy(lma3);
  lma3 = LabelledMeasuredArray_from_measured_array(ma, label);
  LabelledMeasuredArray_destroy(lma3);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_from_farray(nullptr, label);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_from_measured_array(nullptr, label);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArrayTest, Accessors) {
  auto lbl   = LabelledMeasuredArray_label(lma);
  auto conn  = LabelledMeasuredArray_connection(lma);
  auto instr = LabelledMeasuredArray_instrument_type(lma);
  auto unit  = LabelledMeasuredArray_units(lma);
  EXPECT_EQ(LabelledMeasuredArray_size(lma), 6);
  EXPECT_EQ(LabelledMeasuredArray_dimension(lma), 1);
  size_t out_shape[1];
  EXPECT_EQ(LabelledMeasuredArray_shape(lma, out_shape, 1), 1);
  double out_data[6];
  EXPECT_EQ(LabelledMeasuredArray_data(lma, out_data, 6), 6);
  AcquisitionContext_destroy(lbl);
  Connection_destroy(conn);
  String_destroy(instr);
  SymbolUnit_destroy(unit);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_label(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_connection(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_instrument_type(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_units(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_dimension(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_shape(nullptr, out_shape, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_data(nullptr, out_data, 6);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArrayTest, ArithmeticOperators) {
  LabelledMeasuredArray_plus_equals_farray(lma, fa);
  LabelledMeasuredArray_plus_equals_double(lma, 1.0);
  LabelledMeasuredArray_plus_equals_int(lma, 1);
  auto lma_plus_lma = LabelledMeasuredArray_plus_measured_array(lma, lma2);
  auto lma_plus_fa  = LabelledMeasuredArray_plus_farray(lma, fa);
  auto lma_plus_d   = LabelledMeasuredArray_plus_double(lma, 1.0);
  auto lma_plus_i   = LabelledMeasuredArray_plus_int(lma, 1);
  LabelledMeasuredArray_destroy(lma_plus_lma);
  LabelledMeasuredArray_destroy(lma_plus_fa);
  LabelledMeasuredArray_destroy(lma_plus_d);
  LabelledMeasuredArray_destroy(lma_plus_i);

  LabelledMeasuredArray_minus_equals_measured_array(lma, lma2);
  LabelledMeasuredArray_minus_equals_farray(lma, fa);
  LabelledMeasuredArray_minus_equals_double(lma, 1.0);
  LabelledMeasuredArray_minus_equals_int(lma, 1);
  auto lma_minus_ma = LabelledMeasuredArray_minus_measured_array(lma, ma);
  auto lma_minus_fa = LabelledMeasuredArray_minus_farray(lma, fa);
  auto lma_minus_d  = LabelledMeasuredArray_minus_double(lma, 1.0);
  auto lma_minus_i  = LabelledMeasuredArray_minus_int(lma, 1);
  LabelledMeasuredArray_destroy(lma_minus_ma);
  LabelledMeasuredArray_destroy(lma_minus_fa);
  LabelledMeasuredArray_destroy(lma_minus_d);
  LabelledMeasuredArray_destroy(lma_minus_i);

  auto lma_neg = LabelledMeasuredArray_negation(lma);
  LabelledMeasuredArray_destroy(lma_neg);

  LabelledMeasuredArray_times_equals_measured_array(lma, lma2);
  LabelledMeasuredArray_times_equals_farray(lma, fa);
  MeasuredArray_times_equals_double(lma, 2.0);
  LabelledMeasuredArray_times_equals_int(lma, 2);
  auto lma_times_lma = LabelledMeasuredArray_times_measured_array(lma, lma2);
  auto lma_times_fa  = LabelledMeasuredArray_times_farray(lma, fa);
  auto lma_times_d   = LabelledMeasuredArray_times_double(lma, 2.0);
  auto lma_times_i   = LabelledMeasuredArray_times_int(lma, 2);
  LabelledMeasuredArray_destroy(lma_times_lma);
  LabelledMeasuredArray_destroy(lma_times_fa);
  LabelledMeasuredArray_destroy(lma_times_d);
  LabelledMeasuredArray_destroy(lma_times_i);

  LabelledMeasuredArray_divides_equals_measured_array(lma, lma2);
  LabelledMeasuredArray_divides_equals_farray(lma, fa);
  LabelledMeasuredArray_divides_equals_double(lma, 2.0);
  LabelledMeasuredArray_divides_equals_int(lma, 2);
  auto lma_div_lma = LabelledMeasuredArray_divides_measured_array(lma, lma2);
  auto lma_div_fa  = LabelledMeasuredArray_divides_farray(lma, fa);
  auto lma_div_d   = LabelledMeasuredArray_divides_double(lma, 2.0);
  auto lma_div_i   = LabelledMeasuredArray_divides_int(lma, 2);
  LabelledMeasuredArray_destroy(lma_div_lma);
  LabelledMeasuredArray_destroy(lma_div_fa);
  LabelledMeasuredArray_destroy(lma_div_d);
  LabelledMeasuredArray_destroy(lma_div_i);

  auto lma_pow = LabelledMeasuredArray_pow(lma, 2.0);
  LabelledMeasuredArray_destroy(lma_pow);

  auto lma_abs = LabelledMeasuredArray_abs(lma);
  LabelledMeasuredArray_destroy(lma_abs);

  auto lma_min_fa  = LabelledMeasuredArray_min_farray(lma, fa);
  auto lma_min_lma = LabelledMeasuredArray_min_measured_array(lma, lma2);
  LabelledMeasuredArray_destroy(lma_min_fa);
  LabelledMeasuredArray_destroy(lma_min_lma);

  auto lma_max_fa  = LabelledMeasuredArray_max_farray(lma, fa);
  auto lma_max_lma = LabelledMeasuredArray_max_measured_array(lma, lma2);
  LabelledMeasuredArray_destroy(lma_max_fa);
  LabelledMeasuredArray_destroy(lma_max_lma);

  set_last_error(0, nullptr);
  LabelledMeasuredArray_plus_equals_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_plus_equals_farray(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_plus_equals_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_plus_equals_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_plus_measured_array(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_plus_measured_array(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_plus_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_plus_farray(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_plus_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_plus_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledMeasuredArray_minus_equals_measured_array(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_minus_equals_measured_array(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_minus_equals_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_minus_equals_farray(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_minus_equals_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_minus_equals_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_minus_measured_array(nullptr, ma);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_minus_measured_array(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_minus_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_minus_farray(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_minus_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_minus_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledMeasuredArray_negation(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledMeasuredArray_times_equals_measured_array(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_times_equals_measured_array(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_times_equals_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_times_equals_farray(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasuredArray_times_equals_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_times_equals_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_times_measured_array(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_times_measured_array(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_times_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_times_farray(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_times_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_times_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledMeasuredArray_divides_equals_measured_array(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_divides_equals_measured_array(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_divides_equals_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_divides_equals_farray(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_divides_equals_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_divides_equals_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_divides_measured_array(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_divides_measured_array(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_divides_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_divides_farray(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_divides_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_divides_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledMeasuredArray_pow(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_abs(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledMeasuredArray_min_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_min_farray(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_min_measured_array(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_min_measured_array(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledMeasuredArray_max_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_max_farray(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_max_measured_array(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_max_measured_array(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArrayTest, EqualityOperators) {
  EXPECT_TRUE(LabelledMeasuredArray_equal(lma, lma2));
  EXPECT_FALSE(LabelledMeasuredArray_not_equal(lma, lma2));
  set_last_error(0, nullptr);
  LabelledMeasuredArray_equal(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_equal(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_not_equal(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_not_equal(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArrayTest, ComparisonOperators) {
  EXPECT_TRUE(LabelledMeasuredArray_greater_than(lma, 0.5));
  EXPECT_FALSE(LabelledMeasuredArray_less_than(lma, 0.5));
  set_last_error(0, nullptr);
  LabelledMeasuredArray_greater_than(nullptr, 0.5);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_less_than(nullptr, 0.5);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArrayTest, OffsetSumReshapeWhereFlipGradient) {
  LabelledMeasuredArray_remove_offset(lma, 1.0);
  EXPECT_DOUBLE_EQ(LabelledMeasuredArray_sum(lma), 15.0);
  size_t new_shape[1] = {6};
  auto   reshaped     = LabelledMeasuredArray_reshape(lma, new_shape, 1);
  LabelledMeasuredArray_destroy(reshaped);
  auto where = LabelledMeasuredArray_where(lma, 2.0);
  ListListSizeT_destroy(where);
  auto flipped = LabelledMeasuredArray_flip(lma, 0);
  LabelledMeasuredArray_destroy(flipped);
  LabelledMeasuredArrayHandle grad_buffer[1];
  EXPECT_EQ(LabelledMeasuredArray_full_gradient(lma, grad_buffer, 1), 1);
  for (size_t i = 0; i < 1; ++i) {
    LabelledMeasuredArray_destroy(grad_buffer[i]);
  }
  auto grad = LabelledMeasuredArray_gradient(lma, 0);
  LabelledMeasuredArray_destroy(grad);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_remove_offset(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_sum(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_reshape(nullptr, new_shape, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_where(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_flip(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_full_gradient(nullptr, grad_buffer, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_gradient(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArrayTest, SumOfSquares) {
  EXPECT_DOUBLE_EQ(LabelledMeasuredArray_get_sum_of_squares(lma), 91.0);
  EXPECT_DOUBLE_EQ(LabelledMeasuredArray_get_summed_diff_int_of_squares(lma, 1),
                   55.0);
  EXPECT_DOUBLE_EQ(
      LabelledMeasuredArray_get_summed_diff_double_of_squares(lma, 1.0), 55.0);
  EXPECT_DOUBLE_EQ(
      LabelledMeasuredArray_get_summed_diff_array_of_squares(lma, lma2), 0.0);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_get_sum_of_squares(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_get_summed_diff_int_of_squares(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_get_summed_diff_double_of_squares(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_get_summed_diff_array_of_squares(nullptr, lma2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_get_summed_diff_array_of_squares(lma, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArrayTest, ToJsonFromJson) {
  auto json = LabelledMeasuredArray_to_json_string(lma);
  auto lma3 = LabelledMeasuredArray_from_json_string(json);
  EXPECT_TRUE(LabelledMeasuredArray_equal(lma, lma3));
  LabelledMeasuredArray_destroy(lma3);
  String_destroy(json);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArrayTest, ShapeBufferTooSmall) {
  size_t out_shape[1] = {0};  // buffer smaller than needed (should be 1)
  EXPECT_EQ(LabelledMeasuredArray_shape(lma, out_shape, 0), 0);
}

TEST_F(LabelledMeasuredArrayTest, DataBufferTooSmall) {
  double out_data[2] = {0, 0};  // buffer smaller than needed (should be 6)
  EXPECT_EQ(LabelledMeasuredArray_data(lma, out_data, 2), 2);
}

TEST_F(LabelledMeasuredArrayTest, DataNullBuffer) {
  set_last_error(0, nullptr);
  LabelledMeasuredArray_data(lma, nullptr, 6);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledMeasuredArrayTest, TimesEqualsDouble) {
  LabelledMeasuredArray_times_equals_double(lma, 2.0);
  double out_data[6];
  EXPECT_EQ(LabelledMeasuredArray_data(lma, out_data, 6), 6);
  for (int i = 0; i < 6; ++i) EXPECT_EQ(out_data[i], data[i] * 2.0);
  set_last_error(0, nullptr);
  LabelledMeasuredArray_times_equals_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
}
