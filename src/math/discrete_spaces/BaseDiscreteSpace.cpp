#include "falcon_core/math/discrete_spaces/BaseDiscreteSpace.hpp"

#include <stdexcept>

#include "falcon_core/instrument_interfaces/names/Knob.hpp"
#include "falcon_core/math/domains/CoupledKnobDomain.hpp"

namespace falcon_core::math::discrete_spaces {

BaseDiscreteSpace::BaseDiscreteSpace() = default;
BaseDiscreteSpace::BaseDiscreteSpace(
    const spaces::UnitSpaceSP&                     space,
    const AxesSP<domains::CoupledKnobDomain>&      axes,
    const AxesSP<generic::Map<std::string, bool>>& increasing)
    : _space(space), _axes(axes), _increasing(increasing) {
  validate_unit_space_dimensionality_matches_knobs();
  validate_knob_uniqueness();
}
const spaces::UnitSpaceSP& BaseDiscreteSpace::space() const { return _space; }
const AxesSP<domains::CoupledKnobDomain>& BaseDiscreteSpace::axes() const {
  return _axes;
}
const AxesSP<generic::Map<std::string, bool>>& BaseDiscreteSpace::increasing()
    const {
  return _increasing;
}
const instrument_interfaces::names::KnobsSP BaseDiscreteSpace::knobs() const {
  instrument_interfaces::names::KnobsSP knobs;
  for (const domains::CoupledKnobDomainSP axis : *axes()) {
    for (const instrument_interfaces::names::KnobSP knob : *axis->knobs()) {
      knobs->push_back(knob);
    }
  }
  return knobs;
}
void BaseDiscreteSpace::validate_unit_space_dimensionality_matches_knobs()
    const {
  if (_space->dimension() != _axes->size()) {
    throw std::invalid_argument(
        "Unit space dimensionality does not match number of knob axes.");
  }
}
void BaseDiscreteSpace::validate_knob_uniqueness() const {
  std::set<std::string> old_names;
  for (const domains::CoupledKnobDomainSP& axis : *_axes) {
    std::set<std::string> new_names(axis->knobs()->get_default_names()->begin(),
                                    axis->knobs()->get_default_names()->end());
    assert(std::none_of(new_names.begin(),
                        new_names.end(),
                        [&](const std::string& name) {
                          return old_names.count(name);
                        }) &&
           "The default names must be unique.");
    old_names.insert(new_names.begin(), new_names.end());
  }
}
const int BaseDiscreteSpace::get_axis(
    const instrument_interfaces::names::KnobSP& knob) const {
  for (domains::CoupledKnobDomainSP axis : *_axes) {
    if (axis->knobs()->contains(knob)) {
      return _axes->index(axis);
    }
  }
  throw std::runtime_error("Knob " + knob->default_name() +
                           " not found in the axes.");
}
const domains::DomainSP BaseDiscreteSpace::get_domain(
    const instrument_interfaces::names::KnobSP& knob) const {
  int axis = get_axis(knob);
  return _axes->at(axis)->get_domain(knob);
}
const AxesSP<double> BaseDiscreteSpace::get_projection(
    const AxesSP<instrument_interfaces::names::Knob>& projection) const {
  // Validate dimensionality
  if (projection->size() != _space->dimension()) {
    throw std::runtime_error(
        "The projection dimensionality must be less than or equal to the space "
        "dimensionality.");
  }

  // Get projection axes indices
  std::vector<int> projection_axes;
  for (const auto& knob : *projection) {
    projection_axes.push_back(get_axis(knob));
  }

  // Check uniqueness
  std::set<int> unique_axes(projection_axes.begin(), projection_axes.end());
  if (projection->size() != unique_axes.size()) {
    throw std::runtime_error("The projection axes must be unique.");
  }

  // Create unit projections
  auto unitprojections =
      _space->create_array(std::make_shared<Axes<int>>(projection_axes));

  std::vector<arrays::ControlArray> scaled_projections;
  for (size_t i = 0; i < unitprojections->size(); ++i) {
    auto unitprojection = unitprojections->at(i);
    auto knob           = projection->at(i);
    auto increasing_map = _increasing->at(i);

    auto        domain     = get_domain(knob);
    double      difference = domain->range();
    std::string index      = knob->instrument_facing_name();
    int         sign       = increasing_map->at(index) ? 1 : -1;
    double value = sign > 0 ? domain->lesser_bound() : domain->greater_bound();
    scaled_projections.push_back(
        *(*(*(*unitprojection * difference) * sign) + value));
  }
  return std::make_shared<Axes<double>>(scaled_projections);
}

}  // namespace falcon_core::math::discrete_spaces
CEREAL_REGISTER_TYPE(falcon_core::math::discrete_spaces::BaseDiscreteSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::discrete_spaces::BaseDiscreteSpace)
