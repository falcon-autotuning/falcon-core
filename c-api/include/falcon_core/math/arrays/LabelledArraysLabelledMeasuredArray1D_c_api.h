#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListLabelledMeasuredArray1D_c_api.h"
#include "falcon_core/generic/ListAcquisitionContext_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* LabelledArraysLabelledMeasuredArray1DHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API LabelledArraysLabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_create(
    ListLabelledMeasuredArray1DHandle arrays);
// @category:allocation
FALCON_CORE_C_API LabelledArraysLabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_copy(LabelledArraysLabelledMeasuredArray1DHandle handle);
// @category:deallocation
FALCON_CORE_C_API void LabelledArraysLabelledMeasuredArray1D_destroy(
    LabelledArraysLabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API ListLabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_arrays(
    LabelledArraysLabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API ListAcquisitionContextHandle LabelledArraysLabelledMeasuredArray1D_labels(
    LabelledArraysLabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API bool LabelledArraysLabelledMeasuredArray1D_is_control_arrays(
    LabelledArraysLabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API bool LabelledArraysLabelledMeasuredArray1D_is_measured_arrays(
    LabelledArraysLabelledMeasuredArray1DHandle handle);
// @category:write
FALCON_CORE_C_API void LabelledArraysLabelledMeasuredArray1D_push_back(
    LabelledArraysLabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle value);
// @category:read
FALCON_CORE_C_API size_t LabelledArraysLabelledMeasuredArray1D_size(
    LabelledArraysLabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API bool LabelledArraysLabelledMeasuredArray1D_empty(
    LabelledArraysLabelledMeasuredArray1DHandle handle);
// @category:write
FALCON_CORE_C_API void LabelledArraysLabelledMeasuredArray1D_erase_at(
    LabelledArraysLabelledMeasuredArray1DHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void LabelledArraysLabelledMeasuredArray1D_clear(
    LabelledArraysLabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_at(
    LabelledArraysLabelledMeasuredArray1DHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API bool LabelledArraysLabelledMeasuredArray1D_contains(
    LabelledArraysLabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle value);
// @category:read
FALCON_CORE_C_API size_t LabelledArraysLabelledMeasuredArray1D_index(
    LabelledArraysLabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle value);
// @category:read
FALCON_CORE_C_API LabelledArraysLabelledMeasuredArray1DHandle
LabelledArraysLabelledMeasuredArray1D_intersection(
    LabelledArraysLabelledMeasuredArray1DHandle handle,
    LabelledArraysLabelledMeasuredArray1DHandle other);
// @category:read
FALCON_CORE_C_API bool LabelledArraysLabelledMeasuredArray1D_equal(
    LabelledArraysLabelledMeasuredArray1DHandle handle,
    LabelledArraysLabelledMeasuredArray1DHandle other);
// @category:read
FALCON_CORE_C_API bool LabelledArraysLabelledMeasuredArray1D_not_equal(
    LabelledArraysLabelledMeasuredArray1DHandle handle,
    LabelledArraysLabelledMeasuredArray1DHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      LabelledArraysLabelledMeasuredArray1D_to_json_string(LabelledArraysLabelledMeasuredArray1DHandle handle);
// @category:allocation
FALCON_CORE_C_API LabelledArraysLabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif