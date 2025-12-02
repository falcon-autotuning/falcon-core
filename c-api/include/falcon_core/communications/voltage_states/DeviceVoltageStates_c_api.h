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
/* AUTO-DOC from cpp: DeviceVoltageStates_states | falcon_core::communications::voltage_states::DeviceVoltageStates::states */
/**
 * @brief Returns the list of voltage states.
 */
ListDeviceVoltageStateHandle DeviceVoltageStates_states(
    DeviceVoltageStatesHandle handle);
/* AUTO-DOC from cpp: DeviceVoltageStates_add_state | falcon_core::communications::voltage_states::DeviceVoltageStates::add_state */
/**
 * @brief Add a voltage state to the collection.
 * @param state The voltage state to add.
 */
void DeviceVoltageStates_add_state(DeviceVoltageStatesHandle handle,
                                   DeviceVoltageStateHandle  state);
/* AUTO-DOC from cpp: DeviceVoltageStates_find_state | falcon_core::communications::voltage_states::DeviceVoltageStates::find_state */
/**
 * @brief Find a voltage state by its connection.
 * @param connection The connection to find.
 * @returns the voltage state if found.
 */
DeviceVoltageStatesHandle DeviceVoltageStates_find_state(
    DeviceVoltageStatesHandle handle, ConnectionHandle connection);
/* AUTO-DOC from cpp: DeviceVoltageStates_to_point | falcon_core::communications::voltage_states::DeviceVoltageStates::to_point */
/**
 * @brief Conversion to the Point datatype.
 */
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
