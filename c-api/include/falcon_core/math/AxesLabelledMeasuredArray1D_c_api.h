#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/LabelledMeasuredArray1D_c_api.h"
#include "falcon_core/generic/ListLabelledMeasuredArray1D_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesLabelledMeasuredArray1DHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_create_empty();
// @category:allocation
FALCON_CORE_C_API AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_copy(AxesLabelledMeasuredArray1DHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_create(ListLabelledMeasuredArray1DHandle data);
// @category:deallocation
FALCON_CORE_C_API void AxesLabelledMeasuredArray1D_destroy(AxesLabelledMeasuredArray1DHandle handle);
// @category:write
FALCON_CORE_C_API void AxesLabelledMeasuredArray1D_push_back(AxesLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value);
// @category:read
FALCON_CORE_C_API size_t AxesLabelledMeasuredArray1D_size(AxesLabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API bool AxesLabelledMeasuredArray1D_empty(AxesLabelledMeasuredArray1DHandle handle);
// @category:write
FALCON_CORE_C_API void AxesLabelledMeasuredArray1D_erase_at(AxesLabelledMeasuredArray1DHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void AxesLabelledMeasuredArray1D_clear(AxesLabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_at(AxesLabelledMeasuredArray1DHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t AxesLabelledMeasuredArray1D_items(AxesLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool AxesLabelledMeasuredArray1D_contains(AxesLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value);
// @category:read
FALCON_CORE_C_API size_t AxesLabelledMeasuredArray1D_index(AxesLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value);
// @category:read
FALCON_CORE_C_API AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_intersection(AxesLabelledMeasuredArray1DHandle handle, AxesLabelledMeasuredArray1DHandle other);
// @category:read
FALCON_CORE_C_API bool AxesLabelledMeasuredArray1D_equal(AxesLabelledMeasuredArray1DHandle handle, AxesLabelledMeasuredArray1DHandle other);
// @category:read
FALCON_CORE_C_API bool AxesLabelledMeasuredArray1D_not_equal(AxesLabelledMeasuredArray1DHandle handle, AxesLabelledMeasuredArray1DHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      AxesLabelledMeasuredArray1D_to_json_string(AxesLabelledMeasuredArray1DHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif