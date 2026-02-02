#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairChannelConnections_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairChannelConnectionsHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListPairChannelConnectionsHandle ListPairChannelConnections_create_empty();
// @category:allocation
FALCON_CORE_C_API ListPairChannelConnectionsHandle ListPairChannelConnections_copy(ListPairChannelConnectionsHandle handle);

// @category:allocation
FALCON_CORE_C_API ListPairChannelConnectionsHandle ListPairChannelConnections_fill_value(size_t count, PairChannelConnectionsHandle value);
// @category:allocation
FALCON_CORE_C_API ListPairChannelConnectionsHandle ListPairChannelConnections_create(PairChannelConnectionsHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListPairChannelConnections_destroy(ListPairChannelConnectionsHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairChannelConnections_push_back(ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairChannelConnections_size(ListPairChannelConnectionsHandle handle);
// @category:read
FALCON_CORE_C_API bool ListPairChannelConnections_empty(ListPairChannelConnectionsHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairChannelConnections_erase_at(ListPairChannelConnectionsHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListPairChannelConnections_clear(ListPairChannelConnectionsHandle handle);
// @category:read
FALCON_CORE_C_API PairChannelConnectionsHandle ListPairChannelConnections_at(ListPairChannelConnectionsHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListPairChannelConnections_items(ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListPairChannelConnections_contains(ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairChannelConnections_index(ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle value);
// @category:read
FALCON_CORE_C_API ListPairChannelConnectionsHandle ListPairChannelConnections_intersection(ListPairChannelConnectionsHandle handle, ListPairChannelConnectionsHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairChannelConnections_equal(ListPairChannelConnectionsHandle handle, ListPairChannelConnectionsHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairChannelConnections_not_equal(ListPairChannelConnectionsHandle handle, ListPairChannelConnectionsHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListPairChannelConnections_to_json_string(ListPairChannelConnectionsHandle handle);
// @category:allocation
FALCON_CORE_C_API ListPairChannelConnectionsHandle ListPairChannelConnections_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif