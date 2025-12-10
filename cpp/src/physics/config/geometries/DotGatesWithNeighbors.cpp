#include "falcon_core/physics/config/geometries/DotGatesWithNeighbors.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {

DotGatesWithNeighbors::DotGatesWithNeighbors() = default;
DotGatesWithNeighbors::DotGatesWithNeighbors(
    const std::vector<DotGateWithNeighborsSP>& vec)
    : generic::List<DotGateWithNeighbors>(vec) {}

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
bool DotGatesWithNeighbors::operator==(
    const DotGatesWithNeighbors& other) const {
  if (size() != other.size()) {
    return false;
  }
  for (size_t i = 0; i < size(); i++) {
    const StoredValue our_conn   = this->at(i);
    const StoredValue other_conn = other.at(i);
    if (*our_conn != *other_conn) {
      return false;
    }
  }
  return true;
}
bool DotGatesWithNeighbors::operator!=(
    const DotGatesWithNeighbors& other) const {
  return !(*this == other);
}

}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::DotGatesWithNeighbors)
CEREAL_REGISTER_TYPE(
    falcon_core::generic::List<
        falcon_core::physics::config::geometries::DotGatesWithNeighbors>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<
        falcon_core::physics::config::geometries::DotGateWithNeighbors>,
    falcon_core::physics::config::geometries::DotGatesWithNeighbors)
