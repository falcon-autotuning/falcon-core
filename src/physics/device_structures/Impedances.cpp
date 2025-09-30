#include "falcon_core/physics/device_structures/Impedances.hpp"

namespace falcon_core::physics::device_structures {

Impedances::Impedances() = default;

Impedances::Impedances(const std::vector<ImpedanceSP>& vec)
    : List<Impedance>(vec) {}
bool Impedances::operator==(const Impedances& other) const {
  if (size() != other.size()) {
    return false;
  }
  for (size_t i = 0; i < size(); i++) {
    const ImpedanceSP our_conn   = this->at(i);
    const ImpedanceSP other_conn = other.at(i);
    if (*our_conn != *other_conn) {
      return false;
    }
  }
  return true;
}
bool Impedances::operator!=(const Impedances& other) const {
  return !(*this == other);
}
}  // namespace falcon_core::physics::device_structures
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::Impedances)
using LII = falcon_core::generic::List<
    falcon_core::physics::device_structures::Impedance>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    LII, falcon_core::physics::device_structures::Impedances)
