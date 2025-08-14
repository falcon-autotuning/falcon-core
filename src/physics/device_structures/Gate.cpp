#include "falcon_core/physics/device_structures/Gate.hpp"

using namespace falcon_core;
using namespace falcon_core::physics::device_structures;

CEREAL_REGISTER_TYPE(Gate)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseConnection, Gate)
