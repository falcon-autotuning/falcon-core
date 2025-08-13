#pragma once

#include "falcon_core/physics/device_structures/BaseConnections.hpp"
#include "falcon_core/physics/device_structures/Channel.hpp"

namespace falcon_core
{
namespace physics
{
namespace device_structures
{

class Channels : public BaseConnections<Channel>
{
public:
  using BaseConnections<Channel>::BaseConnections;

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j = BaseConnections<Channel>::to_json ();
    add_metadata (
        j, "falcon_core.physics.device_structures.channel", "Channels");
    return j;
  }
};
}
}
} // namespace falcon_core
