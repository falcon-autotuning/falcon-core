#include "falcon_core/physics/config/geometries/HasRightNeighbor.hpp"

#include <stdexcept>

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
HasRightNeighbor::HasRightNeighbor(const HasRightNeighbor& other) {
  std::unique_lock<std::shared_timed_mutex> lock_right_neighbor(
      _mu_right_neighbor);
  if (!other.right_neighbor()) {
    throw std::invalid_argument(
        "HasRightNeighbor: right_neighbor is null in copy");
  }
  _right_neighbor =
      std::make_shared<device_structures::Connection>(*other.right_neighbor());
}
HasRightNeighbor& HasRightNeighbor::operator=(const HasRightNeighbor& other) {
  if (this != &other) {
    std::unique_lock<std::shared_timed_mutex> lock_right_neighbor(
        _mu_right_neighbor);
    if (!other.right_neighbor()) {
      throw std::invalid_argument(
          "HasRightNeighbor: right_neighbor is null in copy");
    }
    _right_neighbor = std::make_shared<device_structures::Connection>(
        *other.right_neighbor());
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
