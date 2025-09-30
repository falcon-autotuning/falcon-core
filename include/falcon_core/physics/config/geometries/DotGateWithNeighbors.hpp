#pragma once

#include "falcon_core/physics/config/geometries/HasLeftNeighbor.hpp"
#include "falcon_core/physics/config/geometries/HasRightNeighbor.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"

namespace falcon_core::physics::config::geometries {

class DotGateWithNeighbors : public device_structures::Connection,
                             public HasLeftNeighbor,
                             public HasRightNeighbor {
 public:
  DotGateWithNeighbors(std::string                      name,
                       device_structures::DeviceFeature type,
                       device_structures::ConnectionSP  left_neighbor,
                       device_structures::ConnectionSP  right_neighbor);
  bool operator==(const DotGateWithNeighbors& other) const;
  bool operator!=(const DotGateWithNeighbors& other) const;

 protected:
  DotGateWithNeighbors();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Connection>(this));
    ar(cereal::base_class<HasLeftNeighbor>(this));
    ar(cereal::base_class<HasRightNeighbor>(this));
  }
};
using DotGateWithNeighborsSP = std::shared_ptr<DotGateWithNeighbors>;

}  // namespace falcon_core::physics::config::geometries
