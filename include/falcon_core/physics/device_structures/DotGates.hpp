#pragma once

#include "falcon_core/physics/device_structures/DotGate.hpp"
#include "falcon_core/physics/device_structures/Gates.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A serializable vector of DotGate pointers, also a Song.
 *
 * Supports all std::vector methods and cereal serialization.
 */
template <typename T>
class DotGates : public Gates<T> {
  static_assert(std::is_base_of<DotGate, T>::value,
                "T must be derived from DotGate");

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Gates<T>>(this));
  }

 public:
  using Gates<T>::Gates;
};

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
