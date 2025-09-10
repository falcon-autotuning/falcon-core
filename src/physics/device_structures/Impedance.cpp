#include "falcon_core/physics/device_structures/Impedance.hpp"

namespace falcon_core::physics::device_structures {

Impedance::Impedance(std::shared_ptr<BaseConnection> connection,
                     double                          resistance,
                     double                          capacitance)
    : _connection(std::move(connection)),
      _resistance(resistance),
      _capacitance(capacitance) {}

Impedance::Impedance() = default;
BaseConnectionSP Impedance::connection() const { return _connection; }
double           Impedance::resistance() const { return _resistance; }
double           Impedance::capacitance() const { return _capacitance; }
}  // namespace falcon_core::physics::device_structures
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::Impedance)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::device_structures::Impedance)
