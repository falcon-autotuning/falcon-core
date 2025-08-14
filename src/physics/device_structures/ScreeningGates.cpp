#include "falcon_core/physics/device_structures/ScreeningGates.hpp"

using namespace falcon_core;
using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(ScreeningGates<ScreeningGate>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Gates<Gate>, ScreeningGates<ScreeningGate>)
