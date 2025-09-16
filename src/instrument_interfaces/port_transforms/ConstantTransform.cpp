#include "falcon_core/instrument_interfaces/port_transforms/ConstantTransform.hpp"

#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"
#include "falcon_core/math/analytic_functions/ConstantFunction.hpp"
#include "falcon_core/math/analytic_functions/ValidatedAnalyticFunction.hpp"

namespace falcon_core::instrument_interfaces::port_transforms {

ConstantTransform::ConstantTransform(
    const double& scale, const names::PortsSP<names::InstrumentPort>& ports)
    : PortTransform(
          ports->ports()->at(0),
          std::make_shared<math::analytic_functions::Constant>(ports, scale)) {}

ConstantTransform::ConstantTransform() : PortTransform() {}

}  // namespace falcon_core::instrument_interfaces::port_transforms

CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::port_transforms::ConstantTransform)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::instrument_interfaces::port_transforms::PortTransform,
    falcon_core::instrument_interfaces::port_transforms::ConstantTransform)
