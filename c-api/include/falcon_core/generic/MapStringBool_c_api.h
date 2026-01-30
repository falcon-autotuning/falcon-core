#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListPairStringBool_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
#include "falcon_core/generic/ListBool_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapStringBoolHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API MapStringBoolHandle MapStringBool_create_empty();
// @category:allocation
FALCON_CORE_C_API MapStringBoolHandle MapStringBool_copy(MapStringBoolHandle handle);
// @category:allocation
FALCON_CORE_C_API MapStringBoolHandle MapStringBool_create(PairStringBoolHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void MapStringBool_destroy(MapStringBoolHandle handle);
// @category:write
FALCON_CORE_C_API void MapStringBool_insert_or_assign(MapStringBoolHandle handle, StringHandle key, bool value);
// @category:write
FALCON_CORE_C_API void MapStringBool_insert(MapStringBoolHandle handle, StringHandle key, bool value);
// @category:read
FALCON_CORE_C_API bool MapStringBool_at(MapStringBoolHandle handle, StringHandle key);
// @category:write
FALCON_CORE_C_API void MapStringBool_erase(MapStringBoolHandle handle, StringHandle key);
// @category:read
FALCON_CORE_C_API size_t MapStringBool_size(MapStringBoolHandle handle);
// @category:read
FALCON_CORE_C_API bool MapStringBool_empty(MapStringBoolHandle handle);
// @category:write
FALCON_CORE_C_API void MapStringBool_clear(MapStringBoolHandle handle);
// @category:read
FALCON_CORE_C_API bool MapStringBool_contains(MapStringBoolHandle handle, StringHandle key);
// @category:read
FALCON_CORE_C_API ListStringHandle MapStringBool_keys(MapStringBoolHandle handle);
// @category:read
FALCON_CORE_C_API ListBoolHandle MapStringBool_values(MapStringBoolHandle handle);
// @category:read
FALCON_CORE_C_API  ListPairStringBoolHandle MapStringBool_items(MapStringBoolHandle handle);
// @category:read
FALCON_CORE_C_API bool MapStringBool_equal(MapStringBoolHandle handle, MapStringBoolHandle other);
// @category:read
FALCON_CORE_C_API bool MapStringBool_not_equal(MapStringBoolHandle handle, MapStringBoolHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      MapStringBool_to_json_string(MapStringBoolHandle handle);
// @category:allocation
FALCON_CORE_C_API MapStringBoolHandle MapStringBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif