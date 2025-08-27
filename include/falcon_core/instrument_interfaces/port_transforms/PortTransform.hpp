#pragma once

#include <memory>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/analytic_functions/AnalyticFunction.hpp"

/**
 * @brief A transform that maps a port to a time domain analytic function.
 */
namespace falcon_core {
namespace instrument_interfaces {
namespace port_transforms {

class PortTransform : public generic::Song {
 public:
  /**
   * @brief Construct a PortTransform with an analytic function.
   * @param function The analytic function to apply.
   */
  PortTransform(
      std::shared_ptr<math::analytic_functions::AnalyticFunction> function)
      : _function(std::move(function)) {}

  /**
   * @brief Apply the transform to a value.
   * @param value The input value.
   * @return The transformed value.
   */
  double apply(double value) const {
    if (!_function) return value;
    return _function->evaluate(value);
  }

#ifndef SWIG
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _function);
  }
#endif

 private:
  std::shared_ptr<math::analytic_functions::AnalyticFunction> _function;
};

}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core
