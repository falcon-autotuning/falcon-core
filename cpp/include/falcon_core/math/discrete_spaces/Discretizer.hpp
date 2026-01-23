/**
 * @file Discretizer.hpp
 * @brief Defines the Discretizer class for FalconCore.
 */

#pragma once

#include "falcon_core/export.h"
#include "falcon_core/math/domains/Domain.hpp"

enum class Dividers {
  Cartesian,
  Polar,
};
namespace falcon_core {
namespace math {
namespace discrete_spaces {

/**
 * @brief Abstract base class for discretizers.
 *
 * @details
 * Discretizers define how a domain is divided into discrete steps.
 */
class FALCON_CORE_CPP_API Discretizer : public generic::Song {
  double                          _delta;
  domains::DomainSP               _delta_domain;
  Dividers                        _type;
  mutable std::shared_timed_mutex _mu_delta;
  mutable std::shared_timed_mutex _mu_delta_domain;
  mutable std::shared_timed_mutex _mu_type;

 public:
  Discretizer(const Discretizer& other);
  Discretizer& operator=(const Discretizer& other);
  /**
   * @brief Construct a Discretizer. The delta must be within the
   * delta_domain.
   * @param delta Step size.
   * @param delta_domain Domain for step size.
   * @param type the type of Dividers to construct.
   */
  Discretizer(const double&            delta,
              const domains::DomainSP& delta_domain,
              const Dividers&          type);
  /**
   * @brief Constructs a CartesianDiscretizer for Cartesian square axes.
   */
  static std::shared_ptr<Discretizer> CartesianDiscretizer(const double& delta);
  /**
   * @brief Construct a PolarDiscretizer for polar angled coordinates.
   */
  static std::shared_ptr<Discretizer> PolarDiscretizer(const double& delta);
  double                              delta() const;
  void                                set_delta(double delta);
  const domains::DomainSP&            domain() const;
  /**
   * @brief Checks if the current Discretizer is Cartesian.
   */
  const bool is_cartesian() const;
  /**
   * @brief Checks if the current Discretizer is Polar.
   */
  const bool is_polar() const;
  bool       operator==(const Discretizer& other) const;
  bool       operator!=(const Discretizer& other) const;

 protected:
  friend class cereal::access;
  Discretizer();
  template <class Archive>
  inline void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_delta(_mu_delta,
                                                         std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_delta_domain(
        _mu_delta_domain, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_type(_mu_type,
                                                        std::defer_lock);
    std::lock(lock_delta, lock_delta_domain, lock_type);
    ar(cereal::base_class<generic::Song>(this), _delta, _delta_domain, _type);
  }
};
using DiscretizerSP = std::shared_ptr<Discretizer>;
}  // namespace discrete_spaces
}  // namespace math
}  // namespace falcon_core
