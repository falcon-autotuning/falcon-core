#include <gtest/gtest.h>

#include <falcon_core/communications/voltage_states/DeviceVoltageState.hpp>
#include <falcon_core/communications/voltage_states/DeviceVoltageStates.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>
#include <falcon_core/physics/units/SymbolUnit.hpp>
#include <memory>
#include <string>

namespace tests {
using namespace falcon_core::communications::voltage_states;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::physics::units;

// Basic construction and access test
TEST(DeviceVoltageStatesTest, BasicConstructionAndAccess) {
  SymbolUnitSP         unit = SymbolUnit::Volt();
  ConnectionSP         conn = Connection::BarrierGate("gate1");
  DeviceVoltageStateSP dvs =
      std::make_shared<DeviceVoltageState>(conn, 1.23, unit);

  ASSERT_EQ(dvs->connection()->name(), "gate1");
  ASSERT_EQ(dvs->voltage(), 1.23);

  DeviceVoltageStates states;
  states.add_state(dvs);

  ASSERT_EQ(states.states()->size(), 1);
  auto found = states.find_state(conn);
  ASSERT_TRUE(found != nullptr);
  ASSERT_EQ(found->voltage(), 1.23);
}

// Serialization round-trip test
TEST(DeviceVoltageStatesTest, SerializationRoundTrip) {
  SymbolUnitSP         unit = SymbolUnit::Volt();
  ConnectionSP         conn = Connection::PlungerGate("gate2");
  DeviceVoltageStateSP dvs =
      std::make_shared<DeviceVoltageState>(conn, 4.56, unit);

  auto states = std::make_shared<DeviceVoltageStates>();
  states->add_state(dvs);

  std::string json = states->to_json_string();
  auto        loaded =
      DeviceVoltageStates::from_json_string<DeviceVoltageStates>(json);

  ASSERT_EQ(loaded->states()->size(), 1);
  auto found = loaded->find_state(conn);
  ASSERT_TRUE(found != nullptr);
  ASSERT_EQ(found->voltage(), 4.56);
  ASSERT_EQ(found->connection()->name(), "gate2");
}

}  // namespace tests
