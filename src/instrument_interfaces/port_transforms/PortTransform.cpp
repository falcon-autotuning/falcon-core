#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"

#include <stdexcept>

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/AnalyticFunction.hpp"

namespace falcon_core::instrument_interfaces::port_transforms {

PortTransform::PortTransform(const names::InstrumentPortSP&  port,
                             const math::AnalyticFunctionSP& transform)
    : AnalyticFunction(transform ? *transform : *Identity()), _port(port) {
  if (!port || !transform) {
    throw std::invalid_argument(
        "InstrumentPort: The transform must not be null.");
  }
}

PortTransform::PortTransform() : AnalyticFunction(), _port(nullptr) {}
PortTransformSP PortTransform::ConstantTransform(
    const names::InstrumentPortSP& port, const double& value) {
  if (!port) {
    throw std::invalid_argument("InstrumentPort: The port must not be null.");
  }
  return std::make_shared<PortTransform>(
      port, math::AnalyticFunction::Constant(value));
}
PortTransformSP PortTransform::IdentityTransform(
    const names::InstrumentPortSP& port) {
  if (!port) {
    throw std::invalid_argument("InstrumentPort: The port must not be null.");
  }
  return std::make_shared<PortTransform>(port,
                                         math::AnalyticFunction::Identity());
}

const names::InstrumentPortSP PortTransform::port() const { return _port; }
bool PortTransform::operator==(const PortTransform& other) const {
  return (*port() == *other.port()) &&
         math::AnalyticFunction::operator==(other);
}
bool PortTransform::operator!=(const PortTransform& other) const {
  return !(*this == other);
}

}  // namespace falcon_core::instrument_interfaces::port_transforms

CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::port_transforms::PortTransform)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::AnalyticFunction,
    falcon_core::instrument_interfaces::port_transforms::PortTransform)
