#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListLabelledMeasuredArray_c_api.h"
#include "falcon_core/generic/ListAcquisitionContext_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* LabelledArraysLabelledMeasuredArrayHandle;
// Function declarations

// @category:allocation
LabelledArraysLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_create(
    ListLabelledMeasuredArrayHandle arrays);
// @category:deallocation
void LabelledArraysLabelledMeasuredArray_destroy(
    LabelledArraysLabelledMeasuredArrayHandle handle);
// @category:read
ListLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_arrays(
    LabelledArraysLabelledMeasuredArrayHandle handle);
// @category:read
ListAcquisitionContextHandle LabelledArraysLabelledMeasuredArray_labels(
    LabelledArraysLabelledMeasuredArrayHandle handle);
// @category:read
bool LabelledArraysLabelledMeasuredArray_isControlArrays(
    LabelledArraysLabelledMeasuredArrayHandle handle);
// @category:read
bool LabelledArraysLabelledMeasuredArray_isMeasuredArrays(
    LabelledArraysLabelledMeasuredArrayHandle handle);
// @category:write
void LabelledArraysLabelledMeasuredArray_push_back(
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle value);
// @category:read
size_t LabelledArraysLabelledMeasuredArray_size(
    LabelledArraysLabelledMeasuredArrayHandle handle);
// @category:read
bool LabelledArraysLabelledMeasuredArray_empty(
    LabelledArraysLabelledMeasuredArrayHandle handle);
// @category:write
void LabelledArraysLabelledMeasuredArray_erase_at(
    LabelledArraysLabelledMeasuredArrayHandle handle, size_t idx);
// @category:write
void LabelledArraysLabelledMeasuredArray_clear(
    LabelledArraysLabelledMeasuredArrayHandle handle);
// @category:read
LabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_at(
    LabelledArraysLabelledMeasuredArrayHandle handle, size_t idx);
// @category:read
bool LabelledArraysLabelledMeasuredArray_contains(
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle value);
// @category:read
size_t LabelledArraysLabelledMeasuredArray_index(
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle value);
// @category:read
LabelledArraysLabelledMeasuredArrayHandle
LabelledArraysLabelledMeasuredArray_intersection(
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledArraysLabelledMeasuredArrayHandle other);
// @category:read
bool LabelledArraysLabelledMeasuredArray_equal(
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledArraysLabelledMeasuredArrayHandle other);
// @category:read
bool LabelledArraysLabelledMeasuredArray_not_equal(
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledArraysLabelledMeasuredArrayHandle other);

// @category:read
StringHandle      LabelledArraysLabelledMeasuredArray_to_json_string(LabelledArraysLabelledMeasuredArrayHandle handle);
// @category:allocation
LabelledArraysLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif