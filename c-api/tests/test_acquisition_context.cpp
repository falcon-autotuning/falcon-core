#include <gtest/gtest.h>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentTypes_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class AcquisitionContextTest : public ::testing::Test {
 protected:
  void SetUp() override {
    conn       = Connection_create_barrier_gate(String_wrap("A"));
    unit       = SymbolUnit_create_volt();
    instr_type = String_wrap("oscilloscope");
    ctx        = AcquisitionContext_create(conn, instr_type, unit);
    port       = InstrumentPort_create_port(String_wrap("P1"),
                                      conn,
                                      InstrumentTypes_voltmeter(),
                                      SymbolUnit_create_volt(),
                                      String_wrap(""));
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
  set_last_error(0, nullptr);
  AcquisitionContext_create(nullptr, instr_type, unit);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AcquisitionContext_create(conn, nullptr, unit);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AcquisitionContext_create(conn, instr_type, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AcquisitionContext_create_from_port(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AcquisitionContext_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AcquisitionContextTest, Accessors) {
  auto c = AcquisitionContext_connection(ctx);
  auto t = AcquisitionContext_instrument_type(ctx);
  auto u = AcquisitionContext_units(ctx);
  Connection_destroy(c);
  String_destroy(t);
  SymbolUnit_destroy(u);
  set_last_error(0, nullptr);
  AcquisitionContext_connection(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AcquisitionContext_instrument_type(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AcquisitionContext_units(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AcquisitionContextTest, Division) {
  auto u2           = SymbolUnit_create_millivolt();
  auto ctx_div_unit = AcquisitionContext_division_unit(ctx, u2);
  AcquisitionContext_destroy(ctx_div_unit);
  auto ctx_div_ctx = AcquisitionContext_division(ctx, ctx2);
  AcquisitionContext_destroy(ctx_div_ctx);
  SymbolUnit_destroy(u2);
  set_last_error(0, nullptr);
  AcquisitionContext_division_unit(nullptr, unit);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AcquisitionContext_division_unit(ctx, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AcquisitionContext_division(nullptr, ctx2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AcquisitionContext_division(ctx, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AcquisitionContextTest, Match) {
  auto c = Connection_create_barrier_gate(String_wrap("A"));
  EXPECT_TRUE(AcquisitionContext_match_connection(ctx, c));
  StringHandle t = String_wrap("oscilloscope");
  EXPECT_TRUE(AcquisitionContext_match_instrument_type(ctx, t));
  Connection_destroy(c);
  String_destroy(t);
  set_last_error(0, nullptr);
  AcquisitionContext_match_connection(nullptr, conn);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AcquisitionContext_match_connection(ctx, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AcquisitionContext_match_instrument_type(nullptr, instr_type);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AcquisitionContext_match_instrument_type(ctx, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AcquisitionContextTest, EqualityOperators) {
  EXPECT_FALSE(AcquisitionContext_equal(ctx, ctx2));
  EXPECT_TRUE(AcquisitionContext_not_equal(ctx, ctx2));
  set_last_error(0, nullptr);
  AcquisitionContext_equal(nullptr, ctx2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AcquisitionContext_equal(ctx, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AcquisitionContext_not_equal(nullptr, ctx2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AcquisitionContext_not_equal(ctx, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(AcquisitionContextTest, ToJsonFromJson) {
  auto json = AcquisitionContext_to_json_string(ctx);
  auto ctx3 = AcquisitionContext_from_json_string(json);
  EXPECT_TRUE(AcquisitionContext_equal(ctx, ctx3));
  AcquisitionContext_destroy(ctx3);
  String_destroy(json);
  set_last_error(0, nullptr);
  AcquisitionContext_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  AcquisitionContext_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
