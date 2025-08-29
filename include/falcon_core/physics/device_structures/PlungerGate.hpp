#pragma once

#include "falcon_core/physics/device_structures/BaseConnection.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

class PlungerGate : public BaseConnection {
 public:
  PlungerGate(std::string name);

 protected:
  PlungerGate();
  friend class cereal::access;
};
using PlungerGateSP = std::shared_ptr<PlungerGate>;

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
