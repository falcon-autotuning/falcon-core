#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListBoolHandle;
// Function declarations

ListBoolHandle ListBool_create_empty();
ListBoolHandle ListBool_allocate(size_t count);
ListBoolHandle ListBool_fill_value(size_t count, bool value);
ListBoolHandle ListBool_create(bool* data, size_t count);
void ListBool_destroy(ListBoolHandle handle);
void ListBool_push_back(ListBoolHandle handle, bool value);
size_t ListBool_size(ListBoolHandle handle);
bool ListBool_empty(ListBoolHandle handle);
void ListBool_erase_at(ListBoolHandle handle, size_t idx);
void ListBool_clear(ListBoolHandle handle);
bool ListBool_at(ListBoolHandle handle, size_t idx);
size_t ListBool_items(ListBoolHandle handle, bool* out_buffer, size_t buffer_size);
bool ListBool_contains(ListBoolHandle handle, bool value);
size_t ListBool_index(ListBoolHandle handle, bool value);
ListBoolHandle ListBool_intersection(ListBoolHandle handle, ListBoolHandle other);
bool ListBool_equal(ListBoolHandle a, ListBoolHandle b);
bool ListBool_not_equal(ListBoolHandle a, ListBoolHandle b);

// Serialization (from Song)
StringHandle      ListBool_to_json_string(ListBoolHandle handle);
ListBoolHandle ListBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif