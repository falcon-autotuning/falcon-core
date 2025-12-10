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

// @category:allocation
InterpretationContextHandle InterpretationContext_copy(
    InterpretationContextHandle handle);
// @category:deallocation
void InterpretationContext_destroy(InterpretationContextHandle handle);
// @category:read
bool InterpretationContext_equal(InterpretationContextHandle handle,
                                 InterpretationContextHandle other);
// @category:read
bool InterpretationContext_not_equal(InterpretationContextHandle handle,
                                     InterpretationContextHandle other);
// @category:read
StringHandle InterpretationContext_to_json_string(
    InterpretationContextHandle handle);
// @category:allocation
InterpretationContextHandle InterpretationContext_from_json_string(
    StringHandle json);
// @category:allocation
InterpretationContextHandle InterpretationContext_create(
    AxesMeasurementContextHandle independant_variables,
    ListMeasurementContextHandle dependant_variables,
    SymbolUnitHandle             unit);
// @category:read
/* AUTO-DOC from cpp: InterpretationContext_independent_variables |
 * falcon_core::autotuner_interfaces::interpretations::InterpretationContext::independent_variables
 */
/**
 * @brief Return the independent variables (sweep parameters).
 */
AxesMeasurementContextHandle InterpretationContext_independent_variables(
    InterpretationContextHandle handle);
// @category:read
/* AUTO-DOC from cpp: InterpretationContext_dependent_variables |
 * falcon_core::autotuner_interfaces::interpretations::InterpretationContext::dependent_variables
 */
/**
 * @brief Return the dependent variables (measured parameters).
 */
ListMeasurementContextHandle InterpretationContext_dependent_variables(
    InterpretationContextHandle handle);
// @category:read
/* AUTO-DOC from cpp: InterpretationContext_unit |
 * falcon_core::autotuner_interfaces::interpretations::InterpretationContext::unit
 */
/**
 * @brief Return the unit for interpreting the values.
 */
SymbolUnitHandle InterpretationContext_unit(InterpretationContextHandle handle);
// @category:read
/* AUTO-DOC from cpp: InterpretationContext_dimension |
 * falcon_core::autotuner_interfaces::interpretations::InterpretationContext::dimension
 */
/**
 * @brief Return the dimensionality of the measurement (number of independent
 * variables).
 */
int InterpretationContext_dimension(InterpretationContextHandle handle);
// @category:write
/* AUTO-DOC from cpp: InterpretationContext_add_dependent_variable |
 * falcon_core::autotuner_interfaces::interpretations::InterpretationContext::add_dependent_variable
 */
/**
 * @brief Add a dependant variable to the measurement context.
 * @param variable The dependent variable to add.
 */
void InterpretationContext_add_dependent_variable(
    InterpretationContextHandle handle, MeasurementContextHandle variable);
// @category:write
/* AUTO-DOC from cpp: InterpretationContext_replace_dependent_variable |
 * falcon_core::autotuner_interfaces::interpretations::InterpretationContext::replace_dependent_variable
 */
/**
 * @brief Replace a dependent variable at the specified index.
 * @param index The count corresponding to the location of the variable to
 * replace.
 * @param variable The varaible that is to be stored at the location.
 */
void InterpretationContext_replace_dependent_variable(
    InterpretationContextHandle handle,
    int                         index,
    MeasurementContextHandle    variable);
// @category:read
MeasurementContextHandle InterpretationContext_get_independent_variables(
    InterpretationContextHandle handle, int index);
// @category:read
/* AUTO-DOC from cpp: InterpretationContext_with_unit |
 * falcon_core::autotuner_interfaces::interpretations::InterpretationContext::with_unit
 */
/**
 * @brief Create a new interpretation context with the given
 * unit.
 * @param unit The physical unit to use
 * @return A new interpretation context with the same variables but a
 * different unit.
 */
InterpretationContextHandle InterpretationContext_with_unit(
    InterpretationContextHandle handle, SymbolUnitHandle unit);

#ifdef __cplusplus
}
#endif
