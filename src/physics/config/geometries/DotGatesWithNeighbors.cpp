#include "falcon_core/physics/config/geometries/DotGatesWithNeighbors.hpp"

#include <algorithm>

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {

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
DotGatesWithNeighbors::DotGatesWithNeighbors(
    const std::vector<device_structures::BarrierGateSP>& vec)
    : generic::List<DotGateWithNeighbors, DotGatesWithNeighbors>([&vec] {
        std::vector<DotGateWithNeighborsSP> base_vec;
        base_vec.reserve(vec.size());
        for (auto& g : vec)
          base_vec.push_back(std::static_pointer_cast<DotGateWithNeighbors>(g));
        return base_vec;
      }()) {}

DotGatesWithNeighbors::DotGatesWithNeighbors(
    const std::vector<device_structures::PlungerGateSP>& vec)
    : generic::List<DotGateWithNeighbors, DotGatesWithNeighbors>([&vec] {
        std::vector<DotGateWithNeighborsSP> base_vec;
        base_vec.reserve(vec.size());
        for (auto& g : vec)
          base_vec.push_back(std::static_pointer_cast<DotGateWithNeighbors>(g));
        return base_vec;
      }()) {}

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

template <class Archive>
void DotGatesWithNeighbors::serialize(Archive& ar) {
  ar(cereal::base_class<
      generic::List<DotGateWithNeighbors, DotGatesWithNeighbors>>(this));
}

}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::DotGatesWithNeighbors)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<
        falcon_core::physics::config::geometries::DotGateWithNeighbors>,
    falcon_core::physics::config::geometries::DotGatesWithNeighbors)
