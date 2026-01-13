

# File VoltageStatesResponse\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**communications**](dir_333323e88b5d6263154607a1eb6b024f.md) **>** [**messages**](dir_b9b9af6e426ae6e63b9b7113e9a16e28.md) **>** [**VoltageStatesResponse\_c\_api.h**](VoltageStatesResponse__c__api_8h.md)

[Go to the documentation of this file](VoltageStatesResponse__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/communications/voltage_states/DeviceVoltageStates_c_api.h"
#include "falcon_core/generic/String_c_api.h"
typedef void* VoltageStatesResponseHandle;

// @category:allocation
VoltageStatesResponseHandle VoltageStatesResponse_copy(
    VoltageStatesResponseHandle handle);
// @category:deallocation
void VoltageStatesResponse_destroy(VoltageStatesResponseHandle handle);
// @category:read
bool VoltageStatesResponse_equal(VoltageStatesResponseHandle handle,
                                 VoltageStatesResponseHandle other);
// @category:read
bool VoltageStatesResponse_not_equal(VoltageStatesResponseHandle handle,
                                     VoltageStatesResponseHandle other);
// @category:read
StringHandle VoltageStatesResponse_to_json_string(
    VoltageStatesResponseHandle handle);
// @category:allocation
VoltageStatesResponseHandle VoltageStatesResponse_from_json_string(
    StringHandle json);
// @category:allocation
VoltageStatesResponseHandle VoltageStatesResponse_create(
    StringHandle message, DeviceVoltageStatesHandle states);
// @category:read
StringHandle VoltageStatesResponse_message(VoltageStatesResponseHandle handle);
// @category:read
DeviceVoltageStatesHandle VoltageStatesResponse_states(
    VoltageStatesResponseHandle handle);

#ifdef __cplusplus
}
#endif
```


