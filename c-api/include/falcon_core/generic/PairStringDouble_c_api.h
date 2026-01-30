#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairStringDoubleHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API PairStringDoubleHandle PairStringDouble_create(StringHandle first, double second);
// @category:allocation
FALCON_CORE_C_API PairStringDoubleHandle PairStringDouble_copy(PairStringDoubleHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PairStringDouble_destroy(PairStringDoubleHandle handle);
// @category:read
FALCON_CORE_C_API StringHandle PairStringDouble_first(PairStringDoubleHandle handle);
// @category:read
FALCON_CORE_C_API double PairStringDouble_second(PairStringDoubleHandle handle);
// @category:read
FALCON_CORE_C_API bool PairStringDouble_equal(PairStringDoubleHandle handle, PairStringDoubleHandle other);
// @category:read
FALCON_CORE_C_API bool PairStringDouble_not_equal(PairStringDoubleHandle handle, PairStringDoubleHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      PairStringDouble_to_json_string(PairStringDoubleHandle handle);
// @category:allocation
FALCON_CORE_C_API PairStringDoubleHandle PairStringDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif