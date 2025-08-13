#pragma once

#include <memory>

#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core {
namespace physics {
namespace units {
const SymbolUnit Meter(std::make_shared<Unit>(common_units::Meter));
const SymbolUnit Kilogram(std::make_shared<Unit>(common_units::Kilogram));
const SymbolUnit Second(std::make_shared<Unit>(common_units::Second));
const SymbolUnit Ampere(std::make_shared<Unit>(common_units::Ampere));
const SymbolUnit Kelvin(std::make_shared<Unit>(common_units::Kelvin));
const SymbolUnit Mole(std::make_shared<Unit>(common_units::Mole));
const SymbolUnit Candela(std::make_shared<Unit>(common_units::Candela));
const SymbolUnit Hertz(std::make_shared<Unit>(common_units::Hertz));
const SymbolUnit Newton(std::make_shared<Unit>(common_units::Newton));
const SymbolUnit Pascal(std::make_shared<Unit>(common_units::Pascal));
const SymbolUnit Joule(std::make_shared<Unit>(common_units::Joule));
const SymbolUnit Watt(std::make_shared<Unit>(common_units::Watt));
const SymbolUnit Coulomb(std::make_shared<Unit>(common_units::Coulomb));
const SymbolUnit Volt(std::make_shared<Unit>(common_units::Volt));
const SymbolUnit Farad(std::make_shared<Unit>(common_units::Farad));
const SymbolUnit Ohm(std::make_shared<Unit>(common_units::Ohm));
const SymbolUnit Siemens(std::make_shared<Unit>(common_units::Siemens));
const SymbolUnit Weber(std::make_shared<Unit>(common_units::Weber));
const SymbolUnit Tesla(std::make_shared<Unit>(common_units::Tesla));
const SymbolUnit Henry(std::make_shared<Unit>(common_units::Henry));
const SymbolUnit Minute(std::make_shared<Unit>(common_units::Minute));
const SymbolUnit Hour(std::make_shared<Unit>(common_units::Hour));
const SymbolUnit ElectronVolt(
    std::make_shared<Unit>(common_units::ElectronVolt));
const SymbolUnit Celsius(std::make_shared<Unit>(common_units::Celsius));
const SymbolUnit Fahrenheit(std::make_shared<Unit>(common_units::Fahrenheit));
const SymbolUnit Dimensionless(
    std::make_shared<Unit>(common_units::Dimensionless));
const SymbolUnit Percent(std::make_shared<Unit>(common_units::Percent));
const SymbolUnit Radian(std::make_shared<Unit>(common_units::Radian));
const SymbolUnit MilliMeter(common_units::get_milli(common_units::Meter));
const SymbolUnit KiloMeter(common_units::get_kilo(common_units::Meter));
const SymbolUnit MilliVolt(common_units::get_milli(common_units::Volt));
const SymbolUnit KiloVolt(common_units::get_kilo(common_units::Volt));
const SymbolUnit MilliAmpere(common_units::get_milli(common_units::Ampere));
const SymbolUnit MicroAmpere(common_units::get_micro(common_units::Ampere));
const SymbolUnit NanoAmpere(common_units::get_nano(common_units::Ampere));
const SymbolUnit PicoAmpere(common_units::get_pico(common_units::Ampere));
const SymbolUnit MilliSecond(common_units::get_milli(common_units::Second));
const SymbolUnit MicroSecond(common_units::get_micro(common_units::Second));
const SymbolUnit NanoSecond(common_units::get_nano(common_units::Second));
const SymbolUnit PicoSecond(common_units::get_pico(common_units::Second));
const SymbolUnit MilliOhm(common_units::get_milli(common_units::Ohm));
const SymbolUnit KiloOhm(common_units::get_kilo(common_units::Ohm));
const SymbolUnit MegaOhm(common_units::get_mega(common_units::Ohm));
const SymbolUnit MilliHertz(common_units::get_milli(common_units::Hertz));
const SymbolUnit KiloHertz(common_units::get_kilo(common_units::Hertz));
const SymbolUnit MegaHertz(common_units::get_mega(common_units::Hertz));
const SymbolUnit GigaHertz(common_units::get_giga(common_units::Hertz));
const SymbolUnit MetersPerSecond(common_units::Meter / common_units::Second);
const SymbolUnit MetersPerSecondSquared(std::make_shared<Unit>(
    (*std::make_shared<Unit>(common_units::Meter)) /
    (*((*std::make_shared<Unit>(common_units::Second)) ^ 2))));
const SymbolUnit NewtonMeter(common_units::Newton *common_units::Meter);
const SymbolUnit NewtonPerMeter(common_units::Newton / common_units::Meter);
const SymbolUnit VoltsPerMeter(common_units::Volt / common_units::Meter);
const SymbolUnit VoltsPerSecond(common_units::Volt / common_units::Second);
const SymbolUnit AmperesPerMeter(common_units::Ampere / common_units::Meter);
const SymbolUnit VoltsPerAmpere(common_units::Volt / common_units::Ampere);
const SymbolUnit WattsPerMeterKelvin(std::make_shared<Unit>(
    common_units::Watt / (*(common_units::Meter * common_units::Kelvin))));
}  // namespace units
}  // namespace physics
}  // namespace falcon_core
