#include "falcon_core/physics/device_structures/Impedance.hpp"

#include <mutex>

namespace falcon_core {
namespace physics {
namespace device_structures {

Impedance::Impedance(ConnectionSP connection,
                     double       resistance,
                     double       capacitance)
    : _connection(connection),
      _resistance(resistance),
      _capacitance(capacitance) {
  if (!connection) {
    throw std::invalid_argument("Impedance: connection cannot be nullptr");
  }
}
Impedance::Impedance(const Impedance& other) {
  std::shared_lock<std::shared_timed_mutex> lock_connection(_mu_connection,
                                                            std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_resistance(_mu_resistance,
                                                            std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_capacitance(_mu_capacitance,
                                                             std::defer_lock);
  std::lock(lock_connection, lock_resistance, lock_capacitance);
  if (!other.connection()) {
    throw std::invalid_argument(
        "Impedance copy constructor: other.connection() cannot be nullptr");
  }
  _connection  = std::make_shared<Connection>(*other.connection());
  _resistance  = other.resistance();
  _capacitance = other.capacitance();
}
Impedance& Impedance::operator=(const Impedance& other) {
  if (this != &other) {
    std::shared_lock<std::shared_timed_mutex> lock_connection(_mu_connection,
                                                              std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_resistance(_mu_resistance,
                                                              std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_capacitance(_mu_capacitance,
                                                               std::defer_lock);
    std::lock(lock_connection, lock_resistance, lock_capacitance);
    if (!other.connection()) {
      throw std::invalid_argument(
          "Impedance assignment operator: other.connection() cannot be "
          "nullptr");
    }
    _connection  = std::make_shared<Connection>(*other.connection());
    _resistance  = other.resistance();
    _capacitance = other.capacitance();
  }
  return *this;
}

Impedance::Impedance() = default;
ImpedanceSP Impedance::create(const ConnectionSP connection,
                              const double       resistance,
                              double             capacitance) {
  return std::make_shared<Impedance>(connection, resistance, capacitance);
}
ConnectionSP Impedance::connection() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_connection);
  return _connection;
}
double Impedance::resistance() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_resistance);
  return _resistance;
}
double Impedance::capacitance() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_capacitance);
  return _capacitance;
}
bool Impedance::operator==(const Impedance& other) const {
  if (this == &other) return true;
  return (*connection() == *other.connection()) &&
         (resistance() == other.resistance()) &&
         (capacitance() == other.capacitance());
}
bool Impedance::operator!=(const Impedance& other) const {
  return !(*this == other);
}
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::Impedance)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::device_structures::Impedance)
