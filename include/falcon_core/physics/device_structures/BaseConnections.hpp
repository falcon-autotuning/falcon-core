#pragma once

#include <cereal/archives/json.hpp>
#include <memory>

#include "falcon_core/physics/device_structures/BaseConnection.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A serializable vector of BaseConnection pointers, also a Song.
 *
 * Uses composition: contains a vector of shared_ptr<T>.
 */
template <typename T>
class BaseConnections : public virtual falcon_core::generic::Song {
  static_assert(std::is_base_of<BaseConnection, T>::value,
                "T must be derived from BaseConnection");

 private:
  std::vector<std::shared_ptr<T>> _items;

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
  BaseConnections(size_t count) : _items(count) {}
  BaseConnections(size_t count, const std::shared_ptr<T>& value)
      : _items(count, value) {}
  BaseConnections(const std::vector<std::shared_ptr<T>>& vec) : _items(vec) {}
  BaseConnections(std::initializer_list<std::shared_ptr<T>> init)
      : _items(init) {}

  // Forwarding methods
  void   push_back(const std::shared_ptr<T>& item) { _items.push_back(item); }
  size_t size() const { return _items.size(); }
  std::shared_ptr<T>       at(const size_t idx) const { return _items.at(idx); }
  const std::shared_ptr<T> operator[](const size_t idx) const {
    return _items[idx];
  }
  const std::shared_ptr<std::vector<std::shared_ptr<T>>>& items() const {
    return _items;
  }
  std::shared_ptr<std::vector<std::shared_ptr<T>>>&  items() { return _items; }
  typename std::vector<std::shared_ptr<T>>::iterator begin() {
    return _items.begin();
  }
  typename std::vector<std::shared_ptr<T>>::iterator end() {
    return _items.end();
  }
  typename std::vector<std::shared_ptr<T>>::const_iterator begin() const {
    return _items.begin();
  }
  typename std::vector<std::shared_ptr<T>>::const_iterator end() const {
    return _items.end();
  }
  void insert(typename std::vector<std::shared_ptr<T>>::iterator       pos,
              typename std::vector<std::shared_ptr<T>>::const_iterator first,
              typename std::vector<std::shared_ptr<T>>::const_iterator last) {
    _items.insert(pos, first, last);
  }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _items);
  }

 protected:
  friend class cereal::access;
};
template <typename T>
using BaseConnectionsSP = std::shared_ptr<BaseConnections<T>>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG

CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::BaseConnections<
                     falcon_core::physics::device_structures::BaseConnection>)

CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::device_structures::BaseConnections<
        falcon_core::physics::device_structures::BaseConnection>)
#endif
