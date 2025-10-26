#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListLabelledControlArray1D_c_api.h"
#include "falcon_core/generic/ListAcquisitionContext_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* LabelledArraysLabelledControlArray1DHandle;
// Function declarations

// Constructors
LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_create(
    ListLabelledControlArray1DHandle arrays);

// Destructor
void LabelledArraysLabelledControlArray1D_destroy(
    LabelledArraysLabelledControlArray1DHandle handle);

// Methods
ListLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_arrays(
    LabelledArraysLabelledControlArray1DHandle handle);
ListAcquisitionContextHandle LabelledArraysLabelledControlArray1D_labels(
    LabelledArraysLabelledControlArray1DHandle handle);
bool LabelledArraysLabelledControlArray1D_isControlArrays(
    LabelledArraysLabelledControlArray1DHandle handle);
bool LabelledArraysLabelledControlArray1D_isMeasuredArrays(
    LabelledArraysLabelledControlArray1DHandle handle);
void LabelledArraysLabelledControlArray1D_push_back(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle value);
size_t LabelledArraysLabelledControlArray1D_size(
    LabelledArraysLabelledControlArray1DHandle handle);
bool LabelledArraysLabelledControlArray1D_empty(
    LabelledArraysLabelledControlArray1DHandle handle);
void LabelledArraysLabelledControlArray1D_erase_at(
    LabelledArraysLabelledControlArray1DHandle handle, size_t idx);
void LabelledArraysLabelledControlArray1D_clear(
    LabelledArraysLabelledControlArray1DHandle handle);
LabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_at(
    LabelledArraysLabelledControlArray1DHandle handle, size_t idx);
bool LabelledArraysLabelledControlArray1D_contains(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle value);
size_t LabelledArraysLabelledControlArray1D_index(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle value);
LabelledArraysLabelledControlArray1DHandle
LabelledArraysLabelledControlArray1D_intersection(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledArraysLabelledControlArray1DHandle other);
bool LabelledArraysLabelledControlArray1D_equal(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledArraysLabelledControlArray1DHandle other);
bool LabelledArraysLabelledControlArray1D_not_equal(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledArraysLabelledControlArray1DHandle other);

// Serialization (from Song)
StringHandle      LabelledArraysLabelledControlArray1D_to_json_string(LabelledArraysLabelledControlArray1DHandle handle);
LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif