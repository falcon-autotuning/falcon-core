#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairConnectionDouble_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairConnectionDoubleHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListPairConnectionDoubleHandle ListPairConnectionDouble_create_empty();
// @category:allocation
FALCON_CORE_C_API ListPairConnectionDoubleHandle ListPairConnectionDouble_copy(ListPairConnectionDoubleHandle handle);

// @category:allocation
FALCON_CORE_C_API ListPairConnectionDoubleHandle ListPairConnectionDouble_fill_value(size_t count, PairConnectionDoubleHandle value);
// @category:allocation
FALCON_CORE_C_API ListPairConnectionDoubleHandle ListPairConnectionDouble_create(PairConnectionDoubleHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListPairConnectionDouble_destroy(ListPairConnectionDoubleHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairConnectionDouble_push_back(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairConnectionDouble_size(ListPairConnectionDoubleHandle handle);
// @category:read
FALCON_CORE_C_API bool ListPairConnectionDouble_empty(ListPairConnectionDoubleHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairConnectionDouble_erase_at(ListPairConnectionDoubleHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListPairConnectionDouble_clear(ListPairConnectionDoubleHandle handle);
// @category:read
FALCON_CORE_C_API PairConnectionDoubleHandle ListPairConnectionDouble_at(ListPairConnectionDoubleHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListPairConnectionDouble_items(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListPairConnectionDouble_contains(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairConnectionDouble_index(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value);
// @category:read
FALCON_CORE_C_API ListPairConnectionDoubleHandle ListPairConnectionDouble_intersection(ListPairConnectionDoubleHandle handle, ListPairConnectionDoubleHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairConnectionDouble_equal(ListPairConnectionDoubleHandle handle, ListPairConnectionDoubleHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairConnectionDouble_not_equal(ListPairConnectionDoubleHandle handle, ListPairConnectionDoubleHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListPairConnectionDouble_to_json_string(ListPairConnectionDoubleHandle handle);
// @category:allocation
FALCON_CORE_C_API ListPairConnectionDoubleHandle ListPairConnectionDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif