#pragma once

#include "falcon_core/physics/device_structures/BaseConnection.hpp"

namespace falcon_core
{
namespace physics
{
namespace device_structures
{

class Gate : public BaseConnection
{
public:
  using BaseConnection::BaseConnection;

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j = BaseConnection::to_json ();
    add_metadata (j, "falcon_core.physics.device_structures.gate", "Gate");
    return j;
  }
};
}
}
} // namespace falcon_core
