#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/BaseConnections.hpp"
#include "falcon_core/physics/device_structures/Gate.hpp"
#include "falcon_core/physics/device_structures/Ohmic.hpp"

#include <memory>
#include <nlohmann/json.hpp>

namespace falcon_core
{
namespace physics
{
namespace config
{
namespace core
{

class StandardConfigConnections : public generic::Song
{
public:
  StandardConfigConnections (
      std::shared_ptr<BaseConnections<device_structures::Ohmic>> ohmics,
      std::shared_ptr<BaseConnections<device_structures::Gate>>  gates)
      : _ohmics (std::move (ohmics)), _gates (std::move (gates))
  {
  }

  const std::shared_ptr<BaseConnections<device_structures::Ohmic>> &
  get_ohmics () const
  {
    return _ohmics;
  }
  const std::shared_ptr<BaseConnections<device_structures::Gate>> &
  get_gates () const
  {
    return _gates;
  }

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j;
    add_metadata (
        j,
        "falcon_core.physics.config.core.standard_config_connections",
        "StandardConfigConnections");
    j["_ohmics"] = _ohmics->to_json ();
    j["_gates"]  = _gates->to_json ();
    return j;
  }

  size_t
  hash () const override
  {
    size_t h1 = _ohmics ? _ohmics->hash () : 0;
    size_t h2 = _gates ? _gates->hash () : 0;
    return h1 ^ (h2 << 1);
  }

private:
  std::shared_ptr<BaseConnections<device_structures::Ohmic>> _ohmics;
  std::shared_ptr<BaseConnections<device_structures::Gate>>  _gates;
};
}
}
}
} // namespace falcon_core
