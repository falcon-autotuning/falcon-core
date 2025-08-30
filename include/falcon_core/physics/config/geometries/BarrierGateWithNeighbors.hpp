#pragma once

#include "falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp"
namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
/*
 * @brief A special barrier with two neighbor gates.
 */
class BarrierGateWithNeighbors : public DotGateWithNeighbors {
 public:
  BarrierGateWithNeighbors(std::string                         name,
                           device_structures::BaseConnectionSP left_neighbor,
                           device_structures::BaseConnectionSP right_neighbor);

 protected:
  BarrierGateWithNeighbors();
  friend class cereal::access;
};
using BarrierGateWithNeighborsSP = std::shared_ptr<BarrierGateWithNeighbors>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
