

# File ListPairQuantityQuantity\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairQuantityQuantity\_c\_api.h**](ListPairQuantityQuantity__c__api_8h.md)

[Go to the documentation of this file](ListPairQuantityQuantity__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairQuantityQuantity_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairQuantityQuantityHandle;
// Function declarations

// @category:allocation
ListPairQuantityQuantityHandle ListPairQuantityQuantity_create_empty();
// @category:allocation
ListPairQuantityQuantityHandle ListPairQuantityQuantity_copy(ListPairQuantityQuantityHandle handle);

// @category:allocation
ListPairQuantityQuantityHandle ListPairQuantityQuantity_fill_value(size_t count, PairQuantityQuantityHandle value);
// @category:allocation
ListPairQuantityQuantityHandle ListPairQuantityQuantity_create(PairQuantityQuantityHandle* data, size_t count);
// @category:deallocation
void ListPairQuantityQuantity_destroy(ListPairQuantityQuantityHandle handle);
// @category:write
void ListPairQuantityQuantity_push_back(ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle value);
// @category:read
size_t ListPairQuantityQuantity_size(ListPairQuantityQuantityHandle handle);
// @category:read
bool ListPairQuantityQuantity_empty(ListPairQuantityQuantityHandle handle);
// @category:write
void ListPairQuantityQuantity_erase_at(ListPairQuantityQuantityHandle handle, size_t idx);
// @category:write
void ListPairQuantityQuantity_clear(ListPairQuantityQuantityHandle handle);
// @category:read
PairQuantityQuantityHandle ListPairQuantityQuantity_at(ListPairQuantityQuantityHandle handle, size_t idx);
// @category:read
size_t ListPairQuantityQuantity_items(ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPairQuantityQuantity_contains(ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle value);
// @category:read
size_t ListPairQuantityQuantity_index(ListPairQuantityQuantityHandle handle, PairQuantityQuantityHandle value);
// @category:read
ListPairQuantityQuantityHandle ListPairQuantityQuantity_intersection(ListPairQuantityQuantityHandle handle, ListPairQuantityQuantityHandle other);
// @category:read
bool ListPairQuantityQuantity_equal(ListPairQuantityQuantityHandle handle, ListPairQuantityQuantityHandle other);
// @category:read
bool ListPairQuantityQuantity_not_equal(ListPairQuantityQuantityHandle handle, ListPairQuantityQuantityHandle other);

// @category:read
StringHandle      ListPairQuantityQuantity_to_json_string(ListPairQuantityQuantityHandle handle);
// @category:allocation
ListPairQuantityQuantityHandle ListPairQuantityQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


