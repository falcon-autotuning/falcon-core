#pragma once

#include "falcon_core/instrument_interfaces/names/Knob.hpp"
#include "falcon_core/math/domains/BaseLabelledDomain.hpp"
namespace falcon_core::math::domains {
/**
 * @brief A knob domain, which is a domain associated with a Knob.
 */
class KnobDomain
    : public BaseLabelledDomain<instrument_interfaces::names::Knob> {
 public:
  /**
   * @brief Initialize a KnobDomain requires knowing instrument details and
   * controls.
   * @param default_name The default name of the knob.
   * @param bounds The bounds of the knob's domain.
   * @param pseudo_name The optional colloquial name of the knob.
   * @param instrument_type The type of instrument the knob belongs to.
   * @param lesser_bound_contained Whether the minimum value is included in the
   * domain.
   * @param greater_bound_contained Whether the maximum value is included in the
   * domain.
   * @param units the units of the knob's domain.
   * @param description A description of the knob.
   */
  KnobDomain(const std::string&                                  default_name,
             const std::pair<double, double>&                    bounds,
             const physics::device_structures::BaseConnectionSP& psuedo_name,
             const instrument_interfaces::Instrument& instrument_type,
             bool                                lesser_bound_contained  = true,
             bool                                greater_bound_contained = true,
             const physics::units::SymbolUnitSP& units =
                 physics::units::SymbolUnit::Volt(),
             const std::string& description = "");
  /**
   * @brief Create a KnobDomain from an existing knob and domain.
   * @param knob The knob to associate with the domain.
   * @param domain The domain to associate with the knob.
   * @return A created KnobDomain.
   */
  static std::shared_ptr<KnobDomain> from_knob_and_domain(
      const instrument_interfaces::names::KnobSP& knob, const DomainSP& domain);
  /**
   * @brief Create a KnobDomain from an existing domain.
   * @param domain The domain to associate with the knob.
   * @param default_name The default name of the knob.
   * @param pseudo_name The optional colloquial name of the knob.
   * @param instrument_type The type of instrument the knob belongs to.
   * @param units the units of the knob's domain.
   * @param description A description of the knob.
   * @return A created KnobDomain.
   */
  static std::shared_ptr<KnobDomain> from_domain(
      const DomainSP&                                     domain,
      const std::string&                                  default_name,
      const physics::device_structures::BaseConnectionSP& pseudo_name,
      const instrument_interfaces::Instrument&            instrument_type,
      const physics::units::SymbolUnitSP&                 units =
          physics::units::SymbolUnit::Volt(),
      const std::string& description = "");
  /**
   * @brief Create a KnobDomain from an existing knob.
   * @param knob The knob to associate with the domain.
   * @param bounds The bounds of the knob's domain.
   * @param lesser_bound_contained Whether the minimum value is included in the
   * domain.
   * @param greater_bound_contained Whether the maximum value is included in the
   * domain.
   * @return A created KnobDomain.
   */
  static std::shared_ptr<KnobDomain> from_knob(
      const instrument_interfaces::names::KnobSP& knob,
      const std::pair<double, double>&            bounds,
      const bool                                  lesser_bound_contained = true,
      const bool greater_bound_contained = true);
  /**
   * @brief Returns the associated knob.
   */
  const std::shared_ptr<instrument_interfaces::names::Knob>& knob() const;

 private:
  friend class cereal::access;
  KnobDomain();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<
        BaseLabelledDomain<instrument_interfaces::names::Knob>>(this));
  }
};
using KnobDomainSP = std::shared_ptr<KnobDomain>;
}  // namespace falcon_core::math::domains
