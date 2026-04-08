#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/generic/PairFloatFloat_c_api.h"
#include "falcon-core/generic/ListFloat_c_api.h"
#include "falcon-core/generic/ListPairFloatFloat_c_api.h"
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapFloatFloatHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API MapFloatFloatHandle MapFloatFloat_create_empty();
// @category:allocation
FALCON_CORE_C_API MapFloatFloatHandle MapFloatFloat_copy(MapFloatFloatHandle handle);
// @category:allocation
FALCON_CORE_C_API MapFloatFloatHandle MapFloatFloat_create(PairFloatFloatHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void MapFloatFloat_destroy(MapFloatFloatHandle handle);
// @category:write
FALCON_CORE_C_API void MapFloatFloat_insert_or_assign(MapFloatFloatHandle handle, float key, float value);
// @category:write
FALCON_CORE_C_API void MapFloatFloat_insert(MapFloatFloatHandle handle, float key, float value);
// @category:read
FALCON_CORE_C_API float MapFloatFloat_at(MapFloatFloatHandle handle, float key);
// @category:write
FALCON_CORE_C_API void MapFloatFloat_erase(MapFloatFloatHandle handle, float key);
// @category:read
FALCON_CORE_C_API size_t MapFloatFloat_size(MapFloatFloatHandle handle);
// @category:read
FALCON_CORE_C_API bool MapFloatFloat_empty(MapFloatFloatHandle handle);
// @category:write
FALCON_CORE_C_API void MapFloatFloat_clear(MapFloatFloatHandle handle);
// @category:read
FALCON_CORE_C_API bool MapFloatFloat_contains(MapFloatFloatHandle handle, float key);
// @category:read
FALCON_CORE_C_API ListFloatHandle MapFloatFloat_keys(MapFloatFloatHandle handle);
// @category:read
FALCON_CORE_C_API ListFloatHandle MapFloatFloat_values(MapFloatFloatHandle handle);
// @category:read
FALCON_CORE_C_API  ListPairFloatFloatHandle MapFloatFloat_items(MapFloatFloatHandle handle);
// @category:read
FALCON_CORE_C_API bool MapFloatFloat_equal(MapFloatFloatHandle handle, MapFloatFloatHandle other);
// @category:read
FALCON_CORE_C_API bool MapFloatFloat_not_equal(MapFloatFloatHandle handle, MapFloatFloatHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      MapFloatFloat_to_json_string(MapFloatFloatHandle handle);
// @category:allocation
FALCON_CORE_C_API MapFloatFloatHandle MapFloatFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif