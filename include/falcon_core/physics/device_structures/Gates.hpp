#pragma once

#include <cereal/archives/json.hpp>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/BaseConnections.hpp"
#include "falcon_core/physics/device_structures/Gate.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A serializable vector of Gate pointers, also a Song.
 *
 * Uses composition: contains a vector of shared_ptr<T>.
 */
template <typename T>
class Gates : public BaseConnections<T> {
  static_assert(std::is_base_of<Gate, T>::value, "T must be derived from Gate");

 public:
  using BaseConnections<T>::BaseConnections;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseConnections<T>>(this));
  }

 protected:
  friend class cereal::access;
};
template <typename T>
using GatesSP = std::shared_ptr<Gates<T>>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core

#ifndef SWIG

using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(Gates<Gate>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, Gates<Gate>)
#endif
