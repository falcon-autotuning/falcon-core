/**
 * @file Cartesian1DSpace.hpp
 * @brief Defines the Cartesian1DSpace class for FalconCore.
 */

#pragma once

#include "falcon_core/math/spaces/CartesianSpace.hpp"

namespace falcon_core {
namespace math {
namespace spaces {

/**
 * @brief Represents a 1D Cartesian space.
 */
class Cartesian1DSpace : public CartesianSpace {
 public:
  /**
   * @brief Construct a 1D Cartesian space.
   * @param delta Discretization step.
   * @param domain Shared pointer to the domain.
   */
  Cartesian1DSpace(double delta, std::shared_ptr<domains::Domain> domain)
      : CartesianSpace(std::vector<double>{delta}, domain) {}

 protected:
  friend class cereal::access;
  /**
   * @brief Default constructor for cereal access.
   */
  Cartesian1DSpace() = default;
  /**
   * @brief Serialization method for cereal.
   * @param ar Archive object.
   */
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<CartesianSpace>(this));
  }
};

}  // namespace spaces
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::math::spaces::Cartesian1DSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::spaces::Cartesian1DSpace)
#endif
