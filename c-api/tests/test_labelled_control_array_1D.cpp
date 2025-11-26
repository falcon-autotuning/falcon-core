#include <gtest/gtest.h>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/arrays/ControlArray_c_api.h"
#include "falcon_core/math/arrays/LabelledControlArray1D_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class LabelledControlArray1DTest : public ::testing::Test {
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
    ca       = ControlArray_from_data(data, shape, 1);
    conn     = Connection_create_barrier_gate(String_wrap("GATE1"));
    label    = AcquisitionContext_create(
        conn, InstrumentTypes_voltmeter(), SymbolUnit_create_volt());
    lca        = LabelledControlArray1D_from_farray(fa, label);
    double_lca = LabelledControlArray1D_from_farray(
        FArrayDouble_times_double(fa, 2.0), label);
    lca2 = LabelledControlArray1D_from_control_array(ca, label);
  }
  void TearDown() override {
    LabelledControlArray1D_destroy(lca);
    LabelledControlArray1D_destroy(double_lca);
    LabelledControlArray1D_destroy(lca2);
    FArrayDouble_destroy(fa);
    ControlArray_destroy(ca);
    AcquisitionContext_destroy(label);
  }
  double                       data[6];
  size_t                       shape[1];
  ConnectionHandle             conn;
  FArrayDoubleHandle           fa;
  ControlArrayHandle           ca;
  AcquisitionContextHandle     label;
  LabelledControlArray1DHandle lca;
  LabelledControlArray1DHandle double_lca;
  LabelledControlArray1DHandle lca2;
};

TEST_F(LabelledControlArray1DTest, CreateDestroy) {
  auto lca3 = LabelledControlArray1D_from_farray(fa, label);
  LabelledControlArray1D_destroy(lca3);
  lca3 = LabelledControlArray1D_from_control_array(ca, label);
  LabelledControlArray1D_destroy(lca3);
  set_last_error(0, nullptr);
  LabelledControlArray1D_from_farray(nullptr, label);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_from_control_array(nullptr, label);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArray1DTest, Accessors) {
  EXPECT_TRUE(LabelledControlArray1D_is_1D(lca));
  auto fa1 = LabelledControlArray1D_as_1D(lca);
  FArrayDouble_destroy(fa1);
  EXPECT_DOUBLE_EQ(LabelledControlArray1D_get_start(lca), 1.0);
  EXPECT_DOUBLE_EQ(LabelledControlArray1D_get_end(lca), 6.0);
  EXPECT_FALSE(LabelledControlArray1D_is_decreasing(lca));
  EXPECT_TRUE(LabelledControlArray1D_is_increasing(lca));
  EXPECT_DOUBLE_EQ(LabelledControlArray1D_get_distance(lca), 5.0);
  EXPECT_DOUBLE_EQ(LabelledControlArray1D_get_mean(lca), 3.5);
  EXPECT_NE(LabelledControlArray1D_get_std(lca), 0.0);
  set_last_error(0, nullptr);
  LabelledControlArray1D_is_1D(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_as_1D(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_get_start(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_get_end(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_is_decreasing(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_is_increasing(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_get_distance(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_get_mean(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_get_std(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArray1DTest, ReverseAndClosestIndex) {
  LabelledControlArray1D_reverse(lca);
  EXPECT_EQ(LabelledControlArray1D_get_closest_index(lca, 2.0), 4);
  set_last_error(0, nullptr);
  LabelledControlArray1D_reverse(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_get_closest_index(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArray1DTest, EvenDivisions) {
  auto list = LabelledControlArray1D_even_divisions(lca, 2);
  // ListFArrayDouble_destroy(list); // implement destroy if needed
  set_last_error(0, nullptr);
  LabelledControlArray1D_even_divisions(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArray1DTest, SizeAndShapeAndData) {
  EXPECT_EQ(LabelledControlArray1D_size(lca), 6);
  EXPECT_EQ(LabelledControlArray1D_dimension(lca), 1);
  size_t out_shape[1];
  EXPECT_EQ(LabelledControlArray1D_shape(lca, out_shape, 1), 1);
  EXPECT_EQ(out_shape[0], 6);
  double out_data[6];
  EXPECT_EQ(LabelledControlArray1D_data(lca, out_data, 6), 6);
  for (int i = 0; i < 6; ++i) EXPECT_EQ(out_data[i], data[i]);
  set_last_error(0, nullptr);
  LabelledControlArray1D_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_dimension(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_shape(nullptr, out_shape, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_data(nullptr, out_data, 6);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArray1DTest, Addition) {
  LabelledControlArray1D_plusequals_farray(lca, fa);
  LabelledControlArray1D_plusequals_double(lca, 1.0);
  LabelledControlArray1D_plusequals_int(lca, 1);
  auto lca_plus_lca = LabelledControlArray1D_plus_control_array(lca, lca2);
  auto lca_plus_fa  = LabelledControlArray1D_plus_farray(lca, fa);
  auto lca_plus_d   = LabelledControlArray1D_plus_double(lca, 1.0);
  auto lca_plus_i   = LabelledControlArray1D_plus_int(lca, 1);
  LabelledControlArray1D_destroy(lca_plus_lca);
  LabelledControlArray1D_destroy(lca_plus_fa);
  LabelledControlArray1D_destroy(lca_plus_d);
  LabelledControlArray1D_destroy(lca_plus_i);
}

TEST_F(LabelledControlArray1DTest, SubtractionEquals) {
  LabelledControlArray1D_minusequals_farray(double_lca, fa);
  LabelledControlArray1D_minusequals_double(lca, 1.0);
  LabelledControlArray1D_minusequals_int(lca, 1);
}
TEST_F(LabelledControlArray1DTest, Subtraction) {
  auto lca_minus_lca =
      LabelledControlArray1D_minus_control_array(double_lca, lca2);
  auto lca_minus_fa = LabelledControlArray1D_minus_farray(double_lca, fa);
  auto lca_minus_d  = LabelledControlArray1D_minus_double(lca, 1.0);
  auto lca_minus_i  = LabelledControlArray1D_minus_int(lca, 1);
  LabelledControlArray1D_destroy(lca_minus_lca);
  LabelledControlArray1D_destroy(lca_minus_fa);
  LabelledControlArray1D_destroy(lca_minus_d);
  LabelledControlArray1D_destroy(lca_minus_i);
}

TEST_F(LabelledControlArray1DTest, Negation) {
  auto lca_neg = LabelledControlArray1D_negation(lca);
  LabelledControlArray1D_destroy(lca_neg);
}

TEST_F(LabelledControlArray1DTest, Times) {
  LabelledControlArray1D_timesequals_double(lca, 2.0);
  LabelledControlArray1D_timesequals_int(lca, 2);
  auto lca_times_d = LabelledControlArray1D_times_double(lca, 2.0);
  auto lca_times_i = LabelledControlArray1D_times_int(lca, 2);
  LabelledControlArray1D_destroy(lca_times_d);
  LabelledControlArray1D_destroy(lca_times_i);
}

TEST_F(LabelledControlArray1DTest, Division) {
  LabelledControlArray1D_dividesequals_double(lca, 2.0);
  LabelledControlArray1D_dividesequals_int(lca, 2);
  auto lca_div_d = LabelledControlArray1D_divides_double(lca, 2.0);
  auto lca_div_i = LabelledControlArray1D_divides_int(lca, 2);
  LabelledControlArray1D_destroy(lca_div_d);
  LabelledControlArray1D_destroy(lca_div_i);
}

TEST_F(LabelledControlArray1DTest, MiscOperations) {
  auto lca_pow = LabelledControlArray1D_pow(lca, 1.0);
  LabelledControlArray1D_destroy(lca_pow);

  auto lca_abs = LabelledControlArray1D_abs(lca);
  LabelledControlArray1D_destroy(lca_abs);

  auto lca_min_fa  = LabelledControlArray1D_min_farray(double_lca, fa);
  auto lca_min_lca = LabelledControlArray1D_min_control_array(double_lca, lca2);
  LabelledControlArray1D_destroy(lca_min_fa);
  LabelledControlArray1D_destroy(lca_min_lca);

  auto lca_max_fa  = LabelledControlArray1D_max_farray(double_lca, fa);
  auto lca_max_lca = LabelledControlArray1D_max_control_array(double_lca, lca2);
  LabelledControlArray1D_destroy(lca_max_fa);
  LabelledControlArray1D_destroy(lca_max_lca);
}

TEST_F(LabelledControlArray1DTest, AlgebraicOperatorNullptrChecks) {
  set_last_error(0, nullptr);
  LabelledControlArray1D_plusequals_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_plusequals_farray(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_plusequals_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_plusequals_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_plus_control_array(nullptr, lca2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_plus_control_array(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_plus_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_plus_farray(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_plus_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_plus_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledControlArray1D_minusequals_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_minusequals_farray(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_minusequals_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_minusequals_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_minus_control_array(nullptr, lca2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_minus_control_array(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_minus_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_minus_farray(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_minus_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_minus_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledControlArray1D_negation(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledControlArray1D_timesequals_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_timesequals_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_times_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_times_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledControlArray1D_dividesequals_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_dividesequals_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_divides_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_divides_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledControlArray1D_pow(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_abs(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledControlArray1D_min_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_min_farray(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_min_control_array(nullptr, lca2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_min_control_array(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledControlArray1D_max_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_max_farray(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_max_control_array(nullptr, lca2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_max_control_array(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArray1DTest, EqualityOperators) {
  EXPECT_TRUE(LabelledControlArray1D_equality(lca, lca2));
  EXPECT_FALSE(LabelledControlArray1D_notequality(lca, lca2));
  set_last_error(0, nullptr);
  LabelledControlArray1D_equality(nullptr, lca2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_equality(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_notequality(nullptr, lca2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_notequality(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArray1DTest, ComparisonOperators) {
  EXPECT_TRUE(LabelledControlArray1D_greaterthan(lca, 0.5));
  EXPECT_FALSE(LabelledControlArray1D_lessthan(lca, 0.5));
  set_last_error(0, nullptr);
  LabelledControlArray1D_greaterthan(nullptr, 0.5);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_lessthan(nullptr, 0.5);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArray1DTest, OffsetSumWhereFlipGradient) {
  LabelledControlArray1D_remove_offset(lca, 1.0);
  EXPECT_DOUBLE_EQ(LabelledControlArray1D_sum(lca), 15.0);
  size_t new_shape[1] = {6};
  auto   where        = LabelledControlArray1D_where(lca, 2.0);
  // ListListSizeT_destroy(where); // implement destroy if needed
  auto flipped = LabelledControlArray1D_flip(lca, 0);
  LabelledControlArray1D_destroy(flipped);
  LabelledControlArray1DHandle grad_buffer[1];
  EXPECT_EQ(LabelledControlArray1D_full_gradient(lca, grad_buffer, 1), 1);
  for (size_t i = 0; i < 1; ++i) {
    LabelledControlArray1D_destroy(grad_buffer[i]);
  }
  auto grad = LabelledControlArray1D_gradient(lca, 0);
  LabelledControlArray1D_destroy(grad);
  set_last_error(0, nullptr);
  LabelledControlArray1D_remove_offset(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_sum(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_where(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_flip(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_full_gradient(nullptr, grad_buffer, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_gradient(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArray1DTest, SumOfSquares) {
  EXPECT_DOUBLE_EQ(LabelledControlArray1D_get_sum_of_squares(lca), 91.0);
  EXPECT_DOUBLE_EQ(
      LabelledControlArray1D_get_summed_diff_int_of_squares(lca, 1), 55.0);
  EXPECT_DOUBLE_EQ(
      LabelledControlArray1D_get_summed_diff_double_of_squares(lca, 1.0), 55.0);
  EXPECT_DOUBLE_EQ(
      LabelledControlArray1D_get_summed_diff_array_of_squares(lca, lca2), 0.0);
  set_last_error(0, nullptr);
  LabelledControlArray1D_get_sum_of_squares(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_get_summed_diff_int_of_squares(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_get_summed_diff_double_of_squares(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_get_summed_diff_array_of_squares(nullptr, lca2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_get_summed_diff_array_of_squares(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArray1DTest, ToJsonFromJson) {
  auto json = LabelledControlArray1D_to_json_string(lca);
  auto lca3 = LabelledControlArray1D_from_json_string(json);
  EXPECT_TRUE(LabelledControlArray1D_equality(lca, lca3));
  LabelledControlArray1D_destroy(lca3);
  String_destroy(json);
  set_last_error(0, nullptr);
  LabelledControlArray1D_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArray1DTest, AllowLabel) {
  auto lbl = LabelledControlArray1D_label(lca);
  EXPECT_NE(lbl, nullptr);
  AcquisitionContext_destroy(lbl);
  set_last_error(0, nullptr);
  LabelledControlArray1D_label(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArray1DTest, AllowConnection) {
  auto conn = LabelledControlArray1D_connection(lca);
  EXPECT_NE(conn, nullptr);
  Connection_destroy(conn);
  set_last_error(0, nullptr);
  LabelledControlArray1D_connection(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArray1DTest, AllowInstrumentType) {
  auto instr = LabelledControlArray1D_instrument_type(lca);
  EXPECT_NE(instr, nullptr);
  String_destroy(instr);
  set_last_error(0, nullptr);
  LabelledControlArray1D_instrument_type(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArray1DTest, AllowUnits) {
  auto unit = LabelledControlArray1D_units(lca);
  EXPECT_NE(unit, nullptr);
  SymbolUnit_destroy(unit);
  set_last_error(0, nullptr);
  LabelledControlArray1D_units(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArray1DTest, FromControlArrayNullptrCheck) {
  set_last_error(0, nullptr);
  LabelledControlArray1D_from_control_array(nullptr, label);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_from_control_array(ca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArray1DTest, FromFArrayNullptrCheck) {
  set_last_error(0, nullptr);
  LabelledControlArray1D_from_farray(nullptr, label);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray1D_from_farray(fa, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
