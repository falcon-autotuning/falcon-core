#include <falcon_core/communications/voltage_states/DeviceVoltageState.hpp>

namespace falcon_core::communications::voltage_states {

DeviceVoltageState::DeviceVoltageState(
    physics::device_structures::BaseConnectionSP connection,
    double                                       voltage,
    physics::units::SymbolUnitSP                 unit)
    : math::Quantity(voltage, unit), _connection(std::move(connection)) {}

DeviceVoltageState::DeviceVoltageState() = default;

std::shared_ptr<physics::device_structures::BaseConnection>
DeviceVoltageState::connection() const {
  return _connection;
}

double DeviceVoltageState::voltage() const { return value(); }

}  // namespace falcon_core::communications::voltage_states

CEREAL_REGISTER_TYPE(
    falcon_core::communications::voltage_states::DeviceVoltageState)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::Quantity,
    falcon_core::communications::voltage_states::DeviceVoltageState)
