#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairFloatFloatHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API PairFloatFloatHandle PairFloatFloat_create(float first, float second);
// @category:allocation
FALCON_CORE_C_API PairFloatFloatHandle PairFloatFloat_copy(PairFloatFloatHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PairFloatFloat_destroy(PairFloatFloatHandle handle);
// @category:read
FALCON_CORE_C_API float PairFloatFloat_first(PairFloatFloatHandle handle);
// @category:read
FALCON_CORE_C_API float PairFloatFloat_second(PairFloatFloatHandle handle);
// @category:read
FALCON_CORE_C_API bool PairFloatFloat_equal(PairFloatFloatHandle handle, PairFloatFloatHandle other);
// @category:read
FALCON_CORE_C_API bool PairFloatFloat_not_equal(PairFloatFloatHandle handle, PairFloatFloatHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      PairFloatFloat_to_json_string(PairFloatFloatHandle handle);
// @category:allocation
FALCON_CORE_C_API PairFloatFloatHandle PairFloatFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif