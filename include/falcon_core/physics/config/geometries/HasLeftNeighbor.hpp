#pragma once

#include <memory>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/Gate.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {

/*
 * @brief A gate with a left neighbor.
 */
template <typename LeftNeighbor>
class HasLeftNeighbor : public virtual generic::Song {
  static_assert(std::is_base_of<device_structures::Gate, LeftNeighbor>::value,
                "LeftNeighbor must be derived from device_structures::Gate");
  std::shared_ptr<LeftNeighbor> _left_neighbor;

 public:
  HasLeftNeighbor(std::shared_ptr<LeftNeighbor> left_neighbor)
      : _left_neighbor(left_neighbor) {}

  /**
   * @brief Returns the left neighbor of the gate.
   */
  std::shared_ptr<LeftNeighbor> left_neighbor() const { return _left_neighbor; }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _left_neighbor);
  }

 protected:
  HasLeftNeighbor() : _left_neighbor(nullptr) {};
  friend class cereal::access;
};
using HasLeftNeighborSP =
    std::shared_ptr<HasLeftNeighbor<device_structures::Gate>>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core

#ifndef SWIG
using namespace falcon_core::physics::config::geometries;
using HLN = HasLeftNeighbor<falcon_core::physics::device_structures::Gate>;
CEREAL_REGISTER_TYPE(HLN)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, HLN)
#endif
