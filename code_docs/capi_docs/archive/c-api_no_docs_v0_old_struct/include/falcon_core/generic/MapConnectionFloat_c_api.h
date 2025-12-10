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

MapConnectionFloatHandle MapConnectionFloat_create_empty();
MapConnectionFloatHandle MapConnectionFloat_create(const PairConnectionFloatHandle* data, size_t count);
void MapConnectionFloat_destroy(MapConnectionFloatHandle handle);
void MapConnectionFloat_insert_or_assign(MapConnectionFloatHandle handle, const ConnectionHandle key, const float value);
void MapConnectionFloat_insert(MapConnectionFloatHandle handle, const ConnectionHandle key, const float value);
float MapConnectionFloat_at(MapConnectionFloatHandle handle, const ConnectionHandle key);
void MapConnectionFloat_erase(MapConnectionFloatHandle handle, const ConnectionHandle key);
size_t MapConnectionFloat_size(MapConnectionFloatHandle handle);
bool MapConnectionFloat_empty(MapConnectionFloatHandle handle);
void MapConnectionFloat_clear(MapConnectionFloatHandle handle);
bool MapConnectionFloat_contains(MapConnectionFloatHandle handle, const ConnectionHandle key);
ListConnectionHandle MapConnectionFloat_keys(MapConnectionFloatHandle handle);
ListFloatHandle MapConnectionFloat_values(MapConnectionFloatHandle handle);
ListPairConnectionFloatHandle MapConnectionFloat_items(MapConnectionFloatHandle handle);
bool MapConnectionFloat_equal(MapConnectionFloatHandle a, MapConnectionFloatHandle b);
bool MapConnectionFloat_not_equal(MapConnectionFloatHandle a, MapConnectionFloatHandle b);
// Serialization (from Song)
StringHandle      MapConnectionFloat_to_json_string(MapConnectionFloatHandle handle);
MapConnectionFloatHandle MapConnectionFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif