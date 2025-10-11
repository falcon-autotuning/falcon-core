#include "falcon_core/physics/device_structures/Impedance.hpp"

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

Impedance::Impedance() = default;
ImpedanceSP Impedance::create(const ConnectionSP connection,
                              const double       resistance,
                              double             capacitance) {
  return std::make_shared<Impedance>(connection, resistance, capacitance);
}
ConnectionSP Impedance::connection() const { return _connection; }
double       Impedance::resistance() const { return _resistance; }
double       Impedance::capacitance() const { return _capacitance; }
bool         Impedance::operator==(const Impedance& other) const {
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
