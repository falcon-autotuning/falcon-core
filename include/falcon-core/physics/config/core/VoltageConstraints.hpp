#pragma once

#include "falcon-core/communications/voltage_states/DeviceVoltageStates.hpp"
#include "falcon-core/export.h"
#include "falcon-core/generic/Song.hpp"
#include "falcon-core/math/domains/CoupledLabelledDomain.hpp"
#include "falcon-core/physics/config/core/Adjacency.hpp"
#include "falcon-core/physics/device_structures/Connections.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace core {

/**
 * @brief The container for the voltage constraints of the device. This includes
 * the adjacency matrix, the maximum safe voltage difference between adjacent
 * gates, and the minimum and maximum voltage bounds for the device. The voltage
 * constraints are used to validate voltage states and to compute the maximal
 * domain of the voltage constraints within a given search domain.
 */
class FALCON_CORE_CPP_API VoltageConstraints : public generic::Song {
  AdjacencySP _adjacency;
  double _max_safe_diff;
  double _min_bound;
  double _max_bound;
  mutable std::shared_timed_mutex _mu_adjacency;
  mutable std::shared_timed_mutex _mu_max_safe_diff;
  mutable std::shared_timed_mutex _mu_min_bound;
  mutable std::shared_timed_mutex _mu_max_bound;

public:
  VoltageConstraints(const VoltageConstraints &other);
  VoltageConstraints &operator=(const VoltageConstraints &other);
  VoltageConstraints(const AdjacencySP adjacency, double max_safe_diff,
                     std::pair<double, double> bounds);
  /**
   * @brief The adjacency matrix used to understand the device layout.
   */
  const AdjacencySP adjacency() const;
  /**
   * @brief The maximum safe voltage difference between adjacent gates.
   */
  const double max_safe_diff() const;
  /**
   * @brief The minimum voltage bound for the device.
   */
  const double min_bound() const;
  /**
   * @brief The maximum voltage bound for the device.
   */
  const double max_bound() const;
  /**
   * @brief Computes the maximal domain of the voltage constraints
   * @param search_domain The domain to search for the maximal domain in.
   * @param current_state The current voltage state of the device.
   * @return The maximal domain of the voltage constraints within the search
   * domain.
   */
  math::domains::CoupledLabelledDomainSP compute_maximal_domain(
      const instrument_interfaces::names::PortsSP search_domain,
      const communications::voltage_states::DeviceVoltageStatesSP current_state)
      const;
  /**
   * @brief Validates if a voltage state is within the voltage constraints.
   * @param voltage_state The voltage state to validate.
   * @return True if the voltage state is within the voltage constraints, false
   * if it is not.
   */
  bool validate_voltage_state(const math::PointSP voltage_state) const;

  bool operator==(const VoltageConstraints &other) const;
  bool operator!=(const VoltageConstraints &other) const;

protected:
  VoltageConstraints();
  friend class cereal::access;
  template <class Archive> inline void serialize(Archive &ar) {
    std::shared_lock<std::shared_timed_mutex> lock_adjacency(_mu_adjacency,
                                                             std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_max_safe_diff(
        _mu_max_safe_diff, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_min_bound(_mu_min_bound,
                                                             std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_max_bound(_mu_max_bound,
                                                             std::defer_lock);
    std::lock(lock_adjacency, lock_max_safe_diff, lock_min_bound,
              lock_max_bound);
    ar(cereal::base_class<generic::Song>(this), _adjacency, _max_safe_diff,
       _min_bound, _max_bound);
  }
};
using VoltageConstraintsSP = std::shared_ptr<VoltageConstraints>;
} // namespace core
} // namespace config
} // namespace physics
} // namespace falcon_core
