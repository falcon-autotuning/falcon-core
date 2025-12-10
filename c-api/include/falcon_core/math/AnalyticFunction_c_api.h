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
AnalyticFunctionHandle AnalyticFunction_copy(AnalyticFunctionHandle handle);
// @category:deallocation
void AnalyticFunction_destroy(AnalyticFunctionHandle handle);
// @category:read
bool AnalyticFunction_equal(AnalyticFunctionHandle handle,
                            AnalyticFunctionHandle other);
// @category:read
bool AnalyticFunction_not_equal(AnalyticFunctionHandle handle,
                                AnalyticFunctionHandle other);
// @category:read
StringHandle AnalyticFunction_to_json_string(AnalyticFunctionHandle handle);
// @category:allocation
AnalyticFunctionHandle AnalyticFunction_from_json_string(StringHandle json);
// @category:allocation
AnalyticFunctionHandle AnalyticFunction_create(ListStringHandle labels,
                                               StringHandle     expression);
// @category:allocation
AnalyticFunctionHandle AnalyticFunction_create_identity();
// @category:allocation
AnalyticFunctionHandle AnalyticFunction_create_constant(double value);
// @category:read
/* AUTO-DOC from cpp: AnalyticFunction_labels |
 * falcon_core::math::AnalyticFunction::labels */
/**
 * @brief Return the set of labels in proper order of the function's arguments
 * to their names.
 */
ListStringHandle AnalyticFunction_labels(AnalyticFunctionHandle handle);
// @category:read
/* AUTO-DOC from cpp: AnalyticFunction_evaluate |
 * falcon_core::math::AnalyticFunction::evaluate */
/**
 * @brief Returns the evaluated analytic function.
 * @param args The vector arguments supplied with human readable names
 * @param time The time to evaluate the function at..
 */
double AnalyticFunction_evaluate(AnalyticFunctionHandle handle,
                                 MapStringDoubleHandle  args,
                                 double                 time);
// @category:read
FArrayDoubleHandle AnalyticFunction_evaluate_arraywise(
    AnalyticFunctionHandle handle,
    MapStringDoubleHandle  args,
    double                 deltaT,
    double                 maxTime);

#ifdef __cplusplus
}
#endif
