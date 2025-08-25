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
  /**
   * @brief Construct a constant function.
   * @param value The constant value to return.
   */
  ConstantFunction(double value) : _value(value) {}

  /**
   * @brief Evaluate the function (returns the constant value).
   * @param x Input value (ignored).
   * @return The constant value.
   */
  double evaluate(double x) const override {
    // x is ignored for a constant function
    (void)x;
    return _value;
  }

 private:
  double _value; ///< The constant value.

  friend class cereal::access;
  /**
   * @brief Default constructor for serialization.
   */
  ConstantFunction() = default;
  /**
   * @brief Serialization method for cereal.
   * @param ar Archive object.
   */
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<AnalyticFunction>(this), _value);
  }
};
}  // namespace analytic_functions
}  // namespace math
}  // namespace falcon_core

using namespace falcon_core::math::analytic_functions;
CEREAL_REGISTER_TYPE(falcon_core::math::analytic_functions::ConstantFunction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::analytic_functions::ConstantFunction)
