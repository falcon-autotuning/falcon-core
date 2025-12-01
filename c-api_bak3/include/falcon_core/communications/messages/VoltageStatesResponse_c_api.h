#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/communications/voltage_states/DeviceVoltageStates_c_api.h"
#include "falcon_core/generic/String_c_api.h"
typedef void* VoltageStatesResponseHandle;

// Constructors
VoltageStatesResponseHandle VoltageStatesResponse_create(
    StringHandle message, DeviceVoltageStatesHandle states);

// Destructor
void VoltageStatesResponse_destroy(VoltageStatesResponseHandle handle);

// Methods
StringHandle VoltageStatesResponse_message(VoltageStatesResponseHandle handle);
DeviceVoltageStatesHandle VoltageStatesResponse_states(
    VoltageStatesResponseHandle handle);
bool VoltageStatesResponse_equal(VoltageStatesResponseHandle handle,
                                 VoltageStatesResponseHandle other);
bool VoltageStatesResponse_not_equal(VoltageStatesResponseHandle handle,
                                     VoltageStatesResponseHandle other);

// Serialization (from Song)
StringHandle VoltageStatesResponse_to_json_string(
    VoltageStatesResponseHandle handle);
VoltageStatesResponseHandle VoltageStatesResponse_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
