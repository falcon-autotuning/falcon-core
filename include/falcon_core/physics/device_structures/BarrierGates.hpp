#pragma once

#include "falcon_core/physics/device_structures/BaseConnections.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A collection of BarrierGates.
 */
class BarrierGates : public BaseConnections {
 public:
  /**
   * @brief Default constructor: creates an empty BarrierGates container.
   */
  BarrierGates();
  /**
   * @brief Construct a BarrierGates container with a given size.
   * @param count Number of elements.
   */
  BarrierGates(size_t count);
  /**
   * @brief Construct a BarrierGates container with a given size, and value.
   * @param count Number of elements.
   * @param value Value to copy.
   */
  BarrierGates(size_t count, const BaseConnectionSP& value);
  /**
   * @brief Construct a BarrierGates container from an existing vector of
   * values.
   * @param vec Vector of values to copy.
   */
  BarrierGates(const std::vector<BarrierGateSP>& vec);

 protected:
  friend class cereal::access;
};
using BarrierGatesSP = std::shared_ptr<BarrierGates>;

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
