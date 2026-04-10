#include "falcon-core/physics/device_structures/Impedances.hpp"

namespace falcon_core {
namespace generic {
template class List<physics::device_structures::Impedance>;
}
namespace physics {
namespace device_structures {

Impedances::Impedances() : generic::List<Impedance>() {}

Impedances::Impedances(const std::vector<ImpedanceSP>& vec)
    : List<Impedance>(vec) {}
bool Impedances::operator==(const Impedances& other) const {
  if (this == &other) return true;
  return static_cast<const List<Impedance>&>(*this) ==
         static_cast<const List<Impedance>&>(other);
}
bool Impedances::operator!=(const Impedances& other) const {
  return !(*this == other);
}
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
