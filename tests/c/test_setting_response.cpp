#include <gtest/gtest.h>

#include "falcon-core/communications/messages/SettingResponse_c_api.h"
#include "falcon-core/generic/ErrorHandling_c_api.h"
#include "falcon-core/generic/MapInstrumentPortQuantity_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon-core/math/Quantity_c_api.h"
#include "falcon-core/physics/device_structures/Connection_c_api.h"
#include "falcon-core/physics/units/SymbolUnit_c_api.h"

class SettingResponseTest : public ::testing::Test {
protected:
  void SetUp() override {
    name = String_wrap("gate");
    instrument = String_wrap("dac");

    port = InstrumentPort_create_setting(
        name, instrument, SCOPE_LOCAL, ACCESS_READWRITE,
        INSTRUMENT_CHARACTERISTIC_NONE, Connection_create_plunger_gate(name),
        INSTRUMENT_DC_VOLTAGE_SOURCE, SymbolUnit_create_volt(),
        String_wrap(""));

    quantity = Quantity_create(1.23, SymbolUnit_create_volt());

    getters = MapInstrumentPortQuantity_create_empty();
    empty_getters = MapInstrumentPortQuantity_create_empty();

    MapInstrumentPortQuantity_insert(getters, port, quantity);

    resp = SettingResponse_create(String_wrap("message"), getters);

    resp2 = SettingResponse_create(String_wrap("other"), empty_getters);
  }

  void TearDown() override {
    SettingResponse_destroy(resp);
    SettingResponse_destroy(resp2);

    MapInstrumentPortQuantity_destroy(getters);
    MapInstrumentPortQuantity_destroy(empty_getters);

    Quantity_destroy(quantity);
    InstrumentPort_destroy(port);

    String_destroy(name);
    String_destroy(instrument);
  }

  StringHandle name = nullptr;
  StringHandle instrument = nullptr;

  InstrumentPortHandle port = nullptr;

  QuantityHandle quantity = nullptr;

  MapInstrumentPortQuantityHandle getters = nullptr;
  MapInstrumentPortQuantityHandle empty_getters = nullptr;

  SettingResponseHandle resp = nullptr;
  SettingResponseHandle resp2 = nullptr;
};

TEST_F(SettingResponseTest, CreateDestroy) {
  auto r = SettingResponse_create(String_wrap("msg"), getters);

  SettingResponse_destroy(r);

  set_last_error(0, nullptr);
  SettingResponse_create(nullptr, getters);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  SettingResponse_create(String_wrap("msg"), nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  SettingResponse_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(SettingResponseTest, Accessors) {
  auto g = SettingResponse_getters(resp);

  EXPECT_EQ(MapInstrumentPortQuantity_size(g), 1);

  MapInstrumentPortQuantity_destroy(g);

  set_last_error(0, nullptr);
  SettingResponse_getters(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(SettingResponseTest, Equality) {
  EXPECT_FALSE(SettingResponse_equal(resp, resp2));
  EXPECT_TRUE(SettingResponse_not_equal(resp, resp2));

  EXPECT_TRUE(SettingResponse_equal(resp, resp));
  EXPECT_FALSE(SettingResponse_not_equal(resp, resp));

  set_last_error(0, nullptr);
  SettingResponse_equal(nullptr, resp2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  SettingResponse_equal(resp, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  SettingResponse_not_equal(nullptr, resp2);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  SettingResponse_not_equal(resp, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(SettingResponseTest, Copy) {
  auto copy = SettingResponse_copy(resp);

  EXPECT_TRUE(SettingResponse_equal(resp, copy));

  SettingResponse_destroy(copy);

  set_last_error(0, nullptr);
  SettingResponse_copy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(SettingResponseTest, ToJsonFromJson) {
  auto json = SettingResponse_to_json_string(resp);

  auto r2 = SettingResponse_from_json_string(json);

  EXPECT_TRUE(SettingResponse_equal(resp, r2));

  SettingResponse_destroy(r2);
  String_destroy(json);

  set_last_error(0, nullptr);
  SettingResponse_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  set_last_error(0, nullptr);
  SettingResponse_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(SettingResponseTest, Messages) {
  EXPECT_NO_THROW({
    auto msg = SettingResponse_message(resp);
    String_destroy(msg);
  });

  set_last_error(0, nullptr);
  SettingResponse_message(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
