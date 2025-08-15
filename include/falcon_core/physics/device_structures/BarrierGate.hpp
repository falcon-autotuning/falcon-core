#pragma once

#include "falcon_core/physics/device_structures/DotGate.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
/*
 * @brief A barrier gate on a quantum dot device.
 */
class BarrierGate : public DotGate {
  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<DotGate>(this));
  }

 public:
  BarrierGate(std::string name) : DotGate(std::move(name)) {}
};
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
