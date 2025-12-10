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
InterpretationContextHandle InterpretationContext_create(
    AxesMeasurementContextHandle independant_variables,
    ListMeasurementContextHandle dependant_variables,
    SymbolUnitHandle             unit);
// @category:deallocation
void InterpretationContext_destroy(InterpretationContextHandle handle);
// @category:read
AxesMeasurementContextHandle InterpretationContext_independent_variables(
    InterpretationContextHandle handle);
// @category:read
ListMeasurementContextHandle InterpretationContext_dependent_variables(
    InterpretationContextHandle handle);
// @category:read
SymbolUnitHandle InterpretationContext_unit(InterpretationContextHandle handle);
// @category:read
int InterpretationContext_dimension(InterpretationContextHandle handle);
// @category:write
void InterpretationContext_add_dependent_variable(
    InterpretationContextHandle handle, MeasurementContextHandle variable);
// @category:write
void InterpretationContext_replace_dependent_variable(
    InterpretationContextHandle handle,
    int                         index,
    MeasurementContextHandle    variable);
// @category:read
MeasurementContextHandle InterpretationContext_get_independent_variables(
    InterpretationContextHandle handle, int index);
// @category:read
InterpretationContextHandle InterpretationContext_with_unit(
    InterpretationContextHandle handle, SymbolUnitHandle unit);
// @category:read
bool InterpretationContext_equal(InterpretationContextHandle a,
                                 InterpretationContextHandle b);
// @category:read
bool InterpretationContext_not_equal(InterpretationContextHandle a,
                                     InterpretationContextHandle b);
// @category:read
StringHandle InterpretationContext_to_json_string(
    InterpretationContextHandle handle);
// @category:allocation
InterpretationContextHandle InterpretationContext_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
