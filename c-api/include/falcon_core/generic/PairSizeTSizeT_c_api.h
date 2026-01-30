#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairSizeTSizeTHandle;
// Function declarations

// @category:allocation
PairSizeTSizeTHandle PairSizeTSizeT_create(size_t first, size_t second);
// @category:allocation
PairSizeTSizeTHandle PairSizeTSizeT_copy(PairSizeTSizeTHandle handle);
// @category:deallocation
void PairSizeTSizeT_destroy(PairSizeTSizeTHandle handle);
// @category:read
size_t PairSizeTSizeT_first(PairSizeTSizeTHandle handle);
// @category:read
size_t PairSizeTSizeT_second(PairSizeTSizeTHandle handle);
// @category:read
bool PairSizeTSizeT_equal(PairSizeTSizeTHandle handle, PairSizeTSizeTHandle other);
// @category:read
bool PairSizeTSizeT_not_equal(PairSizeTSizeTHandle handle, PairSizeTSizeTHandle other);
// @category:read
StringHandle      PairSizeTSizeT_to_json_string(PairSizeTSizeTHandle handle);
// @category:allocation
PairSizeTSizeTHandle PairSizeTSizeT_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif