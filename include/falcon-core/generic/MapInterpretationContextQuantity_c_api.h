#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/generic/PairInterpretationContextQuantity_c_api.h"
#include "falcon-core/generic/ListQuantity_c_api.h"
#include "falcon-core/generic/ListInterpretationContext_c_api.h"
#include "falcon-core/generic/ListPairInterpretationContextQuantity_c_api.h"
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapInterpretationContextQuantityHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_create_empty();
// @category:allocation
FALCON_CORE_C_API MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_copy(MapInterpretationContextQuantityHandle handle);
// @category:allocation
FALCON_CORE_C_API MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_create(PairInterpretationContextQuantityHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void MapInterpretationContextQuantity_destroy(MapInterpretationContextQuantityHandle handle);
// @category:write
FALCON_CORE_C_API void MapInterpretationContextQuantity_insert_or_assign(MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key, QuantityHandle value);
// @category:write
FALCON_CORE_C_API void MapInterpretationContextQuantity_insert(MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key, QuantityHandle value);
// @category:read
FALCON_CORE_C_API QuantityHandle MapInterpretationContextQuantity_at(MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key);
// @category:write
FALCON_CORE_C_API void MapInterpretationContextQuantity_erase(MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key);
// @category:read
FALCON_CORE_C_API size_t MapInterpretationContextQuantity_size(MapInterpretationContextQuantityHandle handle);
// @category:read
FALCON_CORE_C_API bool MapInterpretationContextQuantity_empty(MapInterpretationContextQuantityHandle handle);
// @category:write
FALCON_CORE_C_API void MapInterpretationContextQuantity_clear(MapInterpretationContextQuantityHandle handle);
// @category:read
FALCON_CORE_C_API bool MapInterpretationContextQuantity_contains(MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key);
// @category:read
FALCON_CORE_C_API ListInterpretationContextHandle MapInterpretationContextQuantity_keys(MapInterpretationContextQuantityHandle handle);
// @category:read
FALCON_CORE_C_API ListQuantityHandle MapInterpretationContextQuantity_values(MapInterpretationContextQuantityHandle handle);
// @category:read
FALCON_CORE_C_API  ListPairInterpretationContextQuantityHandle MapInterpretationContextQuantity_items(MapInterpretationContextQuantityHandle handle);
// @category:read
FALCON_CORE_C_API bool MapInterpretationContextQuantity_equal(MapInterpretationContextQuantityHandle handle, MapInterpretationContextQuantityHandle other);
// @category:read
FALCON_CORE_C_API bool MapInterpretationContextQuantity_not_equal(MapInterpretationContextQuantityHandle handle, MapInterpretationContextQuantityHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      MapInterpretationContextQuantity_to_json_string(MapInterpretationContextQuantityHandle handle);
// @category:allocation
FALCON_CORE_C_API MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif