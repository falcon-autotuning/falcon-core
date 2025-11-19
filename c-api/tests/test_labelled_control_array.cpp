#include <gtest/gtest.h>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/arrays/ControlArray_c_api.h"
#include "falcon_core/math/arrays/LabelledControlArray_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class LabelledControlArrayTest : public ::testing::Test {
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
    lca  = LabelledControlArray_from_farray(fa, label);
    lca2 = LabelledControlArray_from_control_array(ca, label);
  }
  void TearDown() override {
    LabelledControlArray_destroy(lca);
    LabelledControlArray_destroy(lca2);
    FArrayDouble_destroy(fa);
    ControlArray_destroy(ca);
    AcquisitionContext_destroy(label);
  }
  double                     data[6];
  size_t                     shape[1];
  ConnectionHandle           conn;
  FArrayDoubleHandle         fa;
  ControlArrayHandle         ca;
  AcquisitionContextHandle   label;
  LabelledControlArrayHandle lca;
  LabelledControlArrayHandle lca2;
};

TEST_F(LabelledControlArrayTest, CreateDestroy) {
  auto lca3 = LabelledControlArray_from_farray(fa, label);
  LabelledControlArray_destroy(lca3);
  lca3 = LabelledControlArray_from_control_array(ca, label);
  LabelledControlArray_destroy(lca3);
  set_last_error(0, nullptr);
  LabelledControlArray_from_farray(nullptr, label);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_from_control_array(nullptr, label);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArrayTest, Accessors) {
  auto lbl   = LabelledControlArray_label(lca);
  auto conn  = LabelledControlArray_connection(lca);
  auto instr = LabelledControlArray_instrument_type(lca);
  auto unit  = LabelledControlArray_units(lca);
  EXPECT_EQ(LabelledControlArray_size(lca), 6);
  EXPECT_EQ(LabelledControlArray_dimension(lca), 1);
  size_t out_shape[1];
  EXPECT_EQ(LabelledControlArray_shape(lca, out_shape, 1), 1);
  double out_data[6];
  EXPECT_EQ(LabelledControlArray_data(lca, out_data, 6), 6);
  AcquisitionContext_destroy(lbl);
  Connection_destroy(conn);
  String_destroy(instr);
  SymbolUnit_destroy(unit);
  set_last_error(0, nullptr);
  LabelledControlArray_label(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_connection(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_instrument_type(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_units(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_dimension(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_shape(nullptr, out_shape, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_data(nullptr, out_data, 6);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArrayTest, Addition) {
  LabelledControlArray_plusequals_farray(lca, fa);
  LabelledControlArray_plusequals_double(lca, 1.0);
  LabelledControlArray_plusequals_int(lca, 1);
  auto lca_plus_lca = LabelledControlArray_plus_control_array(lca, lca2);
  auto lca_plus_fa  = LabelledControlArray_plus_farray(lca, fa);
  auto lca_plus_d   = LabelledControlArray_plus_double(lca, 1.0);
  auto lca_plus_i   = LabelledControlArray_plus_int(lca, 1);
  LabelledControlArray_destroy(lca_plus_lca);
  LabelledControlArray_destroy(lca_plus_fa);
  LabelledControlArray_destroy(lca_plus_d);
  LabelledControlArray_destroy(lca_plus_i);
}

TEST_F(LabelledControlArrayTest, Subtraction) {
  LabelledControlArray_minusequals_control_array(lca, lca2);
  LabelledControlArray_minusequals_farray(lca, fa);
  LabelledControlArray_minusequals_double(lca, 1.0);
  LabelledControlArray_minusequals_int(lca, 1);
  auto lca_minus_lca = LabelledControlArray_minus_control_array(lca, lca2);
  auto lca_minus_fa  = LabelledControlArray_minus_farray(lca, fa);
  auto lca_minus_d   = LabelledControlArray_minus_double(lca, 1.0);
  auto lca_minus_i   = LabelledControlArray_minus_int(lca, 1);
  LabelledControlArray_destroy(lca_minus_lca);
  LabelledControlArray_destroy(lca_minus_fa);
  LabelledControlArray_destroy(lca_minus_d);
  LabelledControlArray_destroy(lca_minus_i);
}

TEST_F(LabelledControlArrayTest, Negation) {
  auto lca_neg = LabelledControlArray_negation(lca);
  LabelledControlArray_destroy(lca_neg);
}

TEST_F(LabelledControlArrayTest, Multiplication) {
  LabelledControlArray_timesequals_double(lca, 2.0);
  LabelledControlArray_timesequals_int(lca, 2);
  auto lca_times_d = LabelledControlArray_times_double(lca, 2.0);
  auto lca_times_i = LabelledControlArray_times_int(lca, 2);
  LabelledControlArray_destroy(lca_times_d);
  LabelledControlArray_destroy(lca_times_i);
}

TEST_F(LabelledControlArrayTest, Division) {
  LabelledControlArray_dividesequals_double(lca, 2.0);
  LabelledControlArray_dividesequals_int(lca, 2);
  auto lca_div_d = LabelledControlArray_divides_double(lca, 2.0);
  auto lca_div_i = LabelledControlArray_divides_int(lca, 2);
  LabelledControlArray_destroy(lca_div_d);
  LabelledControlArray_destroy(lca_div_i);
}

TEST_F(LabelledControlArrayTest, MiscArithmeticOperators) {
  auto lca_pow = LabelledControlArray_pow(lca, 1.0);
  LabelledControlArray_destroy(lca_pow);

  auto lca_abs = LabelledControlArray_abs(lca);
  LabelledControlArray_destroy(lca_abs);

  auto lca_min_fa  = LabelledControlArray_min_farray(lca, fa);
  auto lca_min_lca = LabelledControlArray_min_control_array(lca, lca2);
  LabelledControlArray_destroy(lca_min_fa);
  LabelledControlArray_destroy(lca_min_lca);

  auto lca_max_fa  = LabelledControlArray_max_farray(lca, fa);
  auto lca_max_lca = LabelledControlArray_max_control_array(lca, lca2);
  LabelledControlArray_destroy(lca_max_fa);
  LabelledControlArray_destroy(lca_max_lca);
}

TEST_F(LabelledControlArrayTest, NullArgumentsArithmeticOperators) {
  set_last_error(0, nullptr);
  LabelledControlArray_plusequals_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_plusequals_farray(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_plusequals_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_plusequals_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_plus_control_array(nullptr, lca2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_plus_control_array(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_plus_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_plus_farray(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_plus_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_plus_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledControlArray_minusequals_control_array(nullptr, lca2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_minusequals_control_array(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_minusequals_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_minusequals_farray(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_minusequals_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_minusequals_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_minus_control_array(nullptr, lca2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_minus_control_array(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_minus_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_minus_farray(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_minus_double(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_minus_int(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledControlArray_negation(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledControlArray_timesequals_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_timesequals_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_times_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_times_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledControlArray_dividesequals_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_dividesequals_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_divides_double(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_divides_int(nullptr, 2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledControlArray_pow(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_abs(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledControlArray_min_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_min_farray(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_min_control_array(nullptr, lca2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_min_control_array(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  LabelledControlArray_max_farray(nullptr, fa);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_max_farray(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_max_control_array(nullptr, lca2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_max_control_array(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArrayTest, EqualityOperators) {
  EXPECT_TRUE(LabelledControlArray_equality(lca, lca2));
  EXPECT_FALSE(LabelledControlArray_notequality(lca, lca2));
  set_last_error(0, nullptr);
  LabelledControlArray_equality(nullptr, lca2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_equality(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_notequality(nullptr, lca2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_notequality(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArrayTest, ComparisonOperators) {
  EXPECT_TRUE(LabelledControlArray_greaterthan(lca, 0.5));
  EXPECT_FALSE(LabelledControlArray_lessthan(lca, 0.5));
  set_last_error(0, nullptr);
  LabelledControlArray_greaterthan(nullptr, 0.5);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_lessthan(nullptr, 0.5);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArrayTest, OffsetSumReshapeWhereFlipGradient) {
  LabelledControlArray_remove_offset(lca, 1.0);
  EXPECT_DOUBLE_EQ(LabelledControlArray_sum(lca), 15.0);
  size_t new_shape[1] = {6};
  auto   reshaped     = LabelledControlArray_reshape(lca, new_shape, 1);
  LabelledControlArray_destroy(reshaped);
  auto where = LabelledControlArray_where(lca, 2.0);
  ListListSizeT_destroy(where);
  auto flipped = LabelledControlArray_flip(lca, 0);
  LabelledControlArray_destroy(flipped);
  FArrayDoubleHandle grad_buffer[1];
  EXPECT_EQ(LabelledControlArray_full_gradient(lca, grad_buffer, 1), 1);
  for (size_t i = 0; i < 1; ++i) {
    FArrayDouble_destroy(grad_buffer[i]);
  }
  auto grad = LabelledControlArray_gradient(lca, 0);
  FArrayDouble_destroy(grad);
  set_last_error(0, nullptr);
  LabelledControlArray_remove_offset(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_sum(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_reshape(nullptr, new_shape, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_where(nullptr, 2.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_flip(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_full_gradient(nullptr, grad_buffer, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_gradient(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArrayTest, SumOfSquares) {
  EXPECT_DOUBLE_EQ(LabelledControlArray_get_sum_of_squares(lca), 91.0);
  EXPECT_DOUBLE_EQ(LabelledControlArray_get_summed_diff_int_of_squares(lca, 1),
                   55.0);
  EXPECT_DOUBLE_EQ(
      LabelledControlArray_get_summed_diff_double_of_squares(lca, 1.0), 55.0);
  EXPECT_DOUBLE_EQ(
      LabelledControlArray_get_summed_diff_array_of_squares(lca, lca2), 0.0);
  set_last_error(0, nullptr);
  LabelledControlArray_get_sum_of_squares(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_get_summed_diff_int_of_squares(nullptr, 1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_get_summed_diff_double_of_squares(nullptr, 1.0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_get_summed_diff_array_of_squares(nullptr, lca2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_get_summed_diff_array_of_squares(lca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArrayTest, ToJsonFromJson) {
  auto json = LabelledControlArray_to_json_string(lca);
  auto lca3 = LabelledControlArray_from_json_string(json);
  EXPECT_TRUE(LabelledControlArray_equality(lca, lca3));
  LabelledControlArray_destroy(lca3);
  String_destroy(json);
  set_last_error(0, nullptr);
  LabelledControlArray_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  LabelledControlArray_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArrayTest, FromControlArrayNullLabel) {
  set_last_error(0, nullptr);
  LabelledControlArray_from_control_array(ca, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(LabelledControlArrayTest, FromFArrayNullLabel) {
  set_last_error(0, nullptr);
  LabelledControlArray_from_farray(fa, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
