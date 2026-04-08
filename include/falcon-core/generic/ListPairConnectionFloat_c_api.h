#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/generic/PairConnectionFloat_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairConnectionFloatHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListPairConnectionFloatHandle ListPairConnectionFloat_create_empty();
// @category:allocation
FALCON_CORE_C_API ListPairConnectionFloatHandle ListPairConnectionFloat_copy(ListPairConnectionFloatHandle handle);

// @category:allocation
FALCON_CORE_C_API ListPairConnectionFloatHandle ListPairConnectionFloat_fill_value(size_t count, PairConnectionFloatHandle value);
// @category:allocation
FALCON_CORE_C_API ListPairConnectionFloatHandle ListPairConnectionFloat_create(PairConnectionFloatHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListPairConnectionFloat_destroy(ListPairConnectionFloatHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairConnectionFloat_push_back(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairConnectionFloat_size(ListPairConnectionFloatHandle handle);
// @category:read
FALCON_CORE_C_API bool ListPairConnectionFloat_empty(ListPairConnectionFloatHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairConnectionFloat_erase_at(ListPairConnectionFloatHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListPairConnectionFloat_clear(ListPairConnectionFloatHandle handle);
// @category:read
FALCON_CORE_C_API PairConnectionFloatHandle ListPairConnectionFloat_at(ListPairConnectionFloatHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListPairConnectionFloat_items(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListPairConnectionFloat_contains(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairConnectionFloat_index(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value);
// @category:read
FALCON_CORE_C_API ListPairConnectionFloatHandle ListPairConnectionFloat_intersection(ListPairConnectionFloatHandle handle, ListPairConnectionFloatHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairConnectionFloat_equal(ListPairConnectionFloatHandle handle, ListPairConnectionFloatHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairConnectionFloat_not_equal(ListPairConnectionFloatHandle handle, ListPairConnectionFloatHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListPairConnectionFloat_to_json_string(ListPairConnectionFloatHandle handle);
// @category:allocation
FALCON_CORE_C_API ListPairConnectionFloatHandle ListPairConnectionFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif