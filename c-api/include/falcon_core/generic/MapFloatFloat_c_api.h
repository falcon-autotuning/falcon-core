#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairFloatFloat_c_api.h"
#include "falcon_core/generic/ListFloat_c_api.h"
#include "falcon_core/generic/ListPairFloatFloat_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapFloatFloatHandle;
// Function declarations

MapFloatFloatHandle MapFloatFloat_create_empty();
MapFloatFloatHandle MapFloatFloat_create(const PairFloatFloatHandle* data, size_t count);
void MapFloatFloat_destroy(MapFloatFloatHandle handle);
void MapFloatFloat_insert_or_assign(MapFloatFloatHandle handle, const float key, const float value);
void MapFloatFloat_insert(MapFloatFloatHandle handle, const float key, const float value);
float MapFloatFloat_at(MapFloatFloatHandle handle, const float key);
void MapFloatFloat_erase(MapFloatFloatHandle handle, const float key);
size_t MapFloatFloat_size(MapFloatFloatHandle handle);
bool MapFloatFloat_empty(MapFloatFloatHandle handle);
void MapFloatFloat_clear(MapFloatFloatHandle handle);
bool MapFloatFloat_contains(MapFloatFloatHandle handle, const float key);
/* AUTO-DOC from cpp: MapFloatFloat_keys | falcon_core::generic::Map::keys */
/**
 * @brief Return the keys of the Map.
 */
ListFloatHandle MapFloatFloat_keys(MapFloatFloatHandle handle);
/* AUTO-DOC from cpp: MapFloatFloat_values | falcon_core::generic::Map::values */
/**
 * @brief Return the values of the Map.
 */
ListFloatHandle MapFloatFloat_values(MapFloatFloatHandle handle);
ListPairFloatFloatHandle MapFloatFloat_items(MapFloatFloatHandle handle);
bool MapFloatFloat_equal(MapFloatFloatHandle a, MapFloatFloatHandle b);
bool MapFloatFloat_not_equal(MapFloatFloatHandle a, MapFloatFloatHandle b);
// Serialization (from Song)
StringHandle      MapFloatFloat_to_json_string(MapFloatFloatHandle handle);
MapFloatFloatHandle MapFloatFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif