#include <gtest/gtest.h>
#include "falcon-core/generic/ErrorHandling_c_api.h"

#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon-core/physics/device_structures/Connection_c_api.h"
#include "falcon-core/physics/units/SymbolUnit_c_api.h"

class InstrumentPortTest : public ::testing::Test {
 protected:
  void SetUp() override {
    name  = String_wrap("default");
    type  = String_wrap("type");
    desc  = String_wrap("desc");
    unit  = SymbolUnit_create_volt();
    conn  = Connection_create_plunger_gate(String_wrap("A"));
    port  = InstrumentPort_create_port(name, conn, type, unit, desc);
    knob  = InstrumentPort_create_knob(name, conn, type, unit, desc);
    meter = InstrumentPort_create_meter(name, conn, type, unit, desc);
    timer = InstrumentPort_create_timer();
    clock = InstrumentPort_create_execution_clock();
  }
  void TearDown() override {
    InstrumentPort_destroy(port);
    InstrumentPort_destroy(knob);
    InstrumentPort_destroy(meter);
    InstrumentPort_destroy(timer);
    InstrumentPort_destroy(clock);
    String_destroy(name);
    String_destroy(type);
    String_destroy(desc);
    SymbolUnit_destroy(unit);
    Connection_destroy(conn);
  }
  StringHandle         name  = nullptr;
  StringHandle         type  = nullptr;
  StringHandle         desc  = nullptr;
  SymbolUnitHandle     unit  = nullptr;
  ConnectionHandle     conn  = nullptr;
  InstrumentPortHandle port  = nullptr;
  InstrumentPortHandle knob  = nullptr;
  InstrumentPortHandle meter = nullptr;
  InstrumentPortHandle timer = nullptr;
  InstrumentPortHandle clock = nullptr;
};

TEST_F(InstrumentPortTest, CreatePortKnobMeterTimerClockDestroy) {
  auto p = InstrumentPort_create_port(name, conn, type, unit, desc);
  InstrumentPort_destroy(p);
  auto k = InstrumentPort_create_knob(name, conn, type, unit, desc);
  InstrumentPort_destroy(k);
  auto m = InstrumentPort_create_meter(name, conn, type, unit, desc);
  InstrumentPort_destroy(m);
  auto t = InstrumentPort_create_timer();
  InstrumentPort_destroy(t);
  auto c = InstrumentPort_create_execution_clock();
  InstrumentPort_destroy(c);

  set_last_error(0, nullptr);
  InstrumentPort_create_port(nullptr, conn, type, unit, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_port(name, conn, nullptr, unit, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_port(name, conn, type, nullptr, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_port(name, conn, type, unit, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  InstrumentPort_create_knob(nullptr, conn, type, unit, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_knob(name, conn, nullptr, unit, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_knob(name, conn, type, nullptr, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_knob(name, conn, type, unit, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  InstrumentPort_create_meter(nullptr, conn, type, unit, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_meter(name, conn, nullptr, unit, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_meter(name, conn, type, nullptr, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_meter(name, conn, type, unit, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  InstrumentPort_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(InstrumentPortTest, Accessors) {
  auto n   = InstrumentPort_default_name(port);
  auto pn  = InstrumentPort_psuedo_name(port);
  auto t   = InstrumentPort_instrument_type(port);
  auto u   = InstrumentPort_units(port);
  auto d   = InstrumentPort_description(port);
  auto ifn = InstrumentPort_instrument_facing_name(port);

  String_destroy(n);
  if (pn) Connection_destroy(pn);
  String_destroy(t);
  SymbolUnit_destroy(u);
  String_destroy(d);
  String_destroy(ifn);

  set_last_error(0, nullptr);
  InstrumentPort_default_name(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_psuedo_name(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_instrument_type(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_units(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_description(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_instrument_facing_name(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(InstrumentPortTest, TypeChecks) {
  EXPECT_TRUE(InstrumentPort_is_port(port));
  EXPECT_TRUE(InstrumentPort_is_knob(knob));
  EXPECT_TRUE(InstrumentPort_is_meter(meter));
  EXPECT_FALSE(InstrumentPort_is_knob(port));
  EXPECT_FALSE(InstrumentPort_is_meter(port));
  EXPECT_FALSE(InstrumentPort_is_port(knob));
  EXPECT_FALSE(InstrumentPort_is_port(meter));

  set_last_error(0, nullptr);
  InstrumentPort_is_port(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_is_knob(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_is_meter(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(InstrumentPortTest, Equality) {
  auto p2 = InstrumentPort_create_port(name, conn, type, unit, desc);
  EXPECT_TRUE(InstrumentPort_equal(port, p2));
  EXPECT_FALSE(InstrumentPort_not_equal(port, p2));
  InstrumentPort_destroy(p2);

  set_last_error(0, nullptr);
  InstrumentPort_equal(nullptr, port);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_equal(port, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_not_equal(nullptr, port);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_not_equal(port, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(InstrumentPortTest, Serialization) {
  auto json = InstrumentPort_to_json_string(port);
  auto p2   = InstrumentPort_from_json_string(json);
  EXPECT_TRUE(InstrumentPort_equal(port, p2));
  InstrumentPort_destroy(p2);
  String_destroy(json);

  set_last_error(0, nullptr);
  InstrumentPort_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
