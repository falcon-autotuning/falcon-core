#pragma once

#include "falcon_core/macros.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"
namespace falcon_core {
namespace physics {
namespace units {

inline const SymbolUnit& Meter() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Meter))};
  return unit;
}
inline const SymbolUnit& Kilogram() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Kilogram))};
  return unit;
}
inline const SymbolUnit& Second() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Second))};
  return unit;
}
inline const SymbolUnit& Ampere() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Ampere))};
  return unit;
}
inline const SymbolUnit& Kelvin() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Kelvin))};
  return unit;
}
inline const SymbolUnit& Mole() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Mole))};
  return unit;
}
inline const SymbolUnit& Candela() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Candela))};
  return unit;
}
inline const SymbolUnit& Hertz() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Hertz))};
  return unit;
}
inline const SymbolUnit& Newton() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Newton))};
  return unit;
}
inline const SymbolUnit& Pascal() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Pascal))};
  return unit;
}
inline const SymbolUnit& Joule() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Joule))};
  return unit;
}
inline const SymbolUnit& Watt() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Watt))};
  return unit;
}
inline const SymbolUnit& Coulomb() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Coulomb))};
  return unit;
}
inline const SymbolUnit& Volt() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Volt))};
  return unit;
}
inline const SymbolUnit& Farad() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Farad))};
  return unit;
}
inline const SymbolUnit& Ohm() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Ohm))};
  return unit;
}
inline const SymbolUnit& Siemens() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Siemens))};
  return unit;
}
inline const SymbolUnit& Weber() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Weber))};
  return unit;
}
inline const SymbolUnit& Tesla() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Tesla))};
  return unit;
}
inline const SymbolUnit& Henry() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Henry))};
  return unit;
}
inline const SymbolUnit& Minute() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Minute))};
  return unit;
}
inline const SymbolUnit& Hour() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Hour))};
  return unit;
}
inline const SymbolUnit& ElectronVolt() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::ElectronVolt))};
  return unit;
}
inline const SymbolUnit& Celsius() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Celsius))};
  return unit;
}
inline const SymbolUnit& Fahrenheit() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Fahrenheit))};
  return unit;
}
inline const SymbolUnit& Dimensionless() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Dimensionless))};
  return unit;
}
inline const SymbolUnit& Percent() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Percent))};
  return unit;
}
inline const SymbolUnit& Radian() {
  static const SymbolUnit unit{SP(Unit, Unit(common_units::Radian))};
  return unit;
}
inline const SymbolUnit& MilliMeter() {
  static const SymbolUnit unit{common_units::get_milli(common_units::Meter)};
  return unit;
}
inline const SymbolUnit& KiloMeter() {
  static const SymbolUnit unit{common_units::get_kilo(common_units::Meter)};
  return unit;
}
inline const SymbolUnit& MilliVolt() {
  static const SymbolUnit unit{common_units::get_milli(common_units::Volt)};
  return unit;
}
inline const SymbolUnit& KiloVolt() {
  static const SymbolUnit unit{common_units::get_kilo(common_units::Volt)};
  return unit;
}
inline const SymbolUnit& MilliAmpere() {
  static const SymbolUnit unit{common_units::get_milli(common_units::Ampere)};
  return unit;
}
inline const SymbolUnit& MicroAmpere() {
  static const SymbolUnit unit{common_units::get_micro(common_units::Ampere)};
  return unit;
}
inline const SymbolUnit& NanoAmpere() {
  static const SymbolUnit unit{common_units::get_nano(common_units::Ampere)};
  return unit;
}
inline const SymbolUnit& PicoAmpere() {
  static const SymbolUnit unit{common_units::get_pico(common_units::Ampere)};
  return unit;
}
inline const SymbolUnit& MilliSecond() {
  static const SymbolUnit unit{common_units::get_milli(common_units::Second)};
  return unit;
}
inline const SymbolUnit& MicroSecond() {
  static const SymbolUnit unit{common_units::get_micro(common_units::Second)};
  return unit;
}
inline const SymbolUnit& NanoSecond() {
  static const SymbolUnit unit{common_units::get_nano(common_units::Second)};
  return unit;
}
inline const SymbolUnit& PicoSecond() {
  static const SymbolUnit unit{common_units::get_pico(common_units::Second)};
  return unit;
}
inline const SymbolUnit& MilliOhm() {
  static const SymbolUnit unit{common_units::get_milli(common_units::Ohm)};
  return unit;
}
inline const SymbolUnit& KiloOhm() {
  static const SymbolUnit unit{common_units::get_kilo(common_units::Ohm)};
  return unit;
}
inline const SymbolUnit& MegaOhm() {
  static const SymbolUnit unit{common_units::get_mega(common_units::Ohm)};
  return unit;
}
inline const SymbolUnit& MilliHertz() {
  static const SymbolUnit unit{common_units::get_milli(common_units::Hertz)};
  return unit;
}
inline const SymbolUnit& KiloHertz() {
  static const SymbolUnit unit{common_units::get_kilo(common_units::Hertz)};
  return unit;
}
inline const SymbolUnit& MegaHertz() {
  static const SymbolUnit unit{common_units::get_mega(common_units::Hertz)};
  return unit;
}
inline const SymbolUnit& GigaHertz() {
  static const SymbolUnit unit{common_units::get_giga(common_units::Hertz)};
  return unit;
}
inline const SymbolUnit& MetersPerSecond() {
  static const SymbolUnit unit{
      (common_units::Meter / SP(Unit, common_units::Second))};
  return unit;
}
inline const SymbolUnit& MetersPerSecondSquared() {
  static const SymbolUnit unit{
      (common_units::Meter / (common_units::Second ^ 2))};
  return unit;
}
inline const SymbolUnit& NewtonMeter() {
  static const SymbolUnit unit{
      (common_units::Newton * SP(Unit, common_units::Meter))};
  return unit;
}
inline const SymbolUnit& NewtonPerMeter() {
  static const SymbolUnit unit{
      (common_units::Newton / SP(Unit, common_units::Meter))};
  return unit;
}
inline const SymbolUnit& VoltsPerMeter() {
  static const SymbolUnit unit{
      (common_units::Volt / SP(Unit, common_units::Meter))};
  return unit;
}
inline const SymbolUnit& VoltsPerSecond() {
  static const SymbolUnit unit{
      (common_units::Volt / SP(Unit, common_units::Second))};
  return unit;
}
inline const SymbolUnit& AmperesPerMeter() {
  static const SymbolUnit unit{
      (common_units::Ampere / SP(Unit, common_units::Meter))};
  return unit;
}
inline const SymbolUnit& VoltsPerAmpere() {
  static const SymbolUnit unit{
      (common_units::Volt / SP(Unit, common_units::Ampere))};
  return unit;
}
inline const SymbolUnit& WattsPerMeterKelvin() {
  static const SymbolUnit unit{
      (common_units::Watt /
       (common_units::Meter * SP(Unit, common_units::Kelvin)))};
  return unit;
}

}  // namespace units
}  // namespace physics
}  // namespace falcon_core
