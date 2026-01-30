#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairSizeTSizeT_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairSizeTSizeTHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListPairSizeTSizeTHandle ListPairSizeTSizeT_create_empty();
// @category:allocation
FALCON_CORE_C_API ListPairSizeTSizeTHandle ListPairSizeTSizeT_copy(ListPairSizeTSizeTHandle handle);

// @category:allocation
FALCON_CORE_C_API ListPairSizeTSizeTHandle ListPairSizeTSizeT_fill_value(size_t count, PairSizeTSizeTHandle value);
// @category:allocation
FALCON_CORE_C_API ListPairSizeTSizeTHandle ListPairSizeTSizeT_create(PairSizeTSizeTHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListPairSizeTSizeT_destroy(ListPairSizeTSizeTHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairSizeTSizeT_push_back(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairSizeTSizeT_size(ListPairSizeTSizeTHandle handle);
// @category:read
FALCON_CORE_C_API bool ListPairSizeTSizeT_empty(ListPairSizeTSizeTHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairSizeTSizeT_erase_at(ListPairSizeTSizeTHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListPairSizeTSizeT_clear(ListPairSizeTSizeTHandle handle);
// @category:read
FALCON_CORE_C_API PairSizeTSizeTHandle ListPairSizeTSizeT_at(ListPairSizeTSizeTHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListPairSizeTSizeT_items(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListPairSizeTSizeT_contains(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairSizeTSizeT_index(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle value);
// @category:read
FALCON_CORE_C_API ListPairSizeTSizeTHandle ListPairSizeTSizeT_intersection(ListPairSizeTSizeTHandle handle, ListPairSizeTSizeTHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairSizeTSizeT_equal(ListPairSizeTSizeTHandle handle, ListPairSizeTSizeTHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairSizeTSizeT_not_equal(ListPairSizeTSizeTHandle handle, ListPairSizeTSizeTHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListPairSizeTSizeT_to_json_string(ListPairSizeTSizeTHandle handle);
// @category:allocation
FALCON_CORE_C_API ListPairSizeTSizeTHandle ListPairSizeTSizeT_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif