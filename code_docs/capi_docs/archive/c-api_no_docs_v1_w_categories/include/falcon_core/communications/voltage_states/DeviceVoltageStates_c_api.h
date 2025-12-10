#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/ListDeviceVoltageState_c_api.h"
#include "falcon_core/math/Point_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
typedef void* DeviceVoltageStatesHandle;

// @category:allocation
DeviceVoltageStatesHandle DeviceVoltageStates_create_empty();
// @category:allocation
DeviceVoltageStatesHandle DeviceVoltageStates_create(
    ListDeviceVoltageStateHandle items);
// @category:deallocation
void DeviceVoltageStates_destroy(DeviceVoltageStatesHandle handle);
// @category:read
ListDeviceVoltageStateHandle DeviceVoltageStates_states(
    DeviceVoltageStatesHandle handle);
// @category:write
void DeviceVoltageStates_add_state(DeviceVoltageStatesHandle handle,
                                   DeviceVoltageStateHandle  state);
// @category:read
DeviceVoltageStatesHandle DeviceVoltageStates_find_state(
    DeviceVoltageStatesHandle handle, ConnectionHandle connection);
// @category:read
PointHandle DeviceVoltageStates_to_point(DeviceVoltageStatesHandle handle);
// @category:read
DeviceVoltageStatesHandle DeviceVoltageStates_intersection(
    DeviceVoltageStatesHandle handle, DeviceVoltageStatesHandle other);
// @category:write
void DeviceVoltageStates_push_back(DeviceVoltageStatesHandle handle,
                                   DeviceVoltageStateHandle  value);
// @category:read
size_t DeviceVoltageStates_size(DeviceVoltageStatesHandle handle);
// @category:read
bool DeviceVoltageStates_empty(DeviceVoltageStatesHandle handle);
// @category:write
void DeviceVoltageStates_erase_at(DeviceVoltageStatesHandle handle, size_t idx);
// @category:write
void DeviceVoltageStates_clear(DeviceVoltageStatesHandle handle);
// @category:read
DeviceVoltageStateHandle DeviceVoltageStates_at(
    DeviceVoltageStatesHandle handle, size_t idx);
// @category:read
ListDeviceVoltageStateHandle DeviceVoltageStates_items(
    DeviceVoltageStatesHandle handle);
// @category:read
bool DeviceVoltageStates_contains(DeviceVoltageStatesHandle handle,
                                  DeviceVoltageStateHandle  value);
// @category:read
size_t DeviceVoltageStates_index(DeviceVoltageStatesHandle handle,
                                 DeviceVoltageStateHandle  value);
// @category:read
bool DeviceVoltageStates_equal(DeviceVoltageStatesHandle a,
                               DeviceVoltageStatesHandle b);
// @category:read
bool DeviceVoltageStates_not_equal(DeviceVoltageStatesHandle a,
                                   DeviceVoltageStatesHandle b);
// @category:read
StringHandle DeviceVoltageStates_to_json_string(
    DeviceVoltageStatesHandle handle);
// @category:allocation
DeviceVoltageStatesHandle DeviceVoltageStates_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
