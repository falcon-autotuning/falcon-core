#include <falcon-core/communications/voltage_states/DeviceVoltageStates.hpp>
#include <stdexcept>

#include "falcon-core/communications/voltage_states/DeviceVoltageState.hpp"
#include "falcon-core/math/Quantity.hpp"
#include "falcon-core/physics/device_structures/Connection.hpp"

namespace falcon_core {
namespace generic {
template class List<communications::voltage_states::DeviceVoltageState>;
}
namespace communications {
namespace voltage_states {

static const generic::List<DeviceVoltageState>& dvs_check_and_deref(
    const generic::ListSP<DeviceVoltageState>& states) {
  if (!states)
    throw std::invalid_argument(
        "DeviceVoltageStates: states must not be null.");
  return *states;
}
DeviceVoltageStates::DeviceVoltageStates()
    : generic::List<DeviceVoltageState>() {}

DeviceVoltageStates::DeviceVoltageStates(
    const generic::ListSP<DeviceVoltageState>& states)
    : generic::List<DeviceVoltageState>(dvs_check_and_deref(states)) {}

const generic::ListSP<DeviceVoltageState> DeviceVoltageStates::states() const {
  return std::make_shared<List<DeviceVoltageState>>(items());
}

void DeviceVoltageStates::add_state(const DeviceVoltageStateSP& state) {
  if (!state) {
    throw std::invalid_argument(
        "DeviceVoltageState: The state to add must not be null.");
  }
  push_back(state);
}

const DeviceVoltageStateSP DeviceVoltageStates::find_state(
    const physics::device_structures::ConnectionSP& connection) const {
  if (!connection) {
    throw std::invalid_argument(
        "DeviceVoltageState: The connection to find must not be null.");
  }
  for (const auto& state : items()) {
    if (state->connection()->name() == connection->name() &&
        state->connection()->type() == connection->type()) {
      return state;
    }
  }
  return nullptr;
}

const math::PointSP DeviceVoltageStates::to_point() const {
  generic::MapSP<physics::device_structures::Connection, math::Quantity>
      rawPoint =
          std::make_shared<generic::Map<physics::device_structures::Connection,
                                        math::Quantity>>();
  auto all_the_states = *states();
  for (const DeviceVoltageStateSP& state : all_the_states) {
    rawPoint->insert(state->connection(), state);
  }
  return std::make_shared<math::Point>(rawPoint);
}

}  // namespace voltage_states
}  // namespace communications
}  // namespace falcon_core
