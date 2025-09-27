#include "falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp"

#include <stdexcept>

#include "falcon_core/physics/config/geometries/HasLeftNeighbor.hpp"
namespace falcon_core::physics::config::geometries {
DotGateWithNeighbors::DotGateWithNeighbors() = default;
DotGateWithNeighbors::DotGateWithNeighbors(
    std::string                      name,
    device_structures::DeviceFeature type,
    device_structures::ConnectionSP  left_neighbor,
    device_structures::ConnectionSP  right_neighbor)
    : Connection(name, type),
      HasLeftNeighbor(left_neighbor),
      HasRightNeighbor(right_neighbor) {
  if (!is_dot_gate()) {
    throw std::invalid_argument(
        "DotGateWithNeighbors: This must be a dot gate. Be careful during "
        "instantiation");
  }
}

}  // namespace falcon_core::physics::config::geometries
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::DotGateWithNeighbors)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::Connection,
    falcon_core::physics::config::geometries::DotGateWithNeighbors)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::config::geometries::HasLeftNeighbor,
    falcon_core::physics::config::geometries::DotGateWithNeighbors)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::config::geometries::HasRightNeighbor,
    falcon_core::physics::config::geometries::DotGateWithNeighbors)
