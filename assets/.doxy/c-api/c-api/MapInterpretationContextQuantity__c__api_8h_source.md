

# File MapInterpretationContextQuantity\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapInterpretationContextQuantity\_c\_api.h**](MapInterpretationContextQuantity__c__api_8h.md)

[Go to the documentation of this file](MapInterpretationContextQuantity__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairInterpretationContextQuantity_c_api.h"
#include "falcon_core/generic/ListQuantity_c_api.h"
#include "falcon_core/generic/ListInterpretationContext_c_api.h"
#include "falcon_core/generic/ListPairInterpretationContextQuantity_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapInterpretationContextQuantityHandle;
// Function declarations

// @category:allocation
MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_create_empty();
// @category:allocation
MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_copy(MapInterpretationContextQuantityHandle handle);
// @category:allocation
MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_create(PairInterpretationContextQuantityHandle* data, size_t count);
// @category:deallocation
void MapInterpretationContextQuantity_destroy(MapInterpretationContextQuantityHandle handle);
// @category:write
void MapInterpretationContextQuantity_insert_or_assign(MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key, QuantityHandle value);
// @category:write
void MapInterpretationContextQuantity_insert(MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key, QuantityHandle value);
// @category:read
QuantityHandle MapInterpretationContextQuantity_at(MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key);
// @category:write
void MapInterpretationContextQuantity_erase(MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key);
// @category:read
size_t MapInterpretationContextQuantity_size(MapInterpretationContextQuantityHandle handle);
// @category:read
bool MapInterpretationContextQuantity_empty(MapInterpretationContextQuantityHandle handle);
// @category:write
void MapInterpretationContextQuantity_clear(MapInterpretationContextQuantityHandle handle);
// @category:read
bool MapInterpretationContextQuantity_contains(MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key);
// @category:read
ListInterpretationContextHandle MapInterpretationContextQuantity_keys(MapInterpretationContextQuantityHandle handle);
// @category:read
ListQuantityHandle MapInterpretationContextQuantity_values(MapInterpretationContextQuantityHandle handle);
// @category:read
ListPairInterpretationContextQuantityHandle MapInterpretationContextQuantity_items(MapInterpretationContextQuantityHandle handle);
// @category:read
bool MapInterpretationContextQuantity_equal(MapInterpretationContextQuantityHandle handle, MapInterpretationContextQuantityHandle other);
// @category:read
bool MapInterpretationContextQuantity_not_equal(MapInterpretationContextQuantityHandle handle, MapInterpretationContextQuantityHandle other);
// @category:read
StringHandle      MapInterpretationContextQuantity_to_json_string(MapInterpretationContextQuantityHandle handle);
// @category:allocation
MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


