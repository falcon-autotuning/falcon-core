#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListStringHandle;
// Function declarations

ListStringHandle ListString_create_empty();
ListStringHandle ListString_allocate(size_t count);
ListStringHandle ListString_fill_value(size_t count, StringHandle value);
ListStringHandle ListString_create(const StringHandle* data, size_t count);
void ListString_destroy(ListStringHandle handle);
void ListString_push_back(ListStringHandle handle, StringHandle value);
size_t ListString_size(ListStringHandle handle);
bool ListString_empty(ListStringHandle handle);
void ListString_erase_at(ListStringHandle handle, size_t idx);
void ListString_clear(ListStringHandle handle);
StringHandle ListString_at(ListStringHandle handle, size_t idx);
size_t ListString_items(ListStringHandle handle, StringHandle* out_buffer, size_t buffer_size);
bool ListString_contains(ListStringHandle handle, StringHandle value);
size_t ListString_index(ListStringHandle handle, StringHandle value);
ListStringHandle ListString_intersection(ListStringHandle handle, ListStringHandle other);
bool ListString_equal(ListStringHandle a, ListStringHandle b);
bool ListString_not_equal(ListStringHandle a, ListStringHandle b);

// Serialization (from Song)
StringHandle      ListString_to_json_string(ListStringHandle handle);
ListStringHandle ListString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif