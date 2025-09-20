#include <falcon_core/communications/voltage_states/DeviceVoltageState.hpp>

namespace falcon_core::communications::voltage_states {

DeviceVoltageState::DeviceVoltageState(
    const physics::device_structures::ConnectionSP& connection,
    const double&                                   voltage,
    const physics::units::SymbolUnitSP&             unit)
    : math::Quantity(voltage, unit), _connection(std::move(connection)) {}

DeviceVoltageState::DeviceVoltageState()
    : math::Quantity(), _connection(nullptr) {}

std::shared_ptr<physics::device_structures::Connection>
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
