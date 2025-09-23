#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/AnalyticFunction.hpp"

namespace falcon_core::instrument_interfaces::port_transforms {

PortTransform::PortTransform(const names::InstrumentPortSP&  port,
                             const math::AnalyticFunctionSP& transform)
    : AnalyticFunction(*transform), _port(port) {}

PortTransform::PortTransform() : AnalyticFunction(), _port(nullptr) {}
PortTransformSP PortTransform::ConstantTransform(
    const names::InstrumentPortSP& port, const double& value) {
  return std::make_shared<PortTransform>(
      port, math::AnalyticFunction::Constant(value));
}
PortTransformSP PortTransform::IdentityTransform(
    const names::InstrumentPortSP& port) {
  return std::make_shared<PortTransform>(port,
                                         math::AnalyticFunction::Identity());
}

const names::InstrumentPortSP PortTransform::port() const { return _port; }

}  // namespace falcon_core::instrument_interfaces::port_transforms

CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::port_transforms::PortTransform)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::AnalyticFunction,
    falcon_core::instrument_interfaces::port_transforms::PortTransform)
