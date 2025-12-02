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

// @category:allocation
MapGnameGroupHandle MapGnameGroup_create_empty();
// @category:allocation
MapGnameGroupHandle MapGnameGroup_create(PairGnameGroupHandle* data, size_t count);
// @category:deallocation
void MapGnameGroup_destroy(MapGnameGroupHandle handle);
// @category:write
void MapGnameGroup_insert_or_assign(MapGnameGroupHandle handle, GnameHandle key, GroupHandle value);
// @category:write
void MapGnameGroup_insert(MapGnameGroupHandle handle, GnameHandle key, GroupHandle value);
// @category:read
GroupHandle MapGnameGroup_at(MapGnameGroupHandle handle, GnameHandle key);
// @category:write
void MapGnameGroup_erase(MapGnameGroupHandle handle, GnameHandle key);
// @category:read
size_t MapGnameGroup_size(MapGnameGroupHandle handle);
// @category:read
bool MapGnameGroup_empty(MapGnameGroupHandle handle);
// @category:write
void MapGnameGroup_clear(MapGnameGroupHandle handle);
// @category:read
bool MapGnameGroup_contains(MapGnameGroupHandle handle, GnameHandle key);
// @category:read
/* AUTO-DOC from cpp: MapGnameGroup_keys | falcon_core::generic::Map::keys */
/**
 * @brief Return the keys of the Map.
 */
ListGnameHandle MapGnameGroup_keys(MapGnameGroupHandle handle);
// @category:read
/* AUTO-DOC from cpp: MapGnameGroup_values | falcon_core::generic::Map::values */
/**
 * @brief Return the values of the Map.
 */
ListGroupHandle MapGnameGroup_values(MapGnameGroupHandle handle);
// @category:read
ListPairGnameGroupHandle MapGnameGroup_items(MapGnameGroupHandle handle);
// @category:read
bool MapGnameGroup_equal(MapGnameGroupHandle a, MapGnameGroupHandle b);
// @category:read
bool MapGnameGroup_not_equal(MapGnameGroupHandle a, MapGnameGroupHandle b);
// @category:read
StringHandle      MapGnameGroup_to_json_string(MapGnameGroupHandle handle);
// @category:allocation
MapGnameGroupHandle MapGnameGroup_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif