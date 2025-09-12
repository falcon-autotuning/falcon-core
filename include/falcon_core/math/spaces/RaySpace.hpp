/**
 * @file RaySpace.hpp
 * @brief Defines the RaySpace class for FalconCore.
 */

#pragma once

#include "falcon_core/math/spaces/UnitSpace.hpp"

namespace falcon_core {
namespace math {
namespace spaces {

/**
 * @brief Represents a ray space with radial and angular discretization.
 */
class RaySpace : public UnitSpace {
 public:
  RaySpace(double dr, double dtheta, std::shared_ptr<domains::Domain> domain);

  static Axes<discretizers::BaseDiscretizer> make_axes(double dr,
                                                       double dtheta);

 protected:
  friend class cereal::access;
  RaySpace();
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace spaces
}  // namespace math
}  // namespace falcon_core
