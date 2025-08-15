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
};
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
