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
FALCON_CORE_C_API ListDeviceVoltageStateHandle ListDeviceVoltageState_create_empty();
// @category:allocation
FALCON_CORE_C_API ListDeviceVoltageStateHandle ListDeviceVoltageState_copy(ListDeviceVoltageStateHandle handle);

// @category:allocation
FALCON_CORE_C_API ListDeviceVoltageStateHandle ListDeviceVoltageState_fill_value(size_t count, DeviceVoltageStateHandle value);
// @category:allocation
FALCON_CORE_C_API ListDeviceVoltageStateHandle ListDeviceVoltageState_create(DeviceVoltageStateHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListDeviceVoltageState_destroy(ListDeviceVoltageStateHandle handle);
// @category:write
FALCON_CORE_C_API void ListDeviceVoltageState_push_back(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle value);
// @category:read
FALCON_CORE_C_API size_t ListDeviceVoltageState_size(ListDeviceVoltageStateHandle handle);
// @category:read
FALCON_CORE_C_API bool ListDeviceVoltageState_empty(ListDeviceVoltageStateHandle handle);
// @category:write
FALCON_CORE_C_API void ListDeviceVoltageState_erase_at(ListDeviceVoltageStateHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListDeviceVoltageState_clear(ListDeviceVoltageStateHandle handle);
// @category:read
FALCON_CORE_C_API DeviceVoltageStateHandle ListDeviceVoltageState_at(ListDeviceVoltageStateHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListDeviceVoltageState_items(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListDeviceVoltageState_contains(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle value);
// @category:read
FALCON_CORE_C_API size_t ListDeviceVoltageState_index(ListDeviceVoltageStateHandle handle, DeviceVoltageStateHandle value);
// @category:read
FALCON_CORE_C_API ListDeviceVoltageStateHandle ListDeviceVoltageState_intersection(ListDeviceVoltageStateHandle handle, ListDeviceVoltageStateHandle other);
// @category:read
FALCON_CORE_C_API bool ListDeviceVoltageState_equal(ListDeviceVoltageStateHandle handle, ListDeviceVoltageStateHandle other);
// @category:read
FALCON_CORE_C_API bool ListDeviceVoltageState_not_equal(ListDeviceVoltageStateHandle handle, ListDeviceVoltageStateHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListDeviceVoltageState_to_json_string(ListDeviceVoltageStateHandle handle);
// @category:allocation
FALCON_CORE_C_API ListDeviceVoltageStateHandle ListDeviceVoltageState_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif