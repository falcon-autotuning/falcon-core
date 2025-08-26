/**
 * @file CoupledKnobDomain.hpp
 * @brief Defines the CoupledKnobDomain class for FalconCore.
 */

#pragma once

#include "falcon_core/instrument_interfaces/names/Knob.hpp"
#include "falcon_core/math/domains/CoupledLabelledDomain.hpp"

namespace falcon_core {
namespace math {
namespace domains {

/**
 * @brief Coupled domain for Knob objects.
 */
class CoupledKnobDomain
    : public CoupledLabelledDomain<instrument_interfaces::names::Knob> {
 public:
  using Knob = instrument_interfaces::names::Knob;
  /**
   * @brief Construct a coupled knob domain.
   * @param min_val Minimum value.
   * @param max_val Maximum value.
   * @param label Shared pointer to knob label.
   * @param coupled_domains Vector of coupled knob domains.
   */
  CoupledKnobDomain(
      double                                             min_val,
      double                                             max_val,
      std::shared_ptr<Knob>                              label,
      std::vector<std::shared_ptr<LabelledDomain<Knob>>> coupled_domains)
      : CoupledLabelledDomain<Knob>(min_val, max_val, label, coupled_domains) {}

 private:
  friend class cereal::access;
  CoupledKnobDomain() = default;
  /**
   * @brief Serialization method for cereal.
   */
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<CoupledLabelledDomain<Knob>>(this));
  }
};

}  // namespace domains
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
using namespace falcon_core::math::domains;

CEREAL_REGISTER_TYPE(falcon_core::math::domains::CoupledKnobDomain)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::math::domains::CoupledKnobDomain)
#endif
