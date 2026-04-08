#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/generic/PairStringString_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairStringStringHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListPairStringStringHandle ListPairStringString_create_empty();
// @category:allocation
FALCON_CORE_C_API ListPairStringStringHandle ListPairStringString_copy(ListPairStringStringHandle handle);

// @category:allocation
FALCON_CORE_C_API ListPairStringStringHandle ListPairStringString_fill_value(size_t count, PairStringStringHandle value);
// @category:allocation
FALCON_CORE_C_API ListPairStringStringHandle ListPairStringString_create(PairStringStringHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListPairStringString_destroy(ListPairStringStringHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairStringString_push_back(ListPairStringStringHandle handle, PairStringStringHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairStringString_size(ListPairStringStringHandle handle);
// @category:read
FALCON_CORE_C_API bool ListPairStringString_empty(ListPairStringStringHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairStringString_erase_at(ListPairStringStringHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListPairStringString_clear(ListPairStringStringHandle handle);
// @category:read
FALCON_CORE_C_API PairStringStringHandle ListPairStringString_at(ListPairStringStringHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListPairStringString_items(ListPairStringStringHandle handle, PairStringStringHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListPairStringString_contains(ListPairStringStringHandle handle, PairStringStringHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairStringString_index(ListPairStringStringHandle handle, PairStringStringHandle value);
// @category:read
FALCON_CORE_C_API ListPairStringStringHandle ListPairStringString_intersection(ListPairStringStringHandle handle, ListPairStringStringHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairStringString_equal(ListPairStringStringHandle handle, ListPairStringStringHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairStringString_not_equal(ListPairStringStringHandle handle, ListPairStringStringHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListPairStringString_to_json_string(ListPairStringStringHandle handle);
// @category:allocation
FALCON_CORE_C_API ListPairStringStringHandle ListPairStringString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif