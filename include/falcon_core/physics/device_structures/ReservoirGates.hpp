#pragma once

#include "falcon_core/physics/device_structures/BaseConnections.hpp"
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
class ReservoirGates : public BaseConnections<T> {
  static_assert(std::is_base_of<ReservoirGate, T>::value,
                "T must be derived from ReservoirGate");

 public:
  using BaseConnections<T>::BaseConnections;

 private:
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseConnections<T>>(this));
  }

 protected:
  ReservoirGates() = default;
  friend class cereal::access;
};

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
