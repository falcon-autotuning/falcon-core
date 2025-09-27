#include "falcon_core/physics/config/geometries/HasRightNeighbor.hpp"

#include <stdexcept>

namespace falcon_core::physics::config::geometries {

HasRightNeighbor::HasRightNeighbor() = default;
HasRightNeighbor::HasRightNeighbor(
    device_structures::ConnectionSP right_neighbor)
    : _right_neighbor(right_neighbor) {
  if (!right_neighbor) {
    throw std::invalid_argument(
        "HasRightNeighbor: The right neighbor cannot be null.");
  }
}

device_structures::ConnectionSP HasRightNeighbor::right_neighbor() const {
  return _right_neighbor;
}

}  // namespace falcon_core::physics::config::geometries
CEREAL_REGISTER_TYPE(falcon_core::physics::config::geometries::HasRightNeighbor)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::geometries::HasRightNeighbor)
