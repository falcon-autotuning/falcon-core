#include "falcon_core/instrument_interfaces/port_transforms/IdentityTransform.hpp"

#include "falcon_core/math/analytic_functions/Identity.hpp"
namespace falcon_core::instrument_interfaces::port_transforms {

IdentityTransform::IdentityTransform(
    names::InstrumentPortSP port, names::PortsSP<names::InstrumentPort> ports)
    : port_transforms::PortTransform(
          port,
          std::make_shared<math::analytic_functions::Identity>(port, ports)) {}

}  // namespace falcon_core::instrument_interfaces::port_transforms

CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::port_transforms::IdentityTransform)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::instrument_interfaces::port_transforms::PortTransform,
    falcon_core::instrument_interfaces::port_transforms::IdentityTransform)
