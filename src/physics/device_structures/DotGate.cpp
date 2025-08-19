#include "falcon_core/physics/device_structures/DotGate.hpp"

#include <cereal/archives/json.hpp>
using namespace falcon_core;
using namespace falcon_core::physics::device_structures;

CEREAL_REGISTER_TYPE(DotGate)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Gate, DotGate)
