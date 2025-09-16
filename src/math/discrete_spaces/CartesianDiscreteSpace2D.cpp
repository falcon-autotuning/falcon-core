#include "falcon_core/math/discrete_spaces/CartesianDiscreteSpace2D.hpp"

namespace falcon_core::math::discrete_spaces {

CartesianDiscreteSpace2D::CartesianDiscreteSpace2D() = default;

CartesianDiscreteSpace2D::CartesianDiscreteSpace2D(
    const spaces::UnitSpaceSP&                     space,
    const AxesSP<domains::CoupledKnobDomain>&      axes,
    const AxesSP<generic::Map<std::string, bool>>& increasing)
    : BaseCartesianDiscreteSpace(space, axes, increasing) {}

}  // namespace falcon_core::math::discrete_spaces

CEREAL_REGISTER_TYPE(
    falcon_core::math::discrete_spaces::CartesianDiscreteSpace2D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::discrete_spaces::BaseCartesianDiscreteSpace,
    falcon_core::math::discrete_spaces::CartesianDiscreteSpace2D)
