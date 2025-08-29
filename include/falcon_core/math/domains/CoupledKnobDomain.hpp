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
      std::vector<std::shared_ptr<LabelledDomain<Knob>>> coupled_domains);

  CoupledKnobDomain();

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace domains
}  // namespace math
}  // namespace falcon_core
