/**
 * @file Cartesian1DSpace.hpp
 * @brief Defines the Cartesian1DSpace class for FalconCore.
 */

#pragma once

#include <memory>

#include "falcon_core/math/spaces/CartesianSpace.hpp"

namespace falcon_core::math::spaces {

/**
 * @brief Represents a 1D Cartesian space.
 */
class Cartesian1DSpace : public CartesianSpace {
 public:
  Cartesian1DSpace(const double delta, const domains::DomainSP& domain);

 protected:
  friend class cereal::access;
  Cartesian1DSpace();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<CartesianSpace>(this));
  }
};
using Cartesian1DSpaceSP = std::shared_ptr<Cartesian1DSpace>;
}  // namespace falcon_core::math::spaces
