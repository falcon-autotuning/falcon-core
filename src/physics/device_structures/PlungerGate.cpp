#include "falcon_core/physics/device_structures/PlungerGate.hpp"

#include "falcon_core/physics/device_structures/DotGate.hpp"
using namespace falcon_core::physics::device_structures;

PlungerGate::PlungerGate(std::string name) : DotGate(std::move(name)) {}
PlungerGate::PlungerGate() = default;

template <class Archive>
void PlungerGate::serialize(Archive &ar) {
  ar(cereal::base_class<DotGate>(this));
}

CEREAL_REGISTER_TYPE(PlungerGate)
CEREAL_REGISTER_POLYMORPHIC_RELATION(DotGate, PlungerGate)
