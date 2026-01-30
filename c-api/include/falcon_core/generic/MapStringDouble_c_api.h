#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListPairStringDouble_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
#include "falcon_core/generic/ListDouble_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapStringDoubleHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API MapStringDoubleHandle MapStringDouble_create_empty();
// @category:allocation
FALCON_CORE_C_API MapStringDoubleHandle MapStringDouble_copy(MapStringDoubleHandle handle);
// @category:allocation
FALCON_CORE_C_API MapStringDoubleHandle MapStringDouble_create(PairStringDoubleHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void MapStringDouble_destroy(MapStringDoubleHandle handle);
// @category:write
FALCON_CORE_C_API void MapStringDouble_insert_or_assign(MapStringDoubleHandle handle, StringHandle key, double value);
// @category:write
FALCON_CORE_C_API void MapStringDouble_insert(MapStringDoubleHandle handle, StringHandle key, double value);
// @category:read
FALCON_CORE_C_API double MapStringDouble_at(MapStringDoubleHandle handle, StringHandle key);
// @category:write
FALCON_CORE_C_API void MapStringDouble_erase(MapStringDoubleHandle handle, StringHandle key);
// @category:read
FALCON_CORE_C_API size_t MapStringDouble_size(MapStringDoubleHandle handle);
// @category:read
FALCON_CORE_C_API bool MapStringDouble_empty(MapStringDoubleHandle handle);
// @category:write
FALCON_CORE_C_API void MapStringDouble_clear(MapStringDoubleHandle handle);
// @category:read
FALCON_CORE_C_API bool MapStringDouble_contains(MapStringDoubleHandle handle, StringHandle key);
// @category:read
FALCON_CORE_C_API ListStringHandle MapStringDouble_keys(MapStringDoubleHandle handle);
// @category:read
FALCON_CORE_C_API ListDoubleHandle MapStringDouble_values(MapStringDoubleHandle handle);
// @category:read
FALCON_CORE_C_API  ListPairStringDoubleHandle MapStringDouble_items(MapStringDoubleHandle handle);
// @category:read
FALCON_CORE_C_API bool MapStringDouble_equal(MapStringDoubleHandle handle, MapStringDoubleHandle other);
// @category:read
FALCON_CORE_C_API bool MapStringDouble_not_equal(MapStringDoubleHandle handle, MapStringDoubleHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      MapStringDouble_to_json_string(MapStringDoubleHandle handle);
// @category:allocation
FALCON_CORE_C_API MapStringDoubleHandle MapStringDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif