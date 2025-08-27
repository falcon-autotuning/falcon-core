#pragma once

#include "falcon_core/generic/Song.hpp"

/**
 * @file AnalyticFunction.hpp
 * @brief Abstract base class for analytic functions in FalconCore.
 */

namespace falcon_core {
namespace math {
namespace analytic_functions {

/**
 * @brief Abstract base class for analytic functions.
 *
 * @details
 * AnalyticFunction provides an interface for mathematical functions
 * that can be evaluated at a given point. Derived classes must implement
 * the evaluate() method.
 */
class AnalyticFunction : public generic::Song {
 public:
  /**
   * @brief Virtual destructor.
   */
  virtual ~AnalyticFunction() = default;

  /**
   * @brief Evaluate the function at a given point.
   * @param x The input value.
   * @return The function value at x.
   */
  virtual double evaluate(double x) const = 0;

 private:
  friend class cereal::access;
  /**
   * @brief Serialization method for cereal.
   * @param ar Archive object.
   */
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this));
  }
};
}  // namespace analytic_functions
}  // namespace math
}  // namespace falcon_core

using namespace falcon_core::math::analytic_functions;
CEREAL_REGISTER_TYPE(falcon_core::math::analytic_functions::AnalyticFunction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::analytic_functions::AnalyticFunction)
