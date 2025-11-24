#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairGnameGroup_c_api.h"
#include "falcon_core/generic/ListGname_c_api.h"
#include "falcon_core/generic/ListGroup_c_api.h"
#include "falcon_core/generic/ListPairGnameGroup_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapGnameGroupHandle;
// Function declarations

MapGnameGroupHandle MapGnameGroup_create_empty();
MapGnameGroupHandle MapGnameGroup_create(const PairGnameGroupHandle* data, size_t count);
void MapGnameGroup_destroy(MapGnameGroupHandle handle);
void MapGnameGroup_insert_or_assign(MapGnameGroupHandle handle, const GnameHandle key, const GroupHandle value);
void MapGnameGroup_insert(MapGnameGroupHandle handle, const GnameHandle key, const GroupHandle value);
GroupHandle MapGnameGroup_at(MapGnameGroupHandle handle, const GnameHandle key);
void MapGnameGroup_erase(MapGnameGroupHandle handle, const GnameHandle key);
size_t MapGnameGroup_size(MapGnameGroupHandle handle);
bool MapGnameGroup_empty(MapGnameGroupHandle handle);
void MapGnameGroup_clear(MapGnameGroupHandle handle);
bool MapGnameGroup_contains(MapGnameGroupHandle handle, const GnameHandle key);
/* AUTO-DOC from cpp: MapGnameGroup_keys | falcon_core::generic::Map::keys */
/**
 * @brief (from C++: falcon_core::generic::Map::keys)
 * @brief Return the keys of the Map.
 */
ListGnameHandle MapGnameGroup_keys(MapGnameGroupHandle handle);
/* AUTO-DOC from cpp: MapGnameGroup_values | falcon_core::generic::Map::values */
/**
 * @brief (from C++: falcon_core::generic::Map::values)
 * @brief Return the values of the Map.
 */
ListGroupHandle MapGnameGroup_values(MapGnameGroupHandle handle);
ListPairGnameGroupHandle MapGnameGroup_items(MapGnameGroupHandle handle);
bool MapGnameGroup_equal(MapGnameGroupHandle a, MapGnameGroupHandle b);
bool MapGnameGroup_not_equal(MapGnameGroupHandle a, MapGnameGroupHandle b);
// Serialization (from Song)
/* AUTO-DOC from cpp: MapGnameGroup_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      MapGnameGroup_to_json_string(MapGnameGroupHandle handle);
/* AUTO-DOC from cpp: MapGnameGroup_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
MapGnameGroupHandle MapGnameGroup_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif