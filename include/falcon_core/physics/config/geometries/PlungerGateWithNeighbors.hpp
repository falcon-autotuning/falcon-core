#pragma once

#include "falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp"
namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
/*
 * @brief A special barrier with two neighbor gates.
 */
class PlungerGateWithNeighbors : public DotGateWithNeighbors {
 public:
  PlungerGateWithNeighbors(std::string                         name,
                           device_structures::BaseConnectionSP left_neighbor,
                           device_structures::BaseConnectionSP right_neighbor);

 protected:
  PlungerGateWithNeighbors();
  friend class cereal::access;
};
using PlungerGateWithNeighborsSP = std::shared_ptr<PlungerGateWithNeighbors>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
