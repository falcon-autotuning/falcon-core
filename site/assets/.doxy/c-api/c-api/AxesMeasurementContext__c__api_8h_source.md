

# File AxesMeasurementContext\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesMeasurementContext\_c\_api.h**](AxesMeasurementContext__c__api_8h.md)

[Go to the documentation of this file](AxesMeasurementContext__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext_c_api.h"
#include "falcon_core/generic/ListMeasurementContext_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesMeasurementContextHandle;
// Function declarations

// @category:allocation
AxesMeasurementContextHandle AxesMeasurementContext_create_empty();
// @category:allocation
AxesMeasurementContextHandle AxesMeasurementContext_copy(AxesMeasurementContextHandle handle);
// @category:allocation
AxesMeasurementContextHandle AxesMeasurementContext_create(ListMeasurementContextHandle data);
// @category:deallocation
void AxesMeasurementContext_destroy(AxesMeasurementContextHandle handle);
// @category:write
void AxesMeasurementContext_push_back(AxesMeasurementContextHandle handle, MeasurementContextHandle value);
// @category:read
size_t AxesMeasurementContext_size(AxesMeasurementContextHandle handle);
// @category:read
bool AxesMeasurementContext_empty(AxesMeasurementContextHandle handle);
// @category:write
void AxesMeasurementContext_erase_at(AxesMeasurementContextHandle handle, size_t idx);
// @category:write
void AxesMeasurementContext_clear(AxesMeasurementContextHandle handle);
// @category:read
MeasurementContextHandle AxesMeasurementContext_at(AxesMeasurementContextHandle handle, size_t idx);
// @category:read
size_t AxesMeasurementContext_items(AxesMeasurementContextHandle handle, MeasurementContextHandle* out_buffer, size_t buffer_size);
// @category:read
bool AxesMeasurementContext_contains(AxesMeasurementContextHandle handle, MeasurementContextHandle value);
// @category:read
size_t AxesMeasurementContext_index(AxesMeasurementContextHandle handle, MeasurementContextHandle value);
// @category:read
AxesMeasurementContextHandle AxesMeasurementContext_intersection(AxesMeasurementContextHandle handle, AxesMeasurementContextHandle other);
// @category:read
bool AxesMeasurementContext_equal(AxesMeasurementContextHandle handle, AxesMeasurementContextHandle other);
// @category:read
bool AxesMeasurementContext_not_equal(AxesMeasurementContextHandle handle, AxesMeasurementContextHandle other);

// @category:read
StringHandle      AxesMeasurementContext_to_json_string(AxesMeasurementContextHandle handle);
// @category:allocation
AxesMeasurementContextHandle AxesMeasurementContext_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


