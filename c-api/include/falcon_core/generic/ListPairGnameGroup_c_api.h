#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairGnameGroup_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairGnameGroupHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListPairGnameGroupHandle ListPairGnameGroup_create_empty();
// @category:allocation
FALCON_CORE_C_API ListPairGnameGroupHandle ListPairGnameGroup_copy(ListPairGnameGroupHandle handle);

// @category:allocation
FALCON_CORE_C_API ListPairGnameGroupHandle ListPairGnameGroup_fill_value(size_t count, PairGnameGroupHandle value);
// @category:allocation
FALCON_CORE_C_API ListPairGnameGroupHandle ListPairGnameGroup_create(PairGnameGroupHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListPairGnameGroup_destroy(ListPairGnameGroupHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairGnameGroup_push_back(ListPairGnameGroupHandle handle, PairGnameGroupHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairGnameGroup_size(ListPairGnameGroupHandle handle);
// @category:read
FALCON_CORE_C_API bool ListPairGnameGroup_empty(ListPairGnameGroupHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairGnameGroup_erase_at(ListPairGnameGroupHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListPairGnameGroup_clear(ListPairGnameGroupHandle handle);
// @category:read
FALCON_CORE_C_API PairGnameGroupHandle ListPairGnameGroup_at(ListPairGnameGroupHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListPairGnameGroup_items(ListPairGnameGroupHandle handle, PairGnameGroupHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListPairGnameGroup_contains(ListPairGnameGroupHandle handle, PairGnameGroupHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairGnameGroup_index(ListPairGnameGroupHandle handle, PairGnameGroupHandle value);
// @category:read
FALCON_CORE_C_API ListPairGnameGroupHandle ListPairGnameGroup_intersection(ListPairGnameGroupHandle handle, ListPairGnameGroupHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairGnameGroup_equal(ListPairGnameGroupHandle handle, ListPairGnameGroupHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairGnameGroup_not_equal(ListPairGnameGroupHandle handle, ListPairGnameGroupHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListPairGnameGroup_to_json_string(ListPairGnameGroupHandle handle);
// @category:allocation
FALCON_CORE_C_API ListPairGnameGroupHandle ListPairGnameGroup_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif