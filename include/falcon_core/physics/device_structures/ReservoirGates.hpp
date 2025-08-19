#pragma once

#include "falcon_core/physics/device_structures/Gates.hpp"
#include "falcon_core/physics/device_structures/ReservoirGate.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A serializable vector of ReservoirGate pointers, also a Song.
 *
 * Supports all std::vector methods and cereal serialization.
 */
template <typename T>
class ReservoirGates : public Gates<T> {
  static_assert(std::is_base_of<ReservoirGate, T>::value,
                "T must be derived from ReservoirGate");

 public:
  using Gates<T>::Gates;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Gates<T>>(this));
  }

 protected:
  ReservoirGates() = default;  // or initialize _name with a default value
  friend class cereal::access;
};

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::ReservoirGates<falcon_core::physics::device_structures::ReservoirGate>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::physics::device_structures::Gates<falcon_core::physics::device_structures::Gate>, falcon_core::physics::device_structures::ReservoirGates<falcon_core::physics::device_structures::ReservoirGate>)
