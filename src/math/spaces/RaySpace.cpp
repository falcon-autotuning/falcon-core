#include "falcon_core/math/spaces/RaySpace.hpp"

#include "falcon_core/math/discrete_spaces/Discretizer.hpp"

namespace falcon_core::math::spaces {

RaySpace::RaySpace(double dr, double dtheta, domains::DomainSP domain)
    : UnitSpace(make_axes(dr, dtheta), domain) {}

AxesSP<discrete_spaces::Discretizer> RaySpace::make_axes(double dr,
                                                         double dtheta) {
  AxesSP<discrete_spaces::Discretizer> axes;
  axes->push_back(discrete_spaces::Discretizer::CartesianDiscretizer(dr));
  axes->push_back(discrete_spaces::Discretizer::PolarDiscretizer(dtheta));
  return axes;
}

RaySpace::RaySpace() = default;

}  // namespace falcon_core::math::spaces

CEREAL_REGISTER_TYPE(falcon_core::math::spaces::RaySpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::spaces::RaySpace)
