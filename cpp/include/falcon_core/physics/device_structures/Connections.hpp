#pragma once

#include "falcon_core/export.h"
#include "falcon_core/generic/List.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A serializable vector of Connection pointers, also a Song.
 *
 * Connections can be constructed in 5 different ways:
 *
 * - Default constructor: creates an empty Connections container.
 *   @code
 *   Connections o;
 *   @endcode
 *
 * - Sized constructor: creates an Connections container with a given
 * number of default-initialized elements.
 *   @param count Number of elements.
 *   @code
 *   Connections o(10);
 *   @endcode
 *
 * - Fill constructor: creates an Connections container with a given
 * number of copies of a specified value.
 *   @param count Number of elements.
 *   @param value Value to copy.
 *   @code
 *   Connections o(10, someConnectionsP);
 *   @endcode
 *
 * - Vector constructor: creates an Connections container from an existing
 * vector of ConnectionSP.
 *   @param vec Vector of ConnectionSP to copy.
 *   @code
 *   std::vector<ConnectionsP> v = ...;
 *   Connections o(v);
 *   @endcode
 * - Initializer list constructor: creates a Connections container
 *from an initializer list of shared pointers.
 *   @param init Initializer list of shared_ptr<T> to copy.
 *   @code
 *   Connections o{ptr1, ptr2, ptr3};
 *   @endcode
 */
class FALCON_CORE_CPP_API Connections
    : public falcon_core::generic::List<Connection> {
 public:
  /**
   * @brief Default constructor: creates an empty Connections container.
   */
  Connections();
  /**
   * @brief Construct a Connections container with a given size, and value.
   * @param count Number of elements.
   * @param value Value to copy.
   */
  Connections(size_t count, const ConnectionSP& value);
  /**
   * @brief Construct a Connections container from an existing vector of
   * values.
   * @param vec Vector of values to copy.
   */
  Connections(const std::vector<ConnectionSP>& vec);
  /**
   * @brief Construct a Connections container from an existing vector of
   * values.
   * @param vec Vector of values to copy.
   */
  Connections(const generic::ListSP<Connection>& vec);
  /**
   * @brief Check if all connections are gates (not ohmics).
   */
  bool is_gates() const;
  /**
   * @brief Check if all connections are ohmics (not gates).
   */
  bool is_ohmics() const;
  /**
   * @brief Check if all connections are dot gates (plunger or barrier).
   */
  bool is_dot_gates() const;
  /**
   *  @brief Check if all connections are plunger gates.
   */
  bool is_plunger_gates() const;
  /**
   * @brief Check if all connections are barrier gates.
   */
  bool is_barrier_gates() const;
  /**
   * @brief Check if all connections are reservoir gates.
   */
  bool is_reservoir_gates() const;
  /**
   * @brief Check if all connections are screening gates.
   */
  bool is_screening_gates() const;
  /**
   * @brief Finds the intersection between this list and another.
   * @param other the other list to compare again.
   * @returns A list of values containing elements from both.
   */
  std::shared_ptr<Connections> intersection(
      const std::shared_ptr<Connections>& other) const;
  bool operator==(const Connections& other) const;
  bool operator!=(const Connections& other) const;
};
using ConnectionsSP = std::shared_ptr<Connections>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
