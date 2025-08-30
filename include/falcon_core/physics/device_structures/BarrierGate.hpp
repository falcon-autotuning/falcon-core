#pragma once

#include "falcon_core/physics/device_structures/BaseConnection.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

class BarrierGate : public BaseConnection {
 public:
  BarrierGate(std::string name);

 protected:
  BarrierGate();
  friend class cereal::access;
};
using BarrierGateSP = std::shared_ptr<BarrierGate>;

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
