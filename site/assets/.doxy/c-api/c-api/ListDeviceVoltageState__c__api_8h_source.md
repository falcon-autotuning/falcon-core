

# File ListDeviceVoltageState\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListDeviceVoltageState\_c\_api.h**](ListDeviceVoltageState__c__api_8h.md)

[Go to the documentation of this file](ListDeviceVoltageState__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/communications/voltage_states/DeviceVoltageState_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListDeviceVoltageStateHandle;
// Function declarations

// @category:allocation
ListDeviceVoltageStateHandle ListDeviceVoltageState_create_empty();
// @category:allocation
ListDeviceVoltageStateHandle ListDeviceVoltageState_copy(ListDeviceVoltageStateHandle handle);

// @category:allocation
ListDeviceVoltageStateHandle ListDeviceVoltageState_fill_value(size_t count, DeviceVoltageStateHandle value);
// @category:allocation
ListDeviceVoltageStateHandle ListDeviceVoltageState_create(DeviceVoltageStateHandle* data, size_t count);
// @category:deallocation
void ListDeviceVoltageState_destroy(ListDeviceVoltageStateHandle handle);
// @category:write
void ListDeviceVoltageState_push_back(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle value);
// @category:read
size_t ListDeviceVoltageState_size(ListDeviceVoltageStateHandle handle);
// @category:read
bool ListDeviceVoltageState_empty(ListDeviceVoltageStateHandle handle);
// @category:write
void ListDeviceVoltageState_erase_at(ListDeviceVoltageStateHandle handle, size_t idx);
// @category:write
void ListDeviceVoltageState_clear(ListDeviceVoltageStateHandle handle);
// @category:read
DeviceVoltageStateHandle ListDeviceVoltageState_at(ListDeviceVoltageStateHandle handle, size_t idx);
// @category:read
size_t ListDeviceVoltageState_items(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListDeviceVoltageState_contains(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle value);
// @category:read
size_t ListDeviceVoltageState_index(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle value);
// @category:read
ListDeviceVoltageStateHandle ListDeviceVoltageState_intersection(ListDeviceVoltageStateHandle handle, ListDeviceVoltageStateHandle other);
// @category:read
bool ListDeviceVoltageState_equal(ListDeviceVoltageStateHandle handle, ListDeviceVoltageStateHandle other);
// @category:read
bool ListDeviceVoltageState_not_equal(ListDeviceVoltageStateHandle handle, ListDeviceVoltageStateHandle other);

// @category:read
StringHandle      ListDeviceVoltageState_to_json_string(ListDeviceVoltageStateHandle handle);
// @category:allocation
ListDeviceVoltageStateHandle ListDeviceVoltageState_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


