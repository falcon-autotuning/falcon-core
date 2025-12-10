#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/LabelledMeasuredArray1D_c_api.h"
#include "falcon_core/generic/ListLabelledMeasuredArray1D_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesLabelledMeasuredArray1DHandle;
// Function declarations

// @category:allocation
AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_create_empty();
// @category:allocation
AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_copy(AxesLabelledMeasuredArray1DHandle handle);
// @category:allocation
AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_create(ListLabelledMeasuredArray1DHandle data);
// @category:deallocation
void AxesLabelledMeasuredArray1D_destroy(AxesLabelledMeasuredArray1DHandle handle);
// @category:write
void AxesLabelledMeasuredArray1D_push_back(AxesLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value);
// @category:read
size_t AxesLabelledMeasuredArray1D_size(AxesLabelledMeasuredArray1DHandle handle);
// @category:read
bool AxesLabelledMeasuredArray1D_empty(AxesLabelledMeasuredArray1DHandle handle);
// @category:write
void AxesLabelledMeasuredArray1D_erase_at(AxesLabelledMeasuredArray1DHandle handle, size_t idx);
// @category:write
void AxesLabelledMeasuredArray1D_clear(AxesLabelledMeasuredArray1DHandle handle);
// @category:read
LabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_at(AxesLabelledMeasuredArray1DHandle handle, size_t idx);
// @category:read
size_t AxesLabelledMeasuredArray1D_items(AxesLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle* out_buffer, size_t buffer_size);
// @category:read
bool AxesLabelledMeasuredArray1D_contains(AxesLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value);
// @category:read
size_t AxesLabelledMeasuredArray1D_index(AxesLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value);
// @category:read
AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_intersection(AxesLabelledMeasuredArray1DHandle handle, AxesLabelledMeasuredArray1DHandle other);
// @category:read
bool AxesLabelledMeasuredArray1D_equal(AxesLabelledMeasuredArray1DHandle handle, AxesLabelledMeasuredArray1DHandle other);
// @category:read
bool AxesLabelledMeasuredArray1D_not_equal(AxesLabelledMeasuredArray1DHandle handle, AxesLabelledMeasuredArray1DHandle other);

// @category:read
StringHandle      AxesLabelledMeasuredArray1D_to_json_string(AxesLabelledMeasuredArray1DHandle handle);
// @category:allocation
AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif