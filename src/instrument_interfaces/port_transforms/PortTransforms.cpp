#include "falcon_core/instrument_interfaces/port_transforms/PortTransforms.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace port_transforms {

PortTransforms::PortTransforms() = default;

void PortTransforms::append(const std::shared_ptr<value_type> &transform) {
    _transforms.push_back(transform);
}

const PortTransforms::container_type &PortTransforms::get_transforms() const {
    return _transforms;
}

template <class Archive>
void PortTransforms::serialize(Archive &ar) {
    ar(cereal::base_class<generic::Song>(this), _transforms);
}

}  // namespace port_transforms
}  // namespace instrument_interfaces
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(
    falcon_core::instrument_interfaces::port_transforms::PortTransforms)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::port_transforms::PortTransforms)
