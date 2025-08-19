#include "falcon_core/physics/device_structures/BaseConnections.hpp"

#include <cereal/archives/json.hpp>
using namespace falcon_core;
using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(BaseConnections<BaseConnection>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(generic::Song,
                                     BaseConnections<BaseConnection>)
