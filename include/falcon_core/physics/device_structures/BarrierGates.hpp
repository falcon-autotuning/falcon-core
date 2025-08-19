#pragma once

#include "falcon_core/physics/device_structures/BarrierGate.hpp"
#include "falcon_core/physics/device_structures/DotGates.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A serializable vector of BarrierGate pointers, also a Song.
 *
 * Supports all std::vector methods and cereal serialization.
 */
template <typename T>
class BarrierGates : public DotGates<T> {
  static_assert(std::is_base_of<BarrierGate, T>::value,
                "T must be derived from BarrierGate");

 public:
  using DotGates<T>::DotGates;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<DotGates<T>>(this));
  }
  BarrierGates() = default;  // or initialize _name with a default value
 protected:
  friend class cereal::access;
};

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::BarrierGates<falcon_core::physics::device_structures::BarrierGate>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::physics::device_structures::DotGates<falcon_core::physics::device_structures::DotGate>, falcon_core::physics::device_structures::BarrierGates<falcon_core::physics::device_structures::BarrierGate>)
