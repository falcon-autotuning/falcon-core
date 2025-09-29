#include "falcon_core/physics/config/geometries/PlungerGateWithNeighbors.hpp"

#include "falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"

namespace falcon_core::physics::config::geometries {
PlungerGateWithNeighbors::PlungerGateWithNeighbors(
    std::string                     name,
    device_structures::ConnectionSP left_neighbor,
    device_structures::ConnectionSP right_neighbor)
    : DotGateWithNeighbors(name,
                           device_structures::DeviceFeature::PlungerGate,
                           left_neighbor,
                           right_neighbor) {
  if (!(left_neighbor->is_barrier_gate() &&
        right_neighbor->is_barrier_gate())) {
    throw std::runtime_error(
        "PlungerGateWithNeighbors: The left_neighbor can only be a "
        "BarrierGate, not "
        "a " +
        left_neighbor->type());
  }
}

PlungerGateWithNeighbors::PlungerGateWithNeighbors() = default;
}  // namespace falcon_core::physics::config::geometries
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::PlungerGateWithNeighbors)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::config::geometries::DotGateWithNeighbors,
    falcon_core::physics::config::geometries::PlungerGateWithNeighbors)
