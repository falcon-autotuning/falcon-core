#pragma once

#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"

namespace falcon_core
{
namespace math
{
namespace analytic_functions
{

class ConstantFunction : public AnalyticFunction
{
public:
  ConstantFunction (double value) : _value (value) {}

  double
  evaluate (double x) const override
  {
    // x is ignored for a constant function
    (void)x;
    return _value;
  }

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j = AnalyticFunction::to_json ();
    add_metadata (j,
                  "falcon_core.math.analytic_functions.analytic_function",
                  "ConstantFunction");
    j["_value"] = _value;
    return j;
  }

private:
  double _value;
};
}
}
} // namespace falcon_core
