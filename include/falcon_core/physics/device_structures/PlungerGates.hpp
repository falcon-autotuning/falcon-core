#pragma once

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/physics/device_structures/DotGates.hpp"
#include "falcon_core/physics/device_structures/PlungerGate.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A collection of PlungerGates.
 */
class PlungerGates : public DotGates<PlungerGate> {
 public:
  using DotGates<PlungerGate>::DotGates;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<DotGates<PlungerGate>>(this));
  }

 protected:
  friend class cereal::access;
};
using PlungerGatesSP = std::shared_ptr<PlungerGates>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(PlungerGates)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, PlungerGates)
#endif
