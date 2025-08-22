#pragma once

#include "falcon_core/physics/units/Unit.hpp"

namespace falcon_core {
namespace physics {
namespace units {

struct CommonUnits {
  static const UnitSP Meter;
  static const UnitSP Kilogram;
  static const UnitSP Second;
  static const UnitSP Ampere;
  static const UnitSP Kelvin;
  static const UnitSP Mole;
  static const UnitSP Candela;
  static const UnitSP Hertz;
  static const UnitSP Newton;
  static const UnitSP Pascal;
  static const UnitSP Joule;
  static const UnitSP Watt;
  static const UnitSP Coulomb;
  static const UnitSP Volt;
  static const UnitSP Farad;
  static const UnitSP Ohm;
  static const UnitSP Siemens;
  static const UnitSP Weber;
  static const UnitSP Tesla;
  static const UnitSP Henry;
  static const UnitSP Minute;
  static const UnitSP Hour;
  static const UnitSP ElectronVolt;
  static const UnitSP Celsius;
  static const UnitSP Fahrenheit;
  static const UnitSP Dimensionless;
  static const UnitSP Percent;
  static const UnitSP Radian;
  /*
   * @brief Get a unit with a specific prefix.
   * @param unit The base unit to apply the prefix to.
   * @param prefix The prefix to apply.
   * @return A shared pointer to the new unit with the specified prefix.
   */
  static const UnitSP get_unit_with_prefix(const UnitSP&     unit,
                                           const std::string prefix);
  /*
   * @brief Get the milli- version of a unit.
   * @param unit The base unit to convert to milli-.
   * @return A shared pointer to the new unit with the milli- prefix.
   */
  static const UnitSP get_milli(const UnitSP& unit);
  /*
   * @brief Get the micro- version of a unit.
   * @param unit The base unit to convert to micro-.
   * @return A shared pointer to the new unit with the micro- prefix.
   */
  static const UnitSP get_micro(const UnitSP& unit);
  /*
   * @brief Get the nano- version of a unit.
   * @param unit The base unit to convert to nano-.
   * @return A shared pointer to the new unit with the nano- prefix.
   */
  static const UnitSP get_nano(const UnitSP& unit);
  /*
   * @brief Get the pico- version of a unit.
   * @param unit The base unit to convert to pico-.
   * @return A shared pointer to the new unit with the pico- prefix.
   */
  static const UnitSP get_pico(const UnitSP& unit);
  /*
   * @brief Get the kilo- version of a unit.
   * @param unit The base unit to convert to kilo-.
   * @return A shared pointer to the new unit with the kilo- prefix.
   */
  static const UnitSP get_kilo(const UnitSP& unit);
  /*
   * @brief Get the mega- version of a unit.
   * @param unit The base unit to convert to mega-.
   * @return A shared pointer to the new unit with the mega- prefix.
   */
  static const UnitSP get_mega(const UnitSP& unit);
  /*
   * @brief Get the giga- version of a unit.
   * @param unit The base unit to convert to giga-.
   * @return A shared pointer to the new unit with the giga- prefix.
   */
  static const UnitSP get_giga(const UnitSP& unit);
};
}  // namespace units
}  // namespace physics
}  // namespace falcon_core
