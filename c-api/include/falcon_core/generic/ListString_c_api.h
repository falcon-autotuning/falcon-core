#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListStringHandle;
// Function declarations

// @category:allocation
ListStringHandle ListString_create_empty();
// @category:allocation
ListStringHandle ListString_copy(ListStringHandle handle);
// @category:allocation
ListStringHandle ListString_allocate(size_t count);
// @category:allocation
ListStringHandle ListString_fill_value(size_t count, StringHandle value);
// @category:allocation
ListStringHandle ListString_create(StringHandle* data, size_t count);
// @category:deallocation
void ListString_destroy(ListStringHandle handle);
// @category:write
void ListString_push_back(ListStringHandle handle, StringHandle value);
// @category:read
size_t ListString_size(ListStringHandle handle);
// @category:read
bool ListString_empty(ListStringHandle handle);
// @category:write
void ListString_erase_at(ListStringHandle handle, size_t idx);
// @category:write
void ListString_clear(ListStringHandle handle);
// @category:read
StringHandle ListString_at(ListStringHandle handle, size_t idx);
// @category:read
size_t ListString_items(ListStringHandle handle, StringHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListString_contains(ListStringHandle handle, StringHandle value);
// @category:read
size_t ListString_index(ListStringHandle handle, StringHandle value);
// @category:read
ListStringHandle ListString_intersection(ListStringHandle handle, ListStringHandle other);
// @category:read
bool ListString_equal(ListStringHandle handle, ListStringHandle other);
// @category:read
bool ListString_not_equal(ListStringHandle handle, ListStringHandle other);

// @category:read
StringHandle      ListString_to_json_string(ListStringHandle handle);
// @category:allocation
ListStringHandle ListString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif