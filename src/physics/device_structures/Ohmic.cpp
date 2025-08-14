#include "falcon_core/physics/device_structures/Ohmic.hpp"

using namespace falcon_core;
using namespace falcon_core::physics::device_structures;

CEREAL_REGISTER_TYPE(Ohmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseConnection, Ohmic)
