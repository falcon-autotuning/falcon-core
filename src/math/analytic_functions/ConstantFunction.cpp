#include "falcon_core/math/analytic_functions/ConstantFunction.hpp"

namespace falcon_core {
namespace math {
namespace analytic_functions {

ConstantFunction::ConstantFunction(double value) : _value(value) {}
ConstantFunction::ConstantFunction() = default;

double ConstantFunction::evaluate(double x) const {
  (void)x;
  return _value;
}

template <class Archive>
void ConstantFunction::serialize(Archive& ar) {
  ar(cereal::base_class<AnalyticFunction>(this), _value);
}

}  // namespace analytic_functions
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::analytic_functions::ConstantFunction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::analytic_functions::ConstantFunction)
