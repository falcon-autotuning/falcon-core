#pragma once

#include "falcon_core/physics/device_structures/Gates.hpp"
#include "falcon_core/physics/device_structures/ReservoirGate.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A collection of ReservoirGates.
 */
class ReservoirGates : public Gates<ReservoirGate, ReservoirGates> {
 public:
  ReservoirGates();
  explicit ReservoirGates(size_t count);
  ReservoirGates(size_t count, const ReservoirGateSP& value);
  ReservoirGates(const std::vector<ReservoirGateSP>& vec);

  template <class Archive>
  void serialize(Archive& ar);

 protected:
  friend class cereal::access;
};
using ReservoirGatesSP = std::shared_ptr<ReservoirGates>;

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
