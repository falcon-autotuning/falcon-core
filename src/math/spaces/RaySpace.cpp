#include "falcon_core/math/spaces/RaySpace.hpp"

namespace falcon_core {
namespace math {
namespace spaces {

RaySpace::RaySpace(double                           dr,
                   double                           dtheta,
                   std::shared_ptr<domains::Domain> domain)
    : UnitSpace(make_axes(dr, dtheta), domain) {}

Axes<discretizers::BaseDiscretizer> RaySpace::make_axes(double dr,
                                                        double dtheta) {
  std::vector<std::shared_ptr<discretizers::BaseDiscretizer>> axes;
  axes.push_back(std::make_shared<discretizers::CartesianDiscretizer>(dr));
  axes.push_back(std::make_shared<discretizers::PolarDiscretizer>(dtheta));
  return Axes<discretizers::BaseDiscretizer>(axes);
}

RaySpace::RaySpace() = default;

template <class Archive>
void RaySpace::serialize(Archive& ar) {
  ar(cereal::base_class<UnitSpace>(this));
}

}  // namespace spaces
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::spaces::RaySpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::spaces::RaySpace)
