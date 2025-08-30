#pragma once

#include "falcon_core/physics/device_structures/BaseConnection.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

class ReservoirGate : public BaseConnection {
 public:
  ReservoirGate(std::string name);

 protected:
  ReservoirGate();
  friend class cereal::access;
};
using ReservoirGateSP = std::shared_ptr<ReservoirGate>;

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
