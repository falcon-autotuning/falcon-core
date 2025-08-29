#pragma once

#include "falcon_core/physics/device_structures/BaseConnections.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A collection of ScreeningGates.
 */
class ScreeningGates : public BaseConnections {
 public:
  /**
   * @brief Default constructor: creates an empty ScreeningGates container.
   */
  ScreeningGates();
  /**
   * @brief Construct a ScreeningGates container with a given size.
   * @param count Number of elements.
   */
  ScreeningGates(size_t count);
  /**
   * @brief Construct a ScreeningGates container with a given size, and value.
   * @param count Number of elements.
   * @param value Value to copy.
   */
  ScreeningGates(size_t count, const BaseConnectionSP& value);
  /**
   * @brief Construct a ScreeningGates container from an existing vector of
   * values.
   * @param vec Vector of values to copy.
   */
  ScreeningGates(const std::vector<ScreeningGateSP>& vec);

 protected:
  friend class cereal::access;
};
using ScreeningGatesSP = std::shared_ptr<ScreeningGates>;

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
