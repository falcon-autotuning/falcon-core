#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListPairStringString_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapStringStringHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API MapStringStringHandle MapStringString_create_empty();
// @category:allocation
FALCON_CORE_C_API MapStringStringHandle MapStringString_copy(MapStringStringHandle handle);
// @category:allocation
FALCON_CORE_C_API MapStringStringHandle MapStringString_create(PairStringStringHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void MapStringString_destroy(MapStringStringHandle handle);
// @category:write
FALCON_CORE_C_API void MapStringString_insert_or_assign(MapStringStringHandle handle, StringHandle key, StringHandle value);
// @category:write
FALCON_CORE_C_API void MapStringString_insert(MapStringStringHandle handle, StringHandle key, StringHandle value);
// @category:read
FALCON_CORE_C_API StringHandle MapStringString_at(MapStringStringHandle handle, StringHandle key);
// @category:write
FALCON_CORE_C_API void MapStringString_erase(MapStringStringHandle handle, StringHandle key);
// @category:read
FALCON_CORE_C_API size_t MapStringString_size(MapStringStringHandle handle);
// @category:read
FALCON_CORE_C_API bool MapStringString_empty(MapStringStringHandle handle);
// @category:write
FALCON_CORE_C_API void MapStringString_clear(MapStringStringHandle handle);
// @category:read
FALCON_CORE_C_API bool MapStringString_contains(MapStringStringHandle handle, StringHandle key);
// @category:read
FALCON_CORE_C_API ListStringHandle MapStringString_keys(MapStringStringHandle handle);
// @category:read
FALCON_CORE_C_API ListStringHandle MapStringString_values(MapStringStringHandle handle);
// @category:read
FALCON_CORE_C_API  ListPairStringStringHandle MapStringString_items(MapStringStringHandle handle);
// @category:read
FALCON_CORE_C_API bool MapStringString_equal(MapStringStringHandle handle, MapStringStringHandle other);
// @category:read
FALCON_CORE_C_API bool MapStringString_not_equal(MapStringStringHandle handle, MapStringStringHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      MapStringString_to_json_string(MapStringStringHandle handle);
// @category:allocation
FALCON_CORE_C_API MapStringStringHandle MapStringString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif