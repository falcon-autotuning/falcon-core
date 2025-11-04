#include <gtest/gtest.h>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"
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
    lca2 = LabelledControlArray_from_controlarray(ca, label);
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
  lca3 = LabelledControlArray_from_controlarray(ca, label);
  LabelledControlArray_destroy(lca3);
  EXPECT_THROW(LabelledControlArray_from_farray(nullptr, label),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_from_controlarray(nullptr, label),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_destroy(nullptr), std::invalid_argument);
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
  EXPECT_THROW(LabelledControlArray_label(nullptr), std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_connection(nullptr), std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_instrument_type(nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_units(nullptr), std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_size(nullptr), std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_dimension(nullptr), std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_shape(nullptr, out_shape, 1),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_data(nullptr, out_data, 6),
               std::invalid_argument);
}

TEST_F(LabelledControlArrayTest, ArithmeticOperators) {
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

  auto lca_neg = LabelledControlArray_negation(lca);
  LabelledControlArray_destroy(lca_neg);

  LabelledControlArray_timesequals_double(lca, 2.0);
  LabelledControlArray_timesequals_int(lca, 2);
  auto lca_times_d = ControlArray_times_double(lca, 2.0);
  auto lca_times_i = LabelledControlArray_times_int(lca, 2);
  LabelledControlArray_destroy(lca_times_d);
  LabelledControlArray_destroy(lca_times_i);

  ControlArray_dividesequals_double(lca, 2.0);
  LabelledControlArray_dividesequals_int(lca, 2);
  auto lca_div_d = LabelledControlArray_divides_double(lca, 2.0);
  auto lca_div_i = LabelledControlArray_divides_int(lca, 2);
  LabelledControlArray_destroy(lca_div_d);
  LabelledControlArray_destroy(lca_div_i);

  auto lca_pow = LabelledControlArray_pow(lca, 2.0);
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

  EXPECT_THROW(LabelledControlArray_plusequals_farray(nullptr, fa),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_plusequals_farray(lca, nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_plusequals_double(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_plusequals_int(nullptr, 1),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_plus_control_array(nullptr, lca2),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_plus_control_array(lca, nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_plus_farray(nullptr, fa),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_plus_farray(lca, nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_plus_double(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_plus_int(nullptr, 1),
               std::invalid_argument);

  EXPECT_THROW(LabelledControlArray_minusequals_control_array(nullptr, lca2),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_minusequals_control_array(lca, nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_minusequals_farray(nullptr, fa),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_minusequals_farray(lca, nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_minusequals_double(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_minusequals_int(nullptr, 1),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_minus_control_array(nullptr, lca2),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_minus_control_array(lca, nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_minus_farray(nullptr, fa),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_minus_farray(lca, nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_minus_double(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_minus_int(nullptr, 1),
               std::invalid_argument);

  EXPECT_THROW(LabelledControlArray_negation(nullptr), std::invalid_argument);

  EXPECT_THROW(LabelledControlArray_timesequals_double(nullptr, 2.0),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_timesequals_int(nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(ControlArray_times_double(nullptr, 2.0), std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_times_int(nullptr, 2),
               std::invalid_argument);

  EXPECT_THROW(ControlArray_dividesequals_double(nullptr, 2.0),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_dividesequals_int(nullptr, 2),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_divides_double(nullptr, 2.0),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_divides_int(nullptr, 2),
               std::invalid_argument);

  EXPECT_THROW(LabelledControlArray_pow(nullptr, 2.0), std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_abs(nullptr), std::invalid_argument);

  EXPECT_THROW(LabelledControlArray_min_farray(nullptr, fa),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_min_farray(lca, nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_min_control_array(nullptr, lca2),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_min_control_array(lca, nullptr),
               std::invalid_argument);

  EXPECT_THROW(LabelledControlArray_max_farray(nullptr, fa),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_max_farray(lca, nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_max_control_array(nullptr, lca2),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_max_control_array(lca, nullptr),
               std::invalid_argument);
}

TEST_F(LabelledControlArrayTest, EqualityOperators) {
  EXPECT_FALSE(LabelledControlArray_equality(lca, lca2));
  EXPECT_TRUE(LabelledControlArray_notequality(lca, lca2));
  EXPECT_THROW(LabelledControlArray_equality(nullptr, lca2),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_equality(lca, nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_notequality(nullptr, lca2),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_notequality(lca, nullptr),
               std::invalid_argument);
}

TEST_F(LabelledControlArrayTest, ComparisonOperators) {
  EXPECT_TRUE(LabelledControlArray_greaterthan(lca, 0.5));
  EXPECT_FALSE(LabelledControlArray_lessthan(lca, 0.5));
  EXPECT_THROW(LabelledControlArray_greaterthan(nullptr, 0.5),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_lessthan(nullptr, 0.5),
               std::invalid_argument);
}

TEST_F(LabelledControlArrayTest, OffsetSumReshapeWhereFlipGradient) {
  LabelledControlArray_remove_offset(lca, 1.0);
  EXPECT_DOUBLE_EQ(LabelledControlArray_sum(lca), 21.0);
  size_t new_shape[1] = {6};
  auto   reshaped     = LabelledControlArray_reshape(lca, new_shape, 1);
  LabelledControlArray_destroy(reshaped);
  auto where = LabelledControlArray_where(lca, 2.0);
  // ListListSizeT_destroy(where); // implement destroy if needed
  auto flipped = LabelledControlArray_flip(lca, 0);
  LabelledControlArray_destroy(flipped);
  LabelledControlArrayHandle grad_buffer[1];
  EXPECT_EQ(LabelledControlArray_full_gradient(lca, grad_buffer, 1), 1);
  for (size_t i = 0; i < 1; ++i) {
    LabelledControlArray_destroy(grad_buffer[i]);
  }
  auto grad = LabelledControlArray_gradient(lca, 0);
  LabelledControlArray_destroy(grad);
  EXPECT_THROW(LabelledControlArray_remove_offset(nullptr, 1.0),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_sum(nullptr), std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_reshape(nullptr, new_shape, 1),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_where(nullptr, 2.0), std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_flip(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_full_gradient(nullptr, grad_buffer, 1),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_gradient(nullptr, 0),
               std::invalid_argument);
}

TEST_F(LabelledControlArrayTest, SumOfSquares) {
  EXPECT_DOUBLE_EQ(LabelledControlArray_get_sum_of_squares(lca), 91.0);
  EXPECT_DOUBLE_EQ(LabelledControlArray_get_summed_diff_int_of_squares(lca, 1),
                   70.0);
  EXPECT_DOUBLE_EQ(
      LabelledControlArray_get_summed_diff_double_of_squares(lca, 1.0), 70.0);
  EXPECT_DOUBLE_EQ(
      LabelledControlArray_get_summed_diff_array_of_squares(lca, lca2), 0.0);
  EXPECT_THROW(LabelledControlArray_get_sum_of_squares(nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_get_summed_diff_int_of_squares(nullptr, 1),
               std::invalid_argument);
  EXPECT_THROW(
      LabelledControlArray_get_summed_diff_double_of_squares(nullptr, 1.0),
      std::invalid_argument);
  EXPECT_THROW(
      LabelledControlArray_get_summed_diff_array_of_squares(nullptr, lca2),
      std::invalid_argument);
  EXPECT_THROW(
      LabelledControlArray_get_summed_diff_array_of_squares(lca, nullptr),
      std::invalid_argument);
}

TEST_F(LabelledControlArrayTest, ToJsonFromJson) {
  auto json = LabelledControlArray_to_json_string(lca);
  auto lca3 = LabelledControlArray_from_json_string(json);
  EXPECT_TRUE(LabelledControlArray_equality(lca, lca3));
  LabelledControlArray_destroy(lca3);
  String_destroy(json);
  EXPECT_THROW(LabelledControlArray_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(LabelledControlArray_from_json_string(nullptr),
               std::invalid_argument);
}
