#include <falcon_core/communications/voltage_states/DeviceVoltageStates.hpp>

#include "falcon_core/communications/voltage_states/DeviceVoltageState.hpp"

namespace falcon_core::communications::voltage_states {

DeviceVoltageStates::DeviceVoltageStates()
    : generic::List<DeviceVoltageState>() {}

DeviceVoltageStates::DeviceVoltageStates(
    const generic::ListSP<DeviceVoltageState>& states)
    : generic::List<DeviceVoltageState>(*states) {}

const generic::ListSP<DeviceVoltageState> DeviceVoltageStates::states() const {
  return std::make_shared<List<DeviceVoltageState>>(items());
}

void DeviceVoltageStates::add_state(const DeviceVoltageStateSP& state) {
  push_back(state);
}

const DeviceVoltageStateSP DeviceVoltageStates::find_state(
    const physics::device_structures::BaseConnectionSP& connection) const {
  for (const auto& state : items()) {
    if (state->connection()->name() == connection->name() &&
        state->connection()->type() == connection->type()) {
      return state;
    }
  }
  return nullptr;
}

const math::PointSP DeviceVoltageStates::to_point() const {
  generic::MapSP<physics::device_structures::BaseConnection, math::Quantity>
      rawPoint;
  for (const DeviceVoltageStateSP& state : *states()) {
    rawPoint->insert(state->connection(), state);
  }
  return std::make_shared<math::Point>(rawPoint);
}

}  // namespace falcon_core::communications::voltage_states

CEREAL_REGISTER_TYPE(
    falcon_core::communications::voltage_states::DeviceVoltageStates)
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<
        falcon_core::communications::voltage_states::DeviceVoltageState>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<
        falcon_core::communications::voltage_states::DeviceVoltageState>,
    falcon_core::communications::voltage_states::DeviceVoltageStates)
