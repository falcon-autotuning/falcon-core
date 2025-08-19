#pragma once

#include <cereal/archives/json.hpp>

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

 public:
  using Gates<T>::Gates;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Gates<T>>(this));
  }
  DotGates() = default;  // or initialize _name with a default value
 protected:
  friend class cereal::access;
};

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::DotGates<
                     falcon_core::physics::device_structures::DotGate>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::Gates<
        falcon_core::physics::device_structures::Gate>,
    falcon_core::physics::device_structures::DotGates<
        falcon_core::physics::device_structures::DotGate>)
