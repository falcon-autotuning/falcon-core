#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListDoubleHandle;
// Function declarations

ListDoubleHandle ListDouble_create_empty();
ListDoubleHandle ListDouble_allocate(size_t count);
ListDoubleHandle ListDouble_fill_value(size_t count, double value);
ListDoubleHandle ListDouble_create(double* data, size_t count);
void ListDouble_destroy(ListDoubleHandle handle);
void ListDouble_push_back(ListDoubleHandle handle, double value);
size_t ListDouble_size(ListDoubleHandle handle);
bool ListDouble_empty(ListDoubleHandle handle);
void ListDouble_erase_at(ListDoubleHandle handle, size_t idx);
void ListDouble_clear(ListDoubleHandle handle);
double ListDouble_at(ListDoubleHandle handle, size_t idx);
size_t ListDouble_items(ListDoubleHandle handle, double* out_buffer, size_t buffer_size);
bool ListDouble_contains(ListDoubleHandle handle, double value);
size_t ListDouble_index(ListDoubleHandle handle, double value);
ListDoubleHandle ListDouble_intersection(ListDoubleHandle handle, ListDoubleHandle other);
bool ListDouble_equal(ListDoubleHandle a, ListDoubleHandle b);
bool ListDouble_not_equal(ListDoubleHandle a, ListDoubleHandle b);

// Serialization (from Song)
StringHandle      ListDouble_to_json_string(ListDoubleHandle handle);
ListDoubleHandle ListDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif