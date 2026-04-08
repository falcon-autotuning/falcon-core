#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/math/arrays/ControlArray1D_c_api.h"
#include "falcon-core/generic/ListControlArray1D_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesControlArray1DHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API AxesControlArray1DHandle AxesControlArray1D_create_empty();
// @category:allocation
FALCON_CORE_C_API AxesControlArray1DHandle AxesControlArray1D_copy(AxesControlArray1DHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesControlArray1DHandle AxesControlArray1D_create(ListControlArray1DHandle data);
// @category:deallocation
FALCON_CORE_C_API void AxesControlArray1D_destroy(AxesControlArray1DHandle handle);
// @category:write
FALCON_CORE_C_API void AxesControlArray1D_push_back(AxesControlArray1DHandle handle, ControlArray1DHandle value);
// @category:read
FALCON_CORE_C_API size_t AxesControlArray1D_size(AxesControlArray1DHandle handle);
// @category:read
FALCON_CORE_C_API bool AxesControlArray1D_empty(AxesControlArray1DHandle handle);
// @category:write
FALCON_CORE_C_API void AxesControlArray1D_erase_at(AxesControlArray1DHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void AxesControlArray1D_clear(AxesControlArray1DHandle handle);
// @category:read
FALCON_CORE_C_API ControlArray1DHandle AxesControlArray1D_at(AxesControlArray1DHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t AxesControlArray1D_items(AxesControlArray1DHandle handle, ControlArray1DHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool AxesControlArray1D_contains(AxesControlArray1DHandle handle, ControlArray1DHandle value);
// @category:read
FALCON_CORE_C_API size_t AxesControlArray1D_index(AxesControlArray1DHandle handle, ControlArray1DHandle value);
// @category:read
FALCON_CORE_C_API AxesControlArray1DHandle AxesControlArray1D_intersection(AxesControlArray1DHandle handle, AxesControlArray1DHandle other);
// @category:read
FALCON_CORE_C_API bool AxesControlArray1D_equal(AxesControlArray1DHandle handle, AxesControlArray1DHandle other);
// @category:read
FALCON_CORE_C_API bool AxesControlArray1D_not_equal(AxesControlArray1DHandle handle, AxesControlArray1DHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      AxesControlArray1D_to_json_string(AxesControlArray1DHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesControlArray1DHandle AxesControlArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif