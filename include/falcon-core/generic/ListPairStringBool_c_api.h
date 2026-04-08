#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/generic/PairStringBool_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairStringBoolHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListPairStringBoolHandle ListPairStringBool_create_empty();
// @category:allocation
FALCON_CORE_C_API ListPairStringBoolHandle ListPairStringBool_copy(ListPairStringBoolHandle handle);

// @category:allocation
FALCON_CORE_C_API ListPairStringBoolHandle ListPairStringBool_fill_value(size_t count, PairStringBoolHandle value);
// @category:allocation
FALCON_CORE_C_API ListPairStringBoolHandle ListPairStringBool_create(PairStringBoolHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListPairStringBool_destroy(ListPairStringBoolHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairStringBool_push_back(ListPairStringBoolHandle handle, PairStringBoolHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairStringBool_size(ListPairStringBoolHandle handle);
// @category:read
FALCON_CORE_C_API bool ListPairStringBool_empty(ListPairStringBoolHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairStringBool_erase_at(ListPairStringBoolHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListPairStringBool_clear(ListPairStringBoolHandle handle);
// @category:read
FALCON_CORE_C_API PairStringBoolHandle ListPairStringBool_at(ListPairStringBoolHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListPairStringBool_items(ListPairStringBoolHandle handle, PairStringBoolHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListPairStringBool_contains(ListPairStringBoolHandle handle, PairStringBoolHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairStringBool_index(ListPairStringBoolHandle handle, PairStringBoolHandle value);
// @category:read
FALCON_CORE_C_API ListPairStringBoolHandle ListPairStringBool_intersection(ListPairStringBoolHandle handle, ListPairStringBoolHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairStringBool_equal(ListPairStringBoolHandle handle, ListPairStringBoolHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairStringBool_not_equal(ListPairStringBoolHandle handle, ListPairStringBoolHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListPairStringBool_to_json_string(ListPairStringBoolHandle handle);
// @category:allocation
FALCON_CORE_C_API ListPairStringBoolHandle ListPairStringBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif