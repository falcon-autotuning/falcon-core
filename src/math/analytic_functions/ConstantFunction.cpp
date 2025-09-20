#include "falcon_core/math/analytic_functions/ConstantFunction.hpp"

namespace falcon_core::math::analytic_functions {

ConstantFunction::ConstantFunction(double value) : _value(value) {}
ConstantFunction::ConstantFunction() = default;
double ConstantFunction::scale() const { return _value; }

Constant::Constant() = default;
Constant::Constant(const instrument_interfaces::names::PortsSP& ports,
                   double                                       value)
    : ValidatedAnalyticFunction(ports,
                                std::make_shared<ConstantFunction>(value)) {}

}  // namespace falcon_core::math::analytic_functions

CEREAL_REGISTER_TYPE(falcon_core::math::analytic_functions::ConstantFunction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::analytic_functions::AnalyticFunction,
    falcon_core::math::analytic_functions::ConstantFunction)

CEREAL_REGISTER_TYPE(falcon_core::math::analytic_functions::Constant)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::analytic_functions::ValidatedAnalyticFunction,
    falcon_core::math::analytic_functions::Constant)
