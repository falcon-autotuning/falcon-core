#include <gtest/gtest.h>

#include "falcon_core/communications/voltage_states/DeviceVoltageState_c_api.h"
#include "falcon_core/communications/voltage_states/DeviceVoltageStates_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

class DeviceVoltageStatesTest : public ::testing::Test {
 protected:
  void SetUp() override {
    conn = Connection_create_plunger_gate(String_wrap("A"));
    unit = SymbolUnit_create_volt();
    dvs  = DeviceVoltageState_create(conn, 1.0, unit);
    dvs2 = DeviceVoltageState_create(conn, 2.0, unit);

    dvs_list = ListDeviceVoltageState_create_empty();
    ListDeviceVoltageState_push_back(dvs_list, dvs);

    states = DeviceVoltageStates_create_empty();
    DeviceVoltageStates_add_state(states, dvs);
  }
  void TearDown() override {
    DeviceVoltageStates_destroy(states);
    ListDeviceVoltageState_destroy(dvs_list);
    DeviceVoltageState_destroy(dvs);
    DeviceVoltageState_destroy(dvs2);
    Connection_destroy(conn);
    SymbolUnit_destroy(unit);
  }
  ConnectionHandle             conn;
  SymbolUnitHandle             unit;
  DeviceVoltageStateHandle     dvs;
  DeviceVoltageStateHandle     dvs2;
  ListDeviceVoltageStateHandle dvs_list;
  DeviceVoltageStatesHandle    states;
};

TEST_F(DeviceVoltageStatesTest, CreateDestroy) {
  auto s = DeviceVoltageStates_create_empty();
  DeviceVoltageStates_destroy(s);
  auto s2 = DeviceVoltageStates_create(dvs_list);
  DeviceVoltageStates_destroy(s2);
  set_last_error(0, nullptr);
  DeviceVoltageStates_destroy(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DeviceVoltageStatesTest, StatesAddFind) {
  auto list = DeviceVoltageStates_states(states);
  EXPECT_EQ(ListDeviceVoltageState_size(list), 1);
  ListDeviceVoltageState_destroy(list);

  DeviceVoltageStates_add_state(states, dvs2);
  set_last_error(0, nullptr);
  DeviceVoltageStates_add_state(nullptr, dvs);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageStates_add_state(states, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);

  auto found = DeviceVoltageStates_find_state(states, conn);
  EXPECT_NE(found, nullptr);
  DeviceVoltageState_destroy(found);
  set_last_error(0, nullptr);
  DeviceVoltageStates_find_state(nullptr, conn);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageStates_find_state(states, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DeviceVoltageStatesTest, ToPointIntersection) {
  auto pt = DeviceVoltageStates_to_point(states);
  Point_destroy(pt);

  auto s2    = DeviceVoltageStates_create_empty();
  auto inter = DeviceVoltageStates_intersection(states, s2);
  DeviceVoltageStates_destroy(inter);
  DeviceVoltageStates_destroy(s2);

  set_last_error(0, nullptr);
  DeviceVoltageStates_to_point(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageStates_intersection(nullptr, states);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageStates_intersection(states, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DeviceVoltageStatesTest, PushBackSizeEmptyEraseClear) {
  auto s = DeviceVoltageStates_create_empty();
  DeviceVoltageStates_push_back(s, dvs);
  EXPECT_EQ(DeviceVoltageStates_size(s), 1);
  EXPECT_FALSE(DeviceVoltageStates_empty(s));
  DeviceVoltageStates_erase_at(s, 0);
  EXPECT_TRUE(DeviceVoltageStates_empty(s));
  DeviceVoltageStates_push_back(s, dvs);
  DeviceVoltageStates_clear(s);
  EXPECT_TRUE(DeviceVoltageStates_empty(s));
  DeviceVoltageStates_destroy(s);

  set_last_error(0, nullptr);
  DeviceVoltageStates_push_back(nullptr, dvs);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageStates_push_back(states, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageStates_size(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageStates_empty(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageStates_erase_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageStates_clear(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DeviceVoltageStatesTest, AtItems) {
  auto at = DeviceVoltageStates_at(states, 0);
  EXPECT_NE(at, nullptr);
  DeviceVoltageState_destroy(at);
  auto items = DeviceVoltageStates_items(states);
  EXPECT_EQ(ListDeviceVoltageState_size(items), 1);
  ListDeviceVoltageState_destroy(items);

  set_last_error(0, nullptr);
  DeviceVoltageStates_at(nullptr, 0);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageStates_items(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DeviceVoltageStatesTest, ContainsIndex) {
  EXPECT_TRUE(DeviceVoltageStates_contains(states, dvs));
  EXPECT_EQ(DeviceVoltageStates_index(states, dvs), 0);
  set_last_error(0, nullptr);
  DeviceVoltageStates_contains(nullptr, dvs);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageStates_contains(states, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageStates_index(nullptr, dvs);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageStates_index(states, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DeviceVoltageStatesTest, Equality) {
  auto s2 = DeviceVoltageStates_create_empty();
  EXPECT_FALSE(DeviceVoltageStates_equal(states, s2));
  EXPECT_TRUE(DeviceVoltageStates_not_equal(states, s2));
  DeviceVoltageStates_destroy(s2);
  set_last_error(0, nullptr);
  DeviceVoltageStates_equal(nullptr, states);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageStates_equal(states, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageStates_not_equal(nullptr, states);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageStates_not_equal(states, nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DeviceVoltageStatesTest, ToJsonFromJson) {
  auto json = DeviceVoltageStates_to_json_string(states);
  auto s2   = DeviceVoltageStates_from_json_string(json);
  EXPECT_TRUE(DeviceVoltageStates_equal(states, s2));
  DeviceVoltageStates_destroy(s2);
  String_destroy(json);
  set_last_error(0, nullptr);
  DeviceVoltageStates_to_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
  set_last_error(0, nullptr);
  DeviceVoltageStates_from_json_string(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}

TEST_F(DeviceVoltageStatesTest, StatesNull) {
  set_last_error(0, nullptr);
  DeviceVoltageStates_states(nullptr);
  EXPECT_EQ(get_last_error_code(), 1);
}
