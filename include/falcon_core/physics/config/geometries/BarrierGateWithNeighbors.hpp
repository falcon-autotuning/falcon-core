#pragma once

#include "falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp"
namespace falcon_core::physics::config::geometries {
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
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<DotGateWithNeighbors>(this));
  }
};
using BarrierGateWithNeighborsSP = std::shared_ptr<BarrierGateWithNeighbors>;
}  // namespace falcon_core::physics::config::geometries
