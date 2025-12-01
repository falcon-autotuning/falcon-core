#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/ControlArray_c_api.h"
#include "falcon_core/generic/ListControlArray_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesControlArrayHandle;
// Function declarations

AxesControlArrayHandle AxesControlArray_create_empty();
AxesControlArrayHandle AxesControlArray_create_raw(const ControlArrayHandle* data, size_t count);
AxesControlArrayHandle AxesControlArray_create(ListControlArrayHandle data);
void AxesControlArray_destroy(AxesControlArrayHandle handle);
void AxesControlArray_push_back(AxesControlArrayHandle handle, ControlArrayHandle value);
size_t AxesControlArray_size(AxesControlArrayHandle handle);
bool AxesControlArray_empty(AxesControlArrayHandle handle);
void AxesControlArray_erase_at(AxesControlArrayHandle handle, size_t idx);
void AxesControlArray_clear(AxesControlArrayHandle handle);
ControlArrayHandle AxesControlArray_at(AxesControlArrayHandle handle, size_t idx);
size_t AxesControlArray_items(AxesControlArrayHandle handle, ControlArrayHandle* out_buffer, size_t buffer_size);
bool AxesControlArray_contains(AxesControlArrayHandle handle, ControlArrayHandle value);
size_t AxesControlArray_index(AxesControlArrayHandle handle, ControlArrayHandle value);
AxesControlArrayHandle AxesControlArray_intersection(AxesControlArrayHandle handle, AxesControlArrayHandle other);
bool AxesControlArray_equal(AxesControlArrayHandle a, AxesControlArrayHandle b);
bool AxesControlArray_not_equal(AxesControlArrayHandle a, AxesControlArrayHandle b);

// Serialization (from Song)
StringHandle      AxesControlArray_to_json_string(AxesControlArrayHandle handle);
AxesControlArrayHandle AxesControlArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif