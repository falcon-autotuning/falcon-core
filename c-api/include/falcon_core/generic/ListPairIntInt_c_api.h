#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairIntInt_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairIntIntHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListPairIntIntHandle ListPairIntInt_create_empty();
// @category:allocation
FALCON_CORE_C_API ListPairIntIntHandle ListPairIntInt_copy(ListPairIntIntHandle handle);

// @category:allocation
FALCON_CORE_C_API ListPairIntIntHandle ListPairIntInt_fill_value(size_t count, PairIntIntHandle value);
// @category:allocation
FALCON_CORE_C_API ListPairIntIntHandle ListPairIntInt_create(PairIntIntHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListPairIntInt_destroy(ListPairIntIntHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairIntInt_push_back(ListPairIntIntHandle handle, PairIntIntHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairIntInt_size(ListPairIntIntHandle handle);
// @category:read
FALCON_CORE_C_API bool ListPairIntInt_empty(ListPairIntIntHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairIntInt_erase_at(ListPairIntIntHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListPairIntInt_clear(ListPairIntIntHandle handle);
// @category:read
FALCON_CORE_C_API PairIntIntHandle ListPairIntInt_at(ListPairIntIntHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListPairIntInt_items(ListPairIntIntHandle handle, PairIntIntHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListPairIntInt_contains(ListPairIntIntHandle handle, PairIntIntHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairIntInt_index(ListPairIntIntHandle handle, PairIntIntHandle value);
// @category:read
FALCON_CORE_C_API ListPairIntIntHandle ListPairIntInt_intersection(ListPairIntIntHandle handle, ListPairIntIntHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairIntInt_equal(ListPairIntIntHandle handle, ListPairIntIntHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairIntInt_not_equal(ListPairIntIntHandle handle, ListPairIntIntHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListPairIntInt_to_json_string(ListPairIntIntHandle handle);
// @category:allocation
FALCON_CORE_C_API ListPairIntIntHandle ListPairIntInt_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif