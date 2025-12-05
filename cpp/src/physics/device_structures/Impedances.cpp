#include "falcon_core/physics/device_structures/Impedances.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

Impedances::Impedances() : generic::List<Impedance>() {}

Impedances::Impedances(const std::vector<ImpedanceSP>& vec)
    : List<Impedance>(vec) {}
bool Impedances::operator==(const Impedances& other) const {
  return static_cast<const List<Impedance>&>(*this) ==
         static_cast<const List<Impedance>&>(other);
}
bool Impedances::operator!=(const Impedances& other) const {
  return !(*this == other);
}
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::Impedances)
using LII = falcon_core::generic::List<
    falcon_core::physics::device_structures::Impedance>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    LII, falcon_core::physics::device_structures::Impedances)
