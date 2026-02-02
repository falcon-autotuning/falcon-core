#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairStringStringHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API PairStringStringHandle PairStringString_create(StringHandle first, StringHandle second);
// @category:allocation
FALCON_CORE_C_API PairStringStringHandle PairStringString_copy(PairStringStringHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PairStringString_destroy(PairStringStringHandle handle);
// @category:read
FALCON_CORE_C_API StringHandle PairStringString_first(PairStringStringHandle handle);
// @category:read
FALCON_CORE_C_API StringHandle PairStringString_second(PairStringStringHandle handle);
// @category:read
FALCON_CORE_C_API bool PairStringString_equal(PairStringStringHandle handle, PairStringStringHandle other);
// @category:read
FALCON_CORE_C_API bool PairStringString_not_equal(PairStringStringHandle handle, PairStringStringHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      PairStringString_to_json_string(PairStringStringHandle handle);
// @category:allocation
FALCON_CORE_C_API PairStringStringHandle PairStringString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif