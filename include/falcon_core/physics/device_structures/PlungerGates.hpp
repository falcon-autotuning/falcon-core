#pragma once

#include "falcon_core/physics/device_structures/DotGates.hpp"
#include "falcon_core/physics/device_structures/PlungerGate.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A serializable vector of PlungerGate pointers, also a Song.
 *
 * Supports all std::vector methods and cereal serialization.
 */
template <typename T>
class PlungerGates : public DotGates<T> {
  static_assert(std::is_base_of<PlungerGate, T>::value,
                "T must be derived from PlungerGate");

 public:
  using DotGates<T>::DotGates;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<DotGates<T>>(this));
  }

 protected:
  PlungerGates() = default;  // or initialize _name with a default value
  friend class cereal::access;
};

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
