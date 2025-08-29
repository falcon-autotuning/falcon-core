#pragma once

#include "falcon_core/physics/device_structures/BaseConnections.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A collection of PlungerGates.
 */
class PlungerGates : public BaseConnections {
 public:
  /**
   * @brief Default constructor: creates an empty PlungerGates container.
   */
  PlungerGates();
  /**
   * @brief Construct a PlungerGates container with a given size.
   * @param count Number of elements.
   */
  PlungerGates(size_t count);
  /**
   * @brief Construct a PlungerGates container with a given size, and value.
   * @param count Number of elements.
   * @param value Value to copy.
   */
  PlungerGates(size_t count, const BaseConnectionSP& value);
  /**
   * @brief Construct a PlungerGates container from an existing vector of
   * values.
   * @param vec Vector of values to copy.
   */
  PlungerGates(const std::vector<PlungerGateSP>& vec);

 protected:
  friend class cereal::access;
};
using PlungerGatesSP = std::shared_ptr<PlungerGates>;

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
