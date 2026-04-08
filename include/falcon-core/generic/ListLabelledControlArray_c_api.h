#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/math/arrays/LabelledControlArray_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListLabelledControlArrayHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListLabelledControlArrayHandle ListLabelledControlArray_create_empty();
// @category:allocation
FALCON_CORE_C_API ListLabelledControlArrayHandle ListLabelledControlArray_copy(ListLabelledControlArrayHandle handle);

// @category:allocation
FALCON_CORE_C_API ListLabelledControlArrayHandle ListLabelledControlArray_fill_value(size_t count, LabelledControlArrayHandle value);
// @category:allocation
FALCON_CORE_C_API ListLabelledControlArrayHandle ListLabelledControlArray_create(LabelledControlArrayHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListLabelledControlArray_destroy(ListLabelledControlArrayHandle handle);
// @category:write
FALCON_CORE_C_API void ListLabelledControlArray_push_back(ListLabelledControlArrayHandle handle, LabelledControlArrayHandle value);
// @category:read
FALCON_CORE_C_API size_t ListLabelledControlArray_size(ListLabelledControlArrayHandle handle);
// @category:read
FALCON_CORE_C_API bool ListLabelledControlArray_empty(ListLabelledControlArrayHandle handle);
// @category:write
FALCON_CORE_C_API void ListLabelledControlArray_erase_at(ListLabelledControlArrayHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListLabelledControlArray_clear(ListLabelledControlArrayHandle handle);
// @category:read
FALCON_CORE_C_API LabelledControlArrayHandle ListLabelledControlArray_at(ListLabelledControlArrayHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListLabelledControlArray_items(ListLabelledControlArrayHandle handle, LabelledControlArrayHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListLabelledControlArray_contains(ListLabelledControlArrayHandle handle, LabelledControlArrayHandle value);
// @category:read
FALCON_CORE_C_API size_t ListLabelledControlArray_index(ListLabelledControlArrayHandle handle, LabelledControlArrayHandle value);
// @category:read
FALCON_CORE_C_API ListLabelledControlArrayHandle ListLabelledControlArray_intersection(ListLabelledControlArrayHandle handle, ListLabelledControlArrayHandle other);
// @category:read
FALCON_CORE_C_API bool ListLabelledControlArray_equal(ListLabelledControlArrayHandle handle, ListLabelledControlArrayHandle other);
// @category:read
FALCON_CORE_C_API bool ListLabelledControlArray_not_equal(ListLabelledControlArrayHandle handle, ListLabelledControlArrayHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListLabelledControlArray_to_json_string(ListLabelledControlArrayHandle handle);
// @category:allocation
FALCON_CORE_C_API ListLabelledControlArrayHandle ListLabelledControlArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif