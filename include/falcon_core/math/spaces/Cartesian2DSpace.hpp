/**
 * @file Cartesian2DSpace.hpp
 * @brief Defines the Cartesian2DSpace class for FalconCore.
 */

#pragma once

#include "falcon_core/math/spaces/CartesianSpace.hpp"

namespace falcon_core {
namespace math {
namespace spaces {

/**
 * @brief Represents a 2D Cartesian space.
 */
class Cartesian2DSpace : public CartesianSpace {
 public:
  Cartesian2DSpace(const std::vector<double>& deltas,
                   std::shared_ptr<domains::Domain> domain);

 protected:
  friend class cereal::access;
  Cartesian2DSpace();
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace spaces
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::math::spaces::Cartesian2DSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::spaces::Cartesian2DSpace)
#endif
