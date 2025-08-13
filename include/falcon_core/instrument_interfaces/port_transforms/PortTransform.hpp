#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"

#include <memory>

namespace falcon_core
{
namespace instrument_interfaces
{
namespace port_transforms
{

class PortTransform : public generic::Song
{
public:
  PortTransform (
      std::shared_ptr<math::analytic_function::AnalyticFunction> function)
      : _function (std::move (function))
  {
  }

  double
  apply (double value) const
  {
    if (!_function)
      return value;
    return _function->evaluate (value);
  }

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j;
    add_metadata (
        j, "falcon_core.physics.transforms.port_transform", "PortTransform");
    if (_function)
      {
        j["_function"] = _function->to_json ();
      }
    return j;
  }

  size_t
  hash () const override
  {
    return _function ? _function->hash () : 0;
  }

private:
  std::shared_ptr<math::analytic_function::AnalyticFunction> _function;
};
}
}
} // namespace falcon_core
