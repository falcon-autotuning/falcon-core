#include "falcon_core/math/domains/KnobDomain.hpp"

#include "falcon_core/instrument_interfaces/names/Knob.hpp"

namespace falcon_core::math::domains {
KnobDomain::KnobDomain() = default;
KnobDomain::KnobDomain(
    const std::string&                                  default_name,
    const std::pair<double, double>&                    bounds,
    const physics::device_structures::BaseConnectionSP& psuedo_name,
    const instrument_interfaces::Instrument&            instrument_type,
    bool                                                lesser_bound_contained,
    bool                                                greater_bound_contained,
    const physics::units::SymbolUnitSP&                 units,
    const std::string&                                  description)
    : BaseLabelledDomain<instrument_interfaces::names::Knob>(
          bounds,
          std::make_shared<instrument_interfaces::names::Knob>(
              default_name, psuedo_name, instrument_type, units, description),
          lesser_bound_contained,
          greater_bound_contained) {}

std::shared_ptr<KnobDomain> KnobDomain::from_knob_and_domain(
    const instrument_interfaces::names::KnobSP& knob, const DomainSP& domain) {
  return std::make_shared<KnobDomain>(knob->default_name(),
                                      domain->bounds(),
                                      knob->pseudo_name(),
                                      knob->instrument_type(),
                                      domain->lesser_bound_contained(),
                                      domain->greater_bound_contained(),
                                      knob->units(),
                                      knob->description());
}
std::shared_ptr<KnobDomain> KnobDomain::from_domain(
    const DomainSP&                                     domain,
    const std::string&                                  default_name,
    const physics::device_structures::BaseConnectionSP& pseudo_name,
    const instrument_interfaces::Instrument&            instrument_type,
    const physics::units::SymbolUnitSP&                 units,
    const std::string&                                  description) {
  return std::make_shared<KnobDomain>(default_name,
                                      domain->bounds(),
                                      pseudo_name,
                                      instrument_type,
                                      domain->lesser_bound_contained(),
                                      domain->greater_bound_contained(),
                                      units,
                                      description);
}
std::shared_ptr<KnobDomain> KnobDomain::from_knob(
    const instrument_interfaces::names::KnobSP& knob,
    const std::pair<double, double>&            bounds,
    const bool                                  lesser_bound_contained,
    const bool                                  greater_bound_contained) {
  return std::make_shared<KnobDomain>(knob->default_name(),
                                      bounds,
                                      knob->pseudo_name(),
                                      knob->instrument_type(),
                                      lesser_bound_contained,
                                      greater_bound_contained,
                                      knob->units(),
                                      knob->description());
}
const std::shared_ptr<instrument_interfaces::names::Knob>& KnobDomain::knob()
    const {
  return this->label();
}
}  // namespace falcon_core::math::domains

CEREAL_REGISTER_TYPE(falcon_core::math::domains::KnobDomain)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::domains::KnobDomain)
