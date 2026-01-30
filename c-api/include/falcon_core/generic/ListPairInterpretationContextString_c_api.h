#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairInterpretationContextString_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairInterpretationContextStringHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListPairInterpretationContextStringHandle ListPairInterpretationContextString_create_empty();
// @category:allocation
FALCON_CORE_C_API ListPairInterpretationContextStringHandle ListPairInterpretationContextString_copy(ListPairInterpretationContextStringHandle handle);

// @category:allocation
FALCON_CORE_C_API ListPairInterpretationContextStringHandle ListPairInterpretationContextString_fill_value(size_t count, PairInterpretationContextStringHandle value);
// @category:allocation
FALCON_CORE_C_API ListPairInterpretationContextStringHandle ListPairInterpretationContextString_create(PairInterpretationContextStringHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListPairInterpretationContextString_destroy(ListPairInterpretationContextStringHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairInterpretationContextString_push_back(ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairInterpretationContextString_size(ListPairInterpretationContextStringHandle handle);
// @category:read
FALCON_CORE_C_API bool ListPairInterpretationContextString_empty(ListPairInterpretationContextStringHandle handle);
// @category:write
FALCON_CORE_C_API void ListPairInterpretationContextString_erase_at(ListPairInterpretationContextStringHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListPairInterpretationContextString_clear(ListPairInterpretationContextStringHandle handle);
// @category:read
FALCON_CORE_C_API PairInterpretationContextStringHandle ListPairInterpretationContextString_at(ListPairInterpretationContextStringHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListPairInterpretationContextString_items(ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListPairInterpretationContextString_contains(ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPairInterpretationContextString_index(ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle value);
// @category:read
FALCON_CORE_C_API ListPairInterpretationContextStringHandle ListPairInterpretationContextString_intersection(ListPairInterpretationContextStringHandle handle, ListPairInterpretationContextStringHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairInterpretationContextString_equal(ListPairInterpretationContextStringHandle handle, ListPairInterpretationContextStringHandle other);
// @category:read
FALCON_CORE_C_API bool ListPairInterpretationContextString_not_equal(ListPairInterpretationContextStringHandle handle, ListPairInterpretationContextStringHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListPairInterpretationContextString_to_json_string(ListPairInterpretationContextStringHandle handle);
// @category:allocation
FALCON_CORE_C_API ListPairInterpretationContextStringHandle ListPairInterpretationContextString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif