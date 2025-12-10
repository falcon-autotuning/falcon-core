#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListListSizeTHandle;
// Function declarations

// @category:allocation
ListListSizeTHandle ListListSizeT_create_empty();

// @category:allocation
ListListSizeTHandle ListListSizeT_fill_value(size_t count, ListSizeTHandle value);
// @category:allocation
ListListSizeTHandle ListListSizeT_create(ListSizeTHandle* data, size_t count);
// @category:deallocation
void ListListSizeT_destroy(ListListSizeTHandle handle);
// @category:write
void ListListSizeT_push_back(ListListSizeTHandle handle, ListSizeTHandle value);
// @category:read
size_t ListListSizeT_size(ListListSizeTHandle handle);
// @category:read
bool ListListSizeT_empty(ListListSizeTHandle handle);
// @category:write
void ListListSizeT_erase_at(ListListSizeTHandle handle, size_t idx);
// @category:write
void ListListSizeT_clear(ListListSizeTHandle handle);
// @category:read
ListSizeTHandle ListListSizeT_at(ListListSizeTHandle handle, size_t idx);
// @category:read
size_t ListListSizeT_items(ListListSizeTHandle handle, ListSizeTHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListListSizeT_contains(ListListSizeTHandle handle, ListSizeTHandle value);
// @category:read
size_t ListListSizeT_index(ListListSizeTHandle handle, ListSizeTHandle value);
// @category:read
ListListSizeTHandle ListListSizeT_intersection(ListListSizeTHandle handle, ListListSizeTHandle other);
// @category:read
bool ListListSizeT_equal(ListListSizeTHandle a, ListListSizeTHandle b);
// @category:read
bool ListListSizeT_not_equal(ListListSizeTHandle a, ListListSizeTHandle b);

// @category:read
StringHandle      ListListSizeT_to_json_string(ListListSizeTHandle handle);
// @category:allocation
ListListSizeTHandle ListListSizeT_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif