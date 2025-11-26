#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
typedef void* DeviceVoltageStateHandle;

// @category:allocation
DeviceVoltageStateHandle DeviceVoltageState_create(ConnectionHandle connection,
                                                   double           voltage,
                                                   SymbolUnitHandle unit);
// @category:deallocation
void DeviceVoltageState_destroy(DeviceVoltageStateHandle handle);
// @category:read
ConnectionHandle DeviceVoltageState_connection(DeviceVoltageStateHandle handle);
// @category:read
double DeviceVoltageState_voltage(DeviceVoltageStateHandle handle);
// @category:read
double DeviceVoltageState_value(DeviceVoltageStateHandle handle);
// @category:read
SymbolUnitHandle DeviceVoltageState_unit(DeviceVoltageStateHandle handle);
// @category:write
void DeviceVoltageState_convert_to(DeviceVoltageStateHandle handle,
                                   SymbolUnitHandle         target_unit);
// @category:read
DeviceVoltageStateHandle DeviceVoltageState_multiply_int(
    DeviceVoltageStateHandle handle, int other);
// @category:read
DeviceVoltageStateHandle DeviceVoltageState_multiply_double(
    DeviceVoltageStateHandle handle, double other);
// @category:read
DeviceVoltageStateHandle DeviceVoltageState_multiply_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other);
// @category:write
DeviceVoltageStateHandle DeviceVoltageState_multiply_equals_int(
    DeviceVoltageStateHandle handle, int other);
// @category:write
DeviceVoltageStateHandle DeviceVoltageState_multiply_equals_double(
    DeviceVoltageStateHandle handle, double other);
// @category:write
DeviceVoltageStateHandle DeviceVoltageState_multiply_equals_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other);
// @category:read
DeviceVoltageStateHandle DeviceVoltageState_divide_int(
    DeviceVoltageStateHandle handle, int other);
// @category:read
DeviceVoltageStateHandle DeviceVoltageState_divide_double(
    DeviceVoltageStateHandle handle, double other);
// @category:read
DeviceVoltageStateHandle DeviceVoltageState_divide_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other);
// @category:write
DeviceVoltageStateHandle DeviceVoltageState_divide_equals_int(
    DeviceVoltageStateHandle handle, int other);
// @category:write
DeviceVoltageStateHandle DeviceVoltageState_divide_equals_double(
    DeviceVoltageStateHandle handle, double other);
// @category:write
DeviceVoltageStateHandle DeviceVoltageState_divide_equals_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other);
// @category:read
DeviceVoltageStateHandle DeviceVoltageState_power(
    DeviceVoltageStateHandle handle, int other);
// @category:read
DeviceVoltageStateHandle DeviceVoltageState_add_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other);
// @category:write
DeviceVoltageStateHandle DeviceVoltageState_add_equals_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other);
// @category:read
DeviceVoltageStateHandle DeviceVoltageState_subtract_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other);
// @category:write
DeviceVoltageStateHandle DeviceVoltageState_subtract_equals_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other);
// @category:read
DeviceVoltageStateHandle DeviceVoltageState_negate(
    DeviceVoltageStateHandle handle);
// @category:read
DeviceVoltageStateHandle DeviceVoltageState_abs(
    DeviceVoltageStateHandle handle);
// @category:read
bool DeviceVoltageState_equal(DeviceVoltageStateHandle a,
                              DeviceVoltageStateHandle b);
// @category:read
bool DeviceVoltageState_not_equal(DeviceVoltageStateHandle a,
                                  DeviceVoltageStateHandle b);
// @category:read
StringHandle DeviceVoltageState_to_json_string(DeviceVoltageStateHandle handle);
// @category:allocation
DeviceVoltageStateHandle DeviceVoltageState_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
