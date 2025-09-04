#include <falcon_core/communications/voltage_states/DeviceVoltageStates.hpp>

namespace falcon_core {
namespace communications {
namespace voltage_states {

DeviceVoltageStates::DeviceVoltageStates() = default;

DeviceVoltageStates::DeviceVoltageStates(const container_type& states)
    : _states(states) {}

const DeviceVoltageStates::container_type& DeviceVoltageStates::states() const {
  return _states;
}

void DeviceVoltageStates::add_state(const std::shared_ptr<value_type>& state) {
  _states.push_back(state);
}

std::shared_ptr<DeviceVoltageStates::value_type> DeviceVoltageStates::find_state(
    const std::shared_ptr<physics::device_structures::BaseConnection>& connection) const {
  for (const auto& state : _states) {
    if (state->connection()->name() == connection->name() &&
        state->connection()->type() == connection->type()) {
      return state;
    }
  }
  return nullptr;
}

template <class Archive>
void DeviceVoltageStates::serialize(Archive& ar) {
  ar(cereal::base_class<generic::Song>(this), _states);
}

// Explicit template instantiation for cereal
template void DeviceVoltageStates::serialize<cereal::JSONOutputArchive>(cereal::JSONOutputArchive& ar);
template void DeviceVoltageStates::serialize<cereal::JSONInputArchive>(cereal::JSONInputArchive& ar);

}  // namespace voltage_states
}  // namespace communications
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::communications::voltage_states::DeviceVoltageStates)
