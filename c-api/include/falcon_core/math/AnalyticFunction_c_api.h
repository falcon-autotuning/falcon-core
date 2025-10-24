#pragma once
#include <cstddef>
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* AnalyticFunctionHandle;

// Constructors
AnalyticFunctionHandle AnalyticFunction_create(StringHandle labels,
                                               StringHandle expression);
AnalyticFunctionHandle AnalyticFunction_create_identity();
AnalyticFunctionHandle AnalyticFunction_create_constant();

// Destructor
void AnalyticFunction_destroy(AnalyticFunctionHandle handle);

// Methods
ListStringHandle   AnalyticFunction_labels(AnalyticFunctionHandle handle);
double             AnalyticFunction_evaluate(AnalyticFunctionHandle handle,
                                             MapStringDouble        args,
                                             double                 time);
FArrayDoubleHandle AnalyticFunction_evaluate_arraywise(
    AnalyticFunctionHandle handle,
    MapStringDouble        args,
    double                 deltaT,
    double                 maxTime);
bool AnalyticFunction_equal(AnalyticFunctionHandle a, AnalyticFunctionHandle b);
bool AnalyticFunction_not_equal(AnalyticFunctionHandle a,
                                AnalyticFunctionHandle b);

// Serialization (from Song)
StringHandle AnalyticFunction_to_json_string(AnalyticFunctionHandle handle);
AnalyticFunctionHandle AnalyticFunction_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
