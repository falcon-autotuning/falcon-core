#pragma once

#include "falcon_core/physics/device_structures/BarrierGate.hpp"
#include "falcon_core/physics/device_structures/DotGates.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A collection of BarrierGates.
 */
class BarrierGates : public DotGates<BarrierGate, BarrierGates> {
 public:
  BarrierGates();
  explicit BarrierGates(size_t count);
  BarrierGates(size_t count, const BarrierGateSP& value);
  BarrierGates(const std::vector<BarrierGateSP>& vec);

  template <class Archive>
  void serialize(Archive& ar);

 protected:
  friend class cereal::access;
};
using BarrierGatesSP = std::shared_ptr<BarrierGates>;

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
