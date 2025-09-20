#pragma once

#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"
#include "falcon_core/math/analytic_functions/ValidatedAnalyticFunction.hpp"

/**
 * @file ConstantFunction.hpp
 * @brief Defines a constant analytic function.
 */

namespace falcon_core::math::analytic_functions {

/**
 * @brief Analytic function that always returns a constant value.
 *
 * @details
 * Ignores its input and returns the value provided at construction.
 */
class ConstantFunction : public AnalyticFunction {
  double _value;

 public:
  ConstantFunction(double value);
  double scale() const;

 protected:
  ConstantFunction();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<AnalyticFunction>(this), _value);
  }
};
/**
 * #@brief A type of function that does nothing to the underlying discrete data.
 */
class Constant : public ValidatedAnalyticFunction {
 public:
  Constant(const instrument_interfaces::names::PortsSP& ports, double value);

 protected:
  Constant();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<ValidatedAnalyticFunction>(this));
  }
};
}  // namespace falcon_core::math::analytic_functions
