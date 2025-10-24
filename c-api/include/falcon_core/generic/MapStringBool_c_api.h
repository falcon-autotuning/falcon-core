#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListPairStringBool_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
#include "falcon_core/generic/ListBool_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapStringBoolHandle;
// Function declarations

MapStringBoolHandle MapStringBool_create_empty();
MapStringBoolHandle MapStringBool_create(const PairStringBoolHandle* data, size_t count);
void MapStringBool_destroy(MapStringBoolHandle handle);
void MapStringBool_insert_or_assign(MapStringBoolHandle handle, const StringHandle key, const bool value);
void MapStringBool_insert(MapStringBoolHandle handle, const StringHandle key, const bool value);
bool MapStringBool_at(MapStringBoolHandle handle, const StringHandle key);
void MapStringBool_erase(MapStringBoolHandle handle, const StringHandle key);
size_t MapStringBool_size(MapStringBoolHandle handle);
bool MapStringBool_empty(MapStringBoolHandle handle);
void MapStringBool_clear(MapStringBoolHandle handle);
bool MapStringBool_contains(MapStringBoolHandle handle, const StringHandle key);
ListStringHandle MapStringBool_keys(MapStringBoolHandle handle);
ListBoolHandle MapStringBool_values(MapStringBoolHandle handle);
ListPairStringBoolHandle MapStringBool_items(MapStringBoolHandle handle);
bool MapStringBool_equal(MapStringBoolHandle a, MapStringBoolHandle b);
bool MapStringBool_not_equal(MapStringBoolHandle a, MapStringBoolHandle b);
// Serialization (from Song)
StringHandle      MapStringBool_to_json_string(MapStringBoolHandle handle);
MapStringBoolHandle MapStringBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif