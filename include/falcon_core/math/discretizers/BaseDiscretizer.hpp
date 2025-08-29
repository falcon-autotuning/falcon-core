/**
 * @file BaseDiscretizer.hpp
 * @brief Defines the BaseDiscretizer class for FalconCore.
 */

#pragma once

#include <cereal/types/memory.hpp>
#include <memory>

#include "falcon_core/generic/Song.hpp"
#include "falcon_core/math/domains/Domain.hpp"

namespace falcon_core {
namespace math {
namespace discretizers {

/**
 * @brief Abstract base class for discretizers.
 *
 * @details
 * Discretizers define how a domain is divided into discrete steps.
 */
class BaseDiscretizer : public generic::Song {
 public:
  BaseDiscretizer(double delta, std::shared_ptr<domains::Domain> delta_domain);
  virtual ~BaseDiscretizer();
  double delta() const;
  void set_delta(double delta);
  const std::shared_ptr<domains::Domain>& delta_domain() const;

protected:
  double                           _delta;        ///< Step size.
  std::shared_ptr<domains::Domain> _delta_domain; ///< Domain for step size.

  friend class cereal::access;
  BaseDiscretizer();
  template <class Archive>
  void serialize(Archive& ar);
};
}  // namespace discretizers
}  // namespace math
}  // namespace falcon_core
