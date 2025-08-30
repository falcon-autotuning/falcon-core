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
  HasLeftNeighbor(device_structures::BaseConnectionSP left_neighbor)
      : _left_neighbor(left_neighbor) {}

  /**
   * @brief Returns the left neighbor of the gate.
   */
  device_structures::BaseConnectionSP left_neighbor() const {
    return _left_neighbor;
  }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _left_neighbor);
  }

 protected:
  HasLeftNeighbor() : _left_neighbor(nullptr) {};
  friend class cereal::access;
};
using HasLeftNeighborSP = std::shared_ptr<HasLeftNeighbor>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core

#ifndef SWIG
using namespace falcon_core::physics::config::geometries;
CEREAL_REGISTER_TYPE(HasLeftNeighbor)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     HasLeftNeighbor)
#endif
