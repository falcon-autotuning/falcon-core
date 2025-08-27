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
  /**
   * @brief Construct a discretizer.
   * @param delta Step size.
   * @param delta_domain Domain for the step size.
   */
  BaseDiscretizer(double delta, std::shared_ptr<domains::Domain> delta_domain)
      : _delta(delta), _delta_domain(std::move(delta_domain)) {}

  /**
   * @brief Virtual destructor.
   */
  virtual ~BaseDiscretizer() = default;

  /**
   * @brief Get the step size.
   * @return Step size as double.
   */
  double delta() const { return _delta; }

  /**
   * @brief Set the step size.
   * @param delta New step size.
   */
  void   set_delta(double delta) { _delta = delta; }

  /**
   * @brief Get the domain for the step size.
   * @return Shared pointer to domain.
   */
  const std::shared_ptr<domains::Domain>& delta_domain() const {
    return _delta_domain;
  }

protected:
  double                           _delta;        ///< Step size.
  std::shared_ptr<domains::Domain> _delta_domain; ///< Domain for step size.

  friend class cereal::access;
  /**
   * @brief Default constructor for cereal.
   */
  BaseDiscretizer() = default;
  /**
   * @brief Serialization method for cereal.
   * @param ar Archive object.
   */
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _delta, _delta_domain);
  }
};
}  // namespace discretizers
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
using namespace falcon_core::math::discretizers;
CEREAL_REGISTER_TYPE(falcon_core::math::discretizers::BaseDiscretizer)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::discretizers::BaseDiscretizer)
#endif
