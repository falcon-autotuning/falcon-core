#include <gtest/gtest.h>

#include "falcon_core/communications/messages/VoltageStatesResponse_c_api.h"
#include "falcon_core/communications/voltage_states/DeviceVoltageStates_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class VoltageStatesResponseTest : public ::testing::Test {
 protected:
  void SetUp() override {
    conn     = Connection_create_barrier_gate(String_wrap("A"));
    unit     = SymbolUnit_create_volt();
    dvs      = DeviceVoltageState_create(conn, 1.0, unit);
    dvs2     = DeviceVoltageState_create(conn, 2.0, unit);
    dvs_list = DeviceVoltageStates_create_empty();
    DeviceVoltageStates_push_back(dvs_list, dvs);
    DeviceVoltageStates_push_back(dvs_list, dvs2);
    msg   = String_wrap("voltage states response");
    resp  = VoltageStatesResponse_create(msg, dvs_list);
    resp2 = VoltageStatesResponse_create(String_wrap("other"), dvs_list);
  }
  void TearDown() override {
    VoltageStatesResponse_destroy(resp);
    VoltageStatesResponse_destroy(resp2);
    DeviceVoltageState_destroy(dvs);
    DeviceVoltageState_destroy(dvs2);
    DeviceVoltageStates_destroy(dvs_list);
    Connection_destroy(conn);
    SymbolUnit_destroy(unit);
    String_destroy(msg);
  }
  ConnectionHandle            conn     = nullptr;
  SymbolUnitHandle            unit     = nullptr;
  DeviceVoltageStateHandle    dvs      = nullptr;
  DeviceVoltageStateHandle    dvs2     = nullptr;
  DeviceVoltageStatesHandle   dvs_list = nullptr;
  StringHandle                msg      = nullptr;
  VoltageStatesResponseHandle resp     = nullptr;
  VoltageStatesResponseHandle resp2    = nullptr;
};

TEST_F(VoltageStatesResponseTest, CreateDestroy) {
  auto r = VoltageStatesResponse_create(String_wrap("test"), dvs_list);
  VoltageStatesResponse_destroy(r);
  EXPECT_THROW(VoltageStatesResponse_create(nullptr, dvs_list),
               std::invalid_argument);
  EXPECT_THROW(VoltageStatesResponse_create(msg, nullptr),
               std::invalid_argument);
  EXPECT_THROW(VoltageStatesResponse_destroy(nullptr), std::invalid_argument);
}

TEST_F(VoltageStatesResponseTest, Accessors) {
  auto m = VoltageStatesResponse_message(resp);
  EXPECT_STREQ(m->raw, "voltage states response");
  String_destroy(m);

  auto states = VoltageStatesResponse_states(resp);
  EXPECT_EQ(DeviceVoltageStates_size(states), 2);
  DeviceVoltageStates_destroy(states);

  EXPECT_THROW(VoltageStatesResponse_message(nullptr), std::invalid_argument);
  EXPECT_THROW(VoltageStatesResponse_states(nullptr), std::invalid_argument);
}

TEST_F(VoltageStatesResponseTest, Equality) {
  EXPECT_FALSE(VoltageStatesResponse_equal(resp, resp2));
  EXPECT_TRUE(VoltageStatesResponse_not_equal(resp, resp2));
  EXPECT_TRUE(VoltageStatesResponse_equal(resp, resp));
  EXPECT_FALSE(VoltageStatesResponse_not_equal(resp, resp));

  EXPECT_THROW(VoltageStatesResponse_equal(nullptr, resp2),
               std::invalid_argument);
  EXPECT_THROW(VoltageStatesResponse_equal(resp, nullptr),
               std::invalid_argument);
  EXPECT_THROW(VoltageStatesResponse_not_equal(nullptr, resp2),
               std::invalid_argument);
  EXPECT_THROW(VoltageStatesResponse_not_equal(resp, nullptr),
               std::invalid_argument);
}

TEST_F(VoltageStatesResponseTest, ToJsonFromJson) {
  auto json = VoltageStatesResponse_to_json_string(resp);
  auto r2   = VoltageStatesResponse_from_json_string(json);
  EXPECT_TRUE(VoltageStatesResponse_equal(resp, r2));
  VoltageStatesResponse_destroy(r2);
  String_destroy(json);

  EXPECT_THROW(VoltageStatesResponse_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(VoltageStatesResponse_from_json_string(nullptr),
               std::invalid_argument);
}
