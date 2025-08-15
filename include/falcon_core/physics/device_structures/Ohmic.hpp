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
};
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
