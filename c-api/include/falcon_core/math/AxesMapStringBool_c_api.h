#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListMapStringBool_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesMapStringBoolHandle;
// Function declarations

AxesMapStringBoolHandle AxesMapStringBool_create_empty();
AxesMapStringBoolHandle AxesMapStringBool_create_raw(const MapStringBoolHandle* data, size_t count);
AxesMapStringBoolHandle AxesMapStringBool_create(ListMapStringBoolHandle data);
void AxesMapStringBool_destroy(AxesMapStringBoolHandle handle);
void AxesMapStringBool_push_back(AxesMapStringBoolHandle handle, MapStringBoolHandle value);
size_t AxesMapStringBool_size(AxesMapStringBoolHandle handle);
bool AxesMapStringBool_empty(AxesMapStringBoolHandle handle);
void AxesMapStringBool_erase_at(AxesMapStringBoolHandle handle, size_t idx);
void AxesMapStringBool_clear(AxesMapStringBoolHandle handle);
MapStringBoolHandle AxesMapStringBool_at(AxesMapStringBoolHandle handle, size_t idx);
size_t AxesMapStringBool_items(AxesMapStringBoolHandle handle, MapStringBoolHandle* out_buffer, size_t buffer_size);
bool AxesMapStringBool_contains(AxesMapStringBoolHandle handle, MapStringBoolHandle value);
size_t AxesMapStringBool_index(AxesMapStringBoolHandle handle, MapStringBoolHandle value);
AxesMapStringBoolHandle AxesMapStringBool_intersection(AxesMapStringBoolHandle handle, AxesMapStringBoolHandle other);
bool AxesMapStringBool_equal(AxesMapStringBoolHandle a, AxesMapStringBoolHandle b);
bool AxesMapStringBool_not_equal(AxesMapStringBoolHandle a, AxesMapStringBoolHandle b);

// Serialization (from Song)
StringHandle      AxesMapStringBool_to_json_string(AxesMapStringBoolHandle handle);
AxesMapStringBoolHandle AxesMapStringBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif