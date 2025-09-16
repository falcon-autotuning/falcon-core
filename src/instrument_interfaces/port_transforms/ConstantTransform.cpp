#include "falcon_core/instrument_interfaces/port_transforms/ConstantTransform.hpp"

#include "falcon_core/math/analytic_functions/ConstantFunction.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace port_transforms {

ConstantTransform::ConstantTransform(double value)
    : PortTransform(
          std::make_shared<math::analytic_functions::ConstantFunction>(value)) {
}

ConstantTransform::ConstantTransform() : PortTransform() {}

template <class Archive>
void ConstantTransform::serialize(Archive& ar) {
  ar(cereal::base_class<PortTransform>(this));
}

}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::port_transforms::ConstantTransform)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::port_transforms::ConstantTransform)
