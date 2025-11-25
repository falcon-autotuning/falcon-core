#include <gtest/gtest.h>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/instrument_interfaces/names/Ports_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class PortsTest : public ::testing::Test {
 protected:
  void SetUp() override {
    name = String_wrap("default");
    type = String_wrap("type");
    desc = String_wrap("desc");
    unit = SymbolUnit_create_volt();
    conn = Connection_create_plunger_gate(String_wrap("A"));
    port = InstrumentPort_create_port(name, conn, type, unit, desc);

    items = ListInstrumentPort_create_empty();
    ListInstrumentPort_push_back(items, port);

    ports = Ports_create(items);
  }
  void TearDown() override {
    Ports_destroy(ports);
    ListInstrumentPort_destroy(items);
    InstrumentPort_destroy(port);
    String_destroy(name);
    String_destroy(type);
    String_destroy(desc);
    SymbolUnit_destroy(unit);
    Connection_destroy(conn);
  }
  StringHandle             name  = nullptr;
  StringHandle             type  = nullptr;
  StringHandle             desc  = nullptr;
  SymbolUnitHandle         unit  = nullptr;
  ConnectionHandle         conn  = nullptr;
  InstrumentPortHandle     port  = nullptr;
  ListInstrumentPortHandle items = nullptr;
  PortsHandle              ports = nullptr;
};

TEST_F(PortsTest, CreateDestroy) {
  auto p = Ports_create(items);
  Ports_destroy(p);
  auto e = Ports_create_empty();
  Ports_destroy(e);
  set_last_error(0, nullptr);
  Ports_create(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PortsTest, PortsAccessors) {
  auto p = Ports_ports(ports);
  EXPECT_EQ(ListInstrumentPort_size(p), 1);
  ListInstrumentPort_destroy(p);

  auto names = Ports_default_names(ports);
  EXPECT_EQ(ListString_size(names), 1);
  ListString_destroy(names);

  auto psnames = Ports_get_psuedo_names(ports);
  ListConnection_destroy(psnames);

  auto rawnames = Ports__get_raw_names(ports);
  ListString_destroy(rawnames);

  auto ifnames = Ports__get_instrument_facing_names(ports);
  ListString_destroy(ifnames);

  set_last_error(0, nullptr);
  Ports_ports(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports_default_names(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports_get_psuedo_names(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports__get_raw_names(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports__get_instrument_facing_names(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PortsTest, MatchingPort) {
  auto p = Ports__get_psuedoname_matching_port(ports, conn);
  InstrumentPort_destroy(p);
  set_last_error(0, nullptr);
  Ports__get_psuedoname_matching_port(nullptr, conn);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports__get_psuedoname_matching_port(ports, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  auto t  = String_wrap("type");
  auto p2 = Ports__get_instrument_type_matching_port(ports, t);
  InstrumentPort_destroy(p2);
  String_destroy(t);
  set_last_error(0, nullptr);
  Ports__get_instrument_type_matching_port(nullptr, t);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports__get_instrument_type_matching_port(ports, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PortsTest, TypeChecks) {
  EXPECT_FALSE(Ports_is_knobs(ports));
  EXPECT_FALSE(Ports_is_meters(ports));
  set_last_error(0, nullptr);
  Ports_is_knobs(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports_is_meters(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PortsTest, Intersection) {
  auto p2    = Ports_create(items);
  auto inter = Ports_intersection(ports, p2);
  Ports_destroy(inter);
  Ports_destroy(p2);
  set_last_error(0, nullptr);
  Ports_intersection(nullptr, ports);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports_intersection(ports, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PortsTest, PushBackSizeEmptyEraseClearAtItemsContainsIndex) {
  auto e = Ports_create_empty();
  Ports_push_back(e, port);
  EXPECT_EQ(Ports_size(e), 1);
  EXPECT_FALSE(Ports_empty(e));
  Ports_erase_at(e, 0);
  EXPECT_TRUE(Ports_empty(e));
  Ports_push_back(e, port);
  Ports_clear(e);
  EXPECT_TRUE(Ports_empty(e));
  Ports_push_back(e, port);
  auto a = Ports_at(e, 0);
  InstrumentPort_destroy(a);
  auto items = Ports_items(e);
  ListString_destroy(items);
  EXPECT_TRUE(Ports_contains(e, port));
  EXPECT_EQ(Ports_index(e, port), 0);
  Ports_destroy(e);

  set_last_error(0, nullptr);
  Ports_push_back(nullptr, port);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports_push_back(ports, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports_items(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports_contains(nullptr, port);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports_contains(ports, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports_index(nullptr, port);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports_index(ports, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PortsTest, Equality) {
  auto p2 = Ports_create(items);
  EXPECT_TRUE(Ports_equal(ports, p2));
  EXPECT_FALSE(Ports_not_equal(ports, p2));
  Ports_destroy(p2);
  set_last_error(0, nullptr);
  Ports_equal(nullptr, ports);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports_equal(ports, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports_not_equal(nullptr, ports);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports_not_equal(ports, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(PortsTest, Serialization) {
  auto json = Ports_to_json_string(ports);
  auto p2   = Ports_from_json_string(json);
  EXPECT_TRUE(Ports_equal(ports, p2));
  Ports_destroy(p2);
  String_destroy(json);
  set_last_error(0, nullptr);
  Ports_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  Ports_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
