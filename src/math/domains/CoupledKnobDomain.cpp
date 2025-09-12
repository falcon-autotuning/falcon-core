#include "falcon_core/math/domains/CoupledKnobDomain.hpp"

namespace falcon_core::math::domains {

CoupledKnobDomain::CoupledKnobDomain() = default;
CoupledKnobDomain::CoupledKnobDomain(
    const std::vector<BaseLabelledDomainSP<instrument_interfaces::names::Knob>>&
        init)
    : BaseCoupledLabelledDomain<instrument_interfaces::names::Knob>(init) {}

}  // namespace falcon_core::math::domains

CEREAL_REGISTER_TYPE(falcon_core::math::domains::CoupledKnobDomain)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::domains::CoupledKnobDomain)
