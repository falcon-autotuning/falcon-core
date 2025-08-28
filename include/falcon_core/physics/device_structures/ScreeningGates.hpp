#pragma once

#include "falcon_core/physics/device_structures/Gates.hpp"
#include "falcon_core/physics/device_structures/ScreeningGate.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A collection of ScreeningGates.
 */
class ScreeningGates : public Gates<ScreeningGate, ScreeningGates> {
 public:
  ScreeningGates();
  explicit ScreeningGates(size_t count);
  ScreeningGates(size_t count, const ScreeningGateSP& value);
  ScreeningGates(const std::vector<ScreeningGateSP>& vec);

  template <class Archive>
  void serialize(Archive& ar);

 protected:
  friend class cereal::access;
};
using ScreeningGatesSP = std::shared_ptr<ScreeningGates>;

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
