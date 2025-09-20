
#include "falcon_core/physics/config/geometries/HasLeftNeighbor.hpp"

namespace falcon_core::physics::config::geometries {

HasLeftNeighbor::HasLeftNeighbor() = default;
HasLeftNeighbor::HasLeftNeighbor(device_structures::ConnectionSP left_neighbor)
    : _left_neighbor(left_neighbor) {}

device_structures::ConnectionSP HasLeftNeighbor::left_neighbor() const {
  return _left_neighbor;
}

}  // namespace falcon_core::physics::config::geometries
CEREAL_REGISTER_TYPE(falcon_core::physics::config::geometries::HasLeftNeighbor)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::geometries::HasLeftNeighbor)
