#include "falcon_core/physics/config/geometries/BaseDotGateWithNeighbors.hpp"
namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
BaseDotGateWithNeighbors::BaseDotGateWithNeighbors() = default;
BaseDotGateWithNeighbors::BaseDotGateWithNeighbors(std::string name)
    : device_structures::DotGate(std::move(name)) {}

}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::BaseDotGateWithNeighbors)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::Gate,
    falcon_core::physics::config::geometries::BaseDotGateWithNeighbors)
