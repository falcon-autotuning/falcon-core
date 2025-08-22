#pragma once

#include "falcon_core/math/domains/BaseLabelledDomain.hpp"
#include "falcon_core/instrument_interfaces/names/Knob.hpp"

namespace falcon_core {
namespace math {
namespace domains {

class KnobDomain : public BaseLabelledDomain<instrument_interfaces::names::Knob> {
 public:
  using Knob = instrument_interfaces::names::Knob;
  KnobDomain(double min_val, double max_val, std::shared_ptr<Knob> knob)
      : BaseLabelledDomain<Knob>(min_val, max_val, knob) {}

  const std::shared_ptr<Knob>& knob() const { return this->label(); }

 private:
  friend class cereal::access;
  KnobDomain() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseLabelledDomain<Knob>>(this));
  }
};

}  // namespace domains
}  // namespace math
}  // namespace falcon_core

using namespace falcon_core::math::domains;

#ifndef SWIG
CEREAL_REGISTER_TYPE(falcon_core::math::domains::KnobDomain)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::domains::KnobDomain)
#endif
