#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
typedef void* SymbolUnitHandle;

// Constructors
SymbolUnitHandle SymbolUnit_create_meter();
SymbolUnitHandle SymbolUnit_create_kilogram();
SymbolUnitHandle SymbolUnit_create_second();
SymbolUnitHandle SymbolUnit_create_ampere();
SymbolUnitHandle SymbolUnit_create_kelvin();
SymbolUnitHandle SymbolUnit_create_mole();
SymbolUnitHandle SymbolUnit_create_candela();
SymbolUnitHandle SymbolUnit_create_hertz();
SymbolUnitHandle SymbolUnit_create_newton();
SymbolUnitHandle SymbolUnit_create_pascal();
SymbolUnitHandle SymbolUnit_create_joule();
SymbolUnitHandle SymbolUnit_create_watt();
SymbolUnitHandle SymbolUnit_create_coulomb();
SymbolUnitHandle SymbolUnit_create_volt();
SymbolUnitHandle SymbolUnit_create_farad();
SymbolUnitHandle SymbolUnit_create_ohm();
SymbolUnitHandle SymbolUnit_create_siemens();
SymbolUnitHandle SymbolUnit_create_weber();
SymbolUnitHandle SymbolUnit_create_tesla();
SymbolUnitHandle SymbolUnit_create_henry();
SymbolUnitHandle SymbolUnit_create_minute();
SymbolUnitHandle SymbolUnit_create_hour();
SymbolUnitHandle SymbolUnit_create_electronvolt();
SymbolUnitHandle SymbolUnit_create_celsius();
SymbolUnitHandle SymbolUnit_create_fahrenheit();
SymbolUnitHandle SymbolUnit_create_dimensionless();
SymbolUnitHandle SymbolUnit_create_percent();
SymbolUnitHandle SymbolUnit_create_radian();
SymbolUnitHandle SymbolUnit_create_kilometer();
SymbolUnitHandle SymbolUnit_create_millimeter();
SymbolUnitHandle SymbolUnit_create_millivolt();
SymbolUnitHandle SymbolUnit_create_kilovolt();
SymbolUnitHandle SymbolUnit_create_milliampere();
SymbolUnitHandle SymbolUnit_create_microampere();
SymbolUnitHandle SymbolUnit_create_nanoampere();
SymbolUnitHandle SymbolUnit_create_picoampere();
SymbolUnitHandle SymbolUnit_create_millisecond();
SymbolUnitHandle SymbolUnit_create_microsecond();
SymbolUnitHandle SymbolUnit_create_nanosecond();
SymbolUnitHandle SymbolUnit_create_picosecond();
SymbolUnitHandle SymbolUnit_create_milliohm();
SymbolUnitHandle SymbolUnit_create_kiloohm();
SymbolUnitHandle SymbolUnit_create_megaohm();
SymbolUnitHandle SymbolUnit_create_millihertz();
SymbolUnitHandle SymbolUnit_create_kilohertz();
SymbolUnitHandle SymbolUnit_create_megahertz();
SymbolUnitHandle SymbolUnit_create_gigahertz();
SymbolUnitHandle SymbolUnit_create_meters_per_second();
SymbolUnitHandle SymbolUnit_create_meters_per_second_squared();
SymbolUnitHandle SymbolUnit_create_newton_meter();
SymbolUnitHandle SymbolUnit_create_newtons_per_meter();
SymbolUnitHandle SymbolUnit_create_volts_per_meter();
SymbolUnitHandle SymbolUnit_create_volts_per_second();
SymbolUnitHandle SymbolUnit_create_amperes_per_meter();
SymbolUnitHandle SymbolUnit_create_volts_per_ampere();
SymbolUnitHandle SymbolUnit_create_watts_per_meter_kelvin();

// Destructor
void SymbolUnit_destroy(SymbolUnitHandle handle);

// Methods
const char*      SymbolUnit_symbol(SymbolUnitHandle handle);
const char*      SymbolUnit_name(SymbolUnitHandle handle);
SymbolUnitHandle SymbolUnit_multiplication(SymbolUnitHandle handle,
                                           SymbolUnitHandle other);
SymbolUnitHandle SymbolUnit_division(SymbolUnitHandle handle,
                                     SymbolUnitHandle other);
SymbolUnitHandle SymbolUnit_power(SymbolUnitHandle handle, int power);
SymbolUnitHandle SymbolUnit_with_prefix(SymbolUnitHandle handle,
                                        const char*      prefix);
double           SymbolUnit_convert_value_to(SymbolUnitHandle handle,
                                             double           value,
                                             SymbolUnitHandle target);
bool             SymbolUnit_is_compatible_with(SymbolUnitHandle handle,
                                               SymbolUnitHandle other);
const char*      SymbolUnit_str(SymbolUnitHandle handle);
bool SymbolUnit_equal(SymbolUnitHandle handle, SymbolUnitHandle other);
bool SymbolUnit_not_equal(SymbolUnitHandle handle, SymbolUnitHandle other);

// Serialization (from Song)
const char*      SymbolUnit_to_json_string(SymbolUnitHandle handle);
SymbolUnitHandle SymbolUnit_from_json_string(const char* json);

#ifdef __cplusplus
}
#endif
