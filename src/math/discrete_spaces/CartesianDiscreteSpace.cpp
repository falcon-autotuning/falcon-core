#include "falcon_core/math/discrete_spaces/CartesianDiscreteSpace.hpp"

#include "falcon_core/math/UnitSpace.hpp"

namespace falcon_core::math::discrete_spaces {

CartesianDiscreteSpace::CartesianDiscreteSpace() = default;
CartesianDiscreteSpace::CartesianDiscreteSpace(
    const UnitSpaceSP&                             space,
    const AxesSP<domains::CoupledLabelledDomain>&  axes,
    const AxesSP<generic::Map<std::string, bool>>& increasing)
    : BaseDiscreteSpace(space, axes, increasing) {}

std::shared_ptr<CartesianDiscreteSpace> CartesianDiscreteSpace::from_divisions(
    const generic::ListSP<int>&                    divisions,
    const AxesSP<domains::CoupledLabelledDomain>&  axes,
    const AxesSP<generic::Map<std::string, bool>>& increasing,
    const domains::DomainSP&                       domain) {
  if (divisions->size() != axes->size()) {
    throw std::runtime_error(
        "The number of division of each axis must be the same size as the axes "
        "for the sweeps.");
  }
  AxesSP<double> deltas;
  for (int d : *divisions) deltas->push_back(domain->range() / d);
  auto space = UnitSpace::CartesianSpace(deltas, domain);
  return std::make_shared<CartesianDiscreteSpace>(space, axes, increasing);
}

}  // namespace falcon_core::math::discrete_spaces

CEREAL_REGISTER_TYPE(falcon_core::math::discrete_spaces::CartesianDiscreteSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::discrete_spaces::BaseDiscreteSpace,
    falcon_core::math::discrete_spaces::CartesianDiscreteSpace)
