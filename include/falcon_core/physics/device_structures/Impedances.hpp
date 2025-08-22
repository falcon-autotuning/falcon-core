#pragma once

#include "falcon_core/physics/device_structures/Impedance.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A collection of Impedance measurements on a quantum dot sample.
 */
class Impedances : public generic::Song {
  std::vector<ImpedanceSP> _items;

 public:
  Impedances() = default;

  // Forwarding methods
  void        push_back(const ImpedanceSP& item) { _items.push_back(item); }
  size_t      size() const { return _items.size(); }
  ImpedanceSP at(size_t idx) const { return _items.at(idx); }
  const std::vector<ImpedanceSP>& items() const { return _items; }
  std::vector<ImpedanceSP>&       items() { return _items; }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _items);
  }

 protected:
  friend class cereal::access;
};
using ImpedancesSP = std::shared_ptr<Impedances>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(Impedances)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, Impedances)
#endif
