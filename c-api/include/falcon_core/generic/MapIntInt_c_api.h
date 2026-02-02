#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairIntInt_c_api.h"
#include "falcon_core/generic/ListInt_c_api.h"
#include "falcon_core/generic/ListPairIntInt_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapIntIntHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API MapIntIntHandle MapIntInt_create_empty();
// @category:allocation
FALCON_CORE_C_API MapIntIntHandle MapIntInt_copy(MapIntIntHandle handle);
// @category:allocation
FALCON_CORE_C_API MapIntIntHandle MapIntInt_create(PairIntIntHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void MapIntInt_destroy(MapIntIntHandle handle);
// @category:write
FALCON_CORE_C_API void MapIntInt_insert_or_assign(MapIntIntHandle handle, int key, int value);
// @category:write
FALCON_CORE_C_API void MapIntInt_insert(MapIntIntHandle handle, int key, int value);
// @category:read
FALCON_CORE_C_API int MapIntInt_at(MapIntIntHandle handle, int key);
// @category:write
FALCON_CORE_C_API void MapIntInt_erase(MapIntIntHandle handle, int key);
// @category:read
FALCON_CORE_C_API size_t MapIntInt_size(MapIntIntHandle handle);
// @category:read
FALCON_CORE_C_API bool MapIntInt_empty(MapIntIntHandle handle);
// @category:write
FALCON_CORE_C_API void MapIntInt_clear(MapIntIntHandle handle);
// @category:read
FALCON_CORE_C_API bool MapIntInt_contains(MapIntIntHandle handle, int key);
// @category:read
FALCON_CORE_C_API ListIntHandle MapIntInt_keys(MapIntIntHandle handle);
// @category:read
FALCON_CORE_C_API ListIntHandle MapIntInt_values(MapIntIntHandle handle);
// @category:read
FALCON_CORE_C_API  ListPairIntIntHandle MapIntInt_items(MapIntIntHandle handle);
// @category:read
FALCON_CORE_C_API bool MapIntInt_equal(MapIntIntHandle handle, MapIntIntHandle other);
// @category:read
FALCON_CORE_C_API bool MapIntInt_not_equal(MapIntIntHandle handle, MapIntIntHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      MapIntInt_to_json_string(MapIntIntHandle handle);
// @category:allocation
FALCON_CORE_C_API MapIntIntHandle MapIntInt_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif