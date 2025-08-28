/**
 * @file CartesianSpace.hpp
 * @brief Defines the CartesianSpace class for FalconCore.
 */

#pragma once

#include "falcon_core/math/discretizers/CartesianDiscretizer.hpp"
#include "falcon_core/math/spaces/UnitSpace.hpp"

namespace falcon_core {
namespace math {
namespace spaces {

/**
 * @brief Represents a Cartesian space with discretization.
 */
class CartesianSpace : public UnitSpace {
 public:
  CartesianSpace(const std::vector<double>& deltas,
                 std::shared_ptr<domains::Domain> domain);

  static Axes<discretizers::BaseDiscretizer> make_axes(
      const std::vector<double>& deltas);

 protected:
  friend class cereal::access;
  CartesianSpace();
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace spaces
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::math::spaces::CartesianSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::spaces::CartesianSpace)
#endif
