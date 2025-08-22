#pragma once

#include "falcon_core/physics/device_structures/DotGate.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
/*
 * @brief A plunger gate on a quantum dot device.
 */
class PlungerGate : public DotGate {
 public:
  using DotGate::DotGate;
  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<DotGate>(this));
  }

 protected:
  PlungerGate() = default;  // or initialize _name with a default value

  friend class cereal::access;
};
using PlungerGateSP = std::shared_ptr<PlungerGate>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(PlungerGate)
CEREAL_REGISTER_POLYMORPHIC_RELATION(DotGate, PlungerGate)
#endif
