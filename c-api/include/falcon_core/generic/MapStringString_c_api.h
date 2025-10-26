#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListPairStringString_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapStringStringHandle;
// Function declarations

MapStringStringHandle MapStringString_create_empty();
MapStringStringHandle MapStringString_create(const PairStringStringHandle* data, size_t count);
void MapStringString_destroy(MapStringStringHandle handle);
void MapStringString_insert_or_assign(MapStringStringHandle handle, const StringHandle key, const StringHandle value);
void MapStringString_insert(MapStringStringHandle handle, const StringHandle key, const StringHandle value);
StringHandle MapStringString_at(MapStringStringHandle handle, const StringHandle key);
void MapStringString_erase(MapStringStringHandle handle, const StringHandle key);
size_t MapStringString_size(MapStringStringHandle handle);
bool MapStringString_empty(MapStringStringHandle handle);
void MapStringString_clear(MapStringStringHandle handle);
bool MapStringString_contains(MapStringStringHandle handle, const StringHandle key);
ListStringHandle MapStringString_keys(MapStringStringHandle handle);
ListStringHandle MapStringString_values(MapStringStringHandle handle);
ListPairStringStringHandle MapStringString_items(MapStringStringHandle handle);
bool MapStringString_equal(MapStringStringHandle a, MapStringStringHandle b);
bool MapStringString_not_equal(MapStringStringHandle a, MapStringStringHandle b);
// Serialization (from Song)
StringHandle      MapStringString_to_json_string(MapStringStringHandle handle);
MapStringStringHandle MapStringString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif