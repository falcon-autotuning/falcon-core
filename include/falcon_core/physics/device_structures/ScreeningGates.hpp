#pragma once

#include "falcon_core/physics/device_structures/Gates.hpp"
#include "falcon_core/physics/device_structures/ScreeningGate.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A serializable vector of ScreeningGate pointers, also a Song.
 *
 * Supports all std::vector methods and cereal serialization.
 */
template <typename T>
class ScreeningGates : public Gates<T> {
  static_assert(std::is_base_of<ScreeningGate, T>::value,
                "T must be derived from ScreeningGate");

 public:
  using Gates<T>::Gates;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Gates<T>>(this));
  }

 protected:
  ScreeningGates() = default;  // or initialize _name with a default value
  friend class cereal::access;
};

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
