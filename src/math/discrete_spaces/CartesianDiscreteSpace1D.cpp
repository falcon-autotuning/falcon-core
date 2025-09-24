#include "falcon_core/math/discrete_spaces/CartesianDiscreteSpace1D.hpp"

#include <memory>

#include "falcon_core/generic/List.hpp"
#include "falcon_core/math/UnitSpace.hpp"
#include "falcon_core/math/domains/CoupledLabelledDomain.hpp"
namespace falcon_core::math::discrete_spaces {
CartesianDiscreteSpace1D::CartesianDiscreteSpace1D() = default;
CartesianDiscreteSpace1D::CartesianDiscreteSpace1D(
    const UnitSpaceSP&                       space,
    const domains::CoupledLabelledDomainSP&  shared_domain,
    const generic::MapSP<std::string, bool>& increasing)
    : BaseDiscreteSpace(
          space,
          std::make_shared<Axes<domains::CoupledLabelledDomain>>(
              generic::List<domains::CoupledLabelledDomain>({shared_domain})
                  .items()),
          std::make_shared<Axes<generic::Map<std::string, bool>>>(
              generic::List<generic::Map<std::string, bool>>({increasing})
                  .items())) {}

CartesianDiscreteSpace1DSP CartesianDiscreteSpace1D::from_divisions(
    const int&                               division,
    const domains::CoupledLabelledDomainSP&  shared_domain,
    const generic::MapSP<std::string, bool>& increasing,
    const domains::DomainSP&                 domain) {
  UnitSpaceSP space =
      UnitSpace::Cartesian1DSpace(domain->range() / division, domain);
  return std::make_shared<CartesianDiscreteSpace1D>(
      space, shared_domain, increasing);
}

}  // namespace falcon_core::math::discrete_spaces

CEREAL_REGISTER_TYPE(
    falcon_core::math::discrete_spaces::CartesianDiscreteSpace1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::discrete_spaces::BaseDiscreteSpace,
    falcon_core::math::discrete_spaces::CartesianDiscreteSpace1D)
