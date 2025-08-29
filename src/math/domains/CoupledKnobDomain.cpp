#include "falcon_core/math/domains/CoupledKnobDomain.hpp"

namespace falcon_core {
namespace math {
namespace domains {

CoupledKnobDomain::CoupledKnobDomain(
    double min_val,
    double max_val,
    std::shared_ptr<Knob> label,
    std::vector<std::shared_ptr<LabelledDomain<Knob>>> coupled_domains)
    : CoupledLabelledDomain<Knob>(min_val, max_val, label, coupled_domains) {}

CoupledKnobDomain::CoupledKnobDomain() = default;

template <class Archive>
void CoupledKnobDomain::serialize(Archive& ar) {
  ar(cereal::base_class<CoupledLabelledDomain<Knob>>(this));
}

}  // namespace domains
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::domains::CoupledKnobDomain)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::domains::CoupledKnobDomain)
