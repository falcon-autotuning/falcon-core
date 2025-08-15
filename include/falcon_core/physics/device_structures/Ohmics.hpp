#pragma once

#include "falcon_core/physics/device_structures/BaseConnections.hpp"
#include "falcon_core/physics/device_structures/Ohmic.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A serializable vector of Ohmic pointers, also a Song.
 *
 * Supports all std::vector methods and cereal serialization.
 */
template <typename T>
class Ohmics : public BaseConnections<T> {
  static_assert(std::is_base_of<Ohmic, T>::value,
                "T must be derived from Ohmic");

 public:
  using BaseConnections<T>::BaseConnections;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseConnections<T>>(this));
  }

 protected:
  Ohmics() = default;  // or initialize _name with a default value
  friend class cereal::access;
};

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
