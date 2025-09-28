#include "falcon_core/physics/device_structures/Impedances.hpp"

namespace falcon_core::physics::device_structures {

Impedances::Impedances() = default;

Impedances::Impedances(const std::vector<ImpedanceSP>& vec)
    : List<Impedance, Impedances>(vec) {}
}  // namespace falcon_core::physics::device_structures
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::Impedances)
using LII = falcon_core::generic::List<
    falcon_core::physics::device_structures::Impedance,
    falcon_core::physics::device_structures::Impedances>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    LII, falcon_core::physics::device_structures::Impedances)
