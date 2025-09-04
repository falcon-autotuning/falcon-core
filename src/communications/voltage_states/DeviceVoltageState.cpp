#include <falcon_core/communications/voltage_states/DeviceVoltageState.hpp>

namespace falcon_core {
namespace communications {
namespace voltage_states {

DeviceVoltageState::DeviceVoltageState(
    std::shared_ptr<physics::device_structures::BaseConnection> connection,
    double voltage,
    std::shared_ptr<physics::units::SymbolUnit> unit)
    : math::Quantity(voltage, unit), _connection(std::move(connection)) {}

DeviceVoltageState::DeviceVoltageState() = default;

std::shared_ptr<physics::device_structures::BaseConnection> DeviceVoltageState::connection() const {
  return _connection;
}

double DeviceVoltageState::voltage() const {
  return value();
}

template <class Archive>
void DeviceVoltageState::serialize(Archive& ar) {
  ar(cereal::base_class<math::Quantity>(this),
     _connection);
}

// Explicit template instantiation for cereal
template void DeviceVoltageState::serialize<cereal::JSONOutputArchive>(cereal::JSONOutputArchive& ar);
template void DeviceVoltageState::serialize<cereal::JSONInputArchive>(cereal::JSONInputArchive& ar);

}  // namespace voltage_states
}  // namespace communications
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::communications::voltage_states::DeviceVoltageState)
