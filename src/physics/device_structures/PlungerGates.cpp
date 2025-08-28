#include "falcon_core/physics/device_structures/PlungerGates.hpp"
using namespace falcon_core::physics::device_structures;

PlungerGates::PlungerGates() = default;

PlungerGates::PlungerGates(size_t count)
    : DotGates<PlungerGate, PlungerGates>(count) {}

PlungerGates::PlungerGates(size_t count, const PlungerGateSP& value)
    : DotGates<PlungerGate, PlungerGates>(count, value) {}

PlungerGates::PlungerGates(const std::vector<PlungerGateSP>& vec)
    : DotGates<PlungerGate, PlungerGates>(vec) {}

// Explicit template instantiation for serialize
template <class Archive>
void PlungerGates::serialize(Archive& ar) {
  ar(cereal::base_class<DotGates<PlungerGate, PlungerGates>>(this));
}

CEREAL_REGISTER_TYPE(PlungerGates)
using DGPP = DotGates<PlungerGate, PlungerGates>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(DGPP, PlungerGates)
