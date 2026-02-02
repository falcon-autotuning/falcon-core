#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairFloatFloat_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairFloatFloatHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListPairFloatFloatHandle ListPairFloatFloat_create_empty();
// @category:allocation
FALCON_CORE_C_API ListPairFloatFloatHandle ListPairFloatFloat_copy(ListPairFloatFloatHandle handle);

// @category:allocation
FALCON_CORE_C_API ListPairFloatFloatHandle ListPairFloatFloat_fill_value(size_t count, PairFloatFloatHandle value);
// @category:allocation
FALCON_CORE_C_API ListPairFloatFloatHandle ListPairFloatFloat_create(PairFloatFloatHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListPairFloatFloat_destroy(ListPairFloatFloatHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairFloatFloat_push_back(ListPairFloatFloatHandle handle, PairFloatFloatHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairFloatFloat_size(ListPairFloatFloatHandle handle);
// @category:read
FALCON_CORE_C_API bool ListPairFloatFloat_empty(ListPairFloatFloatHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairFloatFloat_erase_at(ListPairFloatFloatHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListPairFloatFloat_clear(ListPairFloatFloatHandle handle);
// @category:read
FALCON_CORE_C_API PairFloatFloatHandle ListPairFloatFloat_at(ListPairFloatFloatHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListPairFloatFloat_items(ListPairFloatFloatHandle handle, PairFloatFloatHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListPairFloatFloat_contains(ListPairFloatFloatHandle handle, PairFloatFloatHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairFloatFloat_index(ListPairFloatFloatHandle handle, PairFloatFloatHandle value);
// @category:read
FALCON_CORE_C_API ListPairFloatFloatHandle ListPairFloatFloat_intersection(ListPairFloatFloatHandle handle, ListPairFloatFloatHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairFloatFloat_equal(ListPairFloatFloatHandle handle, ListPairFloatFloatHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairFloatFloat_not_equal(ListPairFloatFloatHandle handle, ListPairFloatFloatHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListPairFloatFloat_to_json_string(ListPairFloatFloatHandle handle);
// @category:allocation
FALCON_CORE_C_API ListPairFloatFloatHandle ListPairFloatFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif