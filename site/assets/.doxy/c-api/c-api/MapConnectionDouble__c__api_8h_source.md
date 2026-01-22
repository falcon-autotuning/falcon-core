

# File MapConnectionDouble\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapConnectionDouble\_c\_api.h**](MapConnectionDouble__c__api_8h.md)

[Go to the documentation of this file](MapConnectionDouble__c__api_8h.md)


```C++
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
MapConnectionDoubleHandle MapConnectionDouble_create_empty();
// @category:allocation
MapConnectionDoubleHandle MapConnectionDouble_copy(MapConnectionDoubleHandle handle);
// @category:allocation
MapConnectionDoubleHandle MapConnectionDouble_create(PairConnectionDoubleHandle* data, size_t count);
// @category:deallocation
void MapConnectionDouble_destroy(MapConnectionDoubleHandle handle);
// @category:write
void MapConnectionDouble_insert_or_assign(MapConnectionDoubleHandle handle, ConnectionHandle key, double value);
// @category:write
void MapConnectionDouble_insert(MapConnectionDoubleHandle handle, ConnectionHandle key, double value);
// @category:read
double MapConnectionDouble_at(MapConnectionDoubleHandle handle, ConnectionHandle key);
// @category:write
void MapConnectionDouble_erase(MapConnectionDoubleHandle handle, ConnectionHandle key);
// @category:read
size_t MapConnectionDouble_size(MapConnectionDoubleHandle handle);
// @category:read
bool MapConnectionDouble_empty(MapConnectionDoubleHandle handle);
// @category:write
void MapConnectionDouble_clear(MapConnectionDoubleHandle handle);
// @category:read
bool MapConnectionDouble_contains(MapConnectionDoubleHandle handle, ConnectionHandle key);
// @category:read
ListConnectionHandle MapConnectionDouble_keys(MapConnectionDoubleHandle handle);
// @category:read
ListDoubleHandle MapConnectionDouble_values(MapConnectionDoubleHandle handle);
// @category:read
ListPairConnectionDoubleHandle MapConnectionDouble_items(MapConnectionDoubleHandle handle);
// @category:read
bool MapConnectionDouble_equal(MapConnectionDoubleHandle handle, MapConnectionDoubleHandle other);
// @category:read
bool MapConnectionDouble_not_equal(MapConnectionDoubleHandle handle, MapConnectionDoubleHandle other);
// @category:read
StringHandle      MapConnectionDouble_to_json_string(MapConnectionDoubleHandle handle);
// @category:allocation
MapConnectionDoubleHandle MapConnectionDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


