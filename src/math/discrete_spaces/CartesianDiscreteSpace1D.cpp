#include "falcon_core/math/discrete_spaces/CartesianDiscreteSpace1D.hpp"

#include "falcon_core/generic/List.hpp"
#include "falcon_core/math/domains/CoupledKnobDomain.hpp"
#include "falcon_core/math/spaces/CartesianSpace.hpp"
namespace falcon_core::math::discrete_spaces {
CartesianDiscreteSpace1D::CartesianDiscreteSpace1D() = default;
CartesianDiscreteSpace1D::CartesianDiscreteSpace1D(
    const spaces::UnitSpaceSP&               space,
    const domains::CoupledKnobDomainSP&      shared_domain,
    const generic::MapSP<std::string, bool>& increasing)
    : BaseCartesianDiscreteSpace(
          space,
          std::make_shared<Axes<domains::CoupledKnobDomain>>(
              generic::List<domains::CoupledKnobDomain>({shared_domain})),
          std::make_shared<Axes<generic::Map<std::string, bool>>>(
              generic::List<generic::Map<std::string, bool>>({increasing}))) {}

std::shared_ptr<CartesianDiscreteSpace1D>
CartesianDiscreteSpace1D::from_divisions(
    const int&                               division,
    const domains::CoupledKnobDomainSP&      shared_domain,
    const generic::MapSP<std::string, bool>& increasing,
    const domains::DomainSP&                 domain) {
  std::vector<double> deltas;
  deltas.push_back(domain->range() / division);

  AxesSP<domains::CoupledKnobDomain> axes =
      std::make_shared<Axes<domains::CoupledKnobDomain>>(
          generic::List<domains::CoupledKnobDomain>({shared_domain}));
  auto space = std::make_shared<spaces::CartesianSpace>(deltas, domain);
  return std::make_shared<CartesianDiscreteSpace1D>(space, axes, increasing);
}

}  // namespace falcon_core::math::discrete_spaces

CEREAL_REGISTER_TYPE(
    falcon_core::math::discrete_spaces::CartesianDiscreteSpace1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::discrete_spaces::BaseCartesianDiscreteSpace,
    falcon_core::math::discrete_spaces::CartesianDiscreteSpace1D)
