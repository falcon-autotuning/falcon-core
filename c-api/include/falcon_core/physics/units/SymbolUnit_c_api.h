#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* SymbolUnitHandle;

// @category:allocation
SymbolUnitHandle SymbolUnit_create_meter();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_kilogram();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_second();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_ampere();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_kelvin();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_mole();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_candela();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_hertz();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_newton();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_pascal();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_joule();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_watt();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_coulomb();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_volt();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_farad();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_ohm();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_siemens();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_weber();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_tesla();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_henry();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_minute();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_hour();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_electronvolt();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_celsius();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_fahrenheit();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_dimensionless();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_percent();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_radian();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_kilometer();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_millimeter();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_millivolt();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_kilovolt();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_milliampere();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_microampere();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_nanoampere();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_picoampere();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_millisecond();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_microsecond();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_nanosecond();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_picosecond();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_milliohm();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_kiloohm();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_megaohm();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_millihertz();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_kilohertz();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_megahertz();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_gigahertz();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_meters_per_second();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_meters_per_second_squared();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_newton_meter();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_newtons_per_meter();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_volts_per_meter();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_volts_per_second();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_amperes_per_meter();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_volts_per_ampere();
// @category:allocation
SymbolUnitHandle SymbolUnit_create_watts_per_meter_kelvin();
// @category:deallocation
void SymbolUnit_destroy(SymbolUnitHandle handle);
// @category:read
StringHandle SymbolUnit_symbol(SymbolUnitHandle handle);
// @category:read
StringHandle SymbolUnit_name(SymbolUnitHandle handle);
// @category:allocation
SymbolUnitHandle SymbolUnit_multiplication(SymbolUnitHandle handle,
                                           SymbolUnitHandle other);
// @category:allocation
SymbolUnitHandle SymbolUnit_division(SymbolUnitHandle handle,
                                     SymbolUnitHandle other);
// @category:allocation
SymbolUnitHandle SymbolUnit_power(SymbolUnitHandle handle, int power);
// @category:allocation
SymbolUnitHandle SymbolUnit_with_prefix(SymbolUnitHandle handle,
                                        StringHandle     prefix);
// @category:read
double SymbolUnit_convert_value_to(SymbolUnitHandle handle,
                                   double           value,
                                   SymbolUnitHandle target);
// @category:read
bool SymbolUnit_is_compatible_with(SymbolUnitHandle handle,
                                   SymbolUnitHandle other);
// @category:read
bool SymbolUnit_equal(SymbolUnitHandle handle, SymbolUnitHandle other);
// @category:read
bool SymbolUnit_not_equal(SymbolUnitHandle handle, SymbolUnitHandle other);
// @category:read
StringHandle SymbolUnit_to_json_string(SymbolUnitHandle handle);
// @category:allocation
SymbolUnitHandle SymbolUnit_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
