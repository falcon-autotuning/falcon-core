#pragma once

#include "falcon_core/math/domains/BaseLabelledDomain.hpp"
#include "falcon_core/instrument_interfaces/names/Knob.hpp"

namespace falcon_core {
namespace math {
namespace domains {

class KnobDomain : public BaseLabelledDomain<instrument_interfaces::names::Knob> {
 public:
  using Knob = instrument_interfaces::names::Knob;
  KnobDomain(double min_val, double max_val, std::shared_ptr<Knob> knob);
  const std::shared_ptr<Knob>& knob() const;

 private:
  friend class cereal::access;
  KnobDomain();
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace domains
}  // namespace math
}  // namespace falcon_core
