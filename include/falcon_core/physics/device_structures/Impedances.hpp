#pragma once

#include "falcon_core/generic/Jsonable.hpp"
#include "falcon_core/physics/device_structures/Impedance.hpp"

#include <memory>
#include <vector>

namespace falcon_core
{

class Impedances : public Jsonable
{
public:
  using value_type     = Impedance;
  using container_type = std::vector<std::shared_ptr<value_type>>;

  Impedances () = default;

  void
  append (const std::shared_ptr<value_type> &impedance)
  {
    _impedances.push_back (impedance);
  }

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j;
    add_metadata (
        j, "falcon_core.physics.device_structures.impedance", "Impedances");
    nlohmann::json impedances_json = nlohmann::json::array ();
    for (const auto &imp : _impedances)
      {
        impedances_json.push_back (imp->to_json ());
      }
    j["_impedances"] = impedances_json;
    return j;
  }

  size_t
  hash () const override
  {
    size_t seed = _impedances.size ();
    for (const auto &imp : _impedances)
      {
        seed ^= imp->hash () + 0x9e3779b9 + (seed << 6) + (seed >> 2);
      }
    return seed;
  }

private:
  container_type _impedances;
};

} // namespace falcon_core
