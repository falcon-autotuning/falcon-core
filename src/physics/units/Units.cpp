#include "falcon_core/physics/units/Units.hpp"

#include "falcon_core/physics/units/CommonUnits.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"
#include "falcon_core/physics/units/Unit.hpp"

using namespace falcon_core::physics::units;

const SymbolUnit Units::Meter{SP(Unit, Unit(common_units::Meter))};
const SymbolUnit Units::Kilogram{SP(Unit, Unit(common_units::Kilogram))};
const SymbolUnit Units::Second{SP(Unit, Unit(common_units::Second))};
const SymbolUnit Units::Ampere{SP(Unit, Unit(common_units::Ampere))};
const SymbolUnit Units::Kelvin{SP(Unit, Unit(common_units::Kelvin))};
const SymbolUnit Units::Mole{SP(Unit, Unit(common_units::Mole))};
const SymbolUnit Units::Candela{SP(Unit, Unit(common_units::Candela))};
const SymbolUnit Units::Hertz{SP(Unit, Unit(common_units::Hertz))};
const SymbolUnit Units::Newton{SP(Unit, Unit(common_units::Newton))};
const SymbolUnit Units::Pascal{SP(Unit, Unit(common_units::Pascal))};
const SymbolUnit Units::Joule{SP(Unit, Unit(common_units::Joule))};
const SymbolUnit Units::Watt{SP(Unit, Unit(common_units::Watt))};
const SymbolUnit Units::Coulomb{SP(Unit, Unit(common_units::Coulomb))};
const SymbolUnit Units::Volt{SP(Unit, Unit(common_units::Volt))};
const SymbolUnit Units::Farad{SP(Unit, Unit(common_units::Farad))};
const SymbolUnit Units::Ohm{SP(Unit, Unit(common_units::Ohm))};
const SymbolUnit Units::Siemens{SP(Unit, Unit(common_units::Siemens))};
const SymbolUnit Units::Weber{SP(Unit, Unit(common_units::Weber))};
const SymbolUnit Units::Tesla{SP(Unit, Unit(common_units::Tesla))};
const SymbolUnit Units::Henry{SP(Unit, Unit(common_units::Henry))};
const SymbolUnit Units::Minute{SP(Unit, Unit(common_units::Minute))};
const SymbolUnit Units::Hour{SP(Unit, Unit(common_units::Hour))};
const SymbolUnit Units::ElectronVolt{
    SP(Unit, Unit(common_units::ElectronVolt))};
const SymbolUnit Units::Celsius{SP(Unit, Unit(common_units::Celsius))};
const SymbolUnit Units::Fahrenheit{SP(Unit, Unit(common_units::Fahrenheit))};
const SymbolUnit Units::Dimensionless{
    SP(Unit, Unit(common_units::Dimensionless))};
const SymbolUnit Units::Percent{SP(Unit, Unit(common_units::Percent))};
const SymbolUnit Units::Radian{SP(Unit, Unit(common_units::Radian))};
const SymbolUnit Units::MilliMeter{
    common_units::get_milli(common_units::Meter)};
const SymbolUnit Units::KiloMeter{common_units::get_kilo(common_units::Meter)};
const SymbolUnit Units::MilliVolt{common_units::get_milli(common_units::Volt)};
const SymbolUnit Units::KiloVolt{common_units::get_kilo(common_units::Volt)};
const SymbolUnit Units::MilliAmpere{
    common_units::get_milli(common_units::Ampere)};
const SymbolUnit Units::MicroAmpere{
    common_units::get_micro(common_units::Ampere)};
const SymbolUnit Units::NanoAmpere{
    common_units::get_nano(common_units::Ampere)};
const SymbolUnit Units::PicoAmpere{
    common_units::get_pico(common_units::Ampere)};
const SymbolUnit Units::MilliSecond{
    common_units::get_milli(common_units::Second)};
const SymbolUnit Units::MicroSecond{
    common_units::get_micro(common_units::Second)};
const SymbolUnit Units::NanoSecond{
    common_units::get_nano(common_units::Second)};
const SymbolUnit Units::PicoSecond{
    common_units::get_pico(common_units::Second)};
const SymbolUnit Units::MilliOhm{common_units::get_milli(common_units::Ohm)};
const SymbolUnit Units::KiloOhm{common_units::get_kilo(common_units::Ohm)};
const SymbolUnit Units::MegaOhm{common_units::get_mega(common_units::Ohm)};
const SymbolUnit Units::MilliHertz{
    common_units::get_milli(common_units::Hertz)};
const SymbolUnit Units::KiloHertz{common_units::get_kilo(common_units::Hertz)};
const SymbolUnit Units::MegaHertz{common_units::get_mega(common_units::Hertz)};
const SymbolUnit Units::GigaHertz{common_units::get_giga(common_units::Hertz)};
const SymbolUnit Units::MetersPerSecond{
    (common_units::Meter / SP(Unit, common_units::Second))};
const SymbolUnit Units::MetersPerSecondSquared{
    (common_units::Meter / (common_units::Second ^ 2))};
const SymbolUnit Units::NewtonMeter{
    (common_units::Newton * SP(Unit, common_units::Meter))};
const SymbolUnit Units::NewtonPerMeter{
    (common_units::Newton / SP(Unit, common_units::Meter))};
const SymbolUnit Units::VoltsPerMeter{
    (common_units::Volt / SP(Unit, common_units::Meter))};
const SymbolUnit Units::VoltsPerSecond{
    (common_units::Volt / SP(Unit, common_units::Second))};
const SymbolUnit Units::AmperesPerMeter{
    (common_units::Ampere / SP(Unit, common_units::Meter))};
const SymbolUnit Units::VoltsPerAmpere{
    (common_units::Volt / SP(Unit, common_units::Ampere))};
const SymbolUnit Units::WattsPerMeterKelvin{
    (common_units::Watt /
     (common_units::Meter * SP(Unit, common_units::Kelvin)))};
