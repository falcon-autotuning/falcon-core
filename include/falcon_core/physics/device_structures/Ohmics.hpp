#pragma once

#include "falcon_core/physics/device_structures/BaseConnections.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A collection of Ohmics.
 */
class Ohmics : public BaseConnections {
 public:
  /**
   * @brief Default constructor: creates an empty Ohmics container.
   */
  Ohmics();
  /**
   * @brief Construct a Ohmics container with a given size.
   * @param count Number of elements.
   */
  Ohmics(size_t count);
  /**
   * @brief Construct a Ohmics container with a given size, and value.
   * @param count Number of elements.
   * @param value Value to copy.
   */
  Ohmics(size_t count, const BaseConnectionSP& value);
  /**
   * @brief Construct a Ohmics container from an existing vector of
   * values.
   * @param vec Vector of values to copy.
   */
  Ohmics(const std::vector<OhmicSP>& vec);

 protected:
  friend class cereal::access;
};
using OhmicsSP = std::shared_ptr<Ohmics>;

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
