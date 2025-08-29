#pragma once

#include "falcon_core/physics/device_structures/BaseConnections.hpp"
#include "falcon_core/physics/device_structures/Gate.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A serializable vector of Gate pointers, also a Song.
 *
 * Uses composition: contains a vector of shared_ptr<T>.
 */
template <typename T, typename Derived = void>
class Gates : public BaseConnections<T, Derived> {
  static_assert(std::is_base_of<Gate, T>::value, "T must be derived from Gate");

 public:
  Gates() = default;
  Gates(size_t count) : BaseConnections<T, Derived>(count) {}
  Gates(size_t count, const std::shared_ptr<T>& value)
      : BaseConnections<T, Derived>(count, value) {}
  Gates(const std::vector<std::shared_ptr<T>>& vec)
      : BaseConnections<T, Derived>(vec) {}

  template <
      typename U,
      typename = typename std::enable_if<std::is_base_of<T, U>::value>::type>
  Gates(const std::vector<std::shared_ptr<U>>& vec)
      : BaseConnections<T, Derived>(vec) {}
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseConnections<T, Derived>>(this));
  }

 protected:
  friend class cereal::access;
};
using GatesSP = std::shared_ptr<Gates<Gate>>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::Gates<
                     falcon_core::physics::device_structures::Gate>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::BaseConnections<
        falcon_core::physics::device_structures::Gate>,
    falcon_core::physics::device_structures::Gates<
        falcon_core::physics::device_structures::Gate>)
#endif
