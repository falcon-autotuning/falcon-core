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
  /**
   * @brief Default constructor.
   */
  Identity() = default;

  /**
   * @brief Evaluate the function (returns the input value).
   * @param x Input value.
   * @return The input value.
   */
  double evaluate(double x) const override { return x; }

 private:
  friend class cereal::access;
  /**
   * @brief Serialization method for cereal.
   * @param ar Archive object.
   */
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<AnalyticFunction>(this));
  }
};
}  // namespace analytic_functions
}  // namespace math
}  // namespace falcon_core

using namespace falcon_core::math::analytic_functions;
CEREAL_REGISTER_TYPE(falcon_core::math::analytic_functions::Identity)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::analytic_functions::Identity)
