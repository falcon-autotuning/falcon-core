#pragma once

#include "falcon_core/physics/device_structures/DotGates.hpp"
#include "falcon_core/physics/device_structures/PlungerGate.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A collection of PlungerGates.
 */
class PlungerGates : public DotGates<PlungerGate, PlungerGates> {
 public:
  PlungerGates();
  explicit PlungerGates(size_t count);
  PlungerGates(size_t count, const PlungerGateSP& value);
  PlungerGates(const std::vector<PlungerGateSP>& vec);

  template <class Archive>
  void serialize(Archive& ar);

 protected:
  friend class cereal::access;
};
using PlungerGatesSP = std::shared_ptr<PlungerGates>;

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
