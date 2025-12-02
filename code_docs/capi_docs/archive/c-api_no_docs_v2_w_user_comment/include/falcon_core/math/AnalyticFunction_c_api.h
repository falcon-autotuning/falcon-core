#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
#include "falcon_core/generic/MapStringDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
typedef void* AnalyticFunctionHandle;

// @category:allocation
AnalyticFunctionHandle AnalyticFunction_create(ListStringHandle labels,
                                               StringHandle     expression);
// @category:allocation
AnalyticFunctionHandle AnalyticFunction_create_identity();
// @category:allocation
AnalyticFunctionHandle AnalyticFunction_create_constant(double value);
// @category:deallocation
void AnalyticFunction_destroy(AnalyticFunctionHandle handle);
// @category:read
ListStringHandle AnalyticFunction_labels(AnalyticFunctionHandle handle);
// @category:read
double AnalyticFunction_evaluate(AnalyticFunctionHandle handle,
                                 MapStringDoubleHandle  args,
                                 double                 time);
// @category:read
FArrayDoubleHandle AnalyticFunction_evaluate_arraywise(
    AnalyticFunctionHandle handle,
    MapStringDoubleHandle  args,
    double                 deltaT,
    double                 maxTime);
// @category:read
bool AnalyticFunction_equal(AnalyticFunctionHandle a, AnalyticFunctionHandle b);
// @category:read
bool AnalyticFunction_not_equal(AnalyticFunctionHandle a,
                                AnalyticFunctionHandle b);
// @category:read
StringHandle AnalyticFunction_to_json_string(AnalyticFunctionHandle handle);
// @category:allocation
AnalyticFunctionHandle AnalyticFunction_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
