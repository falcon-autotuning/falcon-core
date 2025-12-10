#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListLabelledControlArray_c_api.h"
#include "falcon_core/generic/ListAcquisitionContext_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* LabelledArraysLabelledControlArrayHandle;
// Function declarations

// @category:allocation
LabelledArraysLabelledControlArrayHandle LabelledArraysLabelledControlArray_create(
    ListLabelledControlArrayHandle arrays);
// @category:allocation
LabelledArraysLabelledControlArrayHandle LabelledArraysLabelledControlArray_copy(LabelledArraysLabelledControlArrayHandle handle);
// @category:deallocation
void LabelledArraysLabelledControlArray_destroy(
    LabelledArraysLabelledControlArrayHandle handle);
// @category:read
ListLabelledControlArrayHandle LabelledArraysLabelledControlArray_arrays(
    LabelledArraysLabelledControlArrayHandle handle);
// @category:read
ListAcquisitionContextHandle LabelledArraysLabelledControlArray_labels(
    LabelledArraysLabelledControlArrayHandle handle);
// @category:read
bool LabelledArraysLabelledControlArray_is_control_arrays(
    LabelledArraysLabelledControlArrayHandle handle);
// @category:read
bool LabelledArraysLabelledControlArray_is_measured_arrays(
    LabelledArraysLabelledControlArrayHandle handle);
// @category:write
void LabelledArraysLabelledControlArray_push_back(
    LabelledArraysLabelledControlArrayHandle handle,
    LabelledControlArrayHandle value);
// @category:read
size_t LabelledArraysLabelledControlArray_size(
    LabelledArraysLabelledControlArrayHandle handle);
// @category:read
bool LabelledArraysLabelledControlArray_empty(
    LabelledArraysLabelledControlArrayHandle handle);
// @category:write
void LabelledArraysLabelledControlArray_erase_at(
    LabelledArraysLabelledControlArrayHandle handle, size_t idx);
// @category:write
void LabelledArraysLabelledControlArray_clear(
    LabelledArraysLabelledControlArrayHandle handle);
// @category:read
LabelledControlArrayHandle LabelledArraysLabelledControlArray_at(
    LabelledArraysLabelledControlArrayHandle handle, size_t idx);
// @category:read
bool LabelledArraysLabelledControlArray_contains(
    LabelledArraysLabelledControlArrayHandle handle,
    LabelledControlArrayHandle value);
// @category:read
size_t LabelledArraysLabelledControlArray_index(
    LabelledArraysLabelledControlArrayHandle handle,
    LabelledControlArrayHandle value);
// @category:read
LabelledArraysLabelledControlArrayHandle
LabelledArraysLabelledControlArray_intersection(
    LabelledArraysLabelledControlArrayHandle handle,
    LabelledArraysLabelledControlArrayHandle other);
// @category:read
bool LabelledArraysLabelledControlArray_equal(
    LabelledArraysLabelledControlArrayHandle handle,
    LabelledArraysLabelledControlArrayHandle other);
// @category:read
bool LabelledArraysLabelledControlArray_not_equal(
    LabelledArraysLabelledControlArrayHandle handle,
    LabelledArraysLabelledControlArrayHandle other);

// @category:read
StringHandle      LabelledArraysLabelledControlArray_to_json_string(LabelledArraysLabelledControlArrayHandle handle);
// @category:allocation
LabelledArraysLabelledControlArrayHandle LabelledArraysLabelledControlArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif