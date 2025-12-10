#include "falcon_core/math/domains/CoupledLabelledDomain.hpp"

#include <stdexcept>

#include "cereal/types/polymorphic.hpp"
#include "falcon_core/generic/List.hpp"
#include "falcon_core/instrument_interfaces/names/Ports.hpp"
#include "falcon_core/math/domains/LabelledDomain.hpp"

namespace falcon_core {
namespace math {
namespace domains {

CoupledLabelledDomain::CoupledLabelledDomain()
    : generic::List<LabelledDomain>() {}
CoupledLabelledDomain::CoupledLabelledDomain(
    const std::vector<LabelledDomainSP>& init)
    : generic::List<LabelledDomain>(init) {}
const std::vector<LabelledDomainSP> CoupledLabelledDomain::domains() const {
  return this->items();
}
const instrument_interfaces::names::PortsSP CoupledLabelledDomain::labels()
    const {
  generic::ListSP<instrument_interfaces::names::InstrumentPort> result =
      std::make_shared<List<instrument_interfaces::names::InstrumentPort>>();
  auto collected_domains = domains();
  for (const auto& domain : collected_domains) {
    result->push_back(domain->port());
  }
  return std::make_shared<instrument_interfaces::names::Ports>(result);
}

LabelledDomainSP CoupledLabelledDomain::get_domain(
    const instrument_interfaces::names::InstrumentPortSP& search) const {
  if (!search) {
    throw std::invalid_argument(
        "CoupledLabelledDomain: The port must not be null.");
  }
  for (const auto& domain : domains()) {
    if (*(domain->port()) == *search) {
      return domain;
    }
  }
  throw std::runtime_error("No domain found matching label");
}
bool CoupledLabelledDomain::operator==(
    const CoupledLabelledDomain& other) const {
  if (size() != other.size()) {
    return false;
  }
  for (size_t i = 0; i < size(); i++) {
    const LabelledDomainSP our_conn   = this->at(i);
    const LabelledDomainSP other_conn = other.at(i);
    if (*our_conn != *other_conn) {
      return false;
    }
  }
  return true;
}
bool CoupledLabelledDomain::operator!=(
    const CoupledLabelledDomain& other) const {
  return !(*this == other);
}

}  // namespace domains
}  // namespace math
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::math::domains::CoupledLabelledDomain);
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<falcon_core::math::domains::LabelledDomain>,
    falcon_core::math::domains::CoupledLabelledDomain)
