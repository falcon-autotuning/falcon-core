#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/Gates.hpp"
#include "falcon_core/physics/device_structures/ScreeningGate.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A serializable vector of ScreeningGate pointers, also a Song.
 *
 * Uses composition: contains a vector of shared_ptr<T>.
 */
template <typename T>
class ScreeningGates : public Gates<T> {
  static_assert(std::is_base_of<ScreeningGate, T>::value,
                "T must be derived from ScreeningGate");

 private:
  std::vector<std::shared_ptr<T>> _items;

 public:
  ScreeningGates() = default;

  // Forwarding methods
  void   push_back(const std::shared_ptr<T>& item) { _items.push_back(item); }
  size_t size() const { return _items.size(); }
  std::shared_ptr<T> at(size_t idx) const { return _items.at(idx); }
  const std::vector<std::shared_ptr<T>>& items() const { return _items; }
  std::vector<std::shared_ptr<T>>&       items() { return _items; }

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
#ifndef SWIG

using namespace falcon_core::physics::device_structures;

CEREAL_REGISTER_TYPE(ScreeningGates<ScreeningGate>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     ScreeningGates<ScreeningGate>)
#endif
