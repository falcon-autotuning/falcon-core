#include "falcon_core/math/discrete_spaces/DiscreteSpace.hpp"

#include <stdexcept>

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/domains/CoupledLabelledDomain.hpp"

namespace falcon_core::math::discrete_spaces {

DiscreteSpace::DiscreteSpace() = default;
DiscreteSpace::DiscreteSpace(
    const UnitSpaceSP&                             space,
    const AxesSP<domains::CoupledLabelledDomain>&  axes,
    const AxesSP<generic::Map<std::string, bool>>& increasing)
    : _space(space), _axes(axes), _increasing(increasing) {
  validate_unit_space_dimensionality_matches_knobs();
  validate_knob_uniqueness();
}
DiscreteSpaceSP DiscreteSpace::CartesianDiscreteSpace(
    const AxesSP<int>&                             divisions,
    const AxesSP<domains::CoupledLabelledDomain>&  axes,
    const AxesSP<generic::Map<std::string, bool>>& increasing,
    const domains::DomainSP&                       domain) {
  if (divisions->size() != axes->size()) {
    throw std::runtime_error(
        "The number of division of each axis must be the same size as the axes "
        "for the sweeps.");
  }
  if (divisions->size() != increasing->size()) {
    throw std::runtime_error(
        "The number of division of each axis must be the same size as the "
        "increasing for the sweeps.");
  }
  AxesSP<double> deltas;
  for (int d : *divisions) deltas->push_back(domain->range() / d);
  auto space = UnitSpace::CartesianSpace(deltas, domain);
  return std::make_shared<DiscreteSpace>(space, axes, increasing);
}
DiscreteSpaceSP DiscreteSpace::CartesianDiscreteSpace1D(
    const int&                               division,
    const domains::CoupledLabelledDomainSP&  shared_domain,
    const generic::MapSP<std::string, bool>& increasing,
    const domains::DomainSP&                 domain) {
  return DiscreteSpace::CartesianDiscreteSpace(
      std::make_shared<Axes<int>>(std::vector<int>{division}),
      std::make_shared<Axes<domains::CoupledLabelledDomain>>(
          std::vector<domains::CoupledLabelledDomainSP>{shared_domain}),
      std::make_shared<Axes<generic::Map<std::string, bool>>>(
          std::vector{increasing}));
}
const UnitSpaceSP& DiscreteSpace::space() const { return _space; }
const AxesSP<domains::CoupledLabelledDomain>& DiscreteSpace::axes() const {
  return _axes;
}
const AxesSP<generic::Map<std::string, bool>>& DiscreteSpace::increasing()
    const {
  return _increasing;
}
const instrument_interfaces::names::PortsSP DiscreteSpace::knobs() const {
  instrument_interfaces::names::PortsSP knobs;
  for (const domains::CoupledLabelledDomainSP axis : *axes()) {
    for (const instrument_interfaces::names::InstrumentPortSP knob :
         *axis->labels()) {
      knobs->push_back(knob);
    }
  }
  return knobs;
}
void DiscreteSpace::validate_unit_space_dimensionality_matches_knobs() const {
  if (_space->dimension() != _axes->size()) {
    throw std::invalid_argument(
        "Unit space dimensionality does not match number of knob axes.");
  }
}
void DiscreteSpace::validate_knob_uniqueness() const {
  std::set<std::string> old_names;
  for (const domains::CoupledLabelledDomainSP& axis : *_axes) {
    std::set<std::string> new_names(
        axis->labels()->get_default_names()->begin(),
        axis->labels()->get_default_names()->end());
    assert(std::none_of(new_names.begin(),
                        new_names.end(),
                        [&](const std::string& name) {
                          return old_names.count(name);
                        }) &&
           "The default names must be unique.");
    old_names.insert(new_names.begin(), new_names.end());
  }
}
const int DiscreteSpace::get_axis(
    const instrument_interfaces::names::InstrumentPortSP& knob) const {
  for (domains::CoupledLabelledDomainSP axis : *_axes) {
    if (axis->labels()->contains(knob)) {
      return _axes->index(axis);
    }
  }
  throw std::runtime_error("Knob " + knob->default_name() +
                           " not found in the axes.");
}
const domains::DomainSP DiscreteSpace::get_domain(
    const instrument_interfaces::names::InstrumentPortSP& knob) const {
  int axis = get_axis(knob);
  return _axes->at(axis)->get_domain(knob);
}
const AxesSP<arrays::LabelledControlArray> DiscreteSpace::get_projection(
    const AxesSP<instrument_interfaces::names::InstrumentPort>& projection)
    const {
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

  std::vector<arrays::ControlArraySP> scaled_projections;
  for (size_t i = 0; i < unitprojections->size(); ++i) {
    auto unitprojection = unitprojections->at(i);
    auto knob           = projection->at(i);
    auto increasing_map = _increasing->at(i);

    auto        domain     = get_domain(knob);
    double      difference = domain->range();
    std::string index      = knob->instrument_facing_name();
    int         sign       = increasing_map->at(index) ? 1 : -1;
    double value = sign > 0 ? domain->lesser_bound() : domain->greater_bound();
    scaled_projections.push_back(*(*(*unitprojection * difference) * sign) +
                                 value);
  }
  generic::ListSP<arrays::LabelledControlArray> container;
  for (int i = 0; i <= projection_axes.size(); i++) {
    container->push_back(std::make_shared<arrays::LabelledControlArray>(
        scaled_projections.at(i), projection->at(i)));
  }
  return std::make_shared<Axes<arrays::LabelledControlArray>>(container);
}

}  // namespace falcon_core::math::discrete_spaces
CEREAL_REGISTER_TYPE(falcon_core::math::discrete_spaces::DiscreteSpace)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::discrete_spaces::DiscreteSpace)
