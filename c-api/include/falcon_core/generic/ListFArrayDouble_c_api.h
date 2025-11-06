#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListFArrayDoubleHandle;
// Function declarations

ListFArrayDoubleHandle ListFArrayDouble_create_empty();

ListFArrayDoubleHandle ListFArrayDouble_fill_value(size_t count, FArrayDoubleHandle value);
ListFArrayDoubleHandle ListFArrayDouble_create(FArrayDoubleHandle* data, size_t count);
void ListFArrayDouble_destroy(ListFArrayDoubleHandle handle);
void ListFArrayDouble_push_back(ListFArrayDoubleHandle handle, FArrayDoubleHandle value);
size_t ListFArrayDouble_size(ListFArrayDoubleHandle handle);
bool ListFArrayDouble_empty(ListFArrayDoubleHandle handle);
void ListFArrayDouble_erase_at(ListFArrayDoubleHandle handle, size_t idx);
void ListFArrayDouble_clear(ListFArrayDoubleHandle handle);
FArrayDoubleHandle ListFArrayDouble_at(ListFArrayDoubleHandle handle, size_t idx);
size_t ListFArrayDouble_items(ListFArrayDoubleHandle handle, FArrayDoubleHandle* out_buffer, size_t buffer_size);
bool ListFArrayDouble_contains(ListFArrayDoubleHandle handle, FArrayDoubleHandle value);
size_t ListFArrayDouble_index(ListFArrayDoubleHandle handle, FArrayDoubleHandle value);
ListFArrayDoubleHandle ListFArrayDouble_intersection(ListFArrayDoubleHandle handle, ListFArrayDoubleHandle other);
bool ListFArrayDouble_equal(ListFArrayDoubleHandle a, ListFArrayDoubleHandle b);
bool ListFArrayDouble_not_equal(ListFArrayDoubleHandle a, ListFArrayDoubleHandle b);

// Serialization (from Song)
StringHandle      ListFArrayDouble_to_json_string(ListFArrayDoubleHandle handle);
ListFArrayDoubleHandle ListFArrayDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif