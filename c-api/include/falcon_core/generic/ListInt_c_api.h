#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListIntHandle;
// Function declarations

ListIntHandle ListInt_create_empty();
ListIntHandle ListInt_allocate(size_t count);
ListIntHandle ListInt_fill_value(size_t count, int value);
ListIntHandle ListInt_create(int* data, size_t count);
void ListInt_destroy(ListIntHandle handle);
void ListInt_push_back(ListIntHandle handle, int value);
size_t ListInt_size(ListIntHandle handle);
bool ListInt_empty(ListIntHandle handle);
void ListInt_erase_at(ListIntHandle handle, size_t idx);
void ListInt_clear(ListIntHandle handle);
int ListInt_at(ListIntHandle handle, size_t idx);
size_t ListInt_items(ListIntHandle handle, int* out_buffer, size_t buffer_size);
bool ListInt_contains(ListIntHandle handle, int value);
size_t ListInt_index(ListIntHandle handle, int value);
ListIntHandle ListInt_intersection(ListIntHandle handle, ListIntHandle other);
bool ListInt_equal(ListIntHandle a, ListIntHandle b);
bool ListInt_not_equal(ListIntHandle a, ListIntHandle b);

// Serialization (from Song)
StringHandle      ListInt_to_json_string(ListIntHandle handle);
ListIntHandle ListInt_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif