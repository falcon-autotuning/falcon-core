

# File MapConnectionQuantity\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapConnectionQuantity\_c\_api.h**](MapConnectionQuantity__c__api_8h.md)

[Go to the documentation of this file](MapConnectionQuantity__c__api_8h.md)


```C++
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
MapConnectionQuantityHandle MapConnectionQuantity_create_empty();
// @category:allocation
MapConnectionQuantityHandle MapConnectionQuantity_copy(MapConnectionQuantityHandle handle);
// @category:allocation
MapConnectionQuantityHandle MapConnectionQuantity_create(PairConnectionQuantityHandle* data, size_t count);
// @category:deallocation
void MapConnectionQuantity_destroy(MapConnectionQuantityHandle handle);
// @category:write
void MapConnectionQuantity_insert_or_assign(MapConnectionQuantityHandle handle, ConnectionHandle key, QuantityHandle value);
// @category:write
void MapConnectionQuantity_insert(MapConnectionQuantityHandle handle, ConnectionHandle key, QuantityHandle value);
// @category:read
QuantityHandle MapConnectionQuantity_at(MapConnectionQuantityHandle handle, ConnectionHandle key);
// @category:write
void MapConnectionQuantity_erase(MapConnectionQuantityHandle handle, ConnectionHandle key);
// @category:read
size_t MapConnectionQuantity_size(MapConnectionQuantityHandle handle);
// @category:read
bool MapConnectionQuantity_empty(MapConnectionQuantityHandle handle);
// @category:write
void MapConnectionQuantity_clear(MapConnectionQuantityHandle handle);
// @category:read
bool MapConnectionQuantity_contains(MapConnectionQuantityHandle handle, ConnectionHandle key);
// @category:read
ListConnectionHandle MapConnectionQuantity_keys(MapConnectionQuantityHandle handle);
// @category:read
ListQuantityHandle MapConnectionQuantity_values(MapConnectionQuantityHandle handle);
// @category:read
ListPairConnectionQuantityHandle MapConnectionQuantity_items(MapConnectionQuantityHandle handle);
// @category:read
bool MapConnectionQuantity_equal(MapConnectionQuantityHandle handle, MapConnectionQuantityHandle other);
// @category:read
bool MapConnectionQuantity_not_equal(MapConnectionQuantityHandle handle, MapConnectionQuantityHandle other);
// @category:read
StringHandle      MapConnectionQuantity_to_json_string(MapConnectionQuantityHandle handle);
// @category:allocation
MapConnectionQuantityHandle MapConnectionQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


