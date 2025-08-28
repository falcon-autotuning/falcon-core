#include "falcon_core/physics/device_structures/ScreeningGate.hpp"

#include "falcon_core/physics/device_structures/Gate.hpp"
using namespace falcon_core::physics::device_structures;

ScreeningGate::ScreeningGate(std::string name) : Gate(std::move(name)) {}
ScreeningGate::ScreeningGate() = default;

template <class Archive>
void ScreeningGate::serialize(Archive &ar) {
  ar(cereal::base_class<Gate>(this));
}

CEREAL_REGISTER_TYPE(ScreeningGate)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Gate, ScreeningGate)
