#include "falcon_core/math/spaces/CartesianSpace.hpp"

namespace falcon_core {
namespace math {
namespace spaces {

CartesianSpace::CartesianSpace(const std::vector<double>&       deltas,
                               std::shared_ptr<domains::Domain> domain)
    : UnitSpace(make_axes(deltas), domain) {}

Axes<discretizers::BaseDiscretizer> CartesianSpace::make_axes(
    const std::vector<double>& deltas) {
  std::vector<std::shared_ptr<discretizers::BaseDiscretizer>> axes;
  for (double delta : deltas) {
    axes.push_back(std::make_shared<discretizers::CartesianDiscretizer>(delta));
  }
  return Axes<discretizers::BaseDiscretizer>(axes);
}

CartesianSpace::CartesianSpace() = default;

template <class Archive>
void CartesianSpace::serialize(Archive& ar) {
  ar(cereal::base_class<UnitSpace>(this));
}

}  // namespace spaces
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::spaces::CartesianSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::spaces::CartesianSpace)
