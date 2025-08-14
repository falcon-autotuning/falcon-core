#include "falcon_core/physics/device_structures/Gates.hpp"

using namespace falcon_core;
using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(Gates<Gate>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseConnections<BaseConnection>,
                                     Gates<Gate>)
