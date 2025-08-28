#pragma once

#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"

/**
 * @file Identity.hpp
 * @brief Defines the identity analytic function.
 */

namespace falcon_core {
namespace math {
namespace analytic_functions {

/**
 * @brief Analytic function that returns its input unchanged.
 */
class Identity : public AnalyticFunction {
 public:
  Identity();
  double evaluate(double x) const override;

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar);
};
}  // namespace analytic_functions
}  // namespace math
}  // namespace falcon_core
