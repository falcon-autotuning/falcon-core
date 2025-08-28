#include "falcon_core/physics/device_structures/ReservoirGate.hpp"

#include "falcon_core/physics/device_structures/Gate.hpp"
using namespace falcon_core::physics::device_structures;

ReservoirGate::ReservoirGate(std::string name) : Gate(std::move(name)) {}
ReservoirGate::ReservoirGate() = default;

template <class Archive>
void ReservoirGate::serialize(Archive &ar) {
  ar(cereal::base_class<Gate>(this));
}

// Explicit instantiation for cereal
template void ReservoirGate::serialize<cereal::JSONOutputArchive>(
    cereal::JSONOutputArchive &);
template void ReservoirGate::serialize<cereal::JSONInputArchive>(
    cereal::JSONInputArchive &);

CEREAL_REGISTER_TYPE(ReservoirGate)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Gate, ReservoirGate)
