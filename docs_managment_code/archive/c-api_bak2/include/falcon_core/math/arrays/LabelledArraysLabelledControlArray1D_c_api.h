#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListLabelledControlArray1D_c_api.h"
#include "falcon_core/generic/ListAcquisitionContext_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* LabelledArraysLabelledControlArray1DHandle;
// Function declarations

// @category:allocation
LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_create(
    ListLabelledControlArray1DHandle arrays);
// @category:deallocation
void LabelledArraysLabelledControlArray1D_destroy(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: LabelledArraysLabelledControlArray1D_arrays | falcon_core::math::arrays::LabelledArrays::arrays */
/**
 * @brief Returns the internal vector of labelled arrays.
 */
ListLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_arrays(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: LabelledArraysLabelledControlArray1D_labels | falcon_core::math::arrays::LabelledArrays::labels */
/**
 * @brief Returns the labels of all labelled arrays.
 */
ListAcquisitionContextHandle LabelledArraysLabelledControlArray1D_labels(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: LabelledArraysLabelledControlArray1D_is_control_arrays | falcon_core::math::arrays::LabelledArrays::is_control_arrays */
/**
 * @brief Checks if the contents are of control arrays.
 */
bool LabelledArraysLabelledControlArray1D_is_control_arrays(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: LabelledArraysLabelledControlArray1D_is_measured_arrays | falcon_core::math::arrays::LabelledArrays::is_measured_arrays */
/**
 * @brief Checks if the contents are of measured arrays.
 */
bool LabelledArraysLabelledControlArray1D_is_measured_arrays(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:write
void LabelledArraysLabelledControlArray1D_push_back(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle value);
// @category:read
size_t LabelledArraysLabelledControlArray1D_size(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:read
bool LabelledArraysLabelledControlArray1D_empty(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:write
void LabelledArraysLabelledControlArray1D_erase_at(
    LabelledArraysLabelledControlArray1DHandle handle, size_t idx);
// @category:write
void LabelledArraysLabelledControlArray1D_clear(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:read
LabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_at(
    LabelledArraysLabelledControlArray1DHandle handle, size_t idx);
// @category:read
bool LabelledArraysLabelledControlArray1D_contains(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle value);
// @category:read
size_t LabelledArraysLabelledControlArray1D_index(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle value);
// @category:read
LabelledArraysLabelledControlArray1DHandle
LabelledArraysLabelledControlArray1D_intersection(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledArraysLabelledControlArray1DHandle other);
// @category:read
bool LabelledArraysLabelledControlArray1D_equal(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledArraysLabelledControlArray1DHandle other);
// @category:read
bool LabelledArraysLabelledControlArray1D_not_equal(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledArraysLabelledControlArray1DHandle other);

// @category:read
StringHandle      LabelledArraysLabelledControlArray1D_to_json_string(LabelledArraysLabelledControlArray1DHandle handle);
// @category:allocation
LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif