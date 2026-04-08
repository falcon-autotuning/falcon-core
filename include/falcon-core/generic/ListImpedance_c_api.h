#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/physics/device_structures/Impedance_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListImpedanceHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListImpedanceHandle ListImpedance_create_empty();
// @category:allocation
FALCON_CORE_C_API ListImpedanceHandle ListImpedance_copy(ListImpedanceHandle handle);

// @category:allocation
FALCON_CORE_C_API ListImpedanceHandle ListImpedance_fill_value(size_t count, ImpedanceHandle value);
// @category:allocation
FALCON_CORE_C_API ListImpedanceHandle ListImpedance_create(ImpedanceHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListImpedance_destroy(ListImpedanceHandle handle);
// @category:write
FALCON_CORE_C_API void ListImpedance_push_back(ListImpedanceHandle handle, ImpedanceHandle value);
// @category:read
FALCON_CORE_C_API size_t ListImpedance_size(ListImpedanceHandle handle);
// @category:read
FALCON_CORE_C_API bool ListImpedance_empty(ListImpedanceHandle handle);
// @category:write
FALCON_CORE_C_API void ListImpedance_erase_at(ListImpedanceHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListImpedance_clear(ListImpedanceHandle handle);
// @category:read
FALCON_CORE_C_API ImpedanceHandle ListImpedance_at(ListImpedanceHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListImpedance_items(ListImpedanceHandle handle, ImpedanceHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListImpedance_contains(ListImpedanceHandle handle, ImpedanceHandle value);
// @category:read
FALCON_CORE_C_API size_t ListImpedance_index(ListImpedanceHandle handle, ImpedanceHandle value);
// @category:read
FALCON_CORE_C_API ListImpedanceHandle ListImpedance_intersection(ListImpedanceHandle handle, ListImpedanceHandle other);
// @category:read
FALCON_CORE_C_API bool ListImpedance_equal(ListImpedanceHandle handle, ListImpedanceHandle other);
// @category:read
FALCON_CORE_C_API bool ListImpedance_not_equal(ListImpedanceHandle handle, ListImpedanceHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListImpedance_to_json_string(ListImpedanceHandle handle);
// @category:allocation
FALCON_CORE_C_API ListImpedanceHandle ListImpedance_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif