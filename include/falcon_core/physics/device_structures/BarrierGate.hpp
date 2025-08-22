#pragma once

#include "falcon_core/physics/device_structures/DotGate.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
/*
 * @brief A barrier gate on a quantum dot device.
 */
class BarrierGate : public virtual DotGate {
 public:
  using DotGate::DotGate;
  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<DotGate>(this));
  }

 protected:
  BarrierGate() = default;  // or initialize _name with a default value
  friend class cereal::access;
};
using BarrierGateSP = std::shared_ptr<BarrierGate>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(BarrierGate)
CEREAL_REGISTER_POLYMORPHIC_RELATION(DotGate, BarrierGate)
#endif
