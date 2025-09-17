#include "falcon_core/physics/config/geometries/DotGatesWithNeighbors.hpp"

namespace falcon_core::physics::config::geometries {

DotGatesWithNeighbors::DotGatesWithNeighbors() = default;
DotGatesWithNeighbors::DotGatesWithNeighbors(size_t count)
    : generic::List<DotGateWithNeighbors, DotGatesWithNeighbors>(count) {}
DotGatesWithNeighbors::DotGatesWithNeighbors(
    size_t count, const DotGateWithNeighborsSP& value)
    : generic::List<DotGateWithNeighbors, DotGatesWithNeighbors>(count, value) {
}
DotGatesWithNeighbors::DotGatesWithNeighbors(
    const std::vector<DotGateWithNeighborsSP>& vec)
    : generic::List<DotGateWithNeighbors, DotGatesWithNeighbors>(vec) {}

bool DotGatesWithNeighbors::is_plunger_gates() const {
  return std::all_of(
      this->begin(), this->end(), [](const DotGateWithNeighborsSP& conn) {
        return conn->is_plunger_gate();
      });
}
bool DotGatesWithNeighbors::is_barrier_gates() const {
  return std::all_of(
      this->begin(), this->end(), [](const DotGateWithNeighborsSP& conn) {
        return conn->is_barrier_gate();
      });
}

}  // namespace falcon_core::physics::config::geometries
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::DotGatesWithNeighbors)
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<
        falcon_core::physics::config::geometries::DotGatesWithNeighbors>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<
        falcon_core::physics::config::geometries::DotGateWithNeighbors>,
    falcon_core::physics::config::geometries::DotGatesWithNeighbors)
