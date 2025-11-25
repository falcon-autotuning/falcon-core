#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListListSizeTHandle;
// Function declarations

ListListSizeTHandle ListListSizeT_create_empty();

ListListSizeTHandle ListListSizeT_fill_value(size_t count, ListSizeTHandle value);
ListListSizeTHandle ListListSizeT_create(ListSizeTHandle* data, size_t count);
void ListListSizeT_destroy(ListListSizeTHandle handle);
void ListListSizeT_push_back(ListListSizeTHandle handle, ListSizeTHandle value);
size_t ListListSizeT_size(ListListSizeTHandle handle);
bool ListListSizeT_empty(ListListSizeTHandle handle);
void ListListSizeT_erase_at(ListListSizeTHandle handle, size_t idx);
void ListListSizeT_clear(ListListSizeTHandle handle);
ListSizeTHandle ListListSizeT_at(ListListSizeTHandle handle, size_t idx);
size_t ListListSizeT_items(ListListSizeTHandle handle, ListSizeTHandle* out_buffer, size_t buffer_size);
bool ListListSizeT_contains(ListListSizeTHandle handle, ListSizeTHandle value);
size_t ListListSizeT_index(ListListSizeTHandle handle, ListSizeTHandle value);
ListListSizeTHandle ListListSizeT_intersection(ListListSizeTHandle handle, ListListSizeTHandle other);
bool ListListSizeT_equal(ListListSizeTHandle a, ListListSizeTHandle b);
bool ListListSizeT_not_equal(ListListSizeTHandle a, ListListSizeTHandle b);

// Serialization (from Song)
StringHandle      ListListSizeT_to_json_string(ListListSizeTHandle handle);
ListListSizeTHandle ListListSizeT_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif