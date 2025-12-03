#include "falcon_core/autotuner_interfaces/contexts/BaseContext.hpp"

#include <stdexcept>

namespace falcon_core {
namespace autotuner_interfaces {
namespace contexts {
BaseContext::BaseContext(const BaseContext& other) {
  std::shared_lock<std::shared_timed_mutex> lock_instrument_type(
      other._mu_instrument_type, std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_connection(
      other._mu_connection, std::defer_lock);
  std::lock(lock_instrument_type, lock_connection);
  _connection      = other._connection;
  _instrument_type = other._instrument_type;
}
BaseContext BaseContext::operator=(const BaseContext& other) {
  if (this != &other) {
    std::shared_lock<std::shared_timed_mutex> lock_other_instrument_type(
        other._mu_instrument_type, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_other_connection(
        other._mu_connection, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_instrument_type(
        _mu_instrument_type, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_connection(_mu_connection,
                                                              std::defer_lock);
    std::lock(lock_instrument_type,
              lock_connection,
              lock_other_instrument_type,
              lock_other_connection);
    _connection      = other._connection;
    _instrument_type = other._instrument_type;
  }
  return *this;
}
BaseContext::BaseContext() = default;
BaseContext::BaseContext(
    const physics::device_structures::ConnectionSP& connection,
    const instrument_interfaces::names::Instrument& instrument_type)
    : _connection(connection), _instrument_type(instrument_type) {
  if (!connection) {
    throw std::invalid_argument(
        "BaseContext: The connection must not be null.");
  }
}
BaseContext::BaseContext(
    const instrument_interfaces::names::InstrumentPortSP& port) {
  if (!port) {
    throw std::invalid_argument("BaseContext: The port must not be null.");
  }
  _connection      = port->pseudo_name();
  _instrument_type = port->instrument_type();
}
const physics::device_structures::ConnectionSP BaseContext::connection() const {
  std::shared_lock<std::shared_timed_mutex> lock_c(_mu_connection);
  return _connection;
}
const instrument_interfaces::names::Instrument BaseContext::instrument_type()
    const {
  std::shared_lock<std::shared_timed_mutex> lock_it(_mu_instrument_type);
  return _instrument_type;
}
bool BaseContext::operator==(const BaseContext& other) const {
  return (*connection() == *other.connection()) &&
         (instrument_type() == other.instrument_type());
}
bool BaseContext::operator!=(const BaseContext& other) const {
  return !(*this == other);
}
}  // namespace contexts
}  // namespace autotuner_interfaces
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::autotuner_interfaces::contexts::BaseContext)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::contexts::BaseContext)
