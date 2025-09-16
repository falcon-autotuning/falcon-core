#pragma once

#include "falcon_core/instrument_interfaces/names/Knobs.hpp"
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
  /**
   * @brief Return the knobs.
   */
  const instrument_interfaces::names::KnobsSP knobs() const;

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<
        BaseCoupledLabelledDomain<instrument_interfaces::names::Knob>>(this));
  };
};
using CoupledKnobDomainSP = std::shared_ptr<CoupledKnobDomain>;
}  // namespace falcon_core::math::domains
