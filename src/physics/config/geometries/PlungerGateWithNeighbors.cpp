#include "falcon_core/physics/config/geometries/PlungerGateWithNeighbors.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
PlungerGateWithNeighbors::PlungerGateWithNeighbors() = default;
PlungerGateWithNeighbors::PlungerGateWithNeighbors(std::string   name,
                                                   BarrierGateSP left_neighbor,
                                                   BarrierGateSP right_neighbor)
    : DotGateWithNeighbors(name, left_neighbor, right_neighbor) {}
template <class Archive>
void PlungerGateWithNeighbors::serialize(Archive& ar) {
  ar(cereal::base_class<PlungerGate>(this),
     cereal::base_class<HasLeftNeighbor<BarrierGate>>(this),
     cereal::base_class<HasRightNeighbor<BarrierGate>>(this));
}

}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(PlungerGateWithNeighbors)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     PlungerGateWithNeighbors)
