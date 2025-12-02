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
/* AUTO-DOC from cpp: DeviceVoltageStates_states | falcon_core::communications::voltage_states::DeviceVoltageStates::states */
/**
 * @brief Returns the list of voltage states.
 */
ListDeviceVoltageStateHandle DeviceVoltageStates_states(
    DeviceVoltageStatesHandle handle);
// @category:write
/* AUTO-DOC from cpp: DeviceVoltageStates_add_state | falcon_core::communications::voltage_states::DeviceVoltageStates::add_state */
/**
 * @brief Add a voltage state to the collection.
 * @param state The voltage state to add.
 */
void DeviceVoltageStates_add_state(DeviceVoltageStatesHandle handle,
                                   DeviceVoltageStateHandle  state);
// @category:read
/* AUTO-DOC from cpp: DeviceVoltageStates_find_state | falcon_core::communications::voltage_states::DeviceVoltageStates::find_state */
/**
 * @brief Find a voltage state by its connection.
 * @param connection The connection to find.
 * @returns the voltage state if found.
 */
DeviceVoltageStatesHandle DeviceVoltageStates_find_state(
    DeviceVoltageStatesHandle handle, ConnectionHandle connection);
// @category:read
/* AUTO-DOC from cpp: DeviceVoltageStates_to_point | falcon_core::communications::voltage_states::DeviceVoltageStates::to_point */
/**
 * @brief Conversion to the Point datatype.
 */
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
