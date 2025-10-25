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
AxesMeasurementContextHandle InterpretationContext_independant_variables(
    InterpretationContextHandle handle);
ListMeasurementContextHandle InterpretationContext_dependent_variables(
    InterpretationContextHandle handle);
SymbolUnitHandle InterpretationContext_unit(InterpretationContextHandle handle);
int  InterpretationContext_dimension(InterpretationContextHandle handle);
void InterpretationContext_dependent_variable(
    InterpretationContextHandle handle, MeasurementContextHandle variable);
void InterpretationContext_replace_dependent_variable(
    InterpretationContextHandle handle,
    int                         index,
    MeasurementContextHandle    variable);
MeasurementContextHandle InterpretationContext_get_independant_variables(
    InterpretationContextHandle handle, int index);
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
