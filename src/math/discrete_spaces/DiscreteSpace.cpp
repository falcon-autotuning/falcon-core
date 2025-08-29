#include "falcon_core/math/discrete_spaces/DiscreteSpace.hpp"

namespace falcon_core {
namespace math {
namespace discrete_spaces {

DiscreteSpace::DiscreteSpace() = default;

DiscreteSpace::DiscreteSpace(std::shared_ptr<spaces::UnitSpace> space,
                             std::shared_ptr<Axes<domains::CoupledKnobDomain>> axes)
    : BaseDiscreteSpace(space, axes) {}

template <class Archive>
void DiscreteSpace::serialize(Archive& ar) {
    ar(cereal::base_class<BaseDiscreteSpace>(this));
}

}  // namespace discrete_spaces
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::discrete_spaces::DiscreteSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::math::discrete_spaces::BaseDiscreteSpace, falcon_core::math::discrete_spaces::DiscreteSpace)
