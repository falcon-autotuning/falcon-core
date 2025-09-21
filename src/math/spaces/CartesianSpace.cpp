#include "falcon_core/math/spaces/CartesianSpace.hpp"

#include "falcon_core/math/discrete_spaces/Discretizer.hpp"

namespace falcon_core::math::spaces {

CartesianSpace::CartesianSpace() = default;
CartesianSpace::CartesianSpace(const std::vector<double>& deltas,
                               const domains::DomainSP&   domain)
    : UnitSpace(make_axes(deltas), domain) {}

AxesSP<discrete_spaces::Discretizer> CartesianSpace::make_axes(
    const std::vector<double>& deltas) {
  std::vector<std::shared_ptr<discrete_spaces::Discretizer>> axes;
  for (double delta : deltas) {
    axes.push_back(discrete_spaces::Discretizer::CartesianDiscretizer(delta));
  }
  return std::make_shared<Axes<discrete_spaces::Discretizer>>(axes);
}

}  // namespace falcon_core::math::spaces

CEREAL_REGISTER_TYPE(falcon_core::math::spaces::CartesianSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::spaces::CartesianSpace)
