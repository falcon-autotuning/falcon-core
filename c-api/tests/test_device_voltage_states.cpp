#include <gtest/gtest.h>

#include "falcon_core/communications/voltage_states/DeviceVoltageState_c_api.h"
#include "falcon_core/communications/voltage_states/DeviceVoltageStates_c_api.h"
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
  EXPECT_THROW(DeviceVoltageStates_destroy(nullptr), std::invalid_argument);
}

TEST_F(DeviceVoltageStatesTest, StatesAddFind) {
  auto list = DeviceVoltageStates_states(states);
  EXPECT_EQ(ListDeviceVoltageState_size(list), 1);
  ListDeviceVoltageState_destroy(list);

  DeviceVoltageStates_add_state(states, dvs2);
  EXPECT_THROW(DeviceVoltageStates_add_state(nullptr, dvs),
               std::invalid_argument);
  EXPECT_THROW(DeviceVoltageStates_add_state(states, nullptr),
               std::invalid_argument);

  auto found = DeviceVoltageStates_find_state(states, conn);
  EXPECT_NE(found, nullptr);
  DeviceVoltageState_destroy(found);
  EXPECT_THROW(DeviceVoltageStates_find_state(nullptr, conn),
               std::invalid_argument);
  EXPECT_THROW(DeviceVoltageStates_find_state(states, nullptr),
               std::invalid_argument);
}

TEST_F(DeviceVoltageStatesTest, ToPointIntersection) {
  auto pt = DeviceVoltageStates_to_point(states);
  Point_destroy(pt);

  auto s2    = DeviceVoltageStates_create_empty();
  auto inter = DeviceVoltageStates_intersection(states, s2);
  DeviceVoltageStates_destroy(inter);
  DeviceVoltageStates_destroy(s2);

  EXPECT_THROW(DeviceVoltageStates_to_point(nullptr), std::invalid_argument);
  EXPECT_THROW(DeviceVoltageStates_intersection(nullptr, states),
               std::invalid_argument);
  EXPECT_THROW(DeviceVoltageStates_intersection(states, nullptr),
               std::invalid_argument);
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

  EXPECT_THROW(DeviceVoltageStates_push_back(nullptr, dvs),
               std::invalid_argument);
  EXPECT_THROW(DeviceVoltageStates_push_back(states, nullptr),
               std::invalid_argument);
  EXPECT_THROW(DeviceVoltageStates_size(nullptr), std::invalid_argument);
  EXPECT_THROW(DeviceVoltageStates_empty(nullptr), std::invalid_argument);
  EXPECT_THROW(DeviceVoltageStates_erase_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(DeviceVoltageStates_clear(nullptr), std::invalid_argument);
}

TEST_F(DeviceVoltageStatesTest, AtConstAtItems) {
  auto at  = DeviceVoltageStates_at(states, 0);
  auto cat = DeviceVoltageStates_const_at(states, 0);
  EXPECT_NE(at, nullptr);
  EXPECT_NE(cat, nullptr);
  DeviceVoltageState_destroy(at);
  auto items = DeviceVoltageStates_items(states);
  EXPECT_EQ(ListDeviceVoltageState_size(items), 1);
  ListDeviceVoltageState_destroy(items);

  EXPECT_THROW(DeviceVoltageStates_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(DeviceVoltageStates_const_at(nullptr, 0), std::invalid_argument);
  EXPECT_THROW(DeviceVoltageStates_items(nullptr), std::invalid_argument);
}

TEST_F(DeviceVoltageStatesTest, ContainsIndex) {
  EXPECT_TRUE(DeviceVoltageStates_contains(states, dvs));
  EXPECT_EQ(DeviceVoltageStates_index(states, dvs), 0);
  EXPECT_THROW(DeviceVoltageStates_contains(nullptr, dvs),
               std::invalid_argument);
  EXPECT_THROW(DeviceVoltageStates_contains(states, nullptr),
               std::invalid_argument);
  EXPECT_THROW(DeviceVoltageStates_index(nullptr, dvs), std::invalid_argument);
  EXPECT_THROW(DeviceVoltageStates_index(states, nullptr),
               std::invalid_argument);
}

TEST_F(DeviceVoltageStatesTest, Equality) {
  auto s2 = DeviceVoltageStates_create_empty();
  EXPECT_FALSE(DeviceVoltageStates_equal(states, s2));
  EXPECT_TRUE(DeviceVoltageStates_not_equal(states, s2));
  DeviceVoltageStates_destroy(s2);
  EXPECT_THROW(DeviceVoltageStates_equal(nullptr, states),
               std::invalid_argument);
  EXPECT_THROW(DeviceVoltageStates_equal(states, nullptr),
               std::invalid_argument);
  EXPECT_THROW(DeviceVoltageStates_not_equal(nullptr, states),
               std::invalid_argument);
  EXPECT_THROW(DeviceVoltageStates_not_equal(states, nullptr),
               std::invalid_argument);
}

TEST_F(DeviceVoltageStatesTest, ToJsonFromJson) {
  auto json = DeviceVoltageStates_to_json_string(states);
  auto s2   = DeviceVoltageStates_from_json_string(json);
  EXPECT_TRUE(DeviceVoltageStates_equal(states, s2));
  DeviceVoltageStates_destroy(s2);
  String_destroy(json);
  EXPECT_THROW(DeviceVoltageStates_to_json_string(nullptr),
               std::invalid_argument);
  EXPECT_THROW(DeviceVoltageStates_from_json_string(nullptr),
               std::invalid_argument);
}

TEST_F(DeviceVoltageStatesTest, StatesNull) {
  EXPECT_THROW(DeviceVoltageStates_states(nullptr), std::invalid_argument);
}
