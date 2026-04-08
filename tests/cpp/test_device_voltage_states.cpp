#include <gtest/gtest.h>

#include <falcon-core/communications/voltage_states/DeviceVoltageState.hpp>
#include <falcon-core/communications/voltage_states/DeviceVoltageStates.hpp>
#include <falcon-core/math/Point.hpp>
#include <falcon-core/physics/device_structures/Connection.hpp>
#include <falcon-core/physics/units/SymbolUnit.hpp>
#include <stdexcept>
namespace {
using namespace falcon_core;
using namespace generic;
using namespace communications::voltage_states;
using namespace physics::device_structures;
using namespace physics::units;
using namespace math;

class DeviceVoltageStatesTest : public ::testing::Test {
 protected:
  ConnectionSP         connA = Connection::PlungerGate("A");
  ConnectionSP         connB = Connection::PlungerGate("B");
  SymbolUnitSP         volt  = SymbolUnit::Volt();
  DeviceVoltageStateSP dvsA;
  DeviceVoltageStateSP dvsB;
  void                 SetUp() override {
    dvsA = std::make_shared<DeviceVoltageState>(connA, 1.0, volt);
    dvsB = std::make_shared<DeviceVoltageState>(connB, 2.0, volt);
  }
};

TEST_F(DeviceVoltageStatesTest, DefaultConstructor) {
  DeviceVoltageStates dvs;
  EXPECT_EQ(dvs.size(), 0);
}

TEST_F(DeviceVoltageStatesTest, ListSPConstructorAndNullThrows) {
  auto list = std::make_shared<generic::List<DeviceVoltageState>>();
  list->push_back(dvsA);
  DeviceVoltageStates dvs(list);
  EXPECT_EQ(dvs.size(), 1);
  EXPECT_THROW(DeviceVoltageStates(nullptr), std::invalid_argument);
}

TEST_F(DeviceVoltageStatesTest, StatesGetter) {
  auto list = std::make_shared<generic::List<DeviceVoltageState>>();
  list->push_back(dvsA);
  DeviceVoltageStates dvs(list);
  auto                states = dvs.states();
  EXPECT_EQ(states->size(), 1);
  EXPECT_EQ(*states->at(0), *dvsA);
}

TEST_F(DeviceVoltageStatesTest, AddStateAndFindState) {
  DeviceVoltageStates dvs;
  dvs.add_state(dvsA);
  dvs.add_state(dvsB);
  EXPECT_EQ(dvs.size(), 2);
  EXPECT_EQ(dvs.find_state(connA), dvsA);
  EXPECT_EQ(dvs.find_state(connB), dvsB);
}

TEST_F(DeviceVoltageStatesTest, AddStateNullThrows) {
  DeviceVoltageStates dvs;
  EXPECT_THROW(dvs.add_state(nullptr), std::invalid_argument);
}

TEST_F(DeviceVoltageStatesTest, FindStateNotFoundReturnsNull) {
  DeviceVoltageStates dvs;
  dvs.add_state(dvsA);
  EXPECT_EQ(dvs.find_state(connB), nullptr);
}

TEST_F(DeviceVoltageStatesTest, ToPointConversion) {
  DeviceVoltageStates dvs;
  dvs.add_state(dvsA);
  dvs.add_state(dvsB);
  auto pt = dvs.to_point();
  EXPECT_EQ(pt->size(), 2);
  EXPECT_DOUBLE_EQ(pt->at(connA)->value(), 1.0);
  EXPECT_DOUBLE_EQ(pt->at(connB)->value(), 2.0);
}

TEST_F(DeviceVoltageStatesTest, SerializationRoundTrip) {
  auto list = std::make_shared<generic::List<DeviceVoltageState>>();
  list->push_back(dvsA);
  list->push_back(dvsB);
  DeviceVoltageStates dvs(list);
  auto                json = dvs.to_json_string();
  auto dvs2 = DeviceVoltageStates::from_json_string<DeviceVoltageStates>(json);
  EXPECT_EQ(dvs, *dvs2);
}

TEST_F(DeviceVoltageStatesTest, FindStateNullConnectionThrows) {
  DeviceVoltageStates dvs;
  EXPECT_THROW(dvs.find_state(nullptr), std::invalid_argument);
}
}  // namespace
