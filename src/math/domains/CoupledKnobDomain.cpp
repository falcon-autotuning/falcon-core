#include "falcon_core/math/domains/CoupledKnobDomain.hpp"

namespace falcon_core::math::domains {

CoupledKnobDomain::CoupledKnobDomain()
    : BaseCoupledLabelledDomain<instrument_interfaces::names::Knob>() {}
CoupledKnobDomain::CoupledKnobDomain(
    const std::vector<BaseLabelledDomainSP<instrument_interfaces::names::Knob>>&
        init)
    : BaseCoupledLabelledDomain<instrument_interfaces::names::Knob>(init) {}
const instrument_interfaces::names::KnobsSP CoupledKnobDomain::knobs() const {
  return std::make_shared<instrument_interfaces::names::Knobs>(labels());
}

}  // namespace falcon_core::math::domains

CEREAL_REGISTER_TYPE(falcon_core::math::domains::CoupledKnobDomain)
CEREAL_REGISTER_TYPE(falcon_core::math::domains::BaseCoupledLabelledDomain<
                     falcon_core::instrument_interfaces::names::Knob>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::domains::BaseCoupledLabelledDomain<
        falcon_core::instrument_interfaces::names::Knob>,
    falcon_core::math::domains::CoupledKnobDomain)
