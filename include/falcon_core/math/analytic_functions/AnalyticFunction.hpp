#pragma once

#include "falcon_core/generic/Song.hpp"

namespace falcon_core
{
namespace math
{
namespace analytic_functions
{

class AnalyticFunction : public generic::Song
{
public:
  virtual ~AnalyticFunction ()             = default;
  virtual double evaluate (double x) const = 0;

  nlohmann::json
  to_json () const override
  {
    nlohmann::json j;
    add_metadata (j,
                  "falcon_core.math.analytic_functions.analytic_function",
                  "AnalyticFunction");
    return j;
  }

  size_t
  hash () const override
  {
    return 0; // Base hash
  }
};
}
}
} // namespace falcon_core
