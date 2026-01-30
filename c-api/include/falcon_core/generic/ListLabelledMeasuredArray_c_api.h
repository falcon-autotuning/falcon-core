#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/LabelledMeasuredArray_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListLabelledMeasuredArrayHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_create_empty();
// @category:allocation
FALCON_CORE_C_API ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_copy(ListLabelledMeasuredArrayHandle handle);

// @category:allocation
FALCON_CORE_C_API ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_fill_value(size_t count, LabelledMeasuredArrayHandle value);
// @category:allocation
FALCON_CORE_C_API ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_create(LabelledMeasuredArrayHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListLabelledMeasuredArray_destroy(ListLabelledMeasuredArrayHandle handle);
// @category:write
FALCON_CORE_C_API void ListLabelledMeasuredArray_push_back(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value);
// @category:read
FALCON_CORE_C_API size_t ListLabelledMeasuredArray_size(ListLabelledMeasuredArrayHandle handle);
// @category:read
FALCON_CORE_C_API bool ListLabelledMeasuredArray_empty(ListLabelledMeasuredArrayHandle handle);
// @category:write
FALCON_CORE_C_API void ListLabelledMeasuredArray_erase_at(ListLabelledMeasuredArrayHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListLabelledMeasuredArray_clear(ListLabelledMeasuredArrayHandle handle);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArrayHandle ListLabelledMeasuredArray_at(ListLabelledMeasuredArrayHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListLabelledMeasuredArray_items(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListLabelledMeasuredArray_contains(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value);
// @category:read
FALCON_CORE_C_API size_t ListLabelledMeasuredArray_index(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value);
// @category:read
FALCON_CORE_C_API ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_intersection(ListLabelledMeasuredArrayHandle handle, ListLabelledMeasuredArrayHandle other);
// @category:read
FALCON_CORE_C_API bool ListLabelledMeasuredArray_equal(ListLabelledMeasuredArrayHandle handle, ListLabelledMeasuredArrayHandle other);
// @category:read
FALCON_CORE_C_API bool ListLabelledMeasuredArray_not_equal(ListLabelledMeasuredArrayHandle handle, ListLabelledMeasuredArrayHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListLabelledMeasuredArray_to_json_string(ListLabelledMeasuredArrayHandle handle);
// @category:allocation
FALCON_CORE_C_API ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif