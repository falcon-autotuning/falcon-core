#include <gtest/gtest.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

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

  EXPECT_THROW(InstrumentPort_create_port(nullptr, conn, type, unit, desc),
               std::invalid_argument);
  EXPECT_THROW(InstrumentPort_create_port(name, nullptr, type, unit, desc),
               std::invalid_argument);  // psuedo_name can be nullptr, so skip
  EXPECT_THROW(InstrumentPort_create_port(name, conn, nullptr, unit, desc),
               std::invalid_argument);
  EXPECT_THROW(InstrumentPort_create_port(name, conn, type, nullptr, desc),
               std::invalid_argument);
  EXPECT_THROW(InstrumentPort_create_port(name, conn, type, unit, nullptr),
               std::invalid_argument);

  EXPECT_THROW(InstrumentPort_create_knob(nullptr, conn, type, unit, desc),
               std::invalid_argument);
  EXPECT_THROW(InstrumentPort_create_knob(name, nullptr, type, unit, desc),
               std::invalid_argument);  // psuedo_name can be nullptr, so skip
  EXPECT_THROW(InstrumentPort_create_knob(name, conn, nullptr, unit, desc),
               std::invalid_argument);
  EXPECT_THROW(InstrumentPort_create_knob(name, conn, type, nullptr, desc),
               std::invalid_argument);
  EXPECT_THROW(InstrumentPort_create_knob(name, conn, type, unit, nullptr),
               std::invalid_argument);

  EXPECT_THROW(InstrumentPort_create_meter(nullptr, conn, type, unit, desc),
               std::invalid_argument);
  EXPECT_THROW(InstrumentPort_create_meter(name, nullptr, type, unit, desc),
               std::invalid_argument);  // psuedo_name can be nullptr, so skip
  EXPECT_THROW(InstrumentPort_create_meter(name, conn, nullptr, unit, desc),
               std::invalid_argument);
  EXPECT_THROW(InstrumentPort_create_meter(name, conn, type, nullptr, desc),
               std::invalid_argument);
  EXPECT_THROW(InstrumentPort_create_meter(name, conn, type, unit, nullptr),
               std::invalid_argument);

  EXPECT_THROW(InstrumentPort_destroy(nullptr), std::invalid_argument);
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

  EXPECT_THROW(InstrumentPort_default_name(nullptr), std::invalid_argument);
  EXPECT_THROW(InstrumentPort_psuedo_name(nullptr), std::invalid_argument);
  EXPECT_THROW(InstrumentPort_instrument_type(nullptr), std::invalid_argument);
  EXPECT_THROW(InstrumentPort_units(nullptr), std::invalid_argument);
  EXPECT_THROW(InstrumentPort_description(nullptr), std::invalid_argument);
  EXPECT_THROW(InstrumentPort_instrument_facing_name(nullptr),
               std::invalid_argument);
}

TEST_F(InstrumentPortTest, TypeChecks) {
  EXPECT_TRUE(InstrumentPort_is_port(port));
  EXPECT_TRUE(InstrumentPort_is_knob(knob));
  EXPECT_TRUE(InstrumentPort_is_meter(meter));
  EXPECT_FALSE(InstrumentPort_is_knob(port));
  EXPECT_FALSE(InstrumentPort_is_meter(port));
  EXPECT_FALSE(InstrumentPort_is_port(knob));
  EXPECT_FALSE(InstrumentPort_is_port(meter));

  EXPECT_THROW(InstrumentPort_is_port(nullptr), std::invalid_argument);
  EXPECT_THROW(InstrumentPort_is_knob(nullptr), std::invalid_argument);
  EXPECT_THROW(InstrumentPort_is_meter(nullptr), std::invalid_argument);
}

TEST_F(InstrumentPortTest, Equality) {
  auto p2 = InstrumentPort_create_port(name, conn, type, unit, desc);
  EXPECT_TRUE(InstrumentPort_equal(port, p2));
  EXPECT_FALSE(InstrumentPort_not_equal(port, p2));
  InstrumentPort_destroy(p2);

  EXPECT_THROW(InstrumentPort_equal(nullptr, port), std::invalid_argument);
  EXPECT_THROW(InstrumentPort_equal(port, nullptr), std::invalid_argument);
  EXPECT_THROW(InstrumentPort_not_equal(nullptr, port), std::invalid_argument);
  EXPECT_THROW(InstrumentPort_not_equal(port, nullptr), std::invalid_argument);
}

TEST_F(InstrumentPortTest, Serialization) {
  auto json = InstrumentPort_to_json_string(port);
  auto p2   = InstrumentPort_from_json_string(json);
  EXPECT_TRUE(InstrumentPort_equal(port, p2));
  InstrumentPort_destroy(p2);
  String_destroy(json);

  EXPECT_THROW(InstrumentPort_to_json_string(nullptr), std::invalid_argument);
  EXPECT_THROW(InstrumentPort_from_json_string(nullptr), std::invalid_argument);
}
