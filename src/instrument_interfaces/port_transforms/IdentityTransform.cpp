#include "falcon_core/instrument_interfaces/port_transforms/IdentityTransform.hpp"

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/math/analytic_functions/Identity.hpp"
namespace falcon_core {
namespace instrument_interfaces {
namespace port_transforms {

IdentityTransform::IdentityTransform(
    names::InstrumentPortSP port, names::PortsSP<names::InstrumentPort> ports)
    : port_transforms::PortTransform(
          port,
          std::make_shared<math::analytic_functions::Identity>(port, ports)) {}

}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::port_transforms::IdentityTransform)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::port_transforms::IdentityTransform)
