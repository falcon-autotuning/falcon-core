#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairInterpretationContextDouble_c_api.h"
#include "falcon_core/generic/ListDouble_c_api.h"
#include "falcon_core/generic/ListInterpretationContext_c_api.h"
#include "falcon_core/generic/ListPairInterpretationContextDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapInterpretationContextDoubleHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API MapInterpretationContextDoubleHandle MapInterpretationContextDouble_create_empty();
// @category:allocation
FALCON_CORE_C_API MapInterpretationContextDoubleHandle MapInterpretationContextDouble_copy(MapInterpretationContextDoubleHandle handle);
// @category:allocation
FALCON_CORE_C_API MapInterpretationContextDoubleHandle MapInterpretationContextDouble_create(PairInterpretationContextDoubleHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void MapInterpretationContextDouble_destroy(MapInterpretationContextDoubleHandle handle);
// @category:write
FALCON_CORE_C_API void MapInterpretationContextDouble_insert_or_assign(MapInterpretationContextDoubleHandle handle, InterpretationContextHandle key, double value);
// @category:write
FALCON_CORE_C_API void MapInterpretationContextDouble_insert(MapInterpretationContextDoubleHandle handle, InterpretationContextHandle key, double value);
// @category:read
FALCON_CORE_C_API double MapInterpretationContextDouble_at(MapInterpretationContextDoubleHandle handle, InterpretationContextHandle key);
// @category:write
FALCON_CORE_C_API void MapInterpretationContextDouble_erase(MapInterpretationContextDoubleHandle handle, InterpretationContextHandle key);
// @category:read
FALCON_CORE_C_API size_t MapInterpretationContextDouble_size(MapInterpretationContextDoubleHandle handle);
// @category:read
FALCON_CORE_C_API bool MapInterpretationContextDouble_empty(MapInterpretationContextDoubleHandle handle);
// @category:write
FALCON_CORE_C_API void MapInterpretationContextDouble_clear(MapInterpretationContextDoubleHandle handle);
// @category:read
FALCON_CORE_C_API bool MapInterpretationContextDouble_contains(MapInterpretationContextDoubleHandle handle, InterpretationContextHandle key);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle MapInterpretationContextDouble_keys(MapInterpretationContextDoubleHandle handle);
// @category:read
FALCON_CORE_C_API ListDoubleHandle MapInterpretationContextDouble_values(MapInterpretationContextDoubleHandle handle);
// @category:read
FALCON_CORE_C_API  ListPairInterpretationContextDoubleHandle MapInterpretationContextDouble_items(MapInterpretationContextDoubleHandle handle);
// @category:read
FALCON_CORE_C_API bool MapInterpretationContextDouble_equal(MapInterpretationContextDoubleHandle handle, MapInterpretationContextDoubleHandle other);
// @category:read
FALCON_CORE_C_API bool MapInterpretationContextDouble_not_equal(MapInterpretationContextDoubleHandle handle, MapInterpretationContextDoubleHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      MapInterpretationContextDouble_to_json_string(MapInterpretationContextDoubleHandle handle);
// @category:allocation
FALCON_CORE_C_API MapInterpretationContextDoubleHandle MapInterpretationContextDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif