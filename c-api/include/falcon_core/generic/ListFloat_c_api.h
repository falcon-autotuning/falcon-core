#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <cstddef>

// Forward declarations for opaque handles
typedef void* ListFloatHandle;
// Function declarations

ListFloatHandle ListFloat_create_empty();
ListFloatHandle ListFloat_allocate(size_t count);
ListFloatHandle ListFloat_fill_value(size_t count, float value);
ListFloatHandle ListFloat_create(const float* data, size_t count);
void ListFloat_destroy(ListFloatHandle handle);
void ListFloat_push_back(ListFloatHandle handle, float value);
size_t ListFloat_size(ListFloatHandle handle);
bool ListFloat_empty(ListFloatHandle handle);
void ListFloat_erase_at(ListFloatHandle handle, size_t idx);
void ListFloat_clear(ListFloatHandle handle);
float ListFloat_at(ListFloatHandle handle, size_t idx);
size_t ListFloat_items(ListFloatHandle handle, float* out_buffer, size_t buffer_size);
bool ListFloat_contains(ListFloatHandle handle, float value);
size_t ListFloat_index(ListFloatHandle handle, float value);
ListFloatHandle ListFloat_intersection(ListFloatHandle handle, ListFloatHandle other);
bool ListFloat_equal(ListFloatHandle a, ListFloatHandle b);
bool ListFloat_not_equal(ListFloatHandle a, ListFloatHandle b);

// Serialization (from Song)
const char*      ListFloat_to_json_string(ListFloatHandle handle);
ListFloatHandle ListFloat_from_json_string(const char* json);

#ifdef __cplusplus
}
#endif