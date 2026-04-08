#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/generic/PairGnameGroup_c_api.h"
#include "falcon-core/generic/ListGname_c_api.h"
#include "falcon-core/generic/ListGroup_c_api.h"
#include "falcon-core/generic/ListPairGnameGroup_c_api.h"
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapGnameGroupHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API MapGnameGroupHandle MapGnameGroup_create_empty();
// @category:allocation
FALCON_CORE_C_API MapGnameGroupHandle MapGnameGroup_copy(MapGnameGroupHandle handle);
// @category:allocation
FALCON_CORE_C_API MapGnameGroupHandle MapGnameGroup_create(PairGnameGroupHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void MapGnameGroup_destroy(MapGnameGroupHandle handle);
// @category:write
FALCON_CORE_C_API void MapGnameGroup_insert_or_assign(MapGnameGroupHandle handle, GnameHandle key, GroupHandle value);
// @category:write
FALCON_CORE_C_API void MapGnameGroup_insert(MapGnameGroupHandle handle, GnameHandle key, GroupHandle value);
// @category:read
FALCON_CORE_C_API GroupHandle MapGnameGroup_at(MapGnameGroupHandle handle, GnameHandle key);
// @category:write
FALCON_CORE_C_API void MapGnameGroup_erase(MapGnameGroupHandle handle, GnameHandle key);
// @category:read
FALCON_CORE_C_API size_t MapGnameGroup_size(MapGnameGroupHandle handle);
// @category:read
FALCON_CORE_C_API bool MapGnameGroup_empty(MapGnameGroupHandle handle);
// @category:write
FALCON_CORE_C_API void MapGnameGroup_clear(MapGnameGroupHandle handle);
// @category:read
FALCON_CORE_C_API bool MapGnameGroup_contains(MapGnameGroupHandle handle, GnameHandle key);
// @category:read
FALCON_CORE_C_API ListGnameHandle MapGnameGroup_keys(MapGnameGroupHandle handle);
// @category:read
FALCON_CORE_C_API ListGroupHandle MapGnameGroup_values(MapGnameGroupHandle handle);
// @category:read
FALCON_CORE_C_API  ListPairGnameGroupHandle MapGnameGroup_items(MapGnameGroupHandle handle);
// @category:read
FALCON_CORE_C_API bool MapGnameGroup_equal(MapGnameGroupHandle handle, MapGnameGroupHandle other);
// @category:read
FALCON_CORE_C_API bool MapGnameGroup_not_equal(MapGnameGroupHandle handle, MapGnameGroupHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      MapGnameGroup_to_json_string(MapGnameGroupHandle handle);
// @category:allocation
FALCON_CORE_C_API MapGnameGroupHandle MapGnameGroup_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif