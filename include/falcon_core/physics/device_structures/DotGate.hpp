#pragma once

#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/device_structures/Gate.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

/*
 * @brief A dot gate on a quantum dot device.
 */
class DotGate : public Gate {
 public:
  DotGate(std::string name) : Gate(std::move(name)) {}
  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<Gate>(this));
  }

 protected:
  DotGate() = default;  // or initialize _name with a default value

  friend class cereal::access;
};
using DotGateSP = std::shared_ptr<DotGate>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG

CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::DotGate)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::Gate,
    falcon_core::physics::device_structures::DotGate)
#endif
