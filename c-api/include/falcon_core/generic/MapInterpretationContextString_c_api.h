#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairInterpretationContextString_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
#include "falcon_core/generic/ListInterpretationContext_c_api.h"
#include "falcon_core/generic/ListPairInterpretationContextString_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapInterpretationContextStringHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API MapInterpretationContextStringHandle MapInterpretationContextString_create_empty();
// @category:allocation
FALCON_CORE_C_API MapInterpretationContextStringHandle MapInterpretationContextString_copy(MapInterpretationContextStringHandle handle);
// @category:allocation
FALCON_CORE_C_API MapInterpretationContextStringHandle MapInterpretationContextString_create(PairInterpretationContextStringHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void MapInterpretationContextString_destroy(MapInterpretationContextStringHandle handle);
// @category:write
FALCON_CORE_C_API void MapInterpretationContextString_insert_or_assign(MapInterpretationContextStringHandle handle, InterpretationContextHandle key, StringHandle value);
// @category:write
FALCON_CORE_C_API void MapInterpretationContextString_insert(MapInterpretationContextStringHandle handle, InterpretationContextHandle key, StringHandle value);
// @category:read
FALCON_CORE_C_API StringHandle MapInterpretationContextString_at(MapInterpretationContextStringHandle handle, InterpretationContextHandle key);
// @category:write
FALCON_CORE_C_API void MapInterpretationContextString_erase(MapInterpretationContextStringHandle handle, InterpretationContextHandle key);
// @category:read
FALCON_CORE_C_API size_t MapInterpretationContextString_size(MapInterpretationContextStringHandle handle);
// @category:read
FALCON_CORE_C_API bool MapInterpretationContextString_empty(MapInterpretationContextStringHandle handle);
// @category:write
FALCON_CORE_C_API void MapInterpretationContextString_clear(MapInterpretationContextStringHandle handle);
// @category:read
FALCON_CORE_C_API bool MapInterpretationContextString_contains(MapInterpretationContextStringHandle handle, InterpretationContextHandle key);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle MapInterpretationContextString_keys(MapInterpretationContextStringHandle handle);
// @category:read
FALCON_CORE_C_API ListStringHandle MapInterpretationContextString_values(MapInterpretationContextStringHandle handle);
// @category:read
FALCON_CORE_C_API  ListPairInterpretationContextStringHandle MapInterpretationContextString_items(MapInterpretationContextStringHandle handle);
// @category:read
FALCON_CORE_C_API bool MapInterpretationContextString_equal(MapInterpretationContextStringHandle handle, MapInterpretationContextStringHandle other);
// @category:read
FALCON_CORE_C_API bool MapInterpretationContextString_not_equal(MapInterpretationContextStringHandle handle, MapInterpretationContextStringHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      MapInterpretationContextString_to_json_string(MapInterpretationContextStringHandle handle);
// @category:allocation
FALCON_CORE_C_API MapInterpretationContextStringHandle MapInterpretationContextString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif