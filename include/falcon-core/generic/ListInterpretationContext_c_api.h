#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListInterpretationContextHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListInterpretationContextHandle ListInterpretationContext_create_empty();
// @category:allocation
FALCON_CORE_C_API ListInterpretationContextHandle ListInterpretationContext_copy(ListInterpretationContextHandle handle);

// @category:allocation
FALCON_CORE_C_API ListInterpretationContextHandle ListInterpretationContext_fill_value(size_t count, InterpretationContextHandle value);
// @category:allocation
FALCON_CORE_C_API ListInterpretationContextHandle ListInterpretationContext_create(InterpretationContextHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListInterpretationContext_destroy(ListInterpretationContextHandle handle);
// @category:write
FALCON_CORE_C_API void ListInterpretationContext_push_back(ListInterpretationContextHandle handle, InterpretationContextHandle value);
// @category:read
FALCON_CORE_C_API size_t ListInterpretationContext_size(ListInterpretationContextHandle handle);
// @category:read
FALCON_CORE_C_API bool ListInterpretationContext_empty(ListInterpretationContextHandle handle);
// @category:write
FALCON_CORE_C_API void ListInterpretationContext_erase_at(ListInterpretationContextHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListInterpretationContext_clear(ListInterpretationContextHandle handle);
// @category:read
FALCON_CORE_C_API InterpretationContextHandle ListInterpretationContext_at(ListInterpretationContextHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListInterpretationContext_items(ListInterpretationContextHandle handle, InterpretationContextHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListInterpretationContext_contains(ListInterpretationContextHandle handle, InterpretationContextHandle value);
// @category:read
FALCON_CORE_C_API size_t ListInterpretationContext_index(ListInterpretationContextHandle handle, InterpretationContextHandle value);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle ListInterpretationContext_intersection(ListInterpretationContextHandle handle, ListInterpretationContextHandle other);
// @category:read
FALCON_CORE_C_API bool ListInterpretationContext_equal(ListInterpretationContextHandle handle, ListInterpretationContextHandle other);
// @category:read
FALCON_CORE_C_API bool ListInterpretationContext_not_equal(ListInterpretationContextHandle handle, ListInterpretationContextHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListInterpretationContext_to_json_string(ListInterpretationContextHandle handle);
// @category:allocation
FALCON_CORE_C_API ListInterpretationContextHandle ListInterpretationContext_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif