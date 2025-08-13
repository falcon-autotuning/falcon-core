#pragma once

#include "falcon_core/physics/device_structures/BaseConnection.hpp"

namespace falcon_core
{

class Ohmic : public BaseConnection
{
public:
  using BaseConnection::BaseConnection;

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j = BaseConnection::to_json ();
    add_metadata (j, "falcon_core.physics.device_structures.ohmic", "Ohmic");
    return j;
  }
};

} // namespace falcon_core
