#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/generic/ListLabelledControlArray1D_c_api.h"
#include "falcon-core/generic/ListAcquisitionContext_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* LabelledArraysLabelledControlArray1DHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_create(
    ListLabelledControlArray1DHandle arrays);
// @category:allocation
FALCON_CORE_C_API LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_copy(LabelledArraysLabelledControlArray1DHandle handle);
// @category:deallocation
FALCON_CORE_C_API void LabelledArraysLabelledControlArray1D_destroy(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:read
FALCON_CORE_C_API ListLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_arrays(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:read
FALCON_CORE_C_API ListAcquisitionContextHandle LabelledArraysLabelledControlArray1D_labels(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:read
FALCON_CORE_C_API bool LabelledArraysLabelledControlArray1D_is_control_arrays(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:read
FALCON_CORE_C_API bool LabelledArraysLabelledControlArray1D_is_measured_arrays(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:write
FALCON_CORE_C_API void LabelledArraysLabelledControlArray1D_push_back(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle value);
// @category:read
FALCON_CORE_C_API size_t LabelledArraysLabelledControlArray1D_size(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:read
FALCON_CORE_C_API bool LabelledArraysLabelledControlArray1D_empty(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:write
FALCON_CORE_C_API void LabelledArraysLabelledControlArray1D_erase_at(
    LabelledArraysLabelledControlArray1DHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void LabelledArraysLabelledControlArray1D_clear(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:read
FALCON_CORE_C_API LabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_at(
    LabelledArraysLabelledControlArray1DHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API bool LabelledArraysLabelledControlArray1D_contains(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle value);
// @category:read
FALCON_CORE_C_API size_t LabelledArraysLabelledControlArray1D_index(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle value);
// @category:read
FALCON_CORE_C_API LabelledArraysLabelledControlArray1DHandle
LabelledArraysLabelledControlArray1D_intersection(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledArraysLabelledControlArray1DHandle other);
// @category:read
FALCON_CORE_C_API bool LabelledArraysLabelledControlArray1D_equal(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledArraysLabelledControlArray1DHandle other);
// @category:read
FALCON_CORE_C_API bool LabelledArraysLabelledControlArray1D_not_equal(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledArraysLabelledControlArray1DHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      LabelledArraysLabelledControlArray1D_to_json_string(LabelledArraysLabelledControlArray1DHandle handle);
// @category:allocation
FALCON_CORE_C_API LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif