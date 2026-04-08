#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/generic/ListLabelledMeasuredArray_c_api.h"
#include "falcon-core/generic/ListAcquisitionContext_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* LabelledArraysLabelledMeasuredArrayHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API LabelledArraysLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_create(
    ListLabelledMeasuredArrayHandle arrays);
// @category:allocation
FALCON_CORE_C_API LabelledArraysLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_copy(LabelledArraysLabelledMeasuredArrayHandle handle);
// @category:deallocation
FALCON_CORE_C_API void LabelledArraysLabelledMeasuredArray_destroy(
    LabelledArraysLabelledMeasuredArrayHandle handle);
// @category:read
FALCON_CORE_C_API ListLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_arrays(
    LabelledArraysLabelledMeasuredArrayHandle handle);
// @category:read
FALCON_CORE_C_API ListAcquisitionContextHandle LabelledArraysLabelledMeasuredArray_labels(
    LabelledArraysLabelledMeasuredArrayHandle handle);
// @category:read
FALCON_CORE_C_API bool LabelledArraysLabelledMeasuredArray_is_control_arrays(
    LabelledArraysLabelledMeasuredArrayHandle handle);
// @category:read
FALCON_CORE_C_API bool LabelledArraysLabelledMeasuredArray_is_measured_arrays(
    LabelledArraysLabelledMeasuredArrayHandle handle);
// @category:write
FALCON_CORE_C_API void LabelledArraysLabelledMeasuredArray_push_back(
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle value);
// @category:read
FALCON_CORE_C_API size_t LabelledArraysLabelledMeasuredArray_size(
    LabelledArraysLabelledMeasuredArrayHandle handle);
// @category:read
FALCON_CORE_C_API bool LabelledArraysLabelledMeasuredArray_empty(
    LabelledArraysLabelledMeasuredArrayHandle handle);
// @category:write
FALCON_CORE_C_API void LabelledArraysLabelledMeasuredArray_erase_at(
    LabelledArraysLabelledMeasuredArrayHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void LabelledArraysLabelledMeasuredArray_clear(
    LabelledArraysLabelledMeasuredArrayHandle handle);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_at(
    LabelledArraysLabelledMeasuredArrayHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API bool LabelledArraysLabelledMeasuredArray_contains(
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle value);
// @category:read
FALCON_CORE_C_API size_t LabelledArraysLabelledMeasuredArray_index(
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle value);
// @category:read
FALCON_CORE_C_API LabelledArraysLabelledMeasuredArrayHandle
LabelledArraysLabelledMeasuredArray_intersection(
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledArraysLabelledMeasuredArrayHandle other);
// @category:read
FALCON_CORE_C_API bool LabelledArraysLabelledMeasuredArray_equal(
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledArraysLabelledMeasuredArrayHandle other);
// @category:read
FALCON_CORE_C_API bool LabelledArraysLabelledMeasuredArray_not_equal(
    LabelledArraysLabelledMeasuredArrayHandle handle,
    LabelledArraysLabelledMeasuredArrayHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      LabelledArraysLabelledMeasuredArray_to_json_string(LabelledArraysLabelledMeasuredArrayHandle handle);
// @category:allocation
FALCON_CORE_C_API LabelledArraysLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif