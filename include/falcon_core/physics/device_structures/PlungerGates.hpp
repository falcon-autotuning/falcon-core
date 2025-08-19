#pragma once

#include "falcon_core/physics/device_structures/DotGates.hpp"
#include "falcon_core/physics/device_structures/PlungerGate.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A serializable vector of PlungerGate pointers, also a Song.
 *
 * Uses composition: contains a vector of shared_ptr<T>.
 */
template <typename T>
class PlungerGates : public falcon_core::generic::Song {
  static_assert(std::is_base_of<PlungerGate, T>::value,
                "T must be derived from PlungerGate");

 private:
  std::vector<std::shared_ptr<T>> _items;

 public:
  PlungerGates() = default;

  // Forwarding methods
  void push_back(const std::shared_ptr<T>& item) { _items.push_back(item); }
  size_t size() const { return _items.size(); }
  std::shared_ptr<T> at(size_t idx) const { return _items.at(idx); }
  const std::vector<std::shared_ptr<T>>& items() const { return _items; }
  std::vector<std::shared_ptr<T>>& items() { return _items; }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _items);
  }

 protected:
  friend class cereal::access;
};

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::PlungerGates<falcon_core::physics::device_structures::PlungerGate>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::physics::device_structures::DotGates<falcon_core::physics::device_structures::DotGate>, falcon_core::physics::device_structures::PlungerGates<falcon_core::physics::device_structures::PlungerGate>)
