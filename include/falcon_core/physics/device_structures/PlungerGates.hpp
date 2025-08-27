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
class PlungerGates : public DotGates<PlungerGate, PlungerGates> {
 public:
  PlungerGates() = default;
  PlungerGates(size_t count) : DotGates<PlungerGate, PlungerGates>(count) {}
  PlungerGates(size_t count, const PlungerGateSP& value)
      : DotGates<PlungerGate, PlungerGates>(count, value) {}
  PlungerGates(const std::vector<PlungerGateSP>& vec)
      : DotGates<PlungerGate, PlungerGates>(vec) {}
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<DotGates<PlungerGate, PlungerGates>>(this));
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
