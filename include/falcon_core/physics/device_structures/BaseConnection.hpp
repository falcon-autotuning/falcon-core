#pragma once

#include "falcon_core/generic/NameBase.hpp"

#include <string>

namespace falcon_core
{
namespace physics
{
namespace device_structures
{
class BaseConnection : public generic::NameBase<std::string>
{
public:
  using NameBase<std::string>::NameBase;

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j = NameBase<std::string>::to_json ();
    add_metadata (j,
                  "falcon_core.physics.device_structures.base_connection",
                  "BaseConnection");
    return j;
  }
};
}
}
} // namespace falcon_core
