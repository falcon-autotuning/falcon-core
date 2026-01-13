

# File ListMeasurementContext\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListMeasurementContext\_c\_api.h**](ListMeasurementContext__c__api_8h.md)

[Go to the documentation of this file](ListMeasurementContext__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListMeasurementContextHandle;
// Function declarations

// @category:allocation
ListMeasurementContextHandle ListMeasurementContext_create_empty();
// @category:allocation
ListMeasurementContextHandle ListMeasurementContext_copy(ListMeasurementContextHandle handle);

// @category:allocation
ListMeasurementContextHandle ListMeasurementContext_fill_value(size_t count, MeasurementContextHandle value);
// @category:allocation
ListMeasurementContextHandle ListMeasurementContext_create(MeasurementContextHandle* data, size_t count);
// @category:deallocation
void ListMeasurementContext_destroy(ListMeasurementContextHandle handle);
// @category:write
void ListMeasurementContext_push_back(ListMeasurementContextHandle handle, MeasurementContextHandle value);
// @category:read
size_t ListMeasurementContext_size(ListMeasurementContextHandle handle);
// @category:read
bool ListMeasurementContext_empty(ListMeasurementContextHandle handle);
// @category:write
void ListMeasurementContext_erase_at(ListMeasurementContextHandle handle, size_t idx);
// @category:write
void ListMeasurementContext_clear(ListMeasurementContextHandle handle);
// @category:read
MeasurementContextHandle ListMeasurementContext_at(ListMeasurementContextHandle handle, size_t idx);
// @category:read
size_t ListMeasurementContext_items(ListMeasurementContextHandle handle, MeasurementContextHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListMeasurementContext_contains(ListMeasurementContextHandle handle, MeasurementContextHandle value);
// @category:read
size_t ListMeasurementContext_index(ListMeasurementContextHandle handle, MeasurementContextHandle value);
// @category:read
ListMeasurementContextHandle ListMeasurementContext_intersection(ListMeasurementContextHandle handle, ListMeasurementContextHandle other);
// @category:read
bool ListMeasurementContext_equal(ListMeasurementContextHandle handle, ListMeasurementContextHandle other);
// @category:read
bool ListMeasurementContext_not_equal(ListMeasurementContextHandle handle, ListMeasurementContextHandle other);

// @category:read
StringHandle      ListMeasurementContext_to_json_string(ListMeasurementContextHandle handle);
// @category:allocation
ListMeasurementContextHandle ListMeasurementContext_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


