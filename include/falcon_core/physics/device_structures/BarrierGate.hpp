#pragma once

#include "falcon_core/physics/device_structures/DotGate.hpp"  // Only needed if you define functions inline

namespace falcon_core {
namespace physics {
namespace device_structures {

class BarrierGate : public virtual DotGate {
 public:
  BarrierGate(std::string name);
  template <class Archive>
  void serialize(Archive &ar);

 protected:
  BarrierGate();
  friend class cereal::access;
};
using BarrierGateSP = std::shared_ptr<BarrierGate>;

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
