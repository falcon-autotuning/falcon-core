#pragma once

#include "falcon_core/physics/device_structures/DotGate.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
/*
 * @brief A barrier gate on a quantum dot device.
 */
class BarrierGate : public DotGate {
 public:
  BarrierGate(std::string name) : DotGate(std::move(name)) {}
  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<DotGate>(this));
  }

 protected:
  BarrierGate() = default;  // or initialize _name with a default value

  friend class cereal::access;
};
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::BarrierGate)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::DotGate,
    falcon_core::physics::device_structures::BarrierGate)
#endif
