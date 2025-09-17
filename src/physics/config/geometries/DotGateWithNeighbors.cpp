#include "falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp"

#include <stdexcept>
namespace falcon_core::physics::config::geometries {
DotGateWithNeighbors::DotGateWithNeighbors() = default;
DotGateWithNeighbors::DotGateWithNeighbors(
    std::string                         name,
    device_structures::DeviceFeature    type,
    device_structures::BaseConnectionSP left_neighbor,
    device_structures::BaseConnectionSP right_neighbor)
    : BaseConnection(name, type),
      HasLeftNeighbor(left_neighbor),
      HasRightNeighbor(right_neighbor) {
  if (!is_dot_gate()) {
    throw std::runtime_error(
        "This must be a dot gate. Be careful during instantiation");
  }
}

}  // namespace falcon_core::physics::config::geometries
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::DotGateWithNeighbors)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::BaseConnection,
    falcon_core::physics::config::geometries::DotGateWithNeighbors)
