#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairIntFloatHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API PairIntFloatHandle PairIntFloat_create(int first, float second);
// @category:allocation
FALCON_CORE_C_API PairIntFloatHandle PairIntFloat_copy(PairIntFloatHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PairIntFloat_destroy(PairIntFloatHandle handle);
// @category:read
FALCON_CORE_C_API int PairIntFloat_first(PairIntFloatHandle handle);
// @category:read
FALCON_CORE_C_API float PairIntFloat_second(PairIntFloatHandle handle);
// @category:read
FALCON_CORE_C_API bool PairIntFloat_equal(PairIntFloatHandle handle, PairIntFloatHandle other);
// @category:read
FALCON_CORE_C_API bool PairIntFloat_not_equal(PairIntFloatHandle handle, PairIntFloatHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      PairIntFloat_to_json_string(PairIntFloatHandle handle);
// @category:allocation
FALCON_CORE_C_API PairIntFloatHandle PairIntFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif