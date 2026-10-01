#include <gtest/gtest.h>

#include "falcon-core/communications/messages/SettingRequest_c_api.h"
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/MapInstrumentPortQuantity_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon-core/instrument_interfaces/names/Ports_c_api.h"
#include "falcon-core/math/Quantity_c_api.h"
#include "falcon-core/physics/device_structures/Connection_c_api.h"
#include "falcon-core/physics/units/SymbolUnit_c_api.h"

class SettingRequestTest : public ::testing::Test {
protected:
  void SetUp() override {
    msg = String_wrap("msg");

    name = String_wrap("gate");
    instrument = String_wrap("dac");
    description = String_wrap("");

    port = InstrumentPort_create_setting(
        name, instrument, SCOPE_LOCAL, ACCESS_READWRITE,
        INSTRUMENT_CHARACTERISTIC_NONE, Connection_create_plunger_gate(name),
        INSTRUMENT_DC_VOLTAGE_SOURCE, SymbolUnit_create_volt(), description);

    getter = InstrumentPort_create_meter(
        String_wrap("meter"), String_wrap("dmm"),
        Connection_create_ohmic(String_wrap("ohm")), INSTRUMENT_VOLTMETER,
        SymbolUnit_create_volt(), String_wrap(""));

    getters = Ports_create_empty();
    Ports_push_back(getters, getter);

    quantity = Quantity_create(1.5, SymbolUnit_create_volt());

    setters = MapInstrumentPortQuantity_create_empty();
    MapInstrumentPortQuantity_insert(setters, port, quantity);

    req = SettingRequest_create(msg, getters, setters);

    req2 = SettingRequest_create(String_wrap("other"), getters, setters);
  }

  void TearDown() override {
    SettingRequest_destroy(req);
    SettingRequest_destroy(req2);

    String_destroy(msg);
    String_destroy(name);
    String_destroy(instrument);
    String_destroy(description);

    Ports_destroy(getters);

    InstrumentPort_destroy(port);
    InstrumentPort_destroy(getter);

    Quantity_destroy(quantity);

    MapInstrumentPortQuantity_destroy(setters);
  }

  StringHandle msg = nullptr;
  StringHandle name = nullptr;
  StringHandle instrument = nullptr;
  StringHandle description = nullptr;

  InstrumentPortHandle port = nullptr;
  InstrumentPortHandle getter = nullptr;

  PortsHandle getters = nullptr;

  QuantityHandle quantity = nullptr;
  MapInstrumentPortQuantityHandle setters = nullptr;

  SettingRequestHandle req = nullptr;
  SettingRequestHandle req2 = nullptr;
};

TEST_F(SettingRequestTest, CreateDestroy) {
  auto r = SettingRequest_create(msg, getters, setters);

  SettingRequest_destroy(r);

  set_last_error(0, nullptr);
  SettingRequest_create(nullptr, getters, setters);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  SettingRequest_create(msg, nullptr, setters);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  SettingRequest_create(msg, getters, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  SettingRequest_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(SettingRequestTest, Accessors) {
  auto m = SettingRequest_message(req);

  EXPECT_STREQ(m->raw, "msg");

  String_destroy(m);

  auto g = SettingRequest_getters(req);

  EXPECT_EQ(Ports_size(g), 1);

  Ports_destroy(g);

  auto s = SettingRequest_setters(req);

  EXPECT_EQ(MapInstrumentPortQuantity_size(s), 1);

  MapInstrumentPortQuantity_destroy(s);

  set_last_error(0, nullptr);
  SettingRequest_message(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  SettingRequest_getters(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  SettingRequest_setters(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(SettingRequestTest, Equality) {
  EXPECT_FALSE(SettingRequest_equal(req, req2));
  EXPECT_TRUE(SettingRequest_not_equal(req, req2));

  EXPECT_TRUE(SettingRequest_equal(req, req));
  EXPECT_FALSE(SettingRequest_not_equal(req, req));

  set_last_error(0, nullptr);
  SettingRequest_equal(nullptr, req2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  SettingRequest_equal(req, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  SettingRequest_not_equal(nullptr, req2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  SettingRequest_not_equal(req, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(SettingRequestTest, Copy) {
  auto copy = SettingRequest_copy(req);

  EXPECT_TRUE(SettingRequest_equal(req, copy));

  SettingRequest_destroy(copy);

  set_last_error(0, nullptr);
  SettingRequest_copy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(SettingRequestTest, ToJsonFromJson) {
  auto json = SettingRequest_to_json_string(req);

  auto copy = SettingRequest_from_json_string(json);

  EXPECT_TRUE(SettingRequest_equal(req, copy));

  SettingRequest_destroy(copy);
  String_destroy(json);

  set_last_error(0, nullptr);
  SettingRequest_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  SettingRequest_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
