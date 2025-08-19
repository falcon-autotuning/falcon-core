#pragma once

#include "falcon_core/physics/device_structures/BaseConnection.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
/*
 * @brief An ohmic connection on a quantum dot device.
 */
class Ohmic : public BaseConnection {
 public:
  Ohmic(std::string name) : BaseConnection(std::move(name)) {}
  template <class Archive>
  void serialize(Archive &ar) {
    ar(cereal::base_class<BaseConnection>(this));
  }

 protected:
  Ohmic() = default;  // or initialize _name with a default value

  friend class cereal::access;
};
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG

CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::Ohmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::BaseConnection,
    falcon_core::physics::device_structures::Ohmic)
#endif
