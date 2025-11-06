#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairFloatFloatHandle;
// Function declarations

PairFloatFloatHandle PairFloatFloat_create(float first, float second);
void PairFloatFloat_destroy(PairFloatFloatHandle handle);
float PairFloatFloat_first(PairFloatFloatHandle handle);
float PairFloatFloat_second(PairFloatFloatHandle handle);
bool PairFloatFloat_equal(PairFloatFloatHandle a, PairFloatFloatHandle b);
bool PairFloatFloat_not_equal(PairFloatFloatHandle a, PairFloatFloatHandle b);
// Serialization (from Song)
StringHandle      PairFloatFloat_to_json_string(PairFloatFloatHandle handle);
PairFloatFloatHandle PairFloatFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif