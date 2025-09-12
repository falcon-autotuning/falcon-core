#pragma once

#include "falcon_core/instrument_interfaces/names/Knob.hpp"
#include "falcon_core/math/domains/BaseCoupledLabelledDomain.hpp"

namespace falcon_core::math::domains {

class CoupledKnobDomain
    : public BaseCoupledLabelledDomain<instrument_interfaces::names::Knob> {
 public:
  CoupledKnobDomain();
  /**
   * @brief Construct from a vector of labelled domains.
   * @param domains Vector of shared pointers to labelled domains.
   */
  CoupledKnobDomain(
      const std::vector<
          BaseLabelledDomainSP<instrument_interfaces::names::Knob>>& init);

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<
        BaseCoupledLabelledDomain<instrument_interfaces::names::Knob>>(this));
  };
};
}  // namespace falcon_core::math::domains
