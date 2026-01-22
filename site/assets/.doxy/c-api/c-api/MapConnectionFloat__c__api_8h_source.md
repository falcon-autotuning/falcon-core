

# File MapConnectionFloat\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapConnectionFloat\_c\_api.h**](MapConnectionFloat__c__api_8h.md)

[Go to the documentation of this file](MapConnectionFloat__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairConnectionFloat_c_api.h"
#include "falcon_core/generic/ListFloat_c_api.h"
#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/generic/ListPairConnectionFloat_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapConnectionFloatHandle;
// Function declarations

// @category:allocation
MapConnectionFloatHandle MapConnectionFloat_create_empty();
// @category:allocation
MapConnectionFloatHandle MapConnectionFloat_copy(MapConnectionFloatHandle handle);
// @category:allocation
MapConnectionFloatHandle MapConnectionFloat_create(PairConnectionFloatHandle* data, size_t count);
// @category:deallocation
void MapConnectionFloat_destroy(MapConnectionFloatHandle handle);
// @category:write
void MapConnectionFloat_insert_or_assign(MapConnectionFloatHandle handle, ConnectionHandle key, float value);
// @category:write
void MapConnectionFloat_insert(MapConnectionFloatHandle handle, ConnectionHandle key, float value);
// @category:read
float MapConnectionFloat_at(MapConnectionFloatHandle handle, ConnectionHandle key);
// @category:write
void MapConnectionFloat_erase(MapConnectionFloatHandle handle, ConnectionHandle key);
// @category:read
size_t MapConnectionFloat_size(MapConnectionFloatHandle handle);
// @category:read
bool MapConnectionFloat_empty(MapConnectionFloatHandle handle);
// @category:write
void MapConnectionFloat_clear(MapConnectionFloatHandle handle);
// @category:read
bool MapConnectionFloat_contains(MapConnectionFloatHandle handle, ConnectionHandle key);
// @category:read
ListConnectionHandle MapConnectionFloat_keys(MapConnectionFloatHandle handle);
// @category:read
ListFloatHandle MapConnectionFloat_values(MapConnectionFloatHandle handle);
// @category:read
ListPairConnectionFloatHandle MapConnectionFloat_items(MapConnectionFloatHandle handle);
// @category:read
bool MapConnectionFloat_equal(MapConnectionFloatHandle handle, MapConnectionFloatHandle other);
// @category:read
bool MapConnectionFloat_not_equal(MapConnectionFloatHandle handle, MapConnectionFloatHandle other);
// @category:read
StringHandle      MapConnectionFloat_to_json_string(MapConnectionFloatHandle handle);
// @category:allocation
MapConnectionFloatHandle MapConnectionFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


