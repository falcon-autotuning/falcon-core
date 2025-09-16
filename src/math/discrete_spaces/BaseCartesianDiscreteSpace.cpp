#include "falcon_core/math/discrete_spaces/BaseCartesianDiscreteSpace.hpp"

namespace falcon_core::math::discrete_spaces {

BaseCartesianDiscreteSpace::BaseCartesianDiscreteSpace(
    const spaces::UnitSpaceSP&                     space,
    const AxesSP<domains::CoupledKnobDomain>&      axes,
    const AxesSP<generic::Map<std::string, bool>>& increasing)
    : BaseDiscreteSpace(space, axes, increasing) {}

}  // namespace falcon_core::math::discrete_spaces
//
CEREAL_REGISTER_TYPE(
    falcon_core::math::discrete_spaces::BaseCartesianDiscreteSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::discrete_spaces::BaseDiscreteSpace,
    falcon_core::math::discrete_spaces::BaseCartesianDiscreteSpace)
