#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListPairStringString_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapStringStringHandle;
// Function declarations

// @category:allocation
MapStringStringHandle MapStringString_create_empty();
// @category:allocation
MapStringStringHandle MapStringString_create(PairStringStringHandle* data, size_t count);
// @category:deallocation
void MapStringString_destroy(MapStringStringHandle handle);
// @category:write
void MapStringString_insert_or_assign(MapStringStringHandle handle, StringHandle key, StringHandle value);
// @category:write
void MapStringString_insert(MapStringStringHandle handle, StringHandle key, StringHandle value);
// @category:read
StringHandle MapStringString_at(MapStringStringHandle handle, StringHandle key);
// @category:write
void MapStringString_erase(MapStringStringHandle handle, StringHandle key);
// @category:read
size_t MapStringString_size(MapStringStringHandle handle);
// @category:read
bool MapStringString_empty(MapStringStringHandle handle);
// @category:write
void MapStringString_clear(MapStringStringHandle handle);
// @category:read
bool MapStringString_contains(MapStringStringHandle handle, StringHandle key);
// @category:read
ListStringHandle MapStringString_keys(MapStringStringHandle handle);
// @category:read
ListStringHandle MapStringString_values(MapStringStringHandle handle);
// @category:read
ListPairStringStringHandle MapStringString_items(MapStringStringHandle handle);
// @category:read
bool MapStringString_equal(MapStringStringHandle a, MapStringStringHandle b);
// @category:read
bool MapStringString_not_equal(MapStringStringHandle a, MapStringStringHandle b);
// @category:read
StringHandle      MapStringString_to_json_string(MapStringStringHandle handle);
// @category:allocation
MapStringStringHandle MapStringString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif