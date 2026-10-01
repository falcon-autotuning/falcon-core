#include "falcon-core/generic/ErrorHandling_c_api.h"
#include <gtest/gtest.h>

#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon-core/physics/device_structures/Connection_c_api.h"
#include "falcon-core/physics/units/SymbolUnit_c_api.h"

class InstrumentPortTest : public ::testing::Test {
protected:
  void SetUp() override {
    name = String_wrap("default");
    instrument = String_wrap("instrument");
    type = INSTRUMENT_VOLTMETER;
    desc = String_wrap("desc");
    unit = SymbolUnit_create_volt();
    conn = Connection_create_plunger_gate(String_wrap("A"));
    port =
        InstrumentPort_create_port(name, instrument, SCOPE_LOCAL, ACCESS_READ,
                                   INSTRUMENT_CHARACTERISTIC_NONE,
                                   PORT_TYPE_SETTING, conn, type, unit, desc);
    knob = InstrumentPort_create_knob(name, instrument, conn, type, unit, desc);
    meter =
        InstrumentPort_create_meter(name, instrument, conn, type, unit, desc);
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
    String_destroy(desc);
    SymbolUnit_destroy(unit);
    Connection_destroy(conn);
  }
  StringHandle name = nullptr;
  StringHandle instrument = nullptr;
  Instrument type;
  StringHandle desc = nullptr;
  SymbolUnitHandle unit = nullptr;
  ConnectionHandle conn = nullptr;
  InstrumentPortHandle port = nullptr;
  InstrumentPortHandle knob = nullptr;
  InstrumentPortHandle meter = nullptr;
  InstrumentPortHandle timer = nullptr;
  InstrumentPortHandle clock = nullptr;
};

TEST_F(InstrumentPortTest, CreatePortKnobMeterTimerClockDestroy) {
  auto p =
      InstrumentPort_create_port(name, instrument, SCOPE_LOCAL, ACCESS_READ,
                                 INSTRUMENT_CHARACTERISTIC_NONE,
                                 PORT_TYPE_SETTING, conn, type, unit, desc);
  InstrumentPort_destroy(p);
  auto k = InstrumentPort_create_knob(name, instrument, conn, type, unit, desc);
  InstrumentPort_destroy(k);
  auto m =
      InstrumentPort_create_meter(name, instrument, conn, type, unit, desc);
  InstrumentPort_destroy(m);
  auto t = InstrumentPort_create_timer();
  InstrumentPort_destroy(t);
  auto c = InstrumentPort_create_execution_clock();
  InstrumentPort_destroy(c);
  set_last_error(0, nullptr);

  InstrumentPort_create_port(nullptr, instrument, SCOPE_LOCAL, ACCESS_READ,
                             INSTRUMENT_CHARACTERISTIC_NONE, PORT_TYPE_SETTING,
                             conn, type, unit, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_port(name, nullptr, SCOPE_LOCAL, ACCESS_READ,
                             INSTRUMENT_CHARACTERISTIC_NONE, PORT_TYPE_SETTING,
                             conn, type, unit, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_port(name, instrument, SCOPE_LOCAL, ACCESS_READ,
                             INSTRUMENT_CHARACTERISTIC_NONE, PORT_TYPE_SETTING,
                             nullptr, type, unit, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_port(name, instrument, SCOPE_LOCAL, ACCESS_READ,
                             INSTRUMENT_CHARACTERISTIC_NONE, PORT_TYPE_SETTING,
                             conn, type, nullptr, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_port(name, instrument, SCOPE_LOCAL, ACCESS_READ,
                             INSTRUMENT_CHARACTERISTIC_NONE, PORT_TYPE_SETTING,
                             conn, type, unit, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);

  InstrumentPort_create_setting(nullptr, instrument, SCOPE_LOCAL, ACCESS_READ,
                                INSTRUMENT_CHARACTERISTIC_NONE, conn, type,
                                unit, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_setting(name, nullptr, SCOPE_LOCAL, ACCESS_READ,
                                INSTRUMENT_CHARACTERISTIC_NONE, conn, type,
                                unit, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_setting(name, instrument, SCOPE_LOCAL, ACCESS_READ,
                                INSTRUMENT_CHARACTERISTIC_NONE, nullptr, type,
                                unit, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_setting(name, instrument, SCOPE_LOCAL, ACCESS_READ,
                                INSTRUMENT_CHARACTERISTIC_NONE, conn, type,
                                nullptr, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_setting(name, instrument, SCOPE_LOCAL, ACCESS_READ,
                                INSTRUMENT_CHARACTERISTIC_NONE, conn, type,
                                unit, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);

  InstrumentPort_create_knob(nullptr, instrument, conn, type, unit, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_knob(name, nullptr, conn, type, unit, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_knob(name, instrument, nullptr, type, unit, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_knob(name, instrument, conn, type, nullptr, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_knob(name, instrument, conn, type, unit, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);

  InstrumentPort_create_meter(nullptr, instrument, conn, type, unit, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_meter(name, nullptr, conn, type, unit, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_meter(name, instrument, nullptr, type, unit, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_meter(name, instrument, conn, type, nullptr, desc);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_create_meter(name, instrument, conn, type, unit, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);

  InstrumentPort_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(InstrumentPortTest, Accessors) {
  auto n = InstrumentPort_default_name(port);
  auto pn = InstrumentPort_pseudo_name(port);
  auto t = InstrumentPort_instrument_type(port);
  auto u = InstrumentPort_units(port);
  auto d = InstrumentPort_description(port);
  auto ifn = InstrumentPort_instrument_facing_name(port);

  String_destroy(n);
  if (pn)
    Connection_destroy(pn);
  SymbolUnit_destroy(u);
  String_destroy(d);
  String_destroy(ifn);

  set_last_error(0, nullptr);
  InstrumentPort_default_name(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_pseudo_name(nullptr);
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
  EXPECT_TRUE(InstrumentPort_is_setting(port));
  EXPECT_TRUE(InstrumentPort_is_knob(knob));
  EXPECT_TRUE(InstrumentPort_is_meter(meter));
  EXPECT_FALSE(InstrumentPort_is_knob(port));
  EXPECT_FALSE(InstrumentPort_is_meter(port));
  EXPECT_FALSE(InstrumentPort_is_setting(knob));
  EXPECT_FALSE(InstrumentPort_is_setting(meter));

  set_last_error(0, nullptr);
  InstrumentPort_is_setting(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_is_knob(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  InstrumentPort_is_meter(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(InstrumentPortTest, Equality) {
  auto p2 =
      InstrumentPort_create_port(name, instrument, SCOPE_LOCAL, ACCESS_READ,
                                 INSTRUMENT_CHARACTERISTIC_NONE,
                                 PORT_TYPE_SETTING, conn, type, unit, desc);
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
  auto p2 = InstrumentPort_from_json_string(json);
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
TEST_F(InstrumentPortTest, Copy) {
  auto copy = InstrumentPort_copy(port);

  EXPECT_TRUE(InstrumentPort_equal(port, copy));

  InstrumentPort_destroy(copy);

  set_last_error(0, nullptr);
  InstrumentPort_copy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(InstrumentPortTest, CreateSetting) {
  auto setting = InstrumentPort_create_setting(
      name, instrument, SCOPE_LOCAL, ACCESS_READ,
      INSTRUMENT_CHARACTERISTIC_NONE, conn, type, unit, desc);

  ASSERT_NE(setting, nullptr);

  EXPECT_TRUE(InstrumentPort_is_setting(setting));
  EXPECT_FALSE(InstrumentPort_is_knob(setting));
  EXPECT_FALSE(InstrumentPort_is_meter(setting));

  InstrumentPort_destroy(setting);
}

TEST_F(InstrumentPortTest, NewAccessors) {
  auto instrument_name = InstrumentPort_instrument_name(port);

  ASSERT_NE(instrument_name, nullptr);
  EXPECT_STREQ(instrument_name->raw, "instrument");

  EXPECT_EQ(InstrumentPort_scope(port), SCOPE_LOCAL);
  EXPECT_EQ(InstrumentPort_access(port), ACCESS_READ);
  EXPECT_EQ(InstrumentPort_characteristic(port),
            INSTRUMENT_CHARACTERISTIC_NONE);
  EXPECT_EQ(InstrumentPort_type(port), PORT_TYPE_SETTING);

  String_destroy(instrument_name);

  set_last_error(0, nullptr);
  InstrumentPort_instrument_name(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  InstrumentPort_scope(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  InstrumentPort_access(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  InstrumentPort_characteristic(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  InstrumentPort_type(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(InstrumentPortTest, TimerAndClockProperties) {
  EXPECT_TRUE(InstrumentPort_is_knob(timer));
  EXPECT_FALSE(InstrumentPort_is_meter(timer));
  EXPECT_FALSE(InstrumentPort_is_setting(timer));

  EXPECT_TRUE(InstrumentPort_is_meter(clock));
  EXPECT_FALSE(InstrumentPort_is_knob(clock));
  EXPECT_FALSE(InstrumentPort_is_setting(clock));

  EXPECT_EQ(InstrumentPort_instrument_type(timer), INSTRUMENT_CLOCK);

  EXPECT_EQ(InstrumentPort_instrument_type(clock), INSTRUMENT_CLOCK);

  EXPECT_EQ(InstrumentPort_scope(timer), SCOPE_GLOBAL);

  EXPECT_EQ(InstrumentPort_scope(clock), SCOPE_GLOBAL);
}

TEST_F(InstrumentPortTest, PseudoNameContents) {
  auto pseudo = InstrumentPort_pseudo_name(port);

  ASSERT_NE(pseudo, nullptr);

  auto name_handle = Connection_name(pseudo);

  ASSERT_NE(name_handle, nullptr);
  EXPECT_STREQ(name_handle->raw, "A");

  String_destroy(name_handle);
  Connection_destroy(pseudo);
}

TEST_F(InstrumentPortTest, SerializationTimerAndClock) {
  auto timer_json = InstrumentPort_to_json_string(timer);
  auto timer_copy = InstrumentPort_from_json_string(timer_json);

  EXPECT_TRUE(InstrumentPort_equal(timer, timer_copy));

  InstrumentPort_destroy(timer_copy);
  String_destroy(timer_json);

  auto clock_json = InstrumentPort_to_json_string(clock);
  auto clock_copy = InstrumentPort_from_json_string(clock_json);

  EXPECT_TRUE(InstrumentPort_equal(clock, clock_copy));

  InstrumentPort_destroy(clock_copy);
  String_destroy(clock_json);
}
