#include <gtest/gtest.h>

#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext_c_api.h"
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class InterpretationContextTest : public ::testing::Test {
 protected:
  void SetUp() override {
    conn = Connection_create_barrier_gate(String_wrap("A"));
    unit = SymbolUnit_create_volt();
    mc1  = MeasurementContext_create(conn, "oscilloscope");
    mc2  = MeasurementContext_create(conn, "multimeter");
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
  EXPECT_THROW(InterpretationContext_create(nullptr, list, unit),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContext_create(axes, nullptr, unit),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContext_create(axes, list, nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContext_destroy(nullptr), std::invalid_argument);
}

TEST_F(InterpretationContextTest, Accessors) {
  auto axes_out = InterpretationContext_independent_variables(ctx);
  auto list_out = InterpretationContext_dependent_variables(ctx);
  auto unit_out = InterpretationContext_unit(ctx);
  EXPECT_EQ(InterpretationContext_dimension(ctx), 2);
  SymbolUnit_destroy(unit_out);
  AxesMeasurementContext_destroy(axes_out);
  ListMeasurementContext_destroy(list_out);
  EXPECT_THROW(InterpretationContext_independent_variables(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContext_dependent_variables(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContext_unit(nullptr), std::invalid_argument);
  EXPECT_THROW(InterpretationContext_dimension(nullptr), std::invalid_argument);
}

TEST_F(InterpretationContextTest, DependentVariableOps) {
  auto mc3 = MeasurementContext_create(conn, "voltmeter");
  InterpretationContext_dependent_variable(ctx, mc3);
  InterpretationContext_replace_dependent_variable(ctx, 0, mc3);
  MeasurementContext_destroy(mc3);
  EXPECT_THROW(InterpretationContext_dependent_variable(nullptr, mc1),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContext_dependent_variable(ctx, nullptr),
               std::invalid_argument);
  EXPECT_THROW(
      InterpretationContext_replace_dependent_variable(nullptr, 0, mc1),
      std::invalid_argument);
  EXPECT_THROW(
      InterpretationContext_replace_dependent_variable(ctx, 0, nullptr),
      std::invalid_argument);
}

TEST_F(InterpretationContextTest, GetIndependentVariable) {
  auto mc_out = InterpretationContext_get_independent_variables(ctx, 0);
  MeasurementContext_destroy(mc_out);
  EXPECT_THROW(InterpretationContext_get_independent_variables(nullptr, 0),
               std::invalid_argument);
}

TEST_F(InterpretationContextTest, WithUnit) {
  auto unit2 = SymbolUnit_create_millivolt();
  auto ctx2  = InterpretationContext_with_unit(ctx, unit2);
  InterpretationContext_destroy(ctx2);
  SymbolUnit_destroy(unit2);
  EXPECT_THROW(InterpretationContext_with_unit(nullptr, unit),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContext_with_unit(ctx, nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContextTest, EqualityOperators) {
  auto ctx2 = InterpretationContext_create(axes, list, unit);
  EXPECT_TRUE(InterpretationContext_equal(ctx, ctx2));
  EXPECT_FALSE(InterpretationContext_not_equal(ctx, ctx2));
  InterpretationContext_destroy(ctx2);
  EXPECT_THROW(InterpretationContext_equal(nullptr, ctx),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContext_equal(ctx, nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContext_not_equal(nullptr, ctx),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContext_not_equal(ctx, nullptr),
               std::invalid_argument);
}

TEST_F(InterpretationContextTest, ToJsonFromJson) {
  auto json = InterpretationContext_to_json_string(ctx);
  auto ctx2 = InterpretationContext_from_json_string(json);
  EXPECT_TRUE(InterpretationContext_equal(ctx, ctx2));
  InterpretationContext_destroy(ctx2);
  String_destroy(json);
  EXPECT_THROW(InterpretationContext_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(InterpretationContext_from_json_string(nullptr),
               std::invalid_argument);
}
