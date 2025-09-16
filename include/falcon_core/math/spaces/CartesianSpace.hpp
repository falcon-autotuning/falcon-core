/**
 * @file CartesianSpace.hpp
 * @brief Defines the CartesianSpace class for FalconCore.
 */

#pragma once

#include "falcon_core/math/spaces/UnitSpace.hpp"

namespace falcon_core::math::spaces {

/**
 * @brief Represents a Cartesian space with discretization.
 */
class CartesianSpace : public UnitSpace {
 public:
  CartesianSpace(const std::vector<double>& deltas,
                 const domains::DomainSP&   domain);

  static AxesSP<discretizers::BaseDiscretizer> make_axes(
      const std::vector<double>& deltas);

 protected:
  friend class cereal::access;
  CartesianSpace();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<UnitSpace>(this));
  }
};

}  // namespace falcon_core::math::spaces
