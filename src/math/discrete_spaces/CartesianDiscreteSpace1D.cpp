#include "falcon_core/math/discrete_spaces/CartesianDiscreteSpace1D.hpp"
#include "falcon_core/math/spaces/Cartesian1DSpace.hpp"

namespace falcon_core {
namespace math {
namespace discrete_spaces {

std::shared_ptr<CartesianDiscreteSpace1D> CartesianDiscreteSpace1D::from_division(
    int division,
    std::shared_ptr<domains::CoupledKnobDomain> shared_domain,
    std::shared_ptr<domains::Domain> domain)
{
    auto space = std::make_shared<spaces::Cartesian1DSpace>(static_cast<double>(division), domain);
    auto axes = std::make_shared<Axes<domains::CoupledKnobDomain>>();
    return std::make_shared<CartesianDiscreteSpace1D>(space, axes);
}

} // namespace discrete_spaces
} // namespace math
} // namespace falcon_core
