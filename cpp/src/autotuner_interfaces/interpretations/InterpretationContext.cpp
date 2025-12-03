#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp"

#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace interpretations {
InterpretationContext::InterpretationContext(
    const InterpretationContext& other) {
  std::shared_lock<std::shared_timed_mutex> lock_independent_variables(
      other._mu_independent_variables, std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_dependent_variables(
      other._mu_dependent_variables, std::defer_lock);
  std::shared_lock<std::shared_timed_mutex> lock_unit(other._mu_unit,
                                                      std::defer_lock);
  std::lock(lock_independent_variables, lock_dependent_variables, lock_unit);
  _independent_variables = other._independent_variables;
  _dependent_variables   = other._dependent_variables;
  _unit                  = other._unit;
}
InterpretationContext InterpretationContext::operator=(
    const InterpretationContext& other) {
  if (this != &other) {
    std::shared_lock<std::shared_timed_mutex> lock_other_independent_variables(
        other._mu_independent_variables, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_other_dependent_variables(
        other._mu_dependent_variables, std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_other_unit(other._mu_unit,
                                                              std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_independent_variables(
        _mu_independent_variables, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_dependent_variables(
        _mu_dependent_variables, std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_unit(_mu_unit,
                                                        std::defer_lock);
    std::lock(lock_independent_variables,
              lock_dependent_variables,
              lock_unit,
              lock_other_independent_variables,
              lock_other_dependent_variables,
              lock_other_unit);
    _independent_variables = other._independent_variables;
    _dependent_variables   = other._dependent_variables;
    _unit                  = other._unit;
  }
  return *this;
}
InterpretationContext::InterpretationContext()
    : _independent_variables(
          std::make_shared<math::Axes<
              autotuner_interfaces::contexts::MeasurementContext>>()),
      _dependent_variables(
          std::make_shared<generic::List<
              autotuner_interfaces::contexts::MeasurementContext>>()),
      _unit(nullptr) {}
InterpretationContext::InterpretationContext(
    const math::AxesSP<autotuner_interfaces::contexts::MeasurementContext>&
        independent_variables,
    const generic::ListSP<autotuner_interfaces::contexts::MeasurementContext>&
                                        dependent_variables,
    const physics::units::SymbolUnitSP& unit)
    : _independent_variables(independent_variables),
      _dependent_variables(dependent_variables),
      _unit(unit) {
  if (!independent_variables) {
    throw std::invalid_argument(
        "InterpretationContext: Independent variables must not be null.");
  }
  if (!dependent_variables) {
    throw std::invalid_argument(
        "InterpretationContext: Dependent variables must not be null.");
  }
  if (!unit) {
    throw std::invalid_argument(
        "InterpretationContext: Unit must not be null.");
  }
}
const math::AxesSP<autotuner_interfaces::contexts::MeasurementContext>
InterpretationContext::independent_variables() const {
  std::shared_lock<std::shared_timed_mutex> lock_independent_variables(
      _mu_independent_variables);
  return _independent_variables;
}
const generic::ListSP<autotuner_interfaces::contexts::MeasurementContext>
InterpretationContext::dependent_variables() const {
  std::shared_lock<std::shared_timed_mutex> lock_dependent_variables(
      _mu_dependent_variables);
  return _dependent_variables;
}
const physics::units::SymbolUnitSP InterpretationContext::unit() const {
  std::shared_lock<std::shared_timed_mutex> lock_unit(_mu_unit);
  return _unit;
}
const int InterpretationContext::dimension() const {
  return independent_variables()->size();
}
void InterpretationContext::add_dependent_variable(
    const autotuner_interfaces::contexts::MeasurementContextSP&
        dependent_variable) {
  if (!dependent_variable) {
    throw std::invalid_argument("Dependent variable must not be null.");
  }
  dependent_variables()->push_back(dependent_variable);
}
void InterpretationContext::replace_dependent_variable(
    int index,
    const autotuner_interfaces::contexts::MeasurementContextSP&
        dependent_variable) {
  if (!dependent_variable) {
    throw std::invalid_argument("Dependent variable must not be null.");
  }
  if (index < 0 || index >= dependent_variables()->size()) {
    throw std::out_of_range("Index out of range");
  }

  (*_dependent_variables)[index] = dependent_variable;
}
const autotuner_interfaces::contexts::MeasurementContextSP
InterpretationContext::get_independent_variable(int index) const {
  if (index < 0 || index >= dimension()) {
    throw std::out_of_range("Index out of range");
  }
  return (*independent_variables())[index];
}
const InterpretationContextSP InterpretationContext::with_unit(
    physics::units::SymbolUnitSP unit) const {
  if (!unit) {
    throw std::invalid_argument("Unit must not be null.");
  }
  return std::make_shared<InterpretationContext>(
      independent_variables(), dependent_variables(), unit);
}
bool InterpretationContext::operator==(
    const InterpretationContext& other) const {
  if (dimension() != other.dimension()) {
    return false;
  }
  for (int i = 0; i < dimension(); i++) {
    if (*(get_independent_variable(i)) !=
        *(other.get_independent_variable(i))) {
      return false;
    }
  }
  if (*unit() != *other.unit()) {
    return false;
  }
  if (dependent_variables()->size() != other.dependent_variables()->size()) {
    return false;
  }
  for (size_t i = 0; i < dependent_variables()->size(); i++) {
    if (*(*dependent_variables())[i] != *(*other.dependent_variables())[i]) {
      return false;
    }
  }
  return true;
}
bool InterpretationContext::operator!=(
    const InterpretationContext& other) const {
  return !(*this == other);
}
}  // namespace interpretations
}  // namespace autotuner_interfaces
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext)
