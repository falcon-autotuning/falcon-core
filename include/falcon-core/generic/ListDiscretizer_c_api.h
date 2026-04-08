#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/math/discrete_spaces/Discretizer_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListDiscretizerHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListDiscretizerHandle ListDiscretizer_create_empty();
// @category:allocation
FALCON_CORE_C_API ListDiscretizerHandle ListDiscretizer_copy(ListDiscretizerHandle handle);

// @category:allocation
FALCON_CORE_C_API ListDiscretizerHandle ListDiscretizer_fill_value(size_t count, DiscretizerHandle value);
// @category:allocation
FALCON_CORE_C_API ListDiscretizerHandle ListDiscretizer_create(DiscretizerHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListDiscretizer_destroy(ListDiscretizerHandle handle);
// @category:write
FALCON_CORE_C_API void ListDiscretizer_push_back(ListDiscretizerHandle handle, DiscretizerHandle value);
// @category:read
FALCON_CORE_C_API size_t ListDiscretizer_size(ListDiscretizerHandle handle);
// @category:read
FALCON_CORE_C_API bool ListDiscretizer_empty(ListDiscretizerHandle handle);
// @category:write
FALCON_CORE_C_API void ListDiscretizer_erase_at(ListDiscretizerHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListDiscretizer_clear(ListDiscretizerHandle handle);
// @category:read
FALCON_CORE_C_API DiscretizerHandle ListDiscretizer_at(ListDiscretizerHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListDiscretizer_items(ListDiscretizerHandle handle, DiscretizerHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListDiscretizer_contains(ListDiscretizerHandle handle, DiscretizerHandle value);
// @category:read
FALCON_CORE_C_API size_t ListDiscretizer_index(ListDiscretizerHandle handle, DiscretizerHandle value);
// @category:read
FALCON_CORE_C_API ListDiscretizerHandle ListDiscretizer_intersection(ListDiscretizerHandle handle, ListDiscretizerHandle other);
// @category:read
FALCON_CORE_C_API bool ListDiscretizer_equal(ListDiscretizerHandle handle, ListDiscretizerHandle other);
// @category:read
FALCON_CORE_C_API bool ListDiscretizer_not_equal(ListDiscretizerHandle handle, ListDiscretizerHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListDiscretizer_to_json_string(ListDiscretizerHandle handle);
// @category:allocation
FALCON_CORE_C_API ListDiscretizerHandle ListDiscretizer_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif