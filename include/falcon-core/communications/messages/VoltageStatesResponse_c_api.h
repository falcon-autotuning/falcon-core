#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon-core/communications/voltage_states/DeviceVoltageStates_c_api.h"
#include "falcon-core/export_c_api.h"
#include "falcon-core/generic/String_c_api.h"
typedef void* VoltageStatesResponseHandle;

// @category:allocation
FALCON_CORE_C_API VoltageStatesResponseHandle
VoltageStatesResponse_copy(VoltageStatesResponseHandle handle);
// @category:deallocation
FALCON_CORE_C_API void VoltageStatesResponse_destroy(
    VoltageStatesResponseHandle handle);
// @category:read
FALCON_CORE_C_API bool VoltageStatesResponse_equal(
    VoltageStatesResponseHandle handle, VoltageStatesResponseHandle other);
// @category:read
FALCON_CORE_C_API bool VoltageStatesResponse_not_equal(
    VoltageStatesResponseHandle handle, VoltageStatesResponseHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
VoltageStatesResponse_to_json_string(VoltageStatesResponseHandle handle);
// @category:allocation
FALCON_CORE_C_API VoltageStatesResponseHandle
VoltageStatesResponse_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API VoltageStatesResponseHandle VoltageStatesResponse_create(
    StringHandle message, DeviceVoltageStatesHandle states);
// @category:read
FALCON_CORE_C_API StringHandle
VoltageStatesResponse_message(VoltageStatesResponseHandle handle);
// @category:read
FALCON_CORE_C_API DeviceVoltageStatesHandle
VoltageStatesResponse_states(VoltageStatesResponseHandle handle);

#ifdef __cplusplus
}
#endif
