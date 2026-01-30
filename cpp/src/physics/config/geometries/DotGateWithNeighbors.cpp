#include "falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp"

#include <stdexcept>

#include "falcon_core/physics/config/geometries/HasLeftNeighbor.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
DotGateWithNeighbors::DotGateWithNeighbors(const DotGateWithNeighbors& other)
    : Connection(other), HasLeftNeighbor(other), HasRightNeighbor(other) {}

DotGateWithNeighbors& DotGateWithNeighbors::operator=(
    const DotGateWithNeighbors& other) {
  if (this != &other) {
    Connection::operator=(other);
    HasLeftNeighbor::operator=(other);
    HasRightNeighbor::operator=(other);
  }
  return *this;
}

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
DotGateWithNeighborsSP DotGateWithNeighbors::BarrierGateWithNeighbors(
    std::string                     name,
    device_structures::ConnectionSP left_neighbor,
    device_structures::ConnectionSP right_neighbor) {
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
        "BarrierGateWithNeighbors: The right_neighbor can only be a "
        "ReservoirGate or a PlungerGate, not "
        "a " +
        right_neighbor->type());
  }
  return std::make_shared<DotGateWithNeighbors>(
      DotGateWithNeighbors(name,
                           device_structures::DeviceFeature::BarrierGate,
                           left_neighbor,
                           right_neighbor));
}
DotGateWithNeighborsSP DotGateWithNeighbors::PlungerGateWithNeighbors(
    std::string                     name,
    device_structures::ConnectionSP left_neighbor,
    device_structures::ConnectionSP right_neighbor) {
  if (!(left_neighbor->is_barrier_gate() &&
        right_neighbor->is_barrier_gate())) {
    throw std::invalid_argument(
        "PlungerGateWithNeighbors: The neighbors can only be a "
        "BarrierGate, not "
        "on the left " +
        left_neighbor->type() + " and on the right " + right_neighbor->type());
  }
  return std::make_shared<DotGateWithNeighbors>(
      DotGateWithNeighbors(name,
                           device_structures::DeviceFeature::PlungerGate,
                           left_neighbor,
                           right_neighbor));
}
bool DotGateWithNeighbors::operator==(const DotGateWithNeighbors& other) const {
  if (this == &other) return true;
  return Connection::operator==(other) &&
         (*left_neighbor() == *other.left_neighbor()) &&
         (*right_neighbor() == *other.right_neighbor());
}
bool DotGateWithNeighbors::operator!=(const DotGateWithNeighbors& other) const {
  return !(*this == other);
}

}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
