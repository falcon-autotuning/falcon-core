

# File MapInstrumentPortPortTransform\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapInstrumentPortPortTransform\_c\_api.h**](MapInstrumentPortPortTransform__c__api_8h.md)

[Go to the documentation of this file](MapInstrumentPortPortTransform__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairInstrumentPortPortTransform_c_api.h"
#include "falcon_core/generic/ListInstrumentPort_c_api.h"
#include "falcon_core/generic/ListPortTransform_c_api.h"
#include "falcon_core/generic/ListPairInstrumentPortPortTransform_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapInstrumentPortPortTransformHandle;
// Function declarations

// @category:allocation
MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_create_empty();
// @category:allocation
MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_copy(MapInstrumentPortPortTransformHandle handle);
// @category:allocation
MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_create(PairInstrumentPortPortTransformHandle* data, size_t count);
// @category:deallocation
void MapInstrumentPortPortTransform_destroy(MapInstrumentPortPortTransformHandle handle);
// @category:write
void MapInstrumentPortPortTransform_insert_or_assign(MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key, PortTransformHandle value);
// @category:write
void MapInstrumentPortPortTransform_insert(MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key, PortTransformHandle value);
// @category:read
PortTransformHandle MapInstrumentPortPortTransform_at(MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key);
// @category:write
void MapInstrumentPortPortTransform_erase(MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key);
// @category:read
size_t MapInstrumentPortPortTransform_size(MapInstrumentPortPortTransformHandle handle);
// @category:read
bool MapInstrumentPortPortTransform_empty(MapInstrumentPortPortTransformHandle handle);
// @category:write
void MapInstrumentPortPortTransform_clear(MapInstrumentPortPortTransformHandle handle);
// @category:read
bool MapInstrumentPortPortTransform_contains(MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key);
// @category:read
ListInstrumentPortHandle MapInstrumentPortPortTransform_keys(MapInstrumentPortPortTransformHandle handle);
// @category:read
ListPortTransformHandle MapInstrumentPortPortTransform_values(MapInstrumentPortPortTransformHandle handle);
// @category:read
ListPairInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_items(MapInstrumentPortPortTransformHandle handle);
// @category:read
bool MapInstrumentPortPortTransform_equal(MapInstrumentPortPortTransformHandle handle, MapInstrumentPortPortTransformHandle other);
// @category:read
bool MapInstrumentPortPortTransform_not_equal(MapInstrumentPortPortTransformHandle handle, MapInstrumentPortPortTransformHandle other);
// @category:read
StringHandle      MapInstrumentPortPortTransform_to_json_string(MapInstrumentPortPortTransformHandle handle);
// @category:allocation
MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


