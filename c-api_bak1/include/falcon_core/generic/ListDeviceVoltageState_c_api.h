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

ListDeviceVoltageStateHandle ListDeviceVoltageState_create_empty();

ListDeviceVoltageStateHandle ListDeviceVoltageState_fill_value(size_t count, DeviceVoltageStateHandle value);
ListDeviceVoltageStateHandle ListDeviceVoltageState_create(DeviceVoltageStateHandle* data, size_t count);
void ListDeviceVoltageState_destroy(ListDeviceVoltageStateHandle handle);
void ListDeviceVoltageState_push_back(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle value);
size_t ListDeviceVoltageState_size(ListDeviceVoltageStateHandle handle);
bool ListDeviceVoltageState_empty(ListDeviceVoltageStateHandle handle);
/* AUTO-DOC from cpp: ListDeviceVoltageState_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListDeviceVoltageState_erase_at(ListDeviceVoltageStateHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListDeviceVoltageState_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListDeviceVoltageState_clear(ListDeviceVoltageStateHandle handle);
DeviceVoltageStateHandle ListDeviceVoltageState_at(ListDeviceVoltageStateHandle handle, size_t idx);
size_t ListDeviceVoltageState_items(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle* out_buffer, size_t buffer_size);
bool ListDeviceVoltageState_contains(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle value);
size_t ListDeviceVoltageState_index(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle value);
/* AUTO-DOC from cpp: ListDeviceVoltageState_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListDeviceVoltageStateHandle ListDeviceVoltageState_intersection(ListDeviceVoltageStateHandle handle, ListDeviceVoltageStateHandle other);
bool ListDeviceVoltageState_equal(ListDeviceVoltageStateHandle a, ListDeviceVoltageStateHandle b);
bool ListDeviceVoltageState_not_equal(ListDeviceVoltageStateHandle a, ListDeviceVoltageStateHandle b);

// Serialization (from Song)
/* AUTO-DOC from cpp: ListDeviceVoltageState_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      ListDeviceVoltageState_to_json_string(ListDeviceVoltageStateHandle handle);
/* AUTO-DOC from cpp: ListDeviceVoltageState_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
ListDeviceVoltageStateHandle ListDeviceVoltageState_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif