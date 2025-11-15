#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListLabelledMeasuredArray1D_c_api.h"
#include "falcon_core/generic/ListAcquisitionContext_c_api.h"
#include <stddef.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* LabelledArraysLabelledMeasuredArray1DHandle;
// Function declarations

// Constructors
LabelledArraysLabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_create(
    ListLabelledMeasuredArray1DHandle arrays);

// Destructor
void LabelledArraysLabelledMeasuredArray1D_destroy(
    LabelledArraysLabelledMeasuredArray1DHandle handle);

// Methods
ListLabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_arrays(
    LabelledArraysLabelledMeasuredArray1DHandle handle);
ListAcquisitionContextHandle LabelledArraysLabelledMeasuredArray1D_labels(
    LabelledArraysLabelledMeasuredArray1DHandle handle);
bool LabelledArraysLabelledMeasuredArray1D_isControlArrays(
    LabelledArraysLabelledMeasuredArray1DHandle handle);
bool LabelledArraysLabelledMeasuredArray1D_isMeasuredArrays(
    LabelledArraysLabelledMeasuredArray1DHandle handle);
void LabelledArraysLabelledMeasuredArray1D_push_back(
    LabelledArraysLabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle value);
size_t LabelledArraysLabelledMeasuredArray1D_size(
    LabelledArraysLabelledMeasuredArray1DHandle handle);
bool LabelledArraysLabelledMeasuredArray1D_empty(
    LabelledArraysLabelledMeasuredArray1DHandle handle);
void LabelledArraysLabelledMeasuredArray1D_erase_at(
    LabelledArraysLabelledMeasuredArray1DHandle handle, size_t idx);
void LabelledArraysLabelledMeasuredArray1D_clear(
    LabelledArraysLabelledMeasuredArray1DHandle handle);
LabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_at(
    LabelledArraysLabelledMeasuredArray1DHandle handle, size_t idx);
bool LabelledArraysLabelledMeasuredArray1D_contains(
    LabelledArraysLabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle value);
size_t LabelledArraysLabelledMeasuredArray1D_index(
    LabelledArraysLabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle value);
LabelledArraysLabelledMeasuredArray1DHandle
LabelledArraysLabelledMeasuredArray1D_intersection(
    LabelledArraysLabelledMeasuredArray1DHandle handle,
    LabelledArraysLabelledMeasuredArray1DHandle other);
bool LabelledArraysLabelledMeasuredArray1D_equal(
    LabelledArraysLabelledMeasuredArray1DHandle handle,
    LabelledArraysLabelledMeasuredArray1DHandle other);
bool LabelledArraysLabelledMeasuredArray1D_not_equal(
    LabelledArraysLabelledMeasuredArray1DHandle handle,
    LabelledArraysLabelledMeasuredArray1DHandle other);

// Serialization (from Song)
StringHandle      LabelledArraysLabelledMeasuredArray1D_to_json_string(LabelledArraysLabelledMeasuredArray1DHandle handle);
LabelledArraysLabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif