#pragma once

#include "falcon_core/physics/device_structures/Gate.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

class ScreeningGate : public virtual Gate {
 public:
  ScreeningGate(std::string name);
  template <class Archive>
  void serialize(Archive &ar);

 protected:
  ScreeningGate();
  friend class cereal::access;
};
using ScreeningGateSP = std::shared_ptr<ScreeningGate>;

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
