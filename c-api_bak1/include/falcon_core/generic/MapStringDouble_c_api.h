#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListPairStringDouble_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
#include "falcon_core/generic/ListDouble_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapStringDoubleHandle;
// Function declarations

MapStringDoubleHandle MapStringDouble_create_empty();
MapStringDoubleHandle MapStringDouble_create(const PairStringDoubleHandle* data, size_t count);
void MapStringDouble_destroy(MapStringDoubleHandle handle);
void MapStringDouble_insert_or_assign(MapStringDoubleHandle handle, const StringHandle key, const double value);
void MapStringDouble_insert(MapStringDoubleHandle handle, const StringHandle key, const double value);
double MapStringDouble_at(MapStringDoubleHandle handle, const StringHandle key);
void MapStringDouble_erase(MapStringDoubleHandle handle, const StringHandle key);
size_t MapStringDouble_size(MapStringDoubleHandle handle);
bool MapStringDouble_empty(MapStringDoubleHandle handle);
void MapStringDouble_clear(MapStringDoubleHandle handle);
bool MapStringDouble_contains(MapStringDoubleHandle handle, const StringHandle key);
/* AUTO-DOC from cpp: MapStringDouble_keys | falcon_core::generic::Map::keys */
/**
 * @brief (from C++: falcon_core::generic::Map::keys)
 * @brief Return the keys of the Map.
 */
ListStringHandle MapStringDouble_keys(MapStringDoubleHandle handle);
/* AUTO-DOC from cpp: MapStringDouble_values | falcon_core::generic::Map::values */
/**
 * @brief (from C++: falcon_core::generic::Map::values)
 * @brief Return the values of the Map.
 */
ListDoubleHandle MapStringDouble_values(MapStringDoubleHandle handle);
ListPairStringDoubleHandle MapStringDouble_items(MapStringDoubleHandle handle);
bool MapStringDouble_equal(MapStringDoubleHandle a, MapStringDoubleHandle b);
bool MapStringDouble_not_equal(MapStringDoubleHandle a, MapStringDoubleHandle b);
// Serialization (from Song)
/* AUTO-DOC from cpp: MapStringDouble_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      MapStringDouble_to_json_string(MapStringDoubleHandle handle);
/* AUTO-DOC from cpp: MapStringDouble_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
MapStringDoubleHandle MapStringDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif