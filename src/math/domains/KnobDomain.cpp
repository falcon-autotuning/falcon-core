#include "falcon_core/math/domains/KnobDomain.hpp"

namespace falcon_core {
namespace math {
namespace domains {

KnobDomain::KnobDomain(double min_val, double max_val, std::shared_ptr<Knob> knob)
    : BaseLabelledDomain<Knob>(min_val, max_val, knob) {}

const std::shared_ptr<KnobDomain::Knob>& KnobDomain::knob() const {
  return this->label();
}

KnobDomain::KnobDomain() = default;

template <class Archive>
void KnobDomain::serialize(Archive& ar) {
  ar(cereal::base_class<BaseLabelledDomain<Knob>>(this));
}

}  // namespace domains
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::domains::KnobDomain)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::domains::KnobDomain)
