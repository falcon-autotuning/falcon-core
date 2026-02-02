#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/LabelledMeasuredArray_c_api.h"
#include "falcon_core/generic/ListLabelledMeasuredArray_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesLabelledMeasuredArrayHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_create_empty();
// @category:allocation
FALCON_CORE_C_API AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_copy(AxesLabelledMeasuredArrayHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_create(ListLabelledMeasuredArrayHandle data);
// @category:deallocation
FALCON_CORE_C_API void AxesLabelledMeasuredArray_destroy(AxesLabelledMeasuredArrayHandle handle);
// @category:write
FALCON_CORE_C_API void AxesLabelledMeasuredArray_push_back(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value);
// @category:read
FALCON_CORE_C_API size_t AxesLabelledMeasuredArray_size(AxesLabelledMeasuredArrayHandle handle);
// @category:read
FALCON_CORE_C_API bool AxesLabelledMeasuredArray_empty(AxesLabelledMeasuredArrayHandle handle);
// @category:write
FALCON_CORE_C_API void AxesLabelledMeasuredArray_erase_at(AxesLabelledMeasuredArrayHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void AxesLabelledMeasuredArray_clear(AxesLabelledMeasuredArrayHandle handle);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArrayHandle AxesLabelledMeasuredArray_at(AxesLabelledMeasuredArrayHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t AxesLabelledMeasuredArray_items(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool AxesLabelledMeasuredArray_contains(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value);
// @category:read
FALCON_CORE_C_API size_t AxesLabelledMeasuredArray_index(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value);
// @category:read
FALCON_CORE_C_API AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_intersection(AxesLabelledMeasuredArrayHandle handle, AxesLabelledMeasuredArrayHandle other);
// @category:read
FALCON_CORE_C_API bool AxesLabelledMeasuredArray_equal(AxesLabelledMeasuredArrayHandle handle, AxesLabelledMeasuredArrayHandle other);
// @category:read
FALCON_CORE_C_API bool AxesLabelledMeasuredArray_not_equal(AxesLabelledMeasuredArrayHandle handle, AxesLabelledMeasuredArrayHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      AxesLabelledMeasuredArray_to_json_string(AxesLabelledMeasuredArrayHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif