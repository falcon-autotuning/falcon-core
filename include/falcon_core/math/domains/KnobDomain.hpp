/**
 * @file KnobDomain.hpp
 * @brief Defines the KnobDomain class for FalconCore.
 */

#pragma once

#include "falcon_core/math/domains/BaseLabelledDomain.hpp"
#include "falcon_core/instrument_interfaces/names/Knob.hpp"

namespace falcon_core {
namespace math {
namespace domains {

/**
 * @brief Domain for a Knob object.
 */
class KnobDomain : public BaseLabelledDomain<instrument_interfaces::names::Knob> {
 public:
  using Knob = instrument_interfaces::names::Knob;
  /**
   * @brief Construct a knob domain.
   * @param min_val Minimum value.
   * @param max_val Maximum value.
   * @param knob Shared pointer to knob.
   */
  KnobDomain(double min_val, double max_val, std::shared_ptr<Knob> knob)
      : BaseLabelledDomain<Knob>(min_val, max_val, knob) {}

  /**
   * @brief Get the knob.
   * @return Shared pointer to knob.
   */
  const std::shared_ptr<Knob>& knob() const { return this->label(); }

 private:
  friend class cereal::access;
  KnobDomain() = default;
  /**
   * @brief Serialization method for cereal.
   */
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
