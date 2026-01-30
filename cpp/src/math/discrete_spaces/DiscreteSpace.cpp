#include "falcon_core/math/discrete_spaces/DiscreteSpace.hpp"

#include <stdexcept>

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/arrays/LabelledControlArray.hpp"
#include "falcon_core/math/domains/CoupledLabelledDomain.hpp"

namespace falcon_core {
namespace math {
namespace discrete_spaces {
DiscreteSpace::DiscreteSpace(const DiscreteSpace& other) {
  std::shared_lock<std::shared_timed_mutex> lock_space(other._mu_space,
                                                       std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_axes(other._mu_axes,
                                                      std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_increasing(
      other._mu_increasing, std::defer_lock);
  std::lock(lock_space, lock_axes, lock_increasing);
  if (!other.space() || !other.axes() || !other.increasing()) {
    throw std::invalid_argument(
        "DiscreteSpace copy constructor: Other DiscreteSpace contains null "
        "shared pointers.");
  }
  _space = std::make_shared<UnitSpace>(*other.space());
  _axes = std::make_shared<Axes<domains::CoupledLabelledDomain>>(*other.axes());
  _increasing = std::make_shared<Axes<generic::Map<std::string, bool>>>(
      *other.increasing());
}
DiscreteSpace& DiscreteSpace::operator=(const DiscreteSpace& other) {
  if (this != &other) {
    std::shared_lock<std::shared_timed_mutex> lock_space(other._mu_space,
                                                         std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_axes(other._mu_axes,
                                                        std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_increasing(
        other._mu_increasing, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_o(_mu_space,
                                                     std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_a(_mu_axes, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_i(_mu_increasing,
                                                     std::defer_lock);
    std::lock(lock_space, lock_axes, lock_increasing, lock_o, lock_a, lock_i);
    if (!other.space() || !other.axes() || !other.increasing()) {
      throw std::invalid_argument(
          "DiscreteSpace copy constructor: Other DiscreteSpace contains null "
          "shared pointers.");
    }
    _space = std::make_shared<UnitSpace>(*other.space());
    _axes =
        std::make_shared<Axes<domains::CoupledLabelledDomain>>(*other.axes());
    _increasing = std::make_shared<Axes<generic::Map<std::string, bool>>>(
        *other.increasing());
  }
  return *this;
}
DiscreteSpace::DiscreteSpace() = default;
DiscreteSpace::DiscreteSpace(
    const UnitSpaceSP&                             space,
    const AxesSP<domains::CoupledLabelledDomain>&  axes,
    const AxesSP<generic::Map<std::string, bool>>& increasing)
    : _space(space), _axes(axes), _increasing(increasing) {
  if (!space || !axes || !increasing) {
    throw std::invalid_argument(
        "DiscreteSpace: The space, axes, and increasing cannot be null.");
  }
  validate_unit_space_dimensionality_matches_knobs();
  validate_knob_uniqueness();
}
DiscreteSpaceSP DiscreteSpace::CartesianDiscreteSpace(
    const AxesSP<int>&                             divisions,
    const AxesSP<domains::CoupledLabelledDomain>&  axes,
    const AxesSP<generic::Map<std::string, bool>>& increasing,
    const domains::DomainSP&                       domain) {
  if (!divisions || !axes || !increasing || !domain) {
    throw std::invalid_argument(
        "DiscreteSpace: The divisions, axes, increasing, and domain cannot be "
        "null.");
  }
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
  AxesSP<double> deltas = std::make_shared<Axes<double>>();
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
          std::vector<generic::MapSP<std::string, bool>>{increasing}));
}
const UnitSpaceSP& DiscreteSpace::space() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_space);
  return _space;
}
const AxesSP<domains::CoupledLabelledDomain>& DiscreteSpace::axes() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_axes);
  return _axes;
}
const AxesSP<generic::Map<std::string, bool>>& DiscreteSpace::increasing()
    const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_increasing);
  return _increasing;
}
const instrument_interfaces::names::PortsSP DiscreteSpace::knobs() const {
  instrument_interfaces::names::PortsSP knobs =
      std::make_shared<instrument_interfaces::names::Ports>();
  auto axes = *this->axes();
  for (const domains::CoupledLabelledDomainSP axis : axes) {
    auto labels = *axis->labels();
    for (const instrument_interfaces::names::InstrumentPortSP knob : labels) {
      knobs->push_back(knob);
    }
  }
  return knobs;
}
void DiscreteSpace::validate_unit_space_dimensionality_matches_knobs() const {
  if (space()->dimension() != axes()->size()) {
    throw std::invalid_argument(
        "Unit space dimensionality does not match number of knob axes.");
  }
}
void DiscreteSpace::validate_knob_uniqueness() const {
  std::set<std::string> old_names;
  auto                  axes = *this->axes();
  for (const domains::CoupledLabelledDomainSP& axis : axes) {
    auto                  labels        = axis->labels();
    auto                  default_names = labels->get_default_names();
    std::set<std::string> new_names(default_names->begin(),
                                    default_names->end());
    if (std::any_of(
            new_names.begin(), new_names.end(), [&](const std::string& name) {
              return old_names.count(name);
            })) {
      throw std::runtime_error("The default names must be unique.");
    }
    old_names.insert(new_names.begin(), new_names.end());
  }
}
const int DiscreteSpace::get_axis(
    const instrument_interfaces::names::InstrumentPortSP& knob) const {
  if (!knob) {
    throw std::invalid_argument(
        "DiscreteSpace: The knob label cannot be null.");
  }
  auto axes = *this->axes();
  for (domains::CoupledLabelledDomainSP axis : axes) {
    auto labels = axis->labels();
    if (labels->contains(knob)) {
      return this->axes()->index(axis);
    }
  }
  throw std::runtime_error("DiscreteSpace: Knob " + knob->default_name() +
                           " not found in the axes.");
}
const domains::DomainSP DiscreteSpace::get_domain(
    const instrument_interfaces::names::InstrumentPortSP& knob) const {
  if (!knob) {
    throw std::invalid_argument(
        "DiscreteSpace: The knob label cannot be null.");
  }
  int axis = get_axis(knob);
  return axes()->at(axis)->get_domain(knob);
}
const AxesSP<arrays::LabelledControlArray> DiscreteSpace::get_projection(
    const AxesSP<instrument_interfaces::names::InstrumentPort>& projection)
    const {
  if (!projection) {
    throw std::invalid_argument(
        "DiscreteSpace: The projection must not be null.");
  }
  // Validate dimensionality
  if (projection->size() != space()->dimension()) {
    throw std::runtime_error(
        "DiscreteSpace: The projection dimensionality must be less than or "
        "equal to the space "
        "dimensionality.");
  }

  // Get projection axes indices
  std::vector<int> projection_axes;
  for (const instrument_interfaces::names::InstrumentPortSP& knob :
       *projection) {
    projection_axes.push_back(get_axis(knob));
  }

  // Check uniqueness
  std::set<int> unique_axes(projection_axes.begin(), projection_axes.end());
  if (projection->size() != unique_axes.size()) {
    throw std::runtime_error(
        "DiscreteSpace: The projection axes must be unique.");
  }

  // Create unit projections
  auto unitprojections =
      space()->create_array(std::make_shared<Axes<int>>(projection_axes));

  std::vector<arrays::ControlArraySP> scaled_projections;
  for (size_t i = 0; i < unitprojections->size(); ++i) {
    auto unitprojection = unitprojections->at(i);
    auto knob           = projection->at(i);
    auto increasing_map = increasing()->at(i);

    auto        domain     = get_domain(knob);
    double      difference = domain->range();
    std::string index      = knob->instrument_facing_name();
    int         sign       = increasing_map->at(index) ? 1 : -1;
    double value = sign > 0 ? domain->lesser_bound() : domain->greater_bound();
    scaled_projections.push_back(*(*(*unitprojection * difference) * sign) +
                                 value);
  }
  generic::ListSP<arrays::LabelledControlArray> container =
      std::make_shared<generic::List<arrays::LabelledControlArray>>();
  for (int i = 0; i < projection_axes.size(); i++) {
    container->push_back(std::make_shared<arrays::LabelledControlArray>(
        scaled_projections.at(i), projection->at(i)));
  }
  return std::make_shared<Axes<arrays::LabelledControlArray>>(container);
}
bool DiscreteSpace::operator==(const DiscreteSpace& other) const {
  if (this == &other) return true;
  return (*space() == *other.space()) && (*axes() == *other.axes()) &&
         (*increasing() == *other.increasing());
}
bool DiscreteSpace::operator!=(const DiscreteSpace& other) const {
  return !(*this == other);
}
}  // namespace discrete_spaces
}  // namespace math
}  // namespace falcon_core
