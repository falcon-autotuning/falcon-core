

# File MapStringBool\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapStringBool\_c\_api.h**](MapStringBool__c__api_8h.md)

[Go to the documentation of this file](MapStringBool__c__api_8h.md)


```C++
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
MapStringBoolHandle MapStringBool_create_empty();
// @category:allocation
MapStringBoolHandle MapStringBool_copy(MapStringBoolHandle handle);
// @category:allocation
MapStringBoolHandle MapStringBool_create(PairStringBoolHandle* data, size_t count);
// @category:deallocation
void MapStringBool_destroy(MapStringBoolHandle handle);
// @category:write
void MapStringBool_insert_or_assign(MapStringBoolHandle handle, StringHandle key, bool value);
// @category:write
void MapStringBool_insert(MapStringBoolHandle handle, StringHandle key, bool value);
// @category:read
bool MapStringBool_at(MapStringBoolHandle handle, StringHandle key);
// @category:write
void MapStringBool_erase(MapStringBoolHandle handle, StringHandle key);
// @category:read
size_t MapStringBool_size(MapStringBoolHandle handle);
// @category:read
bool MapStringBool_empty(MapStringBoolHandle handle);
// @category:write
void MapStringBool_clear(MapStringBoolHandle handle);
// @category:read
bool MapStringBool_contains(MapStringBoolHandle handle, StringHandle key);
// @category:read
ListStringHandle MapStringBool_keys(MapStringBoolHandle handle);
// @category:read
ListBoolHandle MapStringBool_values(MapStringBoolHandle handle);
// @category:read
ListPairStringBoolHandle MapStringBool_items(MapStringBoolHandle handle);
// @category:read
bool MapStringBool_equal(MapStringBoolHandle handle, MapStringBoolHandle other);
// @category:read
bool MapStringBool_not_equal(MapStringBoolHandle handle, MapStringBoolHandle other);
// @category:read
StringHandle      MapStringBool_to_json_string(MapStringBoolHandle handle);
// @category:allocation
MapStringBoolHandle MapStringBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


