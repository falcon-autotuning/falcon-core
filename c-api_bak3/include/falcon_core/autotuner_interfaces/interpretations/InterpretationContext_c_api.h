#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext_c_api.h"
#include "falcon_core/generic/ListMeasurementContext_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/AxesMeasurementContext_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
typedef void* InterpretationContextHandle;

// Constructors
InterpretationContextHandle InterpretationContext_create(
    AxesMeasurementContextHandle independant_variables,
    ListMeasurementContextHandle dependant_variables,
    SymbolUnitHandle             unit);

// Destructor
void InterpretationContext_destroy(InterpretationContextHandle handle);

// Methods
/* AUTO-DOC from cpp: InterpretationContext_independent_variables | falcon_core::autotuner_interfaces::interpretations::InterpretationContext::independent_variables */
/**
 * @brief (from C++: falcon_core::autotuner_interfaces::interpretations::InterpretationContext::independent_variables)
 * @brief Return the independent variables (sweep parameters).
 */
AxesMeasurementContextHandle InterpretationContext_independent_variables(
    InterpretationContextHandle handle);
/* AUTO-DOC from cpp: InterpretationContext_dependent_variables | falcon_core::autotuner_interfaces::interpretations::InterpretationContext::dependent_variables */
/**
 * @brief (from C++: falcon_core::autotuner_interfaces::interpretations::InterpretationContext::dependent_variables)
 * @brief Return the dependent variables (measured parameters).
 */
ListMeasurementContextHandle InterpretationContext_dependent_variables(
    InterpretationContextHandle handle);
/* AUTO-DOC from cpp: InterpretationContext_unit | falcon_core::autotuner_interfaces::interpretations::InterpretationContext::unit */
/**
 * @brief (from C++: falcon_core::autotuner_interfaces::interpretations::InterpretationContext::unit)
 * @brief Return the unit for interpreting the values.
 */
SymbolUnitHandle InterpretationContext_unit(InterpretationContextHandle handle);
/* AUTO-DOC from cpp: InterpretationContext_dimension | falcon_core::autotuner_interfaces::interpretations::InterpretationContext::dimension */
/**
 * @brief (from C++: falcon_core::autotuner_interfaces::interpretations::InterpretationContext::dimension)
 * @brief Return the dimensionality of the measurement (number of independent
 * variables).
 */
int  InterpretationContext_dimension(InterpretationContextHandle handle);
void InterpretationContext_dependent_variable(
    InterpretationContextHandle handle, MeasurementContextHandle variable);
/* AUTO-DOC from cpp: InterpretationContext_replace_dependent_variable | falcon_core::autotuner_interfaces::interpretations::InterpretationContext::replace_dependent_variable */
/**
 * @brief (from C++: falcon_core::autotuner_interfaces::interpretations::InterpretationContext::replace_dependent_variable)
 * @brief Replace a dependent variable at the specified index.
 * @param index The count corresponding to the location of the variable to
 * replace.
 * @param variable The varaible that is to be stored at the location.
 */
void InterpretationContext_replace_dependent_variable(
    InterpretationContextHandle handle,
    int                         index,
    MeasurementContextHandle    variable);
MeasurementContextHandle InterpretationContext_get_independent_variables(
    InterpretationContextHandle handle, int index);
/* AUTO-DOC from cpp: InterpretationContext_with_unit | falcon_core::autotuner_interfaces::interpretations::InterpretationContext::with_unit */
/**
 * @brief (from C++: falcon_core::autotuner_interfaces::interpretations::InterpretationContext::with_unit)
 * @brief Create a new interpretation context with the given
 * unit.
 * @param unit The physical unit to use
 * @return A new interpretation context with the same variables but a
 * different unit.
 */
InterpretationContextHandle InterpretationContext_with_unit(
    InterpretationContextHandle handle, SymbolUnitHandle unit);
bool InterpretationContext_equal(InterpretationContextHandle a,
                                 InterpretationContextHandle b);
bool InterpretationContext_not_equal(InterpretationContextHandle a,
                                     InterpretationContextHandle b);

// Serialization (from Song)
StringHandle InterpretationContext_to_json_string(
    InterpretationContextHandle handle);
InterpretationContextHandle InterpretationContext_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
