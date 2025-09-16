#include "falcon_core/instrument_interfaces/port_transforms/IdentityTransform.hpp"

#include "falcon_core/math/analytic_functions/Identity.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace port_transforms {

IdentityTransform::IdentityTransform()
    : PortTransform(std::make_shared<math::analytic_functions::Identity>()) {}

template <class Archive>
void IdentityTransform::serialize(Archive& ar) {
  ar(cereal::base_class<PortTransform>(this));
}

}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::port_transforms::IdentityTransform)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::port_transforms::IdentityTransform)
