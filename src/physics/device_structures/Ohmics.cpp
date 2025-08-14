#include "falcon_core/physics/device_structures/Ohmics.hpp"

using namespace falcon_core;
using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(Ohmics<Ohmic>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseConnections<BaseConnection>,
                                     Ohmics<Ohmic>)
