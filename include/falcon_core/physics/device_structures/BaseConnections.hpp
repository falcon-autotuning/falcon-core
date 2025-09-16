#pragma once

#include <cereal/archives/json.hpp>
#include <memory>

#include "falcon_core/generic/List.hpp"
#include "falcon_core/physics/device_structures/BarrierGate.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/device_structures/Ohmic.hpp"
#include "falcon_core/physics/device_structures/PlungerGate.hpp"
#include "falcon_core/physics/device_structures/ReservoirGate.hpp"
#include "falcon_core/physics/device_structures/ScreeningGate.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief A serializable vector of BaseConnection pointers, also a Song.
 *
 * BaseConnections can be constructed in 5 different ways:
 *
 * - Default constructor: creates an empty BaseConnections container.
 *   @code
 *   BaseConnections o;
 *   @endcode
 *
 * - Sized constructor: creates an BaseConnections container with a given
 * number of default-initialized elements.
 *   @param count Number of elements.
 *   @code
 *   BaseConnections o(10);
 *   @endcode
 *
 * - Fill constructor: creates an BaseConnections container with a given
 * number of copies of a specified value.
 *   @param count Number of elements.
 *   @param value Value to copy.
 *   @code
 *   BaseConnections o(10, someBaseConnectionsP);
 *   @endcode
 *
 * - Vector constructor: creates an BaseConnections container from an existing
 * vector of BaseConnectionSP.
 *   @param vec Vector of BaseConnectionSP to copy.
 *   @code
 *   std::vector<BaseConnectionsP> v = ...;
 *   BaseConnections o(v);
 *   @endcode
 * - Initializer list constructor: creates a BaseConnections container
 *from an initializer list of shared pointers.
 *   @param init Initializer list of shared_ptr<T> to copy.
 *   @code
 *   BaseConnections o{ptr1, ptr2, ptr3};
 *   @endcode
 */
class BaseConnections
    : public falcon_core::generic::List<BaseConnection, BaseConnections> {
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::List<BaseConnection, BaseConnections>>(
        this));
  }

 public:
  /**
   * @brief Default constructor: creates an empty BaseConnections container.
   */
  BaseConnections();
  /**
   * @brief Construct a BaseConnections container with a given size.
   * @param count Number of elements.
   */
  BaseConnections(size_t count);
  /**
   * @brief Construct a BaseConnections container with a given size, and value.
   * @param count Number of elements.
   * @param value Value to copy.
   */
  BaseConnections(size_t count, const BaseConnectionSP& value);
  /**
   * @brief Construct a BaseConnections container from an existing vector of
   * values.
   * @param vec Vector of values to copy.
   */
  BaseConnections(const std::vector<BaseConnectionSP>& vec);
  /**
   * @brief Construct a BaseConnections container from an existing vector of
   * values.
   * @param vec Vector of values to copy.
   */
  BaseConnections(const std::vector<PlungerGateSP>& vec);
  /**
   * @brief Construct a BaseConnections container from an existing vector of
   * values.
   * @param vec Vector of values to copy.
   */
  BaseConnections(const std::vector<BarrierGateSP>& vec);
  /**
   * @brief Construct a BaseConnections container from an existing vector of
   * values.
   * @param vec Vector of values to copy.
   */
  BaseConnections(const std::vector<ReservoirGateSP>& vec);
  /**
   * @brief Construct a BaseConnections container from an existing vector of
   * values.
   * @param vec Vector of values to copy.
   */
  BaseConnections(const std::vector<ScreeningGateSP>& vec);
  /**
   * @brief Construct a BaseConnections container from an existing vector of
   * values.
   * @param vec Vector of values to copy.
   */
  BaseConnections(const std::vector<OhmicSP>& vec);
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
  std::shared_ptr<BaseConnections> intersection(
      const std::shared_ptr<BaseConnections>& other) const {
    return std::make_shared<BaseConnections>(
        List::intersection(dynamic_pointer_cast<List<BaseConnection>>(other)));
  }

 protected:
  friend class cereal::access;
};
using BaseConnectionsSP = std::shared_ptr<BaseConnections>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
