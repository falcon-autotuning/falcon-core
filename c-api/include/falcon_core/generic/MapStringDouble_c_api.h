#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListPairStringDouble_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
#include "falcon_core/generic/ListDouble_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapStringDoubleHandle;
// Function declarations

// @category:allocation
MapStringDoubleHandle MapStringDouble_create_empty();
// @category:allocation
MapStringDoubleHandle MapStringDouble_create(PairStringDoubleHandle* data, size_t count);
// @category:deallocation
void MapStringDouble_destroy(MapStringDoubleHandle handle);
// @category:write
void MapStringDouble_insert_or_assign(MapStringDoubleHandle handle, StringHandle key, double value);
// @category:write
void MapStringDouble_insert(MapStringDoubleHandle handle, StringHandle key, double value);
// @category:read
double MapStringDouble_at(MapStringDoubleHandle handle, StringHandle key);
// @category:write
void MapStringDouble_erase(MapStringDoubleHandle handle, StringHandle key);
// @category:read
size_t MapStringDouble_size(MapStringDoubleHandle handle);
// @category:read
bool MapStringDouble_empty(MapStringDoubleHandle handle);
// @category:write
void MapStringDouble_clear(MapStringDoubleHandle handle);
// @category:read
bool MapStringDouble_contains(MapStringDoubleHandle handle, StringHandle key);
// @category:read
ListStringHandle MapStringDouble_keys(MapStringDoubleHandle handle);
// @category:read
ListDoubleHandle MapStringDouble_values(MapStringDoubleHandle handle);
// @category:read
ListPairStringDoubleHandle MapStringDouble_items(MapStringDoubleHandle handle);
// @category:read
bool MapStringDouble_equal(MapStringDoubleHandle a, MapStringDoubleHandle b);
// @category:read
bool MapStringDouble_not_equal(MapStringDoubleHandle a, MapStringDoubleHandle b);
// @category:read
StringHandle      MapStringDouble_to_json_string(MapStringDoubleHandle handle);
// @category:allocation
MapStringDoubleHandle MapStringDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif