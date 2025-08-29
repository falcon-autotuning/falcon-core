#include "falcon_core/math/discrete_spaces/CartesianDiscreteSpace1D.hpp"
#include "falcon_core/math/spaces/Cartesian1DSpace.hpp"

namespace falcon_core {
namespace math {
namespace discrete_spaces {

CartesianDiscreteSpace1D::CartesianDiscreteSpace1D() = default;

CartesianDiscreteSpace1D::CartesianDiscreteSpace1D(std::shared_ptr<spaces::Cartesian1DSpace> space,
                                                   std::shared_ptr<Axes<domains::CoupledKnobDomain>> axes)
    : BaseCartesianDiscreteSpace(space, axes) {}

std::shared_ptr<CartesianDiscreteSpace1D> CartesianDiscreteSpace1D::from_division(
    int division,
    std::shared_ptr<domains::CoupledKnobDomain> shared_domain,
    std::shared_ptr<domains::Domain> domain)
{
    auto space = std::make_shared<spaces::Cartesian1DSpace>(static_cast<double>(division), domain);
    auto axes = std::make_shared<Axes<domains::CoupledKnobDomain>>();
    return std::make_shared<CartesianDiscreteSpace1D>(space, axes);
}

template <class Archive>
void CartesianDiscreteSpace1D::serialize(Archive& ar) {
    ar(cereal::base_class<BaseCartesianDiscreteSpace>(this));
}

} // namespace discrete_spaces
} // namespace math
} // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::discrete_spaces::CartesianDiscreteSpace1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::math::discrete_spaces::BaseCartesianDiscreteSpace, falcon_core::math::discrete_spaces::CartesianDiscreteSpace1D)
