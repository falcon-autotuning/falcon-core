#pragma once

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
/*
 * @brief A gate with a left neighbor.
 */
class HasLeftNeighbor : public generic::Song {
  device_structures::Gate _left_neighbor;

 public:
  HasLeftNeighbor(device_structures::Gate left_neighbor)
      : _left_neighbor(left_neighbor) {}
  /**
   * @brief Returns the left neighbor of the gate.
   */
  device_structures::Gate left_neighbor() const { return _left_neighbor; }
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<HasLeftNeighbor>(this), _left_neighbor);
  }
