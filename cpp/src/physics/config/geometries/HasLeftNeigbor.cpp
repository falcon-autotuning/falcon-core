
#include <stdexcept>

#include "falcon_core/physics/config/geometries/HasLeftNeighbor.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
HasLeftNeighbor::HasLeftNeighbor(const HasLeftNeighbor& other) {
  std::shared_lock<std::shared_timed_mutex> lock_left_neighbor(
      other._mu_left_neighbor);
  _left_neighbor = other._left_neighbor;
}
HasLeftNeighbor HasLeftNeighbor::operator=(const HasLeftNeighbor& other) {
  if (this != &other) {
    std::shared_lock<std::shared_timed_mutex> lock_other_left_neighbor(
        other._mu_left_neighbor, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_left_neighbor(
        _mu_left_neighbor, std::defer_lock);
    std::lock(lock_left_neighbor, lock_other_left_neighbor);
    _left_neighbor = other._left_neighbor;
  }
  return *this;
}
HasLeftNeighbor::HasLeftNeighbor() = default;
HasLeftNeighbor::HasLeftNeighbor(device_structures::ConnectionSP left_neighbor)
    : _left_neighbor(left_neighbor) {
  if (!left_neighbor) {
    throw std::invalid_argument(
        "HasLeftNeighbor: The left neightbor must not be null.");
  }
}

device_structures::ConnectionSP HasLeftNeighbor::left_neighbor() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_left_neighbor);
  return _left_neighbor;
}

}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::physics::config::geometries::HasLeftNeighbor)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::geometries::HasLeftNeighbor)
