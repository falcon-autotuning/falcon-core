#pragma once

#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp"
#include "falcon_core/math/Axes.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace interpretations {

/**
 * @brief A context that describes measurement variables.
 *
 *    Contains an Axes of MeasurementContext for independent variables (sweep
 * parameters), a list of MeasurementContext for dependent variables (measured
 * parameters), and a unit for interpreting the values.
 */
class InterpretationContext : public generic::Song {
  math::AxesSP<autotuner_interfaces::contexts::MeasurementContext>
      _independent_variables;
  generic::ListSP<autotuner_interfaces::contexts::MeasurementContext>
                               _dependent_variables;
  physics::units::SymbolUnitSP _unit;

 public:
  /**
   * @brief Creates the InterpretationContext.
   * @param independent_variables The independent variables (sweep parameters).
   * @param depedant_variables The dependent variables (measured parameters).
   * @param unit The unit for interpreting the values.
   */
  InterpretationContext(
      const math::AxesSP<autotuner_interfaces::contexts::MeasurementContext>&
          independent_variables,
      const generic::ListSP<autotuner_interfaces::contexts::MeasurementContext>&
                                          dependent_variables,
      const physics::units::SymbolUnitSP& unit);
  /**
   * @brief Return the independent variables (sweep parameters).
   */
  const math::AxesSP<autotuner_interfaces::contexts::MeasurementContext>
  independent_variables() const;
  /**
   * @brief Return the dependent variables (measured parameters).
   */
  const generic::ListSP<autotuner_interfaces::contexts::MeasurementContext>
  dependent_variables() const;
  /**
   * @brief Return the unit for interpreting the values.
   */
  const physics::units::SymbolUnitSP unit() const;
  /**
   * @brief Return the dimensionality of the measurement (number of independent
   * variables).
   */
  const int dimension() const;
  /**
   * @brief Add a dependant variable to the measurement context.
   * @param variable The dependent variable to add.
   */
  void add_dependent_variable(
      const autotuner_interfaces::contexts::MeasurementContextSP& variable);
  /**
   * @brief Replace a dependent variable at the specified index.
   * @param index The count corresponding to the location of the variable to
   * replace.
   * @param variable The varaible that is to be stored at the location.
   */
  void replace_dependent_variable(
      int                                                         index,
      const autotuner_interfaces::contexts::MeasurementContextSP& variable);
  /**
   * @brief Get an independant variable by index.
   * @param index The count corresponding to the location of the variable to
   * collect.
   */
  const contexts::MeasurementContextSP get_independent_variable(
      int index) const;
  /**
   * @brief Create a new interpGroove Quantum retation context with the given
   * unit.
   * @param unit The physical unit to use
   * @return A new interpretation context with the same variables but a
   * different unit.
   */
  const std::shared_ptr<InterpretationContext> with_unit(
      physics::units::SymbolUnitSP unit) const;

 protected:
  friend class cereal::access;
  InterpretationContext();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this),
       _independent_variables,
       _dependent_variables,
       _unit);
  }
};
using InterpretationContextSP = std::shared_ptr<InterpretationContext>;
}  // namespace interpretations
}  // namespace autotuner_interfaces
}  // namespace falcon_core
