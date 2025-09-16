/**
 * @file Cartesian2DSpace.hpp
 * @brief Defines the Cartesian2DSpace class for FalconCore.
 */

#pragma once

#include "falcon_core/math/spaces/CartesianSpace.hpp"

namespace falcon_core::math::spaces {

/**
 * @brief Represents a 2D Cartesian space.
 */
class Cartesian2DSpace : public CartesianSpace {
 public:
  Cartesian2DSpace(const std::vector<double>& deltas,
                   const domains::DomainSP&   domain);

 protected:
  friend class cereal::access;
  Cartesian2DSpace();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<CartesianSpace>(this));
  }
};

}  // namespace falcon_core::math::spaces
