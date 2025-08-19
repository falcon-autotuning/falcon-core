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

  friend class cereal::access;
  ConstantFunction() = default;
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
