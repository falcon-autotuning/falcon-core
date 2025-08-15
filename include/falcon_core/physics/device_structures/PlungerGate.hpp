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
  PlungerGate(std::string name) : DotGate(std::move(name)) {}
  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<DotGate>(this));
  }
};
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
