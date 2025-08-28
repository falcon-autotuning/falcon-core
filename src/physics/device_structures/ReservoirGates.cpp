#include "falcon_core/physics/device_structures/ReservoirGates.hpp"
using namespace falcon_core::physics::device_structures;

ReservoirGates::ReservoirGates() = default;

ReservoirGates::ReservoirGates(size_t count)
    : Gates<ReservoirGate, ReservoirGates>(count) {}

ReservoirGates::ReservoirGates(size_t count, const ReservoirGateSP& value)
    : Gates<ReservoirGate, ReservoirGates>(count, value) {}

ReservoirGates::ReservoirGates(const std::vector<ReservoirGateSP>& vec)
    : Gates<ReservoirGate, ReservoirGates>(vec) {}

// Explicit template instantiation for serialize
template <class Archive>
void ReservoirGates::serialize(Archive& ar) {
  ar(cereal::base_class<Gates<ReservoirGate, ReservoirGates>>(this));
}

CEREAL_REGISTER_TYPE(ReservoirGates)
using GRR = Gates<ReservoirGate, ReservoirGates>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(GRR, ReservoirGates)
