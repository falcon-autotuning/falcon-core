#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#include "falcon_core/export_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
typedef void* DeviceVoltageStateHandle;

// @category:allocation
FALCON_CORE_C_API DeviceVoltageStateHandle DeviceVoltageState_create(
    ConnectionHandle connection, double voltage, SymbolUnitHandle unit);
// @category:deallocation
FALCON_CORE_C_API void DeviceVoltageState_destroy(
    DeviceVoltageStateHandle handle);
// @category:read
FALCON_CORE_C_API ConnectionHandle
DeviceVoltageState_connection(DeviceVoltageStateHandle handle);
// @category:read
FALCON_CORE_C_API double DeviceVoltageState_voltage(
    DeviceVoltageStateHandle handle);
// @category:read
FALCON_CORE_C_API double DeviceVoltageState_value(
    DeviceVoltageStateHandle handle);
// @category:read
FALCON_CORE_C_API SymbolUnitHandle
DeviceVoltageState_unit(DeviceVoltageStateHandle handle);
// @category:write
FALCON_CORE_C_API void DeviceVoltageState_convert_to(
    DeviceVoltageStateHandle handle, SymbolUnitHandle target_unit);
// @category:read
FALCON_CORE_C_API DeviceVoltageStateHandle
DeviceVoltageState_multiply_int(DeviceVoltageStateHandle handle, int other);
// @category:read
FALCON_CORE_C_API DeviceVoltageStateHandle DeviceVoltageState_multiply_double(
    DeviceVoltageStateHandle handle, double other);
// @category:read
FALCON_CORE_C_API DeviceVoltageStateHandle DeviceVoltageState_multiply_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other);
// @category:write
FALCON_CORE_C_API DeviceVoltageStateHandle
DeviceVoltageState_multiply_equals_int(DeviceVoltageStateHandle handle,
                                       int                      other);
// @category:write
FALCON_CORE_C_API DeviceVoltageStateHandle
DeviceVoltageState_multiply_equals_double(DeviceVoltageStateHandle handle,
                                          double                   other);
// @category:write
FALCON_CORE_C_API DeviceVoltageStateHandle
DeviceVoltageState_multiply_equals_quantity(DeviceVoltageStateHandle handle,
                                            DeviceVoltageStateHandle other);
// @category:read
FALCON_CORE_C_API DeviceVoltageStateHandle
DeviceVoltageState_divide_int(DeviceVoltageStateHandle handle, int other);
// @category:read
FALCON_CORE_C_API DeviceVoltageStateHandle
DeviceVoltageState_divide_double(DeviceVoltageStateHandle handle, double other);
// @category:read
FALCON_CORE_C_API DeviceVoltageStateHandle DeviceVoltageState_divide_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other);
// @category:write
FALCON_CORE_C_API DeviceVoltageStateHandle DeviceVoltageState_divide_equals_int(
    DeviceVoltageStateHandle handle, int other);
// @category:write
FALCON_CORE_C_API DeviceVoltageStateHandle
DeviceVoltageState_divide_equals_double(DeviceVoltageStateHandle handle,
                                        double                   other);
// @category:write
FALCON_CORE_C_API DeviceVoltageStateHandle
DeviceVoltageState_divide_equals_quantity(DeviceVoltageStateHandle handle,
                                          DeviceVoltageStateHandle other);
// @category:read
FALCON_CORE_C_API DeviceVoltageStateHandle
DeviceVoltageState_power(DeviceVoltageStateHandle handle, int other);
// @category:read
FALCON_CORE_C_API DeviceVoltageStateHandle DeviceVoltageState_add_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other);
// @category:write
FALCON_CORE_C_API DeviceVoltageStateHandle
DeviceVoltageState_add_equals_quantity(DeviceVoltageStateHandle handle,
                                       DeviceVoltageStateHandle other);
// @category:read
FALCON_CORE_C_API DeviceVoltageStateHandle DeviceVoltageState_subtract_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other);
// @category:write
FALCON_CORE_C_API DeviceVoltageStateHandle
DeviceVoltageState_subtract_equals_quantity(DeviceVoltageStateHandle handle,
                                            DeviceVoltageStateHandle other);
// @category:read
FALCON_CORE_C_API DeviceVoltageStateHandle
DeviceVoltageState_negate(DeviceVoltageStateHandle handle);
// @category:read
FALCON_CORE_C_API DeviceVoltageStateHandle
DeviceVoltageState_abs(DeviceVoltageStateHandle handle);
// @category:read
FALCON_CORE_C_API bool DeviceVoltageState_equal(DeviceVoltageStateHandle a,
                                                DeviceVoltageStateHandle b);
// @category:read
FALCON_CORE_C_API bool DeviceVoltageState_not_equal(DeviceVoltageStateHandle a,
                                                    DeviceVoltageStateHandle b);
// @category:read
FALCON_CORE_C_API StringHandle
DeviceVoltageState_to_json_string(DeviceVoltageStateHandle handle);
// @category:allocation
FALCON_CORE_C_API DeviceVoltageStateHandle
DeviceVoltageState_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
