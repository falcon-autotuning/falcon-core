#pragma once

#include "falcon_core/physics/device_structures/Gate.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

/*
 * @brief A dot gate on a quantum dot device.
 */
class DotGate : public Gate {
  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<Gate>(this));
  }

 public:
  DotGate(std::string name) : Gate(std::move(name)) {}
};
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
