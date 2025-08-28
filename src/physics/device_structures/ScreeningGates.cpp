#include "falcon_core/physics/device_structures/ScreeningGates.hpp"
using namespace falcon_core::physics::device_structures;

ScreeningGates::ScreeningGates() = default;

ScreeningGates::ScreeningGates(size_t count)
    : Gates<ScreeningGate, ScreeningGates>(count) {}

ScreeningGates::ScreeningGates(size_t count, const ScreeningGateSP& value)
    : Gates<ScreeningGate, ScreeningGates>(count, value) {}

ScreeningGates::ScreeningGates(const std::vector<ScreeningGateSP>& vec)
    : Gates<ScreeningGate, ScreeningGates>(vec) {}

// Explicit template instantiation for serialize
template <class Archive>
void ScreeningGates::serialize(Archive& ar) {
  ar(cereal::base_class<Gates<ScreeningGate, ScreeningGates>>(this));
}

CEREAL_REGISTER_TYPE(ScreeningGates)
using GSS = Gates<ScreeningGate, ScreeningGates>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(GSS, ScreeningGates)
