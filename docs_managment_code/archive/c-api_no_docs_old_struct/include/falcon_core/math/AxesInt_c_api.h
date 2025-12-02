#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListInt_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesIntHandle;
// Function declarations

AxesIntHandle AxesInt_create_empty();
AxesIntHandle AxesInt_create_raw(const int* data, size_t count);
AxesIntHandle AxesInt_create(ListIntHandle data);
void AxesInt_destroy(AxesIntHandle handle);
void AxesInt_push_back(AxesIntHandle handle, int value);
size_t AxesInt_size(AxesIntHandle handle);
bool AxesInt_empty(AxesIntHandle handle);
void AxesInt_erase_at(AxesIntHandle handle, size_t idx);
void AxesInt_clear(AxesIntHandle handle);
int AxesInt_at(AxesIntHandle handle, size_t idx);
size_t AxesInt_items(AxesIntHandle handle, int* out_buffer, size_t buffer_size);
bool AxesInt_contains(AxesIntHandle handle, int value);
size_t AxesInt_index(AxesIntHandle handle, int value);
AxesIntHandle AxesInt_intersection(AxesIntHandle handle, AxesIntHandle other);
bool AxesInt_equal(AxesIntHandle a, AxesIntHandle b);
bool AxesInt_not_equal(AxesIntHandle a, AxesIntHandle b);

// Serialization (from Song)
StringHandle      AxesInt_to_json_string(AxesIntHandle handle);
AxesIntHandle AxesInt_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif