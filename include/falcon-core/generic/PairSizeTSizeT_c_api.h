#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairSizeTSizeTHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API PairSizeTSizeTHandle PairSizeTSizeT_create(size_t first, size_t second);
// @category:allocation
FALCON_CORE_C_API PairSizeTSizeTHandle PairSizeTSizeT_copy(PairSizeTSizeTHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PairSizeTSizeT_destroy(PairSizeTSizeTHandle handle);
// @category:read
FALCON_CORE_C_API size_t PairSizeTSizeT_first(PairSizeTSizeTHandle handle);
// @category:read
FALCON_CORE_C_API size_t PairSizeTSizeT_second(PairSizeTSizeTHandle handle);
// @category:read
FALCON_CORE_C_API bool PairSizeTSizeT_equal(PairSizeTSizeTHandle handle, PairSizeTSizeTHandle other);
// @category:read
FALCON_CORE_C_API bool PairSizeTSizeT_not_equal(PairSizeTSizeTHandle handle, PairSizeTSizeTHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      PairSizeTSizeT_to_json_string(PairSizeTSizeTHandle handle);
// @category:allocation
FALCON_CORE_C_API PairSizeTSizeTHandle PairSizeTSizeT_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif