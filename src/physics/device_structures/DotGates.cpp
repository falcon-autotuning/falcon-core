#include "falcon_core/physics/device_structures/DotGates.hpp"

#include <cereal/archives/json.hpp>
using namespace falcon_core;
using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(DotGates<DotGate>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Gates<Gate>, DotGates<DotGate>)
