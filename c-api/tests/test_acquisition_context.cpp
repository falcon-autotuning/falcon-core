#include <gtest/gtest.h>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class AcquisitionContextTest : public ::testing::Test {
 protected:
  void SetUp() override {
    conn       = Connection_create_barrier_gate(String_wrap("A"));
    unit       = SymbolUnit_create_volt();
    instr_type = String_wrap("oscilloscope");
    ctx        = AcquisitionContext_create(conn, instr_type, unit);
    port       = InstrumentPort_create_port(String_wrap("P1"), conn);
    ctx2       = AcquisitionContext_create_from_port(port);
  }
  void TearDown() override {
    AcquisitionContext_destroy(ctx);
    AcquisitionContext_destroy(ctx2);
    Connection_destroy(conn);
    SymbolUnit_destroy(unit);
    String_destroy(instr_type);
    InstrumentPort_destroy(port);
  }
  ConnectionHandle         conn;
  SymbolUnitHandle         unit;
  StringHandle             instr_type;
  AcquisitionContextHandle ctx;
  AcquisitionContextHandle ctx2;
  InstrumentPortHandle     port;
};

TEST_F(AcquisitionContextTest, CreateDestroy) {
  auto c = AcquisitionContext_create(conn, instr_type, unit);
  AcquisitionContext_destroy(c);
  auto c2 = AcquisitionContext_create_from_port(port);
  AcquisitionContext_destroy(c2);
  EXPECT_THROW(AcquisitionContext_create(nullptr, instr_type, unit),
               std::invalid_argument);
  EXPECT_THROW(AcquisitionContext_create(conn, nullptr, unit),
               std::invalid_argument);
  EXPECT_THROW(AcquisitionContext_create(conn, instr_type, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AcquisitionContext_create_from_port(nullptr),
               std::invalid_argument);
  EXPECT_THROW(AcquisitionContext_destroy(nullptr), std::invalid_argument);
}

TEST_F(AcquisitionContextTest, Accessors) {
  auto c = AcquisitionContext_connection(ctx);
  auto t = AcquisitionContext_instrument_type(ctx);
  auto u = AcquisitionContext_units(ctx);
  Connection_destroy(c);
  String_destroy(t);
  SymbolUnit_destroy(u);
  EXPECT_THROW(AcquisitionContext_connection(nullptr), std::invalid_argument);
  EXPECT_THROW(AcquisitionContext_instrument_type(nullptr),
               std::invalid_argument);
  EXPECT_THROW(AcquisitionContext_units(nullptr), std::invalid_argument);
}

TEST_F(AcquisitionContextTest, Division) {
  auto u2           = SymbolUnit_create_millivolt();
  auto ctx_div_unit = AcquisitionContext_division_unit(ctx, u2);
  AcquisitionContext_destroy(ctx_div_unit);
  auto ctx_div_ctx = AcquisitionContext_division(ctx, ctx2);
  AcquisitionContext_destroy(ctx_div_ctx);
  SymbolUnit_destroy(u2);
  EXPECT_THROW(AcquisitionContext_division_unit(nullptr, unit),
               std::invalid_argument);
  EXPECT_THROW(AcquisitionContext_division_unit(ctx, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AcquisitionContext_division(nullptr, ctx2),
               std::invalid_argument);
  EXPECT_THROW(AcquisitionContext_division(ctx, nullptr),
               std::invalid_argument);
}

TEST_F(AcquisitionContextTest, Match) {
  auto c = Connection_create_barrier_gate(String_wrap("A"));
  EXPECT_TRUE(AcquisitionContext_match_connection(ctx, c));
  StringHandle t = String_wrap("oscilloscope");
  EXPECT_TRUE(AcquisitionContext_match_instrument_type(ctx, t));
  Connection_destroy(c);
  String_destroy(t);
  EXPECT_THROW(AcquisitionContext_match_connection(nullptr, conn),
               std::invalid_argument);
  EXPECT_THROW(AcquisitionContext_match_connection(ctx, nullptr),
               std::invalid_argument);
  EXPECT_THROW(AcquisitionContext_match_instrument_type(nullptr, instr_type),
               std::invalid_argument);
  EXPECT_THROW(AcquisitionContext_match_instrument_type(ctx, nullptr),
               std::invalid_argument);
}

TEST_F(AcquisitionContextTest, EqualityOperators) {
  EXPECT_FALSE(AcquisitionContext_equal(ctx, ctx2));
  EXPECT_TRUE(AcquisitionContext_not_equal(ctx, ctx2));
  EXPECT_THROW(AcquisitionContext_equal(nullptr, ctx2), std::invalid_argument);
  EXPECT_THROW(AcquisitionContext_equal(ctx, nullptr), std::invalid_argument);
  EXPECT_THROW(AcquisitionContext_not_equal(nullptr, ctx2),
               std::invalid_argument);
  EXPECT_THROW(AcquisitionContext_not_equal(ctx, nullptr),
               std::invalid_argument);
}

TEST_F(AcquisitionContextTest, ToJsonFromJson) {
  auto json = AcquisitionContext_to_json_string(ctx);
  auto ctx3 = AcquisitionContext_from_json_string(json);
  EXPECT_TRUE(AcquisitionContext_equal(ctx, ctx3));
  AcquisitionContext_destroy(ctx3);
  String_destroy(json);
  EXPECT_THROW(AcquisitionContext_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(AcquisitionContext_from_json_string(nullptr),
               std::invalid_argument);
}
