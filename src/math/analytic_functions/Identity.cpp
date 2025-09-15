#include "falcon_core/math/analytic_functions/Identity.hpp"

namespace falcon_core::math::analytic_functions {

Identity::Identity() = default;
Identity::Identity(const instrument_interfaces::names::PortsSP<
                       instrument_interfaces::names::InstrumentPort>&    ports,
                   const instrument_interfaces::names::InstrumentPortSP& port)
    : ValidatedAnalyticFunction(ports,
                                std::make_shared<IdentityFunction>(port)) {}
IdentityFunction::IdentityFunction() = default;
IdentityFunction::IdentityFunction(
    const instrument_interfaces::names::InstrumentPortSP& port)
    : _port(port) {}
double IdentityFunction::_function(
    const generic::MapSP<std::string, double>& data) const {
  return data->at("x");
}
}  // namespace falcon_core::math::analytic_functions

CEREAL_REGISTER_TYPE(falcon_core::math::analytic_functions::Identity)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::analytic_functions::AnalyticFunction,
    falcon_core::math::analytic_functions::Identity)
CEREAL_REGISTER_TYPE(falcon_core::math::analytic_functions::IdentityFunction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::analytic_functions::ValidatedAnalyticFunction,
    falcon_core::math::analytic_functions::IdentityFunction)
