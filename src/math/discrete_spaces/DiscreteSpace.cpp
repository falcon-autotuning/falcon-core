#include "falcon_core/math/discrete_spaces/DiscreteSpace.hpp"

namespace falcon_core::math::discrete_spaces {

DiscreteSpace::DiscreteSpace() = default;
DiscreteSpace::DiscreteSpace(
    const UnitSpaceSP&                             space,
    const AxesSP<domains::CoupledLabelledDomain>&  axes,
    const AxesSP<generic::Map<std::string, bool>>& increasing)
    : BaseDiscreteSpace(space, axes, increasing) {}

}  // namespace falcon_core::math::discrete_spaces

CEREAL_REGISTER_TYPE(falcon_core::math::discrete_spaces::DiscreteSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::discrete_spaces::BaseDiscreteSpace,
    falcon_core::math::discrete_spaces::DiscreteSpace)
