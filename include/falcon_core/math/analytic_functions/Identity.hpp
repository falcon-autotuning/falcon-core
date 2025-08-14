#pragma once

#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"

namespace falcon_core {
namespace math {
namespace analytic_functions {

class Identity : public AnalyticFunction {
 public:
  Identity() = default;

  double evaluate(double x) const override { return x; }
};
}  // namespace analytic_functions
}  // namespace math
}  // namespace falcon_core
