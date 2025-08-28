#include "falcon_core/physics/units/Units.hpp"

#include "falcon_core/physics/units/CommonUnits.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"
#include "falcon_core/physics/units/Unit.hpp"

using namespace falcon_core::physics::units;
const SymbolUnit Units::Meter{CommonUnits::Meter};
const SymbolUnit Units::Kilogram{CommonUnits::Kilogram};
const SymbolUnit Units::Second{CommonUnits::Second};
const SymbolUnit Units::Ampere{CommonUnits::Ampere};
const SymbolUnit Units::Kelvin{CommonUnits::Kelvin};
const SymbolUnit Units::Mole{CommonUnits::Mole};
const SymbolUnit Units::Candela{CommonUnits::Candela};
const SymbolUnit Units::Hertz{CommonUnits::Hertz};
const SymbolUnit Units::Newton{CommonUnits::Newton};
const SymbolUnit Units::Pascal{CommonUnits::Pascal};
const SymbolUnit Units::Joule{CommonUnits::Joule};
const SymbolUnit Units::Watt{CommonUnits::Watt};
const SymbolUnit Units::Coulomb{CommonUnits::Coulomb};
const SymbolUnit Units::Volt{CommonUnits::Volt};
const SymbolUnit Units::Farad{CommonUnits::Farad};
const SymbolUnit Units::Ohm{CommonUnits::Ohm};
const SymbolUnit Units::Siemens{CommonUnits::Siemens};
const SymbolUnit Units::Weber{CommonUnits::Weber};
const SymbolUnit Units::Tesla{CommonUnits::Tesla};
const SymbolUnit Units::Henry{CommonUnits::Henry};
const SymbolUnit Units::Minute{CommonUnits::Minute};
const SymbolUnit Units::Hour{CommonUnits::Hour};
const SymbolUnit Units::ElectronVolt{CommonUnits::ElectronVolt};
const SymbolUnit Units::Celsius{CommonUnits::Celsius};
const SymbolUnit Units::Fahrenheit{CommonUnits::Fahrenheit};
const SymbolUnit Units::Dimensionless{CommonUnits::Dimensionless};
const SymbolUnit Units::Percent{CommonUnits::Percent};
const SymbolUnit Units::Radian{CommonUnits::Radian};
const SymbolUnit Units::MilliMeter{CommonUnits::get_milli(CommonUnits::Meter)};
const SymbolUnit Units::KiloMeter{CommonUnits::get_kilo(CommonUnits::Meter)};
const SymbolUnit Units::MilliVolt{CommonUnits::get_milli(CommonUnits::Volt)};
const SymbolUnit Units::KiloVolt{CommonUnits::get_kilo(CommonUnits::Volt)};
const SymbolUnit Units::MilliAmpere{
    CommonUnits::get_milli(CommonUnits::Ampere)};
const SymbolUnit Units::MicroAmpere{
    CommonUnits::get_micro(CommonUnits::Ampere)};
const SymbolUnit Units::NanoAmpere{CommonUnits::get_nano(CommonUnits::Ampere)};
const SymbolUnit Units::PicoAmpere{CommonUnits::get_pico(CommonUnits::Ampere)};
const SymbolUnit Units::MilliSecond{
    CommonUnits::get_milli(CommonUnits::Second)};
const SymbolUnit Units::MicroSecond{
    CommonUnits::get_micro(CommonUnits::Second)};
const SymbolUnit Units::NanoSecond{CommonUnits::get_nano(CommonUnits::Second)};
const SymbolUnit Units::PicoSecond{CommonUnits::get_pico(CommonUnits::Second)};
const SymbolUnit Units::MilliOhm{CommonUnits::get_milli(CommonUnits::Ohm)};
const SymbolUnit Units::KiloOhm{CommonUnits::get_kilo(CommonUnits::Ohm)};
const SymbolUnit Units::MegaOhm{CommonUnits::get_mega(CommonUnits::Ohm)};
const SymbolUnit Units::MilliHertz{CommonUnits::get_milli(CommonUnits::Hertz)};
const SymbolUnit Units::KiloHertz{CommonUnits::get_kilo(CommonUnits::Hertz)};
const SymbolUnit Units::MegaHertz{CommonUnits::get_mega(CommonUnits::Hertz)};
const SymbolUnit Units::GigaHertz{CommonUnits::get_giga(CommonUnits::Hertz)};
const SymbolUnit Units::MetersPerSecond{*CommonUnits::Meter /
                                        CommonUnits::Second};
const SymbolUnit Units::MetersPerSecondSquared{*CommonUnits::Meter /
                                               (*CommonUnits::Second ^ 2)};
const SymbolUnit Units::NewtonMeter{*CommonUnits::Newton * CommonUnits::Meter};
const SymbolUnit Units::NewtonPerMeter{*CommonUnits::Newton /
                                       CommonUnits::Meter};
const SymbolUnit Units::VoltsPerMeter{*CommonUnits::Volt / CommonUnits::Meter};
const SymbolUnit Units::VoltsPerSecond{*CommonUnits::Volt /
                                       CommonUnits::Second};
const SymbolUnit Units::AmperesPerMeter{*CommonUnits::Ampere /
                                        CommonUnits::Meter};
const SymbolUnit Units::VoltsPerAmpere{*CommonUnits::Volt /
                                       CommonUnits::Ampere};
const SymbolUnit Units::WattsPerMeterKelvin{
    *CommonUnits::Watt / (*CommonUnits::Meter * CommonUnits::Kelvin)};
