

# File MapIntInt\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapIntInt\_c\_api.h**](MapIntInt__c__api_8h.md)

[Go to the documentation of this file](MapIntInt__c__api_8h.md)


```C++
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
MapIntIntHandle MapIntInt_create_empty();
// @category:allocation
MapIntIntHandle MapIntInt_copy(MapIntIntHandle handle);
// @category:allocation
MapIntIntHandle MapIntInt_create(PairIntIntHandle* data, size_t count);
// @category:deallocation
void MapIntInt_destroy(MapIntIntHandle handle);
// @category:write
void MapIntInt_insert_or_assign(MapIntIntHandle handle, int key, int value);
// @category:write
void MapIntInt_insert(MapIntIntHandle handle, int key, int value);
// @category:read
int MapIntInt_at(MapIntIntHandle handle, int key);
// @category:write
void MapIntInt_erase(MapIntIntHandle handle, int key);
// @category:read
size_t MapIntInt_size(MapIntIntHandle handle);
// @category:read
bool MapIntInt_empty(MapIntIntHandle handle);
// @category:write
void MapIntInt_clear(MapIntIntHandle handle);
// @category:read
bool MapIntInt_contains(MapIntIntHandle handle, int key);
// @category:read
ListIntHandle MapIntInt_keys(MapIntIntHandle handle);
// @category:read
ListIntHandle MapIntInt_values(MapIntIntHandle handle);
// @category:read
ListPairIntIntHandle MapIntInt_items(MapIntIntHandle handle);
// @category:read
bool MapIntInt_equal(MapIntIntHandle handle, MapIntIntHandle other);
// @category:read
bool MapIntInt_not_equal(MapIntIntHandle handle, MapIntIntHandle other);
// @category:read
StringHandle      MapIntInt_to_json_string(MapIntIntHandle handle);
// @category:allocation
MapIntIntHandle MapIntInt_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


