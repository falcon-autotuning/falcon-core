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

// Constructors
AnalyticFunctionHandle AnalyticFunction_create(ListStringHandle labels,
                                               StringHandle     expression);
AnalyticFunctionHandle AnalyticFunction_create_identity();
AnalyticFunctionHandle AnalyticFunction_create_constant(double value);

// Destructor
void AnalyticFunction_destroy(AnalyticFunctionHandle handle);

// Methods
/* AUTO-DOC from cpp: AnalyticFunction_labels | falcon_core::math::AnalyticFunction::labels */
/**
 * @brief Return the set of labels in proper order of the function's arguments
 * to their names.
 */
ListStringHandle   AnalyticFunction_labels(AnalyticFunctionHandle handle);
/* AUTO-DOC from cpp: AnalyticFunction_evaluate | falcon_core::math::AnalyticFunction::evaluate */
/**
 * @brief Returns the evaluated analytic function.
 * @param args The vector arguments supplied with human readable names
 * @param time The time to evaluate the function at..
 */
double             AnalyticFunction_evaluate(AnalyticFunctionHandle handle,
                                             MapStringDoubleHandle  args,
                                             double                 time);
FArrayDoubleHandle AnalyticFunction_evaluate_arraywise(
    AnalyticFunctionHandle handle,
    MapStringDoubleHandle  args,
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
