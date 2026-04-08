#pragma once

#include "falcon-core/export.h"
#include "falcon-core/generic/Song.hpp"
#include "falcon-core/physics/device_structures/Connection.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {

/**
 * @brief A gate with a right neighbor.
 */
class FALCON_CORE_CPP_API HasRightNeighbor : public virtual generic::Song {
  device_structures::ConnectionSP _right_neighbor;
  mutable std::shared_timed_mutex _mu_right_neighbor;

 public:
  HasRightNeighbor(const HasRightNeighbor& other);
  HasRightNeighbor& operator=(const HasRightNeighbor& other);
  HasRightNeighbor(device_structures::ConnectionSP right_neighbor);

  /**
   * @brief Returns the right neighbor of the gate.
   */
  device_structures::ConnectionSP right_neighbor() const;

 protected:
  HasRightNeighbor();
  friend class cereal::access;
  template <class Archive>
  inline void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_right_neighbor(
        _mu_right_neighbor);
    ar(cereal::base_class<generic::Song>(this), _right_neighbor);
  }
};
using HasRightNeighborSP = std::shared_ptr<HasRightNeighbor>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
