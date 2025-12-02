#include <gtest/gtest.h>

#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext_c_api.h"
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class InterpretationContextTest : public ::testing::Test {
 protected:
  void SetUp() override {
    conn = Connection_create_barrier_gate(String_wrap("A"));
    unit = SymbolUnit_create_volt();
    mc1  = MeasurementContext_create(conn, String_wrap("oscilloscope"));
    mc2  = MeasurementContext_create(conn, String_wrap("multimeter"));
    axes = AxesMeasurementContext_create_empty();
    AxesMeasurementContext_push_back(axes, mc1);
    AxesMeasurementContext_push_back(axes, mc2);
    list = ListMeasurementContext_create_empty();
    ListMeasurementContext_push_back(list, mc2);
    ctx = InterpretationContext_create(axes, list, unit);
  }
  void TearDown() override {
    InterpretationContext_destroy(ctx);
    MeasurementContext_destroy(mc1);
    MeasurementContext_destroy(mc2);
    Connection_destroy(conn);
    SymbolUnit_destroy(unit);
    AxesMeasurementContext_destroy(axes);
    ListMeasurementContext_destroy(list);
  }
  ConnectionHandle             conn;
  SymbolUnitHandle             unit;
  MeasurementContextHandle     mc1;
  MeasurementContextHandle     mc2;
  AxesMeasurementContextHandle axes;
  ListMeasurementContextHandle list;
  InterpretationContextHandle  ctx;
};

TEST_F(InterpretationContextTest, CreateDestroy) {
  auto ctx2 = InterpretationContext_create(axes, list, unit);
  InterpretationContext_destroy(ctx2);
  set_last_error(0, nullptr);
  InterpretationContext_create(nullptr, list, unit);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContext_create(axes, nullptr, unit);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContext_create(axes, list, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContext_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(InterpretationContextTest, Accessors) {
  auto axes_out = InterpretationContext_independent_variables(ctx);
  auto list_out = InterpretationContext_dependent_variables(ctx);
  auto unit_out = InterpretationContext_unit(ctx);
  EXPECT_EQ(InterpretationContext_dimension(ctx), 2);
  SymbolUnit_destroy(unit_out);
  AxesMeasurementContext_destroy(axes_out);
  ListMeasurementContext_destroy(list_out);
  set_last_error(0, nullptr);
  InterpretationContext_independent_variables(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContext_dependent_variables(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContext_unit(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContext_dimension(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(InterpretationContextTest, DependentVariableOps) {
  auto mc3 = MeasurementContext_create(conn, String_wrap("voltmeter"));
  InterpretationContext_add_dependent_variable(ctx, mc3);
  InterpretationContext_replace_dependent_variable(ctx, 0, mc3);
  MeasurementContext_destroy(mc3);
  set_last_error(0, nullptr);
  InterpretationContext_add_dependent_variable(nullptr, mc1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContext_add_dependent_variable(ctx, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContext_replace_dependent_variable(nullptr, 0, mc1);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContext_replace_dependent_variable(ctx, 0, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(InterpretationContextTest, GetIndependentVariable) {
  auto mc_out = InterpretationContext_get_independent_variables(ctx, 0);
  MeasurementContext_destroy(mc_out);
  set_last_error(0, nullptr);
  InterpretationContext_get_independent_variables(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(InterpretationContextTest, WithUnit) {
  auto unit2 = SymbolUnit_create_millivolt();
  auto ctx2  = InterpretationContext_with_unit(ctx, unit2);
  InterpretationContext_destroy(ctx2);
  SymbolUnit_destroy(unit2);
  set_last_error(0, nullptr);
  InterpretationContext_with_unit(nullptr, unit);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContext_with_unit(ctx, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(InterpretationContextTest, EqualityOperators) {
  auto ctx2 = InterpretationContext_create(axes, list, unit);
  EXPECT_TRUE(InterpretationContext_equal(ctx, ctx2));
  EXPECT_FALSE(InterpretationContext_not_equal(ctx, ctx2));
  InterpretationContext_destroy(ctx2);
  set_last_error(0, nullptr);
  InterpretationContext_equal(nullptr, ctx);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContext_equal(ctx, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContext_not_equal(nullptr, ctx);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContext_not_equal(ctx, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(InterpretationContextTest, ToJsonFromJson) {
  auto json = InterpretationContext_to_json_string(ctx);
  auto ctx2 = InterpretationContext_from_json_string(json);
  EXPECT_TRUE(InterpretationContext_equal(ctx, ctx2));
  InterpretationContext_destroy(ctx2);
  String_destroy(json);
  set_last_error(0, nullptr);
  InterpretationContext_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InterpretationContext_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
