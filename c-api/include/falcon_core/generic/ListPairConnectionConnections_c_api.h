#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairConnectionConnections_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairConnectionConnectionsHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListPairConnectionConnectionsHandle ListPairConnectionConnections_create_empty();
// @category:allocation
FALCON_CORE_C_API ListPairConnectionConnectionsHandle ListPairConnectionConnections_copy(ListPairConnectionConnectionsHandle handle);

// @category:allocation
FALCON_CORE_C_API ListPairConnectionConnectionsHandle ListPairConnectionConnections_fill_value(size_t count, PairConnectionConnectionsHandle value);
// @category:allocation
FALCON_CORE_C_API ListPairConnectionConnectionsHandle ListPairConnectionConnections_create(PairConnectionConnectionsHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListPairConnectionConnections_destroy(ListPairConnectionConnectionsHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairConnectionConnections_push_back(ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairConnectionConnections_size(ListPairConnectionConnectionsHandle handle);
// @category:read
FALCON_CORE_C_API bool ListPairConnectionConnections_empty(ListPairConnectionConnectionsHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairConnectionConnections_erase_at(ListPairConnectionConnectionsHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListPairConnectionConnections_clear(ListPairConnectionConnectionsHandle handle);
// @category:read
FALCON_CORE_C_API PairConnectionConnectionsHandle ListPairConnectionConnections_at(ListPairConnectionConnectionsHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListPairConnectionConnections_items(ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListPairConnectionConnections_contains(ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairConnectionConnections_index(ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle value);
// @category:read
FALCON_CORE_C_API ListPairConnectionConnectionsHandle ListPairConnectionConnections_intersection(ListPairConnectionConnectionsHandle handle, ListPairConnectionConnectionsHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairConnectionConnections_equal(ListPairConnectionConnectionsHandle handle, ListPairConnectionConnectionsHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairConnectionConnections_not_equal(ListPairConnectionConnectionsHandle handle, ListPairConnectionConnectionsHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListPairConnectionConnections_to_json_string(ListPairConnectionConnectionsHandle handle);
// @category:allocation
FALCON_CORE_C_API ListPairConnectionConnectionsHandle ListPairConnectionConnections_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif