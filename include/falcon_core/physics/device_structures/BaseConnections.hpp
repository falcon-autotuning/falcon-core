#pragma once

#include <cereal/archives/json.hpp>
#include <memory>

#include "falcon_core/generic/List.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A serializable vector of BaseConnection pointers, also a Song.
 *
 * Uses composition: contains a vector of shared_ptr<T>.
 */
template <typename Conn, typename Derived = void>
class BaseConnections
    : public virtual falcon_core::generic::List<Conn, Derived> {
  static_assert(std::is_base_of<BaseConnection, Conn>::value,
                "Conn must be derived from BaseConnection");

 public:
  /**
   * @brief BaseConnections can be constructed in 5 different ways:
   *
   * - Default constructor: creates an empty BaseConnections container.
   *   @code
   *   BaseConnections o;
   *   @endcode
   *
   * - Sized constructor: creates an BaseConnections container with a given
   * number of default-initialized elements.
   *   @param count Number of elements.
   *   @code
   *   BaseConnections o(10);
   *   @endcode
   *
   * - Fill constructor: creates an BaseConnections container with a given
   * number of copies of a specified value.
   *   @param count Number of elements.
   *   @param value Value to copy.
   *   @code
   *   BaseConnections o(10, someBaseConnectionsP);
   *   @endcode
   *
   * - Vector constructor: creates an BaseConnections container from an existing
   * vector of BaseConnectionSP.
   *   @param vec Vector of BaseConnectionSP to copy.
   *   @code
   *   std::vector<BaseConnectionsP> v = ...;
   *   BaseConnections o(v);
   *   @endcode
   * - Initializer list constructor: creates a BaseConnections container
   *from an initializer list of shared pointers.
   *   @param init Initializer list of shared_ptr<T> to copy.
   *   @code
   *   BaseConnections o{ptr1, ptr2, ptr3};
   *   @endcode
   */
  BaseConnections() = default;
  BaseConnections(size_t count) : generic::List<Conn, Derived>(count) {}
  BaseConnections(size_t count, const std::shared_ptr<Conn>& value)
      : falcon_core::generic::List<Conn, Derived>(count, value) {}
  BaseConnections(const std::vector<std::shared_ptr<Conn>>& vec)
      : generic::List<Conn, Derived>(vec) {}

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::List<Conn, Derived>>(this));
  }

 protected:
  friend class cereal::access;
};
using BaseConnectionsSP = std::shared_ptr<BaseConnections<BaseConnection>>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(falcon_core::generic::List<BaseConnection>)
CEREAL_REGISTER_TYPE(BaseConnections<BaseConnection>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::generic::List<BaseConnection>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     BaseConnections<BaseConnection>)
#endif
