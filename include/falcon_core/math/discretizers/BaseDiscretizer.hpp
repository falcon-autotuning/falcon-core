/**
 * @file BaseDiscretizer.hpp
 * @brief Defines the BaseDiscretizer class for FalconCore.
 */

#pragma once

#include <cereal/types/memory.hpp>
#include <memory>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/domains/Domain.hpp"

namespace falcon_core::math::discretizers {

/**
 * @brief Abstract base class for discretizers.
 *
 * @details
 * Discretizers define how a domain is divided into discrete steps.
 */
class BaseDiscretizer : public generic::Song {
  double                           _delta;         ///< Step size.
  std::shared_ptr<domains::Domain> _delta_domain;  ///< Domain for step size.
 public:
  /**
   * @brief Construct a BaseDiscretizer. The delta must be within the
   * delta_domain.
   * @param delta Step size.
   * @param delta_domain Domain for step size.
   */
  BaseDiscretizer(const double&                           delta,
                  const std::shared_ptr<domains::Domain>& delta_domain);
  double                                  delta() const;
  void                                    set_delta(double delta);
  const std::shared_ptr<domains::Domain>& delta_domain() const;

 protected:
  friend class cereal::access;
  BaseDiscretizer();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _delta, _delta_domain);
  }
};
}  // namespace falcon_core::math::discretizers
