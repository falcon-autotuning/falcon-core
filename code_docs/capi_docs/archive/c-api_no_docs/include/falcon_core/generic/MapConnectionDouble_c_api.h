#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairConnectionDouble_c_api.h"
#include "falcon_core/generic/ListDouble_c_api.h"
#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/generic/ListPairConnectionDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapConnectionDoubleHandle;
// Function declarations

// @category:allocation
MapConnectionDoubleHandle MapConnectionDouble_create_empty();
// @category:allocation
MapConnectionDoubleHandle MapConnectionDouble_create(PairConnectionDoubleHandle* data, size_t count);
// @category:deallocation
void MapConnectionDouble_destroy(MapConnectionDoubleHandle handle);
// @category:write
void MapConnectionDouble_insert_or_assign(MapConnectionDoubleHandle handle, ConnectionHandle key, double value);
// @category:write
void MapConnectionDouble_insert(MapConnectionDoubleHandle handle, ConnectionHandle key, double value);
// @category:read
double MapConnectionDouble_at(MapConnectionDoubleHandle handle, ConnectionHandle key);
// @category:write
void MapConnectionDouble_erase(MapConnectionDoubleHandle handle, ConnectionHandle key);
// @category:read
size_t MapConnectionDouble_size(MapConnectionDoubleHandle handle);
// @category:read
bool MapConnectionDouble_empty(MapConnectionDoubleHandle handle);
// @category:write
void MapConnectionDouble_clear(MapConnectionDoubleHandle handle);
// @category:read
bool MapConnectionDouble_contains(MapConnectionDoubleHandle handle, ConnectionHandle key);
// @category:read
ListConnectionHandle MapConnectionDouble_keys(MapConnectionDoubleHandle handle);
// @category:read
ListDoubleHandle MapConnectionDouble_values(MapConnectionDoubleHandle handle);
// @category:read
ListPairConnectionDoubleHandle MapConnectionDouble_items(MapConnectionDoubleHandle handle);
// @category:read
bool MapConnectionDouble_equal(MapConnectionDoubleHandle a, MapConnectionDoubleHandle b);
// @category:read
bool MapConnectionDouble_not_equal(MapConnectionDoubleHandle a, MapConnectionDoubleHandle b);
// @category:read
StringHandle      MapConnectionDouble_to_json_string(MapConnectionDoubleHandle handle);
// @category:allocation
MapConnectionDoubleHandle MapConnectionDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif