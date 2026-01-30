#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairConnectionDouble_c_api.h"
#include "falcon_core/generic/ListDouble_c_api.h"
#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/generic/ListPairConnectionDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapConnectionDoubleHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API MapConnectionDoubleHandle MapConnectionDouble_create_empty();
// @category:allocation
FALCON_CORE_C_API MapConnectionDoubleHandle MapConnectionDouble_copy(MapConnectionDoubleHandle handle);
// @category:allocation
FALCON_CORE_C_API MapConnectionDoubleHandle MapConnectionDouble_create(PairConnectionDoubleHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void MapConnectionDouble_destroy(MapConnectionDoubleHandle handle);
// @category:write
FALCON_CORE_C_API void MapConnectionDouble_insert_or_assign(MapConnectionDoubleHandle handle, ConnectionHandle key, double value);
// @category:write
FALCON_CORE_C_API void MapConnectionDouble_insert(MapConnectionDoubleHandle handle, ConnectionHandle key, double value);
// @category:read
FALCON_CORE_C_API double MapConnectionDouble_at(MapConnectionDoubleHandle handle, ConnectionHandle key);
// @category:write
FALCON_CORE_C_API void MapConnectionDouble_erase(MapConnectionDoubleHandle handle, ConnectionHandle key);
// @category:read
FALCON_CORE_C_API size_t MapConnectionDouble_size(MapConnectionDoubleHandle handle);
// @category:read
FALCON_CORE_C_API bool MapConnectionDouble_empty(MapConnectionDoubleHandle handle);
// @category:write
FALCON_CORE_C_API void MapConnectionDouble_clear(MapConnectionDoubleHandle handle);
// @category:read
FALCON_CORE_C_API bool MapConnectionDouble_contains(MapConnectionDoubleHandle handle, ConnectionHandle key);
// @category:read
FALCON_CORE_C_API ListConnectionHandle MapConnectionDouble_keys(MapConnectionDoubleHandle handle);
// @category:read
FALCON_CORE_C_API ListDoubleHandle MapConnectionDouble_values(MapConnectionDoubleHandle handle);
// @category:read
FALCON_CORE_C_API  ListPairConnectionDoubleHandle MapConnectionDouble_items(MapConnectionDoubleHandle handle);
// @category:read
FALCON_CORE_C_API bool MapConnectionDouble_equal(MapConnectionDoubleHandle handle, MapConnectionDoubleHandle other);
// @category:read
FALCON_CORE_C_API bool MapConnectionDouble_not_equal(MapConnectionDoubleHandle handle, MapConnectionDoubleHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      MapConnectionDouble_to_json_string(MapConnectionDoubleHandle handle);
// @category:allocation
FALCON_CORE_C_API MapConnectionDoubleHandle MapConnectionDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif