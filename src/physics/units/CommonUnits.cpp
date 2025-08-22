#include "falcon_core/physics/units/CommonUnits.hpp"

#include "falcon_core/macros.hpp"
using namespace falcon_core::physics::units;
using namespace falcon_core::SI;
#define SPU(...) SP(Unit, __VA_ARGS__)
const UnitSP CommonUnits::Meter =
    SPU(Unit(DIMENSIONS_METER, 1.0, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Kilogram =
    SPU(Unit(DIMENSIONS_KILOGRAM, 1.0, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Second =
    SPU(Unit(DIMENSIONS_SECOND, 1.0, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Ampere =
    SPU(Unit(DIMENSIONS_AMPERE, 1.0, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Kelvin =
    SPU(Unit(DIMENSIONS_KELVIN, 1.0, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Mole =
    SPU(Unit(DIMENSIONS_MOLE, 1.0, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Candela =
    SPU(Unit(DIMENSIONS_CANDELA, 1.0, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Hertz =
    SPU(Unit(DIMENSIONS_HERTZ, 1.0, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Newton =
    SPU(Unit(DIMENSIONS_NEWTON, 1.0, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Pascal =
    SPU(Unit(DIMENSIONS_PASCAL, 1.0, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Joule =
    SPU(Unit(DIMENSIONS_JOULE, 1.0, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Watt =
    SPU(Unit(DIMENSIONS_WATT, 1.0, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Coulomb =
    SPU(Unit(DIMENSIONS_COULOMB, 1.0, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Volt =
    SPU(Unit(DIMENSIONS_VOLT, 1.0, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Farad =
    SPU(Unit(DIMENSIONS_FARAD, 1.0, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Ohm =
    SPU(Unit(DIMENSIONS_OHM, 1.0, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Siemens =
    SPU(Unit(DIMENSIONS_SIEMENS, 1.0, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Weber =
    SPU(Unit(DIMENSIONS_WEBER, 1.0, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Tesla =
    SPU(Unit(DIMENSIONS_TESLA, 1.0, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Henry =
    SPU(Unit(DIMENSIONS_HENRY, 1.0, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Minute =
    SPU(Unit(DIMENSIONS_SECOND, SECONDS_PER_MINUTE, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Hour = SPU(Unit(
    DIMENSIONS_SECOND, SECONDS_PER_MINUTE* MINUTES_PER_HOUR, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::ElectronVolt =
    SPU(Unit(DIMENSIONS_JOULE, ELECTRON_CHARGE, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Celsius =
    SPU(Unit(DIMENSIONS_KELVIN, 1.0, CELSIUS_OFFSET, UNIT_SYMBOL));
const UnitSP CommonUnits::Fahrenheit    = SPU(Unit(
    DIMENSIONS_KELVIN, UNIT_SCALE_FAHRENHEIT, FAHRENHEIT_OFFSET, UNIT_SYMBOL));
const UnitSP CommonUnits::Dimensionless = SPU(Unit(DIMENSIONS_DIMENSIONLESS));
const UnitSP CommonUnits::Percent =
    SPU(Unit(DIMENSIONS_DIMENSIONLESS, 0.01, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::Radian =
    SPU(Unit(DIMENSIONS_DIMENSIONLESS, 1.0, 0.0, UNIT_SYMBOL));
const UnitSP CommonUnits::get_unit_with_prefix(const UnitSP&     unit,
                                               const std::string prefix) {
  return unit->with_prefix(prefix);
}
const UnitSP CommonUnits::get_milli(const UnitSP& unit) {
  return unit->with_prefix(MILLI_SYMBOL);
}
const UnitSP CommonUnits::get_micro(const UnitSP& unit) {
  return unit->with_prefix(MICRO_SYMBOL);
}
const UnitSP CommonUnits::get_nano(const UnitSP& unit) {
  return unit->with_prefix(NANO_SYMBOL);
}
const UnitSP CommonUnits::get_pico(const UnitSP& unit) {
  return unit->with_prefix(PICO_SYMBOL);
}
const UnitSP CommonUnits::get_kilo(const UnitSP& unit) {
  return unit->with_prefix(KILO_SYMBOL);
}
const UnitSP CommonUnits::get_mega(const UnitSP& unit) {
  return unit->with_prefix(MEGA_SYMBOL);
}
const UnitSP CommonUnits::get_giga(const UnitSP& unit) {
  return unit->with_prefix(GIGA_SYMBOL);
}
