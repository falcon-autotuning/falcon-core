/**
 * @file RaySpace.hpp
 * @brief Defines the RaySpace class for FalconCore.
 */

#pragma once

#include "falcon_core/math/spaces/UnitSpace.hpp"

namespace falcon_core::math::spaces {

/**
 * @brief Represents a ray space with radial and angular discretization.
 */
class RaySpace : public UnitSpace {
 public:
  RaySpace(double dr, double dtheta, domains::DomainSP domain);

  static AxesSP<discretizers::BaseDiscretizer> make_axes(double dr,
                                                         double dtheta);

 protected:
  friend class cereal::access;
  RaySpace();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<UnitSpace>(this));
  }
};

}  // namespace falcon_core::math::spaces
