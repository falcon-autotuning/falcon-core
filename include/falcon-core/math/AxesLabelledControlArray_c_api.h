#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/math/arrays/LabelledControlArray_c_api.h"
#include "falcon-core/generic/ListLabelledControlArray_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesLabelledControlArrayHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API AxesLabelledControlArrayHandle AxesLabelledControlArray_create_empty();
// @category:allocation
FALCON_CORE_C_API AxesLabelledControlArrayHandle AxesLabelledControlArray_copy(AxesLabelledControlArrayHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesLabelledControlArrayHandle AxesLabelledControlArray_create(ListLabelledControlArrayHandle data);
// @category:deallocation
FALCON_CORE_C_API void AxesLabelledControlArray_destroy(AxesLabelledControlArrayHandle handle);
// @category:write
FALCON_CORE_C_API void AxesLabelledControlArray_push_back(AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle value);
// @category:read
FALCON_CORE_C_API size_t AxesLabelledControlArray_size(AxesLabelledControlArrayHandle handle);
// @category:read
FALCON_CORE_C_API bool AxesLabelledControlArray_empty(AxesLabelledControlArrayHandle handle);
// @category:write
FALCON_CORE_C_API void AxesLabelledControlArray_erase_at(AxesLabelledControlArrayHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void AxesLabelledControlArray_clear(AxesLabelledControlArrayHandle handle);
// @category:read
FALCON_CORE_C_API LabelledControlArrayHandle AxesLabelledControlArray_at(AxesLabelledControlArrayHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t AxesLabelledControlArray_items(AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool AxesLabelledControlArray_contains(AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle value);
// @category:read
FALCON_CORE_C_API size_t AxesLabelledControlArray_index(AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle value);
// @category:read
FALCON_CORE_C_API AxesLabelledControlArrayHandle AxesLabelledControlArray_intersection(AxesLabelledControlArrayHandle handle, AxesLabelledControlArrayHandle other);
// @category:read
FALCON_CORE_C_API bool AxesLabelledControlArray_equal(AxesLabelledControlArrayHandle handle, AxesLabelledControlArrayHandle other);
// @category:read
FALCON_CORE_C_API bool AxesLabelledControlArray_not_equal(AxesLabelledControlArrayHandle handle, AxesLabelledControlArrayHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      AxesLabelledControlArray_to_json_string(AxesLabelledControlArrayHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesLabelledControlArrayHandle AxesLabelledControlArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif