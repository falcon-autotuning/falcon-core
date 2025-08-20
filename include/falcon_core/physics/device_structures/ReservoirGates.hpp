#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/Gates.hpp"
#include "falcon_core/physics/device_structures/ReservoirGate.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A serializable vector of ReservoirGate pointers, also a Song.
 *
 * Uses composition: contains a vector of shared_ptr<T>.
 */
template <typename T>
class ReservoirGates : public Gates<T> {
  static_assert(std::is_base_of<ReservoirGate, T>::value,
                "T must be derived from ReservoirGate");

 private:
  std::vector<std::shared_ptr<T>> _items;

 public:
  ReservoirGates() = default;

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
template <typename T>
struct ReservoirGatesSP {
  typedef std::shared_ptr<ReservoirGates<T>> type;
};
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG

using namespace falcon_core::physics::device_structures;

CEREAL_REGISTER_TYPE(ReservoirGates<ReservoirGate>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     ReservoirGates<ReservoirGate>)
#endif
