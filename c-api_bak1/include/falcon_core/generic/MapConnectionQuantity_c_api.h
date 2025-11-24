#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairConnectionQuantity_c_api.h"
#include "falcon_core/generic/ListQuantity_c_api.h"
#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/generic/ListPairConnectionQuantity_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapConnectionQuantityHandle;
// Function declarations

MapConnectionQuantityHandle MapConnectionQuantity_create_empty();
MapConnectionQuantityHandle MapConnectionQuantity_create(const PairConnectionQuantityHandle* data, size_t count);
void MapConnectionQuantity_destroy(MapConnectionQuantityHandle handle);
void MapConnectionQuantity_insert_or_assign(MapConnectionQuantityHandle handle, const ConnectionHandle key, const QuantityHandle value);
void MapConnectionQuantity_insert(MapConnectionQuantityHandle handle, const ConnectionHandle key, const QuantityHandle value);
QuantityHandle MapConnectionQuantity_at(MapConnectionQuantityHandle handle, const ConnectionHandle key);
void MapConnectionQuantity_erase(MapConnectionQuantityHandle handle, const ConnectionHandle key);
size_t MapConnectionQuantity_size(MapConnectionQuantityHandle handle);
bool MapConnectionQuantity_empty(MapConnectionQuantityHandle handle);
void MapConnectionQuantity_clear(MapConnectionQuantityHandle handle);
bool MapConnectionQuantity_contains(MapConnectionQuantityHandle handle, const ConnectionHandle key);
/* AUTO-DOC from cpp: MapConnectionQuantity_keys | falcon_core::generic::Map::keys */
/**
 * @brief (from C++: falcon_core::generic::Map::keys)
 * @brief Return the keys of the Map.
 */
ListConnectionHandle MapConnectionQuantity_keys(MapConnectionQuantityHandle handle);
/* AUTO-DOC from cpp: MapConnectionQuantity_values | falcon_core::generic::Map::values */
/**
 * @brief (from C++: falcon_core::generic::Map::values)
 * @brief Return the values of the Map.
 */
ListQuantityHandle MapConnectionQuantity_values(MapConnectionQuantityHandle handle);
ListPairConnectionQuantityHandle MapConnectionQuantity_items(MapConnectionQuantityHandle handle);
bool MapConnectionQuantity_equal(MapConnectionQuantityHandle a, MapConnectionQuantityHandle b);
bool MapConnectionQuantity_not_equal(MapConnectionQuantityHandle a, MapConnectionQuantityHandle b);
// Serialization (from Song)
/* AUTO-DOC from cpp: MapConnectionQuantity_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      MapConnectionQuantity_to_json_string(MapConnectionQuantityHandle handle);
/* AUTO-DOC from cpp: MapConnectionQuantity_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
MapConnectionQuantityHandle MapConnectionQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif