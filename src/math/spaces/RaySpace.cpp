#include "falcon_core/math/spaces/RaySpace.hpp"

#include "falcon_core/math/discretizers/CartesianDiscretizer.hpp"
#include "falcon_core/math/discretizers/PolarDiscretizer.hpp"

namespace falcon_core::math::spaces {

RaySpace::RaySpace(double dr, double dtheta, domains::DomainSP domain)
    : UnitSpace(make_axes(dr, dtheta), domain) {}

AxesSP<discretizers::BaseDiscretizer> RaySpace::make_axes(double dr,
                                                          double dtheta) {
  std::vector<std::shared_ptr<discretizers::BaseDiscretizer>> axes;
  axes.push_back(std::make_shared<discretizers::CartesianDiscretizer>(dr));
  axes.push_back(std::make_shared<discretizers::PolarDiscretizer>(dtheta));
  return std::make_shared<Axes<discretizers::BaseDiscretizer>>(axes);
}

RaySpace::RaySpace() = default;

}  // namespace falcon_core::math::spaces

CEREAL_REGISTER_TYPE(falcon_core::math::spaces::RaySpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::spaces::RaySpace)
