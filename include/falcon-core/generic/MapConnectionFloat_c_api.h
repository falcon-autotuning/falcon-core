#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/generic/PairConnectionFloat_c_api.h"
#include "falcon-core/generic/ListFloat_c_api.h"
#include "falcon-core/generic/ListConnection_c_api.h"
#include "falcon-core/generic/ListPairConnectionFloat_c_api.h"
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapConnectionFloatHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API MapConnectionFloatHandle MapConnectionFloat_create_empty();
// @category:allocation
FALCON_CORE_C_API MapConnectionFloatHandle MapConnectionFloat_copy(MapConnectionFloatHandle handle);
// @category:allocation
FALCON_CORE_C_API MapConnectionFloatHandle MapConnectionFloat_create(PairConnectionFloatHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void MapConnectionFloat_destroy(MapConnectionFloatHandle handle);
// @category:write
FALCON_CORE_C_API void MapConnectionFloat_insert_or_assign(MapConnectionFloatHandle handle, ConnectionHandle key, float value);
// @category:write
FALCON_CORE_C_API void MapConnectionFloat_insert(MapConnectionFloatHandle handle, ConnectionHandle key, float value);
// @category:read
FALCON_CORE_C_API float MapConnectionFloat_at(MapConnectionFloatHandle handle, ConnectionHandle key);
// @category:write
FALCON_CORE_C_API void MapConnectionFloat_erase(MapConnectionFloatHandle handle, ConnectionHandle key);
// @category:read
FALCON_CORE_C_API size_t MapConnectionFloat_size(MapConnectionFloatHandle handle);
// @category:read
FALCON_CORE_C_API bool MapConnectionFloat_empty(MapConnectionFloatHandle handle);
// @category:write
FALCON_CORE_C_API void MapConnectionFloat_clear(MapConnectionFloatHandle handle);
// @category:read
FALCON_CORE_C_API bool MapConnectionFloat_contains(MapConnectionFloatHandle handle, ConnectionHandle key);
// @category:read
FALCON_CORE_C_API ListConnectionHandle MapConnectionFloat_keys(MapConnectionFloatHandle handle);
// @category:read
FALCON_CORE_C_API ListFloatHandle MapConnectionFloat_values(MapConnectionFloatHandle handle);
// @category:read
FALCON_CORE_C_API  ListPairConnectionFloatHandle MapConnectionFloat_items(MapConnectionFloatHandle handle);
// @category:read
FALCON_CORE_C_API bool MapConnectionFloat_equal(MapConnectionFloatHandle handle, MapConnectionFloatHandle other);
// @category:read
FALCON_CORE_C_API bool MapConnectionFloat_not_equal(MapConnectionFloatHandle handle, MapConnectionFloatHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      MapConnectionFloat_to_json_string(MapConnectionFloatHandle handle);
// @category:allocation
FALCON_CORE_C_API MapConnectionFloatHandle MapConnectionFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif