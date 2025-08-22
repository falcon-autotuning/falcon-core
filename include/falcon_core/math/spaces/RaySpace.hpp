#pragma once

#include "falcon_core/math/spaces/UnitSpace.hpp"
#include "falcon_core/math/discretizers/CartesianDiscretizer.hpp"
#include "falcon_core/math/discretizers/PolarDiscretizer.hpp"

namespace falcon_core {
namespace math {
namespace spaces {

class RaySpace : public UnitSpace {
 public:
  RaySpace(double dr, double dtheta, std::shared_ptr<domains::Domain> domain)
      : UnitSpace(make_axes(dr, dtheta), domain) {}

  static Axes<discretizers::BaseDiscretizer>
  make_axes(double dr, double dtheta) {
    std::vector<std::shared_ptr<discretizers::BaseDiscretizer>> axes;
    axes.push_back(std::make_shared<discretizers::CartesianDiscretizer>(dr));
    axes.push_back(std::make_shared<discretizers::PolarDiscretizer>(dtheta));
    return Axes<discretizers::BaseDiscretizer>(axes);
  }

 protected:
  friend class cereal::access;
  RaySpace() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<UnitSpace>(this));
  }
};

}  // namespace spaces
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::math::spaces::RaySpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::spaces::RaySpace)
#endif
