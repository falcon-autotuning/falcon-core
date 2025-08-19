#pragma once

#include "falcon_core/physics/device_structures/Gate.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
/*
 * @brief A reservoir gate on a quantum dot device.
 */
class ReservoirGate : public Gate {
 public:
  ReservoirGate(std::string name) : Gate(std::move(name)) {}
  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<Gate>(this));
  }

 protected:
  ReservoirGate() = default;  // or initialize _name with a default value

  friend class cereal::access;
};
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::ReservoirGate)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::physics::device_structures::Gate, falcon_core::physics::device_structures::ReservoirGate)
