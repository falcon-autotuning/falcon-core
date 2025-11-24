#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairConnectionDouble_c_api.h"
#include "falcon_core/generic/ListDouble_c_api.h"
#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/generic/ListPairConnectionDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapConnectionDoubleHandle;
// Function declarations

MapConnectionDoubleHandle MapConnectionDouble_create_empty();
MapConnectionDoubleHandle MapConnectionDouble_create(const PairConnectionDoubleHandle* data, size_t count);
void MapConnectionDouble_destroy(MapConnectionDoubleHandle handle);
void MapConnectionDouble_insert_or_assign(MapConnectionDoubleHandle handle, const ConnectionHandle key, const double value);
void MapConnectionDouble_insert(MapConnectionDoubleHandle handle, const ConnectionHandle key, const double value);
double MapConnectionDouble_at(MapConnectionDoubleHandle handle, const ConnectionHandle key);
void MapConnectionDouble_erase(MapConnectionDoubleHandle handle, const ConnectionHandle key);
size_t MapConnectionDouble_size(MapConnectionDoubleHandle handle);
bool MapConnectionDouble_empty(MapConnectionDoubleHandle handle);
void MapConnectionDouble_clear(MapConnectionDoubleHandle handle);
bool MapConnectionDouble_contains(MapConnectionDoubleHandle handle, const ConnectionHandle key);
/* AUTO-DOC from cpp: MapConnectionDouble_keys | falcon_core::generic::Map::keys */
/**
 * @brief (from C++: falcon_core::generic::Map::keys)
 * @brief Return the keys of the Map.
 */
ListConnectionHandle MapConnectionDouble_keys(MapConnectionDoubleHandle handle);
/* AUTO-DOC from cpp: MapConnectionDouble_values | falcon_core::generic::Map::values */
/**
 * @brief (from C++: falcon_core::generic::Map::values)
 * @brief Return the values of the Map.
 */
ListDoubleHandle MapConnectionDouble_values(MapConnectionDoubleHandle handle);
ListPairConnectionDoubleHandle MapConnectionDouble_items(MapConnectionDoubleHandle handle);
bool MapConnectionDouble_equal(MapConnectionDoubleHandle a, MapConnectionDoubleHandle b);
bool MapConnectionDouble_not_equal(MapConnectionDoubleHandle a, MapConnectionDoubleHandle b);
// Serialization (from Song)
/* AUTO-DOC from cpp: MapConnectionDouble_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      MapConnectionDouble_to_json_string(MapConnectionDoubleHandle handle);
/* AUTO-DOC from cpp: MapConnectionDouble_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
MapConnectionDoubleHandle MapConnectionDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif