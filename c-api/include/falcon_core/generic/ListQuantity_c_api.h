#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/Quantity_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListQuantityHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListQuantityHandle ListQuantity_create_empty();
// @category:allocation
FALCON_CORE_C_API ListQuantityHandle ListQuantity_copy(ListQuantityHandle handle);

// @category:allocation
FALCON_CORE_C_API ListQuantityHandle ListQuantity_fill_value(size_t count, QuantityHandle value);
// @category:allocation
FALCON_CORE_C_API ListQuantityHandle ListQuantity_create(QuantityHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListQuantity_destroy(ListQuantityHandle handle);
// @category:write
FALCON_CORE_C_API void ListQuantity_push_back(ListQuantityHandle handle, QuantityHandle value);
// @category:read
FALCON_CORE_C_API size_t ListQuantity_size(ListQuantityHandle handle);
// @category:read
FALCON_CORE_C_API bool ListQuantity_empty(ListQuantityHandle handle);
// @category:write
FALCON_CORE_C_API void ListQuantity_erase_at(ListQuantityHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListQuantity_clear(ListQuantityHandle handle);
// @category:read
FALCON_CORE_C_API QuantityHandle ListQuantity_at(ListQuantityHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListQuantity_items(ListQuantityHandle handle, QuantityHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListQuantity_contains(ListQuantityHandle handle, QuantityHandle value);
// @category:read
FALCON_CORE_C_API size_t ListQuantity_index(ListQuantityHandle handle, QuantityHandle value);
// @category:read
FALCON_CORE_C_API ListQuantityHandle ListQuantity_intersection(ListQuantityHandle handle, ListQuantityHandle other);
// @category:read
FALCON_CORE_C_API bool ListQuantity_equal(ListQuantityHandle handle, ListQuantityHandle other);
// @category:read
FALCON_CORE_C_API bool ListQuantity_not_equal(ListQuantityHandle handle, ListQuantityHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListQuantity_to_json_string(ListQuantityHandle handle);
// @category:allocation
FALCON_CORE_C_API ListQuantityHandle ListQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif