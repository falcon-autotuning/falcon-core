#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListLabelledMeasuredArray_c_api.h"
#include "falcon_core/generic/ListAcquisitionContext_c_api.h"
#include <stddef.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* LabelledArraysLabelledMeasuredArrayHandle;
// Function declarations

// Constructors
LabelledArraysLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_create(
    ListLabelledMeasuredArrayHandle arrays);

// Destructor
void LabelledArraysLabelledMeasuredArray_destroy(
    LabelledArraysLabelledMeasuredArrayHandle handle);

// Methods
ListLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_arrays(
    LabelledArraysLabelledMeasuredArrayHandle handle);
ListAcquisitionContextHandle LabelledArraysLabelledMeasuredArray_labels(
    LabelledArraysLabelledMeasuredArrayHandle handle);
bool LabelledArraysLabelledMeasuredArray_isControlArrays(
    LabelledArraysLabelledMeasuredArrayHandle handle);
bool LabelledArraysLabelledMeasuredArray_isMeasuredArrays(
    LabelledArraysLabelledMeasuredArrayHandle handle);
void LabelledArraysLabelledMeasuredArray_push_back(
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle value);
size_t LabelledArraysLabelledMeasuredArray_size(
    LabelledArraysLabelledMeasuredArrayHandle handle);
bool LabelledArraysLabelledMeasuredArray_empty(
    LabelledArraysLabelledMeasuredArrayHandle handle);
void LabelledArraysLabelledMeasuredArray_erase_at(
    LabelledArraysLabelledMeasuredArrayHandle handle, size_t idx);
void LabelledArraysLabelledMeasuredArray_clear(
    LabelledArraysLabelledMeasuredArrayHandle handle);
LabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_at(
    LabelledArraysLabelledMeasuredArrayHandle handle, size_t idx);
bool LabelledArraysLabelledMeasuredArray_contains(
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle value);
size_t LabelledArraysLabelledMeasuredArray_index(
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle value);
LabelledArraysLabelledMeasuredArrayHandle
LabelledArraysLabelledMeasuredArray_intersection(
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledArraysLabelledMeasuredArrayHandle other);
bool LabelledArraysLabelledMeasuredArray_equal(
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledArraysLabelledMeasuredArrayHandle other);
bool LabelledArraysLabelledMeasuredArray_not_equal(
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledArraysLabelledMeasuredArrayHandle other);

// Serialization (from Song)
StringHandle      LabelledArraysLabelledMeasuredArray_to_json_string(LabelledArraysLabelledMeasuredArrayHandle handle);
LabelledArraysLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif