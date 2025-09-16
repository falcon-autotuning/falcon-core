#include "falcon_core/instrument_interfaces/port_transforms/PortTransforms.hpp"

#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"

namespace falcon_core::instrument_interfaces::port_transforms {

PortTransforms::PortTransforms() = default;
PortTransforms::PortTransforms(const generic::ListSP<PortTransform>& init)
    : List(*init) {}
PortTransforms::PortTransforms(const std::vector<PortTransformSP>& init)
    : List(init) {}
const generic::ListSP<PortTransform> PortTransforms::transforms() const {
  return std::make_shared<List<PortTransform>>(items());
}

}  // namespace falcon_core::instrument_interfaces::port_transforms

CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::port_transforms::PortTransforms)
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<
        falcon_core::instrument_interfaces::port_transforms::PortTransform>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<
        falcon_core::instrument_interfaces::port_transforms::PortTransform>,
    falcon_core::instrument_interfaces::port_transforms::PortTransforms)
