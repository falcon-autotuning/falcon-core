#pragma once

#include "falcon_core/physics/config/geometries/HasLeftNeighbor.hpp"
#include "falcon_core/physics/config/geometries/HasRightNeighbor.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {

// Template implementation
class DotGateWithNeighbors : public device_structures::BaseConnection,
                             public HasLeftNeighbor,
                             public HasRightNeighbor {
 public:
  DotGateWithNeighbors(std::string                         name,
                       device_structures::DeviceFeature    type,
                       device_structures::BaseConnectionSP left_neighbor,
                       device_structures::BaseConnectionSP right_neighbor);

  template <class Archive>
  void serialize(Archive& ar);

 protected:
  DotGateWithNeighbors();
  friend class cereal::access;
};
using DotGateWithNeighborsSP = std::shared_ptr<DotGateWithNeighbors>;

}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
