#include "falcon_core/physics/device_structures/PlungerGates.hpp"

using namespace falcon_core;
using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(PlungerGates<PlungerGate>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(DotGates<DotGate>,
                                     PlungerGates<PlungerGate>)
