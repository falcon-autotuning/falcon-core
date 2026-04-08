#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/generic/PairIntFloat_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairIntFloatHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListPairIntFloatHandle ListPairIntFloat_create_empty();
// @category:allocation
FALCON_CORE_C_API ListPairIntFloatHandle ListPairIntFloat_copy(ListPairIntFloatHandle handle);

// @category:allocation
FALCON_CORE_C_API ListPairIntFloatHandle ListPairIntFloat_fill_value(size_t count, PairIntFloatHandle value);
// @category:allocation
FALCON_CORE_C_API ListPairIntFloatHandle ListPairIntFloat_create(PairIntFloatHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListPairIntFloat_destroy(ListPairIntFloatHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairIntFloat_push_back(ListPairIntFloatHandle handle, PairIntFloatHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairIntFloat_size(ListPairIntFloatHandle handle);
// @category:read
FALCON_CORE_C_API bool ListPairIntFloat_empty(ListPairIntFloatHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairIntFloat_erase_at(ListPairIntFloatHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListPairIntFloat_clear(ListPairIntFloatHandle handle);
// @category:read
FALCON_CORE_C_API PairIntFloatHandle ListPairIntFloat_at(ListPairIntFloatHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListPairIntFloat_items(ListPairIntFloatHandle handle, PairIntFloatHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListPairIntFloat_contains(ListPairIntFloatHandle handle, PairIntFloatHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairIntFloat_index(ListPairIntFloatHandle handle, PairIntFloatHandle value);
// @category:read
FALCON_CORE_C_API ListPairIntFloatHandle ListPairIntFloat_intersection(ListPairIntFloatHandle handle, ListPairIntFloatHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairIntFloat_equal(ListPairIntFloatHandle handle, ListPairIntFloatHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairIntFloat_not_equal(ListPairIntFloatHandle handle, ListPairIntFloatHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListPairIntFloat_to_json_string(ListPairIntFloatHandle handle);
// @category:allocation
FALCON_CORE_C_API ListPairIntFloatHandle ListPairIntFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif