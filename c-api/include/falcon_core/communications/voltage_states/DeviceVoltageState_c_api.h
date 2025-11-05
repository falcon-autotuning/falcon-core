#pragma once
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
typedef void* DeviceVoltageStateHandle;

// Constructors
DeviceVoltageStateHandle DeviceVoltageState_create(
    ConnectionHandle connection,
    double           voltage,
    SymbolUnitHandle unit = SymbolUnit_create_volt());

// Destructor
void DeviceVoltageState_destroy(DeviceVoltageStateHandle handle);

// Methods
ConnectionHandle DeviceVoltageState_connection(DeviceVoltageStateHandle handle);
double           DeviceVoltageState_voltage(DeviceVoltageStateHandle handle);
double           DeviceVoltageState_value(DeviceVoltageStateHandle handle);
SymbolUnitHandle DeviceVoltageState_unit(DeviceVoltageStateHandle handle);
void             DeviceVoltageState_convert_to(DeviceVoltageStateHandle handle,
                                               SymbolUnitHandle         target_unit);
DeviceVoltageStateHandle DeviceVoltageState_multiply_int(
    DeviceVoltageStateHandle handle, int other);
DeviceVoltageStateHandle DeviceVoltageState_multiply_double(
    DeviceVoltageStateHandle handle, double other);
DeviceVoltageStateHandle DeviceVoltageState_multiply_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other);
DeviceVoltageStateHandle DeviceVoltageState_multiply_equals_int(
    DeviceVoltageStateHandle handle, int other);
DeviceVoltageStateHandle DeviceVoltageState_multiply_equals_double(
    DeviceVoltageStateHandle handle, double other);
DeviceVoltageStateHandle DeviceVoltageState_multiply_equals_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other);
DeviceVoltageStateHandle DeviceVoltageState_divide_int(
    DeviceVoltageStateHandle handle, int other);
DeviceVoltageStateHandle DeviceVoltageState_divide_double(
    DeviceVoltageStateHandle handle, double other);
DeviceVoltageStateHandle DeviceVoltageState_divide_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other);
DeviceVoltageStateHandle DeviceVoltageState_divide_equals_int(
    DeviceVoltageStateHandle handle, int other);
DeviceVoltageStateHandle DeviceVoltageState_divide_equals_double(
    DeviceVoltageStateHandle handle, double other);
DeviceVoltageStateHandle DeviceVoltageState_divide_equals_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other);
DeviceVoltageStateHandle DeviceVoltageState_power(
    DeviceVoltageStateHandle handle, int other);
DeviceVoltageStateHandle DeviceVoltageState_add_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other);
DeviceVoltageStateHandle DeviceVoltageState_add_equals_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other);
DeviceVoltageStateHandle DeviceVoltageState_subtract_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other);
DeviceVoltageStateHandle DeviceVoltageState_subtract_equals_quantity(
    DeviceVoltageStateHandle handle, DeviceVoltageStateHandle other);
DeviceVoltageStateHandle DeviceVoltageState_negate(
    DeviceVoltageStateHandle handle);
DeviceVoltageStateHandle DeviceVoltageState_abs(
    DeviceVoltageStateHandle handle);
bool DeviceVoltageState_equal(DeviceVoltageStateHandle a,
                              DeviceVoltageStateHandle b);
bool DeviceVoltageState_not_equal(DeviceVoltageStateHandle a,
                                  DeviceVoltageStateHandle b);

// Serialization (from Song)
StringHandle DeviceVoltageState_to_json_string(DeviceVoltageStateHandle handle);
DeviceVoltageStateHandle DeviceVoltageState_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
