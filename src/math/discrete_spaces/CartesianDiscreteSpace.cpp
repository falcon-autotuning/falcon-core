#include "falcon_core/math/discrete_spaces/CartesianDiscreteSpace.hpp"
#include "falcon_core/math/spaces/CartesianSpace.hpp"

namespace falcon_core {
namespace math {
namespace discrete_spaces {

std::shared_ptr<CartesianDiscreteSpace> CartesianDiscreteSpace::from_divisions(
    const std::vector<int>& divisions,
    std::shared_ptr<Axes<domains::CoupledKnobDomain>> axes,
    std::shared_ptr<domains::Domain> domain)
{
    std::vector<double> deltas;
    for (int d : divisions) deltas.push_back(static_cast<double>(d));
    auto space = std::make_shared<spaces::CartesianSpace>(deltas, domain);
    return std::make_shared<CartesianDiscreteSpace>(space, axes);
}

} // namespace discrete_spaces
} // namespace math
} // namespace falcon_core
