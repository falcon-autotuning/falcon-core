#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/communications/voltage_states/DeviceVoltageState_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListDeviceVoltageStateHandle;
// Function declarations

ListDeviceVoltageStateHandle ListDeviceVoltageState_create_empty();

ListDeviceVoltageStateHandle ListDeviceVoltageState_fill_value(size_t count, DeviceVoltageStateHandle value);
ListDeviceVoltageStateHandle ListDeviceVoltageState_create(DeviceVoltageStateHandle* data, size_t count);
void ListDeviceVoltageState_destroy(ListDeviceVoltageStateHandle handle);
void ListDeviceVoltageState_push_back(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle value);
size_t ListDeviceVoltageState_size(ListDeviceVoltageStateHandle handle);
bool ListDeviceVoltageState_empty(ListDeviceVoltageStateHandle handle);
void ListDeviceVoltageState_erase_at(ListDeviceVoltageStateHandle handle, size_t idx);
void ListDeviceVoltageState_clear(ListDeviceVoltageStateHandle handle);
DeviceVoltageStateHandle ListDeviceVoltageState_at(ListDeviceVoltageStateHandle handle, size_t idx);
size_t ListDeviceVoltageState_items(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle* out_buffer, size_t buffer_size);
bool ListDeviceVoltageState_contains(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle value);
size_t ListDeviceVoltageState_index(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle value);
ListDeviceVoltageStateHandle ListDeviceVoltageState_intersection(ListDeviceVoltageStateHandle handle, ListDeviceVoltageStateHandle other);
bool ListDeviceVoltageState_equal(ListDeviceVoltageStateHandle a, ListDeviceVoltageStateHandle b);
bool ListDeviceVoltageState_not_equal(ListDeviceVoltageStateHandle a, ListDeviceVoltageStateHandle b);

// Serialization (from Song)
StringHandle      ListDeviceVoltageState_to_json_string(ListDeviceVoltageStateHandle handle);
ListDeviceVoltageStateHandle ListDeviceVoltageState_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif