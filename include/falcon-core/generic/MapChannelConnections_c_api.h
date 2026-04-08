#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/generic/PairChannelConnections_c_api.h"
#include "falcon-core/generic/ListChannel_c_api.h"
#include "falcon-core/generic/ListConnections_c_api.h"
#include "falcon-core/generic/ListPairChannelConnections_c_api.h"
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapChannelConnectionsHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API MapChannelConnectionsHandle MapChannelConnections_create_empty();
// @category:allocation
FALCON_CORE_C_API MapChannelConnectionsHandle MapChannelConnections_copy(MapChannelConnectionsHandle handle);
// @category:allocation
FALCON_CORE_C_API MapChannelConnectionsHandle MapChannelConnections_create(PairChannelConnectionsHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void MapChannelConnections_destroy(MapChannelConnectionsHandle handle);
// @category:write
FALCON_CORE_C_API void MapChannelConnections_insert_or_assign(MapChannelConnectionsHandle handle, ChannelHandle key, ConnectionsHandle value);
// @category:write
FALCON_CORE_C_API void MapChannelConnections_insert(MapChannelConnectionsHandle handle, ChannelHandle key, ConnectionsHandle value);
// @category:read
FALCON_CORE_C_API ConnectionsHandle MapChannelConnections_at(MapChannelConnectionsHandle handle, ChannelHandle key);
// @category:write
FALCON_CORE_C_API void MapChannelConnections_erase(MapChannelConnectionsHandle handle, ChannelHandle key);
// @category:read
FALCON_CORE_C_API size_t MapChannelConnections_size(MapChannelConnectionsHandle handle);
// @category:read
FALCON_CORE_C_API bool MapChannelConnections_empty(MapChannelConnectionsHandle handle);
// @category:write
FALCON_CORE_C_API void MapChannelConnections_clear(MapChannelConnectionsHandle handle);
// @category:read
FALCON_CORE_C_API bool MapChannelConnections_contains(MapChannelConnectionsHandle handle, ChannelHandle key);
// @category:read
FALCON_CORE_C_API ListChannelHandle MapChannelConnections_keys(MapChannelConnectionsHandle handle);
// @category:read
FALCON_CORE_C_API ListConnectionsHandle MapChannelConnections_values(MapChannelConnectionsHandle handle);
// @category:read
FALCON_CORE_C_API  ListPairChannelConnectionsHandle MapChannelConnections_items(MapChannelConnectionsHandle handle);
// @category:read
FALCON_CORE_C_API bool MapChannelConnections_equal(MapChannelConnectionsHandle handle, MapChannelConnectionsHandle other);
// @category:read
FALCON_CORE_C_API bool MapChannelConnections_not_equal(MapChannelConnectionsHandle handle, MapChannelConnectionsHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      MapChannelConnections_to_json_string(MapChannelConnectionsHandle handle);
// @category:allocation
FALCON_CORE_C_API MapChannelConnectionsHandle MapChannelConnections_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif