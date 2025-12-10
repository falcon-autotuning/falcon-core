#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListIntHandle;
// Function declarations

// @category:allocation
ListIntHandle ListInt_create_empty();
// @category:allocation
ListIntHandle ListInt_copy(ListIntHandle handle);
// @category:allocation
ListIntHandle ListInt_allocate(size_t count);
// @category:allocation
ListIntHandle ListInt_fill_value(size_t count, int value);
// @category:allocation
ListIntHandle ListInt_create(int* data, size_t count);
// @category:deallocation
void ListInt_destroy(ListIntHandle handle);
// @category:write
void ListInt_push_back(ListIntHandle handle, int value);
// @category:read
size_t ListInt_size(ListIntHandle handle);
// @category:read
bool ListInt_empty(ListIntHandle handle);
// @category:write
void ListInt_erase_at(ListIntHandle handle, size_t idx);
// @category:write
void ListInt_clear(ListIntHandle handle);
// @category:read
int ListInt_at(ListIntHandle handle, size_t idx);
// @category:read
size_t ListInt_items(ListIntHandle handle, int* out_buffer, size_t buffer_size);
// @category:read
bool ListInt_contains(ListIntHandle handle, int value);
// @category:read
size_t ListInt_index(ListIntHandle handle, int value);
// @category:read
ListIntHandle ListInt_intersection(ListIntHandle handle, ListIntHandle other);
// @category:read
bool ListInt_equal(ListIntHandle handle, ListIntHandle other);
// @category:read
bool ListInt_not_equal(ListIntHandle handle, ListIntHandle other);

// @category:read
StringHandle      ListInt_to_json_string(ListIntHandle handle);
// @category:allocation
ListIntHandle ListInt_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif