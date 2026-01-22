

# File LeftReservoirWithImplantedOhmic\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**config**](dir_581a120aab54b5f137a62afb53b974b4.md) **>** [**geometries**](dir_1d88f50ca6512fed7187c162c771cfa6.md) **>** [**LeftReservoirWithImplantedOhmic\_c\_api.h**](LeftReservoirWithImplantedOhmic__c__api_8h.md)

[Go to the documentation of this file](LeftReservoirWithImplantedOhmic__c__api_8h.md)


```C++
#pragma once
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* LeftReservoirWithImplantedOhmicHandle;

// @category:allocation
LeftReservoirWithImplantedOhmicHandle LeftReservoirWithImplantedOhmic_copy(
    LeftReservoirWithImplantedOhmicHandle handle);
// @category:deallocation
void LeftReservoirWithImplantedOhmic_destroy(
    LeftReservoirWithImplantedOhmicHandle handle);
// @category:read
bool LeftReservoirWithImplantedOhmic_equal(
    LeftReservoirWithImplantedOhmicHandle handle,
    LeftReservoirWithImplantedOhmicHandle other);
// @category:read
bool LeftReservoirWithImplantedOhmic_not_equal(
    LeftReservoirWithImplantedOhmicHandle handle,
    LeftReservoirWithImplantedOhmicHandle other);
// @category:read
StringHandle LeftReservoirWithImplantedOhmic_to_json_string(
    LeftReservoirWithImplantedOhmicHandle handle);
// @category:allocation
LeftReservoirWithImplantedOhmicHandle
LeftReservoirWithImplantedOhmic_from_json_string(StringHandle json);
// @category:allocation
LeftReservoirWithImplantedOhmicHandle LeftReservoirWithImplantedOhmic_create(
    StringHandle name, ConnectionHandle right_neighbor, ConnectionHandle ohmic);
// @category:read
StringHandle LeftReservoirWithImplantedOhmic_name(
    LeftReservoirWithImplantedOhmicHandle handle);
// @category:read
StringHandle LeftReservoirWithImplantedOhmic_type(
    LeftReservoirWithImplantedOhmicHandle handle);
// @category:read
ConnectionHandle LeftReservoirWithImplantedOhmic_ohmic(
    LeftReservoirWithImplantedOhmicHandle handle);
// @category:read
ConnectionHandle LeftReservoirWithImplantedOhmic_right_neighbor(
    LeftReservoirWithImplantedOhmicHandle handle);
#ifdef __cplusplus
}
#endif
```


