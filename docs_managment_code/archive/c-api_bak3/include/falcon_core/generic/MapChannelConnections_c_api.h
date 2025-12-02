#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairChannelConnections_c_api.h"
#include "falcon_core/generic/ListChannel_c_api.h"
#include "falcon_core/generic/ListConnections_c_api.h"
#include "falcon_core/generic/ListPairChannelConnections_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapChannelConnectionsHandle;
// Function declarations

// @category:allocation
MapChannelConnectionsHandle MapChannelConnections_create_empty();
// @category:allocation
MapChannelConnectionsHandle MapChannelConnections_create(PairChannelConnectionsHandle* data, size_t count);
// @category:deallocation
void MapChannelConnections_destroy(MapChannelConnectionsHandle handle);
// @category:write
void MapChannelConnections_insert_or_assign(MapChannelConnectionsHandle handle, ChannelHandle key, ConnectionsHandle value);
// @category:write
void MapChannelConnections_insert(MapChannelConnectionsHandle handle, ChannelHandle key, ConnectionsHandle value);
// @category:read
ConnectionsHandle MapChannelConnections_at(MapChannelConnectionsHandle handle, ChannelHandle key);
// @category:write
void MapChannelConnections_erase(MapChannelConnectionsHandle handle, ChannelHandle key);
// @category:read
size_t MapChannelConnections_size(MapChannelConnectionsHandle handle);
// @category:read
bool MapChannelConnections_empty(MapChannelConnectionsHandle handle);
// @category:write
void MapChannelConnections_clear(MapChannelConnectionsHandle handle);
// @category:read
bool MapChannelConnections_contains(MapChannelConnectionsHandle handle, ChannelHandle key);
// @category:read
/* AUTO-DOC from cpp: MapChannelConnections_keys | falcon_core::generic::Map::keys */
/**
 * @brief Return the keys of the Map.
 */
ListChannelHandle MapChannelConnections_keys(MapChannelConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: MapChannelConnections_values | falcon_core::generic::Map::values */
/**
 * @brief Return the values of the Map.
 */
ListConnectionsHandle MapChannelConnections_values(MapChannelConnectionsHandle handle);
// @category:read
ListPairChannelConnectionsHandle MapChannelConnections_items(MapChannelConnectionsHandle handle);
// @category:read
bool MapChannelConnections_equal(MapChannelConnectionsHandle a, MapChannelConnectionsHandle b);
// @category:read
bool MapChannelConnections_not_equal(MapChannelConnectionsHandle a, MapChannelConnectionsHandle b);
// @category:read
StringHandle      MapChannelConnections_to_json_string(MapChannelConnectionsHandle handle);
// @category:allocation
MapChannelConnectionsHandle MapChannelConnections_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif