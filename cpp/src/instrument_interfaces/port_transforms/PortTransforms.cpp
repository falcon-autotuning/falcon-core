#include "falcon_core/instrument_interfaces/port_transforms/PortTransforms.hpp"

#include "falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace port_transforms {

const generic::List<PortTransform>& pts_check_and_deref(
    const generic::ListSP<PortTransform>& init) {
  if (!init)
    throw std::invalid_argument("PortTransforms: init must not be null.");
  return *init;
}
PortTransforms::PortTransforms(const PortTransforms& other)
    : List<PortTransform>(other) {}
PortTransforms::PortTransforms() = default;
PortTransforms::PortTransforms(const generic::ListSP<PortTransform>& init)
    : List(pts_check_and_deref(init)) {}
PortTransforms::PortTransforms(const std::vector<PortTransformSP>& init)
    : List(init) {}
const generic::ListSP<PortTransform> PortTransforms::transforms() const {
  return std::make_shared<List<PortTransform>>(items());
}

}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::port_transforms::PortTransforms)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<
        falcon_core::instrument_interfaces::port_transforms::PortTransform>,
    falcon_core::instrument_interfaces::port_transforms::PortTransforms)
