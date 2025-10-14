#pragma once
#include <cstddef>
#ifdef __cplusplus
extern "C" {
#endif
#include "falcon_core/generic/Pair_c_api.h"
#include "falcon_core/generic/List_c_api.h"

// Forward declarations for opaque handles
typedef void* MapIntIntHandle;
typedef void* MapFloatFloatHandle;
typedef void* MapConnectionFloatHandle;

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
ListFloatHandle MapFloatFloat_keys(MapFloatFloatHandle handle);
ListFloatHandle MapFloatFloat_values(MapFloatFloatHandle handle);
ListPairFloatFloatHandle MapFloatFloat_items(MapFloatFloatHandle handle);
bool MapFloatFloat_equal(MapFloatFloatHandle a, MapFloatFloatHandle b);
bool MapFloatFloat_not_equal(MapFloatFloatHandle a, MapFloatFloatHandle b);

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

#ifdef __cplusplus
}
#endif
