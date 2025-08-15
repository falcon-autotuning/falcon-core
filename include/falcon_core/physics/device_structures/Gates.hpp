#pragma once

#include "falcon_core/physics/device_structures/BaseConnections.hpp"
#include "falcon_core/physics/device_structures/Gate.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A serializable vector of Gate pointers, also a Song.
 *
 * Supports all std::vector methods and cereal serialization.
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
};

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
