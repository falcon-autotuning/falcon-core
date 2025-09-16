#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"

#include <cereal/archives/binary.hpp>

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/analytic_functions/ValidatedAnalyticFunction.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace port_transforms {

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

}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::port_transforms::PortTransform)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::port_transforms::PortTransform)
