#pragma once

#include "falcon_core/generic/Jsonable.hpp"
#include "falcon_core/math/domains/Domain.hpp"

#include <memory>

namespace falcon_core
{

class BaseDiscretizer : public Jsonable
{
public:
  BaseDiscretizer (double delta, std::shared_ptr<Domain> delta_domain)
      : _delta (delta), _delta_domain (std::move (delta_domain))
  {
  }

  virtual ~BaseDiscretizer () = default;

  double
  delta () const
  {
    return _delta;
  }
  void
  set_delta (double delta)
  {
    _delta = delta;
  }

  const std::shared_ptr<Domain> &
  delta_domain () const
  {
    return _delta_domain;
  }

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j;
    add_metadata (j,
                  "falcon_core.math.discretizers.base_discretizer",
                  "BaseDiscretizer");
    j["_delta"] = _delta;
    if (_delta_domain)
      {
        j["_delta_domain"] = _delta_domain->to_json ();
      }
    return j;
  }

  size_t
  hash () const override
  {
    size_t h1 = std::hash<double>{}(_delta);
    size_t h2 = _delta_domain ? _delta_domain->hash () : 0;
    return h1 ^ (h2 << 1);
  }

private:
  double                  _delta;
  std::shared_ptr<Domain> _delta_domain;
};

} // namespace falcon_core
