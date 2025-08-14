#include "falcon_core/physics/device_structures/ReservoirGates.hpp"

using namespace falcon_core;
using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(ReservoirGates<ReservoirGate>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Gates<Gate>, ReservoirGates<ReservoirGate>)
