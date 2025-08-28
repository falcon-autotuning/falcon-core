#include "falcon_core/physics/device_structures/BarrierGate.hpp"

#include "falcon_core/physics/device_structures/DotGate.hpp"
using namespace falcon_core::physics::device_structures;

BarrierGate::BarrierGate(std::string name) : DotGate(std::move(name)) {}
BarrierGate::BarrierGate() = default;

template <class Archive>
void BarrierGate::serialize(Archive &ar) {
  ar(cereal::base_class<DotGate>(this));
}

// Explicit instantiation for cereal
template void BarrierGate::serialize<cereal::JSONOutputArchive>(
    cereal::JSONOutputArchive &);
template void BarrierGate::serialize<cereal::JSONInputArchive>(
    cereal::JSONInputArchive &);

CEREAL_REGISTER_TYPE(BarrierGate)
CEREAL_REGISTER_POLYMORPHIC_RELATION(DotGate, BarrierGate)
