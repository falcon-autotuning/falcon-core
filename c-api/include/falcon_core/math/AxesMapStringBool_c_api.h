#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListMapStringBool_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesMapStringBoolHandle;
// Function declarations

// @category:allocation
AxesMapStringBoolHandle AxesMapStringBool_create_empty();
// @category:allocation
AxesMapStringBoolHandle AxesMapStringBool_create_raw(const MapStringBoolHandle* data, size_t count);
// @category:allocation
AxesMapStringBoolHandle AxesMapStringBool_create(ListMapStringBoolHandle data);
// @category:deallocation
void AxesMapStringBool_destroy(AxesMapStringBoolHandle handle);
// @category:write
void AxesMapStringBool_push_back(AxesMapStringBoolHandle handle, MapStringBoolHandle value);
// @category:read
size_t AxesMapStringBool_size(AxesMapStringBoolHandle handle);
// @category:read
bool AxesMapStringBool_empty(AxesMapStringBoolHandle handle);
// @category:write
void AxesMapStringBool_erase_at(AxesMapStringBoolHandle handle, size_t idx);
// @category:write
void AxesMapStringBool_clear(AxesMapStringBoolHandle handle);
// @category:read
MapStringBoolHandle AxesMapStringBool_at(AxesMapStringBoolHandle handle, size_t idx);
// @category:read
size_t AxesMapStringBool_items(AxesMapStringBoolHandle handle, MapStringBoolHandle* out_buffer, size_t buffer_size);
// @category:read
bool AxesMapStringBool_contains(AxesMapStringBoolHandle handle, MapStringBoolHandle value);
// @category:read
size_t AxesMapStringBool_index(AxesMapStringBoolHandle handle, MapStringBoolHandle value);
// @category:read
AxesMapStringBoolHandle AxesMapStringBool_intersection(AxesMapStringBoolHandle handle, AxesMapStringBoolHandle other);
// @category:read
bool AxesMapStringBool_equal(AxesMapStringBoolHandle a, AxesMapStringBoolHandle b);
// @category:read
bool AxesMapStringBool_not_equal(AxesMapStringBoolHandle a, AxesMapStringBoolHandle b);

// @category:read
StringHandle      AxesMapStringBool_to_json_string(AxesMapStringBoolHandle handle);
// @category:allocation
AxesMapStringBoolHandle AxesMapStringBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif