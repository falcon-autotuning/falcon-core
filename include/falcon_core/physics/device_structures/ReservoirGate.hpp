#pragma once

#include "falcon_core/physics/device_structures/Gate.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

class ReservoirGate : public virtual Gate {
 public:
  ReservoirGate(std::string name);
  template <class Archive>
  void serialize(Archive &ar);

 protected:
  ReservoirGate();
  friend class cereal::access;
};
using ReservoirGateSP = std::shared_ptr<ReservoirGate>;

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
