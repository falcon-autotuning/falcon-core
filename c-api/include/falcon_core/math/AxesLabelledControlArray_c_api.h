#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/LabelledControlArray_c_api.h"
#include "falcon_core/generic/ListLabelledControlArray_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesLabelledControlArrayHandle;
// Function declarations

AxesLabelledControlArrayHandle AxesLabelledControlArray_create_empty();
AxesLabelledControlArrayHandle AxesLabelledControlArray_create_raw(const LabelledControlArrayHandle* data, size_t count);
AxesLabelledControlArrayHandle AxesLabelledControlArray_create(ListLabelledControlArrayHandle data);
void AxesLabelledControlArray_destroy(AxesLabelledControlArrayHandle handle);
void AxesLabelledControlArray_push_back(AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle value);
size_t AxesLabelledControlArray_size(AxesLabelledControlArrayHandle handle);
bool AxesLabelledControlArray_empty(AxesLabelledControlArrayHandle handle);
void AxesLabelledControlArray_erase_at(AxesLabelledControlArrayHandle handle, size_t idx);
void AxesLabelledControlArray_clear(AxesLabelledControlArrayHandle handle);
LabelledControlArrayHandle AxesLabelledControlArray_at(AxesLabelledControlArrayHandle handle, size_t idx);
size_t AxesLabelledControlArray_items(AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle* out_buffer, size_t buffer_size);
bool AxesLabelledControlArray_contains(AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle value);
size_t AxesLabelledControlArray_index(AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle value);
AxesLabelledControlArrayHandle AxesLabelledControlArray_intersection(AxesLabelledControlArrayHandle handle, AxesLabelledControlArrayHandle other);
bool AxesLabelledControlArray_equal(AxesLabelledControlArrayHandle a, AxesLabelledControlArrayHandle b);
bool AxesLabelledControlArray_not_equal(AxesLabelledControlArrayHandle a, AxesLabelledControlArrayHandle b);

// Serialization (from Song)
StringHandle      AxesLabelledControlArray_to_json_string(AxesLabelledControlArrayHandle handle);
AxesLabelledControlArrayHandle AxesLabelledControlArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif