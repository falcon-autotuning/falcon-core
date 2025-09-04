#include <cassert>
#include <cereal/archives/json.hpp>
#include <falcon_core/communications/voltage_states/DeviceVoltageState.hpp>
#include <falcon_core/communications/voltage_states/DeviceVoltageStates.hpp>
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/Quantity.hpp>
#include <falcon_core/physics/device_structures/BaseConnection.hpp>
#include <falcon_core/physics/units/CommonUnits.hpp>
#include <falcon_core/physics/units/SymbolUnit.hpp>
#include <iostream>
#include <sstream>

using namespace falcon_core::communications::voltage_states;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::physics::units;

void test_DeviceVoltageStates_basic() {
  // Create a SymbolUnit for volt
  auto unit = std::make_shared<SymbolUnit>(CommonUnits::Volt);
  // Create a BaseConnection
  auto conn =
      std::make_shared<BaseConnection>("gate1", DeviceFeature::BarrierGate);

  // Create a DeviceVoltageState
  auto dvs = std::make_shared<DeviceVoltageState>(conn, 1.23, unit);

  // Test getters
  assert(dvs->connection()->name() == "gate1");
  assert(dvs->voltage() == 1.23);

  // Create DeviceVoltageStates and add state
  DeviceVoltageStates states;
  states.add_state(dvs);

  // Test states() and find_state()
  assert(states.states().size() == 1);
  auto found = states.find_state(conn);
  assert(found != nullptr);
  assert(found->voltage() == 1.23);
}

void test_DeviceVoltageStates_SerializationRoundTrip() {
  auto unit = std::make_shared<SymbolUnit>(CommonUnits::Volt);
  auto conn =
      std::make_shared<BaseConnection>("gate2", DeviceFeature::PlungerGate);
  auto dvs = std::make_shared<DeviceVoltageState>(conn, 4.56, unit);

  DeviceVoltageStates states;
  states.add_state(dvs);

  // Serialize to JSON
  std::stringstream ss;
  {
    cereal::JSONOutputArchive oarchive(ss);
    oarchive(states);
  }

  // Deserialize from JSON
  DeviceVoltageStates loaded;
  {
    cereal::JSONInputArchive iarchive(ss);
    iarchive(loaded);
  }

  // Check round-trip
  assert(loaded.states().size() == 1);
  auto found = loaded.find_state(conn);
  assert(found != nullptr);
  assert(found->voltage() == 4.56);
  assert(found->connection()->name() == "gate2");
}

int main() {
  test_DeviceVoltageStates_basic();
  test_DeviceVoltageStates_SerializationRoundTrip();
  std::cout << "DeviceVoltageStates tests passed.\n";
  return 0;
}
