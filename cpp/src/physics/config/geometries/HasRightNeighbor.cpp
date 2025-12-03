#include "falcon_core/physics/config/geometries/HasRightNeighbor.hpp"

#include <stdexcept>

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
HasRightNeighbor::HasRightNeighbor(const HasRightNeighbor& other) {
  std::shared_lock<std::shared_timed_mutex> lock_right_neighbor(
      other._mu_right_neighbor);
  _right_neighbor = other._right_neighbor;
}
HasRightNeighbor HasRightNeighbor::operator=(const HasRightNeighbor& other) {
  if (this != &other) {
    std::shared_lock<std::shared_timed_mutex> lock_other_right_neighbor(
        other._mu_right_neighbor, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_right_neighbor(
        _mu_right_neighbor, std::defer_lock);
    std::lock(lock_right_neighbor, lock_other_right_neighbor);
    _right_neighbor = other._right_neighbor;
  }
  return *this;
}
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
  std::shared_lock<std::shared_timed_mutex> lock(_mu_right_neighbor);
  return _right_neighbor;
}

}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::config::geometries::HasRightNeighbor)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::geometries::HasRightNeighbor)
