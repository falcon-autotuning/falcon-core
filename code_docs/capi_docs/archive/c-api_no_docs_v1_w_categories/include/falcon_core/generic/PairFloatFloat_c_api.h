#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairFloatFloatHandle;
// Function declarations

// @category:allocation
PairFloatFloatHandle PairFloatFloat_create(float first, float second);
// @category:deallocation
void PairFloatFloat_destroy(PairFloatFloatHandle handle);
// @category:read
float PairFloatFloat_first(PairFloatFloatHandle handle);
// @category:read
float PairFloatFloat_second(PairFloatFloatHandle handle);
// @category:read
bool PairFloatFloat_equal(PairFloatFloatHandle a, PairFloatFloatHandle b);
// @category:read
bool PairFloatFloat_not_equal(PairFloatFloatHandle a, PairFloatFloatHandle b);
// @category:read
StringHandle      PairFloatFloat_to_json_string(PairFloatFloatHandle handle);
// @category:allocation
PairFloatFloatHandle PairFloatFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif