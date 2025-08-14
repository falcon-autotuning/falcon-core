#include "falcon_core/physics/device_structures/BaseConnection.hpp"

using namespace falcon_core;
using namespace falcon_core::physics::device_structures;

CEREAL_REGISTER_TYPE(BaseConnection)
CEREAL_REGISTER_POLYMORPHIC_RELATION(generic::Song, BaseConnection)
