#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp"

#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace interpretations {
InterpretationContext::InterpretationContext() = default;
InterpretationContext::InterpretationContext(
    const math::AxesSP<autotuner_interfaces::contexts::MeasurementContext>&
        independent_variables,
    const generic::ListSP<autotuner_interfaces::contexts::MeasurementContext>&
                                        dependent_variables,
    const physics::units::SymbolUnitSP& unit)
    : _independent_variables(independent_variables),
      _dependent_variables(dependent_variables),
      _unit(unit) {}
const math::AxesSP<autotuner_interfaces::contexts::MeasurementContext>
InterpretationContext::independent_variables() const {
  return _independent_variables;
}
const generic::ListSP<autotuner_interfaces::contexts::MeasurementContext>
InterpretationContext::dependent_variables() const {
  return _dependent_variables;
}
const physics::units::SymbolUnitSP InterpretationContext::unit() const {
  return _unit;
}
const int InterpretationContext::dimension() const {
  return _independent_variables->size();
}
void InterpretationContext::add_dependent_variable(
    const autotuner_interfaces::contexts::MeasurementContextSP&
        dependent_variable) {
  _dependent_variables->push_back(dependent_variable);
}
void InterpretationContext::replace_dependent_variable(
    int index,
    const autotuner_interfaces::contexts::MeasurementContextSP&
        dependent_variable) {
  if (index < 0 || index >= _dependent_variables->size()) {
    throw std::out_of_range("Index out of range");
  }

  (*_dependent_variables)[index] = dependent_variable;
}
const autotuner_interfaces::contexts::MeasurementContextSP
InterpretationContext::get_independent_variable(int index) const {
  if (index < 0 || index >= dimension()) {
    throw std::out_of_range("Index out of range");
  }
  return (*dependent_variables())[index];
}
const InterpretationContextSP InterpretationContext::with_unit(
    physics::units::SymbolUnitSP unit) const {
  return std::make_shared<InterpretationContext>(
      _independent_variables, _dependent_variables, unit);
}
}  // namespace interpretations
}  // namespace autotuner_interfaces
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::interpretations::InterpretationContext)
