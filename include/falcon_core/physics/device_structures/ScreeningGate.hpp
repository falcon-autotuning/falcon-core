#pragma once

#include "falcon_core/physics/device_structures/BaseConnection.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

class ScreeningGate : public virtual BaseConnection {
 public:
  ScreeningGate(std::string name);

 protected:
  ScreeningGate();
  friend class cereal::access;
};
using ScreeningGateSP = std::shared_ptr<ScreeningGate>;

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
