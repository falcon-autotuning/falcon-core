#include "falcon_core/physics/device_structures/BarrierGate.hpp"

#include <cereal/archives/json.hpp>
using namespace falcon_core;
using namespace falcon_core::physics::device_structures;

CEREAL_REGISTER_TYPE(BarrierGate)
CEREAL_REGISTER_POLYMORPHIC_RELATION(DotGate, BarrierGate)
