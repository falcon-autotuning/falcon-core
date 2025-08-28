#include "falcon_core/physics/device_structures/BarrierGates.hpp"
using namespace falcon_core::physics::device_structures;

BarrierGates::BarrierGates() = default;

BarrierGates::BarrierGates(size_t count)
    : DotGates<BarrierGate, BarrierGates>(count) {}

BarrierGates::BarrierGates(size_t count, const BarrierGateSP& value)
    : DotGates<BarrierGate, BarrierGates>(count, value) {}

BarrierGates::BarrierGates(const std::vector<BarrierGateSP>& vec)
    : DotGates<BarrierGate, BarrierGates>(vec) {}

// Explicit template instantiation for serialize
template <class Archive>
void BarrierGates::serialize(Archive& ar) {
  ar(cereal::base_class<DotGates<BarrierGate, BarrierGates>>(this));
}

CEREAL_REGISTER_TYPE(BarrierGates)
using DGBB = DotGates<BarrierGate, BarrierGates>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(DGBB, BarrierGates)
