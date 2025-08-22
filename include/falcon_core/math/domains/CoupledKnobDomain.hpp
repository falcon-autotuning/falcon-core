#pragma once

#include "falcon_core/instrument_interfaces/names/Knob.hpp"
#include "falcon_core/math/domains/CoupledLabelledDomain.hpp"

namespace falcon_core {
namespace math {
namespace domains {

class CoupledKnobDomain
    : public CoupledLabelledDomain<instrument_interfaces::names::Knob> {
 public:
  using Knob = instrument_interfaces::names::Knob;
  CoupledKnobDomain(
      double                                             min_val,
      double                                             max_val,
      std::shared_ptr<Knob>                              label,
      std::vector<std::shared_ptr<LabelledDomain<Knob>>> coupled_domains)
      : CoupledLabelledDomain<Knob>(min_val, max_val, label, coupled_domains) {}

 private:
  friend class cereal::access;
  CoupledKnobDomain() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<CoupledLabelledDomain<Knob>>(this));
  }
};

}  // namespace domains
}  // namespace math
}  // namespace falcon_core

using namespace falcon_core::math::domains;

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::math::domains::CoupledKnobDomain)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::domains::CoupledKnobDomain)
#endif
