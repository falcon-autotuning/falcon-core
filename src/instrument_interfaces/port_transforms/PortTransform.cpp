#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"

#include "falcon_core/math/analytic_functions/ValidatedAnalyticFunction.hpp"

namespace falcon_core::instrument_interfaces::port_transforms {

PortTransform::PortTransform(
    names::InstrumentPortSP                               port,
    math::analytic_functions::ValidatedAnalyticFunctionSP function)
    : _port(port) {}

PortTransform::PortTransform() = default;

bool PortTransform::validate_transform() {
  if (!validate_port(_port)) {
    throw std::runtime_error("The transform must be valid for the port.");
  }
  return true;
}
const names::InstrumentPortSP PortTransform::port() const { return _port; }
const math::analytic_functions::ValidatedAnalyticFunctionSP
PortTransform::transform() const {
  return std::make_shared<math::analytic_functions::ValidatedAnalyticFunction>(
      ports(), function());
}

}  // namespace falcon_core::instrument_interfaces::port_transforms

CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::port_transforms::PortTransform)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::analytic_functions::ValidatedAnalyticFunction,
    falcon_core::instrument_interfaces::port_transforms::PortTransform)
