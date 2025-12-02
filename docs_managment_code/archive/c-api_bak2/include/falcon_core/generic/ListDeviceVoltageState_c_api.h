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
/* AUTO-DOC from cpp: ListDeviceVoltageState_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListDeviceVoltageState_erase_at(ListDeviceVoltageStateHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListDeviceVoltageState_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
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
/* AUTO-DOC from cpp: ListDeviceVoltageState_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListDeviceVoltageStateHandle ListDeviceVoltageState_intersection(ListDeviceVoltageStateHandle handle, ListDeviceVoltageStateHandle other);
// @category:read
bool ListDeviceVoltageState_equal(ListDeviceVoltageStateHandle a, ListDeviceVoltageStateHandle b);
// @category:read
bool ListDeviceVoltageState_not_equal(ListDeviceVoltageStateHandle a, ListDeviceVoltageStateHandle b);

// @category:read
StringHandle      ListDeviceVoltageState_to_json_string(ListDeviceVoltageStateHandle handle);
// @category:allocation
ListDeviceVoltageStateHandle ListDeviceVoltageState_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif