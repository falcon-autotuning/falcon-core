#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairConnectionQuantity_c_api.h"
#include "falcon_core/generic/ListQuantity_c_api.h"
#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/generic/ListPairConnectionQuantity_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapConnectionQuantityHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API MapConnectionQuantityHandle MapConnectionQuantity_create_empty();
// @category:allocation
FALCON_CORE_C_API MapConnectionQuantityHandle MapConnectionQuantity_copy(MapConnectionQuantityHandle handle);
// @category:allocation
FALCON_CORE_C_API MapConnectionQuantityHandle MapConnectionQuantity_create(PairConnectionQuantityHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void MapConnectionQuantity_destroy(MapConnectionQuantityHandle handle);
// @category:write
FALCON_CORE_C_API void MapConnectionQuantity_insert_or_assign(MapConnectionQuantityHandle handle, ConnectionHandle key, QuantityHandle value);
// @category:write
FALCON_CORE_C_API void MapConnectionQuantity_insert(MapConnectionQuantityHandle handle, ConnectionHandle key, QuantityHandle value);
// @category:read
FALCON_CORE_C_API QuantityHandle MapConnectionQuantity_at(MapConnectionQuantityHandle handle, ConnectionHandle key);
// @category:write
FALCON_CORE_C_API void MapConnectionQuantity_erase(MapConnectionQuantityHandle handle, ConnectionHandle key);
// @category:read
FALCON_CORE_C_API size_t MapConnectionQuantity_size(MapConnectionQuantityHandle handle);
// @category:read
FALCON_CORE_C_API bool MapConnectionQuantity_empty(MapConnectionQuantityHandle handle);
// @category:write
FALCON_CORE_C_API void MapConnectionQuantity_clear(MapConnectionQuantityHandle handle);
// @category:read
FALCON_CORE_C_API bool MapConnectionQuantity_contains(MapConnectionQuantityHandle handle, ConnectionHandle key);
// @category:read
FALCON_CORE_C_API ListConnectionHandle MapConnectionQuantity_keys(MapConnectionQuantityHandle handle);
// @category:read
FALCON_CORE_C_API ListQuantityHandle MapConnectionQuantity_values(MapConnectionQuantityHandle handle);
// @category:read
FALCON_CORE_C_API  ListPairConnectionQuantityHandle MapConnectionQuantity_items(MapConnectionQuantityHandle handle);
// @category:read
FALCON_CORE_C_API bool MapConnectionQuantity_equal(MapConnectionQuantityHandle handle, MapConnectionQuantityHandle other);
// @category:read
FALCON_CORE_C_API bool MapConnectionQuantity_not_equal(MapConnectionQuantityHandle handle, MapConnectionQuantityHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      MapConnectionQuantity_to_json_string(MapConnectionQuantityHandle handle);
// @category:allocation
FALCON_CORE_C_API MapConnectionQuantityHandle MapConnectionQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif