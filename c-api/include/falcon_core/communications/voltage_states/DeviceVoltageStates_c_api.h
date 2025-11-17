#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/ListDeviceVoltageState_c_api.h"
#include "falcon_core/math/Point_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
typedef void* DeviceVoltageStatesHandle;

// Constructors
DeviceVoltageStatesHandle DeviceVoltageStates_create_empty();
DeviceVoltageStatesHandle DeviceVoltageStates_create(
    ListDeviceVoltageStateHandle items);

// Destructor
void DeviceVoltageStates_destroy(DeviceVoltageStatesHandle handle);

// Methods
ListDeviceVoltageStateHandle DeviceVoltageStates_states(
    DeviceVoltageStatesHandle handle);
void DeviceVoltageStates_add_state(DeviceVoltageStatesHandle handle,
                                   DeviceVoltageStateHandle  state);
DeviceVoltageStatesHandle DeviceVoltageStates_find_state(
    DeviceVoltageStatesHandle handle, ConnectionHandle connection);
PointHandle DeviceVoltageStates_to_point(DeviceVoltageStatesHandle handle);
DeviceVoltageStatesHandle DeviceVoltageStates_intersection(
    DeviceVoltageStatesHandle handle, DeviceVoltageStatesHandle other);
void   DeviceVoltageStates_push_back(DeviceVoltageStatesHandle handle,
                                     DeviceVoltageStateHandle  value);
size_t DeviceVoltageStates_size(DeviceVoltageStatesHandle handle);
bool   DeviceVoltageStates_empty(DeviceVoltageStatesHandle handle);
void DeviceVoltageStates_erase_at(DeviceVoltageStatesHandle handle, size_t idx);
void DeviceVoltageStates_clear(DeviceVoltageStatesHandle handle);
const DeviceVoltageStateHandle DeviceVoltageStates_const_at(
    DeviceVoltageStatesHandle handle, size_t idx);
DeviceVoltageStateHandle DeviceVoltageStates_at(
    DeviceVoltageStatesHandle handle, size_t idx);
ListDeviceVoltageStateHandle DeviceVoltageStates_items(
    DeviceVoltageStatesHandle handle);
bool   DeviceVoltageStates_contains(DeviceVoltageStatesHandle handle,
                                    DeviceVoltageStateHandle  value);
size_t DeviceVoltageStates_index(DeviceVoltageStatesHandle handle,
                                 DeviceVoltageStateHandle  value);
bool   DeviceVoltageStates_equal(DeviceVoltageStatesHandle a,
                                 DeviceVoltageStatesHandle b);
bool   DeviceVoltageStates_not_equal(DeviceVoltageStatesHandle a,
                                     DeviceVoltageStatesHandle b);

// Serialization (from Song)
StringHandle DeviceVoltageStates_to_json_string(
    DeviceVoltageStatesHandle handle);
DeviceVoltageStatesHandle DeviceVoltageStates_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
