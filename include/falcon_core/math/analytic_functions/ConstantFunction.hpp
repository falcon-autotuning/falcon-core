#pragma once

#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"

namespace falcon_core {
namespace math {
namespace analytic_functions {

class ConstantFunction : public AnalyticFunction {
 public:
  ConstantFunction(double value) : _value(value) {}

  double evaluate(double x) const override {
    // x is ignored for a constant function
    (void)x;
    return _value;
  }

 private:
  double _value;
};
}  // namespace analytic_functions
}  // namespace math
}  // namespace falcon_core
