#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"

namespace falcon_core::physics::config::geometries {

/*
 * @brief A gate with a right neighbor.
 */
class HasRightNeighbor : public virtual generic::Song {
  device_structures::ConnectionSP _right_neighbor;

 public:
  HasRightNeighbor(device_structures::ConnectionSP right_neighbor);

  /**
   * @brief Returns the right neighbor of the gate.
   */
  device_structures::ConnectionSP right_neighbor() const;

 protected:
  HasRightNeighbor();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _right_neighbor);
  }
};
using HasRightNeighborSP = std::shared_ptr<HasRightNeighbor>;
}  // namespace falcon_core::physics::config::geometries
