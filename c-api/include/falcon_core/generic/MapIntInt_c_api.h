#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairIntInt_c_api.h"
#include "falcon_core/generic/ListInt_c_api.h"
#include "falcon_core/generic/ListPairIntInt_c_api.h"

// Forward declarations for opaque handles
typedef void* MapIntIntHandle;
// Function declarations

MapIntIntHandle MapIntInt_create_empty();
MapIntIntHandle MapIntInt_create(const PairIntIntHandle* data, size_t count);
void MapIntInt_destroy(MapIntIntHandle handle);
void MapIntInt_insert_or_assign(MapIntIntHandle handle, const int key, const int value);
void MapIntInt_insert(MapIntIntHandle handle, const int key, const int value);
int MapIntInt_at(MapIntIntHandle handle, const int key);
void MapIntInt_erase(MapIntIntHandle handle, const int key);
size_t MapIntInt_size(MapIntIntHandle handle);
bool MapIntInt_empty(MapIntIntHandle handle);
void MapIntInt_clear(MapIntIntHandle handle);
bool MapIntInt_contains(MapIntIntHandle handle, const int key);
ListIntHandle MapIntInt_keys(MapIntIntHandle handle);
ListIntHandle MapIntInt_values(MapIntIntHandle handle);
ListPairIntIntHandle MapIntInt_items(MapIntIntHandle handle);
bool MapIntInt_equal(MapIntIntHandle a, MapIntIntHandle b);
bool MapIntInt_not_equal(MapIntIntHandle a, MapIntIntHandle b);
// Serialization (from Song)
const char*      MapIntInt_to_json_string(MapIntIntHandle handle);
MapIntIntHandle MapIntInt_from_json_string(const char* json);

#ifdef __cplusplus
}
#endif