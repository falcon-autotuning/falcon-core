#pragma once

#include "falcon_core/physics/device_structures/BarrierGate.hpp"
#include "falcon_core/physics/device_structures/DotGates.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A collection of BarrierGates.
 */
class BarrierGates : public DotGates<BarrierGate> {
 public:
  using DotGates<BarrierGate>::DotGates;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<DotGates<BarrierGate>>(this));
  }

 protected:
  friend class cereal::access;
};
using BarrierGatesSP = std::shared_ptr<BarrierGates>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(BarrierGates)
CEREAL_REGISTER_POLYMORPHIC_RELATION(DotGates<BarrierGate>, BarrierGates)
#endif
