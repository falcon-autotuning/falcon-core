#include "falcon_core/physics/device_structures/Impedances.hpp"

using namespace falcon_core::physics::device_structures;

Impedances::Impedances() = default;

Impedances::Impedances(size_t count) : List<Impedance, Impedances>(count) {}

Impedances::Impedances(size_t count, const ImpedanceSP& value)
    : List<Impedance, Impedances>(count, value) {}

Impedances::Impedances(const std::vector<ImpedanceSP>& vec)
    : List<Impedance, Impedances>(vec) {}

// Explicit template instantiation for serialize
template <class Archive>
void Impedances::serialize(Archive& ar) {
  ar(cereal::base_class<List<Impedance, Impedances>>(this));
}

CEREAL_REGISTER_TYPE(Impedances)
using LII = falcon_core::generic::List<Impedance, Impedances>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(LII, Impedances)
