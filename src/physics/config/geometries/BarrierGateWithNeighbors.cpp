#include "falcon_core/physics/config/geometries/BarrierGateWithNeighbors.hpp"

#include <stdexcept>

#include "falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"

namespace falcon_core::physics::config::geometries {
BarrierGateWithNeighbors::BarrierGateWithNeighbors(
    std::string                     name,
    device_structures::ConnectionSP left_neighbor,
    device_structures::ConnectionSP right_neighbor)
    : DotGateWithNeighbors(name,
                           device_structures::DeviceFeature::BarrierGate,
                           left_neighbor,
                           right_neighbor) {
  if (!(left_neighbor->is_reservoir_gate() ||
        left_neighbor->is_plunger_gate())) {
    throw std::invalid_argument(
        "BarrierGateWithNeighbors: The left_neighbor can only be a "
        "ReservoirGate or a PlungerGate, not "
        "a " +
        left_neighbor->type());
  }
  if (!(right_neighbor->is_reservoir_gate() ||
        right_neighbor->is_plunger_gate())) {
    throw std::invalid_argument(
        "BarrierGateWithNeighbors: The left_neighbor can only be a "
        "ReservoirGate or a PlungerGate, not "
        "a " +
        right_neighbor->type());
  }
}

BarrierGateWithNeighbors::BarrierGateWithNeighbors() = default;
}  // namespace falcon_core::physics::config::geometries
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::BarrierGateWithNeighbors)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::config::geometries::DotGateWithNeighbors,
    falcon_core::physics::config::geometries::BarrierGateWithNeighbors)
