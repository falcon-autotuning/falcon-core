#pragma once

#include <cereal/archives/json.hpp>

#include "falcon_core/physics/device_structures/BaseConnection.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A serializable vector of BaseConnection pointers, also a Song.
 *
 * Supports all std::vector methods and cereal serialization.
 */
template <typename T>
class BaseConnections : public std::vector<std::shared_ptr<T>>,
                        public falcon_core::generic::Song {
  static_assert(std::is_base_of<BaseConnection, T>::value,
                "T must be derived from BaseConnection");

 public:
  using std::vector<std::shared_ptr<T>>::vector;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this),
       cereal::base_class<std::vector<std::shared_ptr<T>>>(this));
  }

 protected:
  BaseConnections() = default;  // or initialize _name with a default value
  friend class cereal::access;
};

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::BaseConnections<
                     falcon_core::physics::device_structures::BaseConnection>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::device_structures::BaseConnections<
        falcon_core::physics::device_structures::BaseConnection>)
