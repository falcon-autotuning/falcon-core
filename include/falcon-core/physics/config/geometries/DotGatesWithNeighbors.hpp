#pragma once

#include "falcon-core/export.h"
#include "falcon-core/generic/List.hpp"
#include "falcon-core/physics/config/geometries/DotGateWithNeighbors.hpp"
namespace falcon_core {
namespace generic {
extern template class 
    List<physics::config::geometries::DotGateWithNeighbors>;
}
namespace physics {
namespace config {
namespace geometries {

/**
 * @brief A serializable vector of DotGateWithNeighbors pointers, also a Song.
 *
 * DotGatesWithNeighbors can be constructed in 5 different ways:
 *
 * - Default constructor: creates an empty DotGatesWithNeighbors container.
 *   @code
 *   DotGatesWithNeighbors o;
 *   @endcode
 *
 * - Sized constructor: creates an DotGatesWithNeighbors container with a given
 * number of default-initialized elements.
 *   @param count Number of elements.
 *   @code
 *   DotGatesWithNeighbors o(10);
 *   @endcode
 *
 * - Fill constructor: creates an DotGatesWithNeighbors container with a given
 * number of copies of a specified value.
 *   @param count Number of elements.
 *   @param value Value to copy.
 *   @code
 *   DotGatesWithNeighbors o(10, someDotGatesWithNeighborsP);
 *   @endcode
 *
 * - Vector constructor: creates an DotGatesWithNeighbors container from an
 *existing vector of DotGateWithNeighborsSP.
 *   @param vec Vector of DotGateWithNeighborsSP to copy.
 *   @code
 *   std::vector<DotGatesWithNeighborsP> v = ...;
 *   DotGatesWithNeighbors o(v);
 *   @endcode
 * - Initializer list constructor: creates a DotGatesWithNeighbors container
 *from an initializer list of shared pointers.
 *   @param init Initializer list of shared_ptr<T> to copy.
 *   @code
 *   DotGatesWithNeighbors o{ptr1, ptr2, ptr3};
 *   @endcode
 */
class FALCON_CORE_CPP_API DotGatesWithNeighbors
    : public falcon_core::generic::List<DotGateWithNeighbors> {
 public:
  DotGatesWithNeighbors();
  /**
   * @brief Construct a DotGatesWithNeighbors container from an existing vector
   * of values.
   * @param vec Vector of values to copy.
   */
  DotGatesWithNeighbors(const std::vector<DotGateWithNeighborsSP>& vec);
  /**
   *  @brief Check if all connections are plunger gates.
   */
  bool is_plunger_gates() const;
  /**
   * @brief Check if all connections are barrier gates.
   */
  bool is_barrier_gates() const;
  bool operator==(const DotGatesWithNeighbors& other) const;
  bool operator!=(const DotGatesWithNeighbors& other) const;
};
using DotGatesWithNeighborsSP = std::shared_ptr<DotGatesWithNeighbors>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
