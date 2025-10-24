#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <cstddef>

// Forward declarations for opaque handles
typedef void* ListSizeTHandle;
// Function declarations

ListSizeTHandle ListSizeT_create_empty();
ListSizeTHandle ListSizeT_allocate(size_t count);
ListSizeTHandle ListSizeT_fill_value(size_t count, size_t value);
ListSizeTHandle ListSizeT_create(const size_t* data, size_t count);
void ListSizeT_destroy(ListSizeTHandle handle);
void ListSizeT_push_back(ListSizeTHandle handle, size_t value);
size_t ListSizeT_size(ListSizeTHandle handle);
bool ListSizeT_empty(ListSizeTHandle handle);
void ListSizeT_erase_at(ListSizeTHandle handle, size_t idx);
void ListSizeT_clear(ListSizeTHandle handle);
size_t ListSizeT_at(ListSizeTHandle handle, size_t idx);
size_t ListSizeT_items(ListSizeTHandle handle, size_t* out_buffer, size_t buffer_size);
bool ListSizeT_contains(ListSizeTHandle handle, size_t value);
size_t ListSizeT_index(ListSizeTHandle handle, size_t value);
ListSizeTHandle ListSizeT_intersection(ListSizeTHandle handle, ListSizeTHandle other);
bool ListSizeT_equal(ListSizeTHandle a, ListSizeTHandle b);
bool ListSizeT_not_equal(ListSizeTHandle a, ListSizeTHandle b);

// Serialization (from Song)
const char*      ListSizeT_to_json_string(ListSizeTHandle handle);
ListSizeTHandle ListSizeT_from_json_string(const char* json);

#ifdef __cplusplus
}
#endif