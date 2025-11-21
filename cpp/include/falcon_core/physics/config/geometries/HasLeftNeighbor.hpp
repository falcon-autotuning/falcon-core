#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {

/**
 * @brief A gate with a left neighbor.
 */
class HasLeftNeighbor : public virtual generic::Song {
  device_structures::ConnectionSP _left_neighbor;

 public:
  HasLeftNeighbor(device_structures::ConnectionSP left_neighbor);

  /**
   * @brief Returns the left neighbor of the gate.
   */
  device_structures::ConnectionSP left_neighbor() const;

 protected:
  HasLeftNeighbor();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _left_neighbor);
  }
};
using HasLeftNeighborSP = std::shared_ptr<HasLeftNeighbor>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
