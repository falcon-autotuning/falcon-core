#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListLabelledControlArray_c_api.h"
#include "falcon_core/generic/ListAcquisitionContext_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* LabelledArraysLabelledControlArrayHandle;
// Function declarations

// Constructors
LabelledArraysLabelledControlArrayHandle LabelledArraysLabelledControlArray_create(
    ListLabelledControlArrayHandle arrays);

// Destructor
void LabelledArraysLabelledControlArray_destroy(
    LabelledArraysLabelledControlArrayHandle handle);

// Methods
ListLabelledControlArrayHandle LabelledArraysLabelledControlArray_arrays(
    LabelledArraysLabelledControlArrayHandle handle);
ListAcquisitionContextHandle LabelledArraysLabelledControlArray_labels(
    LabelledArraysLabelledControlArrayHandle handle);
bool LabelledArraysLabelledControlArray_isControlArrays(
    LabelledArraysLabelledControlArrayHandle handle);
bool LabelledArraysLabelledControlArray_isMeasuredArrays(
    LabelledArraysLabelledControlArrayHandle handle);
void LabelledArraysLabelledControlArray_push_back(
    LabelledArraysLabelledControlArrayHandle handle,
    LabelledControlArrayHandle value);
size_t LabelledArraysLabelledControlArray_size(
    LabelledArraysLabelledControlArrayHandle handle);
bool LabelledArraysLabelledControlArray_empty(
    LabelledArraysLabelledControlArrayHandle handle);
void LabelledArraysLabelledControlArray_erase_at(
    LabelledArraysLabelledControlArrayHandle handle, size_t idx);
void LabelledArraysLabelledControlArray_clear(
    LabelledArraysLabelledControlArrayHandle handle);
LabelledControlArrayHandle LabelledArraysLabelledControlArray_at(
    LabelledArraysLabelledControlArrayHandle handle, size_t idx);
bool LabelledArraysLabelledControlArray_contains(
    LabelledArraysLabelledControlArrayHandle handle,
    LabelledControlArrayHandle value);
size_t LabelledArraysLabelledControlArray_index(
    LabelledArraysLabelledControlArrayHandle handle,
    LabelledControlArrayHandle value);
LabelledArraysLabelledControlArrayHandle
LabelledArraysLabelledControlArray_intersection(
    LabelledArraysLabelledControlArrayHandle handle,
    LabelledArraysLabelledControlArrayHandle other);
bool LabelledArraysLabelledControlArray_equal(
    LabelledArraysLabelledControlArrayHandle handle,
    LabelledArraysLabelledControlArrayHandle other);
bool LabelledArraysLabelledControlArray_not_equal(
    LabelledArraysLabelledControlArrayHandle handle,
    LabelledArraysLabelledControlArrayHandle other);

// Serialization (from Song)
StringHandle      LabelledArraysLabelledControlArray_to_json_string(LabelledArraysLabelledControlArrayHandle handle);
LabelledArraysLabelledControlArrayHandle LabelledArraysLabelledControlArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif