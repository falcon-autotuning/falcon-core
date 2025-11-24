#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/LabelledMeasuredArray_c_api.h"
#include "falcon_core/generic/ListLabelledMeasuredArray_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesLabelledMeasuredArrayHandle;
// Function declarations

AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_create_empty();
AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_create_raw(const LabelledMeasuredArrayHandle* data, size_t count);
AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_create(ListLabelledMeasuredArrayHandle data);
void AxesLabelledMeasuredArray_destroy(AxesLabelledMeasuredArrayHandle handle);
void AxesLabelledMeasuredArray_push_back(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value);
size_t AxesLabelledMeasuredArray_size(AxesLabelledMeasuredArrayHandle handle);
bool AxesLabelledMeasuredArray_empty(AxesLabelledMeasuredArrayHandle handle);
void AxesLabelledMeasuredArray_erase_at(AxesLabelledMeasuredArrayHandle handle, size_t idx);
void AxesLabelledMeasuredArray_clear(AxesLabelledMeasuredArrayHandle handle);
LabelledMeasuredArrayHandle AxesLabelledMeasuredArray_at(AxesLabelledMeasuredArrayHandle handle, size_t idx);
size_t AxesLabelledMeasuredArray_items(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle* out_buffer, size_t buffer_size);
bool AxesLabelledMeasuredArray_contains(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value);
size_t AxesLabelledMeasuredArray_index(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value);
AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_intersection(AxesLabelledMeasuredArrayHandle handle, AxesLabelledMeasuredArrayHandle other);
bool AxesLabelledMeasuredArray_equal(AxesLabelledMeasuredArrayHandle a, AxesLabelledMeasuredArrayHandle b);
bool AxesLabelledMeasuredArray_not_equal(AxesLabelledMeasuredArrayHandle a, AxesLabelledMeasuredArrayHandle b);

// Serialization (from Song)
StringHandle      AxesLabelledMeasuredArray_to_json_string(AxesLabelledMeasuredArrayHandle handle);
AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif