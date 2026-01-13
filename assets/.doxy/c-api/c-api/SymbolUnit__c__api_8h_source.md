

# File SymbolUnit\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**units**](dir_819f82495bddee121ceebbf28911313c.md) **>** [**SymbolUnit\_c\_api.h**](SymbolUnit__c__api_8h.md)

[Go to the documentation of this file](SymbolUnit__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* SymbolUnitHandle;

// @category:allocation
SymbolUnitHandle SymbolUnit_copy(SymbolUnitHandle handle);
// @category:deallocation
void SymbolUnit_destroy(SymbolUnitHandle handle);
// @category:read
bool SymbolUnit_equal(SymbolUnitHandle handle, SymbolUnitHandle other);
// @category:read
bool SymbolUnit_not_equal(SymbolUnitHandle handle, SymbolUnitHandle other);
// @category:read
StringHandle SymbolUnit_to_json_string(SymbolUnitHandle handle);
// @category:allocation
SymbolUnitHandle SymbolUnit_from_json_string(StringHandle json);
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_meter |
 * falcon_core::physics::units::SymbolUnit::Meter */
SymbolUnitHandle SymbolUnit_create_meter();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_kilogram |
 * falcon_core::physics::units::SymbolUnit::Kilogram */
SymbolUnitHandle SymbolUnit_create_kilogram();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_second |
 * falcon_core::physics::units::SymbolUnit::Second */
SymbolUnitHandle SymbolUnit_create_second();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_ampere |
 * falcon_core::physics::units::SymbolUnit::Ampere */
SymbolUnitHandle SymbolUnit_create_ampere();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_kelvin |
 * falcon_core::physics::units::SymbolUnit::Kelvin */
SymbolUnitHandle SymbolUnit_create_kelvin();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_mole |
 * falcon_core::physics::units::SymbolUnit::Mole */
SymbolUnitHandle SymbolUnit_create_mole();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_candela |
 * falcon_core::physics::units::SymbolUnit::Candela */
SymbolUnitHandle SymbolUnit_create_candela();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_hertz |
 * falcon_core::physics::units::SymbolUnit::Hertz */
SymbolUnitHandle SymbolUnit_create_hertz();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_newton |
 * falcon_core::physics::units::SymbolUnit::Newton */
SymbolUnitHandle SymbolUnit_create_newton();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_pascal |
 * falcon_core::physics::units::SymbolUnit::Pascal */
SymbolUnitHandle SymbolUnit_create_pascal();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_joule |
 * falcon_core::physics::units::SymbolUnit::Joule */
SymbolUnitHandle SymbolUnit_create_joule();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_watt |
 * falcon_core::physics::units::SymbolUnit::Watt */
SymbolUnitHandle SymbolUnit_create_watt();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_coulomb |
 * falcon_core::physics::units::SymbolUnit::Coulomb */
SymbolUnitHandle SymbolUnit_create_coulomb();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_volt |
 * falcon_core::physics::units::SymbolUnit::Volt */
SymbolUnitHandle SymbolUnit_create_volt();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_farad |
 * falcon_core::physics::units::SymbolUnit::Farad */
SymbolUnitHandle SymbolUnit_create_farad();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_ohm |
 * falcon_core::physics::units::SymbolUnit::Ohm */
SymbolUnitHandle SymbolUnit_create_ohm();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_siemens |
 * falcon_core::physics::units::SymbolUnit::Siemens */
SymbolUnitHandle SymbolUnit_create_siemens();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_weber |
 * falcon_core::physics::units::SymbolUnit::Weber */
SymbolUnitHandle SymbolUnit_create_weber();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_tesla |
 * falcon_core::physics::units::SymbolUnit::Tesla */
SymbolUnitHandle SymbolUnit_create_tesla();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_henry |
 * falcon_core::physics::units::SymbolUnit::Henry */
SymbolUnitHandle SymbolUnit_create_henry();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_minute |
 * falcon_core::physics::units::SymbolUnit::Minute */
SymbolUnitHandle SymbolUnit_create_minute();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_hour |
 * falcon_core::physics::units::SymbolUnit::Hour */
SymbolUnitHandle SymbolUnit_create_hour();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_electronvolt |
 * falcon_core::physics::units::SymbolUnit::ElectronVolt */
SymbolUnitHandle SymbolUnit_create_electronvolt();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_celsius |
 * falcon_core::physics::units::SymbolUnit::Celsius */
SymbolUnitHandle SymbolUnit_create_celsius();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_fahrenheit |
 * falcon_core::physics::units::SymbolUnit::Fahrenheit */
SymbolUnitHandle SymbolUnit_create_fahrenheit();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_dimensionless |
 * falcon_core::physics::units::SymbolUnit::Dimensionless */
SymbolUnitHandle SymbolUnit_create_dimensionless();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_percent |
 * falcon_core::physics::units::SymbolUnit::Percent */
SymbolUnitHandle SymbolUnit_create_percent();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_radian |
 * falcon_core::physics::units::SymbolUnit::Radian */
SymbolUnitHandle SymbolUnit_create_radian();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_kilometer |
 * falcon_core::physics::units::SymbolUnit::KiloMeter */
SymbolUnitHandle SymbolUnit_create_kilometer();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_millimeter |
 * falcon_core::physics::units::SymbolUnit::MilliMeter */
SymbolUnitHandle SymbolUnit_create_millimeter();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_millivolt |
 * falcon_core::physics::units::SymbolUnit::MilliVolt */
SymbolUnitHandle SymbolUnit_create_millivolt();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_kilovolt |
 * falcon_core::physics::units::SymbolUnit::KiloVolt */
SymbolUnitHandle SymbolUnit_create_kilovolt();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_milliampere |
 * falcon_core::physics::units::SymbolUnit::MilliAmpere */
SymbolUnitHandle SymbolUnit_create_milliampere();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_microampere |
 * falcon_core::physics::units::SymbolUnit::MicroAmpere */
SymbolUnitHandle SymbolUnit_create_microampere();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_nanoampere |
 * falcon_core::physics::units::SymbolUnit::NanoAmpere */
SymbolUnitHandle SymbolUnit_create_nanoampere();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_picoampere |
 * falcon_core::physics::units::SymbolUnit::PicoAmpere */
SymbolUnitHandle SymbolUnit_create_picoampere();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_millisecond |
 * falcon_core::physics::units::SymbolUnit::MilliSecond */
SymbolUnitHandle SymbolUnit_create_millisecond();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_microsecond |
 * falcon_core::physics::units::SymbolUnit::MicroSecond */
SymbolUnitHandle SymbolUnit_create_microsecond();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_nanosecond |
 * falcon_core::physics::units::SymbolUnit::NanoSecond */
SymbolUnitHandle SymbolUnit_create_nanosecond();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_picosecond |
 * falcon_core::physics::units::SymbolUnit::PicoSecond */
SymbolUnitHandle SymbolUnit_create_picosecond();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_milliohm |
 * falcon_core::physics::units::SymbolUnit::MilliOhm */
SymbolUnitHandle SymbolUnit_create_milliohm();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_kiloohm |
 * falcon_core::physics::units::SymbolUnit::KiloOhm */
SymbolUnitHandle SymbolUnit_create_kiloohm();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_megaohm |
 * falcon_core::physics::units::SymbolUnit::MegaOhm */
SymbolUnitHandle SymbolUnit_create_megaohm();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_millihertz |
 * falcon_core::physics::units::SymbolUnit::MilliHertz */
SymbolUnitHandle SymbolUnit_create_millihertz();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_kilohertz |
 * falcon_core::physics::units::SymbolUnit::KiloHertz */
SymbolUnitHandle SymbolUnit_create_kilohertz();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_megahertz |
 * falcon_core::physics::units::SymbolUnit::MegaHertz */
SymbolUnitHandle SymbolUnit_create_megahertz();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_gigahertz |
 * falcon_core::physics::units::SymbolUnit::GigaHertz */
SymbolUnitHandle SymbolUnit_create_gigahertz();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_meters_per_second |
 * falcon_core::physics::units::SymbolUnit::MetersPerSecond */
SymbolUnitHandle SymbolUnit_create_meters_per_second();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_meters_per_second_squared |
 * falcon_core::physics::units::SymbolUnit::MetersPerSecondSquared */
SymbolUnitHandle SymbolUnit_create_meters_per_second_squared();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_newton_meter |
 * falcon_core::physics::units::SymbolUnit::NewtonMeter */
SymbolUnitHandle SymbolUnit_create_newton_meter();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_newtons_per_meter |
 * falcon_core::physics::units::SymbolUnit::NewtonPerMeter */
SymbolUnitHandle SymbolUnit_create_newtons_per_meter();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_volts_per_meter |
 * falcon_core::physics::units::SymbolUnit::VoltsPerMeter */
SymbolUnitHandle SymbolUnit_create_volts_per_meter();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_volts_per_second |
 * falcon_core::physics::units::SymbolUnit::VoltsPerSecond */
SymbolUnitHandle SymbolUnit_create_volts_per_second();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_amperes_per_meter |
 * falcon_core::physics::units::SymbolUnit::AmperesPerMeter */
SymbolUnitHandle SymbolUnit_create_amperes_per_meter();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_volts_per_ampere |
 * falcon_core::physics::units::SymbolUnit::VoltsPerAmpere */
SymbolUnitHandle SymbolUnit_create_volts_per_ampere();
// @category:allocation
/* AUTO-DOC from cpp: SymbolUnit_create_watts_per_meter_kelvin |
 * falcon_core::physics::units::SymbolUnit::WattsPerMeterKelvin */
SymbolUnitHandle SymbolUnit_create_watts_per_meter_kelvin();
// @category:read
/* AUTO-DOC from cpp: SymbolUnit_symbol |
 * falcon_core::physics::units::SymbolUnit::symbol */
StringHandle SymbolUnit_symbol(SymbolUnitHandle handle);
// @category:read
/* AUTO-DOC from cpp: SymbolUnit_name |
 * falcon_core::physics::units::SymbolUnit::name */
StringHandle SymbolUnit_name(SymbolUnitHandle handle);
// @category:read
SymbolUnitHandle SymbolUnit_multiplication(SymbolUnitHandle handle,
                                           SymbolUnitHandle other);
// @category:read
SymbolUnitHandle SymbolUnit_division(SymbolUnitHandle handle,
                                     SymbolUnitHandle other);
// @category:read
SymbolUnitHandle SymbolUnit_power(SymbolUnitHandle handle, int power);
// @category:read
SymbolUnitHandle SymbolUnit_with_prefix(SymbolUnitHandle handle,
                                        StringHandle     prefix);
// @category:read
/* AUTO-DOC from cpp: SymbolUnit_convert_value_to |
 * falcon_core::physics::units::SymbolUnit::convert_value_to */
double SymbolUnit_convert_value_to(SymbolUnitHandle handle,
                                   double           value,
                                   SymbolUnitHandle target);
// @category:read
/* AUTO-DOC from cpp: SymbolUnit_is_compatible_with |
 * falcon_core::physics::units::SymbolUnit::is_compatible_with */
bool SymbolUnit_is_compatible_with(SymbolUnitHandle handle,
                                   SymbolUnitHandle other);

#ifdef __cplusplus
}
#endif
```


