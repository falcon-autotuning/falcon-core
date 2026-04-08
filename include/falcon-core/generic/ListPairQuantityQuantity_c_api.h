#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/generic/PairQuantityQuantity_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairQuantityQuantityHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListPairQuantityQuantityHandle ListPairQuantityQuantity_create_empty();
// @category:allocation
FALCON_CORE_C_API ListPairQuantityQuantityHandle ListPairQuantityQuantity_copy(ListPairQuantityQuantityHandle handle);

// @category:allocation
FALCON_CORE_C_API ListPairQuantityQuantityHandle ListPairQuantityQuantity_fill_value(size_t count, PairQuantityQuantityHandle value);
// @category:allocation
FALCON_CORE_C_API ListPairQuantityQuantityHandle ListPairQuantityQuantity_create(PairQuantityQuantityHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListPairQuantityQuantity_destroy(ListPairQuantityQuantityHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairQuantityQuantity_push_back(ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairQuantityQuantity_size(ListPairQuantityQuantityHandle handle);
// @category:read
FALCON_CORE_C_API bool ListPairQuantityQuantity_empty(ListPairQuantityQuantityHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairQuantityQuantity_erase_at(ListPairQuantityQuantityHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListPairQuantityQuantity_clear(ListPairQuantityQuantityHandle handle);
// @category:read
FALCON_CORE_C_API PairQuantityQuantityHandle ListPairQuantityQuantity_at(ListPairQuantityQuantityHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListPairQuantityQuantity_items(ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListPairQuantityQuantity_contains(ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairQuantityQuantity_index(ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle value);
// @category:read
FALCON_CORE_C_API ListPairQuantityQuantityHandle ListPairQuantityQuantity_intersection(ListPairQuantityQuantityHandle handle, ListPairQuantityQuantityHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairQuantityQuantity_equal(ListPairQuantityQuantityHandle handle, ListPairQuantityQuantityHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairQuantityQuantity_not_equal(ListPairQuantityQuantityHandle handle, ListPairQuantityQuantityHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListPairQuantityQuantity_to_json_string(ListPairQuantityQuantityHandle handle);
// @category:allocation
FALCON_CORE_C_API ListPairQuantityQuantityHandle ListPairQuantityQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif