#include "falcon_core/physics/units/CommonUnits.hpp"

#include "falcon_core/macros.hpp"
#define SPU(...) SP(Unit, __VA_ARGS__)
namespace falcon_core::physics::units {
const UnitSP CommonUnits::Meter =
    SPU(Unit(SI::DIMENSIONS_METER, 1.0, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Kilogram =
    SPU(Unit(SI::DIMENSIONS_KILOGRAM, 1.0, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Second =
    SPU(Unit(SI::DIMENSIONS_SECOND, 1.0, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Ampere =
    SPU(Unit(SI::DIMENSIONS_AMPERE, 1.0, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Kelvin =
    SPU(Unit(SI::DIMENSIONS_KELVIN, 1.0, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Mole =
    SPU(Unit(SI::DIMENSIONS_MOLE, 1.0, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Candela =
    SPU(Unit(SI::DIMENSIONS_CANDELA, 1.0, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Hertz =
    SPU(Unit(SI::DIMENSIONS_HERTZ, 1.0, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Newton =
    SPU(Unit(SI::DIMENSIONS_NEWTON, 1.0, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Pascal =
    SPU(Unit(SI::DIMENSIONS_PASCAL, 1.0, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Joule =
    SPU(Unit(SI::DIMENSIONS_JOULE, 1.0, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Watt =
    SPU(Unit(SI::DIMENSIONS_WATT, 1.0, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Coulomb =
    SPU(Unit(SI::DIMENSIONS_COULOMB, 1.0, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Volt =
    SPU(Unit(SI::DIMENSIONS_VOLT, 1.0, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Farad =
    SPU(Unit(SI::DIMENSIONS_FARAD, 1.0, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Ohm =
    SPU(Unit(SI::DIMENSIONS_OHM, 1.0, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Siemens =
    SPU(Unit(SI::DIMENSIONS_SIEMENS, 1.0, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Weber =
    SPU(Unit(SI::DIMENSIONS_WEBER, 1.0, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Tesla =
    SPU(Unit(SI::DIMENSIONS_TESLA, 1.0, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Henry =
    SPU(Unit(SI::DIMENSIONS_HENRY, 1.0, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Minute =
    SPU(Unit(SI::DIMENSIONS_SECOND, SECONDS_PER_MINUTE, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Hour = SPU(Unit(SI::DIMENSIONS_SECOND,
                                          SECONDS_PER_MINUTE* MINUTES_PER_HOUR,
                                          0.0,
                                          SI::UNIT_SYMBOL));
const UnitSP CommonUnits::ElectronVolt =
    SPU(Unit(SI::DIMENSIONS_JOULE, ELECTRON_CHARGE, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Celsius =
    SPU(Unit(SI::DIMENSIONS_KELVIN, 1.0, CELSIUS_OFFSET, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Fahrenheit = SPU(Unit(SI::DIMENSIONS_KELVIN,
                                                UNIT_SCALE_FAHRENHEIT,
                                                FAHRENHEIT_OFFSET,
                                                SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Dimensionless =
    SPU(Unit(SI::DIMENSIONS_DIMENSIONLESS));
const UnitSP CommonUnits::Percent =
    SPU(Unit(SI::DIMENSIONS_DIMENSIONLESS, 0.01, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::Radian =
    SPU(Unit(SI::DIMENSIONS_DIMENSIONLESS, 1.0, 0.0, SI::UNIT_SYMBOL));
const UnitSP CommonUnits::get_unit_with_prefix(const UnitSP&     unit,
                                               const std::string prefix) {
  return unit->with_prefix(prefix);
}
const UnitSP CommonUnits::get_milli(const UnitSP& unit) {
  return unit->with_prefix(SI::MILLI_SYMBOL);
}
const UnitSP CommonUnits::get_micro(const UnitSP& unit) {
  return unit->with_prefix(SI::MICRO_SYMBOL);
}
const UnitSP CommonUnits::get_nano(const UnitSP& unit) {
  return unit->with_prefix(SI::NANO_SYMBOL);
}
const UnitSP CommonUnits::get_pico(const UnitSP& unit) {
  return unit->with_prefix(SI::PICO_SYMBOL);
}
const UnitSP CommonUnits::get_kilo(const UnitSP& unit) {
  return unit->with_prefix(SI::KILO_SYMBOL);
}
const UnitSP CommonUnits::get_mega(const UnitSP& unit) {
  return unit->with_prefix(SI::MEGA_SYMBOL);
}
const UnitSP CommonUnits::get_giga(const UnitSP& unit) {
  return unit->with_prefix(SI::GIGA_SYMBOL);
}
}  // namespace falcon_core::physics::units
