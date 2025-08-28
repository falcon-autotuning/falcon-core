#pragma once

#include "falcon_core/physics/device_structures/DotGate.hpp"  // Only needed if you define functions inline

namespace falcon_core {
namespace physics {
namespace device_structures {

class PlungerGate : public virtual DotGate {
 public:
  PlungerGate(std::string name);
  template <class Archive>
  void serialize(Archive &ar);

 protected:
  PlungerGate();
  friend class cereal::access;
};
using PlungerGateSP = std::shared_ptr<PlungerGate>;

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
