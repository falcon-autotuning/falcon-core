#pragma once

#include "falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp"
#include "falcon_core/physics/device_structures/BarrierGate.hpp"
#include "falcon_core/physics/device_structures/PlungerGate.hpp"
namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
/*
 * @brief A special plunger gate with two neighbor barrier gates.
 */
class PlungerGateWithNeighbors
    : public DotGateWithNeighbors<BarrierGate, PlungerGate, BarrierGate> {
 public:
  PlungerGateWithNeighbors(std::string   name,
                           BarrierGateSP left_neighbor,
                           BarrierGateSP right_neighbor);
  template <class Archive>
  void serialize(Archive& ar);

 protected:
  PlungerGateWithNeighbors();
  friend class cereal::access;
};
using PlungerGateWithNeighborsSP = std::shared_ptr<PlungerGateWithNeighbors>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
