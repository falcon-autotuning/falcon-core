#include <falcon-core/communications/voltage_states/DeviceVoltageState.hpp>
#include <stdexcept>

namespace falcon_core {
namespace communications {
namespace voltage_states {
DeviceVoltageState::DeviceVoltageState(const DeviceVoltageState& other)
    : math::Quantity(other) {
  std::unique_lock<std::shared_timed_mutex> lock_c(_mu_connection);
  if (!other._connection) {
    throw std::invalid_argument(
        "DeviceVoltageState copy constructor: Other DeviceVoltageState "
        "contains null shared pointer.");
  }
  _connection = std::make_shared<physics::device_structures::Connection>(
      *other._connection);
}
DeviceVoltageState& DeviceVoltageState::operator=(
    const DeviceVoltageState& other) {
  if (this != &other) {
    math::Quantity::operator=(other);
    std::unique_lock<std::shared_timed_mutex> lock_c(_mu_connection);
    if (!other._connection) {
      throw std::invalid_argument(
          "DeviceVoltageState copy constructor: Other DeviceVoltageState "
          "contains null shared pointer.");
    }
    _connection = std::make_shared<physics::device_structures::Connection>(
        *other._connection);
  }
  return *this;
}
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
  std::shared_lock<std::shared_timed_mutex> lock_c(_mu_connection);
  return _connection;
}

double DeviceVoltageState::voltage() const { return value(); }
bool   DeviceVoltageState::operator==(const DeviceVoltageState& other) const {
  if (this == &other) return true;
  return (*connection() == *other.connection()) &&
         math::Quantity::operator==(other);
}

bool DeviceVoltageState::operator!=(const DeviceVoltageState& other) const {
  return !(*this == other);
}
}  // namespace voltage_states
}  // namespace communications
}  // namespace falcon_core
