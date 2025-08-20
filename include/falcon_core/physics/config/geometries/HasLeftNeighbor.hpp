#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/Gate.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
/*
 * @brief A gate with a left neighbor.
 */
class HasLeftNeighbor : public generic::Song {
  device_structures::GateSP _left_neighbor;

 public:
  HasLeftNeighbor(device_structures::GateSP left_neighbor)
      : _left_neighbor(left_neighbor) {}
  /**
   * @brief Returns the left neighbor of the gate.
   */
  device_structures::GateSP left_neighbor() const { return _left_neighbor; }
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<HasLeftNeighbor>(this), _left_neighbor);
  }

 protected:
  HasLeftNeighbor() : _left_neighbor(nullptr) {};
  friend class cereal::access;
};
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
