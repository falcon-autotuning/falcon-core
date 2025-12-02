#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairConnectionFloat_c_api.h"
#include "falcon_core/generic/ListFloat_c_api.h"
#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/generic/ListPairConnectionFloat_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapConnectionFloatHandle;
// Function declarations

// @category:allocation
MapConnectionFloatHandle MapConnectionFloat_create_empty();
// @category:allocation
MapConnectionFloatHandle MapConnectionFloat_create(PairConnectionFloatHandle* data, size_t count);
// @category:deallocation
void MapConnectionFloat_destroy(MapConnectionFloatHandle handle);
// @category:write
void MapConnectionFloat_insert_or_assign(MapConnectionFloatHandle handle, ConnectionHandle key, float value);
// @category:write
void MapConnectionFloat_insert(MapConnectionFloatHandle handle, ConnectionHandle key, float value);
// @category:read
float MapConnectionFloat_at(MapConnectionFloatHandle handle, ConnectionHandle key);
// @category:write
void MapConnectionFloat_erase(MapConnectionFloatHandle handle, ConnectionHandle key);
// @category:read
size_t MapConnectionFloat_size(MapConnectionFloatHandle handle);
// @category:read
bool MapConnectionFloat_empty(MapConnectionFloatHandle handle);
// @category:write
void MapConnectionFloat_clear(MapConnectionFloatHandle handle);
// @category:read
bool MapConnectionFloat_contains(MapConnectionFloatHandle handle, ConnectionHandle key);
// @category:read
/* AUTO-DOC from cpp: MapConnectionFloat_keys | falcon_core::generic::Map::keys */
/**
 * @brief Return the keys of the Map.
 */
ListConnectionHandle MapConnectionFloat_keys(MapConnectionFloatHandle handle);
// @category:read
/* AUTO-DOC from cpp: MapConnectionFloat_values | falcon_core::generic::Map::values */
/**
 * @brief Return the values of the Map.
 */
ListFloatHandle MapConnectionFloat_values(MapConnectionFloatHandle handle);
// @category:read
ListPairConnectionFloatHandle MapConnectionFloat_items(MapConnectionFloatHandle handle);
// @category:read
bool MapConnectionFloat_equal(MapConnectionFloatHandle a, MapConnectionFloatHandle b);
// @category:read
bool MapConnectionFloat_not_equal(MapConnectionFloatHandle a, MapConnectionFloatHandle b);
// @category:read
StringHandle      MapConnectionFloat_to_json_string(MapConnectionFloatHandle handle);
// @category:allocation
MapConnectionFloatHandle MapConnectionFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif