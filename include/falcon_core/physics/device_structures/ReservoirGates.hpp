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

 private:
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Gates<T>>(this));
  }

 protected:
  ReservoirGates() = default;
  friend class cereal::access;
};

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
