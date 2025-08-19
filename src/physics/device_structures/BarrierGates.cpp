#include "falcon_core/physics/device_structures/BarrierGates.hpp"

#include <cereal/archives/json.hpp>

#include "falcon_core/physics/device_structures/DotGates.hpp"

using namespace falcon_core;
using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(BarrierGates<BarrierGate>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(DotGates<DotGate>,
                                     BarrierGates<BarrierGate>)
