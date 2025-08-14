#pragma once

#include "falcon_core/physics/device_structures/BaseConnections.hpp"
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
class ScreeningGates : public BaseConnections<T> {
  static_assert(std::is_base_of<ScreeningGate, T>::value,
                "T must be derived from ScreeningGate");

 public:
  using BaseConnections<T>::BaseConnections;

 private:
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseConnections<T>>(this));
  }

 protected:
  ScreeningGates() = default;
  friend class cereal::access;
};

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
