#pragma once

#include <memory>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/Gate.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {

/*
 * @brief A gate with a right neighbor.
 */
template <typename RightNeighbor>
class HasRightNeighbor : public virtual generic::Song {
  static_assert(std::is_base_of<device_structures::Gate, RightNeighbor>::value,
                "RightNeighbor must be derived from device_structures::Gate");
  std::shared_ptr<RightNeighbor> _right_neighbor;

 public:
  HasRightNeighbor(std::shared_ptr<RightNeighbor> right_neighbor)
      : _right_neighbor(right_neighbor) {}

  /**
   * @brief Returns the right neighbor of the gate.
   */
  std::shared_ptr<RightNeighbor> right_neighbor() const {
    return _right_neighbor;
  }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _right_neighbor);
  }

 protected:
  HasRightNeighbor() : _right_neighbor(nullptr) {};
  friend class cereal::access;
};
using HasRightNeighborSP =
    std::shared_ptr<HasRightNeighbor<device_structures::Gate>>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core

#ifndef SWIG
using namespace falcon_core::physics::config::geometries;
using HRN = HasRightNeighbor<falcon_core::physics::device_structures::Gate>;
CEREAL_REGISTER_TYPE(HRN)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, HRN)
#endif
