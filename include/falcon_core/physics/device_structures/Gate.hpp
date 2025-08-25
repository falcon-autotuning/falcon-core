#pragma once

#include "falcon_core/physics/device_structures/BaseConnection.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
/*
 * @brief A gate on a quantum dot device.
 */
class Gate : public BaseConnection {
 public:
  Gate(std::string name) : BaseConnection(std::move(name)) {}
  Gate() : BaseConnection("") {}
  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<BaseConnection>(this));
  }

 protected:
  friend class cereal::access;
};
using GateSP = std::shared_ptr<Gate>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::Gate)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::BaseConnection,
    falcon_core::physics::device_structures::Gate)
#endif
