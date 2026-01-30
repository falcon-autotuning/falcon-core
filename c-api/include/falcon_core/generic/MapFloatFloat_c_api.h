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

// @category:allocation
MapFloatFloatHandle MapFloatFloat_create_empty();
// @category:allocation
MapFloatFloatHandle MapFloatFloat_copy(MapFloatFloatHandle handle);
// @category:allocation
MapFloatFloatHandle MapFloatFloat_create(PairFloatFloatHandle* data, size_t count);
// @category:deallocation
void MapFloatFloat_destroy(MapFloatFloatHandle handle);
// @category:write
void MapFloatFloat_insert_or_assign(MapFloatFloatHandle handle, float key, float value);
// @category:write
void MapFloatFloat_insert(MapFloatFloatHandle handle, float key, float value);
// @category:read
float MapFloatFloat_at(MapFloatFloatHandle handle, float key);
// @category:write
void MapFloatFloat_erase(MapFloatFloatHandle handle, float key);
// @category:read
size_t MapFloatFloat_size(MapFloatFloatHandle handle);
// @category:read
bool MapFloatFloat_empty(MapFloatFloatHandle handle);
// @category:write
void MapFloatFloat_clear(MapFloatFloatHandle handle);
// @category:read
bool MapFloatFloat_contains(MapFloatFloatHandle handle, float key);
// @category:read
ListFloatHandle MapFloatFloat_keys(MapFloatFloatHandle handle);
// @category:read
ListFloatHandle MapFloatFloat_values(MapFloatFloatHandle handle);
// @category:read
ListPairFloatFloatHandle MapFloatFloat_items(MapFloatFloatHandle handle);
// @category:read
bool MapFloatFloat_equal(MapFloatFloatHandle handle, MapFloatFloatHandle other);
// @category:read
bool MapFloatFloat_not_equal(MapFloatFloatHandle handle, MapFloatFloatHandle other);
// @category:read
StringHandle      MapFloatFloat_to_json_string(MapFloatFloatHandle handle);
// @category:allocation
MapFloatFloatHandle MapFloatFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif