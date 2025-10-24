#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/MapStringBool_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListMapStringBoolHandle;
// Function declarations

ListMapStringBoolHandle ListMapStringBool_create_empty();
ListMapStringBoolHandle ListMapStringBool_allocate(size_t count);
ListMapStringBoolHandle ListMapStringBool_fill_value(size_t count, MapStringBoolHandle value);
ListMapStringBoolHandle ListMapStringBool_create(const MapStringBoolHandle* data, size_t count);
void ListMapStringBool_destroy(ListMapStringBoolHandle handle);
void ListMapStringBool_push_back(ListMapStringBoolHandle handle, MapStringBoolHandle value);
size_t ListMapStringBool_size(ListMapStringBoolHandle handle);
bool ListMapStringBool_empty(ListMapStringBoolHandle handle);
void ListMapStringBool_erase_at(ListMapStringBoolHandle handle, size_t idx);
void ListMapStringBool_clear(ListMapStringBoolHandle handle);
MapStringBoolHandle ListMapStringBool_at(ListMapStringBoolHandle handle, size_t idx);
size_t ListMapStringBool_items(ListMapStringBoolHandle handle, MapStringBoolHandle* out_buffer, size_t buffer_size);
bool ListMapStringBool_contains(ListMapStringBoolHandle handle, MapStringBoolHandle value);
size_t ListMapStringBool_index(ListMapStringBoolHandle handle, MapStringBoolHandle value);
ListMapStringBoolHandle ListMapStringBool_intersection(ListMapStringBoolHandle handle, ListMapStringBoolHandle other);
bool ListMapStringBool_equal(ListMapStringBoolHandle a, ListMapStringBoolHandle b);
bool ListMapStringBool_not_equal(ListMapStringBoolHandle a, ListMapStringBoolHandle b);

// Serialization (from Song)
StringHandle      ListMapStringBool_to_json_string(ListMapStringBoolHandle handle);
ListMapStringBoolHandle ListMapStringBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif