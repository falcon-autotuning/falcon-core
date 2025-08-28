#pragma once

#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"

/**
 * @file ConstantFunction.hpp
 * @brief Defines a constant analytic function.
 */

namespace falcon_core {
namespace math {
namespace analytic_functions {

/**
 * @brief Analytic function that always returns a constant value.
 *
 * @details
 * Ignores its input and returns the value provided at construction.
 */
class ConstantFunction : public AnalyticFunction {
 public:
  ConstantFunction(double value);
  double evaluate(double x) const override;

 private:
  double _value;
  ConstantFunction();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar);
};
}  // namespace analytic_functions
}  // namespace math
}  // namespace falcon_core
