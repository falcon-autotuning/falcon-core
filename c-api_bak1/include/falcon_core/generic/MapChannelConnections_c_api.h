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

MapChannelConnectionsHandle MapChannelConnections_create_empty();
MapChannelConnectionsHandle MapChannelConnections_create(const PairChannelConnectionsHandle* data, size_t count);
void MapChannelConnections_destroy(MapChannelConnectionsHandle handle);
void MapChannelConnections_insert_or_assign(MapChannelConnectionsHandle handle, const ChannelHandle key, const ConnectionsHandle value);
void MapChannelConnections_insert(MapChannelConnectionsHandle handle, const ChannelHandle key, const ConnectionsHandle value);
ConnectionsHandle MapChannelConnections_at(MapChannelConnectionsHandle handle, const ChannelHandle key);
void MapChannelConnections_erase(MapChannelConnectionsHandle handle, const ChannelHandle key);
size_t MapChannelConnections_size(MapChannelConnectionsHandle handle);
bool MapChannelConnections_empty(MapChannelConnectionsHandle handle);
void MapChannelConnections_clear(MapChannelConnectionsHandle handle);
bool MapChannelConnections_contains(MapChannelConnectionsHandle handle, const ChannelHandle key);
/* AUTO-DOC from cpp: MapChannelConnections_keys | falcon_core::generic::Map::keys */
/**
 * @brief (from C++: falcon_core::generic::Map::keys)
 * @brief Return the keys of the Map.
 */
ListChannelHandle MapChannelConnections_keys(MapChannelConnectionsHandle handle);
/* AUTO-DOC from cpp: MapChannelConnections_values | falcon_core::generic::Map::values */
/**
 * @brief (from C++: falcon_core::generic::Map::values)
 * @brief Return the values of the Map.
 */
ListConnectionsHandle MapChannelConnections_values(MapChannelConnectionsHandle handle);
ListPairChannelConnectionsHandle MapChannelConnections_items(MapChannelConnectionsHandle handle);
bool MapChannelConnections_equal(MapChannelConnectionsHandle a, MapChannelConnectionsHandle b);
bool MapChannelConnections_not_equal(MapChannelConnectionsHandle a, MapChannelConnectionsHandle b);
// Serialization (from Song)
/* AUTO-DOC from cpp: MapChannelConnections_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      MapChannelConnections_to_json_string(MapChannelConnectionsHandle handle);
/* AUTO-DOC from cpp: MapChannelConnections_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
MapChannelConnectionsHandle MapChannelConnections_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif