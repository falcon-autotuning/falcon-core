#pragma once
#include <cstddef>
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
typedef void* AnalyticFunctionHandle;

// Constructors
AnalyticFunctionHandle AnalyticFunction_create(const char** labels,
                                               char*        expression);
AnalyticFunctionHandle AnalyticFunction_create_identity();
AnalyticFunctionHandle AnalyticFunction_create_constant();

// Destructor
void AnalyticFunction_destroy(AnalyticFunctionHandle handle);

// Methods
void   AnalyticFunction_labels(AnalyticFunctionHandle handle,
                               char**                 out_buffer,
                               size_t                 buffer_size);
double AnalyticFunction_evaluate(AnalyticFunctionHandle handle,
                                 MapStringDouble        args,
                                 double                 time);
// FArrayDoubleHandle AnalyticFunction_evaluate_arraywise(AnalyticFunctionHandle
// handle, MapStrinDouble args, double deltaT, double maxTime);
bool AnalyticFunction_equal(AnalyticFunctionHandle a, AnalyticFunctionHandle b);
bool AnalyticFunction_not_equal(AnalyticFunctionHandle a,
                                AnalyticFunctionHandle b);

// Serialization (from Song)
const char* AnalyticFunction_to_json_string(AnalyticFunctionHandle handle);
AnalyticFunctionHandle AnalyticFunction_from_json_string(const char* json);

#ifdef __cplusplus
}
#endif
