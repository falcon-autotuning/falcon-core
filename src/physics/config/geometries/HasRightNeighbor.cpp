#include "falcon_core/physics/config/geometries/HasRightNeighbor.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {

HasRightNeighbor::HasRightNeighbor() = default;
HasRightNeighbor::HasRightNeighbor(
    device_structures::BaseConnectionSP right_neighbor)
    : _right_neighbor(right_neighbor) {}

device_structures::BaseConnectionSP HasRightNeighbor::right_neighbor() const {
  return _right_neighbor;
}

template <class Archive>
void HasRightNeighbor::serialize(Archive& ar) {
  ar(cereal::base_class<generic::Song>(this), _right_neighbor);
}
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::config::geometries::HasRightNeighbor)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::geometries::HasRightNeighbor)
