
#include "falcon_core/physics/config/geometries/HasLeftNeighbor.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {

HasLeftNeighbor::HasLeftNeighbor() = default;
HasLeftNeighbor::HasLeftNeighbor(
    device_structures::BaseConnectionSP left_neighbor)
    : _left_neighbor(left_neighbor) {}

device_structures::BaseConnectionSP HasLeftNeighbor::left_neighbor() const {
  return _left_neighbor;
}

template <class Archive>
void HasLeftNeighbor::serialize(Archive& ar) {
  ar(cereal::base_class<generic::Song>(this), _left_neighbor);
}
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::config::geometries::HasLeftNeighbor)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::geometries::HasLeftNeighbor)
