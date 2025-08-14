#include "falcon_core/physics/device_structures/GateRelations.hpp"

using namespace falcon_core;
using namespace falcon_core::physics::device_structures;
using GR = GateRelations<Gate, Gates<Gate>>;
CEREAL_REGISTER_TYPE(GR)
CEREAL_REGISTER_POLYMORPHIC_RELATION(generic::Song, GR)
