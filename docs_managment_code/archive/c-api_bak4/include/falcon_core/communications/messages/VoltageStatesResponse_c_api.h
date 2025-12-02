#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/communications/voltage_states/DeviceVoltageStates_c_api.h"
#include "falcon_core/generic/String_c_api.h"
typedef void* VoltageStatesResponseHandle;

// @category:allocation
VoltageStatesResponseHandle VoltageStatesResponse_create(
    StringHandle message, DeviceVoltageStatesHandle states);
// @category:deallocation
void VoltageStatesResponse_destroy(VoltageStatesResponseHandle handle);
// @category:read
StringHandle VoltageStatesResponse_message(VoltageStatesResponseHandle handle);
// @category:read
DeviceVoltageStatesHandle VoltageStatesResponse_states(
    VoltageStatesResponseHandle handle);
// @category:read
bool VoltageStatesResponse_equal(VoltageStatesResponseHandle handle,
                                 VoltageStatesResponseHandle other);
// @category:read
bool VoltageStatesResponse_not_equal(VoltageStatesResponseHandle handle,
                                     VoltageStatesResponseHandle other);
// @category:read
StringHandle VoltageStatesResponse_to_json_string(
    VoltageStatesResponseHandle handle);
// @category:allocation
VoltageStatesResponseHandle VoltageStatesResponse_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
