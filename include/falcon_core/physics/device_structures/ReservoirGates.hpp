#pragma once

#include "falcon_core/physics/device_structures/BaseConnections.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A collection of ReservoirGates.
 */
class ReservoirGates : public BaseConnections {
 public:
  /**
   * @brief Default constructor: creates an empty ReservoirGates container.
   */
  ReservoirGates();
  /**
   * @brief Construct a ReservoirGates container with a given size.
   * @param count Number of elements.
   */
  ReservoirGates(size_t count);
  /**
   * @brief Construct a ReservoirGates container with a given size, and value.
   * @param count Number of elements.
   * @param value Value to copy.
   */
  ReservoirGates(size_t count, const BaseConnectionSP& value);
  /**
   * @brief Construct a ReservoirGates container from an existing vector of
   * values.
   * @param vec Vector of values to copy.
   */
  ReservoirGates(const std::vector<ReservoirGateSP>& vec);

 protected:
  friend class cereal::access;
};
using ReservoirGatesSP = std::shared_ptr<ReservoirGates>;

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
