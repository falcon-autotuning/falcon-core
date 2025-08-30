#pragma once

#include <memory>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {

/*
 * @brief A gate with a left neighbor.
 */
class HasLeftNeighbor : public virtual generic::Song {
  device_structures::BaseConnectionSP _left_neighbor;

 public:
  HasLeftNeighbor(device_structures::BaseConnectionSP left_neighbor);

  /**
   * @brief Returns the left neighbor of the gate.
   */
  device_structures::BaseConnectionSP left_neighbor() const;

  template <class Archive>
  void serialize(Archive& ar);

 protected:
  HasLeftNeighbor();
  friend class cereal::access;
};
using HasLeftNeighborSP = std::shared_ptr<HasLeftNeighbor>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
