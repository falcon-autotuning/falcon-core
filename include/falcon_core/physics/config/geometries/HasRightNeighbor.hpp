#pragma once

#include <memory>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {

/*
 * @brief A gate with a right neighbor.
 */
class HasRightNeighbor : public virtual generic::Song {
  device_structures::BaseConnectionSP _right_neighbor;

 public:
  HasRightNeighbor(device_structures::BaseConnectionSP right_neighbor);

  /**
   * @brief Returns the right neighbor of the gate.
   */
  device_structures::BaseConnectionSP right_neighbor() const;

  template <class Archive>
  void serialize(Archive& ar);

 protected:
  HasRightNeighbor();
  friend class cereal::access;
};
using HasRightNeighborSP = std::shared_ptr<HasRightNeighbor>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
