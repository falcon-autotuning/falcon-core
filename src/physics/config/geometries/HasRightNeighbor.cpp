#include "falcon_core/physics/config/geometries/HasRightNeighbor.hpp"

namespace falcon_core::physics::config::geometries {

HasRightNeighbor::HasRightNeighbor() = default;
HasRightNeighbor::HasRightNeighbor(
    device_structures::BaseConnectionSP right_neighbor)
    : _right_neighbor(right_neighbor) {}

device_structures::BaseConnectionSP HasRightNeighbor::right_neighbor() const {
  return _right_neighbor;
}

}  // namespace falcon_core::physics::config::geometries
CEREAL_REGISTER_TYPE(falcon_core::physics::config::geometries::HasRightNeighbor)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::geometries::HasRightNeighbor)
