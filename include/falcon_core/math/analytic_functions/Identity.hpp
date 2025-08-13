#pragma once

#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"

namespace falcon_core
{
namespace math
{
namespace analytic_functions
{

class Identity : public AnalyticFunction
{
public:
  Identity () = default;

  double
  evaluate (double x) const override
  {
    return x;
  }

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j = AnalyticFunction::to_json ();
    add_metadata (j,
                  "falcon_core.math.analytic_functions.analytic_function",
                  "Identity");
    return j;
  }
};
}
}
} // namespace falcon_core
