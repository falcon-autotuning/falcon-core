#include <gtest/gtest.h>
#include "falcon_core/generic/ErrorHandling_c_api.h"

#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"

class MeasurementContextTest : public ::testing::Test {
 protected:
  void SetUp() override {
    conn = Connection_create_barrier_gate(String_wrap("A"));
    port = InstrumentPort_create_port(
        String_wrap("P1"), Connection_create_plunger_gate(String_wrap("G1")));
    mc  = MeasurementContext_create(conn, String_wrap("oscilloscope"));
    mc2 = MeasurementContext_create_from_port(port);
  }
  void TearDown() override {
    MeasurementContext_destroy(mc);
    MeasurementContext_destroy(mc2);
    Connection_destroy(conn);
    InstrumentPort_destroy(port);
  }
  ConnectionHandle         conn;
  InstrumentPortHandle     port;
  MeasurementContextHandle mc;
  MeasurementContextHandle mc2;
};

TEST_F(MeasurementContextTest, CreateDestroy) {
  auto m = MeasurementContext_create(conn, String_wrap("multimeter"));
  MeasurementContext_destroy(m);
  auto m2 = MeasurementContext_create_from_port(port);
  MeasurementContext_destroy(m2);
  set_last_error(0, nullptr);
  MeasurementContext_create(nullptr, String_wrap("oscilloscope"));
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementContext_create(conn, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementContext_create_from_port(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementContext_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MeasurementContextTest, Accessors) {
  auto c = MeasurementContext_connection(mc);
  auto t = MeasurementContext_instrument_type(mc);
  Connection_destroy(c);
  String_destroy(t);
  set_last_error(0, nullptr);
  MeasurementContext_connection(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementContext_instrument_type(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MeasurementContextTest, EqualityOperators) {
  EXPECT_FALSE(MeasurementContext_equal(mc, mc2));
  EXPECT_TRUE(MeasurementContext_not_equal(mc, mc2));
  set_last_error(0, nullptr);
  MeasurementContext_equal(nullptr, mc2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementContext_equal(mc, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementContext_not_equal(nullptr, mc2);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementContext_not_equal(mc, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(MeasurementContextTest, ToJsonFromJson) {
  auto json = MeasurementContext_to_json_string(mc);
  auto mc3  = MeasurementContext_from_json_string(json);
  EXPECT_TRUE(MeasurementContext_equal(mc, mc3));
  MeasurementContext_destroy(mc3);
  String_destroy(json);
  set_last_error(0, nullptr);
  MeasurementContext_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  MeasurementContext_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
