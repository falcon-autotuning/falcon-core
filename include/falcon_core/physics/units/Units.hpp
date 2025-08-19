#pragma once

#include "falcon_core/macros.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"
namespace falcon_core {
namespace physics {
namespace units {
struct Units {
  static const SymbolUnit& Meter() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Meter))};
    return unit;
  }
  static const SymbolUnit& Kilogram() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Kilogram))};
    return unit;
  }
  static const SymbolUnit& Second() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Second))};
    return unit;
  }
  static const SymbolUnit& Ampere() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Ampere))};
    return unit;
  }
  static const SymbolUnit& Kelvin() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Kelvin))};
    return unit;
  }
  static const SymbolUnit& Mole() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Mole))};
    return unit;
  }
  static const SymbolUnit& Candela() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Candela))};
    return unit;
  }
  static const SymbolUnit& Hertz() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Hertz))};
    return unit;
  }
  static const SymbolUnit& Newton() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Newton))};
    return unit;
  }
  static const SymbolUnit& Pascal() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Pascal))};
    return unit;
  }
  static const SymbolUnit& Joule() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Joule))};
    return unit;
  }
  static const SymbolUnit& Watt() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Watt))};
    return unit;
  }
  static const SymbolUnit& Coulomb() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Coulomb))};
    return unit;
  }
  static const SymbolUnit& Volt() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Volt))};
    return unit;
  }
  static const SymbolUnit& Farad() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Farad))};
    return unit;
  }
  static const SymbolUnit& Ohm() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Ohm))};
    return unit;
  }
  static const SymbolUnit& Siemens() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Siemens))};
    return unit;
  }
  static const SymbolUnit& Weber() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Weber))};
    return unit;
  }
  static const SymbolUnit& Tesla() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Tesla))};
    return unit;
  }
  static const SymbolUnit& Henry() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Henry))};
    return unit;
  }
  static const SymbolUnit& Minute() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Minute))};
    return unit;
  }
  static const SymbolUnit& Hour() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Hour))};
    return unit;
  }
  static const SymbolUnit& ElectronVolt() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::ElectronVolt))};
    return unit;
  }
  static const SymbolUnit& Celsius() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Celsius))};
    return unit;
  }
  static const SymbolUnit& Fahrenheit() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Fahrenheit))};
    return unit;
  }
  static const SymbolUnit& Dimensionless() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Dimensionless))};
    return unit;
  }
  static const SymbolUnit& Percent() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Percent))};
    return unit;
  }
  static const SymbolUnit& Radian() {
    static const SymbolUnit unit{SP(Unit, Unit(common_units::Radian))};
    return unit;
  }
  static const SymbolUnit& MilliMeter() {
    static const SymbolUnit unit{common_units::get_milli(common_units::Meter)};
    return unit;
  }
  static const SymbolUnit& KiloMeter() {
    static const SymbolUnit unit{common_units::get_kilo(common_units::Meter)};
    return unit;
  }
  static const SymbolUnit& MilliVolt() {
    static const SymbolUnit unit{common_units::get_milli(common_units::Volt)};
    return unit;
  }
  static const SymbolUnit& KiloVolt() {
    static const SymbolUnit unit{common_units::get_kilo(common_units::Volt)};
    return unit;
  }
  static const SymbolUnit& MilliAmpere() {
    static const SymbolUnit unit{common_units::get_milli(common_units::Ampere)};
    return unit;
  }
  static const SymbolUnit& MicroAmpere() {
    static const SymbolUnit unit{common_units::get_micro(common_units::Ampere)};
    return unit;
  }
  static const SymbolUnit& NanoAmpere() {
    static const SymbolUnit unit{common_units::get_nano(common_units::Ampere)};
    return unit;
  }
  static const SymbolUnit& PicoAmpere() {
    static const SymbolUnit unit{common_units::get_pico(common_units::Ampere)};
    return unit;
  }
  static const SymbolUnit& MilliSecond() {
    static const SymbolUnit unit{common_units::get_milli(common_units::Second)};
    return unit;
  }
  static const SymbolUnit& MicroSecond() {
    static const SymbolUnit unit{common_units::get_micro(common_units::Second)};
    return unit;
  }
  static const SymbolUnit& NanoSecond() {
    static const SymbolUnit unit{common_units::get_nano(common_units::Second)};
    return unit;
  }
  static const SymbolUnit& PicoSecond() {
    static const SymbolUnit unit{common_units::get_pico(common_units::Second)};
    return unit;
  }
  static const SymbolUnit& MilliOhm() {
    static const SymbolUnit unit{common_units::get_milli(common_units::Ohm)};
    return unit;
  }
  static const SymbolUnit& KiloOhm() {
    static const SymbolUnit unit{common_units::get_kilo(common_units::Ohm)};
    return unit;
  }
  static const SymbolUnit& MegaOhm() {
    static const SymbolUnit unit{common_units::get_mega(common_units::Ohm)};
    return unit;
  }
  static const SymbolUnit& MilliHertz() {
    static const SymbolUnit unit{common_units::get_milli(common_units::Hertz)};
    return unit;
  }
  static const SymbolUnit& KiloHertz() {
    static const SymbolUnit unit{common_units::get_kilo(common_units::Hertz)};
    return unit;
  }
  static const SymbolUnit& MegaHertz() {
    static const SymbolUnit unit{common_units::get_mega(common_units::Hertz)};
    return unit;
  }
  static const SymbolUnit& GigaHertz() {
    static const SymbolUnit unit{common_units::get_giga(common_units::Hertz)};
    return unit;
  }
  static const SymbolUnit& MetersPerSecond() {
    static const SymbolUnit unit{
        (common_units::Meter / SP(Unit, common_units::Second))};
    return unit;
  }
  static const SymbolUnit& MetersPerSecondSquared() {
    static const SymbolUnit unit{
        (common_units::Meter / (common_units::Second ^ 2))};
    return unit;
  }
  static const SymbolUnit& NewtonMeter() {
    static const SymbolUnit unit{
        (common_units::Newton * SP(Unit, common_units::Meter))};
    return unit;
  }
  static const SymbolUnit& NewtonPerMeter() {
    static const SymbolUnit unit{
        (common_units::Newton / SP(Unit, common_units::Meter))};
    return unit;
  }
  static const SymbolUnit& VoltsPerMeter() {
    static const SymbolUnit unit{
        (common_units::Volt / SP(Unit, common_units::Meter))};
    return unit;
  }
  static const SymbolUnit& VoltsPerSecond() {
    static const SymbolUnit unit{
        (common_units::Volt / SP(Unit, common_units::Second))};
    return unit;
  }
  static const SymbolUnit& AmperesPerMeter() {
    static const SymbolUnit unit{
        (common_units::Ampere / SP(Unit, common_units::Meter))};
    return unit;
  }
  static const SymbolUnit& VoltsPerAmpere() {
    static const SymbolUnit unit{
        (common_units::Volt / SP(Unit, common_units::Ampere))};
    return unit;
  }
  static const SymbolUnit& WattsPerMeterKelvin() {
    static const SymbolUnit unit{
        (common_units::Watt /
         (common_units::Meter * SP(Unit, common_units::Kelvin)))};
    return unit;
  }
};
}  // namespace units
}  // namespace physics
}  // namespace falcon_core
