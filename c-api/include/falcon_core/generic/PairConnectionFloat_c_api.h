#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionFloatHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API PairConnectionFloatHandle PairConnectionFloat_create(ConnectionHandle first, float second);
// @category:allocation
FALCON_CORE_C_API PairConnectionFloatHandle PairConnectionFloat_copy(PairConnectionFloatHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PairConnectionFloat_destroy(PairConnectionFloatHandle handle);
// @category:read
FALCON_CORE_C_API ConnectionHandle PairConnectionFloat_first(PairConnectionFloatHandle handle);
// @category:read
FALCON_CORE_C_API float PairConnectionFloat_second(PairConnectionFloatHandle handle);
// @category:read
FALCON_CORE_C_API bool PairConnectionFloat_equal(PairConnectionFloatHandle handle, PairConnectionFloatHandle other);
// @category:read
FALCON_CORE_C_API bool PairConnectionFloat_not_equal(PairConnectionFloatHandle handle, PairConnectionFloatHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      PairConnectionFloat_to_json_string(PairConnectionFloatHandle handle);
// @category:allocation
FALCON_CORE_C_API PairConnectionFloatHandle PairConnectionFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif