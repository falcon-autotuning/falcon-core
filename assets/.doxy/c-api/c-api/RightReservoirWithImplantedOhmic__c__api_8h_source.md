

# File RightReservoirWithImplantedOhmic\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**config**](dir_581a120aab54b5f137a62afb53b974b4.md) **>** [**geometries**](dir_1d88f50ca6512fed7187c162c771cfa6.md) **>** [**RightReservoirWithImplantedOhmic\_c\_api.h**](RightReservoirWithImplantedOhmic__c__api_8h.md)

[Go to the documentation of this file](RightReservoirWithImplantedOhmic__c__api_8h.md)


```C++
#pragma once
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* RightReservoirWithImplantedOhmicHandle;

// @category:allocation
RightReservoirWithImplantedOhmicHandle RightReservoirWithImplantedOhmic_copy(
    RightReservoirWithImplantedOhmicHandle handle);
// @category:deallocation
void RightReservoirWithImplantedOhmic_destroy(
    RightReservoirWithImplantedOhmicHandle handle);
// @category:read
bool RightReservoirWithImplantedOhmic_equal(
    RightReservoirWithImplantedOhmicHandle handle,
    RightReservoirWithImplantedOhmicHandle other);
// @category:read
bool RightReservoirWithImplantedOhmic_not_equal(
    RightReservoirWithImplantedOhmicHandle handle,
    RightReservoirWithImplantedOhmicHandle other);
// @category:read
StringHandle RightReservoirWithImplantedOhmic_to_json_string(
    RightReservoirWithImplantedOhmicHandle handle);
// @category:allocation
RightReservoirWithImplantedOhmicHandle
RightReservoirWithImplantedOhmic_from_json_string(StringHandle json);
// @category:allocation
RightReservoirWithImplantedOhmicHandle RightReservoirWithImplantedOhmic_create(
    StringHandle name, ConnectionHandle left_neighbor, ConnectionHandle ohmic);
// @category:read
StringHandle RightReservoirWithImplantedOhmic_name(
    RightReservoirWithImplantedOhmicHandle handle);
// @category:read
StringHandle RightReservoirWithImplantedOhmic_type(
    RightReservoirWithImplantedOhmicHandle handle);
// @category:read
ConnectionHandle RightReservoirWithImplantedOhmic_ohmic(
    RightReservoirWithImplantedOhmicHandle handle);
// @category:read
ConnectionHandle RightReservoirWithImplantedOhmic_left_neighbor(
    RightReservoirWithImplantedOhmicHandle handle);
#ifdef __cplusplus
}
#endif
```


