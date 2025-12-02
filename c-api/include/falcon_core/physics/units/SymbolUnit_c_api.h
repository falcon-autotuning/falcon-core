#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* SymbolUnitHandle;

// Constructors
/* AUTO-DOC from cpp: SymbolUnit_create_meter | falcon_core::physics::units::SymbolUnit::Meter */
/**
 * @brief Construct a Meter
 */
SymbolUnitHandle SymbolUnit_create_meter();
/* AUTO-DOC from cpp: SymbolUnit_create_kilogram | falcon_core::physics::units::SymbolUnit::Kilogram */
/**
 * @brief Construct a Kilogram
 */
SymbolUnitHandle SymbolUnit_create_kilogram();
/* AUTO-DOC from cpp: SymbolUnit_create_second | falcon_core::physics::units::SymbolUnit::Second */
/**
 * @brief Construct a Second
 */
SymbolUnitHandle SymbolUnit_create_second();
/* AUTO-DOC from cpp: SymbolUnit_create_ampere | falcon_core::physics::units::SymbolUnit::Ampere */
/**
 * @brief Construct an Ampere
 */
SymbolUnitHandle SymbolUnit_create_ampere();
/* AUTO-DOC from cpp: SymbolUnit_create_kelvin | falcon_core::physics::units::SymbolUnit::Kelvin */
/**
 * @brief Construct a Kelvin
 */
SymbolUnitHandle SymbolUnit_create_kelvin();
/* AUTO-DOC from cpp: SymbolUnit_create_mole | falcon_core::physics::units::SymbolUnit::Mole */
/**
 * @brief Construct a Mole
 */
SymbolUnitHandle SymbolUnit_create_mole();
/* AUTO-DOC from cpp: SymbolUnit_create_candela | falcon_core::physics::units::SymbolUnit::Candela */
/**
 * @brief Construct a Candela
 */
SymbolUnitHandle SymbolUnit_create_candela();
/* AUTO-DOC from cpp: SymbolUnit_create_hertz | falcon_core::physics::units::SymbolUnit::Hertz */
/**
 * @brief Construct a Hertz
 */
SymbolUnitHandle SymbolUnit_create_hertz();
/* AUTO-DOC from cpp: SymbolUnit_create_newton | falcon_core::physics::units::SymbolUnit::Newton */
/**
 * @brief Construct a Newton
 */
SymbolUnitHandle SymbolUnit_create_newton();
/* AUTO-DOC from cpp: SymbolUnit_create_pascal | falcon_core::physics::units::SymbolUnit::Pascal */
/**
 * @brief Construct a Pascal
 */
SymbolUnitHandle SymbolUnit_create_pascal();
/* AUTO-DOC from cpp: SymbolUnit_create_joule | falcon_core::physics::units::SymbolUnit::Joule */
/**
 * @brief Construct a Joule
 */
SymbolUnitHandle SymbolUnit_create_joule();
/* AUTO-DOC from cpp: SymbolUnit_create_watt | falcon_core::physics::units::SymbolUnit::Watt */
/**
 * @brief Construct a Watt
 */
SymbolUnitHandle SymbolUnit_create_watt();
/* AUTO-DOC from cpp: SymbolUnit_create_coulomb | falcon_core::physics::units::SymbolUnit::Coulomb */
/**
 * @brief Construct a Coulomb
 */
SymbolUnitHandle SymbolUnit_create_coulomb();
/* AUTO-DOC from cpp: SymbolUnit_create_volt | falcon_core::physics::units::SymbolUnit::Volt */
/**
 * @brief Construct a Volt
 */
SymbolUnitHandle SymbolUnit_create_volt();
/* AUTO-DOC from cpp: SymbolUnit_create_farad | falcon_core::physics::units::SymbolUnit::Farad */
/**
 * @brief Construct a Farad
 */
SymbolUnitHandle SymbolUnit_create_farad();
/* AUTO-DOC from cpp: SymbolUnit_create_ohm | falcon_core::physics::units::SymbolUnit::Ohm */
/**
 * @brief Construct an Ohm
 */
SymbolUnitHandle SymbolUnit_create_ohm();
/* AUTO-DOC from cpp: SymbolUnit_create_siemens | falcon_core::physics::units::SymbolUnit::Siemens */
/**
 * @brief Construct a Seimens
 */
SymbolUnitHandle SymbolUnit_create_siemens();
/* AUTO-DOC from cpp: SymbolUnit_create_weber | falcon_core::physics::units::SymbolUnit::Weber */
/**
 * @brief Construct a Weber
 */
SymbolUnitHandle SymbolUnit_create_weber();
/* AUTO-DOC from cpp: SymbolUnit_create_tesla | falcon_core::physics::units::SymbolUnit::Tesla */
/**
 * @brief Construct a Tesla
 */
SymbolUnitHandle SymbolUnit_create_tesla();
/* AUTO-DOC from cpp: SymbolUnit_create_henry | falcon_core::physics::units::SymbolUnit::Henry */
/**
 * @brief Construct a Henry
 */
SymbolUnitHandle SymbolUnit_create_henry();
/* AUTO-DOC from cpp: SymbolUnit_create_minute | falcon_core::physics::units::SymbolUnit::Minute */
/**
 * @brief Construct a Minute
 */
SymbolUnitHandle SymbolUnit_create_minute();
/* AUTO-DOC from cpp: SymbolUnit_create_hour | falcon_core::physics::units::SymbolUnit::Hour */
/**
 * @brief Construct an Hour
 */
SymbolUnitHandle SymbolUnit_create_hour();
/* AUTO-DOC from cpp: SymbolUnit_create_electronvolt | falcon_core::physics::units::SymbolUnit::ElectronVolt */
/**
 * @brief Construct an ElectronVolt
 */
SymbolUnitHandle SymbolUnit_create_electronvolt();
/* AUTO-DOC from cpp: SymbolUnit_create_celsius | falcon_core::physics::units::SymbolUnit::Celsius */
/**
 * @brief Construct a Celsius
 */
SymbolUnitHandle SymbolUnit_create_celsius();
/* AUTO-DOC from cpp: SymbolUnit_create_fahrenheit | falcon_core::physics::units::SymbolUnit::Fahrenheit */
/**
 * @brief Construct a Fahrenheit
 */
SymbolUnitHandle SymbolUnit_create_fahrenheit();
/* AUTO-DOC from cpp: SymbolUnit_create_dimensionless | falcon_core::physics::units::SymbolUnit::Dimensionless */
/**
 * @brief Construct a Dimensionless
 */
SymbolUnitHandle SymbolUnit_create_dimensionless();
/* AUTO-DOC from cpp: SymbolUnit_create_percent | falcon_core::physics::units::SymbolUnit::Percent */
/**
 * @brief Construct a Percent
 */
SymbolUnitHandle SymbolUnit_create_percent();
/* AUTO-DOC from cpp: SymbolUnit_create_radian | falcon_core::physics::units::SymbolUnit::Radian */
/**
 * @brief Construct a Radian
 */
SymbolUnitHandle SymbolUnit_create_radian();
/* AUTO-DOC from cpp: SymbolUnit_create_kilometer | falcon_core::physics::units::SymbolUnit::KiloMeter */
/**
 * @brief Construct a KiloMeter
 */
SymbolUnitHandle SymbolUnit_create_kilometer();
/* AUTO-DOC from cpp: SymbolUnit_create_millimeter | falcon_core::physics::units::SymbolUnit::MilliMeter */
/**
 * @brief Construct a MilliMeter
 */
SymbolUnitHandle SymbolUnit_create_millimeter();
/* AUTO-DOC from cpp: SymbolUnit_create_millivolt | falcon_core::physics::units::SymbolUnit::MilliVolt */
/**
 * @brief Construct a MilliVolt
 */
SymbolUnitHandle SymbolUnit_create_millivolt();
/* AUTO-DOC from cpp: SymbolUnit_create_kilovolt | falcon_core::physics::units::SymbolUnit::KiloVolt */
/**
 * @brief Construct a KiloVolt
 */
SymbolUnitHandle SymbolUnit_create_kilovolt();
/* AUTO-DOC from cpp: SymbolUnit_create_milliampere | falcon_core::physics::units::SymbolUnit::MilliAmpere */
/**
 * @brief Construct a MilliAmpere
 */
SymbolUnitHandle SymbolUnit_create_milliampere();
/* AUTO-DOC from cpp: SymbolUnit_create_microampere | falcon_core::physics::units::SymbolUnit::MicroAmpere */
/**
 * @brief Construct a MicroAmpere
 */
SymbolUnitHandle SymbolUnit_create_microampere();
/* AUTO-DOC from cpp: SymbolUnit_create_nanoampere | falcon_core::physics::units::SymbolUnit::NanoAmpere */
/**
 * @brief Construct a NanoAmpere
 */
SymbolUnitHandle SymbolUnit_create_nanoampere();
/* AUTO-DOC from cpp: SymbolUnit_create_picoampere | falcon_core::physics::units::SymbolUnit::PicoAmpere */
/**
 * @brief Construct a PicoAmpere
 */
SymbolUnitHandle SymbolUnit_create_picoampere();
/* AUTO-DOC from cpp: SymbolUnit_create_millisecond | falcon_core::physics::units::SymbolUnit::MilliSecond */
/**
 * @brief Construct a MilliSecond
 */
SymbolUnitHandle SymbolUnit_create_millisecond();
/* AUTO-DOC from cpp: SymbolUnit_create_microsecond | falcon_core::physics::units::SymbolUnit::MicroSecond */
/**
 * @brief Construct a MicroSecond
 */
SymbolUnitHandle SymbolUnit_create_microsecond();
/* AUTO-DOC from cpp: SymbolUnit_create_nanosecond | falcon_core::physics::units::SymbolUnit::NanoSecond */
/**
 * @brief Construct a NanoSecond
 */
SymbolUnitHandle SymbolUnit_create_nanosecond();
/* AUTO-DOC from cpp: SymbolUnit_create_picosecond | falcon_core::physics::units::SymbolUnit::PicoSecond */
/**
 * @brief Construct a PicoSecond
 */
SymbolUnitHandle SymbolUnit_create_picosecond();
/* AUTO-DOC from cpp: SymbolUnit_create_milliohm | falcon_core::physics::units::SymbolUnit::MilliOhm */
/**
 * @brief Construct a MilliOhm
 */
SymbolUnitHandle SymbolUnit_create_milliohm();
/* AUTO-DOC from cpp: SymbolUnit_create_kiloohm | falcon_core::physics::units::SymbolUnit::KiloOhm */
/**
 * @brief Construct a KiloOhm
 */
SymbolUnitHandle SymbolUnit_create_kiloohm();
/* AUTO-DOC from cpp: SymbolUnit_create_megaohm | falcon_core::physics::units::SymbolUnit::MegaOhm */
/**
 * @brief Construct a MegaOhm
 */
SymbolUnitHandle SymbolUnit_create_megaohm();
/* AUTO-DOC from cpp: SymbolUnit_create_millihertz | falcon_core::physics::units::SymbolUnit::MilliHertz */
/**
 * @brief Construct a MilliHertz
 */
SymbolUnitHandle SymbolUnit_create_millihertz();
/* AUTO-DOC from cpp: SymbolUnit_create_kilohertz | falcon_core::physics::units::SymbolUnit::KiloHertz */
/**
 * @brief Construct a KiloHertz
 */
SymbolUnitHandle SymbolUnit_create_kilohertz();
/* AUTO-DOC from cpp: SymbolUnit_create_megahertz | falcon_core::physics::units::SymbolUnit::MegaHertz */
/**
 * @brief Construct a MegaHertz
 */
SymbolUnitHandle SymbolUnit_create_megahertz();
/* AUTO-DOC from cpp: SymbolUnit_create_gigahertz | falcon_core::physics::units::SymbolUnit::GigaHertz */
/**
 * @brief Construct a GigaHertz
 */
SymbolUnitHandle SymbolUnit_create_gigahertz();
/* AUTO-DOC from cpp: SymbolUnit_create_meters_per_second | falcon_core::physics::units::SymbolUnit::MetersPerSecond */
/**
 * @brief Construct a MetersPerSecond
 */
SymbolUnitHandle SymbolUnit_create_meters_per_second();
/* AUTO-DOC from cpp: SymbolUnit_create_meters_per_second_squared | falcon_core::physics::units::SymbolUnit::MetersPerSecondSquared */
/**
 * @brief Construct a MetersPerSecondSquared
 */
SymbolUnitHandle SymbolUnit_create_meters_per_second_squared();
/* AUTO-DOC from cpp: SymbolUnit_create_newton_meter | falcon_core::physics::units::SymbolUnit::NewtonMeter */
/**
 * @brief Construct a NewtonMeter
 */
SymbolUnitHandle SymbolUnit_create_newton_meter();
/* AUTO-DOC from cpp: SymbolUnit_create_newtons_per_meter | falcon_core::physics::units::SymbolUnit::NewtonPerMeter */
/**
 * @brief Construct a NewtonPerMeter
 */
SymbolUnitHandle SymbolUnit_create_newtons_per_meter();
/* AUTO-DOC from cpp: SymbolUnit_create_volts_per_meter | falcon_core::physics::units::SymbolUnit::VoltsPerMeter */
/**
 * @brief Construct a VoltsPerMeter
 */
SymbolUnitHandle SymbolUnit_create_volts_per_meter();
/* AUTO-DOC from cpp: SymbolUnit_create_volts_per_second | falcon_core::physics::units::SymbolUnit::VoltsPerSecond */
/**
 * @brief Construct a VoltsPerSecond
 */
SymbolUnitHandle SymbolUnit_create_volts_per_second();
/* AUTO-DOC from cpp: SymbolUnit_create_amperes_per_meter | falcon_core::physics::units::SymbolUnit::AmperesPerMeter */
/**
 * @brief Construct an AmperesPerMeter
 */
SymbolUnitHandle SymbolUnit_create_amperes_per_meter();
/* AUTO-DOC from cpp: SymbolUnit_create_volts_per_ampere | falcon_core::physics::units::SymbolUnit::VoltsPerAmpere */
/**
 * @brief Construct a VoltsPerAmpere
 */
SymbolUnitHandle SymbolUnit_create_volts_per_ampere();
/* AUTO-DOC from cpp: SymbolUnit_create_watts_per_meter_kelvin | falcon_core::physics::units::SymbolUnit::WattsPerMeterKelvin */
/**
 * @brief Construct a WattsPerMeterKelvin
 */
SymbolUnitHandle SymbolUnit_create_watts_per_meter_kelvin();

// Destructor
void SymbolUnit_destroy(SymbolUnitHandle handle);

// Methods
/* AUTO-DOC from cpp: SymbolUnit_symbol | falcon_core::physics::units::SymbolUnit::symbol */
/**
 * @brief Get the name of the unit.
 * @return The name as a string.
 */
StringHandle     SymbolUnit_symbol(SymbolUnitHandle handle);
/* AUTO-DOC from cpp: SymbolUnit_name | falcon_core::physics::units::SymbolUnit::name */
/**
 * @brief Get the name of the unit.
 * @return The name as a string.
 */
StringHandle     SymbolUnit_name(SymbolUnitHandle handle);
SymbolUnitHandle SymbolUnit_multiplication(SymbolUnitHandle handle,
                                           SymbolUnitHandle other);
SymbolUnitHandle SymbolUnit_division(SymbolUnitHandle handle,
                                     SymbolUnitHandle other);
SymbolUnitHandle SymbolUnit_power(SymbolUnitHandle handle, int power);
SymbolUnitHandle SymbolUnit_with_prefix(SymbolUnitHandle handle,
                                        StringHandle     prefix);
/* AUTO-DOC from cpp: SymbolUnit_convert_value_to | falcon_core::physics::units::SymbolUnit::convert_value_to */
/**
 * @brief Convert a value from this symbol unit to a target symbol unit.
 * @param value The value in this symbol unit to convert.
 * @param target_unit The symbol unit to convert the value to.
 * @return The converted value in the target symbol unit.
 * @throws std::invalid_argument if the units are not compatible.
 */
double           SymbolUnit_convert_value_to(SymbolUnitHandle handle,
                                             double           value,
                                             SymbolUnitHandle target);
/* AUTO-DOC from cpp: SymbolUnit_is_compatible_with | falcon_core::physics::units::SymbolUnit::is_compatible_with */
/**
 * @brief Check if this symbol unit is compatible with another symbol unit.
 * @param other The symbol unit to check compatibility with.
 * @return True if the symbol units are compatible (same dimensions), false
 * otherwise.
 */
bool             SymbolUnit_is_compatible_with(SymbolUnitHandle handle,
                                               SymbolUnitHandle other);
bool SymbolUnit_equal(SymbolUnitHandle handle, SymbolUnitHandle other);
bool SymbolUnit_not_equal(SymbolUnitHandle handle, SymbolUnitHandle other);

// Serialization (from Song)
StringHandle     SymbolUnit_to_json_string(SymbolUnitHandle handle);
SymbolUnitHandle SymbolUnit_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
