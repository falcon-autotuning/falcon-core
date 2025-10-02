#include <falcon_core/communications/voltage_states/DeviceVoltageState.hpp>
#include <stdexcept>

namespace falcon_core::communications::voltage_states {

DeviceVoltageState::DeviceVoltageState(
    const physics::device_structures::ConnectionSP& connection,
    const double&                                   voltage,
    const physics::units::SymbolUnitSP&             unit)
    : math::Quantity(voltage, unit), _connection(connection) {
  if (!connection) {
    throw std::invalid_argument(
        "DeviceVoltageState: The connection must not be null.");
  }
}

DeviceVoltageState::DeviceVoltageState()
    : math::Quantity(), _connection(nullptr) {}

const physics::device_structures::ConnectionSP& DeviceVoltageState::connection()
    const {
  return _connection;
}

double DeviceVoltageState::voltage() const { return value(); }
bool   DeviceVoltageState::operator==(const DeviceVoltageState& other) const {
  return (*connection() == *other.connection()) &&
         math::Quantity::operator==(other);
}

bool DeviceVoltageState::operator!=(const DeviceVoltageState& other) const {
  return !(*this == other);
}
}  // namespace falcon_core::communications::voltage_states

CEREAL_REGISTER_TYPE(
    falcon_core::communications::voltage_states::DeviceVoltageState)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::Quantity,
    falcon_core::communications::voltage_states::DeviceVoltageState)
