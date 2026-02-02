#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/discrete_spaces/Discretizer_c_api.h"
#include "falcon_core/generic/ListDiscretizer_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesDiscretizerHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API AxesDiscretizerHandle AxesDiscretizer_create_empty();
// @category:allocation
FALCON_CORE_C_API AxesDiscretizerHandle AxesDiscretizer_copy(AxesDiscretizerHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesDiscretizerHandle AxesDiscretizer_create(ListDiscretizerHandle data);
// @category:deallocation
FALCON_CORE_C_API void AxesDiscretizer_destroy(AxesDiscretizerHandle handle);
// @category:write
FALCON_CORE_C_API void AxesDiscretizer_push_back(AxesDiscretizerHandle handle, DiscretizerHandle value);
// @category:read
FALCON_CORE_C_API size_t AxesDiscretizer_size(AxesDiscretizerHandle handle);
// @category:read
FALCON_CORE_C_API bool AxesDiscretizer_empty(AxesDiscretizerHandle handle);
// @category:write
FALCON_CORE_C_API void AxesDiscretizer_erase_at(AxesDiscretizerHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void AxesDiscretizer_clear(AxesDiscretizerHandle handle);
// @category:read
FALCON_CORE_C_API DiscretizerHandle AxesDiscretizer_at(AxesDiscretizerHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t AxesDiscretizer_items(AxesDiscretizerHandle handle, DiscretizerHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool AxesDiscretizer_contains(AxesDiscretizerHandle handle, DiscretizerHandle value);
// @category:read
FALCON_CORE_C_API size_t AxesDiscretizer_index(AxesDiscretizerHandle handle, DiscretizerHandle value);
// @category:read
FALCON_CORE_C_API AxesDiscretizerHandle AxesDiscretizer_intersection(AxesDiscretizerHandle handle, AxesDiscretizerHandle other);
// @category:read
FALCON_CORE_C_API bool AxesDiscretizer_equal(AxesDiscretizerHandle handle, AxesDiscretizerHandle other);
// @category:read
FALCON_CORE_C_API bool AxesDiscretizer_not_equal(AxesDiscretizerHandle handle, AxesDiscretizerHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      AxesDiscretizer_to_json_string(AxesDiscretizerHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesDiscretizerHandle AxesDiscretizer_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif